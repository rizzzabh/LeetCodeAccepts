class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq; 
        pair<int,int> dir[4] = {{-1 , 0},{0 , -1},{1 , 0},{0 , 1}};
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<bool>>vis(n , vector<bool>(m , 0));
        vis[0][0] = true ; 

        auto isValid = [&] (int x , int y)->bool {
            return ((x>=0)&&(x<n)&&(y>=0)&&(y<m)&&(!vis[x][y]));
        };

        pq.push({grid[0][0] , 0 , 0}); 
        while (!pq.empty()) {
            auto [timer , x , y] = pq.top() ; 
            pq.pop() ; 
            if ((x == n - 1) && (y == m - 1))return timer ; 

            for (auto [dx , dy] : dir) {
                int newX = x + dx ; 
                int newY = y + dy ; 
                if (isValid(newX , newY)) {
                        if(grid[newX][newY] > timer) {
                            pq.push({grid[newX][newY] , newX , newY}) ;
                        }else{
                            pq.push({timer , newX , newY}) ;
                        }
                        vis[newX][newY] = true ;
                }
            }
        }

        return -1 ; 
    }
};