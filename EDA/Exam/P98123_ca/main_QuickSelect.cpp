#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef vector<int64_t> VI;

void eliminar_element(VI& bossa, const int& usr_valor) {
    for (int i = 0; i<bossa.size(); i++) {
        if (bossa[i] == usr_valor) {
            bossa.erase(bossa.begin()+i);
            return;
        }
    }
}

int64_t make_sum(VI& bossa, const int& inici) {
    int64_t counter = 0;
    for (int i = inici; i<bossa.size(); i++) counter += bossa[i];
    return counter;
}

int find_pivot(VI& bossa, int l, int r) {
    int i = l, j = r;
    int key = bossa[l];

    while (i<=j) {
        while (i<=r && bossa[i]<=key) i++;
        while (j>=l && bossa[j]>key) j--;
        if (i<=j) swap(bossa[i], bossa[j]);
    }
    swap(bossa[l], bossa[j]);
    return j;
}

void quicksort(VI& bossa, int l, int r, const int& k, const int& n) {
    int pivot = find_pivot(bossa, l, r);

    if (pivot == n-k) return;
    else if (pivot < n-k) quicksort(bossa, pivot+1, r, k, n);
    else quicksort(bossa, l, pivot-1, k, n); 
}

int64_t get_sum(VI& bossa, int const k) {
    int n = bossa.size();
    int ideal_pivot = n-k;
    if (ideal_pivot<=0) return make_sum(bossa, 0);

    quicksort(bossa, 0, n-1, k, n);
    return make_sum(bossa, ideal_pivot);
}

int main(void) {
    int num_elements;
    cin >> num_elements;

    string usr_op; 
    int usr_valor;
    VI bossa;
    bool reordenar;

    while (cin >> usr_op >> usr_valor) {
        reordenar = true;
        if (usr_op == "deixar") bossa.emplace_back(usr_valor);
        else if (usr_op == "endur") eliminar_element(bossa, usr_valor);

        cout << get_sum(bossa, num_elements) << endl;
    }
}