class Solution {
public:
    int checkPal(int l, int r, int n, string s){
        int ans = 0;
        while(l >= 0 && r < n){
            if(s[l] == s[r]){
                ans++;
            }
            else{
                break;
            }
            l--;
            r++;
        }
        return ans;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int len = 0;

        for(int i=0; i<n; i++){
            // odd length palindrome
            int currlen = checkPal(i-1, i+1, n, s);
            if(currlen*2 + 1 > len){
                len = currlen*2 + 1;
                ans = s.substr(i-currlen, len);
            }

            // even length palindrome
            int currlen2 = checkPal(i, i+1, n, s);
            if(currlen2*2 > len){
                len = currlen2*2;
                ans = s.substr(i-currlen2+1, len);
            }
        }
        return ans;
    }
};
