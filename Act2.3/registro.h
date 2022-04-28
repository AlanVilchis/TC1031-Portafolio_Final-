#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include<iostream>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;



class registro{
    public:
    registro(string mes, string dia, string horas, string minutos, string segundos, string ip, string port, string message);
    registro* next;
    registro* prev;
    time_t getDate();
    time_t date;
    string mes;
    string dia;
    string horas;
    string minutos;
    string segundos;
    string ip;
    string port; 
    string message;
    //string printAll();
    private:

    vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm dateStruct;
    
};



#endif