#ifndef __REGISTRO_H
#define __REGISTRO_H
#include <string>
#include <iostream>
#include <math.h>


//Declaracion de la clase
class Registro {
  public:
      Registro();
      Registro(std::string mes, std::string dia, std::string hora, std::string cuarto, std::string tercero,  std::string segundo, std::string primero,std::string portMsg);
      std::string getMes();
      std::string getDia();
      std::string getHora();
      std::string getCuarto();
      std::string getTercero();
      std::string getSegundo();
      std::string getPrimero();
      std::string getPortMsg();
      long long int getSuma();
      long long int ipToInt(int cuarto, int tercero, int segundo, int primero);
  private:
      std::string mes;
      std::string dia;
      std::string hora;
      std::string cuarto;
      std::string tercero;
      std::string segundo;
      std::string primero;
      std::string portMsg;
      long long int Suma;

};

  Registro::Registro() {
    mes="Enero";
    dia="1";
    hora="0:0:0";
    cuarto="8";
    tercero="8";
    segundo="8";
    primero="8";
    portMsg="8";
    Suma= 0;
  }

  Registro::Registro(std::string month, std::string day, std::string hour, std::string forth, std::string third,  std::string second, std::string first,std::string puertoMsg) {
    mes=month;
    dia=day;
    hora=hour;
    cuarto=forth;
    tercero=third;
    segundo=second;
    primero=first;
    portMsg=puertoMsg;
    Suma= ipToInt(std::stoi(forth),std::stoi(third),std::stoi(second),std::stoi(first));
    //Suma=1;
  }

  long long Registro::ipToInt(int cu ,int te ,int se, int pr){
 return (cu * pow(256,3.0)) + (te * pow(256,2.0)) + (se * 256) + pr;
  }

  long long int Registro::getSuma(){
    return Suma;
  }

  std::string  Registro::getMes(){
    return mes;
  }

  std::string  Registro::getDia(){
    return dia;
  }
      
  std::string  Registro::getHora(){
    return hora;
  }

  std::string  Registro::getCuarto(){
    return cuarto;
  }

  std::string  Registro::getTercero(){
    return tercero;
  }

  std::string  Registro::getSegundo(){
    return segundo;
  }

  std::string  Registro::getPrimero(){
    return primero;
  }

  std::string  Registro::getPortMsg(){
    return portMsg;
  }

#endif