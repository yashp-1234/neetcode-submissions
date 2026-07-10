class TimeMap {
public:
    TimeMap() { }

    // key → {timestamp → value}
    map<string, map<int, string>> mpp;

    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (!mpp.count(key)) return "";

        auto& innerMap = mpp[key];
        auto it = innerMap.upper_bound(timestamp); // First element > timestamp

        if (it == innerMap.begin()) return ""; // No timestamp ≤ given
        --it; // Move to largest timestamp ≤ given

        return it->second;
    }
};
