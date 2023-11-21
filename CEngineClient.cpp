#include "CEngineClient.h"

int CEngineClient::GetLocalPlayerIndex()
{
	int index = -1;
	GetSplitScreenPlayer(&index);
	return index + 1;
}
