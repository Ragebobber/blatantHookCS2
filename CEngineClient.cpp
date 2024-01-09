#include "sdk.h"

int CEngineClient::GetLocalPlayerIndex()
{
	int index = -1;
	GetSplitScreenPlayer(index, 0);
	return index + 1;
}