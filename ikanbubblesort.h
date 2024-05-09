#ifndef IKANBUBBLESORT_H
#define IKANBUBBLESORT_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class IkanBubbleSort;
}

class IkanBubbleSort : public QMainWindow
{
    Q_OBJECT

public:
    explicit IkanBubbleSort(QWidget *parent = nullptr);
    ~IkanBubbleSort();

private slots:
    void on_pushButtonJenisAsc_clicked();
    void on_pushButtonJenisDesc_clicked();
    void on_pushButtonBeratAsc_clicked();
    void on_pushButtonBeratDesc_clicked();
    void on_pushButton_clicked();

    void on_pushButtonHapus_clicked();

    void on_pushUpdate_clicked();

    void on_pushButtonIkanAsc_clicked();

    void on_pushButtonIkanDesc_clicked();

private:
    Ui::IkanBubbleSort *ui;
    QVector<QVector<QString>> dataArray; // Declare dataArray here
};

#endif // IKANBUBBLESORT_H
