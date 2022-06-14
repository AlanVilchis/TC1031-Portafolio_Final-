#ifndef _SPLAYTREENODE_H_
#define _SPLAYTREENODE_H_

  #include<iostream>

  template <class T>
  class SplayTreeNode { 
  public: 
      T data; 
      int numRepetido;
      SplayTreeNode<T>* left;
      SplayTreeNode<T>* right;
      SplayTreeNode();
      SplayTreeNode(T);
  }; 

  template<class T>
  SplayTreeNode<T>::SplayTreeNode() : data{}, left{nullptr}, right{nullptr}, numRepetido{} {}

  template<class T>
  SplayTreeNode<T>::SplayTreeNode(T val){
      data = val;
      left = nullptr;
      right = nullptr;
      numRepetido = 1;
  }

#endif // _SPLAYTREENODE_H_