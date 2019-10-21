#include "dlgsample.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QFont>

DlgSample::DlgSample(QWidget *parent) :
    QDialog(parent)
{
    initUi();
    initSignalSlots();
    setWindowTitle("Mannual Dialog");
}

DlgSample::~DlgSample()
{
    // todo
}

void DlgSample::initUi()
{
    chkUnder = new QCheckBox(tr("Underline"));
    chkItalic = new QCheckBox(tr("Italic"));
    chkBold = new QCheckBox(tr("Bold"));
    QHBoxLayout *hLyt1 = new QHBoxLayout;
    hLyt1->addWidget(chkUnder);
    hLyt1->addWidget(chkItalic);
    hLyt1->addWidget(chkBold);

    rdBlack = new QRadioButton(tr("Black"));
    rdBlack->setChecked(true);
    rdRed = new QRadioButton(tr("Red"));
    rdBlue = new QRadioButton(tr("Blue"));
    QHBoxLayout *hLyt2 = new QHBoxLayout;
    hLyt2->addWidget(rdBlack);
    hLyt2->addWidget(rdRed);
    hLyt2->addWidget(rdBlue);

    btnOk = new QPushButton(tr("OK"));
    btnCancel = new QPushButton(tr("Cancel"));
    btnClose = new QPushButton(tr("Quit"));
    QHBoxLayout *hLyt3 = new QHBoxLayout;
    hLyt3->addStretch();
    hLyt3->addWidget(btnOk);
    hLyt3->addWidget(btnCancel);
    hLyt3->addStretch();
    hLyt3->addWidget(btnClose);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hi QT!");

    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout *vLyt = new QVBoxLayout;
    vLyt->addLayout(hLyt1);
    vLyt->addLayout(hLyt2);
    vLyt->addWidget(txtEdit);
    vLyt->addLayout(hLyt3);
    setLayout(vLyt);
}

void DlgSample::initSignalSlots()
{
    connect(rdBlack, &QRadioButton::clicked, this, [this]{setTextFontColor(Black);});
    connect(rdRed, &QRadioButton::clicked, this, [this]{setTextFontColor(Red);});
    connect(rdBlue, &QRadioButton::clicked, this, [this]{setTextFontColor(Blue);});

    connect(chkUnder, &QCheckBox::clicked, this, &DlgSample::on_chkUnder_checked);
    connect(chkItalic, &QCheckBox::clicked, this, &DlgSample::on_chkItalic_checked);
    connect(chkBold, &QCheckBox::clicked, this, &DlgSample::on_chkBold_checked);

    connect(btnOk, &QPushButton::clicked, this, &DlgSample::accept);
    connect(btnCancel, &QPushButton::clicked, this, &DlgSample::reject);
    connect(btnClose, &QPushButton::clicked, this, &DlgSample::close);
}

void DlgSample::on_chkUnder_checked(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void DlgSample::on_chkItalic_checked(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void DlgSample::on_chkBold_checked(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void DlgSample::setTextFontColor(TXT_COLOR color)
{
    QPalette pal = txtEdit->palette();
    if (color == Red) {
        pal.setColor(QPalette::Text, QColor(255, 0, 0));
    } else if (color == Blue) {
        pal.setColor(QPalette::Text, QColor(0, 0, 255));
    } else {
        pal.setColor(QPalette::Text, QColor(0, 0, 0));
    }
    txtEdit->setPalette(pal);

}

