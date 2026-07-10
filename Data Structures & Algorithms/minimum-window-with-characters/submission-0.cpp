class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        int l = 0;
        int r = 0;

        for (int i = 0; i < n2; i++) {
            mpp2[t[i]]++;
        }

        int required = mpp2.size();
        int formed = 0;

        int currlen = 0;
        int ans = INT_MAX;
        string ansstr = "";
        deque<pair<char, int>> idx;  // ✅ Changed from queue to deque

        while (r < n1) {
            if (mpp2.count(s[r]) != 0) {
                mpp1[s[r]]++;
                idx.push_back({s[r], r});

                if (mpp1[s[r]] == mpp2[s[r]]) {
                    formed++;
                }


                while (!idx.empty() && mpp1[idx.front().first] > mpp2[idx.front().first]) {
                    char drop = idx.front().first;
                    mpp1[drop]--;
                    idx.pop_front();
                }

        
                while (formed == required) {
                    currlen = r - idx.front().second + 1;
                    if (currlen < ans) {
                        ans = currlen;
                        ansstr = s.substr(idx.front().second, currlen);
                    }

                
                    char ch = idx.front().first;
                    idx.pop_front();
                    mpp1[ch]--;
                    if (mpp1[ch] < mpp2[ch]) {
                        formed--;
                    }
                }
            }
            r++;
        }

        if (ans == INT_MAX) return "";
        return ansstr;
    }
};
