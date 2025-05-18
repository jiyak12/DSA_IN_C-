/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n) {
  int iniS = 0;
  for (int i = 0; i < n; i++) {
    //stars
    for( int j =1;j<=n-i;j++){
      cout << "*";
    }
    // spaces
    for(int j =0;j<iniS;j++){
      cout << " ";
    }
    // stars
    for (int j =1;j<=n-i;j++) {
        cout << "*";
      }
      iniS += 2;
      cout << endl;
    }
    iniS = 8;
    for (int i = 1; i <= n; i++) {
    //stars
    for( int j =1;j<=i;j++){
      cout << "*";
    }
    // spaces
    for(int j =0;j<iniS;j++){
      cout << " ";
    }
    // stars
    for (int j =1;j<=i;j++) {
        cout << "*";
      }
      iniS -= 2;
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
