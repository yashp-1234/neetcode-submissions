class Solution {
public:
    int makeDp(int i, vector<int>& nums, vector<int>& dp){
        if(dp[i] != -1){
            return dp[i];
        }
        if(i == 1){
            dp[i] = nums[i];
            return nums[i];
        }
        if(i == 0){
            dp[i] = nums[i];
            return nums[i];
        }

        set<int, greater<int>> myset;
        for(int j=i-2; j>=0; j--){
            myset.insert(makeDp(j, nums, dp));
        }
        dp[i] = nums[i] + *myset.begin();
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int currans = 0;
        vector<int> dp(n+1, -1);
        for(int i=n-1; i>=0; i--){
            currans = makeDp(i, nums, dp);
            ans = max(currans, ans);
        }
        return ans;
    }
};
