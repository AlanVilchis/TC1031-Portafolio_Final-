/**
Autores: Alan Vilchis A01640260 & Gonzalo Calderon A01740008
        
Compilación:
  * make -s

 * Ejecución:
  * ./main

Referencias:
https://parzibyte.me/blog/2021/04/15/cpp-separar-cadena-delimitador/
https://github.com/Vinayak-D/FileIO
https://replit.com/@ertello/demoDateCompare#main.cpp
https://www.youtube.com/watch?v=RBZidsPGkfs

**/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "dateTime.h"
#include "dateInt.h"
using namespace std;


int main() {

string mes, dia, hora, minutos, segundos, ip, msg;
int n=16806;
vector<string>MES;
vector<string>DIA;
vector<string>HORA;
vector<string>MINUTOS;
vector<string>SEGUNDOS;
vector<string>IP;
vector<string>MSG;
vector<int>fechaInt;
vector<int>Id;
  
//se abre el archivo con ayuda de la libreria fstream
ifstream archivo("bitacora.txt"); 
//se almacena cada variable del archivo en un vector diferente
  for(int i=0;i<n+1;i++){ 
  getline(archivo, mes, ' ');
	MES.push_back(mes);
	getline(archivo, dia, ' ');
	DIA.push_back(dia);
	getline(archivo, hora, ':');
	HORA.push_back(hora);
	getline(archivo, minutos, ':'); 
  MINUTOS.push_back(minutos);
  getline(archivo, segundos, ' '); 
  SEGUNDOS.push_back(segundos);
	getline(archivo, ip, ' '); 
	IP.push_back(ip);
  getline(archivo, msg, '\n'); 
	MSG.push_back(msg);
  }

//se crea un objeto dateTime con la finalidad de pasar los datos de cada fecha a entero en un vector, junto con un identificador
for(int i=0;i<n+1;i++){ 
dateTime tiempoInt(MES[i],stoi(DIA[i]),stoi(HORA[i]),stoi(MINUTOS[i]),stoi(SEGUNDOS[i]));
fechaInt.push_back(tiempoInt.getDate());
Id.push_back(i);
  }

//se crea un objeto dateInt para almacenar los vectores anteriormente obtenidos, despues se ordenan esos vectores.
dateInt fechasNum(fechaInt,Id); 
fechasNum.ordenaBurbuja(fechaInt,Id,n);

//se crea vector para almacenar de modo de entero las fechas a buscar
vector<int>fechas; 
int iid;
  
// se crea un archivo con la bitacora ordenada
  ofstream archivo2("bitacora_ordenada.txt");
  for(int i=0;i<n;i++){
  iid=Id[i];
    archivo2<<MES[iid]<<" "<<DIA[iid]<<" "<<HORA[iid]<<":"<<MINUTOS[iid]<<":"<<SEGUNDOS[iid]<<" "<<IP[iid]<<" "<<MSG[iid]<<endl;
  }
  
//loop para almacenar las fechas a buscar y pasarlas a entero
for(int i=0;i<2;i++){  
cout<<"Ingresar intervalo de fechas de resgistro a revisar:"<<endl;
cout<<"Fecha "<<i+1<<": "<<endl;
cout<<"Mes: "<<endl;
cin>>mes;
cout<<"Dia: "<<endl;
cin>>dia;
cout<<"Hora: "<<endl;
cin>>hora;
cout<<"Minutos: "<<endl;
cin>>minutos;
cout<<"Segundos: "<<endl;
cin>>segundos;

dateTime fecha1(mes,stoi(dia),stoi(hora),stoi(minutos),stoi(segundos));
fechas.push_back(fecha1.getDate());
  cout<<fechas[i]<<endl;
  }

dateTime fecha2(mes,stoi(dia),stoi(hora),stoi(minutos),stoi(segundos));
cout<<fecha2.getDate()<<endl;
//con el metodo de busquedaBinaria se buscan las fechas ingresadas
int f1=fechasNum.busquedaBinaria(fechaInt,n,fechas[0]);
int f2=fechasNum.busquedaBinaria(fechaInt,n,fechas[1]);

//se revisan si las fechas existen, si es asi se imprime los registros del rango de fecha anteriormente ingresado
if (f1==-1|| f2==-1){ 
  cout<<"La fecha ingresada no se encuentra en los registros. "<<endl;
}
else{
  for(int i=f1;i<f2+1;i++){
    cout<<MES[Id[i]]<<" "<<DIA[Id[i]]<<" "<<HORA[Id[i]]<<":"<<MINUTOS[Id[i]]<<":"<<SEGUNDOS[Id[i]]<<" "<<IP[Id[i]]<<" "<<MSG[Id[i]]<<endl;
  }
}
}

