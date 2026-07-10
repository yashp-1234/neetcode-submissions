class Solution {
public:
    void dfs(string src, map<string, vector<string>>& mp, vector<string> &ans){
        auto &dests = mp[src];

        while(!dests.empty()){
            string next = dests.back();
            dests.pop_back();

            dfs(next, mp, ans);
        }

        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        map<string, vector<string>> mp;
        for(int i=0; i<n; i++){
            mp[tickets[i][0]].emplace_back(tickets[i][1]);
        }

        for(auto &[src, dests] : mp){
            sort(dests.rbegin(), dests.rend());
        }

        vector<string> ans;

        dfs("JFK", mp, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};