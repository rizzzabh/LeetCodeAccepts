class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c1 = 0 , c2 = 0 ; 

        for (auto num : nums){
            if (c1 == num){
                c2++;
            }else {
                if (c2 == 0){
                    c1 = num;
                    c2 = 1 ;
                }else{
                    c2--;
                }
            }
        }
        return c1;
    }
};