class Solution {
public:
    string interpret(string c) {
        string result="";
        for(int i=0;i<c.size();){
            if(c[i]=='G'){
                result+='G';
                i++;
            }
            if(c[i]=='(' &&c[i+1]==')'){
                result+='o';
                i+=2;
            }
             if(c[i]=='(' &&c[i+1]=='a'){
                result+="al";
                i+=4;
            }
            
        }
        return result;
    }
};