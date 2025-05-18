/*
1
01
101
0101
*/
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
      int start = i;
      if(i % 2 ==0) start=1;
      else start = 0;
      for (int j = 0;j<=i;j++) {
        cout << start;
        start = 1-start;
      }
      cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        printPattern(n);
    }
    return 0;
}
