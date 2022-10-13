#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(ui->rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(ui->rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_checkBoxUderline_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(true);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(true);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(true);
    ui->plainTextEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette palette = ui->plainTextEdit->palette();
    if(ui->rBtnRed->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if(ui->rBtnBlue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    else if(ui->rBtnBlack->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else
        palette.setColor(QPalette::Text, Qt::black);

    ui->plainTextEdit->setPalette(palette);
}
