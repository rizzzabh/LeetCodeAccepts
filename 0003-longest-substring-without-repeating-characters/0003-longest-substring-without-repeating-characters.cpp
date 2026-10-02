class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>freq;

        int n = s.size() , l = 0 , i = 0 ; 
        int ans = 0 ;
        for (; i < n ; i++ ){
            freq[s[i]]++ ; 

            if (freq[s[i]] == 1){
                ans = max(ans , i - l + 1);
            }else {
                while (freq[s[i]] > 1){
                    freq[s[l]]--;
                    l++;
                }
            }
        }

        return ans;
    }
};