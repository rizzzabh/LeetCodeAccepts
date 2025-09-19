class Solution {
public:
    struct DSU{
        vector<int>rank , parent ; 
        DSU (int size) {
            rank.resize(size + 1 , 0) ; 
            parent.resize(size + 1 , 0) ; 
            for (int i = 1 ; i <= size ; i++ ){
                rank[i] = 1 ; 
                parent[i] = i ; 
            }
        }

        int findParent (int node) {
            if (parent[node] != node) {
                parent[node] = findParent(parent[node]) ; 
            }
            return parent[node] ;
        }

        bool unite (int node1 , int node2) {
            int parent1 = findParent(node1) ; 
            int parent2 = findParent(node2) ; 

            if (parent1 == parent2) return false ;

            int rank1 = rank[parent1] ; 
            int rank2 = rank[parent2] ; 

            if (rank1 > rank2) {
                parent[parent2] = parent1 ; 
            }else if (rank1 < rank2) {
                parent[parent1] = parent2 ; 
            }else {
                rank[parent1]++ ; 
                parent[parent2] = parent1 ; 
            }
            return true ; 
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size() ; 
        DSU dsu(size) ;
        for (int i = 0 ; i < size ; i++ ){
            for (int j = 0 ; j < size ; j++ ) {
                if (isConnected[i][j] == 1) {
                    dsu.unite(i + 1 , j + 1) ; 
                }
            }
        }
        int provinces = 0 ; 
        for (int i = 1 ; i <= size ; i++ ) {
            if (dsu.findParent(i) == i)provinces++ ; 
        }

        return provinces ; 
    }   
};