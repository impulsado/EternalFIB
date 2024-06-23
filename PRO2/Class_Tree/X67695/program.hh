int suma_max_camiAux(const node_arbre* node) const {
    if (node==NULL) return 0;

    int suma_esq = suma_max_camiAux(node->segE);
    int suma_dreta = suma_max_camiAux(node->segD);
    
    if (suma_esq>suma_dreta) return node->info+suma_esq;
    return node->info+suma_dreta;
}

T max_suma_cami() const {
    return suma_max_camiAux(primer_node);
}