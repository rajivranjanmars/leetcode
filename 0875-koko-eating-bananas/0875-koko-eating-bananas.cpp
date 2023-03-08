class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         long long int mx = INT_MIN,mn = 1,mid,hr,n = piles.size(),i;
        if(n==1){
            if(piles[0]%h){
                return piles[0]/h+1;
            }
            return piles[0]/h;
        }
        for(auto &i: piles){
            mx = max((long long int)i,mx);
        }
        while(mn<mx){
            mid = (mx-mn)/2+mn;
            // cout<<mn<<" "<<mx<<" "<<mid<<" ";
            hr = 0;
            for(auto &i: piles){
                // cout<<float(i)/float(mid)<<" ";
                if(i<=mid){
                    hr++;
                }else if(i%mid){
                    hr += 1 + i/mid;
                }else{
                    hr += i/mid;
                }
            }
            // cout<<hr<<endl;
            if(hr<=h){
                mx = mid;
            }else{
                mn = mid+1;
            }
        }
        return mx;
    }
};