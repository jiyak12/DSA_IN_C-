//Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size nxn filled with '*'. For every value of 'n', help him to print the corresponding n-dimensional forest.


#include <bits/stdc++.h>
using namespace std;

void printPattern(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int n;
        cin >> n;
        printPattern(n);
    return 0;
}
