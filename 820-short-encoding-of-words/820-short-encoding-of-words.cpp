class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
         set<string> s1(words.begin(),words.end());
    set<string> s2(words.begin(),words.end());
    for(auto temp:s1)
        for(int i=1;i<temp.size();i++)
            s2.erase(temp.substr(i));
    int sum=0;
    for(auto i:s2)
        sum+=i.size()+1;
    return sum;
    }
};