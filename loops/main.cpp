//
// Created by prenc on 28.06.17.
//


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int x, n, m;
    vector<int> a, b, c;

    cin >> m;
    //cin>>n;

    for (int i = 0; i < m; i++) {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        for (int j = (i + 1); j < m; j++) {
            for (int k = (j + 1); k < m; k++) {
                cout << a[i] << a[j] << a[k] << endl;
            }
        }
    }
}
