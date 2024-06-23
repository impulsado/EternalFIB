#ifndef ARBREGENERAL_HH
#define ARBREGENERAL_HH

#include "utils.PRO2"
#include <vector>

template <class T> class ArbreGen {

private:     
  struct node_arbreGen {
    T info;
    vector<node_arbreGen*> seg;
  };
  node_arbreGen* primer_node;
  // especificació operacions privades

  static node_arbreGen* copia_node_arbreGen(node_arbreGen* m) { 
    /* Pre: cert */
    /* Post: el resultat és NULL si m és NULL; en cas contrari, el resultat apunta
       al node arrel d'una jerarquia de nodes que és una còpia de la 
       jerarquia de nodes que té el node apuntat per m com a arrel */
    node_arbreGen* n;
    if (m == NULL) n = NULL;
    else {
      n = new node_arbreGen;
      n->info = m->info;
      int ari = m->seg.size();
      n->seg = vector<node_arbreGen*>(ari);
      for (int i = 0; i < ari; ++i) 
	n->seg[i] = copia_node_arbreGen(m->seg[i]);        
    }
    return n;
  }

  static void esborra_node_arbreGen(node_arbreGen* m) {  
    /* Pre: cert */
    /* Post no fa res si m és NULL; en cas contrari, allibera espai de tots els nodes
       de la jerarquia que té el node apuntat per m com a arrel */
    if (m != NULL) {
      int ari = m->seg.size();
      for (int i=0; i<ari; ++i) 
	esborra_node_arbreGen(m->seg[i]);
      delete m;
    }
  }

public:
  // especificació operacions públiques
  ArbreGen() {
    /* Pre: cert */
    /* Post: el p.i. és un arbre general buit */
    primer_node = NULL;
  }

  ArbreGen(const T &x) {
    /* Pre: cert */
    /* Post: el resultat és un arbre general amb arrel x i sense fills */
    primer_node= new node_arbreGen;
    primer_node->info = x;
    // No cal fer primer_node->seg = vector<node_arbreGen*>(0);
  }

  ArbreGen(const ArbreGen& original) {
    /* Pre: cert */
    /* Post: el resultat és una còpia d'original */
    primer_node = copia_node_arbreGen(original.primer_node);
  }

  ~ArbreGen()
  // Destructora: Esborra automàticament els objectes locals en
  // sortir d'un àmbit de visibilitat
  {
    esborra_node_arbreGen(primer_node);
  }

  ArbreGen& operator=(const ArbreGen& original)
  /* Pre: cert */
  /* Post: El p.i. passa a ser una còpia d'original i qualsevol
     contingut anterior del p.i. ha estat esborrat 
     (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      esborra_node_arbreGen(primer_node);
      primer_node = copia_node_arbreGen(original.primer_node);
    }
    return *this;
  }

  void a_buit() {
    /* Pre: cert */
    /* Post: el p.i. és un arbre general buit i qualsevol
       contingut anterior del p.i. ha estat esborrat */
    esborra_node_arbreGen(primer_node);
    primer_node = NULL;
  }        

  void plantar(const T &x) {
    /* Pre: el p.i. és buit */
    /* Post: el p.i. té x com a arrel i zero fills */
    if (primer_node == NULL) {  
      primer_node = new node_arbreGen;
      primer_node->info = x;
      // No cal fer primer_node->seg = vector<node_arbreGen*>(0);
    }
    else throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
  }

  void plantar(const T &x, vector<ArbreGen> &v) {
    /* Pre:  el p.i. és buit i v.size()>0 i cap arbre de v és buit */
    /* Post: el p.i. té x com a arrel i els elements originals  
       de v com a fills, v passa a contenir arbres buits */
    if (primer_node == NULL) { 
      int n = v.size();
      if (n > 0){
	node_arbreGen* aux = new node_arbreGen;
	aux->info = x;
     
	aux->seg = vector<node_arbreGen*>(n);
	for (int i = 0; i < n; ++i) {
	  if (v[i].primer_node != NULL) {
	    aux->seg[i] = v[i].primer_node;
	    v[i].primer_node = NULL;
	  }
	  else throw PRO2Excepcio("No es pot plantar amb arbres buits al vector");
	}
	primer_node= aux;
      }
      else throw PRO2Excepcio("No es pot plantar amb un vector buit");
    }
    else throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
  }

  void afegir_fill(const ArbreGen &a) {
    /* Pre: el p.i. i a no són buits */
    /* Post: el p.i. té un fill més que a l'inici, i aquest nou darrer fill 
       és una còpia de l'arbre a */
    (primer_node->seg).push_back(copia_node_arbreGen(a.primer_node));
  }       

  void fill(const ArbreGen &a, int i) {
    /* Pre: el p.i. és buit, a no és buit, i està entre 1 i el nombre de fills d'a */
    /* Post: el p.i és una còpia del fill i-èssim d'a */
    primer_node = copia_node_arbreGen((a.primer_node)->seg[i-1]);
  }       

  void fills(vector<ArbreGen> &v) {
    /* Pre:  el p.i. no és buit i li diem A, v és un vector buit  */
    /* Post: el p.i. és buit, v passa a contenir els fills de l'arbre A  */
    if (primer_node != NULL) {
      if (v.size() == 0){
	node_arbreGen* aux = primer_node;
	int n = aux->seg.size();
	v = vector<ArbreGen> (n);
	for (int i = 0; i < n; ++i) 
	  v[i].primer_node = aux->seg[i];  
	primer_node = NULL;
	delete aux;
      }
      else throw PRO2Excepcio("No es pot passar a fills un vector no buit");
    }
    else throw PRO2Excepcio("Un arbre buit no te fills");
  }

  T arrel() const {
    /* Pre: el p.i. no és buit */
    /* Post: el resultat és l'arrel del p.i. */
    if (primer_node != NULL) 
      return primer_node->info;
    else
      throw PRO2Excepcio ("Un arbre buit no té arrel");
  }

  bool es_buit() const {
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. és un arbre buit */
    return (primer_node == NULL);
  }

  int nombre_fills() const {
    /* Pre: el p.i. no és buit */
    /* Post: el resultat és el nombre de fills del p.i. */
    if (primer_node != NULL) 
      return (primer_node->seg).size();
    else
      throw PRO2Excepcio ("Un arbre buit no té nombre de fills");
  }
  //
  // extension
  //
  #include "program.hh"
   
};

#endif
