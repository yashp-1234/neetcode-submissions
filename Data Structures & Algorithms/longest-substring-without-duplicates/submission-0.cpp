class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 1;
        int n = s.size(); 
        if(n == 0) return 0;

        int currlen = 1;
        int anslen = 1;
        queue<pair<char, int>> mpp;
        set<char> myset;

        mpp.push({s[0], 0});
        myset.insert(s[0]);

        while(r < n){
            if(myset.count(s[r]) == 0){
                mpp.push({s[r], r});
                myset.insert(s[r]);
                r++;
                currlen++;
            }
            else {
                anslen = max(anslen, currlen);
                int m = mpp.size();
                for(int i = 0; i < m; i++){
                    if(mpp.front().first != s[r]){
                        myset.erase(mpp.front().first);
                        mpp.pop();
                        currlen--;
                    }
                    else {
                        l = mpp.front().second + 1;
                        myset.erase(mpp.front().first);
                        mpp.pop();
                        currlen--;
                        break;
                    }
                }
                mpp.push({s[r], r});
                myset.insert(s[r]);
                r++;
                currlen++;
            }
        }

        return max(anslen, currlen);
    }
};

