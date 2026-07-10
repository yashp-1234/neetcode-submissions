int checkIf(int i, vector<int>& dp, int& n, vector<int>& nums) {
    if (dp[i] != -1) {
        return dp[i];
    }
    if (i == n - 1) {
        return 0;
    }
    if (nums[i] == 0) {
        return INT_MAX;
    }

    int ans = INT_MAX;
    int currval = INT_MAX;
    for (int j = 1; j <= nums[i] && i + j < n; j++) {
        currval = checkIf(i + j, dp, n, nums);
        if (currval != INT_MAX) {
            ans = min(ans, 1 + currval);
        }
    }

    dp[i] = ans;
    return dp[i];
}
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = checkIf(0, dp, n, nums);

        return ans == INT_MAX ? 0 : ans;
    }
};
