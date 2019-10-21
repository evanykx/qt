#include "widget.h"
#include "ui_widget.h"
#include "dlgsample.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->btn, &QPushButton::clicked, this, &Widget::onBtnClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_clicked()
{
   DlgSample *dlg = new DlgSample;
   dlg->show();
}
