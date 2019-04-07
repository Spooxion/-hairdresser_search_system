#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serch = new SerchWindow(this);

    QPixmap *backgnd = new QPixmap(":/new/back/Images/Images/1.jpg");
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Window, QBrush(*backgnd));
    this->setPalette(*palette);

    ui->label->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_2->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_3->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_4->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_5->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_6->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_7->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_8->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_9->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_10->setStyleSheet("color: rgb(171, 171, 171)");
    ui->lineEdit_number->setValidator(new QDoubleValidator(0, 100, 2, this));

    QDateTime date1 = QDateTime::currentDateTime();
    if ((date1.time().hour() >= 19) && (date1.time().minute() >= 29))
    {
    ui->comboBox_data->addItem("");
    ui->comboBox_data->addItem(date1.addDays(+1).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+2).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+3).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+4).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+5).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+6).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+7).toString("dd/MM/yy"));
    }
    else
    {
    ui->comboBox_data->addItem("");
    ui->comboBox_data->addItem(date1.toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+1).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+2).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+3).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+4).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+5).toString("dd/MM/yy"));
    ui->comboBox_data->addItem(date1.addDays(+6).toString("dd/MM/yy"));
    }

    ui->comboBox_time->addItem(" ");
    ui->comboBox_time->addItem("08:00");
    ui->comboBox_time->addItem("08:30");
    ui->comboBox_time->addItem("09:00");
    ui->comboBox_time->addItem("09:30");
    ui->comboBox_time->addItem("10:00");
    ui->comboBox_time->addItem("10:30");
    ui->comboBox_time->addItem("11:00");
    ui->comboBox_time->addItem("11:30");
    ui->comboBox_time->addItem("12:00");
    ui->comboBox_time->addItem("12:30");
    ui->comboBox_time->addItem("13:00");
    ui->comboBox_time->addItem("13:30");
    ui->comboBox_time->addItem("14:00");
    ui->comboBox_time->addItem("14:30");
    ui->comboBox_time->addItem("15:00");
    ui->comboBox_time->addItem("15:30");
    ui->comboBox_time->addItem("16:00");
    ui->comboBox_time->addItem("16:30");
    ui->comboBox_time->addItem("17:00");
    ui->comboBox_time->addItem("17:30");
    ui->comboBox_time->addItem("18:00");
    ui->comboBox_time->addItem("18:30");
    ui->comboBox_time->addItem("19:00");
    ui->comboBox_time->addItem("19:30");




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

        QString first_name = ui->lineEdit_firstname->text();
        QString third_name = ui->lineEdit_thirdname->text();
        QString number = ui->lineEdit_number->text();
        QString last_service = ui->comboBox_lastservice->currentText();
        QString data = ui->comboBox_data->currentText();
        QString time = ui->comboBox_time->currentText();
        QString cost = ui->lineEdit_cost->text();

        Client *client1 = new Client (first_name,third_name,number,last_service,data,time,cost);
        this->client_vector.push_back(client1);


        QString buffer;
        buffer.setNum(counter + 1);
        rows.push_back(buffer);

        ui->tableWidget->insertRow(static_cast<short>(counter));
        ui->tableWidget->setVerticalHeaderLabels(rows);


        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(client_vector[counter]->getFirstName());
        ui->tableWidget->setItem(static_cast<short>(counter), 0, item);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText(this->client_vector[counter]->getThirdName());
        ui->tableWidget->setItem(static_cast<short>(counter), 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(this->client_vector[counter]->getNumber());
        ui->tableWidget->setItem(static_cast<short>(counter), 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem();
        item3->setText(this->client_vector[counter]->getLastService());
        ui->tableWidget->setItem(static_cast<short>(counter),3,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem();
        item4->setText(this->client_vector[counter]->getData());
        ui->tableWidget->setItem(static_cast<short>(counter),4,item4);

        QTableWidgetItem *item5 = new QTableWidgetItem();
        item5->setText(this->client_vector[counter]->getTime());
        ui->tableWidget->setItem(static_cast<short>(counter),5,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem();
        item6->setText(this->client_vector[counter]->getCost());
        ui->tableWidget->setItem(static_cast<short>(counter),6,item6);

        ui->lineEdit_firstname->clear();
        ui->lineEdit_thirdname->clear();
        ui->lineEdit_number->clear();
        ui->comboBox_lastservice->setCurrentIndex(0);
        ui->comboBox_data->setCurrentIndex(0);
        ui->comboBox_time->setCurrentIndex(0);

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



        //client_vector.erase(client_vector.begin()+ static_cast<short>(counter));
        counter--;

        }
}




void MainWindow::on_pushButton_3_clicked()
{
    QString serch1 = ui->lineEdit_serch->text();
    if (ui->comboBox_serch->currentIndex() == 0){

    }
    if (ui->comboBox_serch->currentIndex() == 1){

    }
    if (ui->comboBox_serch->currentIndex() == 2){

    }
    if (ui->comboBox_serch->currentIndex() == 3){

    }
    if (ui->comboBox_serch->currentIndex() == 4){

    }
    if (ui->comboBox_serch->currentIndex() == 5){

    }
    if (ui->comboBox_serch->currentIndex() == 6){

    }
    serch->show();


}
