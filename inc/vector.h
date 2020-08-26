#pragma once
#include <cmath>

struct Vector3D 
{
    float x;
    float y;
    float z;

    Vector3D() = default;

    Vector3D(float a, float b, float c);

    float& operator[] (const int& i);

    const float& operator[](const int& i) const;
    Vector3D& operator *=(float s);
    Vector3D& operator /=(float s);
    Vector3D& operator +=(const Vector3D& v);
    Vector3D& operator -=(const Vector3D& v);
};

inline Vector3D operator+ (const Vector3D& v1, const Vector3D& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

inline Vector3D operator- (const Vector3D& v1, const Vector3D& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

inline Vector3D operator *(const Vector3D& v, float s) {
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator /(const Vector3D& v, float s) {
    s = 1.0F / s;
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator -(const Vector3D& v) {
    return {-v.x, -v.y, -v.z};
}

inline float Magnitude(const Vector3D& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D Normalize(const Vector3D& v) {
    return (v / Magnitude(v));
}

inline float Dot(const Vector3D& a, const Vector3D& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float Dot(float len1, float len2, float degree) {
    return len1 * len2 * cos(degree / 57.2958);
}

inline Vector3D Cross(const Vector3D& a, const Vector3D& b) {
    return Vector3D{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x};
}

inline Vector3D Project(const Vector3D& a, const Vector3D& b) {
    return b * (Dot(a, b) / Dot(b, b));
}

inline Vector3D Reject(const Vector3D& a, const Vector3D& b) {
    return a - Project(a, b);
}

/* more fast than just project */
inline Vector3D Project_unit(const Vector3D& a, const Vector3D& b_unit) {
    return b_unit * (Dot(a, b_unit));
}

/* more fast than just reject */
inline Vector3D Reject_unit(const Vector3D& a, const Vector3D& b_unit) {
    return a - Project_unit(a, b_unit);
}
