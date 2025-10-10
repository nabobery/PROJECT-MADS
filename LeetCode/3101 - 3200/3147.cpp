// 3147. Taking Maximum Energy From the Mystic Dungeon

// Solution 1: Greedy and Straightforward Implementation using Unordered Map
// Time Complexity: O(n * (n/k))
// Space Complexity: O(n)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = -1000, n = energy.size();
        unordered_map<int,int> finalK;
        // Initialize the last k elements
        for(int i =n-k; i < n;i++){
            finalK[i] = energy[i];
            res = max(res, energy[i]);
        }
        // Update the map for each multiple of k
        for(int i =1; i <= n/k;i++){
            for(auto& it: finalK){
                if(it.first >= k*i){
                    it.second += energy[it.first - k*i];
                    res = max(res, it.second);
                }
            }
        }
        return res;
    }
};

// More Efficient and Concise Implementation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int max_energy = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (i + k < n) energy[i] += energy[i + k];
            max_energy = max(max_energy, energy[i]);
        }
        return max_energy;
    }
};