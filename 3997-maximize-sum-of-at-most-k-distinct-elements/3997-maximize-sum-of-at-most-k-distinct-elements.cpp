class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end()) ; 
        vector<int> ans; 
        int cnt = 0 ; 
        while (s.size() and cnt < k) {
            int one = *s.rbegin() ; 
            if (one > 0)ans.push_back(one) ; 
            s.erase(one) ; 
            cnt++ ; 
        }
        
        return ans ; 
    }
};