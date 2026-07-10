class Solution {
    long calHours(int speed, vector<int>& piles) {
    long totalHours = 0;
    for(int bananas : piles) {
        totalHours += ceil((double)bananas / speed);
    }
    return totalHours;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    int ans = r;

    while (l <= r) {
        long mid = (l + r) / 2;
        long hours = calHours(mid, piles);

        if (hours <= h) {
            ans = mid;      // try to minimize speed
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

};
