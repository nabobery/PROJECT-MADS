// 2211. Count Collisions on a Road

// Solution 1 : Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int countCollisions(string directions) {
        bool stationaryExists = false;
        int right = 0, res = 0, n = directions.size();
        for(int i = 0; i < n;i++){
            char dir = directions[i];
            if(dir == 'R'){
                // Check for immediate 'R' followed by 'L' ->  collision
                if(i+1 < n && directions[i+1] == 'L'){
                    stationaryExists = true;
                    res += 2;
                    res += right;
                    right = 0;
                    i++;
                }
                else right++;
            }
            // 'L' direction
            else if(dir == 'L'){
                if(stationaryExists) res++;
            }
            // 'S' direction
            else{
                res += right;
                right = 0;
                stationaryExists = true;
            }
        }
        return res;
    }
};

// Simpler and cleaner version of Solution 1
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), left = 0, right = n - 1;

        // 1. Skip all cars on the left moving Left (they escape)
        while (left < n && directions[left] == 'L') {
            left++;
        }

        // 2. Skip all cars on the right moving Right (they escape)
        while (right >= 0 && directions[right] == 'R') {
            right--;
        }

        // 3. Count moving cars in the remaining "trapped" zone
        int collisions = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                collisions++;
            }
        }
        return collisions;
    }
};