class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         if(matrix.empty()) return 0;
        int N = matrix.size();
        int left = matrix[0][0];
        int right = matrix[N-1][N-1];
        while(left < right) {
            int mid = left + (right - left)/2;
            int count = 0;
            for(int i=0; i<N; i++) {
                count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            if(count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};