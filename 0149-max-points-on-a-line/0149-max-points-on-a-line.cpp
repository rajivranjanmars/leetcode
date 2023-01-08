class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         int n=points.size();
        if(n==1) return 1;
        int ans=0;
        for(int x=0; x<n-1; x++)
        {
            for(int y=x+1; y<n; y++)
            {
                int count=2;
                for(int z=0; z<n; z++)
                {
                    if(z!=x && z!=y)
                    {
                        double m1=(double)(points[x][0]-points[y][0])/(double)(points[x][1]-points[y][1]);
                        double m2=(double)(points[x][0]-points[z][0])/(double)(points[x][1]-points[z][1]);
                        if(m1==m2) count++;
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};