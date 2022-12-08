//
// Create by HoChihchou on 2022/12/7
//

//进行功能性测试

#include <iostream>
#include "Matrix4x4.h"
#include "Vector3.h"
#include "MyDraw.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyDraw drawWin(nullptr);
    drawWin.drawLineByBresenham(100, 100, 150, 120);
    drawWin.drawLineByBresenham(100, 100, 120, 150);
    drawWin.drawLineByBresenham(100, 100, 80, 150);
    drawWin.drawLineByBresenham(100, 100, 50, 120);
    drawWin.drawLineByBresenham(100, 100, 50, 80);
    drawWin.drawLineByBresenham(100, 100, 80, 50);
    drawWin.drawLineByBresenham(100, 100, 120, 50);
    drawWin.drawLineByBresenham(100, 100, 150, 80);
//    drawWin.drawLineByDDA(100, 100, 150, 120);
//    drawWin.drawLineByDDA(100, 100, 120, 150);
//    drawWin.drawLineByDDA(100, 100, 80, 150);
//    drawWin.drawLineByDDA(100, 100, 50, 120);
//    drawWin.drawLineByDDA(100, 100, 50, 80);
//    drawWin.drawLineByDDA(100, 100, 80, 50);
//    drawWin.drawLineByDDA(100, 100, 120, 50);
//    drawWin.drawLineByDDA(100, 100, 150, 80);
    drawWin.show();
    return QApplication::exec();
}
