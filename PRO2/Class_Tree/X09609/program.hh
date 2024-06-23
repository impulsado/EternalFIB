/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
    pair<node_arbre*, int> result = sub_arrelAux(primer_node, x, 0);

    if (result.first != NULL) asub.primer_node = copia_node_arbre(result.first);
}

pair<node_arbre*,int> sub_arrelAux(const node_arbre* node, const T&x, int dist) {
    // Base Case
    if (node==NULL) return make_pair((node_arbre*)NULL, 0);

    // General Case
    if (node->info == x) return make_pair((node_arbre*)node, dist);

    // Recursivitat
    pair<node_arbre*,int> node_esq = sub_arrelAux(node->segE, x, dist+1);
    pair<node_arbre*,int> node_dret = sub_arrelAux(node->segD, x, dist+1);

    // Tots dos subarbres contenen l'element buscat
    if (node_esq.first != NULL and node_dret.first != NULL) {
        if (node_esq.second<node_dret.second) return node_esq;
        else if (node_dret.second<node_esq.second) return node_dret;
        return node_esq;
    }
    // Només el de l'esquerra conté l'element buscat
    else if (node_esq.first != NULL) return node_esq;
    // Només el de la dreta conté l'element buscat
    else if (node_dret.first != NULL) return node_dret;
    
    // Cap conté l'element buscat
    return make_pair((node_arbre*)NULL, dist);
}