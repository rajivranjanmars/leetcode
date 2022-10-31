class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int k = 0; k < m; k++){
            int i = 0;
            int j = k;
            int store = matrix[i][k];
            while( i < n and j < m){
                if(store != matrix[i++][j++]) return false;
            }
        }
        for(int k = 1; k < n; k++){
            int i = k;
            int j = 0;
            int store = matrix[i][0];
            while( i < n and j < m){
                if(store != matrix[i++][j++]) return false;
            }
        }
        return true; 
    }
};