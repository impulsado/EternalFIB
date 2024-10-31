#include <vector>
#include <iostream>
using namespace std;

/*
=== IDEA ===
Hi ha un element (pivot) que és el que sap si un element ha d'anar davant o darrere seu.
# Imaginar com una cua que s'ordena per alçada. Ell només sap si una persona és més alta o no.
Llavors va intercanvient la primera persona que no li toca estar darrere seu amb la primera persona
que troba que no li toca estar davant seu (Sigui ASC/DESC).
Posteriorment es fa recursivament pels que estàn davant com darrere.
# El pivot que hem escollit si que esta en la pos. correcta. Ja no farà falta tindre-lo en compte.

=== COST ===
WORST = O(n^2)
AVG = BEST = O(n*log(n))

=== ASC/DESC === 
Per modificar el funcionament, simplement hem de canviar:
|     ASC     |     DESC    |
| ----------- | ----------- |
| v[i]<=pivot | v[i]>pivot  | 
| v[j]>pivot  | v[j]<=pivot |
*/

int partition(vector<int>& v, int low, int high, int pivot) {
    // 1. Inicialitcem "els punters" que serviràn per revisar a l'hora els previs 
    // i els posteriors respecte el pivot.
    // NOTA: Donat que sabem que pivot==v[low], podem agafar el següent i = low+1
    int i = low + 1;
    int j = high;
    
    // 2. Recorrem el vector en busqueda d'elements malament posicionats.
    // La condició de sortida implica que si no s'han creuat, encara hi ha un element malament pos.
    // És important considerar el cas i==j perquè sino, podria haver un element no comprobat
    // abans que es passin j<i.
    while (i <= j) {
        /*
        EXPLICACIÓ:
        1. Avançar mentre i no sobre passi a j.
        Si sobre passa, significa que no hem trobat un element malament pos. respecte pivot.

        2. Mentre l'element que veguem sigui més petit que el pivot avançar.
        Això assegura que els elements a l'esquerra del pivot siguin menors o iguals.
        # Podem pensar busquem la primera persona que serà més alta que el pivot.
        # Altrament, significa que estant abans que el pivot, ja estàn "ben ficats".
        */
        while (i<=j && v[i]<=pivot) i++;

        /*
        EXPLICACIÓ:
        Simetria amb el cas anterior.
        */
        while(j>=i && v[j]>pivot) j--;

        /*
        EXPLICACIÓ:
        Si no s'han creuat, significa que tots dos s'han aturat a un nombre que no correspón
        a estar davant/darrere del pivot, així que els intercanviem.
        Si s'haguessin creuat (j<i) significa que no han trobat cap nombre mal posicionat previament,
        i el primer que s'han trobat ja correspón a un més gran/petit que el pivot.

        Movem i,j posteriorment per a evitar canvis redundants a la pròxima iteració del bucle.
        */
        if (i < j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    // 3. Finalment hem d'intercanviar el pivot (Núm. que hem prés de refèrencia per determinar swaps)
    // amb el número on apunta "j". Això és així perquè "j" ha parat al primer nombre (començant per high)
    // tal que v[j]<=pivot. Això implica que al fer intercanvi, continuarà respectant-se "l'ordre".
    // En canvi, no ho podriem fer amb v[i] perquè aquest apunta a un v[i]>pivot (Per exemple 9) i si intercanviem,
    // a la pos. low hi haurià un element més gran que v[low+1],...
    swap(v[low], v[j]);

    // 4. Retornem la posició on ha acabat el pivot (j)
    return j;
}

void quickSort(vector<int>& v, int low, int high) {
    // === BASE CASE ===
    /*
    CASE1: "low == high" sig. que no farem cap swap() així que no fa falta processar res.
    CASE2: "low>high" son incorrectes així que no podem continuar pq. petaria.
    */ 
    if (low>=high) return;

    // === GENERAL CASE ===
    // 1. Seleccionem quin serà el nostre pivot
    int pivot = v[low];  // Quin seleccionem no importa en absolut.
    // NOTA: Per millorar la selecció del pivot hi ha un pseudo-avg, però no ho té importancia ara.

    // 2. Volem ""Ordenar"" (A groso modo) i saber en quina posició ha acabat el pivot.
    // Això ens permetrà delimitar per on fem la recursivitat. # Pivot sempre acaba en la pos. correcta.
    int indexPivot = partition(v,low,high,pivot);

    // 3. Quan ja sabem on esta el pivot ubicat. Fem les crides recursives per "Ordenar".
    // Amb "la màgia" de la recusivtat, els elements previs/posteriors al pivot acabaràn ordenats entre ells.
    quickSort(v, low, indexPivot-1);
    quickSort(v, indexPivot+1, high);
}   