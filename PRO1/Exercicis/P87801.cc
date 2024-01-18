#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Rows;
typedef vector<Rows> Matrix;

typedef vector<char> Row;
typedef vector<Row> Sopa;

// Pre : entra la matriu de lletres, la paraula a trobar, unes coordenades ij i les dimensions de la matriu
// Post : retorna si la paraula es troba a la matriu
bool word_found(Sopa &sopa, string &p, int i, int j, int inci, int incj) {
	int r = sopa.size();
	int c = sopa[0].size();
	int len = 0;
	while (i < r and j < c and len < p.length()) {
		if (sopa[i][j] != p[len]) return false;
		i += inci;
		j += incj;
		++len;
	}
	return len == p.length();
}

int sum_points(Matrix &numeros, int len, int x, int y, int incx, int incy) {
	int sum = 0;
	for (int i = 0; i < len; ++i) {
	  sum += numeros[x][y];
	  x = x + incx;
	  y = y + incy;
	}
	return sum;
}

int main() {
	int r, c;
	while (cin >> r >> c) {
		Sopa sopa(r, vector<char>(c));
		for (int i = 0; i < r; ++i) { 
			for (int j = 0; j < c; ++j) cin >> sopa[i][j];
		}
		Matrix numeros(r, vector<int>(c));
		for (int i = 0; i < r; ++i) { 
			for (int j = 0; j < c; ++j) cin >> numeros[i][j];
		}
		int n;
		cin >> n;
		for (int k = 0; k < n; ++k) {
			string p;
			cin >> p;
			int len = p.length();
			int sum_max = -1; //int sum_max = 0;
			// bool found = false; <--- no hace falta esta var
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {	// recorrem matriu
					if (word_found(sopa, p, i, j, 0, 1)) { //horitzontal
					  //found = true;
					  int suma_punts = sum_points(numeros, len, i, j, 0, 1);
						if (sum_max < suma_punts) sum_max = suma_punts;
					}
					if (word_found(sopa, p, i, j, 1, 0)) { //vertical
					  //found = true;
					  int suma_punts = sum_points(numeros, len, i, j, 1, 0);
						if (sum_max < suma_punts) sum_max = suma_punts;
					}
				}
			}
			if (sum_max != -1) /*(found)*/ cout << sum_max << endl;
			else cout << "no" << endl;
		}
	}	
}

/*
#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > cMatrix;
typedef vector< vector<int> > iMatrix;

// Demanar Matriu de CHAR
void askcMatrix(cMatrix& matriu, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            cin >> matriu[row][col];
        }
    }
}

// Demanar Matriu de INT
void askiMatrix(iMatrix& matriu, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            cin >> matriu[row][col];
        }
    }
}

// Buscar paraula en HORIZONTAL
int searchHorizontal(cMatrix cMatriu, iMatrix iMatriu, int rows, int columns, string word) {
    vector<int> valors;
    int col, tmp_col, counter;
    char lletra;

    for (int row = 0; row<rows; row++) {  // Buscar en matriu
        col = tmp_col = counter = 0;  // Reset
        while (col<columns) {
            tmp_col = col;
            counter = 0;
            for (int pos = 0; pos<word.size(); pos++) {
                lletra = word[pos];

                if (tmp_col>=columns) {counter = 0; break;}  // No es passi del límit de la matriu  // Podria optimitzar-se fent que no guardi el valor si aquest es 0 i despres mirar si es empty

                if (lletra==cMatriu[row][tmp_col]) {
                    counter = counter + iMatriu[row][tmp_col];
                    tmp_col++;
                } else {counter = 0; break;}
            }

            valors.push_back(counter);
            col++;
        }
    }

    counter = 0;  // Farem servir el mateix comptador que ara ha quedat en desús
    for (int i = 0; i<valors.size(); i++) {  // Retornar el valor més gran dels vistos
        if (valors[i]>=counter) counter = valors[i];
    }

    return counter;
}

// Buscar paraula en VERICAL
int searchVertical(cMatrix cMatriu, iMatrix iMatriu, int rows, int columns, string word) {
    vector<int> valors;
    int row, tmp_row, counter;
    char lletra;

    for (int col = 0; col<columns; col++) {  // Buscar en matriu
        row = tmp_row = counter = 0;  // Reset
        while (row<rows) {
            tmp_row = row;
            counter = 0;
            for (int pos = 0; pos<word.size(); pos++) {
                lletra = word[pos];

                if (tmp_row>=rows) {counter = 0; break;}  // No passar-se del límit  // Podria optimitzar-se fent que no guardi el valor si aquest es 0 i despres mirar si es empty

                if (lletra==cMatriu[tmp_row][col]) {
                    counter = counter + iMatriu[tmp_row][col];
                    tmp_row++;
                } else {counter = 0; break;}
            }
            valors.push_back(counter);
            row++;
        }
    }

    counter = 0;  // Farem servir el mateix comptador que ara ha quedat en desús
    for (int i = 0; i<valors.size(); i++) {  // Retornar el valor més gran dels vistos
        if (valors[i]>=counter) counter = valors[i];
    }

    return counter;
}

int main () {
    int usr_rows, usr_cols, usr_quant;
    string paraula;

    while (cin >> usr_rows >> usr_cols) {
        // Demanar Matrius
        cMatrix cMatriu(usr_rows,vector<char>(usr_cols));
        iMatrix iMatriu(usr_rows,vector<int>(usr_cols));
        askcMatrix(cMatriu,usr_rows,usr_cols);
        askiMatrix(iMatriu,usr_rows,usr_cols);

        cin >> usr_quant;
        for (int i = 0; i<usr_quant; i++) {
            // Demanar paraula
            cin >> paraula;

            // Buscar puntuacions de la paraula
            int hor_counter = 0, ver_counter = 0;
            hor_counter = searchHorizontal(cMatriu,iMatriu,usr_rows,usr_cols,paraula);
            ver_counter = searchVertical(cMatriu,iMatriu,usr_rows,usr_cols,paraula);

            // Mostrar la màxima puntuació de la paraula
            if (hor_counter==0 and ver_counter==0) cout << "no" << endl;
            else if (hor_counter>=ver_counter) cout << hor_counter << endl;
            else if (ver_counter>=hor_counter) cout << ver_counter << endl;
        }
    }
}
*/