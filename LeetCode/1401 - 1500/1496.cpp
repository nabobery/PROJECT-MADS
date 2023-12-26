// 1496. Path Crossing

// Solution 1 using set
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        map<char, pair<int,int>> dirs = {{'N', {-1,0}}, {'S', {1,0}}, {'E', {0,1}}, {'W', {0,-1}}};
        pair<int,int> curr = {0,0};
        visited.insert(curr);
        for(char p : path){
            curr = {curr.first + dirs[p].first, curr.second + dirs[p].second};
            if(visited.count(curr)) return true;
            visited.insert(curr);
        }
        return false;
    }
};


// Solution 2 using unordered set
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const{
            return hash<T1>()(p.first) ^ hash<T2>()(p.second);
        }
    };
    bool isPathCrossing(string path) {
        unordered_set<pair<int,int>, hash_pair> visited;
        unordered_map<char, pair<int,int>> dirs = {{'N', {-1,0}}, {'S', {1,0}}, {'E', {0,1}}, {'W', {0,-1}}};
        pair<int,int> curr = {0,0};
        visited.insert(curr);
        for(char p : path){
            curr = {curr.first + dirs[p].first, curr.second + dirs[p].second};
            if(visited.count(curr)) return true;
            visited.insert(curr);
        }
        return false;
    }
};