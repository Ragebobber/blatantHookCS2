#pragma once

class Quaternion {
public:
    float x, y, z, w;
};


class alignas(16) CTransform {
public:
    alignas(16) Vector m_Position;
    alignas(16) Quaternion m_Orientation;

    matrix3x4_t ToMatrix() const;
};