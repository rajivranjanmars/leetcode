class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
          int res=1;
        sort(p.begin(),p.end());
        int mini=p[0][1];
        for(int i=1;i<p.size();i++)
        {
            int start=p[i][0];
            int end=p[i][1];
            
            //use the same arrow
            if(start<=mini)
            {
                mini=min(mini,end);
            }
            else{
                //need a new arrow
                res++;
                mini=end;
            }
        }
        return res;
    }
};