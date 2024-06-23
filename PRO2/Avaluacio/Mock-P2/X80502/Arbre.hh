// NOTA; la version de laboratorio contiene excepciones para controlar
// las situaciones de error

using namespace std;

template <class T> class Arbre { 
private:     
  struct node_arbre {
    T info;
    node_arbre* segE;
    node_arbre* segD;
  };
  node_arbre* primer_node;

  // especificaci� operacions privades
static node_arbre* copia_node_arbre(node_arbre* m)
  /* Pre: cert */
  /* Post: el resultat �s NULL si m �s NULL; en cas contrari, el resultat apunta
     al node arrel d'una jerarquia de nodes que �s una c�pia de la 
     jerarquia de nodes que t� el node apuntat per m com a arrel */
  {
    node_arbre* n;
    if (m==NULL) n=NULL;
    else {
      n = new node_arbre;
      n->info = m->info;
      n->segE = copia_node_arbre(m->segE);
      n->segD = copia_node_arbre(m->segD);
    }
    return n;
  }

static void esborra_node_arbre(node_arbre* m) 
  /* Pre: cert */
  /* Post no fa res si m �s NULL; en cas contrari, allibera espai de tots els nodes
     de la jerarquia que t� el node apuntat per m com a arrel */
  {
    if (m != NULL) {
      esborra_node_arbre(m->segE);
      esborra_node_arbre(m->segD);
      delete m;
    }
  }
public:
  // especificaci� operacions p�bliques
  Arbre() 
  /* Pre: cert */
  /* Post: el p.i. �s un arbre buit */
  {
    primer_node= NULL;
  }

  Arbre(const Arbre& original) 
  /* Pre: cert */
  /* Post: el p.i. �s una c�pia d'original */
  {
    primer_node = copia_node_arbre(original.primer_node);
  }

  ~Arbre() {
    esborra_node_arbre(primer_node);
  }

  Arbre& operator=(const Arbre& original) {
    if (this != &original) {
      esborra_node_arbre(primer_node);
      primer_node = copia_node_arbre(original.primer_node);
    }
    return *this;
  }

  void swap(Arbre &a) // a1.swap(a2);
    /* Pre: a=A, p.i. = P */
    /* Post: el p.i. passa a ser A; a passa a ser P */
  {
    node_arbre* aux;
    // o tambien swap(primer_node, a.primer_node);
    aux = a.primer_node;
    a.primer_node = primer_node;
    primer_node = aux;
  }

  void a_buit() 
  /* Pre: cert */
  /* Post: el p.i. �s un arbre buit */
  {
    esborra_node_arbre(primer_node);
    primer_node = NULL;
  }        

  // a.plantar(x,a1,a2);
  void plantar(const T &x, Arbre &a1, Arbre &a2) 
  /* Pre: El par�metre impl�cit �s buit, a1 = A1, a2 = A2, el p.i. �s
     buit per� no �s el mateix objecte que a1 ni a2 */
  /* Post: El par�metre impl�cit t� x com a arrel, A1 com a fill esquerre
     i A2 com a fill dret; a1 i a2 s�n buits; si A1 i A2 s�n el mateix objecte,
     el fill dret n'�s una c�pia  */ 
  {
    node_arbre* aux; // se puede hacer sin aux
    aux = new node_arbre;
    aux->info = x;
    aux->segE= a1.primer_node;
    // HAY QUE EVITAR LA COMPARTICION DE NODOS:
    if (a1.primer_node == a2.primer_node) aux->segD = copia_node_arbre(a1.primer_node);
    else  aux->segD = a2.primer_node;
    primer_node = aux;
    a1.primer_node = NULL;
    a2.primer_node = NULL;
    /* sin aux
   
    primer_node = new node_arbre;
    primer_node->info = x;
    primer_node->segE= a1.primer_node;
    // HAY QUE EVITAR LA COMPARTICION DE NODOS:
    if (a1.primer_node == a2.primer_node) primer_node->segD= copia_node_arbre(a1.primer_node);
    else  primer_node->segD= a2.primer_node;
    a1.primer_node = NULL;
    a2.primer_node = NULL;
  
    */
  }

  void fills (Arbre &fe, Arbre &fd) 
  /* Pre: El par�metre impl�cit no �s buit; fe, fd s�n buits i no
     s�n el matex objecte */ // a.fills(b,b); NO
  /* Post: fe �s el fill esquerre del par�metre impl�cit original; fd �s
     el fill dret del par�metre impl�cit original, el par�metre impl�cit
     �s buit */
  {
    node_arbre* aux;  // se puede hacer sin aux
    aux = primer_node;
    fe.primer_node = aux->segE;
    fd.primer_node = aux->segD;
    primer_node = NULL;
    delete aux;

    /* sin aux
      fe.primer_node = primer_node->segE;
      fd.primer_node = primer_node->segD;
      delete primer_node;
      primer_node = NULL;
    */
  }

  T arrel() const 
  /* Pre: el p.i. no �s buit */
  /* Post: el resultat �s l'arrel del p.i. */
  {  
    return primer_node->info;
  }

  bool es_buit() const 
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. �s un arbre buit */
  {  
    return (primer_node==NULL);
  }

  // Extensi�n -----------------------------------------------------


// Pre:  el p.i. i a s�n arbres de enters positius
// Post: Retorna la intersecci� del p.i. i a, on cada node
//       cont� la suma dels nodes corresponents del p.i. i a
// Descomenteu les seg�ents dues linies i implementeu el m�tode:
Arbre suma (const Arbre& a) const{
  Arbre<T> resultat;
  resultat.primer_node = sum_aux(this->primer_node, a.primer_node);
  return resultat;
}
private:
  

  static node_arbre* sum_aux(node_arbre* n,  node_arbre *m){
    // === Base Case
    if (n==nullptr or m==nullptr) return nullptr;

    // === General Case
    node_arbre* node = new node_arbre;
    node->info = n->info + m->info;
    if (n->segE!=nullptr and m->segE!=nullptr) node->segE = sum_aux(n->segE, m->segE);
    if (n->segD!=nullptr and m->segD!=nullptr) node->segD = sum_aux(n->segD, m->segD);
    return node;
  }  
  
};
