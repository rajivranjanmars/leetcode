class Solution {
public:
     static bool compare(pair<int,int>&a , pair<int,int>&b)
    {
        return a.second>b.second;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        for(int i=0;i<plantTime.size();i++)
        {
            v.push_back({plantTime[i],growTime[i]});
        }
        sort(v.begin(),v.end(),compare);
        int ans=v[0].first+v[0].second;
        int prev = v[0].first;
        for(int i=1;i<v.size();i++)
        {
            ans=max(ans,prev+v[i].second+v[i].first);
            prev+=v[i].first;
        }
        return ans;
    }
};