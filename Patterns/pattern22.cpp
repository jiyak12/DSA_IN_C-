/*
555555555
544444445
543333345
543222345
543212345
543222345
543333345
544444445
555555555
*/
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n) { 
  for (int i = 0; i <2*n-1; i++) {
    for( int j =0;j <2*n-1;j++){
      int top = i;
      int left = j;
      int right =(2*n-2) - j;
      int down =(2*n -2) - i;
      cout << (n - min(min(top,down), min(left,right)));
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
