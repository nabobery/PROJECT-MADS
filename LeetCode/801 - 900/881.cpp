// 881. Boats to Save People

// Solution 1 using Sorting and Two Pointers
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // get size
        int n = people.size();
        // sort weights in descending order
        sort(people.begin(), people.end(), greater<int>());
        // two pointers left and right and initialising result
        int l = 0, r = n - 1, result = 0;
        // loop until left <= right
        while(l <= r){
            // get weight of two people as boat can carry atmost 2
            int curr = people[l] + people[r];
            // if only one person left, then result++ and increment left
            if(l == r){
                l++;
                result++;
            }
            // else
            else{
                // if current weight less than limit increment result and increment pointers
                if(curr <= limit){
                    l++;
                    r--;
                    result++;
                }
                // else increment the boat by incrementing the right pointer(as it's heavier than the left pointer)
                else{
                    l++;
                    result++;
                }
            }
        }
        // return result
        return result;
    }
};

