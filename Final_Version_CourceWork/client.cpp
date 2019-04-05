#include "client.h"

Client::Client(QString First_name, QString Last_name, QString Third_name, QString Number, QString Last_service){
    first_name= First_name;
    last_name=Last_name;
    third_name=Third_name;
    number=Number;
    last_service=Last_service;
}

void Client::setFirstName(QString First_name){
    first_name=First_name;
}
void Client::setLastName(QString Lirst_name){
    last_name=Lirst_name;
}
void Client::setThirdName(QString Third_name){
    third_name=Third_name;
}
void Client::setLastService(QString Last_service){
    last_service=Last_service;
}
void Client::setNumber (QString Number){
    number=Number;
}
QString Client::getFirstName(){
    return first_name;
}
QString Client::getLastName(){
    return last_name;
}
QString Client::getThirdName(){
    return third_name;
}
QString Client::getNumber(){
    return number;
}
QString Client::getLastService(){
    return last_service;
}


