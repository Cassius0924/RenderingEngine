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
    return {1, 0, 0, 0,                         //Rx(a) = [1, 0     , 0,       0]
            0, cos(angle), -sin(angle), 0,      //        [0, cos(a), -sin(a), 0]
            0, sin(angle), cos(angle), 0,       //        [0, sin(a), cos(a),  0]
            0, 0, 0, 1};                        //        [0, 0     , 0,       1]
}

Matrix4x4 Matrix4x4::createRotationY(double angle) {
    return {cos(angle), 0, sin(angle), 0,       //Ry(a) = [cos(a), 0, sin(a), 0]
            0, 1, 0, 0,                         //        [0     , 1, 0     , 0]
            -sin(angle), 0, cos(angle), 0,      //        [-sin(a), 0, cos(a), 0]
            0, 0, 0, 1};                        //        [0     , 0, 0     , 1]
}

Matrix4x4 Matrix4x4::createRotationZ(double angle) {
    return {cos(angle), -sin(angle), 0, 0,      //Rz(a) = [cos(a), -sin(a), 0, 0]
            sin(angle), cos(angle), 0, 0,       //        [sin(a), cos(a) , 0, 0]
            0, 0, 1, 0,                         //        [0     , 0      , 1, 0]
            0, 0, 0, 1};                        //        [0     , 0      , 0, 1]
}

//旋转和平移结合计算的公式：y = (y - c.y)*cos(θ) - (z - c.z)*sin(θ) + c.y;
//                     z = (y - c.y)*sin(θ) + (z - c.z)*cos(θ) + c.z;
//c代表中心点，凡和c坐标相乘的都是平移的部分，将平移部分提取出来，就是下面的公式。其余部分皆为旋转的部分。
//ty = c.y - c.y*cos(θ) + c.z*sin(θ) = c.y*(1 - cos(θ)) + c.z*sin(θ);
//tz = c.z - c.z*cos(θ) - c.y*sin(θ) = c.z*(1 - cos(θ)) - c.y*sin(θ);
Matrix4x4 Matrix4x4::createRotationX(double angle, Vector3 &center) {
    Matrix4x4 m;
    double ty = center.y * (1 - cos(angle)) + center.z * sin(angle);
    double tz = center.z * (1 - cos(angle)) - center.y * sin(angle);
    m = {1, 0, 0, 0,                            //Rx(a) = [1, 0     , 0,       0]
         0, cos(angle), -sin(angle), ty,        //        [0, cos(a), -sin(a), ty]
         0, sin(angle), cos(angle), tz,         //        [0, sin(a), cos(a),  tz]
         0, 0, 0, 1};                           //        [0, 0     , 0,      1]
    return m;
}

//旋转和平移结合计算的公式：x = (x - c.x)*cos(θ) + (z - c.z)*sin(θ) + c.x;
//                     z = -(x - c.x)*sin(θ) + (z - c.z)*cos(θ) + c.z;
Matrix4x4 Matrix4x4::createRotationY(double angle, Vector3 &center) {
    Matrix4x4 m;
    double tx = center.x * (1 - cos(angle)) - center.z * sin(angle);
    double tz = center.z * (1 - cos(angle)) + center.x * sin(angle);
    m = {cos(angle), 0, sin(angle), tx,         //Ry(a) = [cos(a), 0, sin(a), tx]
         0, 1, 0, 0,                            //        [0     , 1, 0     , 0]
         -sin(angle), 0, cos(angle), tz,        //        [-sin(a), 0, cos(a), tz]
         0, 0, 0, 1};                           //        [0     , 0, 0     , 1]
    return m;
}

//旋转和平移结合计算的公式：x = (x - c.x)*cos(θ) - (y - c.y)*sin(θ) + c.x;
//                     y = (x - c.x)*sin(θ) + (y - c.y)*cos(θ) + c.y;
Matrix4x4 Matrix4x4::createRotationZ(double angle, Vector3 &center) {
    Matrix4x4 m;
    double tx = center.x * (1 - cos(angle)) + center.y * sin(angle);
    double ty = center.y * (1 - cos(angle)) - center.x * sin(angle);
    m = {cos(angle), -sin(angle), 0, tx,        //Rz(a) = [cos(a), -sin(a), 0, tx]
         sin(angle), cos(angle), 0, ty,         //        [sin(a), cos(a) , 0, ty]
         0, 0, 1, 0,                            //        [0     , 0      , 1, 0]
         0, 0, 0, 1};                           //        [0     , 0      , 0, 1]
    return m;
}

Matrix4x4 Matrix4x4::createScale(double scale) {
    return {scale, 0, 0, 0,                     //S(s) = [s, 0, 0, 0]
            0, scale, 0, 0,                     //       [0, s, 0, 0]
            0, 0, scale, 0,                     //       [0, 0, s, 0]
            0, 0, 0, 1};                        //       [0, 0, 0, 1]
}

Matrix4x4 Matrix4x4::createScale(double sx, double sy, double sz) {
    return {sx, 0, 0, 0,                        //S(sx, sy, sz) = [sx, 0,  0,  0]
            0, sy, 0, 0,                        //                [0,  sy, 0,  0]
            0, 0, sz, 0,                        //                [0,  0,  sz, 0]
            0, 0, 0, 1};                        //                [0,  0,  0,  1]
}

Matrix4x4 Matrix4x4::createScale(Vector3 &scales) {
    return {scales.x, 0, 0, 0,                  //S(sx, sy, sz) = [sx, 0,  0,  0]
            0, scales.y, 0, 0,                  //                [0,  sy, 0,  0]
            0, 0, scales.z, 0,                  //                [0,  0,  sz, 0]
            0, 0, 0, 1};                        //                [0,  0,  0,  1]
}

Matrix4x4 Matrix4x4::createScale(double scale, Vector3 &center) {
    Matrix4x4 m;
    double tx = (1 - scale) * center.x;
    double ty = (1 - scale) * center.y;
    double tz = (1 - scale) * center.z;
    m = {scale, 0, 0, tx,                        //S(s) = [s, 0, 0, tx]
         0, scale, 0, ty,                        //       [0, s, 0, ty]
         0, 0, scale, tz,                        //       [0, 0, s, tz]
         0, 0, 0, 1};                            //       [0, 0, 0, 1]
    return m;
}

Matrix4x4 Matrix4x4::createScale(double sx, double sy, double sz, Vector3 &center) {
    Matrix4x4 m;
    double tx = (1 - sx) * center.x;
    double ty = (1 - sy) * center.y;
    double tz = (1 - sz) * center.z;
    m = {sx, 0, 0, tx,                          //S(sx, sy, sz) = [sx, 0,  0,  tx]
         0, sy, 0, ty,                          //                [0,  sy, 0,  ty]
         0, 0, sz, tz,                          //                [0,  0,  sz, tz]
         0, 0, 0, 1};                           //                [0,  0,  0,  1]
    return m;
}

Matrix4x4 Matrix4x4::createScale(Vector3 &scales, Vector3 &center) {
    Matrix4x4 m;
    double tx = (1 - scales.x) * center.x;
    double ty = (1 - scales.y) * center.y;
    double tz = (1 - scales.z) * center.z;
    m = {scales.x, 0, 0, tx,                    //S(sx, sy, sz) = [sx, 0,  0,  tx]
         0, scales.y, 0, ty,                    //                [0,  sy, 0,  ty]
         0, 0, scales.z, tz,                    //                [0,  0,  sz, tz]
         0, 0, 0, 1};                           //                [0,  0,  0,  1]
    return m;

}

Matrix4x4 Matrix4x4::createTranslation(double tx, double ty, double tz) {
    return {1, 0, 0, tx,                       //T(tx, ty, tz) = [1, 0, 0, tx]
            0, 1, 0, ty,                       //               [0, 1, 0, ty]
            0, 0, 1, tz,                       //               [0, 0, 1, tz]
            0, 0, 0, 1};                       //               [0, 0, 0, 1]
}

Matrix4x4 Matrix4x4::createTranslation(Vector3 &position) {
    return {1, 0, 0, position.x,                //T(tx, ty, tz) = [1, 0, 0, tx]
            0, 1, 0, position.y,                //               [0, 1, 0, ty]
            0, 0, 1, position.z,                //               [0, 0, 1, tz]
            0, 0, 0, 1};                        //               [0, 0, 0, 1]
}

