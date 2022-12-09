//
// Create by HoChihchou on 2022/12/9
//

#include "CoordTransformer.h"

CoordTransformer::CoordTransformer() = default;

CoordTransformer::~CoordTransformer() = default;

//视图变换（摄像机变换），就是将世界坐标系变换到观察坐标系，本质上是将物体进行平移再进行旋转。
//步骤如下：
//1. 将摄像机位置平移到原点
//2. 将-f向量旋转到Z轴上
//3. 将u向量旋转到Y轴上
//4. 将r向量旋转到X轴上
//参考文章：https://blog.csdn.net/lyzirving/article/details/125817816
Matrix4x4 CoordTransformer::lookAt(Vector3 eye, Vector3 center, Vector3 up) {
    //eye是摄像机的位置，center是摄像机所观察的物体的位置，up是摄像机的上方向
    //建立摄像机坐标系（CameraCoordination）
    Vector3 f = (center - eye).normalize();     //f是摄像机的前方向
    Vector3 r = f.cross(up).normalize();    //r是摄像机的右方向
    Vector3 u = r.cross(f);                 //u是摄像机的上方向

    //旋转矩阵是正交阵，所以其逆矩阵等于其转置矩阵。因此可以将坐标轴XYZ旋转到坐标轴ruf上，然后求其转置矩阵，即可得到旋转矩阵。
    Matrix4x4 ViewMatrix = Matrix4x4(
            r.x, r.y, r.z, -eye.x,
            u.x, u.y, u.z, -eye.y,
            f.x, f.y, f.z, -eye.z,
            0, 0, 0, 1
    );
    return ViewMatrix;      //返回视图变换矩阵
}


//正交投影，没有近大远小的关系。
//NDC标准化设备坐标系
//参考文章：https://blog.csdn.net/lyzirving/article/details/125860578
Matrix4x4 CoordTransformer::orthographic(float left, float right, float bottom, float top, float zNear, float zFar) {
    //缩放矩阵参数
    double sx = 2 / (right - left);
    double sy = 2 / (top - bottom);
    double sz = 2 / (zNear - zFar);
    //平移矩阵参数
    double tx = -(right + left) / (right - left);
    double ty = -(top + bottom) / (top - bottom);
    double tz = -(zFar + zNear) / (zFar - zNear);
    Matrix4x4 OrthoMatrix = Matrix4x4(
            sx, 0, 0, tx,
            0, sy, 0, ty,
            0, 0, sz, tz,
            0, 0, 0, 1
    );
    return OrthoMatrix;
}

//透视投影，物体近大远小
//参考文章：https://blog.csdn.net/lyzirving/article/details/125860578
Matrix4x4 CoordTransformer::perspective(float fovy, float aspect, float zNear, float zFar) {

}

//视口变换
//参考文章：https://blog.csdn.net/lyzirving/article/details/125860578
Matrix4x4 CoordTransformer::viewport(int x, int y, int w, int h) {

}