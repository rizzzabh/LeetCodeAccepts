class Solution {
public:
    vector<string> allC = {"000","123","132","121","131","213","231","212","232","321","312","323","313"} ; 
    const int MOD = 1000000007 ; 
    int dp[5001][15] ; 
    bool notMatch(int prevWay , int currWay) {
        bool good = true ; 
        for (int i = 0 ; i < 3 ; i++ ) {
            if (allC[prevWay][i] == allC[currWay][i]){
                good = false ; 
            }
        }
        return good ; 
    }
    long long f(int num , int prevWay) {
        if (num == 0)return 1LL ; 
        if(dp[num][prevWay] != -1)return dp[num][prevWay] ; 

        long long ways = 0 ; 
        for (int i = 1 ; i <= 12 ; i++ ) {
            if (notMatch(prevWay , i)){
                ways  = (ways + f(num - 1 , i)) % MOD ; 
            }
        }
        return dp[num][prevWay] = ways ; 
    }
    int numOfWays(int n) {
         memset(dp ,-1 , sizeof(dp) ) ; 
        long long ways = f(n , 0) ; 
        return (int)ways ; 
    }
};