#include "landingpage.h"
#include "loginpage.h"
#include "ui_landingpage.h"

LandingPage::LandingPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LandingPage)
{
    ui->setupUi(this);
    ui->label->setText("<font color='#ffbc12'>AquaGuide</font>");
    QPixmap bkgnd("E:/IkanBubbleSort/ikan.jpeg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

LandingPage::~LandingPage()
{
    delete ui;
}

void LandingPage::on_pushButton_clicked()
{
    this->hide();
    LoginPage *loginPage = new LoginPage();
    loginPage->show();
}

