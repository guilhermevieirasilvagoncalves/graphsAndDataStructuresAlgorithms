#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Mochila (vector<int> & v,vector<int> &p, int w,int n) {
    if(n == 0) return 0;
    for (int i = 0; i < n - 1; i++) {
        if (p[n - 1 - i]  > w) return Mochila(v, p, w, n - 1);
        else return max(Mochila(v,p,w - p[n - 1 - i], n - 1) + v[n - 1 - i], Mochila(v,p,w,n - 1));
    }
}

int main() {
    vector<int> v = {10, 7, 25, 24};
    vector<int> p = {2, 1, 6, 5};
    int w = 7;
    int n = 4;
    cout << Mochila(v,p,w,n) << endl;

}
