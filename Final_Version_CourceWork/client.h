#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include<QString>
#include <QLineEdit>

class Client
{
private:
    QString first_name;
    QString last_name;
    QString third_name;
    QString last_service;
    QString number;


protected:

public:

    Client(QString First_name, QString Last_name, QString Third_name, QString Number, QString Last_service);
    Client();
    ~Client();

    void setFirstName(QString First_name);
    void setLastName(QString Lirst_name);
    void setThirdName(QString Third_name);
    void setLastService(QString Last_service);
    void setNumber (QString Number);

    QString getFirstName();
    QString getLastName();
    QString getThirdName();
    QString getNumber();
    QString getLastService();
 };




#endif // CLIENT_H
