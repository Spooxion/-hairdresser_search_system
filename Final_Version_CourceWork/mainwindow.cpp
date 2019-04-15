#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringRef>
#include <QList>
#include <QTableView>
#include <QFileDialog>
#include <QTextCodec>
#include <QWidget>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serch = new SerchWindow(this);

    QPixmap *backgnd = new QPixmap(":/new/back/Images/Images/1.jpg");
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Window, QBrush(*backgnd));
    this->setPalette(*palette);

    QRegExp Const_int ("^[0-9]+$");
    QRegExp Const_word ("^[А-Яа-яA-Za-z]{,50}$");
    QRegExpValidator *word_check = new QRegExpValidator(Const_word, this);
    QRegExpValidator *int_check = new QRegExpValidator(Const_int, this);

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
    ui->label_11->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_12->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_13->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_14->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_15->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_16->setStyleSheet("color: rgb(171, 171, 171)");
    ui->label_17->setStyleSheet("color: rgb(171, 171, 171)");

    ui->lineEdit_number->setMaxLength(11);
    ui->lineEdit_number_2->setMaxLength(11);
    ui->lineEdit_cost->setMaxLength(4);
    ui->lineEdit_cost_2->setMaxLength(4);

    ui->lineEdit_firstname->setValidator(word_check);
    ui->lineEdit_firstname_2->setValidator(word_check);
    ui->lineEdit_thirdname->setValidator(word_check);
    ui->lineEdit_thirdname_2->setValidator(word_check);
    ui->lineEdit_cost->setValidator(int_check);
    ui->lineEdit_cost_2->setValidator(int_check);
    ui->lineEdit_number->setValidator(int_check);
    ui->lineEdit_number_2->setValidator(int_check);

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

        ui->comboBox_data_2->addItem("");
        ui->comboBox_data_2->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+6).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+7).toString("dd/MM/yy"));
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

        ui->comboBox_data_2->addItem("");
        ui->comboBox_data_2->addItem(date1.toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+6).toString("dd/MM/yy"));
    }

    ui->comboBox_time->addItem("");
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

    ui->comboBox_time_2->addItem("");
    ui->comboBox_time_2->addItem("10:00");
    ui->comboBox_time_2->addItem("10:30");
    ui->comboBox_time_2->addItem("11:00");
    ui->comboBox_time_2->addItem("11:30");
    ui->comboBox_time_2->addItem("12:00");
    ui->comboBox_time_2->addItem("12:30");
    ui->comboBox_time_2->addItem("13:00");
    ui->comboBox_time_2->addItem("13:30");
    ui->comboBox_time_2->addItem("14:00");
    ui->comboBox_time_2->addItem("14:30");
    ui->comboBox_time_2->addItem("15:00");
    ui->comboBox_time_2->addItem("15:30");
    ui->comboBox_time_2->addItem("16:00");
    ui->comboBox_time_2->addItem("16:30");
    ui->comboBox_time_2->addItem("17:00");
    ui->comboBox_time_2->addItem("17:30");
    ui->comboBox_time_2->addItem("18:00");
    ui->comboBox_time_2->addItem("18:30");
    ui->comboBox_time_2->addItem("19:00");
    ui->comboBox_time_2->addItem("19:30");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

static QString file_name="Новый проект";

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString  first_name = ui->lineEdit_firstname->text();
    QString  third_name = ui->lineEdit_thirdname->text();
    QString  number = ui->lineEdit_number->text();
    QString  last_service = ui->comboBox_lastservice->currentText();
    QString  data = ui->comboBox_data->currentText();
    QString  time = ui->comboBox_time->currentText();
    QString  cost = ui->lineEdit_cost->text();

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

    line_edit_1_clear();
    counter++;
}

void MainWindow::line_edit_1_clear()
{
    ui->lineEdit_firstname->clear();
    ui->lineEdit_thirdname->clear();
    ui->lineEdit_number->clear();
    ui->comboBox_lastservice->setCurrentIndex(0);
    ui->comboBox_data->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->lineEdit_cost->clear();
}

void MainWindow::line_edit_2_clear()
{
ui->lineEdit_firstname_2->clear();
ui->lineEdit_thirdname_2->clear();
ui->lineEdit_number_2->clear();
ui->comboBox_lastservice_2->setCurrentIndex(0);
ui->comboBox_data_2->setCurrentIndex(0);
ui->comboBox_time_2->setCurrentIndex(0);
ui->lineEdit_cost_2->clear();
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
        QMessageBox::warning(this, "", "Таблица пустая.");
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

        client_vector.erase(client_vector.begin() + chosed_row);
        counter--;
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    bool firstname_is_serch = true;
    bool thirdname_is_serch = true;
    bool number_is_serch = true;
    bool lastservice_is_serch = true;
    bool date_is_serch = true;
    bool time_is_serch = true;
    bool cost_is_serch = true;

    QString firstname_string = ui->lineEdit_firstname_2->text().toLower();
    QString thirdname_string = ui->lineEdit_thirdname_2->text().toLower();
    QString number_string = ui->lineEdit_number_2->text().toLower();
    QString lastservice_string = ui->comboBox_lastservice_2->currentText();
    QString date_string = ui->comboBox_data_2->currentText().toLower();
    QString time_string = ui->comboBox_time_2->currentText().toLower();
    QString cost_string = ui->lineEdit_cost_2->text().toLower();

    serch->serch_results.clear();

    line_edit_2_clear();

    for(size_t i = 0; i < client_vector.size(); ++i)
    {
        firstname_is_serch = true;
        thirdname_is_serch = true;
        number_is_serch = true;
        lastservice_is_serch = true;
        date_is_serch = true;
        time_is_serch = true;
        cost_is_serch = true;

        if(!firstname_string.isEmpty())
        {
            QString firstname_ = client_vector[i]->getFirstName().toLower();
            if(!firstname_.contains(firstname_string)){firstname_is_serch = false;}
        }

        if(!thirdname_string.isEmpty())
        {
            QString thirdname_ = client_vector[i]->getThirdName().toLower();
            if(!thirdname_.contains(thirdname_string)){thirdname_is_serch = false;}   
        }

        if(!number_string.isEmpty())
        {
            QString number_ = client_vector[i]->getNumber().toLower();
            if(number_ != number_string){number_is_serch = false;}
            qInfo()<< number_<< number_string<< number_is_serch;
        }

        if(!lastservice_string.isEmpty())
        {
            QString lastservice_ = client_vector[i]->getLastService().toLower();
            if(lastservice_ != lastservice_string){lastservice_is_serch = false;}
            qInfo()<< lastservice_<< lastservice_string << lastservice_is_serch;
        }

        if(!date_string.isEmpty())
        {
            QString date_ = client_vector[i]->getData().toLower();
            if(date_ != date_string){date_is_serch = false;}
            qInfo()<< date_ << date_is_serch<< date_is_serch;
        }

        if(!time_string.isEmpty())
        {
            QString time_ = client_vector[i]->getTime().toLower();
            if(time_ != time_string){time_is_serch = false;}

        }

        if(!cost_string.isEmpty())
        {
            QString cost_ = client_vector[i]->getCost().toLower();
            if(cost_ != cost_string){cost_is_serch = false;}
        }

        if(firstname_is_serch && thirdname_is_serch && number_is_serch && lastservice_is_serch && date_is_serch && time_is_serch && cost_is_serch)
        {
              serch->serch_results.push_back(client_vector[i]);
        }

    }
    serch->updateTable();
    int serch_row_count = serch->rowCount();
    if (serch_row_count == 0){QMessageBox::warning(this, "Ошибка", "Соответствий критериям поиска не было найдено.");}
    else{serch->show();}
}

void MainWindow::on_comboBox_lastservice_currentIndexChanged(int index)
{
    if (ui->comboBox_lastservice->currentIndex() == 1){ui->lineEdit_cost->setText("350");}
    if (ui->comboBox_lastservice->currentIndex() == 2){ui->lineEdit_cost->setText("550");}
    if (ui->comboBox_lastservice->currentIndex() == 3){ui->lineEdit_cost->setText("900");}
    if (ui->comboBox_lastservice->currentIndex() == 4){ui->lineEdit_cost->setText("600");}
    if (ui->comboBox_lastservice->currentIndex() == 5){ui->lineEdit_cost->setText("1500");}
    if (ui->comboBox_lastservice->currentIndex() == 6){ui->lineEdit_cost->setText("2000");}
}

void MainWindow::on_comboBox_data_currentIndexChanged(const QString &arg1)
{
    QString combo_text = ui->comboBox_data->currentText();
    QString current_date_text = QDate::currentDate().toString("dd/MM/yy");

    if ( combo_text == current_date_text )
    {
        ui->comboBox_time->clear();
        int current_time_hour    = QTime::currentTime().hour();
        int current_time_minutes = QTime::currentTime().minute();
        ui->comboBox_time->addItem(" ");
        QString buffer;
        if (current_time_minutes<30)
        {
            QString true_time;
            true_time.append(QString::number(current_time_hour).append(":30"));;
            ui->comboBox_time->addItem(true_time);
            buffer = true_time;
        }
        else
        {
            QString true_time;
            true_time.append(QString::number(current_time_hour+1).append(":00"));;
            ui->comboBox_time->addItem(true_time);
            buffer=true_time;
        }

        for (int i=current_time_hour; i<20; ++i)
        {
            QString last_two_char = buffer.mid(3,2);
            if (last_two_char == "30")
            {
                QString true_time1;
                true_time1.append(QString::number(i+1).append(":00"));;
                ui->comboBox_time->addItem(true_time1);
                buffer = true_time1;
            }

            if (last_two_char == "00")
            {
                QString true_time1;
                true_time1.append(QString::number(i+1).append(":30"));;
                ui->comboBox_time->addItem(true_time1);
                buffer = true_time1;
            }
        }

    }
    else
    {
        ui->comboBox_time->clear();
        ui->comboBox_time->addItem("");
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
}

void MainWindow::on_pushButton_edit_client_clicked()
{
    ui->tableWidget->removeRow(chosed_row);
    chosed_row = ui->tableWidget->selectionModel()->currentIndex().row();
}

void MainWindow::show_project(){
    QWidget::setWindowTitle("Парикмахерская\" "+file_name);
}

void MainWindow::show_vector_in_table(){
    ui->tableWidget->setRowCount(0);

     if (client_vector.size() != 0)
     {
      for(unsigned int i=0;i<client_vector.size();i++)
      {
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

          line_edit_1_clear();
          counter++;
      }
     }
}

void MainWindow::on_action_save_triggered()
{
    QStringList save_project;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    if(file_name=="Новый проект")
    {
         QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
         qInfo()<< filename;
         if(!filename.isEmpty()){file_name=filename;}
    }

    else
    {
        for(unsigned int i=0;i<client_vector.size();i++)
        {
            qInfo()<< " save project -> metody";
            save_project<<client_vector[i]->getFirstName().toUtf8();
            save_project<<client_vector[i]->getThirdName().toUtf8();
            save_project<<client_vector[i]->getNumber().toUtf8();
            save_project<<client_vector[i]->getLastService().toUtf8();
            save_project<<client_vector[i]->getData().toUtf8();
            save_project<<client_vector[i]->getTime().toUtf8();
            save_project<<client_vector[i]->getCost().toUtf8()<<"\r\n";
        }}
         qInfo()<< file_name << save_project;
         QFile file(file_name);
         if ((file.open(QIODevice::WriteOnly)))
         {
            for(unsigned int i=0;i<client_vector.size();i++)
            {
                qInfo()<< " save project -> metody";
                save_project<<client_vector[i]->getFirstName().toUtf8()<<"\n";
                save_project<<client_vector[i]->getThirdName().toUtf8()<<"\n";
                save_project<<client_vector[i]->getNumber().toUtf8()<<"\n";
                save_project<<client_vector[i]->getLastService().toUtf8()<<"\n";
                save_project<<client_vector[i]->getData().toUtf8()<<"\n";
                save_project<<client_vector[i]->getTime().toUtf8()<<"\n";
                save_project<<client_vector[i]->getCost().toUtf8()<<"\n";
            }
            QTextStream stream(&file);
            foreach(QString s, save_project){stream<<s;}
         }
         file.close();

         show_project();
}

void MainWindow::on_action_save_as_triggered()
{
    on_action_save_triggered();
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
    if(!filename.isEmpty())
    {
    QFile young(filename);
    QFile old(file_name);
    old.close();
    young.open(QIODevice::WriteOnly);
    old.open(QIODevice::ReadOnly);
    QByteArray my_buf = old.readAll();
    young.write(my_buf);
    young.close();
    file_name=filename;
    show_project();
    QMessageBox::information(this,"Результат","Файл сохранен","ОК");
    }
}

void MainWindow::on_action_open_triggered()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
      QString filename =  QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("File (*.txt)"));
      QStringList open_project;
      if(!filename.isEmpty())
      {
        qInfo()<< "gotoint";
        file_name=filename;
        client_vector.clear();

        QFile file(file_name);
        if (file.open(QIODevice::ReadOnly))
        {

          while(!file.atEnd())
          {
            open_project<<file.readLine( ) ;
           }

       }
        file.close();

        for(int i=0;i<open_project.size();i+=7){
           Client *client1 = new Client(open_project[i],open_project[i+1],open_project[i+2],open_project[i+3],open_project[i+4],open_project[i+5],open_project[i+6]);
           client_vector.push_back(client1);
        }
        line_edit_1_clear();
        line_edit_2_clear();
        show_vector_in_table();
        show_project();
      }
}

void MainWindow::on_action_close_triggered()
{

}
