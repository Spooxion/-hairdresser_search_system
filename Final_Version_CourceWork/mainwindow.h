#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPixmap>
#include <iostream>
#include "client.h"
#include <QLineEdit>
#include <QMenu>
#include <QHeaderView>
#include <vector>
#include "serchwindow.h"
#include <QDate>
#include <QTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellPressed(int row, int column);

    void on_pushButton_2_clicked();





    void on_pushButton_3_clicked();

private:
      Ui::MainWindow *ui;
      std::vector <Client*> client_vector;
      QStringList columns;
      QStringList rows;
      SerchWindow *serch;

      unsigned int counter = 0;
      int chosed_column;
      int chosed_row;

};

#endif // MAINWINDOW_H
