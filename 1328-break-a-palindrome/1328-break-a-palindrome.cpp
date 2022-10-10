class Solution {
public:
    string breakPalindrome(string p) {
        if(p.length()==1){
            return "";
    }

    int m = p.length()/2;
    
    for(int i = 0;i < p.length();i++){
        if(p[i] != 'a' && i != m){
            p[i] = 'a';
            return p;
        }
    }
    p[p.length()-1] = 'b';
    return p;
    }
};