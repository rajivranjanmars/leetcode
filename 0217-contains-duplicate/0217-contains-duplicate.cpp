class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        set<int>s;
        for(int i=0;i<v.size();i++)
            s.insert(v[i]);
        if(s.size()==v.size())
            return false;
        return true;
    }
};