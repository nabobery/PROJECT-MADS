// 287. Find the Duplicate Number
// my naive O(n) time and space solution using unordered_set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int result;
        for(int num : nums){
            // if already there then return num
            if(s.count(num)){
                result = num;
                break;
            }
            // else insert into the set
            else s.insert(num);
        }
        return result;
    }
};

// using sort and compare adjacent elements
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size();i++){
            if(nums[i] == nums[i-1]) return nums[i];
        }
        return -1;
    }
};

// negative marking O(n) time and O(1) space solution
// traverse the array and make the array index of current num as negative and if we encounter a negative number again, it means
// that the current num is repeated
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for(int &num : nums){
            int curr = abs(num);
            if(nums[curr] < 0){
                duplicate = curr;
                break;
            }
            nums[curr] *= -1;
        }
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        return duplicate;
    }
};

// using Array as HashMap Iterative O(n) time and O(1) space solution
// As 0 doesn't have any mapping(number between 1 and n), we choose zero as the starting place
// The key idea is to always map the number at index 0 to its equivalent index.
// We keep on swapping and use the number as key of a hashmap and it's value is the nums[number] until we encounter the same number again
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]])
            swap(nums[0],nums[nums[0]]);
        return nums[0];
    }
};

// Using slow and fast pointers
// O(n) time and O(1) space solution
// The idea is to use slow and fast pointers. The slow pointer moves one step at a time while the fast pointer moves based on the number at the num[index].
// Eventually, they will meet at a loop. The entry point of the loop is the duplicate number.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        // find the intersection point of the two runners
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // find the "entrance" to the cycle
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Bit Manipulation O(nlogn) time and O(1) space solution
// The idea is to count the number of 1s in the binary representation of the numbers from 1 to n.
// If the count of 1s is greater than the count of 0s, then the duplicate number's binary representation will have 1s at the same positions.
// We can use this idea to find the duplicate number.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int duplicate = 0;
        // count the number of 1s in the binary representation of the numbers from 1 to n
        for(int i = 0; i < 32; i++){
            int bit = (1 << i);
            int count1 = 0, count2 = 0;
            for(int j = 0; j <= n; j++){
                if(j & bit) count1++;
                if(nums[j] & bit) count2++;
            }
            if(count2 > count1) duplicate |= bit;
        }
        return duplicate;
    }
};

