/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
   Node *makeTree(vector<vector<int>>& grid, int posI, int posJ, int n){
        Node *newNode = new Node();
        bool startCellVal = grid[posI][posJ];
        for(int i = posI; i < posI+n; i++){
            for(int j = posJ; j < posJ+n; j++){
                if(grid[i][j] != startCellVal){
                    newNode->val = startCellVal;
                    newNode->isLeaf = false;
                    newNode->topLeft = makeTree(grid, posI, posJ, n/2);
                    newNode->topRight = makeTree(grid, posI, posJ+n/2, n/2);
                    newNode->bottomLeft = makeTree(grid, posI+n/2, posJ, n/2);
                    newNode->bottomRight = makeTree(grid, posI+n/2, posJ+n/2, n/2);
                    return newNode;
                }
            }
        }
        newNode->val = startCellVal;
        newNode->isLeaf = true;
        return newNode;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return makeTree(grid, 0, 0, n);
        // n  is the size of square.
    }
};