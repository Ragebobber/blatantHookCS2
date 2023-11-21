#pragma once

struct bbox_t
{
	void Invalidate() {

		m_Mins.x = m_Mins.y = FLT_MAX;
		m_Maxs.x = m_Maxs.y = -FLT_MAX;

		std::fill(std::begin(m_Vertices), std::end(m_Vertices),
			ImVec2{ -FLT_MAX, -FLT_MAX });
	}
	ImVec2 m_Mins, m_Maxs;
	ImVec2 m_Vertices[8];
};