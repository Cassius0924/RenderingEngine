//
// Create by HoChihchou on 2022/11/14
//
//实现MATRIX4，包括转置短阵，矩阵与向量的乘法问题（左乘，右乘)

#ifndef RENDERINGENGINE_MATRIX4_H
#define RENDERINGENGINE_MATRIX4_H

#include <vector>

using namespace std;

class Matrix4 {
private:
    vector<vector<double>> m;

public:
    explicit Matrix4(const vector<vector<double>> &m);      //了解 explicit ?

};


#endif //RENDERINGENGINE_MATRIX4_H
