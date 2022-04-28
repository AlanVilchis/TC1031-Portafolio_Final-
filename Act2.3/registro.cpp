#include "registro.h"
using namespace std;
registro::registro(string m, string d, string h, string min, string s, string i, string p, string mess){
    mes=m;
    dia=d;
    horas=h;
    minutos=min;
    segundos=s;
    ip=i;
    port=p;
    message=mess;
    next = nullptr;
    prev = nullptr;

    dateStruct.tm_sec = stoi(s);
    dateStruct.tm_min = stoi(min);
    dateStruct.tm_hour = stoi(horas);
    dateStruct.tm_mday = stoi(dia);
    dateStruct.tm_isdst = 0;
    dateStruct.tm_year = 2022 - 1900;
    for (int i=0; i < meses.size(); i++) {
    if (meses[i]==m)
    dateStruct.tm_mon = i;
      
  }
    date = mktime(&dateStruct);




}

time_t registro::getDate(){
  return date;
}

