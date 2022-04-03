#ifndef _DATEINT_H_
#define _DATEINT_H_

#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class dateInt{
  public:
  dateInt(vector<int> date,vector<int> id);
  void ordenaBurbuja(vector<int> &arrDate, vector<int> &arrId, int n);
  int busquedaBinaria(vector<int> arr, int n, int k); 
  private:
  vector<int> date;
  vector<int> id;
  

};





#endif