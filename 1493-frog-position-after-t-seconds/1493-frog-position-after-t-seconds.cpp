class Solution {
public:
    void dfs(int node , int parent , vector<vector<int>> & adj , int timer , double currentProbability , int t , vector<pair<double,int>> & probability) {

        probability[node] = {currentProbability , timer}; 

        int numberOfChildren = adj[node].size() - (node != 1); 
        for (auto child : adj[node]) {
            if (child == parent) continue ; 

            dfs (child , node , adj ,  timer + 1 , currentProbability*(1.0/numberOfChildren) , t , probability ) ; 
        }

    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1)return 1 ; 
        vector<pair<double,int>>probability (n + 1 , {-1 , 0}) ;
        vector<vector<int>> adj(n + 1) ; 
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]) ; 
            adj[edge[1]].push_back(edge[0]) ; 
        }
        dfs (1 , -1 , adj ,  0 , 1 ,  t, probability) ; 
        if (probability[target].second == t ) return probability[target].first ; 
        if (adj[target].size()==1 && target!=1 && t>=probability[target].second) return probability[target].first ;
        return 0.0 ; 
    }
};