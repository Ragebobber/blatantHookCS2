#pragma once

class Math {
public:
	bool WorldToScreen(const Vector& in, ImVec2& out);
	void updateViewMatrix(VMatrix* pViewMatrix);
	
private:
	VMatrix m_ViewMatrix;
};