#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
private:

  // Items:
  
  struct Item {
    T value;
    Item* next;
  };

  // Data:
  
  int _size;
  Item* ptopitem;

  // Helpers:
  
  Item* copyItems(Item *pitem) {
    if (pitem == NULL) return NULL;
    Item *pfirstitem = new Item();
    Item *pcurrentitem = pfirstitem;
    while (pitem != NULL) {
      pcurrentitem->value = pitem->value;
      if (pitem->next != NULL) pcurrentitem->next = new Item();
      else pcurrentitem->next = NULL;
      pcurrentitem = pcurrentitem->next;
      pitem = pitem->next;
    }
    return pfirstitem;
  }
  
  void deleteItems()
  {
    Item *pitem = ptopitem;
    while (pitem != NULL) {
      Item *pitemaux = pitem;
      pitem = pitem->next;
      delete pitemaux;
    }
    _size = 0;
  }
  
  void printRec(ostream &os, const Item *pitem) const
  {
    if (pitem == NULL) return;
    printRec(os, pitem->next);
    os << " ";
    os << pitem->value;
  }
  
public:

  // Constructors/destructors.
  Stack() {
    ptopitem = NULL;
    _size = 0;
  }
  
  Stack(const Stack<T> &s) {
    ptopitem = copyItems(s.ptopitem);
    _size = s._size;
  }
  
  ~Stack() {
    deleteItems();
  }

  // Assignment:
  
  Stack<T> &operator=(const Stack<T> &s) {
    if (this != &s) {
      deleteItems();
      ptopitem = copyItems(s.ptopitem);
      _size = s._size;
    }
    return *this;
  }

  // Standard functions:
  
  int size() {
    return _size;
  }

  bool empty() const {
    return ptopitem == NULL;
  }

  void push(T value) {
    Item *pnewitem = new Item();
    pnewitem->value = value;
    pnewitem->next = ptopitem;
    ptopitem = pnewitem;
    _size++;
  }
  
  void pop() {
    if (ptopitem == NULL) {
      cerr << "Error: pop on empty stack" << endl;
      exit(1);
    }
    Item *paux = ptopitem;
    ptopitem = ptopitem->next;
    delete paux;
    _size--;
  }
    
  T top() {
    if (ptopitem == NULL) {
      cerr << "Error: accessing top of empty stack" << endl;
      exit(1);
    }
    return ptopitem->value;
  }
    
  const T top() const {
    if (ptopitem == NULL) {
      cerr << "Error: accessing top of empty stack" << endl;
      exit(1);
    }
    return ptopitem->value;
  }

  // Read and write:
  
  template <typename U> friend ostream &operator<<(ostream &os, const Stack<U> &s);
  template<typename U> friend istream &operator>>(istream &is, Stack<U> &s);
    
  // Pre:
  // Post: Elimina l'element de la pila implícita que es troba en segona posició des del top.
  //       Si la pila té només un element, llavors elimina aquest element.
  //       Si la pila no té cap element, llavors no canvia res.
  // Descomenteu les següents dues linies i implementeu el mètode:
  void pop2() {
    // És buida
    if (_size==0) return;
    // Només té 1 element
    if (_size==1) {pop(); return;}
    Item* aux = ptopitem->next;
    delete ptopitem->next;
    ptopitem->next = aux->next;
    
    _size--;
  }
  
};

// Implementation of read and write:

template <typename U> ostream &operator<<(ostream &os, const Stack<U> &s)
{
  os << s._size;
  s.printRec(os, s.ptopitem);
  return os;
}

template <typename U> istream &operator>>(istream &is, Stack<U> &s)
{
  int n;
  is >> n;
  s = Stack<U> ();
  for (int i = 0; i < n; i++) {
    U u;
    is >> u;
    s.push(u);
  }
  return is;
}
