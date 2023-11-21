#include "sdk.h"

bool Math::WorldToScreen(const Vector& in, ImVec2& out)
{
    if (!ImGui::GetCurrentContext()) return false;

    const float z = m_ViewMatrix[3][0] * in.x + m_ViewMatrix[3][1] * in.y + m_ViewMatrix[3][2] * in.z + m_ViewMatrix[3][3];
    if (z < 0.001f) return false;

    out = ImGui::GetIO().DisplaySize * 0.5f;
    out.x *= 1.0f + (m_ViewMatrix[0][0] * in.x + m_ViewMatrix[0][1] * in.y + m_ViewMatrix[0][2] * in.z + m_ViewMatrix[0][3]) / z;
    out.y *= 1.0f - (m_ViewMatrix[1][0] * in.x + m_ViewMatrix[1][1] * in.y + m_ViewMatrix[1][2] * in.z + m_ViewMatrix[1][3]) / z;

    // Prevents rounded corners.
    out = ImFloor(out);

    return true;
}

void Math::updateViewMatrix(VMatrix* pViewMatrix)
{
    if (!pViewMatrix)
        return;
    m_ViewMatrix = *pViewMatrix;
}
