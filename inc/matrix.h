#pragma once
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
struct Matrix3D {
private:
    float n[3][3];
    float g;
public:
    Matrix3D() = default;

    Matrix3D(float nOO, float nOl, float n02,
             float nlO, float nll, float nl2,
             float n20, float n21, float n22);

    Matrix3D(const Vector3D& a,
             const Vector3D& b,
             const Vector3D& c);
    
    float& operator () (int i, int j);

    const float& operator () (int i, int j) const;

    Vector3D& operator[](int j);

    const Vector3D& operator [](int j) const;
};

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B);

Vector3D operator *(const Matrix3D& M, const Vector3D& v);

// float Determinant(const Matrix3D& M) {
//     return M(0, 0) * M(1, 1
// }