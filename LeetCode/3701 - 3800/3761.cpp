// 3761. Minimum Absolute Distance Between Mirror Pairs

// Solution 1: Hash Map + Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), res = n;
        unordered_map<string, vector<int>> numToIndices;
        for(int i = 0; i < n;i++)
            numToIndices[to_string(nums[i])].push_back(i);
        for(int i = 0; i < n;i++){
            string curr = to_string(nums[i]);
            while(curr.back() == '0') curr.pop_back();
            reverse(curr.begin(), curr.end());
            if(numToIndices.count(curr)){
                auto it = upper_bound(numToIndices[curr].begin(), numToIndices[curr].end(), i);
                if(it != numToIndices[curr].end()) res = min(res, *it - i);
            }
        }
        return res == n ? -1 : res;
    }
};

// Solution 2: Hash Map (Store Last Seen Index) + Reverse Integer
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), res = n;
        unordered_map<int, int> lastSeen;
        for (int i = n - 1; i >= 0; --i) {
            int original = nums[i];
            int reversed = reverseInt(original);

            if (lastSeen.count(reversed)) {
                res = min(res, lastSeen[reversed] - i);
            }

            lastSeen[original] = i;
        }

        return (res == n) ? -1 : res;
    }

private:
    int reverseInt(int n) {
        if (n == 0)
            return 0;
        while (n > 0 && n % 10 == 0) {
            n /= 10;
        }
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }
};