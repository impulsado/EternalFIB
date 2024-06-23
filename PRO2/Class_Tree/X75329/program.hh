int freqAux(const node_arbre* node, const T& x) const {
    // === Base Case
    if (node == NULL) return 0;

    // === General Case
    int num = 0;
    if (node->info == x) num++;
    num += freqAux(node->segE, x);
    num += freqAux(node->segD, x);

    return num;
}

/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
    return freqAux(primer_node, x);
}