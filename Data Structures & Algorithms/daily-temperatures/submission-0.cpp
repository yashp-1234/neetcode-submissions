class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n, 0);
        stack<pair<int, int>>st;
        st.push({0, temperatures[0]});
        for(int i=1; i<n; i++){
            if(st.size() > 0 && temperatures[i] > st.top().second){
                // int cnt = 0;
                while(st.size() > 0 && st.top().second < temperatures[i]){
                    ans[st.top().first] = i - st.top().first;
                    st.pop();
                    // cnt++;
                }
                st.push({i, temperatures[i]});
            }
            else{
                st.push({i, temperatures[i]});
            }
        }
        return ans;
    }
};
