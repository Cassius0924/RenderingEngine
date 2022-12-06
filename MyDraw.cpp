//
// Create by HoChihchou on 2022/12/6
//

#include "MyDraw.h"

MyDraw::MyDraw(QWidget *parent) : QMainWindow(parent), ui(new Ui::Draw) {
    ui->setupUi(this);
    m_image = QImage(width(), height(), QImage::Format_RGB32);
    m_image.fill(Qt::white);
}

MyDraw::~MyDraw() {
    delete ui;
}

void MyDraw::drawLine(int x1, int y1, int x2, int y2) {  //调用QPainter的drawLine函数
    QPainter painter(&m_image);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(x1, y1, x2, y2);
    update();
}

//DDA算法
void MyDraw::drawLineByDDA(int x1, int y1, int x2, int y2) {
    QPainter painter(&m_image);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    float k = (float) (y2 - y1) / (x2 - x1);  //计算斜率
    if (x1 > x2) {  //保证x1小于x2
        int temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    if (k >= 0 && k <= 1) {  //斜率在0到1之间
        float y = y1;
        for (int x = x1; x <= x2; x++) {    //x正方向为主位移方向
            painter.drawPoint(x, (int) (y + 0.5));  //y+0.5再取整，四舍五入
            y += k;
        }
    } else if (k > 1) {  //斜率大于1
        float x = x1;
        for (int y = y1; y <= y2; y++) {    //y正方向为主位移方向
            painter.drawPoint((int) (x + 0.5), y);
            x += 1 / k;
        }
    } else if (k < 0 && k >= -1) {  //斜率在-1到0之间
        float y = y1;
        for (int x = x1; x <= x2; x++) {    //x正方向为主位移方向
            painter.drawPoint(x, (int) (y + 0.5));
            y += k;
        }
    } else if (k < -1) {  //斜率小于-1
        float x = x1;
        for (int y = y1; y >= y2; y--) {    //y负方向为主位移方向
            painter.drawPoint((int) (x + 0.5), y);
            x -= 1/k;
        }
    }
    update();
}

//Bresenham算法
void MyDraw::drawLineByBresenham(int x1, int y1, int x2, int y2) {

}


void MyDraw::paintEvent(QPaintEvent *event) {   //重写paintEvent函数，paintEvent函数在窗口显示时会被调用
    QPainter painter(this);
    painter.drawImage(0, 0, m_image);
}



