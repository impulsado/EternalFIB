/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    asum.primer_node = arbSumaAux(primer_node, N);
}

node_arbreNari* arbSumaAux(const node_arbreNari* node, int mida) const {
    // Base Case
    if (node==NULL) return NULL;

    // General Case
    node_arbreNari *n = new node_arbreNari;
    
    n->info = node->info;
    n->seg = node->seg;
    if (node->seg.size()>0) {
        // Fer recusrivitat
        for (int i = 0; i<mida; i++) n->seg[i] = arbSumaAux(node->seg[i], mida);
        // Fer suma dels subarbres
        for (int i = 0; i<mida; i++) {
            if (n->seg[i] != NULL) n->info += n->seg[i]->info;
        }
    }

    return n;
}