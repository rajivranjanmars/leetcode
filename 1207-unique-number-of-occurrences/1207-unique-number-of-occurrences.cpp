class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        set<int>s;
        for(int i=0;i<arr.size();i++)  ++m[arr[i]];
        for(auto i:m)s.insert(i.second);  
        return m.size()==s.size();
    }
};