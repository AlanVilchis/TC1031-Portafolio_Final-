/**
Autor: Alan Vilchis A01640260 
        
Compilación:
  * make -s

 * Ejecución:
  * ./main


**/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include "registro.h"
#include <sstream>
#include <string>
#include "DLList.h"


using namespace std;
int main(){
    string mes,dia,hora,minutos,segundos,ip,port,msg;
    DLList<registro> Bitacora;
    ifstream archivo("bitacora.txt");
  
    
    while (!archivo.eof()){
        getline(archivo, mes, ' ');
        getline(archivo, dia, ' ');
        getline(archivo, hora, ':');
        getline(archivo, minutos, ':');
        getline(archivo, segundos, ' ');
        getline(archivo, ip, ':');
        getline(archivo, port, ' ');
        getline(archivo, msg, '\n');
        Bitacora.addLast(mes,dia,hora,minutos,segundos,ip,port,msg);
      

    };
    archivo.close();
    Bitacora.sort();
    Bitacora.bitacoraOrdenada();

}