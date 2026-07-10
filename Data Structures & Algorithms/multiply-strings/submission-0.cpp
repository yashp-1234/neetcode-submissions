class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        vector<int> ans(n1 + n2, 0);
        int gap = 0;
        int carry = 0;

        for (int i = n2 - 1; i >= 0; --i) {
            for (int j = n1 - 1; j >= 0; --j) {
                int prod =
                    (num2[i] - '0') * (num1[j] - '0'); // product of two digits
                int p1 = i + j;                        // index for carry
                int p2 = i + j + 1;       // index for current digit
                int sum = ans[p2] + prod; // add existing value at p2
                ans[p2] = sum % 10;
                ans[p1] += sum / 10; // add carry to the higher slot
            }
        }

        string ans_str;
        int k = 0;
        // skip leading zeros
        while (k < ans.size() && ans[k] == 0)
            ++k;
        for (; k < ans.size(); ++k)
            ans_str.push_back(char('0' + ans[k]));
        if (ans_str.empty())
            return "0";
        return ans_str;
    }
};
