class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    unordered_map<int, vector<int>> following;
    int count = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId) {

        // use min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int n = mp[userId].size();

        for (int i = 0; i < n; i++) {
            pq.push(mp[userId][i]);

            if (pq.size() > 10) {
                pq.pop();
            }
        }

        int m = 0;

        n = following[userId].size();
        for (int i = 0; i < n; i++) {
            int followeeId = following[userId][i]; // get followee id
            m = mp[followeeId].size();             // check tweets of followee

            for (int j = 0; j < m; j++) {
                pq.push(mp[followeeId][j]);

                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return; // optional: prevent self-follow
        auto& vec = following[followerId];
        if (find(vec.begin(), vec.end(), followeeId) == vec.end()) {
            vec.push_back(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        auto& vec = following[followerId];
        vec.erase(remove(vec.begin(), vec.end(), followeeId), vec.end());
    }
};
