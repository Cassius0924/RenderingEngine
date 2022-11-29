//
// Create by HoChihchou on 2022/11/14
//

#ifndef RENDERINGENGINE_VECTOR4_H
#define RENDERINGENGINE_VECTOR4_H

#include "Vector3.h"

class Vector4{
public:
    double x;
    double y;
    double z;
    double w;

    Vector4();

    Vector4(double x, double y, double z, double w);

    Vector4(const Vector3 &v,double w);

    explicit Vector4(double v);

    double dot(const Vector4 &v) const;

    double operator*(const Vector4 &v) const;

    Vector4 cross(const Vector4 &v) const;

    Vector4 &cross(const Vector4 &l,const Vector4 &r);

    Vector4 add(const Vector4 &v) const;

    Vector4 operator+(const Vector4 &v) const;

    Vector4 &operator+=(const Vector4 &v);

    Vector4 sub(const Vector4 &v) const;

    Vector4 operator-(const Vector4 &v) const;

    Vector4 &operator-=(const Vector4 &v);

    Vector4 mul(double v) const;

    Vector4 operator*(double v) const;

    friend Vector4 operator*(double v,const Vector4 &vec);  //加上友元函数修饰符friend之后，这个函数不再是类的成员函数

    Vector4 &operator*=(double v);

    Vector4 div(double v) const;

    Vector4 operator/(double v) const;

    Vector4 &operator/=(double v);

    double length() const;

    Vector4 normalize() const;

    Vector4 lerp(const Vector4 &v,double t) const;

    bool operator==(const Vector4 &v) const;

    bool operator!=(const Vector4 &v) const;

    friend ostream &operator<<(ostream &os, const Vector4 &v);

    Vector4 operator-() const;

    Vector4 abs() const;

    double distance(const Vector4 &v) const;
};

#endif //RENDERINGENGINE_VECTOR4_H

















