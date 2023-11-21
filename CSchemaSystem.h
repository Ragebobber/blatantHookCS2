#pragma once

class CSchemaSystemTypeScope;
class CSchemaClassInfo;
class CSchemaBaseClassInfo;
class CSchemaClassField;

struct SchemaClassInfoData_t {
	char pad0[0x8];                       // 0x00
	const char* m_Name;                   // 0x08
	const char* m_Description;            // 0x10
	int32_t m_nSizeOf;                    // 0x18
	uint8_t m_nFieldsCount;               // 0x1C
	char pad1[0x5];                       // 0x1D
	uint8_t m_nAlignOf;                   // 0x22
	uint8_t m_nBaseClassesCount;          // 0x23
	char pad2[0x4];                       // 0x24
	CSchemaClassField* m_Fields;          // 0x28
	char pad3[0x8];                       // 0x30
	CSchemaBaseClassInfo* m_BaseClasses;  // 0x38
	char pad4[0x28];                      // 0x40
};

class CSchemaClassInfo : public SchemaClassInfoData_t {
public:
};

struct SchemaBaseClassInfoData_t {
	int32_t m_nOffset;
	CSchemaClassInfo* m_pClass;
};

class CSchemaBaseClassInfo : public SchemaBaseClassInfoData_t {
public:
};

struct SchemaClassFieldData_t {
	const char* m_Name;
	char pad0[0x8];
	int32_t m_nSingleInheritanceOffset;
	char pad1[0xC];
};

class CSchemaClassField : public SchemaClassFieldData_t {
public:
};




class CSchemaSystemTypeScope {
public:
	virtual void unk_0() = 0;
	virtual void unk_1() = 0;
	virtual void unk_2() = 0;
	virtual void unk_3() = 0;
	virtual void unk_4() = 0;
	virtual void unk_5() = 0;
	virtual void unk_6() = 0;
	virtual void unk_7() = 0;
	virtual void unk_8() = 0;
	virtual void unk_9() = 0;
	virtual void unk_10() = 0;
	virtual void unk_11() = 0;
	virtual void unk_12() = 0;
	virtual void unk_13() = 0;
	virtual void unk_14() = 0;
	virtual void unk_15() = 0;
	virtual void unk_16() = 0;
	virtual void unk_17() = 0;
	virtual void unk_18() = 0;
	virtual void unk_19() = 0;
	virtual void unk_20() = 0;
	virtual void unk_21() = 0;
	virtual void unk_22() = 0;
	virtual void unk_23() = 0;
	virtual void unk_24() = 0;
	virtual void unk_25() = 0;
	virtual void unk_26() = 0;
	virtual void unk_27() = 0;
	virtual void unk_28() = 0;
	virtual void unk_29() = 0;
	virtual void unk_30() = 0;
	virtual void unk_31() = 0;
	virtual void unk_32() = 0;
	virtual void unk_33() = 0;
	virtual void unk_34() = 0;
	virtual void unk_35() = 0;
	virtual void unk_36() = 0;
public:
	CSchemaClassInfo* FindDeclaredClass(const char* name);
};

class CSchemaSystem
{
public:
	virtual void unk_0() = 0;
	virtual void unk_1() = 0;
	virtual void unk_2() = 0;
	virtual void unk_3() = 0;
	virtual void unk_4() = 0;
	virtual void unk_5() = 0;
	virtual void unk_6() = 0;
	virtual void unk_7() = 0;
	virtual void unk_8() = 0;
	virtual void unk_9() = 0;
	virtual void unk_10() = 0;
	virtual void unk_11() = 0;
	virtual void unk_12() = 0;
	virtual void unk_13() = 0;
	virtual void unk_14() = 0;
	virtual void unk_15() = 0;
	virtual void unk_16() = 0;
	virtual unsigned int ScopedNameForClass(__int64 a2, /*CBufferString*/void* a3) = 0;
	virtual void unk_18() = 0;
	virtual void unk_19() = 0;
	virtual void unk_20() = 0;
	virtual __int64 LoadSchemaDataForModules(__int64 a2, int a3) = 0;
	virtual void unk_22() = 0;
	virtual void unk_23() = 0;
	virtual void unk_24() = 0;
	virtual void unk_25() = 0;
	virtual void unk_26() = 0;
	virtual void unk_27() = 0;
	virtual void unk_28() = 0;
	virtual void unk_29() = 0;
	virtual void unk_30() = 0;
	virtual void unk_31() = 0;
	virtual void unk_32() = 0;
	virtual void unk_33() = 0;
	virtual void unk_34() = 0;
	virtual void unk_35() = 0;
	virtual void unk_36() = 0;
	virtual void unk_37() = 0;
	virtual void unk_38() = 0;
	virtual void unk_39() = 0;
	virtual void unk_40() = 0;
	virtual void unk_41() = 0;
public:
	CSchemaSystemTypeScope* FindTypeScopeForModule(const char* name);
};

