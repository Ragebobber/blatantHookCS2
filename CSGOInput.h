#pragma once
class IInputHandler {
public:
};
class IKeybindChangeListener
{
public:
};
class CClientInput
{
public:
};

class CCSGOInput : CClientInput, IKeybindChangeListener, IInputHandler {
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
public: 
	CUserCmd* getUserCmd(CCSGOInput* input, uint32_t  vSlot);
};