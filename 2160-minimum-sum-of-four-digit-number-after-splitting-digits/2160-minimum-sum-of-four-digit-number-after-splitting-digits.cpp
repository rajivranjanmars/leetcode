class Solution {
public:
    int minimumSum(int num) {
       vector<int>v;
        v.push_back(num/1000);
       num=num-v[0]*1000;
        v.push_back(num/100);
        num=num-v[1]*100;
        v.push_back(num/10);
        num=num-v[2]*10;
        v.push_back(num);
     sort(v.begin(),v.end());
        return(v[0]*10+v[1]*10+v[2]+v[3]);
    }
};