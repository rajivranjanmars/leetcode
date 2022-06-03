class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int>v;
        for(int i=0;i<rocks.size();i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        int m=0;
       for(int i=0;i<v.size();i++){
         if(v[i]>0&&a>=v[i]){
             a=a-v[i];
            v[i]=0;
         }  
           if(v[i]==0)
               m++;   
       }
       
        return m;
    }
};