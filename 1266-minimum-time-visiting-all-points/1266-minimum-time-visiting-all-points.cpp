class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cost = 0 ; 

        for ( int i = 1 ; i < (int)points.size() ; i++ ) {
            int yBig = max(points[i][1] , points[i - 1][1]) ; 
            int ySmall = min(points[i][1] , points[i - 1][1]) ; 
            int xBig = max(points[i][0] , points[i - 1][0]) ; 
            int xSmall = min(points[i][0] , points[i - 1][0]); 

            while(true){
                if((xBig==xSmall) || (yBig==ySmall)){
                    break ; 
                }

                yBig -= 1;
                xBig -= 1 ; 
                cost++ ; 
            }

            cost += (xBig - xSmall) + (yBig - ySmall) ; 
        }


        return cost ; 
    }
};