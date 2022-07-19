class Solution {
public:
    int minPartitions(string n) {
      int max=  *max_element(n.begin(),n.end());
        return max-48;
    }
};