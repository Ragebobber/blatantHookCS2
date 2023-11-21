#pragma once

class CSchemaManager
{
public:
	CSchemaManager() {};
	CSchemaManager(const CSchemaManager&) = delete;
	CSchemaManager& operator=(const CSchemaManager&) = delete;
	~CSchemaManager() {};

	static CSchemaManager& get()
	{
		static CSchemaManager s;
		return s;
	}

	static  auto GetSchemaOffset(const char* moduleName, const char* bindingName, const char* fieldName) {
		return get().GetSchemaOffsetInternal(moduleName, bindingName, fieldName);
	}

private:
	int32_t GetSchemaOffsetInternal(const char* moduleName, const char* bindingName, const char* fieldName) ;
};

#define SCHEMA_EXTENDED(type, name, module_name, binding_name, field_name, extra_offset)                   \
    std::add_lvalue_reference_t<type> name() const {                                                       \
        static const auto offset = CSchemaManager::GetSchemaOffset(module_name, binding_name, field_name); \
        if (offset) return *reinterpret_cast<std::add_pointer_t<type>>(										\
          (uintptr_t)(this) + offset + extra_offset);														\
        static type null{};                                                                                \
        return null;                                                                                       \
    }

#define SCHEMA(type, name, binding_name, field_name) SCHEMA_EXTENDED(type, name, "client.dll", binding_name, field_name, 0)

#define PSCHEMA_EXTENDED(type, name, module_name, binding_name, field_name, extra_offset)                             \
    std::add_pointer_t<type> name() const {                                                                           \
        static const auto offset = CSchemaManager::GetSchemaOffset(module_name, binding_name, field_name);            \
        if (offset) return reinterpret_cast<std::add_pointer_t<type>>(                         \
        (uintptr_t)(this) + offset + extra_offset); \
        return nullptr;                                                                                               \
    }

#define PSCHEMA(type, name, binding_name, field_name) PSCHEMA_EXTENDED(type, name, "client.dll", binding_name, field_name, 0)