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
  bool isEntagled;
  Stack<T>* cua;
  
  int _size;
  Item* ptopitem;

  // Add what it takes to know if the stack is engangled to another stack and which one.
    
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
    isEntagled = false;
  }
  
  Stack(const Stack<T> &s) {
    ptopitem = copyItems(s.ptopitem);
    _size = s._size;
    // This function won't be used in this exercise but you can add initializations here if you want.
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
      // This function won't be used in this exercise but you can add initializations here if you want.
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
    // Change what it takes so that, if the stack is entangled, then value is also piled to the other stack.
    Item *pnewitem = new Item();
    pnewitem->value = value;
    pnewitem->next = ptopitem;
    ptopitem = pnewitem;
    _size++;

    bool wasEntagled = false;
    if (this->isEntagled) {
      if (cua->isEntagled) {
        wasEntagled = true;
        cua->isEntagled = false;
      }
      cua->push(value);
      if (wasEntagled) cua->isEntagled = true;
    }
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
      
  // Remove comments and implement the following two methods:

  // Pre:
  // Post: The implicit parameter is linked to the queue q given as parameter,
  //       so that any push on the implicit parameter also piles the same element
  //       on top of q. Any other previous entanglement is cancelled.
  void entangle(Stack &s) {
    this->isEntagled = true;
    cua = &s;
  }

  // Pre: The implicit parameter is linked to some other stack.
  // Post: The implicit parameter is not linked, so that, unless stated otherwise,
  //       any push on the implicit parameter does not affect any other stack.
  void disentangle() {
   this->isEntagled = false; 
   cua = nullptr;
  }
};

// Implementation of read and write:

template <typename U> ostream &operator<<(ostream &os, const Stack<U> &s)
{
  os << s._size;
  if (s.ptopitem != NULL) os << " ";
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
