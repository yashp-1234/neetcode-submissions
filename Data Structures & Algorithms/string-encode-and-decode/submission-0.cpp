#include <string>
class Solution {
public:

    string s = "";
    vector<int> len;
    

    string encode(vector<string>& strs) {
        int n = strs.size();
        for(int i=0; i<n; i++){
            len.push_back(strs[i].size());
            s+=strs[i];
        }
        return s;
    }

    vector<string> ans;
    vector<string> decode(string s) {
        int m = len.size();
        int curridx = 0;
        for(int i=0; i<m; i++){
            string currstr = s.substr(curridx, len[i]);
            ans.push_back(currstr);
            curridx += len[i];
        }
    return ans;
    }
};
