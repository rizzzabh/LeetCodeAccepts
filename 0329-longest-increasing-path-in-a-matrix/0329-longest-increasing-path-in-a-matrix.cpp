class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 
        vector<vector<int>> indeg(n , vector<int> (m , 0)) ; 
        pair<int,int> dir [4] = {{-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0}} ; 
        auto isValid = [&] (int x , int y) ->bool{
            return ((x >= 0) && (x < n) && (y >= 0) && (y < m)) ; 
        };
        for (int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < m ; j++ ) {
                int currValue = matrix[i][j] ; 
                for (auto [di , dj] : dir) {
                    int newI = i + di ; 
                    int newJ = j + dj ; 
                    if (isValid(newI , newJ) && matrix[newI][newJ]<matrix[i][j]){
                        indeg[i][j]++ ; 
                    }
                }
            }
        }
        queue<pair<int,int>> q; 
        for (int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < m ; j++ ) {
                if (indeg[i][j]==0)q.push({i , j}) ; 
            }
        }
        vector<pair<int,int>> topoOrder ; 
        while (!q.empty()){
            auto [x , y] = q.front() ; 
            q.pop() ; 
        
            topoOrder.push_back({x , y}) ; 

            for (auto [dx , dy ] : dir){
                int newX = x + dx ; 
                int newY = y + dy ; 

                if (isValid(newX , newY) && matrix[newX][newY]>matrix[x][y]){
                    indeg[newX][newY]-- ; 
                    if (indeg[newX][newY]==0){
                        q.push({newX , newY}) ; 
                    }
                }
            }
        }
        int size = topoOrder.size() ; 
        vector<vector<int>> maxLength(n , vector<int>(m , 1)) ; 
        for (int i = 0 ; i < size ; i++ ) {
            auto [x , y] = topoOrder[i] ; 
            for (auto [dx , dy] : dir ) {
                int newX = x + dx ; 
                int newY = y + dy ; 
                if (isValid(newX , newY) && matrix[newX][newY]>matrix[x][y]){
                    maxLength[newX][newY] = max(maxLength[newX][newY] , maxLength[x][y] + 1);
                }
            }
        }

        int maxLen = 0 ; 
        for (int i = 0 ; i < n ; i++ ){
            for (int j = 0 ; j < m ; j++ )maxLen = max(maxLen , maxLength[i][j]) ; 
        }

        return maxLen ; 
    }
};