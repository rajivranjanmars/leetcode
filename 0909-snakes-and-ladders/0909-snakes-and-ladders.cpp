class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = size(board);
        vector<vector<int>> visited(n,vector<int> (n,0));
        queue<int> q;

        q.push(1); 
        visited[n-1][0] = 1;

        int steps = 0;

        while(q.size()){
           
           int size = q.size();
           for(int i=0 ; i<size ; i++){
              
              int pos = q.front();
              q.pop();
             
              if(pos == n*n) return steps;
              
             
              for(int k=1; k<=6 ;k++){
               
                if(k+pos > n*n) break;

                pair<int,int> cordi = cordinate(k+pos , n);
                
                int row = cordi.first;
                int col = cordi.second;
                
               
                if(visited[row][col]) continue; 

                visited[row][col] = 1;

                if(board[row][col]==-1)
                  q.push(k+pos);
                else
                  q.push(board[row][col]);  
              }  

           }
           steps++;
        }
        return -1;
    }
    pair<int,int> cordinate(int block,int n){
      
      int row = n - (block-1)/n -1;
      int col = (block-1) % n;
    
      if(row%2 == n%2) 
         col = n-1-col;

      return {row,col};   
    }
};