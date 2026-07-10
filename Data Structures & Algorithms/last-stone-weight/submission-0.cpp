class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int a = 0;
        int b = 0;
        while(pq.size() != 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(abs(a-b));
        }
        return pq.top();
    }
};
