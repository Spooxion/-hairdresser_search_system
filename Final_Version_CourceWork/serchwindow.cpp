#include "serchwindow.h"
#include "ui_serchwindow.h"

SerchWindow::SerchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerchWindow)
{
    ui->setupUi(this);
}

SerchWindow::~SerchWindow()
{
    delete ui;
}

void SerchWindow::on_pushButton_clicked()
{
    this->close();
}
