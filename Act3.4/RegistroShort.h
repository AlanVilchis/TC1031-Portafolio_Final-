#ifndef __REGISTROSHORT_H
#define __REGISTROSHORT_H
#include <string>
#include <iostream>
#include <math.h>


//Declaracion de la clase
class RegistroShort {
  public:
      RegistroShort();
      RegistroShort(long long int Suma, int numRepetido);
      int getNumRepetido();
      long long int getSuma();
      std::string intToIp(long long int Suma);
      std::string getIp();
  private:
      std::string ip;
      int numRepetido;
      long long int Suma;

};

  RegistroShort::RegistroShort() {
    ip="8.8.8.8";
    numRepetido= 0;
    Suma= 0;
  }

  RegistroShort::RegistroShort(long long int sum, int numRep) {
    Suma=sum;
    numRepetido= numRep;
    ip=intToIp(Suma);
  }

  std::string RegistroShort::intToIp(long long int numero){
    int cuarto, tercero, segundo, primero;
    cuarto = trunc(numero/(pow(256, 3.0)));
    numero=numero-(cuarto* pow(256, 3.0));
    tercero = trunc(numero/(256*256));
    numero=numero-(tercero*256*256);
    segundo= trunc(numero/(256));
    numero= numero-(segundo*256);
    return std::to_string(cuarto)+"."+std::to_string(tercero)+"."+std::to_string(segundo)+"."+std::to_string(numero);
  }

  long long int RegistroShort::getSuma(){
    return Suma;
  }

  std::string  RegistroShort::getIp(){
    return ip;
  }

  int RegistroShort::getNumRepetido(){
    return numRepetido;
  }
      
#endif