class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pr = {};
        for(int i=0; i<n; i++){
            pr.push_back({position[i], speed[i]});
        }
        sort(pr.begin(), pr.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });
        for(int i=0; i<n; i++){
            cout<<pr[i].first << " " << pr[i].second <<endl;
        }
        stack<float> st;
        st.push((float)(target - pr[0].first) / pr[0].second);

        for(int i = 1; i < n; i++) {
            float time = (float)(target - pr[i].first) / pr[i].second;
            if (time > st.top()) {
                cout << i << endl;
                st.push(time);
            }
        }
        return st.size();
    }
};