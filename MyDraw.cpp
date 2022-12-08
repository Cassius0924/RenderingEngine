//
// Create by HoChihchou on 2022/12/6
//

#include "MyDraw.h"

MyDraw::MyDraw(QWidget *parent) : QMainWindow(parent), ui(new Ui::Draw) {
    ui->setupUi(this);
    m_image = QImage(width(), height(), QImage::Format_RGB32);
    m_image.fill(Qt::white);
    painter.begin(&m_image);
}

MyDraw::~MyDraw() {
    delete ui;
}

void MyDraw::drawLine(int x1, int y1, int x2, int y2) {  //调用QPainter的drawLine函数
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);

    painter.drawLine(x1, y1, x2, y2);
    update();
}

//DDA算法
void MyDraw::drawLineByDDA(int x1, int y1, int x2, int y2) {
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    //Qt的坐标系与数学坐标系不同，y轴向下，图如下
    //  |(4)/
    //  |  /
    //  | / (3) x
    //  |------->
    //  | \ (1)
    //  |  \
    // y|(2)\
    //  V
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);    //取最大值，即为步长
    float xInc = dx / steps;    //x增量
    float yInc = dy / steps;    //y增量
    float x = x1;   //起点
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        painter.drawPoint((int) (x + 0.5), (int) (y + 0.5));
        x += xInc;  //xInc为正时，x轴向右
        y += yInc;  //yInc为正时，y轴向下
    }
    update();
}

//Bresenham算法
void MyDraw::drawLineByBresenham(int x1, int y1, int x2, int y2) {
    pen.setWidth(1);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    int dx = abs(x2 - x1);  //x轴距离
    int dy = abs(y2 - y1);  //y轴距离
    bool bInterChange = false;      //是否交换x和y
    int signX = x1 < x2 ? 1 : -1;   //x轴增量
    int signY = y1 < y2 ? 1 : -1;   //y轴增量
    int e = -dx;        //初始误差
    if (dy > dx) {      //如果y轴距离大于x轴距离，交换x和y
        int temp = dx;
        dx = dy;
        dy = temp;
        bInterChange = true;    //交换标志置为true
    }
    int x = x1;
    int y = y1;
    for (int i = 0; i <= dx; i++) {
        painter.drawPoint(x, y);
        if (e + dy >= 0) {
            if (bInterChange) { //如果交换了x和y，x轴增量为y轴增量
                x += signX;
            } else {            //否则，y轴增量为x轴增量
                y += signY;
            }
            e -= dx;    //减去x轴距离
        }
        if (bInterChange) { //如果交换了x和y，y轴增量
            y += signY;
        } else {            //否则，x轴增量
            x += signX;
        }
        e += dy;    //误差累加
    }
}

void MyDraw::paintEvent(QPaintEvent *event) {   //重写paintEvent函数，paintEvent函数在窗口显示时会被调用
    QPainter painter1(this);    //创建QPainter对象，用于在窗口上绘图，this表示当前窗口
    painter1.drawImage(0, 0, m_image);  //将m_image绘制到窗口上，起始坐标为(0,0)
}



