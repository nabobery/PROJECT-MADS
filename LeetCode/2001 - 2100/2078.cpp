// 2078. Two Furthest Houses With Different Colors

// Solution 1: Using Hash Map keeping track of the first and last occurrence of each color
// Time Complexity: O(n + K^2) where K is the number of unique colors
// Space Complexity: O(K) where K is the number of unique colors
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), res = 0;
        unordered_map<int, pair<int,int>> colorToFirstLastSeen;
        for(int i = 0; i < n;i++){
            if(!colorToFirstLastSeen.count(colors[i])){
                colorToFirstLastSeen[colors[i]] = {i, i};
            }
            else colorToFirstLastSeen[colors[i]].second = i;
        }
        for(auto& it1: colorToFirstLastSeen){
            for(auto& it2: colorToFirstLastSeen){
                if(it1.first != it2.first){
                    res = max(res, abs(it1.second.second - it2.second.first));
                    res = max(res, abs(it1.second.first - it2.second.second));
                }
            }
        }
        return res;
    }
};

// Solution 2: Using Two Pointers (Greedy Approach) 
// Since we want to maximize the distance, we can check the first and last elements of the array. If they are different, then the maximum distance is n - 1. If they are the same, we can move one pointer from the left and one pointer from the right until we find a different color. The maximum distance will be the maximum of the distances calculated from both pointers.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n - 1])
            return n - 1;
        int left = 0, right = n - 1;

        while (colors[right] == colors[0]) {
            right--;
        }

        while (colors[left] == colors[n - 1]) {
            left++;
        }

        return max(right, n - 1 - left);
    }
};