#include <iostream>

using namespace std;

template <typename T> class List {
private:
  
  // Items:
  
  class Item {
  public:
    T value;
    Item *next;
    Item *prev;
  };
  
  // Data:
  
  int _size;
  Item iteminf,itemsup;

  // Mètodes auxiliars

  void insertItem(Item *pitemprev, Item *pitem)
  /* Pre: pitemprev apunta a un element del p.i.
     pitemprev != pitem, 
     pitemprev.next = P, 
     pitem != nullptr,
     pitem apunta a un element singular */
  /* Post: inserta al p.i. el node apuntat per pitem entre el node apuntat
     per pitemprev i P, augmenta _size en 1 */  
  {
    pitem->next = pitemprev->next;
    pitem->next->prev = pitem;
    pitem->prev = pitemprev;
    pitemprev->next = pitem;
    _size++;
  }
  
  void insertItem(Item *pitemprev, const T &value) 
  /* Pre: pitemprev apunta un element del p.i.
     pitemprev.next = P */
  /* Post: inserta al p.i. un node amb valor value entre el node apuntat
     per pitemprev i P, augmenta _size en 1 */
  {
    Item *pitem = new Item;
    pitem->value = value;
    insertItem(pitemprev, pitem);
  }

  void extractItem(Item *pitem)
  /* Pre: pitem != & iteminf, pitem != &itemsup
     pitem apunta a un element del p.i. */
  /* Post: enllaça doblement el node anterior a pitem amb el posterior
     a pitem, disminueix en 1 _size */
  {
    pitem->next->prev = pitem->prev;
    pitem->prev->next = pitem->next;
    _size--;
  }

  void removeItem(Item *pitem) 
  /* Pre: pitem != & iteminf, pitem != &itemsup */
  /* Post: enllaça doblement el node anterior a pitem amb el posterior
     a pitem, s'allibera la memòria del node apuntat per pitem */
  {
    extractItem(pitem);
    delete pitem;
  }
    
  void removeItems() {
  /* Pre: _size = S */
  /* Post: s'ha alliberat la memòria dels S nodes entre iteminf i itemsup,
     iteminf.next = &itemsup, itemsup.prev = &iteminf, _size = 0*/
    while (_size > 0)
      removeItem(iteminf.next);
  }
  
  void copyItems(List & l) {
  /* Pre: cert*/
  /* Post: copia els elements de la llista l al p.i. */
    for (Item *pitem = l.itemsup.prev; pitem != &l.iteminf; pitem = pitem->prev)
      insertItem(&iteminf, pitem->value); 
  }
  
  
public:

  // Constructors/Destructors:
  
  List() 
  /* Pre: cert*/
  /* Post: el resultat és una llista sense elements */
  {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
  }

  List(List &l) 
  /* Pre: cert */
  /* Post: El resultat és una còpia d’l */
  {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
    copyItems(l);
  }

  ~List() 
  // Destructora: Esborra automàticament els objectes locals en
  // sortir d’un àmbit de visibilitat
  {
    removeItems();
  }

  // Assignment:
  
  List &operator=(const List &l) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una còpia d’l i qualsevol
     contingut anterior del p.i. ha estat esborrat
    (excepte si el p.i. i l ja eren el mateix objecte) */
  {
    if (this != &l) {
      removeItems();
      copyItems(l);
    }
    return *this;
  }

  // Standard operations:
  
  int size() const
  /* Pre: cert */
  /* Post: el resultat és el nombre de nodes del p.i
     (els nodes iteminf i itemsup no es conten) */
  {
    return _size;
  }

  bool empty() const
  /* Pre: cert */
  /* Post: el resultat és si el p.i té nodes o no
     (els nodes iteminf i itemsup no conten) */
  {
    return _size == 0;
  }


  void push_back(const T &value) 
  /* Pre: cert */
  /* Post: s'inserta un node amb valor value al final del p.i. */
  {
    insertItem(itemsup.prev, value);
  }
  
  void push_front(const T &value) 
  /* Pre: cert */
  /* Post: s'inserta un node amb valor value al principi del p.i. */
  {
    insertItem(&iteminf, value);
  }

  void pop_back() 
  /* Pre: el p.i. no és buit */
  /* Post: s'esborra el primer node del p.i. */
  {
    if (_size == 0) {
      cerr << "Error: pop_back on empty list" << endl;
      exit(1);
    }
    removeItem(itemsup.prev);
  }

  void pop_front()
  /* Pre: el p.i. no és buit */
  /* Post: s'esborra el darrer node del p.i. */
  {
    if (_size == 0) {
      cerr << "Error: pop_front on empty list" << endl;
      exit(1);
    }
    removeItem(iteminf.next);
  }


  // Read and write:
  
  template <typename U> friend istream &operator>>(istream &is, List<U> &l);

  template <typename U> friend ostream &operator<<(ostream &os, List<U> &l);

    
  // Iterators mutables
  class iterator {
    friend class List;
    private:
      List *plist;
      Item *pitem;
      // NEW
      bool activeHook;

      // Swap amb el següent.
      void swapNext() {
        Item *next = pitem->next;  // c

        pitem->next = next->next;  // b->d
        next->next->prev = pitem;  // b<-d
        next->next = pitem;  // c->b
        pitem->prev->next = next;  // a->c
        next->prev = pitem->prev;  // a<-c
        pitem->prev = next;  // c<-b
      }
      
      // Swap quan serà l'últim element.
      void swapNextSup() {
        Item *next = pitem->next;  // d

        pitem->next = &plist->itemsup;  // c->sup
        plist->itemsup.prev = pitem;  // c<-sup
        next->next = pitem;  // d->c
        next->prev = pitem->prev;  // b<-d
        pitem->prev->next = next;  // b->d
        pitem->prev = next;  // d<-c
      }

      // Swap quan és primer element.
      void swapNextInf() {
        Item *next = pitem->next;  // b

        plist->iteminf.next = next;  // inf->b
        next->prev = &plist->iteminf;  //inf<-b
        pitem->prev = next;  // b<-a
        pitem->next = next->next;  // a->c
        next->next->prev = pitem;  // a<-c
        next->next = pitem;  // b->a
      }

      // Swap amb l'anterior.
      void swapPrev() {
        Item *prev = pitem->prev;  // b

        prev->prev->next = pitem;  // a->c
        pitem->prev = prev->prev;  // a<-c
        prev->next = pitem->next;  // b->d
        pitem->next->prev = prev;  // b<-d
        prev->prev = pitem;  // c<-b
        pitem->next = prev;  // c->b
      }

/*
        cout << "swapPrev" << endl;
        Item *prev = pitem->prev;  // b

        prev->next = pitem;  // a->c
        pitem->prev = prev->prev;  // a<-c
        prev->prev = pitem;  // c<-b
        prev->next = pitem->next;  // b->d
        pitem->next->prev = prev;  // b<-d
        pitem->next = prev;  // c->b
*/

      // Swap quan és l'últim element.
      void swapPrevSup() {
        Item *prev = pitem->prev;  // c

        plist->itemsup.prev = prev;  // c<-sup
        prev->next = &plist->itemsup;  // c->sup
        prev->prev->next = pitem;  // b->d
        pitem->prev = prev->prev;  // b<-d
        prev->prev = pitem;  // d<-c
        pitem->next = prev;  // d->c
      }

      // Swap quan serà el primer element.
      void swapPrevInf() {
        Item *prev = pitem->prev;  // a

        plist->iteminf.next = pitem;  // inf->b
        pitem->prev = &plist->iteminf;  // inf<-b
        prev->prev = pitem;  // b<-a
        prev->next = pitem->next; // a->c
        pitem->next->prev = prev;  // a<-c
        pitem->next = prev;  // b->a
      }

      public:
      
    iterator() {
      activeHook = false;  // Tot i que per defecte ja és false
    }
    
    // Adapt this function so that moving beyond boundaries does not trigger error,
    // but leaves the iterator unchanged instead.
    // Also, add the necessary adaptations so that, when the iterator has an active hook,
    // instead of making the iterator point to next element (towards the end of the list),
    // the iterator keeps pointing to the same element, and this element swaps its position
    // with the next one (towards the end of the list). In the event that there is no such
    // a next element, nothing changes.
    // Preincrement
    iterator operator++()
    /* Pre: el p.i apunta a un element E de la llista,
       que no és el end() */
    /* Post: el p.i apunta a l'element següent a E 
       el resultat és el p.i. */
    {
      // === Base Case
      if (pitem == &(plist->itemsup)) return *this;
      
      if (this->activeHook) {
        // [it] ja està al final de la list
        if (pitem == plist->itemsup.prev) return *this;
        // [it] acabarà sent l'últim de la list
        if (pitem->next == plist->itemsup.prev) swapNextSup();
        // [it] és el primer de la list
        else if (pitem == plist->iteminf.next) swapNextInf();
        // [it] és un qualsevol del mig
        else swapNext();
      } 
      else pitem = pitem->next;

      return *this;
    }

    // Postincrement
    iterator operator++(int)
    /* Pre: p.i. = I,
       el p.i apunta a un element E de la llista,
       que no és el end() */
    /* Post: el p.i apunta a l'element següent a E,
       el resultat és I */
    {
      iterator aux = *this;
      operator++();
      return aux;
    }

    // Adapt this function so that moving beyond boundaries does not trigger error,
    // but leaves the iterator unchanged instead.
    // Also, add the necessary adaptations so that, when the iterator has an active hook,
    // instead of making the iterator point to previous element (towards the begin of the list),
    // the iterator keeps pointing to the same element, and this element swaps its position
    // with previous one (towards the begin of the list). In the event that there is no such
    // a previous element, nothing changes.
    // Predecrement
    iterator operator--()
    /* Pre: el p.i apunta a un element E de la llista que
       no és el begin() */
    /* Post: el p.i apunta a l'element anterior a E,
       el resultat és el p.i. */
    {
      // === Base Case 
      if (pitem == plist->iteminf.next) return *this;

      if (this->activeHook) {
        // [it] ja està al prinicipi de la list
        if (pitem == plist->iteminf.next) return *this;
        // [it] és l'últim de la list
        else if (pitem == plist->itemsup.prev) swapPrevSup();
        // [it] acabarà sent el primer de la list
        else if (pitem->prev == plist->iteminf.next) swapPrevInf();
        // [it] és un qualsevol del mig
        else swapPrev();
      }
      else pitem = pitem->prev;
      
      return *this;
    }

    // Postdecrement
    iterator operator--(int)
    /* Pre: p.i. = I,
       el p.i apunta a un element E de la llista que no és el begin() */
    /* Post: el p.i apunta a l'element anterior a E,
       el resultat és I */
    {
      iterator aux = *this;
      operator--();
      return aux;
    }

    T& operator*()
    /* Pre: el p.i apunta a un element E de la llista,
       que no és el end() */
    /* Post: el resultat és el valor de l'element E */
    {
      if (pitem == &(plist->itemsup)) {
        cerr << "Error: * on iterator at the end of list" << endl;
        exit(1);
      }
      return pitem->value;
    }
    
    bool operator==(const iterator &it) const 
    /* Pre: cert */
    /* Post: el resultat ens diu si els dos iteradors són iguals */
    {
      return plist == it.plist and pitem == it.pitem;
    }

    bool operator!=(const iterator &it) const 
    /* Pre: cert */
    /* Post: el resultat ens diu si els dos iteradors són diferents */
    {
      return not (plist == it.plist and pitem == it.pitem);
    }
 
    // Pre: Iterator 'this' (the implicit parameter) does not have an active hook,
    //      and it points to an element of a list.
    //      In particular, 'this' does not point to the end of a list.
    // Post: 'it' keeps pointing to the same element and has an active hook to this element.
    // Remove comment marks and implement this function:
    void hook() {
      this->activeHook = true;
    }
      
    // Pre: 'this' has an active hook.
    // Post: 'this' does not have an active hook.
    // Remove comment marks and implement this function:
    void stopHook() {
      this->activeHook = false;
    }

    // Pre:
    // Post: Returns true iff 'this' has an active hook.
    // Remove comment marks and implement this function:
    bool hasActiveHook() const {
      return this->activeHook;
    }
  };
  
  // Operations with iterators:
  
  iterator begin () 
  /* Pre: cert */
  /* Post: el resultat apunta al primer element del p.i o 
     a l'element fictici si el p.i. no té cap element no
     fictici */
  {
    iterator it;
    it.plist = this;
    it.pitem = iteminf.next;
    return it;
  }
    
  iterator end() 
  /* Pre: cert */
  /* Post: el resultat apunta a l'element fictici */
  {
    iterator it;
    it.plist = this;
    it.pitem = &itemsup;
    return it;
  }

  iterator insert(iterator it, const T & value)
  /* Pre: it ha d'apuntar a un element del p.i
     o a l'element fictici end() del p.i */
  /* Post: s'inserta un element amb valor value abans 
     de l'element al que apunta it i el resultat 
     apunta al nou element inserit */
  {
    if (it.plist != this) {
      cout << "Error: insert with an iterator not on this list" << endl;
      exit(1);
    }
    iterator res = it;
    insertItem(res.pitem->prev, value);
    res.pitem = res.pitem->prev;
    return res;
  }

  iterator erase(iterator it)
  /* Pre: it ha d'apuntar a un element del p.i 
     que no sigui l'end() */
  /* Post: s'elimina l'element apuntat per it, el 
     resultat apunta a l'element posterior a l'eliminat */ 
  {
    if (it.plist != this) {
      cout << "Error: erase with an iterator not on this list" << endl;
      exit(1);
    }
    if (it.pitem == &itemsup) {
      cout << "Error: erase with an iterator pointing to the end of the list" << endl;
      exit(1);
    }
    iterator res = it;
    res.pitem = res.pitem->next;
    removeItem(res.pitem->prev);
    return res;
  }
  

  // Iteradors constants
  
  class const_iterator {
    friend class List;
  private:
    List const *plist;
    Item const *pitem;
      
      
  public:
  
    // Preincrement
    const_iterator operator++()
    /* Pre: el p.i apunta a un element E de la llista,
       que no és el end() */
    /* Post: el p.i apunta a l'element següent a E,
       el resultat és el p.i. */
    {
      if (pitem == &(plist->itemsup)) {
        cerr << "Error: ++iterator at the end of list" << endl;
        exit(1);
      }
      pitem = pitem->next;
      return *this;
    }
    
    // Postincrement
    const_iterator operator++(int)
    /* Pre: p.i. = I,
       el p.i apunta a un element E de la llista, que no és el end() */
    /* Post: el p.i apunta a l'element següent a E,
       el resultat és I */
    {
      if (pitem == &(plist->itemsup)) {
        cerr << "Error: iterator++ at the end of list" << endl;
        exit(1);
      }
      const_iterator aux = *this;
      pitem = pitem->next;
      return aux;
    }
    
    // Predecrement
    const_iterator operator--()
    /* Pre: el p.i apunta a un element E de la llista que
       no és el begin() */
    /* Post: el p.i apunta a l'element anterior a E,
       el resultat és el p.i. */
    {
      if (pitem == plist->iteminf.next) {
       cerr << "Error: --iterator at the beginning of list" << endl;
       exit(1);
      }
      pitem = pitem->prev;
      return *this;
    }
    
    // Postdecrement
    const_iterator operator--(int)
    /* Pre: p.i. = I,
       el p.i apunta a un element E de la llista que no és el begin() */
    /* Post: el p.i apunta a l'element anterior a E,
       el resultat és I */
    {
      if (pitem == plist->iteminf.next) {
        cerr << "Error: iterator-- at the beginning of list" << endl;
        exit(1);
      }
      const_iterator aux;
      aux = *this;
      pitem = pitem->prev;
      return aux;
    }

    const T& operator*()
    /* Pre: el p.i apunta a un element E de la llista,
       que no és el end() */
    /* Post: el resultat és el valor de l'element E */
    {
      return pitem->value;
    }

    bool operator==(const const_iterator &it) const
    /* Pre: cert */
    /* Post: el resultat ens diu si els dos iteradors són iguals */
    {
      return plist == it.plist and pitem == it.pitem;
    }

    bool operator!=(const const_iterator &it) const 
    /* Pre: cert */
    /* Post: el resultat ens diu si els dos iteradors són diferents */
    {
      return not (plist == it.plist and pitem == it.pitem);
    }
      
  };
    
  const_iterator cbegin() const
  /* Pre: cert */
  /* Post: el resultat apunta al primer element del p.i o 
     a l'element fictici si el p.i. no té cap element no
     fictici */
  {
    const_iterator it;
    it.plist = this;
    it.pitem = iteminf.next;
    return it;
  }
    
  const_iterator cend() const
  /* Pre: cert */
  /* Post: el resultat apunta a l'element fictici */
  {
    const_iterator it;
    it.plist = this;
    it.pitem = &itemsup;
    return it;
  }
  
  const_iterator insert(const_iterator it, const T & value)
  /* Pre: it ha d'apuntar a un element del p.i
     o a l'element fictici end() del p.i */
  /* Post: s'inserta un element amb valor value abans 
     de l'element al que apunta it i el resultat 
     apunta al nou element inserit */
  {
    if (it.plist != this) {
      cout << "Error: insert with an iterator not on this list" << endl;
      exit(1);
    }
    const_iterator res = it;
    insertItem(res.pitem->prev, value);
    res.pitem = res.pitem->prev;
    return res;
  }

  const_iterator erase(const_iterator it)
  /* Pre: it ha d'apuntar a un element del p.i 
     que no sigui l'end() */
  /* Post: s'elimina l'element apuntat per it, el 
     resultat apunta a l'element posterior a l'eliminat */ 
  {
    if (it.plist != this) {
      cout << "Error: erase with an iterator not on this list" << endl;
      exit(1);
    }
    if (it.pitem == &itemsup) {
      cout << "Error: erase with an iterator pointing to the end of the list" << endl;
      exit(1);
    }
    const_iterator res = it;
    res.pitem = res.pitem->next;
    removeItem(res.pitem->prev);
    return res;
  }
  
};

// Implementation of read and write lists.

template <typename T> istream &operator>>(istream &is, List<T> &l)
{
  l.removeItems();
  int size;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    T value;
    cin >> value;
    l.insertItem(l.itemsup.prev, value);
  }
  return is;
}

template<typename T> ostream &operator<<(ostream &os, List<T> &l)
{
  os << l._size;
  for (typename List<T>::Item* pitem = l.iteminf.next; pitem != &l.itemsup; pitem = pitem->next)
    cout << " " << pitem->value;
  return os;
}
