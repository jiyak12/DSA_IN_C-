//in this program, the no of times a character appears in the arrray is counted (only lower case letters are present in the array)
//NOTE- if any character is taken in a string with int variable it returns the ASCII value of the character not the character itself. 
//i.e. int function ='a' this returns 97(ASCII value of lowercase a)
//for taking a string of characters of alphabet and using hashmap  hash[s[i] - 'a']++

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	
	// precompute 
	int hash[26] ={0};
	for(int i =0; i<s.size(); i++){
	    hash[s[i] - 'a']++;
	    
	}
	int q;
	cin>> q;
	while(q--) {
	    char c;
	    cin>> c;
	    // fetch
	    cout << hash[c-'a']<< endl;
	}
	return 0;
}
