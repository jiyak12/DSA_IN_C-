// Sum of Beauty of All Substrings
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters. For example, the beauty of "abaacc" is 3 - 1 = 2.
class Solution {
public:
    int beauty(vector<int>&alpha){
        int mf =-1;
        int lf = le9;
        for(int i=0; i<26; i+=){
            mf=max(mf,alpha[i]);
            if(alpha[i]>=1){
                lf=min(lf, alpha[i]);
            } 
        }
        return mf -lf;
    }
    int beautySum(string s) {
        int res =0;
        //substring
        for(int i=0; i< s.size();i++){
            vector<int>alpha(26,0);
            for(int j=i;j<s.size();j++){
                alpha[s[j]-'a']++;
                res=res+beauty(alpha);
            }
        }
        
    }
};
