#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

  #include <vector>
  #include <iostream>
  #include <stdexcept>
  #include "Registro.h"
  #include <fstream>
  #include "SplayTree.h"
using namespace std;
  template<class T>
  class MaxHeap {
    private:
      SplayTree<long long int> mySplayTree;
      // contiene los elementos del heap
      std::vector<T> data; 
      // capacidad maxima del heap
      int maxSize;
      // tamaño actual del heap   
      int size;   
      int parent(int i);
      int left(int i);
      int right(int i);

    public:
      MaxHeap(int capacity);
      ~MaxHeap();
      bool isEmpty();
      int getCapacity();
      void printMaxHeap();
      void push(T key);
      T top();
      void pop();
      int getSize();
      void heapify_down(int i);
      void readBitacora(std::string fileName);
      void BSTSplay();
      void SortIp();
      void printBST();
      

  };

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
      data.clear();
  }
// cargar la bitacora
template <class T> 
  void MaxHeap<T>::readBitacora(std::string fileName){
  std::string mes, dia, hora, cuarto,segundo,tercero,primero, portMsg;
    
    std::ifstream archivo(fileName);
     while (!archivo.eof()){
        getline(archivo, mes, ' ');
        getline(archivo, dia, ' ');
        getline(archivo, hora, ' ');
        getline(archivo, cuarto, '.');
        getline(archivo, tercero, '.');
        getline(archivo, segundo, '.');
        getline(archivo, primero, ':');
        getline(archivo, portMsg, '\n');
       Registro reg(mes,dia,hora,cuarto,tercero,segundo,primero,portMsg);
       push(reg);   
  }
    archivo.close();
    }
    
//Complejidad O(1)
  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }
//Complejidad O(1)
  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }
//Complejidad O(n)
  template <class T> 
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      std::cout << data[i].getSuma() << " ";
    std::cout << std::endl;
  }
//Complejidad O(1)
  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
//Complejidad O(1)
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }
//Complejidad O(1)
  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

//Complejidad O(log n)
  template <class T> 
  void MaxHeap<T>::push(T key) {
    if (size == maxSize) {
      throw std::out_of_range("Overflow: no se puede insertar la llave: " + key.getSuma());
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    //std::cout<<"ki: "<<data[i].getSuma()<<std::endl;
    size++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)].getSuma() < data[i].getSuma()) {
       std::swap(data[i], data[parent(i)]);
       i = parent(i);
    }
  }
//Complejidad O(1)
  template <class T> 
  T MaxHeap<T>::top() {
    if(size==0){
      std::cout<<"La fila esta vacia"<<std::endl;
    }
    else{
    return data[0];
    }
  }
//Complejidad O(log n)
 template <class T>
  void MaxHeap<T>::heapify_down(int i)
    {
      // get left and right child of node at index `i`
      int LEFT = left(i);
      int RIGHT = right(i);
 
      int largest = i;
 
        // compare `A[i]` with its left and right child
        // and find the largest value
        if (LEFT < getSize() && data[LEFT].getSuma() > data[i].getSuma()) {
            largest = LEFT;
        }
 
        if (RIGHT < getSize() && data[RIGHT].getSuma() > data[largest].getSuma()) {
            largest = RIGHT;
        }
 
        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            std::swap(data[i], data[largest]);
            heapify_down(largest);
        }
    }

//Complejidad O(1)
  template <class T> 
  void MaxHeap<T>::pop() {
    if(size==0){
      std::cout<<"La fila esta vacia"<<std::endl;
    }
    else{
      data[0]=data[size-1];
      data.pop_back();
      size--;
      // Reparar las propiedades del max heap si son violadas
      heapify_down(0);

    }
  }

  
//Complejidad O(1)
  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

//Complejidad O(log n)
  template <class T> 
  void MaxHeap<T>::BSTSplay() {
    for (int i=0; i < size; i++){
      mySplayTree.add(data[i].getSuma());
  }
    mySplayTree.callInorder();
    mySplayTree.top5();
  }

  template <class T> 
  void MaxHeap<T>::SortIp(){
    ofstream archivo("bitacora_ordenada.txt");
    while(size!=0){
      archivo<<data[0].getMes()<<" "<<data[0].getDia()<<" "<<data[0].getHora()<<" "<<data[0].getCuarto()<<"."<<data[0].getTercero()<<"."<<data[0].getSegundo()<<"."<<data[0].getPrimero()<<":"<<data[0].getPortMsg()<<std::endl;
    pop();
    }
    archivo.close();
  }

  template <class T> 
  void MaxHeap<T>::printBST(){
    mySplayTree.printMaxHeap();
  }
  


#endif // __MAXHEAP_H_