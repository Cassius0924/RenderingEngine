//
// Create by HoChihchou on 2022/11/14
//


#include "Vector3.h"
#include "cmath"

using namespace std;

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3::Vector3(double v) : x(v), y(v), z(v) {}

double Vector3::dot(const Vector3 &v) const {
    return x * v.x + y * v.y + z * v.z;
}

double Vector3::operator*(const Vector3 &v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};     //{}，大括号初始化，避免重复声明返回类型
}

Vector3 &Vector3::cross(const Vector3 &l, const Vector3 &r) {
    x = l.y * r.z - l.z * r.y;
    y = l.z * r.x - l.x * r.z;
    z = l.x * r.y - r.y * l.x;
    return *this;   //this是指针，*this解引用表示this类本身
}

Vector3 Vector3::add(const Vector3 &v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vector3 Vector3::operator+(const Vector3 &v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vector3 &Vector3::operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3 Vector3::sub(const Vector3 &v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vector3 &Vector3::operator-=(const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3 Vector3::mul(double v) const {
    return {x * v, y * v, z * v};
}

Vector3 Vector3::operator*(double v) const {
    return {x * v, y * v, z * v};
}

Vector3 operator*(double v, const Vector3 &vec) {
    return vec*v;
}

Vector3 &Vector3::operator*=(double v) {
    x *= v;
    y *= v;
    z *= v;
    return *this;
}

Vector3 Vector3::div(double v) const {
    return {x / v, y / v, z / v};
}

Vector3 Vector3::operator/(double v) const {
    if(v == 0) {    //除数为零
        return {};
    }
    return {x / v, y / v, z / v};
}

Vector3 &Vector3::operator/=(double v) {
    x /= v;
    y /= v;
    z /= v;
    return *this;
}

double Vector3::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalized() const{
    double len = length();
    return {x / len, y / len, z / len};
}

Vector3 Vector3::lerp(const Vector3 &endVec, double t) const {
    return *this + (endVec - *this) * t;
};

bool Vector3::operator==(const Vector3 &v) const {
    return x == v.x && y == v.y && z == v.z;
}

bool Vector3::operator!=(const Vector3 &v) const {
    return !(v == *this);
}

ostream &operator<<(ostream &os, const Vector3 &vector3) {
    os << "x:" << vector3.x << " y:" << vector3.y << " z:" << vector3.z;
    return os;
}

Vector3 Vector3::operator-() const {
    return {-x, -y, -z};
}

Vector3 Vector3::abs() const {
    return {fabs(x), fabs(y), fabs(z)};
}

double Vector3::distance(const Vector3 &v) const {
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
}

















