/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
    bool found = false;
    buscarAux(primer_node, x, found);
    return found;
}

void buscarAux(const node_arbreGen* node, const T& x, bool &found) const {
    // === Base Cases
    if (node==NULL) return;
    if (found) return;

    // === General Case
    if (node->info == x) {
        found = true;
        return;
    }
    if (node->seg.size()>0) {
        for (int i = 0; i<node->seg.size() and not found; i++) {
            buscarAux(node->seg[i], x, found);
        }
    }

    return;
}