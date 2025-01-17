#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// AQUEST EXEMPLE SUPOSA QUE L'ENTRADA ES EN FORMAT BINARI
int main(void) {
    int num;
    int n = read(0, &num, sizeof(int));  // llegim de la entrada standard
    printf("NUMERO: %d\n", num);
}