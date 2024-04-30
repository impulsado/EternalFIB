#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
	int max = v[0];
	int min = v[0];
	int n = v.size();
	for (int i = 1; i < n; ++i) {
		if (max < v[i]) max = v[i];
		if (min > v[i]) min = v[i];
	}
	parint p;
	p.prim = max;
	p.seg = min;
	return p;
}
 
pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
	int max = v[0];
	int min = v[0];
	int n = v.size();
	for (int i = 1; i < n; ++i) {
		if (max < v[i]) max = v[i];
		if (min > v[i]) min = v[i];
	}
	pair<int, int> p;
	p.first = max;
	p.second = min;
	return p;
}
 
void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
	x = v[0];
	y = v[0];
	int n = v.size();
	for (int i = 1; i < n; ++i) {
		if (x < v[i]) x = v[i];
		if (y > v[i]) y = v[i];
	}
}