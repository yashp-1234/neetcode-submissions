class Solution {
public:

    int calDp(int step, vector<int>& cost, vector<int>& dp){

        if(step == -1 || step == -2){
            return 0;
        }
        if(dp[step] != -1){
            return dp[step];
        }

        int oneStep = cost[step] + calDp(step-1, cost, dp);

        int twoStep = cost[step] + calDp(step-2, cost, dp);

        dp[step] = min(oneStep, twoStep);

        return dp[step];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        cost.push_back(0);
        return calDp(cost.size()-1, cost, dp);
    }
};
