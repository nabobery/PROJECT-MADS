// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

// Solution 1 using Prefix Xor
// Time complexity: O(n^3)
// Space complexity: O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n;i++) prefix[i] = prefix[i-1]^arr[i-1];
        for(int i = 0; i < n-1;i++){
            for(int j = i+1; j < n;j++){
                for(int k = j; k < n;k++){
                    int a = prefix[j]^prefix[i], b = prefix[k+1]^prefix[j];
                    if(a == b) res++;
                }
            }
        }
        return res;
    }
};

// Solution 2 using Prefix Xor and Checking if Xor(Subarray) == 0 
// As a == b implies xor(subarray[i,k]) == 0 which means there are k-i-1 triplets possible
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n;i++) prefix[i] = prefix[i-1]^arr[i-1];
        for(int i = 0; i <= n;i++)
            for(int j = i+1; j <= n;j++)
                if(prefix[i] == prefix[j]) res += j-i-1;
        return res;
    }
};


// Solution 3 using Two Pass Prefix Xor using Hashmap
// The idea is to use two pass prefix xor  and first store the prefix xor
// Then we use 2 hashmaps to iterate over the prefix xor and then calculate the number of triplets
// count[prefix[i]] stores the number of times prefix[i] has occured
// total[prefix[i]] stores the total number of indices where prefix[i] has occured
// count[prefix[i]]*i - total[prefix[i]] gives the number of triplets possible
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n;i++) prefix[i] = prefix[i-1]^arr[i-1];
        unordered_map<int, int> cnt, total;
        for(int i = 0; i <= n;i++){
            res += cnt[prefix[i]]*i - total[prefix[i]];
            cnt[prefix[i]]++;
            total[prefix[i]] += i+1;
        }
        return res;
    }
};

// Solution 4 using Single Pass Prefix Xor using Hashmap
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0, prefix = 0;
        unordered_map<int, int> cnt, total;
        cnt[0] = 1;
        for(int i = 0; i < n;i++){
            prefix ^= arr[i];
            res += cnt[prefix]*i - total[prefix];
            cnt[prefix]++;
            total[prefix] += i+1;
        }
        return res;
    }
};