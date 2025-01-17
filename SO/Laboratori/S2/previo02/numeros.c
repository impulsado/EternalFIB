#include <stdbool.h>
//#include <stdio.h>
#include <unistd.h>
 
#define MAX_SIZE 8

int esNumero(char *str) {
	int i = 0;
	bool esNum = true;
	
	// printf("El primer número es %d\n",str[0]);
	while (esNum && str[i] != '\0') {
		if (48>str[i] || 57<str[i]) esNum = false;		
		i++;
	}

	if (esNum && i<=MAX_SIZE) return 1;
	else return 0;

}

int main(int argc, char *argv[]) {
	if (esNumero(argv[1]) == 1) {
		write(1, "SI número\n", 11);  // 11 = longitud del missatge perquè 'ú' en UTF-8 són 2B
		return 1;
	}
	else {
		write(1, "NO número\n", 11); 
		return 0;
	}
}
