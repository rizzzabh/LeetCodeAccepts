class Solution {
public:
    bool doesAliceWin(string s) {
        for (auto & ch : s) {
            if ((ch == 'a') or (ch == 'e') or (ch == 
            'i') or (ch == 'o') or (ch == 'u')){
                return true ; 
            }
        }
        return false ;
    }
};