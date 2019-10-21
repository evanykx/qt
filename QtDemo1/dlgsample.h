#ifndef DLGSAMPLE_H
#define DLGSAMPLE_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>

//namespace Ui {
//class DlgSample;
//}
enum TXT_COLOR {
    Black,
    Red,
    Blue
};

class DlgSample : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSample(QWidget *parent = nullptr);
    ~DlgSample();

private:
//    Ui::DlgSample *ui;
    QCheckBox *chkUnder;
    QCheckBox *chkItalic;
    QCheckBox *chkBold;
    QRadioButton *rdBlack;
    QRadioButton *rdRed;
    QRadioButton *rdBlue;
    QPlainTextEdit *txtEdit;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QPushButton *btnClose;
    void initUi();
    void initSignalSlots();

private slots:
    void on_chkUnder_checked(bool checked);
    void on_chkItalic_checked(bool checked);
    void on_chkBold_checked(bool checked);
    void setTextFontColor(TXT_COLOR color);

};

#endif // DLGSAMPLE_H
