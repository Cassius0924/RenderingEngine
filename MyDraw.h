//
// Create by HoChihchou on 2022/12/6
//

#ifndef RENDERINGENGINE_DRAWLINE_H
#define RENDERINGENGINE_DRAWLINE_H

#endif //RENDERINGENGINE_DRAWLINE_H

#include "iostream"
#include "QPainter"
#include "QMainWindow"
#include "ui_win.h"

class MyDraw : public QMainWindow {
Q_OBJECT

private:
    QImage m_image;

public:
    explicit MyDraw(QWidget *parent = Q_NULLPTR);

    ~MyDraw() override;

    void drawLine(int x1, int y1, int x2, int y2);  //使用内置函数画线

    void drawLineByDDA(int x1, int y1, int x2, int y2); //使用DDA算法画线

    void drawLineByBresenham(int x1, int y1, int x2, int y2); //使用Bresenham算法画线

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Draw *ui;


};
