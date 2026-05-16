// 3629. Minimum Jumps to Reach End via Prime Teleportation

// Solution 1: BFS + Sieve of Eratosthenes
// Time Complexity: O(n log log m + n log n) where m is the maximum element in nums
// Space Complexity: O(n + m) for the sieve and the prime to indices mapping
class Solution {
public:
    vector<int> spf;
    // spf[i] will be the smallest prime factor of i
    void sieve(int mx) {
        spf.resize(mx+1);
        for (int i = 0; i <= mx; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        // Find the maximum element in nums to determine the size of the sieve
        int mx = *max_element(nums.begin(), nums.end());
        sieve(mx);
        // Map each prime to the indices in nums that have that prime as the factor
        unordered_map<int, vector<int>> primeToIndices;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            while (num != 1){
                int p = spf[num];
                primeToIndices[p].push_back(i);
                while (num % p == 0)
                    num /= p;
            }
        }
        // BFS to find the minimum jumps
        queue<int> q;
        // Start from index 0
        q.push(0);
        int steps = 0;
        // visited array to keep track of visited indices
        vector<bool> visited(n, false);
        visited[0] = false;
        // BFS loop
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz;i++){
                int ind = q.front();
                // If we have reached the last index, return the number of steps taken
                if(ind == n-1) return steps;
                q.pop();
                // Check the adjacent indices (ind+1 and ind-1) and add them to the queue if they are valid and not visited
                if(ind+1 < n && !visited[ind+1]){
                    q.push(ind+1);
                    visited[ind+1] = true;
                }
                if(ind > 0 && !visited[ind-1]){ 
                    q.push(ind-1);
                    visited[ind-1] = true;
                }
                // if numss[ind] is a prime, we can teleport to all indices that have nums[ind] as a prime factor
                if(primeToIndices.count(nums[ind])){
                    // Teleport to all indices that have nums[ind] as a prime factor
                    for(auto& it: primeToIndices[nums[ind]]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = true;
                        }
                    }
                    // After teleporting, we can erase the prime from the map to avoid redundant teleportation in future iterations
                    primeToIndices.erase(nums[ind]);
                }
            }
            steps++;
        }
        return -1;
    }
};