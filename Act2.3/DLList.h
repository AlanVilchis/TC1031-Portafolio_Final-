#ifndef _DLLIST_H_
#define _DLLIST_H_
  
  #include<iostream>
  #include <stdexcept>
  #include <iostream>
  #include <stdio.h>
  #include <fstream>
  #include <cstdlib>
  #include <sstream>
  #include <string>
  #include "registro.h"

  template <class T>
  class DLList {
      private:
        registro *head;
        registro *tail;
        int numElements;

      public:
        DLList();
        ~DLList();
        int getNumElements();
        void addLast(string,string,string,string,string,string,string,string);
        void addFirst(string,string,string,string,string,string,string,string);
        void printList();
        void sort();
        int busquedaBinaria(int size, time_t k);
        int getDateIt(int n);
        void search();
        void bitacoraOrdenada();
        

};

  template<class T>
  DLList<T>::DLList() {
      std::cout << "--->Creando una lista vacia" << std::endl;
      head = nullptr;
      tail = nullptr;
      numElements = 0;
  }

  template<class T>
  DLList<T>::~DLList() {
      std::cout << "--->Liberando memoria de la lista ligada" << std::endl;
    registro *p, *q;
    p = head;
    while (p != nullptr) {
      q = p->next;
      delete p;
      p = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
  }

  template<class T>
  int DLList<T>::getNumElements(){
    return numElements;
  }

  template<class T>
  void DLList<T>::addFirst(string test,string test1,string test2,string test3,string test4,string test5,string test6,string test7) {
    //string test8="1";
    registro *newDLLNode = new registro(test,test1,test2,test3,test4,test5,test6,test7);
    // Si la lista está vacia
    if (head == nullptr && tail == nullptr) {
      head = newDLLNode;
      tail = newDLLNode;
    }
    else {
      newDLLNode->next = head;
      head->prev = newDLLNode;
      head = newDLLNode;
    }
    numElements++;
  }

 template<class T>
  void DLList<T>::addLast(string test,string test1,string test2,string test3,string test4,string test5,string test6,string test7) {
    //string test8="1";
    if (head == nullptr && tail == nullptr) {
      addFirst(test,test1,test2,test3,test4,test5,test6,test7);
    }
    else {
      registro *newDLLNode = new registro(test,test1,test2,test3,test4,test5,test6,test7);
      tail->next = newDLLNode;
      newDLLNode->prev = tail; 
      tail = newDLLNode;
      numElements++;
    }
  }

  template<class T>
  void DLList<T>::printList() {
    registro *ptr = head;
    if (ptr != nullptr) {
    while (ptr != nullptr) {
        std::cout << ptr->getDate() << " ";
        ptr = ptr->next;
    }
    } else {
      std::cout<<"La lista esta vacia"<<std::endl;
    }
    std::cout << std::endl;
  }

  template<class T> //complejidad O(n^2)
  void DLList<T>::sort()
{
    int swapped, i;
    registro *ptr1;
    registro *lptr = nullptr;
  
    /* Checking for empty list */
    if (head == nullptr)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->date > ptr1->next->date)
            {
                swap(ptr1->date, ptr1->next->date);
                swap(ptr1->mes, ptr1->next->mes);
                swap(ptr1->dia, ptr1->next->dia);
                swap(ptr1->horas, ptr1->next->horas);
                swap(ptr1->minutos, ptr1->next->minutos);
                swap(ptr1->segundos, ptr1->next->segundos);
                swap(ptr1->ip, ptr1->next->ip);
                swap(ptr1->port, ptr1->next->port);
                swap(ptr1->message, ptr1->next->message);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

template<class T>
int DLList<T>::getDateIt(int n){

  registro *p = head;
  for(int i=0;i<=n;i++){
    if(i==n){
      return p->getDate();
    }
    p=p->next;
  }
  
  
}

template<class T> //Complejidad O(logn)
int DLList<T>::busquedaBinaria(int size,time_t key){
    int low = 0;
    int high = size ;
    while (low <= high) {
      int m = low + (high - low) / 2;
      if (key == getDateIt(m)) return m;
      else if (key < getDateIt(m)) 
        high = m - 1;
      else 
        low = m + 1;
    }
    //cout<<endl;
    return -1;
}

template<class T>
void DLList<T>::search(){
  string mes, dia, hora, minutos, segundos;
  vector<time_t>fechas; 
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
    registro reg(mes, dia,hora,minutos,segundos,"ip","port","msg");
    fechas[i]=reg.getDate();
    cout<<fechas[i]<<endl;
  }
int f1=busquedaBinaria(numElements,fechas[0]);
int f2=busquedaBinaria(numElements,fechas[1]);
  cout<<fechas[0];
  cout<<fechas[1];  
  int f1,f2;
  int ii=0;
  registro *q=head;
  while(q->next != nullptr){
    if(q->getDate()==fechas[0]){
      int f1=ii;
      }
    q=q->next;
    ii++;
  }
    int iii=0;
  registro *r=head;
  while(r->next != nullptr){
    if(r->getDate()==fechas[1]){
      int f2=iii;
      }
    r=r->next;
    iii++;
  }


if (f1==-1|| f2==-1){ 
  cout<<"La fecha ingresada no se encuentra en los registros. "<<endl;
}
else{
    ofstream archivo2("resultado_busqueda.txt");
    registro *p = head;
    bool actuador;
    int index=0;
    while(p->next!=nullptr){
    if(index==f1){
      actuador=true;
  }
    }
    if(actuador==true){
      archivo2<<p->getDate()<<endl;

    }
    if(index==f2){
      actuador=false;
      archivo2.close();
    }
    p=p->next;
    index++;
  }

  }

template<class T>
void DLList<T>::bitacoraOrdenada(){
  ofstream archivo("bitacora_ordenada.txt");
  registro *p = head;
  while(p->next!=nullptr){
//Sep 03 08:52:35 252.3.50.199:6222 Failed password for illegal user root
    archivo<<p->mes<<" "<<p->dia<<" "<<p->horas<<":"<<p->minutos<<":"<<p->segundos<<" "<<p->ip<<":"<<p->port<<" "<<p->message<<endl;
    p=p->next;
  }
  archivo.close();
}

  

#endif