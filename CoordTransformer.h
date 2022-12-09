//
// Create by HoChihchou on 2022/12/9
//

#ifndef RENDERINGENGINE_COORDTRANSFORMER_H
#define RENDERINGENGINE_COORDTRANSFORMER_H

#include "Matrix4x4.h"
#include "Vector3.h"
#include "Vector4.h"


//坐标系变换，视图变换（MVP变换）
//投影变换、视口变换
//参考视频：https://www.bilibili.com/video/BV1ZK411x7Zp?p=3（GAMES101-现代计算机图形学入门-闫令琪）
class CoordTransformer {
public:
    CoordTransformer();

    ~CoordTransformer();

    //视图变换（摄像机变换）
    static Matrix4x4 lookAt(Vector3 eye, Vector3 center, Vector3 up);

    //正交投影变换
    static Matrix4x4 orthographic(float left, float right, float bottom, float top, float zNear, float zFar);

    //投影投影变换
    static Matrix4x4 perspective(float fovy, float aspect, float zNear, float zFar);

    //视口变换
    static Matrix4x4 viewport(int x, int y, int w, int h);
};


#endif //RENDERINGENGINE_COORDTRANSFORMER_H
