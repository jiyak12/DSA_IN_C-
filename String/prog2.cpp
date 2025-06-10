//reverse words in a string
#include<bits/stdc++.h>
using namespace std;
string result(string s)
{
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
  /* 
  // Trim leading spaces
    while (left <= right && s[left] == ' ') left++;
    // Trim trailing spaces
    while (right >= left && s[right] == ' ') right--;
    */
  
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
          //if (!temp.empty()) {  // Only add if temp has a word
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
      /*
      // skip multiple spaces by moving left until next non-space
      while (left + 1 <= right && s[left + 1] == ' ') left++;
    }
  */
        left++;
    
  
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    
}
int main()
{
    string st="DSA preparation is difficult";
    cout<<"Before reversing words: "<<endl;
    cout<<st<<endl;
    cout<<"After reversing words: "<<endl;
    cout<<result(st);
    return 0;
}
