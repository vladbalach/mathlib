#include "matrix.h"
#include "vector.h"
/* [a b c]
*
* logicaly - MAIN:
* ax bx cx
* ay by cy
* az bz cz
*
* physically
* ax ay az bx by bz cx cy cz 
*/
Matrix3D::Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22)
             : n{n00, n10, n20, n01, n11, n21, n02, n12, n22} {}

Matrix3D::Matrix3D(const Vector3D& a,
            const Vector3D& b,
            const Vector3D& c)
            : n{a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z} {}

float& Matrix3D::operator () (int i, int j) {
    return n[j][i];
}

const float& Matrix3D::operator () (int i, int j) const {
    return n[j][i];
}

Vector3D& Matrix3D::operator[](int j) {
    return (*reinterpret_cast<Vector3D*>(n[j]));
}

const Vector3D& Matrix3D::operator [](int j) const {
    return (*reinterpret_cast<const Vector3D*>(n[j]));
}

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B) {
    return Matrix3D{
        A(0,0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
        A(0,0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
        A(0,0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
    
        A(1,0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
        A(1,0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
        A(1,0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
        
        A(2,0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
        A(2,0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
        A(2,0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)};
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v) {
    return Vector3D{M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
            M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
            M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z};
}