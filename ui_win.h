/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QRadioButton>
#include <QTimeEdit>
#include <QTextEdit>
#include <QDialog>

QT_BEGIN_NAMESPACE

class Ui_Dialog {
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QTimeEdit *timeEdit;
    QTextEdit *textEdit;

    explicit Ui_Dialog(QTimeEdit *timeEdit) : timeEdit(timeEdit) {}

    explicit Ui_Dialog() {}

//    void setupUi(QDialog *Dialog) {
//        if (Dialog->objectName().isEmpty())
//            Dialog->setObjectName(QString::fromUtf8("Dialog"));
//        Dialog->resize(1024, 768);
//        Dialog->setWindowTitle("1024*768 Window");
//        buttonBox = new QDialogButtonBox(Dialog);
//        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
//        buttonBox->setGeometry(QRect(30, 240, 341, 32));
//        buttonBox->setOrientation(Qt::Horizontal);
//        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
//        pushButton = new QPushButton(Dialog);
//        pushButton->setObjectName(QString::fromUtf8("pushButton"));
//        pushButton->setGeometry(QRect(110, 90, 113, 32));
//        radioButton = new QRadioButton(Dialog);
//        radioButton->setObjectName(QString::fromUtf8("radioButton"));
//        radioButton->setGeometry(QRect(320, 110, 99, 20));
//        timeEdit = new QTimeEdit(Dialog);
//        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
//        timeEdit->setGeometry(QRect(70, 20, 118, 22));
//        textEdit = new QTextEdit(Dialog);
//        textEdit->setObjectName(QString::fromUtf8("textEdit"));
//        textEdit->setGeometry(QRect(70, 140, 104, 71));

//        retranslateUi(Dialog);
//        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
//        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

//        QMetaObject::connectSlotsByName(Dialog);
//    }

    void setupUi(QWidget *Win)
    {
        if (Win->objectName().isEmpty())
            Win->setObjectName(QString::fromUtf8("Win"));
        Win->resize(1024, 768);
        Win->setWindowTitle("1024*768 Window");
    }

    void retranslateUi(QDialog *Dialog) {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        radioButton->setText(QCoreApplication::translate("Dialog", "RadioButton", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Dialog",
                                                      "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                      "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                                                      "p, li { white-space: pre-wrap; }\n"
                                                      "</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
                                                      "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">hello</span></p></body></html>",
                                                      nullptr));
    } // retranslateUi

//    void retranslateUi(QWidget *Win)
//    {
//        Win->setWindowTitle(QCoreApplication::translate("Win", "Win", nullptr));
//    } // retranslateUi

};

class Ui_Widget {
public:
    explicit Ui_Widget() {}

    void setupUi(QWidget *Win)
    {
        if (Win->objectName().isEmpty())
            Win->setObjectName(QString::fromUtf8("Win"));
        Win->resize(1024, 768);
        Win->setWindowTitle("1024*768 Window");
    }

};

namespace Ui {
    class Dialog : public Ui_Dialog {
    };

    class Widget: public Ui_Widget{
    };

    class Draw: public Ui_Widget{
    };
} // namespace Ui

//namespace Ui {
//    class Win: public Ui_Win {};
//} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
