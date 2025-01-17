#include <iostream>
#include <vector>
using namespace std;

bool binSearchRight(int x, const vector<int>& v, int low) {
  int high = v.size()-1;

  while (low<=high) {
    int mid = low + (high-low)/2;
    if (v[mid] == x) return true;
    else if (x<v[mid]) low = mid+1;
    else high = mid-1;
  }

  return false;
}

bool binSearchLeft(int x, const vector<int>& v, int high) {
  int low = 0;

  while (low<=high) {
    int mid = low + (high-low)/2;
    if (v[mid] == x) return true;
    else if (v[mid]>x) high = mid-1;
    else low = mid+1; 
  }

  return false;
}

int findPic(int x, const vector<int>& v, bool& found) {
  int low = 0, high, n;
  high = n = v.size()-1;

  while (low<high) {
    int mid = low + (high-low)/2;
    // Per si acàs me'l trobo buscant el pic
    if (v[mid] == x) {
      found = true;
      return -2;  // irrellevant
    }
    
    if (mid+1<=n && mid-1>=0) {
      if (v[mid-1]==x || v[mid+1]==x) {
        found = true;
        return -2;  // irrellevant
      }
      else if (v[mid-1]<v[mid] && v[mid]>v[mid+1]) return mid;
    }
    if (mid-1>=0 && v[mid-1]<v[mid]) low = mid+1;
    else if (mid-1>=0 && v[mid-1]>v[mid]) high = mid-1;
    else if (mid+1<=n && v[mid]<v[mid+1]) low = mid+1;
    else if (mid+1<=n && v[mid]>v[mid+1]) high = mid-1;
  }

  return low;
} 

bool search(int x, const vector<int>& v) {
  bool found = false;
  int pos_pic = findPic(x,v,found);
  if (found) return found;
  else if (pos_pic == 0) return binSearchRight(x,v,0);
  else if (pos_pic == v.size()-1) return binSearchLeft(x,v,v.size()-1);
  
  found = binSearchLeft(x,v,pos_pic-1);
  if (found) return found;
  
  found  = binSearchRight(x,v,pos_pic+1);
  return found;
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}
