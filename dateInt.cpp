#include "dateInt.h"
//constructor
dateInt::dateInt(vector<int> d,vector<int> i){
  date=d;
  id=i;
}
//Se eligio por que este metodo nos daba los resultados esperados en una actividad anterior, ademas de poder adaptar facilmente ese codigo a este nuevo proyecto, es un metodo estable, su complejidad va desde O(n) en el mejor caso, O(n^2) en el caso promedio y en el peor lo mismo.
//metodo de ordenamiento tipo bubbleSort
void dateInt::ordenaBurbuja(vector<int> &arrDate,vector<int> &arrId, int n) {
  int i, j, tmp ,tmp2;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n-i; j++) {
      if (arrDate[j] > arrDate[j+1]) {
        tmp = arrDate[j];
        arrDate[j] = arrDate[j+1];
        arrDate[j+1] = tmp;
        tmp2 = arrId[j];
        arrId[j]=arrId[j+1];
        arrId[j+1]=tmp2;
      }
    }
  }
}
//Se eligio por que tiene un bajo nivel de complejidad, O(log n) en el peor caso, ademas se reutilizo de otra actividad donde este metodo nos daba los resultados esperados.
//metodo de busqueda de tipo binaria
int dateInt::busquedaBinaria(vector<int> arr, int n, int k) {
    int low = 0;
    int high = n ;
    while (low <= high) {
      int m = low + (high - low) / 2;
      if (k == arr[m]) return m;
      else if (k < arr[m]) 
        high = m - 1;
      else 
        low = m + 1;
    }
    //cout<<endl;
    return -1;
}