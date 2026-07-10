class Solution {
    bool checkIf(int i, vector<int>& dp, int& n, vector<int>& nums) {
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i == n - 1) {
            return true;
        }
        if (nums[i] == 0) {
            return false;
        }

        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            if (checkIf(i + j, dp, n, nums)) {
                dp[i+j] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        bool ans = checkIf(0, dp, n, nums);

        return ans;
    }
};
