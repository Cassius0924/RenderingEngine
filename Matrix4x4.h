//
// Create by HoChihchou on 2022/11/14
//
//实现MATRIX4，包括转置短阵，矩阵与向量的乘法问题（左乘，右乘)

#ifndef RENDERINGENGINE_MATRIX4X4_H
#define RENDERINGENGINE_MATRIX4X4_H

using namespace std;

class Matrix4x4 {
public:
    double a[4][4];

    Matrix4x4();
    Matrix4x4(double value);
    Matrix4x4(double values[4][4]);
    Matrix4x4(double a11, double a12, double a13, double a14,
              double a21, double a22, double a23, double a24,
              double a31, double a32, double a33, double a34,
              double a41, double a42, double a43, double a44);
    static Matrix4x4 identity();  //返回单位矩阵
    static Matrix4x4 zero();      //返回零矩阵

    Matrix4x4 inverse();        //返回逆矩阵
    Matrix4x4 transpose();      //返回转置矩阵




};


#endif //RENDERINGENGINE_MATRIX4X4_H
