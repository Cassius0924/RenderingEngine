//
// Create by HoChihchou on 2022/11/14
//

#ifndef RENDERINGENGINE_VECTOR3_H
#define RENDERINGENGINE_VECTOR3_H

#include <ostream>

using namespace std;

class Vector3 {
public:
    double x;
    double y;
    double z;

    //构造函数
    Vector3();

    Vector3(double x, double y, double z);

    explicit Vector3(double v);     //explicit 防止隐式转换，即不能用一个double类型的变量直接初始化一个Vector3类型的变量

    //点乘
    double dot(const Vector3 &v) const;    //const：不允许修改成员变量，不会对类中对任何成员变量进行修改

    double operator*(const Vector3 &v) const;

    //叉乘
    Vector3 cross(const Vector3 &v) const;

    Vector3 &cross(const Vector3 &l, const Vector3 &r);

    //加
    Vector3 add(const Vector3 &v) const;

    Vector3 operator+(const Vector3 &v) const;    //重载运算符

    Vector3 &operator+=(const Vector3 &v);    //需要改变类本身变量，不使用const

    //减
    Vector3 sub(const Vector3 &v) const;

    Vector3 operator-(const Vector3 &v) const;

    Vector3 &operator-=(const Vector3 &v);

    //乘
    Vector3 mul(double v) const;

    Vector3 operator*(double v) const;

    friend Vector3 operator*(double v,const  Vector3 &vec);    //实现double左乘Vector3，即double*Vector3；friend友元函数，可以访问类的私有成员

    Vector3 &operator*=(double v);

    //除
    Vector3 div(double v) const;

    Vector3 operator/(double v) const;

    Vector3 &operator/=(double v);

    //模
    double length() const;

    //标准化
    Vector3 normalize() const;

    Vector3 lerp(const Vector3 &v, double t) const;

    bool operator==(const Vector3 &v) const;

    bool operator!=(const Vector3 &v) const;

    friend ostream &operator<<(ostream &os, const Vector3 &vector3);

    Vector3 operator-() const;

    Vector3 abs() const;

    double distance(const Vector3 &v) const;
};

#endif //RENDERINGENGINE_VECTOR3_H
