class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0 ; 
        string curr = "" ; 
        int n = text.size() ; 
        for (int i = 0 ; i < n ; i++ ) {
            if (text[i] == ' ') {
                bool ok = true ; 
                for(auto j : curr) {
                    for (auto p : brokenLetters){
                        if (j == p){
                            ok = false ; 
                            break ; 
                        }
                    }
                }
                if (ok)cnt++ ; 
                curr.clear();  
            }else {
                curr.push_back(text[i]) ; 
            }
        }
        bool ok = true ; 
        for (auto j : curr){
            for (auto p : brokenLetters){
                if (j == p){
                    ok = false ; 
                    break ;
                }
            }
        }
        if (ok)cnt++ ; 

        return cnt ; 
    }
};