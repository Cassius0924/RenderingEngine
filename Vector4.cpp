//
// Create by HoChihchou on 2022/11/14
//

#include "Vector4.h"
#include "cmath"

Vector4::Vector4(): x(0), y(0), z(0), w(0) {}

Vector4::Vector4(double x, double y, double z, double w): x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector3 &v, double w): x(v.x), y(v.y), z(v.z), w(w) {}

Vector4::Vector4(double v): x(v), y(v), z(v), w(v) {}

double Vector4::dot(const Vector4 &v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

double Vector4::operator*(const Vector4 &v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vector4 Vector4::cross(const Vector4 &v) const {
    return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0};
}

Vector4 &Vector4::cross(const Vector4 &l, const Vector4 &r) {
    x = l.y * r.z - l.z * r.y;
    y = l.z * r.x - l.x * r.z;
    z = l.x * r.y - r.y * l.x;
    w = 0;
    return *this;
}

Vector4 Vector4::add(const Vector4 &v) const {
    return {x + v.x, y + v.y, z + v.z, w + v.w};
}

Vector4 Vector4::operator+(const Vector4 &v) const {
    return {x + v.x, y + v.y, z + v.z, w + v.w};
}

Vector4 &Vector4::operator+=(const Vector4 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vector4 Vector4::sub(const Vector4 &v) const {
    return {x - v.x, y - v.y, z - v.z, w - v.w};
}

Vector4 Vector4::operator-(const Vector4 &v) const {
    return {x - v.x, y - v.y, z - v.z, w - v.w};
}

Vector4 &Vector4::operator-=(const Vector4 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vector4 Vector4::mul(double v) const {
    return {x * v, y * v, z * v, w * v};
}

Vector4 Vector4::operator*(double v) const {
    return {x * v, y * v, z * v, w * v};
}

Vector4 operator*(double v, const Vector4 &vec) {
    return {vec.x * v, vec.y * v, vec.z * v, vec.w * v};
}

Vector4 &Vector4::operator*=(double v) {
    x *= v;
    y *= v;
    z *= v;
    w *= v;
    return *this;
}

Vector4 Vector4::div(double v) const {
    return {x / v, y / v, z / v, w / v};
}

Vector4 Vector4::operator/(double v) const {
    return {x / v, y / v, z / v, w / v};
}

Vector4 &Vector4::operator/=(double v) {
    x /= v;
    y /= v;
    z /= v;
    w /= v;
    return *this;
}

double Vector4::length() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::normalize() const{
    double len = length();
    return {x / len, y / len, z / len, w / len};
}

Vector4 Vector4::lerp(const Vector4 &v, double t) const {
    return *this + (v - *this) * t;
}

bool Vector4::operator==(const Vector4 &v) const {
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

bool Vector4::operator!=(const Vector4 &v) const {
    return !(v == *this);
}

ostream &operator<<(ostream &os, const Vector4 &v) {
    os << "Vector4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return os;
}

Vector4 Vector4::operator-() const {
    return {-x, -y, -z, -w};
}

Vector4 Vector4::abs() const {
    return {fabs(x), fabs(y), fabs(z), fabs(w)};
}

double Vector4::distance(const Vector4 &v) const {
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z) + (w - v.w) * (w - v.w));
}

