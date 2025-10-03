class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n) ; 
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back({edge[1] , edge[2]}) ;
            adj[edge[1]].push_back({edge[0] , edge[2]}) ; 
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq ; 
        vector<int> minDist(n , INT_MAX) ; 

        minDist[0] = 0 ;
        pq.push({0 , 0}) ; 
        while (!pq.empty()) {
            auto [dist , node] = pq.top() ; pq.pop() ; 

            if (minDist[node] < dist)continue ; 

            for (auto & [childNode , childDist] : adj[node]) {
                if (dist + childDist + 1 < minDist[childNode]) {
                    minDist[childNode] = dist + childDist + 1; 
                    pq.push({minDist[childNode] , childNode}) ; 
                }
            }
        }
        int reachableNodes = 0 ; 
        for (vector<int> & edge : edges) {
            int dist1 = minDist[edge[0]] ; 
            int dist2 = minDist[edge[1]] ; 
            int maxAllowed = edge[2] ; 
            int nodesAddedByFirst = max(0 , maxMoves - dist1) ; 
            int nodesAddedBySecond = max(0 , maxMoves - dist2) ; 
            reachableNodes += min(nodesAddedByFirst + nodesAddedBySecond , maxAllowed) ; 
        }
        for (int dist : minDist){
            if (dist <= maxMoves)reachableNodes++ ; 
        }
        return reachableNodes ; 
    }
};