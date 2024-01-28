// 380. Insert Delete GetRandom O(1)

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Solution 1 using Unordered Set
class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {  
    }
    
    bool insert(int val) {
        bool b = s.count(val) == 0;
        s.insert(val);
        return b;
    }
    
    bool remove(int val) {
        bool b = s.count(val) != 0;
        s.erase(val);
        return b;
    }
    
    int getRandom() {
        auto it = next(s.begin(), rand()%s.size());
        return *it;
    }
};

// Solution 2 using Vector and Map
class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> m;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool b = m.count(val) == 0;
        if (b) {
            v.push_back(val);
            m[val] = v.size()-1;
        }
        return b;
    }
    
    bool remove(int val) {
        bool b = m.count(val) != 0;
        if (b) {
            int i = m[val];
            v[i] = v.back();
            m[v[i]] = i;
            v.pop_back();
            m.erase(val);
        }
        return b;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};
