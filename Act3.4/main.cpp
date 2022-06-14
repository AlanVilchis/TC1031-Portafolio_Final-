/*
Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
Autor: Alan Vilchis - A01640260

Compilación:
  * make -s

 * Ejecución:
  * ./main


 */

#include <iostream>
#include <math.h>
#include "MaxHeap.h"

using namespace std;
typedef long long ll;

int main() {


  MaxHeap<Registro> Bitacora(20000);
  Bitacora.readBitacora("bitacoraHeap.txt");
  Bitacora.BSTSplay();
  Bitacora.SortIp();

}

