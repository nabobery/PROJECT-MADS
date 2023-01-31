// 460. LFU Cache

class LFUCache {
    unordered_map<int, list<pair<int, int>>> frequencies;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int cap,minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }
public:
    LFUCache(int capacity){
        cap = capacity;
        minf = 0;
    }

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto itr = it->second.second;
        pair<int, int> kv = *itr;
        frequencies[f].erase(itr);
        if (frequencies[f].empty() && minf == f) {
            ++minf;
        }
        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if(cap == 0) return;
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (cap == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();
        }
        minf = 1;
        insert(key, 1, value);
    }
};