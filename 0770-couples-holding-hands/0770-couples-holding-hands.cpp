class Solution {
public:
    void dfs (int node , map<int,vector<int>> & adj , map<int,int> & vis) {
        vis[node] = 1 ; 
        for (auto & child : adj[node]) {
            if (vis.find(child) == vis.end()) dfs(child , adj , vis) ; 
        }
    }
    int minSwapsCouples(vector<int>& a) {
        int n = a.size() ; 

        int group = n + 1; 
        map<int,int>mp ; 

        for (int i = 0 ; i < n ; i += 2 , group++ ) {
            mp[i] = mp[i + 1] = group ; 
        }

        map <int,vector<int>> adj; 
        for (int i = 0 ; i < n ; i++ ) {
            if (a[i]%2==0){
                for (int j = 0 ; j < n ; j++ ) {
                    if (a[j] == a[i] + 1) {
                        adj[mp[j]].push_back(mp[i]) ; 
                        adj[mp[i]].push_back(mp[j]) ; 
                    }
                }
            }
        }
        int numberOfCycles = 0 ; 
        map<int,int>vis ; 
        for (int node = group - 1 ; node >= n + 1 ; node-- ) {
            if (vis.find(node) == vis.end()) {
                numberOfCycles++ ; 
                dfs (node , adj , vis) ; 
            }
        }
        return (n/2 - numberOfCycles) ;
    }
};