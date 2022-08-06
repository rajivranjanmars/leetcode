class Solution {
public:
    int poorPigs(int buckets, int d, int t) {
         int T = (t/d) + 1;
        int cnt = 0;
        int total = 1;
        while (total < buckets) {
            total *= T;
            cnt++;
        }
        return cnt;
    }
};