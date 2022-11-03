class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         int ans = 0;
        unordered_map<string,int> mp;
        for(auto word : words)
        {
            string rev = word;
            reverse(rev.begin(),rev.end());
            if(mp[rev] > 0)
            {
                ans+=4;
                mp[rev]--;
            }
            else 
            {
                mp[word]++;
            }
        }
        for(auto x : mp)
        {
            if(x.first[0] == x.first[1] && x.second > 0)
            {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};