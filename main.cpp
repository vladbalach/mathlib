#include "matrix.h"
#include <iostream>

using namespace std;

void PrintMatrix(const Matrix3D& M) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M(i, j) << " ";
        }
        cout << endl;
    }
}

void PrintVector(const Vector3D& v) {
    for (int i = 0 ; i < 3; i++) {
        cout << v[i] << endl;
    }
}

int main() {
    Vector3D a{5, 2, 0};
    Vector3D b{-0.8, 2, 0};

    Vector3D na = Normalize(a);
    Vector3D nb = Normalize(b);

    cout << "na" << endl;
    PrintVector(na);
    cout << "nb" << endl;
    PrintVector(nb);

    cout << "Magnitude a = " << Magnitude(na) << endl;
    cout << "Magnitude b = " << Magnitude(nb) << endl;
    cout << "Dot a * b = " << Dot(a, b) << endl;

}