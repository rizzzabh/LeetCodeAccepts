class Solution {
public:
    void fillSubtree(int node , int parent , vector<vector<int>> & adj , vector<int> & subtree) {
        subtree[node] = 1 ; 
        for (auto & child : adj[node]) {
            if (child == parent) continue ; 
            fillSubtree(child , node , adj , subtree) ; 
            subtree[node] += subtree[child] ; 
        }
    }
    void fillDp (int node , int parent , vector<vector<int>> & adj , vector<int> & subtree , vector<int> & dp) {
        
        for (auto & child : adj[node]) {
            if (child == parent)continue ; 
            fillDp(child , node , adj , subtree , dp) ;
            dp[node] += dp[child] + subtree[child]; 
        }
    }
    void fillAns (int node , int parent , vector<vector<int>> & adj , vector<int> & subtree , vector<int> & dp , vector<int> & ans , int n) {
        
        for (auto child  : adj[node]){
            if (child == parent) continue ; 
            ans[child] = ans[node] - 2*subtree[child] + n; 
            fillAns (child , node , adj , subtree , dp , ans , n ) ; 
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ; 
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]) ;
            adj[edge[1]].push_back(edge[0]) ; 
        }
        vector<int> subtree(n, 0) , dp(n , 0) , ans(n , 0); 
        fillSubtree(0 , -1 , adj , subtree) ; 
        fillDp(0 , -1 ,  adj , subtree , dp) ; 
        ans[0] = dp[0] ;
        fillAns(0 , -1 , adj , subtree , dp , ans , n) ; 
        return ans ; 
     }
};