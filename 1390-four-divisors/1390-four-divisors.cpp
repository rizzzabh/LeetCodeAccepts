class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0 ; 

        for (int & num : nums) {
            int sum2 = 0 , cnt = 0 ; 
            for (int i = 1 ; i*i <= num ; i++ ) {
                if (num%i == 0 ) {
                    cnt++ ; 
                    sum2 += i ; 

                    if (i != num / i) {
                        sum2 += num/i ; 
                        cnt++ ; 
                    }
                }
                if (cnt > 4) {
                    break ; 
                }
            }

            if (cnt == 4){
             sum += sum2 ; 
            }
        }

        return sum ; 
    }
};