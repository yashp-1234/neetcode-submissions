class Solution {
public:
    int calTotal(string s, vector<int>& dp, int& n, int digits) {
        int i = s.size();
        
        // base case: finished decoding
        if (i == 0) return 1;

        // if first character is '0', invalid
        if (s[0] == '0') return 0;

        // memoization lookup
        if (dp[n - i] != -1) {
            return dp[n - i];
        }

        // take one digit
        int left = calTotal(s.substr(1), dp, n, 1);

        int right = 0;
        // take two digits if valid
        if (s.size() >= 2) {
            int val = stoi(s.substr(0, 2));
            if (val <= 26) {
                right = calTotal(s.substr(2), dp, n, 2);
            }
        }

        return dp[n - i] = left + right;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return calTotal(s, dp, n, 1); // only one call needed
    }
};

