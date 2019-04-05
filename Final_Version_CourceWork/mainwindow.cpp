#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap *backgnd = new QPixmap("C:\\Users\\azaza\\Documents\\Final_Version_CourceWork\\Images\\Images\\1.jpg");
    QPalette *palette = new QPalette;
    //QSize *sz = new QSize(this->size());
    //backgnd->scaled(*sz, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    palette->setBrush(QPalette::Window, QBrush(*backgnd));
    this->setPalette(*palette);

    ui->label->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_2->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_3->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_4->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_5->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_6->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_7->setStyleSheet("color: rgb(171, 171, 171)");
    ui->lineEdit_number->setValidator(new QDoubleValidator(0, 100, 2, this));

    client = new Client*[50];
    std::vector <Client> client_vector();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
        QString first_name = ui->lineEdit_firstname->text();
        QString last_name = ui->lineEdit_lastname->text();
        QString third_name = ui->lineEdit_thirdname->text();
        QString number = ui->lineEdit_number->text();
        QString last_service = ui->comboBox_lastservice->currentText();

        Client *b = new Client(first_name,last_name,third_name,number,last_service);
        this->client[counter]= b;

        QString buffer;
        buffer.setNum(counter + 1);
        rows.push_back(buffer);

        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setVerticalHeaderLabels(rows);


        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(this->client[counter]->getFirstName());
        ui->tableWidget->setItem(counter, 0, item);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText(this->client[counter]->getLastName());
        ui->tableWidget->setItem(counter, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(this->client[counter]->getThirdName());
        ui->tableWidget->setItem(counter, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem();
        item3->setText(this->client[counter]->getNumber());
        ui->tableWidget->setItem(counter, 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem();
        item4->setText(this->client[counter]->getLastService());
        ui->tableWidget->setItem(counter, 4, item4);



        ui->lineEdit_firstname->clear();
        ui->lineEdit_lastname->clear();
        ui->lineEdit_thirdname->clear();
        ui->lineEdit_number->clear();
        ui->comboBox_lastservice->setCurrentIndex(0);

        counter++;
}

void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    chosed_row = row;
      chosed_column = column;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->removeRow(chosed_row);
    if(counter == 0 )
    {
        QMessageBox::warning(this, "Ошибка", "Таблица пустая.");
    }
    else {
        chosed_row = ui->tableWidget->selectionModel()->currentIndex().row();
        for(int i = chosed_row; i < rows.size() - 1; ++i)
        {
            QString str;
            str.setNum(i+1);
            rows[i] = str;
        }
        rows.erase(--rows.end());
        ui->tableWidget->setVerticalHeaderLabels(rows);

        counter--;
        }
}



