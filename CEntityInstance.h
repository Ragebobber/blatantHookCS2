#pragma once

class CEntityKeyValues;


class CEntityIdentity {
public:
	SCHEMA(uint32_t, m_flags, "CEntityIdentity", "m_flags");
};


class CEntityInstance
{
//public:
//	virtual void unk_0() = 0;
//	virtual void unk_1() = 0;
//	virtual void Connect() = 0;
//	virtual void Precache() = 0;// #STR: "Precache"
//	virtual void AddedToEntityDatabase() = 0;
//	virtual void Spawn(CEntityKeyValues* a2) = 0;//#STR: "Spawn"
//	virtual void PostDataUpdate() = 0;
//	virtual void Activate(unsigned int a2, __int64 a3, __int64 a4) = 0;//#STR: "Activate"
//	virtual char* UpdateOnRemove() = 0;// ret EntityClass::RemoveFromClassList #STR: "kv 0x%p Release refcount == %d\n", "UpdateOnRemove"
//	virtual bool OnSetDormant(int a2, int a3) = 0;
//	virtual void unk_10() = 0;
//	virtual void unk_11() = 0;
//	virtual void unk_12() = 0;
//	virtual void unk_13() = 0;
//	virtual void unk_14() = 0;
//	virtual void unk_15() = 0;
//	virtual void unk_16() = 0;
//	virtual void unk_17() = 0;
//	virtual void unk_18() = 0;
//	virtual void unk_19() = 0;
//	virtual void unk_20() = 0;
//	virtual void unk_21() = 0;
//	virtual void unk_22() = 0;
//	virtual void unk_23() = 0;
//	virtual void unk_24() = 0;
//	virtual void unk_25() = 0;
//	virtual void unk_26() = 0;
//	virtual void unk_27() = 0;
//	virtual void unk_28() = 0;
//	virtual void unk_29() = 0;
//	virtual void unk_30() = 0;
//	virtual void** ReloadPrivateScripts() = 0;// #STR: "%s executing script: %s\n"
//	virtual void unk_32() = 0;
//	virtual void unk_33() = 0;
//	virtual CSchemaClassInfo* SchemaDynamicBinding() = 0;
//	virtual void unk_35() = 0;
public:
	CBaseHandle GetRefEHandle();
	SCHEMA(CEntityIdentity*, m_pEntity, "CEntityInstance", "m_pEntity");
};

