class Solution {
public:
    int ans = -1 ; 
    int dfs (int node , int parent , vector<vector<int>> & adj , string & s ) {
    
        int firstMax , secondMax ; 
        firstMax = secondMax = 0 ; 

        for (auto & child : adj[node]) {
            if (child == parent) continue ; 

            if (s[child] != s[node]){
                secondMax = max(secondMax , dfs(child , node , adj , s)) ; 
            }else {
                dfs (child , node , adj , s) ;
            }

            if (secondMax >= firstMax) swap(firstMax , secondMax) ; 
        }
        ans = max(ans , firstMax + secondMax + 1 ) ; 

        return firstMax + 1 ; 
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size() ; 
        vector<vector<int>> adj (n) ; 
        for (int i = 1 ; i < n ; i++ ) adj[parent[i]].push_back(i) ; 

        dfs (0 , -1 , adj , s) ; 
        return ans ; 
    }
};