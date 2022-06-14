#ifndef _SPLAY_TREE_H_
#define _SPLAY_TREE_H_

  #include <iostream>
  #include <vector>
  #include "SplayTreeNode.h"
  #include "RegistroShort.h"
  #include <fstream>

  template <class T>
  class SplayTree { 
    private:
      SplayTreeNode<T> *root;
      int size;
      int sizeMaxHeap;
      void print2D(SplayTreeNode<T> *p, int space);
      void preorder(SplayTreeNode<T>* nodo);
      void postorder(SplayTreeNode<T>* nodo);
      void inorder(SplayTreeNode<T>* nodo);
      SplayTreeNode<T>* zig(SplayTreeNode<T> *x);
      SplayTreeNode<T>* zag(SplayTreeNode<T> *x);
      SplayTreeNode<T>* splay(SplayTreeNode<T> *root, T value);
      SplayTreeNode<T>* insertRec(SplayTreeNode<T> *root, T value);
      SplayTreeNode<T>* searchRec(SplayTreeNode<T> *root, T value);
      SplayTreeNode<T>* removeRec(SplayTreeNode<T> *root, T value);
      std::vector<RegistroShort> vectorRegShort;
      int left(int i);
      int right(int i);

    public: 
      SplayTree();
      ~SplayTree();
      void clearMemory(SplayTreeNode<T> *p);
      void print();
      void callPreorder();
      void callPostorder();
      void callInorder();
      void buildTestTree();
      void add(T value);
      void find(T value);
      void remove(T value);
      int getSize();
      int getSize2();
      void top5();
      void push(RegistroShort value);
      int parent(int i);
      void printMaxHeap();
      void heapify_down(int i);
      void pop();

  };

  template<class T>
  SplayTree<T>::SplayTree() {
    std::cout << "--->Creando un SplayTree vacio: " <<  this << std::endl;
    root = nullptr;
    size = 0;
    sizeMaxHeap=0;
    vectorRegShort.resize(20000);
  }

  template<class T>
  SplayTree<T>::~SplayTree() {
    std::cout << "--->Liberando memoria del SplayTree: " << this << std::endl;
    clearMemory(root);
  }

  template<class T>
  void SplayTree<T>::clearMemory(SplayTreeNode<T> *p) {
    if (p != nullptr) {
      clearMemory(p->left);
      clearMemory(p->right);
      delete p;
      p = nullptr;
    }
  }

  template <class T>
  void SplayTree<T>::print() {
      print2D(root, 0);
  }

  template <class T>
  void SplayTree<T>::print2D(SplayTreeNode<T> *root, int space) {
      // Caso base
      if (root == nullptr)
          return;
      // Incrementa la distancia entre niveles
      space += 5;
   
      // Procesa hijo derecho
      print2D(root->right, space);
      // Imprime el nodo actual despues de los espacios necesarios
      std::cout << std::endl;
      for (int i = 5; i < space; i++)
          std::cout << " ";
      std::cout << root->data << std::endl;
      // Procesa el hijo izquierdo 
      print2D(root->left, space);
  }

  template<class T>
  void SplayTree<T>::callPreorder(){
    preorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void SplayTree<T>::preorder(SplayTreeNode<T>* nodo){
      if(nodo != nullptr){
        std::cout << nodo->data << " ";
        preorder(nodo->left); 
        preorder(nodo->right); 
      }
  }    

  template<class T>
  void SplayTree<T>::callInorder(){
    inorder(root);
  }

//Complejidad O(1)
  template <class T> 
  int SplayTree<T>::parent(int i) {
    return (i-1)/2; 
  }

  template <class T> 
  void SplayTree<T>::push(RegistroShort key) {
    // Insertamos la nueva llave al final del vector
    int i = sizeMaxHeap;
    vectorRegShort[i] = key;
    sizeMaxHeap++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && vectorRegShort[parent(i)].getNumRepetido() < vectorRegShort[i].getNumRepetido()) {
       std::swap(vectorRegShort[i], vectorRegShort[parent(i)]);
       i = parent(i);
    }
  }

  template<class T>
  void SplayTree<T>::inorder(SplayTreeNode<T>* nodo) {
      if(nodo != nullptr){
      inorder(nodo->left);
      RegistroShort reg(nodo->data,nodo->numRepetido);
      push(reg);
      inorder(nodo->right);
      }
  }

//Complejidad O(1)
  template <class T> 
  int SplayTree<T>::left(int i) {
    return (2*i + 1); 
  }
//Complejidad O(1)
  template <class T> 
  int SplayTree<T>::right(int i) {
    return (2*i + 2);
  }

//Complejidad O(log n)
 template <class T>
  void SplayTree<T>::heapify_down(int i)
    {
      // get left and right child of node at index `i`
      int LEFT = left(i);
      int RIGHT = right(i);
 
      int largest = i;
 
        // compare `A[i]` with its left and right child
        // and find the largest value
        if (LEFT < getSize() && vectorRegShort[LEFT].getNumRepetido() > vectorRegShort[i].getNumRepetido()) {
            largest = LEFT;
        }
 
        if (RIGHT < getSize() && vectorRegShort[RIGHT].getNumRepetido() > vectorRegShort[largest].getNumRepetido()) {
            largest = RIGHT;
        }
 
        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            std::swap(vectorRegShort[i], vectorRegShort[largest]);
            heapify_down(largest);
        }
    }

//Complejidad O(1)
  template <class T> 
  void SplayTree<T>::pop() {
    if(size==0){
      std::cout<<"La fila esta vacia"<<std::endl;
    }
    else{
      vectorRegShort[0]=vectorRegShort[sizeMaxHeap-1];
      vectorRegShort.pop_back();
      sizeMaxHeap--;
      // Reparar las propiedades del max heap si son violadas
      heapify_down(0);

    }
  }
  
  template<class T>
  void SplayTree<T>::callPostorder() {
    postorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void SplayTree<T>::postorder(SplayTreeNode<T>* nodo) {
      if(nodo != nullptr){
      postorder(nodo->left);
      postorder(nodo->right);
      std::cout << nodo->data << " ";
      }
  }

  template<class T>
  void SplayTree<T>::buildTestTree() {
    
      root = new SplayTreeNode<T>(100);
      root->left = new SplayTreeNode<T>(50);
      root->right = new SplayTreeNode<T>(200);
      root->left->left = new SplayTreeNode<T>(40);
      root->left->left->left = new SplayTreeNode<T>(30);
      root->left->left->left->left = new SplayTreeNode<T>(20);
      size+=6;
    
    /* // Other test tree
      root = new SplayTreeNode<T>(6);
      root->left = new SplayTreeNode<T>(1);
      root->right = new SplayTreeNode<T>(9);
      root->left->right = new SplayTreeNode<T>(4);
      root->left->right->left = new SplayTreeNode<T>(2);
      root->right->left = new SplayTreeNode<T>(7);
      size+=6;
    */
  }

  // right rotation
  template<class T>
  SplayTreeNode<T>* SplayTree<T>::zig(SplayTreeNode<T> *x) {
      SplayTreeNode<T> *y = x->left;
      x->left = y->right;
      y->right = x;
      return y;
  }
  
  // left rotation
  template<class T>
  SplayTreeNode<T>* SplayTree<T>::zag(SplayTreeNode<T> *x) {
      SplayTreeNode<T> *y = x->right;
      x->right = y->left;
      y->left = x;
      return y;
  }

  template<class T>
  SplayTreeNode<T>* SplayTree<T>::splay(SplayTreeNode<T> *root, T value) {
      // Base cases: root is nullptr or
      // value is present at root
      if (root == nullptr || value == root->data)
        return root;
      // value lies in left subtree
      if (value < root->data) {
          // value is not in tree, we are done
          if (root->left == nullptr) return root;
          // Zig-Zig (Left Left)
          if (value < root->left->data) {
              // First recursively bring the key as root of left-left
              root->left->left = splay(root->left->left, value);
              // Do first rotation for root, second rotation is done after else
              root = zig(root);
          }
          else if (value > root->left->data) { // Zig-Zag (Left Right)
              // First recursively bring the key as root of left-right
              root->left->right = splay(root->left->right, value); 
              // Do first rotation for root->left
              if (root->left->right != nullptr)
                  root->left = zag(root->left);
          }
          // Do second rotation for root
          return (root->left == nullptr)? root : zig(root);
      }
      else { // Key lies in right subtree
          // Key is not in tree, we are done
          if (root->right == nullptr) return root;
          // Zig-Zag (Right Left)
          if (value < root->right->data) {
              // Bring the key as root of right-left
              root->right->left = splay(root->right->left, value);
              // Do first rotation for root->right
              if (root->right->left != nullptr)
                  root->right = zig(root->right);
          }
          else if (value > root->right->data) { // Zag-Zag (Right Right)
              // Bring the key as root of right-right and do first rotation
              root->right->right = splay(root->right->right, value);
              root = zag(root);
          }
          // Do second rotation for root
          return (root->right == nullptr)? root: zag(root);
      }
  }

  template<class T>
  SplayTreeNode<T>* SplayTree<T>::insertRec(SplayTreeNode<T> *root, T value) {
      // Simple Case: If tree is empty
      if (root == nullptr) {
        SplayTreeNode<T> *newNode = new SplayTreeNode<T>(value);
        size++;
        return newNode;
      }
      // Bring the closest leaf node to root
      root = splay(root, value);
      // If value is already present, then return
      if (value == root->data){
        root->numRepetido = root->numRepetido + 1;
        return root;
      } 
   
      // Otherwise allocate memory for new node
      SplayTreeNode<T> *newNode = new SplayTreeNode<T>(value);
      size++;
      // If root's key is greater, make
      // root as right child of newnode
      // and copy the left child of root to newnode
      if (value < root->data) {
          newNode->right = root;
          newNode->left = root->left;
          root->left = nullptr;
      }
      // If root's key is smaller, make
      // root as left child of newnode
      // and copy the right child of root to newnode
      else {
          newNode->left = root;
          newNode->right = root->right;
          root->right = nullptr;
      }
      return newNode; // newnode becomes new root
  }

  template<class T>
  void SplayTree<T>::add(T value) {
      root = insertRec(root, value);
  }

  template<class T>
  SplayTreeNode<T>* SplayTree<T>::searchRec(SplayTreeNode<T> *root, T value) {
      return splay(root, value);
  }

  template<class T>
  void SplayTree<T>::find(T value) {
      root = searchRec(root, value);
  }

  template<class T>
  SplayTreeNode<T>* SplayTree<T>::removeRec(SplayTreeNode<T> *root, T value) {
      SplayTreeNode<T> *temp;
      if (!root) 
        return nullptr;
        
      // Splay the given value    
      root = splay(root, value);
        
      // If value is not present, then return root
      if (value != root->data)
        return root;
            
      // If value is present
      // If left child of root does not exist
      // make root->right as root   
      if (!root->left) {
        temp = root;
        root = root->right;
      }
      // Else if left child exits
      else {
          temp = root;
          /* Note: Since value == root->data,
          so after Splay(value, root->lchild),
          the tree we get will have no right child tree
          and maximum node in left subtree will get splayed */
          // New root
          root = splay(root->left, value);
        
          // Make right child of previous root  as
          // new root's right child
          root->right = temp->right;
      }
      // free the previous root node, that is,
      // the node containing the key
      delete temp;
      size--;
      // return root of the new Splay Tree
      return root;
  }

  template<class T>
  void SplayTree<T>::remove(T value) {
      root = removeRec(root, value);
  }

  template<class T>
  int SplayTree<T>::getSize() {
      return size;
  }

  template<class T>
  void SplayTree<T>::top5(){
    std::ofstream archivo("ips_con_mayor_acceso.txt");
    std::cout<<"IPs con mayor acceso: "<<std::endl;
    for (int i =0; i<5;i++){
    std::cout<<"IP: "<<vectorRegShort[0].getIp()<<" Numero de veces repetido: "<<vectorRegShort[0].getNumRepetido()<<std::endl;
      archivo<<"IP: "<<vectorRegShort[0].getIp()<<" Numero de veces repetido: "<<vectorRegShort[0].getNumRepetido()<<std::endl;
      pop();
      }
    while(sizeMaxHeap!=0){
            archivo<<"IP: "<<vectorRegShort[0].getIp()<<" Numero de veces repetido: "<<vectorRegShort[0].getNumRepetido()<<std::endl;
      pop();
    }
    archivo.close();
  }

  template<class T>
  int SplayTree<T>::getSize2() {
      return sizeMaxHeap;
  }

  template <class T> 
  void SplayTree<T>::printMaxHeap() {
    for (int i=0; i < sizeMaxHeap; i++)
      std::cout << vectorRegShort[i].getIp() << std::endl;
    std::cout << std::endl;
  }
  

#endif // _SPLAY_TREE_H_