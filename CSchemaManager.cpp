#include "sdk.h"


int32_t CSchemaManager::GetSchemaOffsetInternal(const char* moduleName, const char* bindingName, const char* fieldName)
{
	CSchemaSystemTypeScope* typeScope = I::gSchemaSystem->FindTypeScopeForModule(moduleName);

	CSchemaClassInfo* classInfo = typeScope->FindDeclaredClass(bindingName);

	uint32_t fieldHash = sdk::helpers->fnv1aHash(fieldName);

	for (int i = 0; classInfo->m_Fields && i < classInfo->m_nFieldsCount; ++i) {
		auto& field = classInfo->m_Fields[i];
		if (sdk::helpers->fnv1aHash(field.m_Name) == fieldHash) {
			return field.m_nSingleInheritanceOffset;
		}
	}
	return 0;
}
