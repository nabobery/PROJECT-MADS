// 2251. Number of Flowers in Full Bloom

// Solution 1 using Priority Queue
// Time complexity: O(nlogn+m(logn+logm))
// Space complexity: O(n+m)
// Intuitive Solution
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // sort the people and the flowers
        vector<int> temp(people.begin(), people.end());
        sort(temp.begin(), temp.end());
        sort(flowers.begin(), flowers.end());
        // map to store the time t and the number of flowers in full bloom at time t
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for(auto p : temp){
            // add the flowers that have start bloom time before or equal to time p
            while(i < flowers.size() && flowers[i][0] <= p){
                pq.push(flowers[i][1]);
                i++;
            }
            // remove the floweers whose bloom end time is before p
            while(!pq.empty() && pq.top() < p){
                pq.pop();
            }
            // add the number of flowers in full bloom at time p
            mp[p] = pq.size();
        }
        vector<int> res;
        for(auto p : people){
            res.push_back(mp[p]);
        }
        return res;
    }
};

// Solution 2 using Difference Prefix + Binary Search
// Time complexity: O((n+m)logn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // map for difference 
        map<int, int> diff;
        diff[0] = 0;
        // range to store the number of flowers in full bloom
        for(auto flower : flowers){
            diff[flower[0]]++;
            diff[flower[1]+1]--;
        }
        // pos to store the position of the difference prefix sum
        // prefix to store the difference prefix sum
        vector<int> pos, prefix;
        int sum = 0;
        // calculate the difference prefix sum
        for(auto p : diff){
            pos.push_back(p.first);
            sum += p.second;
            prefix.push_back(sum);
        }
        vector<int> res;
        // binary search to find the position of number of flowers in full bloom at time p
        for(auto p : people){
            int idx = upper_bound(pos.begin(), pos.end(), p) - pos.begin()-1;
            res.push_back(prefix[idx]);
        }
        return res;
    }
};

// Solution 3 using Binary Search
// Time complexity: O((n+m)logn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // start to store the start bloom time
        // end to store the end bloom time
        vector<int> start, end;
        for(auto flower : flowers){
            start.push_back(flower[0]);
            end.push_back(flower[1]+1);
        }
        // sort the start and end time
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> res;
        // binary search to find the number of flowers in full bloom at time p
        for(auto p : people){
            // upper_bound to find flowers whose start bloom time is before or equal to p
            int i = upper_bound(start.begin(), start.end(), p) - start.begin();
            // upper_bound to find flowers whose end bloom time is before p
            int j = upper_bound(end.begin(), end.end(), p) - end.begin();
            // the number of flowers in full bloom at time p is i-j
            res.push_back(i-j);
        }
        return res;
    }
};