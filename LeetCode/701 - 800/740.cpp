// 740. Delete and Earn
// Top-Down Dynamic Programming O(N + Max) time and Space Solution
// In the top-down approach, we start at the "top" (maxNumber), and move towards our base cases
class Solution {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> cache;
    // to get points when we start from the given num
    int points(int num){
        // if it's 0 then return 0 as we get 0 points
        if(num == 0) return 0;
        // return points gained by deleting 1 if it exists else 0
        if(num == 1) return mp.count(1) ? mp[1] : 0;
        // get points gained for a specific subproblem if already computed
        if(cache.count(num)) return cache[num];
        // points gained by deleting the num
        int gain = mp.count(num) ? mp[num] : 0;
        // storing the maximum of the points earned by either taking num or not taking num
        cache[num] = max(points(num - 1), points(num - 2) + gain);
        return cache[num];
    }
    // we Find the Max element and then start the program from there
    int deleteAndEarn(vector<int>& nums) {
        int Max = 0;
        // fill the map with num -> points and get max
        for(int num : nums){
            mp[num] += num;
            Max = max(Max,num);
        }
        return points(Max);
    }
};

// bottom up DP O(N + Max) time and Space Solution
// With bottom-up, we will start at the base cases and iterate away from them towards the result we want (maxNumber)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int Max = 0;
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num] += num;
            Max = max(Max,num);
        }
        vector<int> maxPoints(Max+1,0);
        maxPoints[1] = mp.count(1) ? mp[1] : 0;
        for(int i = 2; i < maxPoints.size();i++){
            int gain = mp.count(i) ? mp[i] : 0;
            maxPoints[i] = max(maxPoints[i - 1], maxPoints[i - 2] + gain);
        }
        return maxPoints[Max];
    }
};

// space optimised Bottom Up DP O(N + Max) time and O(N) Space Solution
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int Max = 0;
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num] += num;
            Max = max(Max,num);
        }
        vector<int> elements;
        for(auto itr: mp) elements.push_back(itr.first);
        sort(elements.begin(),elements.end());
        // base case
        int prev2 = 0, prev1 = mp[elements[0]];
        for(int i = 1; i < elements.size();i++){
            int curr = elements[i];
            int temp = prev1;
            // If the 2 elements are adjacent, cannot take both - apply normal recurrence
            if(curr == elements[i - 1] + 1){
                prev1 = max(prev1, prev2 + mp[curr]);
            }
            // else delete as we need not worry about adjacent
            else{
                prev1 += mp[curr];
            }
            prev2 = temp;
        }
        return prev1;
    }
};




