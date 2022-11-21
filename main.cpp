#include <iostream>
#include "Matrix4.h"
#include "Vector3.h"

using namespace std;

int main() {
//    int *p = new int(3);
//    cout << *p;
//    delete p;

    Vector3 v0(0);
    Vector3 v1 = {1,3,4};
    Vector3 v2 = {1,2,4};

//    cout << &v1;
//    v1.cross(v0, v1);
    cout << (v1 += v2) << endl;
//    cout << (v1 -= v2) << endl;
    cout << v1 << endl;

    v1.normalized();

    cout << v1 << endl;
    cout << v1.length() << endl;

    4.0*v1;
    v1*4;

    Vector3 vv = v1;
    cout << vv << endl;
    cout << v1 << endl;
    cout << -v1 << endl;



    return 0;
}
