#include "loginpage.h"
#include "ikanbubblesort.h"
#include "ui_loginpage.h"
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username=="admin" && password=="admin123"){
        QMessageBox::information(this,"Info Login", "Login Berhasil");
        this->hide();
        IkanBubbleSort *ikanBubbleSort = new IkanBubbleSort();
        ikanBubbleSort->show();

    }else{
        QMessageBox::information(this,"Info Login", "Login Gagal, Username atau Password Salah");
    }
}

