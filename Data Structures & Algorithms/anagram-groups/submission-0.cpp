class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Anagrams will match after sorting
            mpp[sortedStr].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
