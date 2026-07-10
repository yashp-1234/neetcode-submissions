class Solution {
private:
    int cntbits(bitset<32> b){
        int ans = 0;
        for(int i=0; i<32; i++){
            ans += b[i];
        }

        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++){
            ans[i] = cntbits(i);
        }
        return ans;
    }
};
