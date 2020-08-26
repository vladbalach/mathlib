#include "vector.h"
#include <cmath>

// struct
Vector3D::Vector3D(float a, float b, float c)
: x(a), y(b), z(c) {}

float& Vector3D::operator[] (const int& i) {
    return ((&x)[i]);
}

const float& Vector3D::operator[](const int& i) const {
    return ((&x)[i]);
}

Vector3D& Vector3D::operator += (const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
}

Vector3D& Vector3D::operator -=(const Vector3D& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

