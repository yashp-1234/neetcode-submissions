class Solution {
public:
    int reverseBits(int n) {
        bitset<32> a(n);
        bitset<32> b;

        for(int i=31; i>=0; i--){
            b[31-i] = a[i];
        }

        return b.to_ulong();
        
    }
};
