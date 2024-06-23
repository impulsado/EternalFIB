/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    asum.primer_node = arb_sumesAux(primer_node);
}

node_arbre* arb_sumesAux(node_arbre* node) const {
    // === Base Case
    if (node == NULL) return NULL;

    // === General Case
    // Recursivitat
    node_arbre* left = arb_sumesAux(node->segE);
    node_arbre* right = arb_sumesAux(node->segD);
    
    // Fer la suma dels sub-arbres
    int value = node->info;
    if (left != NULL) value += left->info;
    if (right != NULL) value += right->info;

    // Crear el nou node que conté la suma
    // Realment hem de crear un arbre de sumes fisicament al nostre disc. 
    // Això també passava abans amb els exercicis de BinTree pero era "invisible" per a nosaltres.
    node_arbre *actual = new node_arbre;
    actual->info = value;
    actual->segE = left;
    actual->segD = right;
    
    return actual;
}