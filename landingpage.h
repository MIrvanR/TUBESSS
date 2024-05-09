#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QMainWindow>

namespace Ui {
class LandingPage;
}

class LandingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LandingPage(QWidget *parent = nullptr);
    ~LandingPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LandingPage *ui;
};

#endif // LANDINGPAGE_H
