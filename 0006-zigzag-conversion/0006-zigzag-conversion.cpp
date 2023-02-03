class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> v(min(numRows, int(s.size())), "");
        // direction -1 is down, 1 is up
        int direction = -1, idx = 0;
        
        for (int i = 0; i < s.size(); i++) {
            v[idx] += s[i];
            idx += direction == -1 ? 1 : -1;
            if (idx == 0 || idx == numRows - 1) direction = -direction;
        }
        
        string res = "";
        for (auto a : v) res += a;
        
        return res;
    }
};