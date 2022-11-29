//
// Create by HoChihchou on 2022/11/14
//

#include "cmath"
#include "Matrix4x4.h"

Matrix4x4::Matrix4x4() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = 0;
        }
    }
}

Matrix4x4::Matrix4x4(double value) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = value;
        }
    }
}

Matrix4x4::Matrix4x4(double values[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = values[i][j];
        }
    }
};

Matrix4x4::Matrix4x4(double a11, double a12, double a13, double a14,
                     double a21, double a22, double a23, double a24,
                     double a31, double a32, double a33, double a34,
                     double a41, double a42, double a43, double a44) {
    a[0][0] = a11;
    a[0][1] = a12;
    a[0][2] = a13;
    a[0][3] = a14;
    a[1][0] = a21;
    a[1][1] = a22;
    a[1][2] = a23;
    a[1][3] = a24;
    a[2][0] = a31;
    a[2][1] = a32;
    a[2][2] = a33;
    a[2][3] = a34;
    a[3][0] = a41;
    a[3][1] = a42;
    a[3][2] = a43;
    a[3][3] = a44;
}

Matrix4x4 Matrix4x4::identity() {
    Matrix4x4 m;
    m = {1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1};
    return m;
}

Matrix4x4 Matrix4x4::zero() {
    return {};
}

//Matrix4x4 Matrix4x4::inverse() {}   //逆矩阵 = 伴随矩阵 / 行列式的值

Matrix4x4 Matrix4x4::transpose() {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.a[i][j] = a[j][i];
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::mul(Matrix4x4 &mat) {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                m.a[i][j] += a[i][k] * mat.a[k][j];
            }
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::mul(double v) {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.a[i][j] *= v;
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::mul(Matrix4x4 &lMat, Matrix4x4 &rMat) {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                m.a[i][j] += lMat.a[i][k] * rMat.a[k][j];
            }
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &mat) const {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                m.a[i][j] += a[i][k] * mat.a[k][j];
            }
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::operator*=(Matrix4x4 &mat) {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                m.a[i][j] += a[i][k] * mat.a[k][j];
            }
        }
    }
    return *this = m;
}

Matrix4x4 Matrix4x4::operator*(double v) {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.a[i][j] *= v;
        }
    }
    return m;
}

Matrix4x4 operator*(double v, const Matrix4x4 &mat) {   //友元函数不属于成员函数，不需要指定类的作用域
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.a[i][j] *= v;
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::operator-() {
    Matrix4x4 m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.a[i][j] = -a[i][j];
        }
    }
    return m;
}

Matrix4x4 Matrix4x4::createRotationX(double angle) {
    return {1, 0, 0, 0,                        //Rx(a) = [1, 0     , 0,       0]
            0, cos(angle), -sin(angle), 0,     //        [0, cos(a), -sin(a), 0]
            0, sin(angle), cos(angle), 0,      //        [0, sin(a), cos(a),  0]
            0, 0, 0, 1};                       //        [0, 0     , 0,       1]
}

Matrix4x4 Matrix4x4::createRotationY(double angle) {
    return {cos(angle), 0, sin(angle), 0,      //Ry(a) = [cos(a), 0, sin(a), 0]
            0, 1, 0, 0,                        //        [0     , 1, 0     , 0]
            -sin(angle), 0, cos(angle), 0,     //        [-sin(a), 0, cos(a), 0]
            0, 0, 0, 1};                       //        [0     , 0, 0     , 1]
}

Matrix4x4 Matrix4x4::createRotationZ(double angle) {
    return {cos(angle), -sin(angle), 0, 0,     //Rz(a) = [cos(a), -sin(a), 0, 0]
            sin(angle), cos(angle), 0, 0,      //        [sin(a), cos(a) , 0, 0]
            0, 0, 1, 0,                        //        [0     , 0      , 1, 0]
            0, 0, 0, 1};                       //        [0     , 0      , 0, 1]
}

Matrix4x4 Matrix4x4::createScale(double s) {
    return {s, 0, 0, 0,                        //S(s) = [s, 0, 0, 0]
            0, s, 0, 0,                        //       [0, s, 0, 0]
            0, 0, s, 0,                        //       [0, 0, s, 0]
            0, 0, 0, 1};                       //       [0, 0, 0, 1]
}

Matrix4x4 Matrix4x4::createScale(double sx, double sy, double sz) {
    return {sx, 0, 0, 0,                       //S(sx, sy, sz) = [sx, 0,  0,  0]
            0, sy, 0, 0,                       //                [0,  sy, 0,  0]
            0, 0, sz, 0,                       //                [0,  0,  sz, 0]
            0, 0, 0, 1};                       //                [0,  0,  0,  1]
}

Matrix4x4 Matrix4x4::createScale(double sx, double sy, double sz, Vector3 &center) {

}

Matrix4x4 Matrix4x4::createTranslation(double tx, double ty, double tz) {
    return {1, 0, 0, tx,                       //T(tx, ty, tz) = [1, 0, 0, tx]
            0, 1, 0, ty,                       //               [0, 1, 0, ty]
            0, 0, 1, tz,                       //               [0, 0, 1, tz]
            0, 0, 0, 1};                       //               [0, 0, 0, 1]
}

Matrix4x4 Matrix4x4::createTranslation(Vector3 &translation){
    return {1, 0, 0, translation.x,
            0, 1, 0, translation.y,
            0, 0, 1, translation.z,
            0, 0, 0, 1};
}