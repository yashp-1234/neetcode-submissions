class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> b(n);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += b[i];
        }

        return ans;
    }
};
