class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indeg(numCourses , 0) ; 
        vector<vector<int>> adj(numCourses) ; 
        for (auto X : prerequisites){
            int a = X[0] , b = X[1] ; 
            adj[b].push_back(a); 
            indeg[a]++ ; 
        }
        queue<int> q ; 
        for (int i = 0 ; i < numCourses ; i++ ){
            if (indeg[i] == 0)q.push(i) ; 
        }
        vector<int> ans ; 
        while (!q.empty()) {
            int currNode = q.front() ; 
            ans.push_back(currNode) ; 
            q.pop() ; 
            for (auto child : adj[currNode]){
                indeg[child]-- ; 
                if (indeg[child] == 0) q.push(child) ; 
            }
        }
        if (ans.size() == numCourses)return ans ; 

        return {} ;
    }
};