//698. Partition to K Equal Sum Subsets
//time complexity is of the order of 2^N
class Solution {
public:
    bool helper(vector<int>& nums, int subsetSum[], bool taken[], int subset,int k,int n, int curr, int limit){
        // if subset sum = required subset sum
        if(subsetSum[curr] == subset){
            if(curr == k-2) // if this is the last subset return true
                return true;
            return helper(nums,subsetSum,taken, subset,k,n,curr + 1,n-1); // go recursive
        }
        // from backward as we took the last element
        for(int i = limit; i >= 0;i--){
            // if laready taken, continue(shouldn't include)
            if(taken[i])
                continue;
            // using a temp variable to keep track if the addition is less than required subset sum
            int temp = subsetSum[curr] + nums[i];
            if(temp <= subset){
                taken[i] = true; // set taken to true
                subsetSum[curr] += nums[i]; // add the element
                bool next = helper(nums,subsetSum,taken, subset,k,n,curr,i-1); // to see if this addition and beyond result in true
                taken[i] = false; // umark the element if it's false
                subsetSum[curr] -= nums[i];
                if(next){ // if it's true proceed
                    return true;
                }
            }
        }
        // return false if not possible
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(); // number of elements
        if(k == 1) // if there is only one subset(it's true as we can use the whole array)
            return true;
        if(n < k) // not possible as k subsets won't be possible if there aren't those many elements in the array
            return false;
        // Calculating sum
        int sum  = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        // if elements can't be made into K subsets(by sum)
        if(sum % k != 0)
            return false;
        int subset = sum/k; // required sum
        int subsetSum[k]; // sum of k subsets
        bool taken[n]; // array to see if element is taken or not
        for(int i = 0; i < k; i++){
            subsetSum[i] = 0;
        }
        for(int i = 0; i < n; i++){
            taken[i] = false;
        }
        subsetSum[0] = nums[n -1]; // setting first subsetsum as final array element
        taken[n - 1] = true; // taken as true for final element of array
        return helper(nums,subsetSum,taken, subset,k,n,0,n-1);
    }
};