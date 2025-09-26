class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0 , j = 0 ; 
        int n = start.size() ; 
        while (true) {
            if (i < n && start[i]=='X'){
                i++ ; 
                continue ; 
            }
            if (j < n && result[j] == 'X'){
                j++ ; 
                continue ; 
            }
            if (i < n && j < n && start[i]=='L' && result[j]=='L' && i >= j){
                i++ ; 
                j++ ; 
                continue ; 
            }
            if (i < n && j < n && start[i]=='R' && result[j]=='R' && j >= i){
                i++ ; 
                j++ ; 
                continue ; 
            }

            break ; 
        }
        return ((i == n) && (j == n)) ; 
    }
};