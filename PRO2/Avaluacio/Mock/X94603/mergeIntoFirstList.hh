#include <list>

using namespace std;

// Pre: l1 i l2 estan ordenades creixentment. Siguin L1 i L2 els seus valors inicials.
// Post: l1 conté la fusió ordenada de L1 i L2.
//       A més a més, els elements inicials de la llista han persistit i
//       no han canviat de valor.
void mergeIntoFirstList(list<int> &l1, list<int> l2);
