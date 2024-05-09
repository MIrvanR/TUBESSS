#include "ikanbubblesort.h"
#include "./ui_ikanbubblesort.h"
#include <QStandardItemModel>
#include <QMessageBox>

IkanBubbleSort::IkanBubbleSort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IkanBubbleSort)
{
    ui->setupUi(this);

    // Membuat model untuk tableView
    QStandardItemModel *model = new QStandardItemModel(this);

    // Menambahkan header ke model
    QStringList headers = {"Ikan", "Jenis", "Berat"};
    model->setHorizontalHeaderLabels(headers);

    int rows = 100;
    int cols = 3;
    dataArray = {
        {"Buntal", "Tongkol", "Udang"},
        {"Tidak bisa dimakan", "Bisa dimakan", "Bisa dimakan"},
        {"1.5", "5.3", "3.7"}
    };

    // Menambahkan data ke model
    for (int i = 0; i < 3; ++i) {
        QList<QStandardItem*> rowItems;
        for (int j = 0; j < cols; ++j) {
            QStandardItem *item = new QStandardItem(dataArray[j][i]);
            rowItems.append(item);
        }
        model->appendRow(rowItems);
    }

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

IkanBubbleSort::~IkanBubbleSort()
{
    delete ui;
}


// Tambah Data
void IkanBubbleSort::on_pushButton_clicked()
{
    QString ikan = ui->lineEditIkan->text();
    QString jenis = ui->lineEditJenis->text();
    QString berat = ui->lineEditBerat->text();

    if (ikan.isEmpty() || jenis.isEmpty() || berat.isEmpty()) {
        QMessageBox::warning(this, "Error", "Semua data harus diisi!");
        return;
    }

    float beratFloat = berat.toFloat();

    if (beratFloat <= 0) {
        QMessageBox::warning(this, "Error", "Jumlah dan berat harus berupa angka positif!");
        return;
    }

    QVector<QString> dataRow = {ikan, jenis, berat};
    dataArray.append(dataRow);

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    QList<QStandardItem*> rowItems;
    for (const QString &data : dataRow) {
        rowItems.append(new QStandardItem(data));
    }

    model->appendRow(rowItems);

    QMessageBox::information(this, "Success", "Data has been added successfully!");

    ui->lineEditIkan->clear();
    ui->lineEditJenis->clear();
    ui->lineEditBerat->clear();

    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonHapus_clicked()
{
    QString ikan = ui->lineHapusIkan->text();

    if (ikan.isEmpty()) {
        QMessageBox::warning(this, "Error", "Data must be filled!");
        return;
    }

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowToDelete = -1;
    for (int i = 0; i < model->rowCount(); ++i) {
        QString currentikan = model->data(model->index(i, 0)).toString();
        if (currentikan == ikan) {
            rowToDelete = i;
            break;
        }
    }

    if (rowToDelete != -1) {
        model->removeRow(rowToDelete);
        QMessageBox::information(this, "Success", "Data has been deleted successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Data not found!");
    }

    ui->lineEditIkan->clear();

    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonIkanAsc_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QString ikan1 = model->data(model->index(j, 0)).toString();
            QString ikan2 = model->data(model->index(j + 1, 0)).toString();

            if (ikan1.compare(ikan2) > 0) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QStandardItem *item1 = model->takeItem(j, col);
                    QStandardItem *item2 = model->takeItem(j + 1, col);
                    model->setItem(j, col, item2);
                    model->setItem(j + 1, col, item1);
                }
            }
        }
    }
    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonIkanDesc_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QString ikan1 = model->data(model->index(j, 0)).toString();
            QString ikan2 = model->data(model->index(j + 1, 0)).toString();

            if (ikan2.compare(ikan1) > 0) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QStandardItem *item1 = model->takeItem(j, col);
                    QStandardItem *item2 = model->takeItem(j + 1, col);
                    model->setItem(j, col, item2);
                    model->setItem(j + 1, col, item1);
                }
            }
        }
    }
    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonJenisAsc_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QString jenis1 = model->data(model->index(j, 1)).toString();
            QString jenis2 = model->data(model->index(j + 1, 1)).toString();

            if (jenis1.compare(jenis2) > 0) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QStandardItem *item1 = model->takeItem(j, col);
                    QStandardItem *item2 = model->takeItem(j + 1, col);
                    model->setItem(j, col, item2);
                    model->setItem(j + 1, col, item1);
                }
            }
        }
    }
    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonJenisDesc_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QString jenis1 = model->data(model->index(j, 1)).toString();
            QString jenis2 = model->data(model->index(j + 1, 1)).toString();

            if (jenis2.compare(jenis1) > 0) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QStandardItem *item1 = model->takeItem(j, col);
                    QStandardItem *item2 = model->takeItem(j + 1, col);
                    model->setItem(j, col, item2);
                    model->setItem(j + 1, col, item1);
                }
            }
        }
    }
    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonBeratAsc_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QString berat1 = model->data(model->index(j, 2)).toString();
            QString berat2 = model->data(model->index(j + 1, 2)).toString();

            if (berat1.compare(berat2) > 0) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QStandardItem *item1 = model->takeItem(j, col);
                    QStandardItem *item2 = model->takeItem(j + 1, col);
                    model->setItem(j, col, item2);
                    model->setItem(j + 1, col, item1);
                }
            }
        }
    }
    ui->tableView->reset();
}


void IkanBubbleSort::on_pushButtonBeratDesc_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QString berat1 = model->data(model->index(j, 2)).toString();
            QString berat2 = model->data(model->index(j + 1, 2)).toString();

            if (berat2.compare(berat1) > 0) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QStandardItem *item1 = model->takeItem(j, col);
                    QStandardItem *item2 = model->takeItem(j + 1, col);
                    model->setItem(j, col, item2);
                    model->setItem(j + 1, col, item1);
                }
            }
        }
    }
    ui->tableView->reset();
}


void IkanBubbleSort::on_pushUpdate_clicked()
{
    QString oldIkan = ui->lineUpdateIkan->text();
    QString newIkan = ui->lineEditIkan_2->text();
    QString newJenis = ui->lineEditJenis_2->text();
    QString newBerat = ui->lineEditBerat_2->text();

    if (oldIkan.isEmpty() || newIkan.isEmpty() || newJenis.isEmpty() || newBerat.isEmpty()) {
        QMessageBox::warning(this, "Error", "All data must be filled!");
        return;
    }

    bool beratOk;
    float beratFloat = newBerat.toFloat(&beratOk);

    if (!beratOk || beratFloat <= 0) {
        QMessageBox::warning(this, "Error", "Berat must be a positive number!");
        return;
    }

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());


    int rowToUpdate = -1;
    for (int i = 0; i < model->rowCount(); ++i) {
        QString currentikan = model->data(model->index(i, 0)).toString();
        if (currentikan == oldIkan) {
            rowToUpdate = i;
            break;
        }
    }

    if (rowToUpdate != -1) {
        model->setItem(rowToUpdate, 0, new QStandardItem(newIkan));
        model->setItem(rowToUpdate, 1, new QStandardItem(newJenis));
        model->setItem(rowToUpdate, 2, new QStandardItem(newBerat));
        QMessageBox::information(this, "Success", "Data has been updated successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Data not found!");
    }

    ui->lineUpdateIkan->clear();
    ui->lineEditIkan_2->clear();
    ui->lineEditJenis_2->clear();
    ui->lineEditBerat_2->clear();

    ui->tableView->reset();
}
