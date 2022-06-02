class Solution {
public:

    
    int maximumUnits(vector<vector<int>>& b, int t) {
        vector<pair<int,int>>v;
        for(int i=0;i<b.size();i++){
            v.push_back({b[i][1],b[i][0]});
        }
        sort(v.begin(),v.end());
        int o=0;
        for(int i=v.size()-1;i>=0;i--){
            if(t>v[i].second){
              o+=v[i].first*v[i].second;
                t-=v[i].second;
            }
            else{
              o+=v[i].first*t;
                t=0;
            }
        }
        return o;
    }
};