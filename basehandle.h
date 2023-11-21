#pragma once
#define INVALID_EHANDLE_INDEX 0xFFFFFFFF
#define ENT_ENTRY_MASK 0x7fff

#define NUM_SERIAL_NUM_SHIFT_BITS 15
#define ENT_MAX_NETWORKED_ENTRY 16384


class C_BaseEntity;

class CBaseHandle
{
public:
public:
	CBaseHandle() : m_Index(INVALID_EHANDLE_INDEX) {}
	CBaseHandle(uint32_t value) : m_Index(value) {}
	CBaseHandle(int entry, int serialNumber) { Init(entry, serialNumber); }

	void Init(int entry, int serialNumber);

	bool IsValid() const;

	int GetEntryIndex() const;
	int GetSerialNumber() const;

	int ToInt() const;
	bool operator==(CBaseHandle rhs) const;
	bool operator!=(CBaseHandle rhs) const;

	C_BaseEntity* Get() const;

protected:
	uint32_t m_Index;

};

template <typename T>
class CHandle : public CBaseHandle {
public:
	T* Get() const { return static_cast<T*>(CBaseHandle::Get()); }
};