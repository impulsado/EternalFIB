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
    bool isMark;
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
    if (pitem->next != NULL) os << " ";
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

  // Modifica aquesta funció per a recordar que l'element afegit no està marcat.
  void push(T value) {
    Item *pnewitem = new Item();
    pnewitem->value = value;
    pnewitem->next = ptopitem;
    pnewitem->isMark = false;  // Afegit
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
  // Post: S'afegeix value al cim de la pila, com a element marcat.
  // Descomenteu les següents dues linies i implementeu el mètode:
  void push_mark(T value) {
    Item *pnewitem = new Item();
    pnewitem->value = value;
    pnewitem->next = ptopitem;
    pnewitem->isMark = true;  // Afegit
    ptopitem = pnewitem;
    _size++;
  }


  // Pre: 
  // Post: S'han eliminat del cim de la pila el mínim nombre d'elements necessaris
  //       per tal de garantir que o bé el cim de la pila té un element que va ser
  //       afegit amb push_mark, o bé la pila és buida.
  //       En particular, si el cim de la pila ja tenia un element marcat, no s'ha eliminat res.
  // Descomenteu les següents dues linies i implementeu el mètode:
  void pop_mark() {
    if (ptopitem == NULL) {
      return;
    }
    if (ptopitem->isMark) {
      return;
    }
    while (ptopitem!=NULL and (not ptopitem->isMark)) {
      Item *paux = ptopitem;
      ptopitem = ptopitem->next;
      delete paux;
      _size--;
    }
  }
  
};

// Implementation of read and write:

template <typename U> ostream &operator<<(ostream &os, const Stack<U> &s)
{
  //os << s._size;
  //if (s.ptopitem != NULL) os << " ";
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
