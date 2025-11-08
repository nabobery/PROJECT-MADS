// 3321. Find X-Sum of All K-Long Subarrays II

// Solution 1: Sliding Window and Set
// Time Complexity: O(n + klogk)
// Space Complexity: O(k)
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        long long curr = 0;
        vector<long long> res(n-k+1, 0);
        // topx frequent and other element in window
        set<pair<int,int>> g1, g2;
        unordered_map<int,int> freq;
        for(int i = 0; i < k;i++) freq[nums[i]]++;
        for(auto& it: freq) g1.insert({it.second, it.first});
        while(g1.size() > x){
            auto it = g1.begin();
            g2.insert({it->first, it->second});
            g1.erase(*it);
        }
        for(auto& it : g1) curr += 1LL*it.first * it.second;
        res[0] = curr;
        for(int i = k; i < n;i++){
            // for nums i-k
            if(g1.count({freq[nums[i-k]], nums[i-k]})){
                g1.erase({freq[nums[i-k]], nums[i-k]});
                freq[nums[i-k]]--;
                if(freq[nums[i-k]]) g1.insert({freq[nums[i-k]], nums[i-k]});
                curr -= nums[i-k];
            }
            else{
                g2.erase({freq[nums[i-k]], nums[i-k]});
                freq[nums[i-k]]--;
                if(freq[nums[i-k]]) g2.insert({freq[nums[i-k]], nums[i-k]});
            }

            // for nums1
            if(g1.count({freq[nums[i]], nums[i]})){
                g1.erase({freq[nums[i]], nums[i]});
                freq[nums[i]]++;
                g1.insert({freq[nums[i]], nums[i]});
                curr += nums[i];
            }
            else if(g2.count({freq[nums[i]], nums[i]})){
                g2.erase({freq[nums[i]], nums[i]});
                freq[nums[i]]++;
                g2.insert({freq[nums[i]], nums[i]});
            }
            else{
                freq[nums[i]]++;
                g2.insert({freq[nums[i]], nums[i]});
            }

            if(!g2.empty()){
                auto largestG2 = g2.rbegin();
                g1.insert({largestG2->first, largestG2->second});
                curr += 1LL* largestG2->first * largestG2->second;
                g2.erase(*largestG2);
                while(g1.size() > x){
                    auto it = g1.begin();
                    curr -= 1LL*it->first * it->second;
                    g2.insert({it->first, it->second});
                    g1.erase(*it);
                }
            }
            res[i-k+1] = curr;
        }
        return res;
    }
};

// a more elegant solution 1
class Solution {
    // We use 'long long' for the sum, as frequencies and values can be large.
    long long curr_sum = 0;
    
    // Map to store {value -> frequency}
    unordered_map<int, int> freq;
    
    // g1 = "top x", g2 = "the rest"
    // Sets store {frequency, value}
    set<pair<int, int>> g1, g2;
    
    // Helper 1: Remove a value's pair from whichever set it's in
    void removePair(int val) {
        // Find the old pair using its *current* frequency
        int f = freq[val];
        if (f == 0) return; // Should not happen if logic is correct, but safe
        
        pair<int, int> p = {f, val};
        
        if (g1.count(p)) {
            g1.erase(p);
            // If it was in g1, it was part of the sum
            curr_sum -= 1LL * p.first * p.second;
        } else {
            // It must be in g2
            g2.erase(p);
        }
    }
    
    // Helper 2: Add a value's new pair
    void addPair(int val) {
        int f = freq[val];
        if (f == 0) return; // Don't store zero-frequency elements
        
        pair<int, int> p = {f, val};
        
        // As a default, just add to g2.
        // The balance() function will promote it to g1 if it belongs there.
        // This simplifies the logic.
        g2.insert(p);
    }

    // Helper 3: The magic. Rebalance the sets.
    // This is the most elegant part of the refactor.
    void balance(int x) {
        // Case 1: g1 is too small. Promote the best from g2.
        while (g1.size() < x && !g2.empty()) {
            auto largest_g2 = *g2.rbegin(); // Get largest from g2
            
            g2.erase(prev(g2.end()));      // Remove it from g2
            g1.insert(largest_g2);         // Add it to g1
            
            // Update the sum
            curr_sum += 1LL * largest_g2.first * largest_g2.second;
        }
        
        // Case 2: g1 is too big. Demote the worst from g1.
        while (g1.size() > x) {
            auto smallest_g1 = *g1.begin(); // Get smallest from g1
            
            g1.erase(g1.begin());          // Remove it from g1
            g2.insert(smallest_g1);        // Add it to g2
            
            // Update the sum
            curr_sum -= 1LL * smallest_g1.first * smallest_g1.second;
        }
        
        // Case 3: Sizes are correct, but boundary might be wrong.
        // (g1's worst < g2's best)
        // This ensures g1 *always* has the "best" x elements.
        if (!g1.empty() && !g2.empty()) {
            auto smallest_g1 = *g1.begin();
            auto largest_g2 = *g2.rbegin();
            
            if (largest_g2 > smallest_g1) {
                // Swap them
                g1.erase(g1.begin());
                g2.erase(prev(g2.end()));
                
                g1.insert(largest_g2);
                g2.insert(smallest_g1);
                
                // Update sum for the swap
                curr_sum -= 1LL * smallest_g1.first * smallest_g1.second;
                curr_sum += 1LL * largest_g2.first * largest_g2.second;
            }
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res(n - k + 1);
        
        // --- Initialization (First Window) ---
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        
        for (auto const& [val, f] : freq) {
            // Initially add all to g2, let balance() sort it out
            g2.insert({f, val});
        }
        
        balance(x); // This will move the top x from g2 to g1 and set curr_sum
        res[0] = curr_sum;

        // --- Sliding Window ---
        for (int i = k; i < n; i++) {
            int val_out = nums[i - k];
            int val_in = nums[i];

            // Step 1: Remove old pairs
            removePair(val_out);
            removePair(val_in); // Handles val_in == val_out case correctly
            
            // Step 2: Update frequencies
            freq[val_out]--;
            freq[val_in]++;
            
            // Step 3: Add new pairs
            addPair(val_out);
            addPair(val_in);
            
            // Step 4: Rebalance
            // This single call handles all complexity.
            balance(x);
            
            res[i - k + 1] = curr_sum;
        }
        
        return res;
    }
};