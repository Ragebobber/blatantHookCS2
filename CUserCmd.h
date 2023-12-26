#pragma once

struct CCmdQangle {
	char pad1[0x18];
	Vector angles;
};


struct CSubTickContainer
{
	int32_t			mTickCount;
	char			pad1[0x4];
	void*			mInputHistory;
};

struct CUserCmdBase {
	char			pad1[0x40];
	CCmdQangle*		mViewangles;//QAngle
	int				mCommandNumber;
	int				mTickCount;
	float			mForwardmove;
	float			mRightmove;
	float			mUpmove;
};

struct CUserCmd
{
	char				pad1[0x20];
	CSubTickContainer	mSubTickContainer;
	CUserCmdBase*		mBaseCmd;
	int					mStartHistoryIndexAttack1;
	int					mStartHistoryIndexAttack2;
	int					mStartHistoryIndexAttack3;
	char				pad2[0x8];
	uint64_t			mButtons;
	uint64_t			mButtonsChanged;
	uint64_t			mButtonsScroll;
	char				pad3[0x8];
};