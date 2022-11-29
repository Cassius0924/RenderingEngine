//
// Create by HoChihchou on 2022/11/14
//

#ifndef RENDERINGENGINE_MATRIX4X4_H
#define RENDERINGENGINE_MATRIX4X4_H

#include "Vector4.h"
#include "Vector3.h"

using namespace std;

//实现MATRIX4，包括转置短阵，矩阵与向量的乘法问题（左乘，右乘)
//关于Matrix4x4的介绍，为什么要用4x4的矩阵
//可以看这期视频：https://www.bilibili.com/video/BV1b34y1y7nF
//以及这篇文章：https://zhuanlan.zhihu.com/p/261097735

class Matrix4x4 {
public:
    double a[4][4];

    Matrix4x4();

    explicit Matrix4x4(double value);

    explicit Matrix4x4(double values[4][4]);

    Matrix4x4(double a11, double a12, double a13, double a14,
              double a21, double a22, double a23, double a24,
              double a31, double a32, double a33, double a34,
              double a41, double a42, double a43, double a44);

    static Matrix4x4 identity();  //返回单位矩阵
    static Matrix4x4 zero();      //返回零矩阵

    //Matrix4x4 inverse();        //返回逆矩阵
    Matrix4x4 transpose();      //返回转置矩阵

    //矩阵乘法：左乘行变换，右乘列变换
    Matrix4x4 mul(Matrix4x4 &mat);

    Matrix4x4 mul(double v);

    static Matrix4x4 mul(Matrix4x4 &lMat, Matrix4x4 &rMat);

    Matrix4x4 operator*(const Matrix4x4 &mat) const;

    Matrix4x4 operator*=(Matrix4x4 &mat);

    Matrix4x4 operator*(double v);

    friend Matrix4x4 operator*(double v,const Matrix4x4 &mat);  //加上友元函数修饰符friend之后，这个函数不再是类的成员函数

    Matrix4x4 operator-();

    //矩阵与向量的乘法
    //Matrix4x4 mul(Vector4 &v);

    //旋转矩阵
    //Rx(a) = [1, 0     , 0,       0]
    //        [0, cos(a), -sin(a), 0]
    //        [0, sin(a), cos(a),  0]
    //        [0, 0     , 0,       1]
    static Matrix4x4 createRotationX(double angle);

    //Ry(a) = [cos(a), 0, sin(a), 0]
    //        [0     , 1, 0     , 0]
    //        [-sin(a),0, cos(a), 0]
    //        [0     , 0, 0     , 1]
    static Matrix4x4 createRotationY(double angle);

    //Rz(a) = [cos(a), -sin(a), 0, 0]
    //        [sin(a), cos(a),  0, 0]
    //        [0     , 0     ,  1, 0]
    //        [0     , 0     ,  0, 1]
    static Matrix4x4 createRotationZ(double angle);


    //缩放矩阵
    //S = [Sx, 0, 0, 0]
    //    [0, Sy, 0, 0]
    //    [0, 0, Sz, 0]
    //    [0, 0, 0,  1]
    static Matrix4x4 createScale(double s);  //x,y,z方向等比例缩放

    static Matrix4x4 createScale(double sx, double sy, double sz);   //x,y,z方向不等比例缩放

    static Matrix4x4 createScale(double sx, double sy, double sz, Vector3 &center);  //以center为中心，x,y,z方向不等比例缩放


    //平移矩阵
    //T = [1, 0, 0, Tx]
    //    [0, 1, 0, Ty]
    //    [0, 0, 1, Tz]
    //    [0, 0, 0, 1]
    static Matrix4x4 createTranslation(double tx, double ty, double tz);

    static Matrix4x4 createTranslation(Vector3 &translation);

};


#endif //RENDERINGENGINE_MATRIX4X4_H
