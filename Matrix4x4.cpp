//
// Create by HoChihchou on 2022/11/14
//

#include "Matrix4x4.h"

Matrix4x4::Matrix4x4() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = 0;
        }
    }
}

Matrix4x4::Matrix4x4(double value) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = value;
        }
    }
}

Matrix4x4::Matrix4x4(double values[4][4]) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = values[i][j];
        }
    }
};

Matrix4x4::Matrix4x4(double a11, double a12, double a13, double a14,
                     double a21, double a22, double a23, double a24,
                     double a31, double a32, double a33, double a34,
                     double a41, double a42, double a43, double a44){
    a[0][0] = a11; a[0][1] = a12; a[0][2] = a13; a[0][3] = a14;
    a[1][0] = a21; a[1][1] = a22; a[1][2] = a23; a[1][3] = a24;
    a[2][0] = a31; a[2][1] = a32; a[2][2] = a33; a[2][3] = a34;
    a[3][0] = a41; a[3][1] = a42; a[3][2] = a43; a[3][3] = a44;
}

Matrix4x4 Matrix4x4::identity() {
    Matrix4x4 m;
    m = {1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1};
    return m;
}

Matrix4x4 Matrix4x4::zero() {
    return {};
}

Matrix4x4 Matrix4x4::inverse() {

}

Matrix4x4 Matrix4x4::transpose() {
Matrix4x4 m;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m.a[i][j] = a[j][i];
        }
    }
    return m;
}




