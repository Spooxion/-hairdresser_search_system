#ifndef SERCHWINDOW_H
#define SERCHWINDOW_H

#include <QMainWindow>

namespace Ui {
class SerchWindow;
}

class SerchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerchWindow(QWidget *parent = nullptr);
    ~SerchWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SerchWindow *ui;
};

#endif // SERCHWINDOW_H
