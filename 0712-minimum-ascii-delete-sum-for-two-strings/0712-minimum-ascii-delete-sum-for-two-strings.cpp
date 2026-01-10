class Solution {
public:
    const int INF = 1e9 ; 
    int N , M ; 
    int f (string & s1 , string & s2 , vector<vector<int>> & dp , int i , int j) {
        if (i == N) {   
            return accumulate(s2.begin() + j , s2.end() , 0LL) ; 
        }
        if (j == M) {
            return accumulate(s1.begin() + i , s1.end() , 0LL) ; 
        }

        if (dp[i][j] != INF) {
            return dp[i][j] ; 
        }


        if (s1[i] == s2[j]) {
           dp[i][j] =  f (s1 , s2 , dp , i + 1 , j + 1) ; 
        }else {
            dp[i][j] = min(f(s1 , s2 , dp , i + 1 , j) + (int)s1[i] , f(s1 , s2 , dp , i , j + 1) + (int)s2[j]) ; 
        }

        return dp[i][j] ; 
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size() ; 
        this->N = n , this->M = m ; 
        vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , INF)) ; 

        return f(s1 , s2 , dp , 0 , 0) ; 
    }
};