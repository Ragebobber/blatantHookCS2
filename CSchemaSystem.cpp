#include "sdk.h"

CSchemaSystemTypeScope* CSchemaSystem::FindTypeScopeForModule(const char* name)
{
	return sdk::helpers->CallVirtual<13, CSchemaSystemTypeScope*>(this,name, nullptr);
}

CSchemaClassInfo* CSchemaSystemTypeScope::FindDeclaredClass(const char* name)
{
	CSchemaClassInfo* binding = nullptr;
	sdk::helpers->CallVirtual<2, void>(this, &binding, name);
	return binding;
}
