class Solution {
public:
    string minWindow(string s, string t) {
       int n=t.size();
        map<char,int> mp;
        for(auto a:t){
            mp[a]++;
        }
        int l=0,ma=1000000,ms=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){
                n--;
            }
            mp[s[i]]--;
            if(n==0){
                cout<<l<<" "<<i<<"\n";
                while(l<i && mp[s[l]]<0){
                    mp[s[l]]++;
                    l++;
                }
                if(ma>(i-l)){
                    ma=i-l+1;
                    ms=l;
                }
                mp[s[l++]]++;
                n++;
            }
        }
        return ma==1000000 ? "" : s.substr(ms,ma); 
    }
};