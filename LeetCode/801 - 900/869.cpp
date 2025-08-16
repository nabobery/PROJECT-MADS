// 869. Reordered Power of 2

// Solution 1: By generating permutations and checking if its a power of 2
// Time Complexity: O(9 * 9!)
// Space Complexity: O(9) = O(1)
class Solution {
public:

    bool isPowerOfTwo(int n) {
        if(n == 0) return 0;
        while(n % 2 == 0) 
            n /= 2;
        return n == 1;     
    }

    bool nextPermutation(vector<int>& nums) {
        int n = nums.size(), k = -1, l = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) return false;

        for (int i = n - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[l], nums[k]);
        int i = k + 1, j = n - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> digits;
        int temp = n, f;
        while(temp){
            digits.push_back(temp%10);
            temp /= 10;
        }
        sort(digits.begin(), digits.end());

        bool b = true;

        while(b){
            temp = 0, f = digits[0];
            for(int i = 0; i < digits.size();i++){
                temp += digits[i];
                if(i != digits.size() - 1) temp *= 10;
            }
            b = nextPermutation(digits);
            if(f == 0) continue;
            if(isPowerOfTwo(temp)) return true;
        }
        return false;
    }
};

// Solution 2: Using HashMap and Sorting
// Time Complexity: O(9 + 31*9log9) = O(1)
// Space Complexity: O(31*9) = O(1)
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = countDigits(n);

        static unordered_set<string> powerSignatures = generatePowerSignatures();

        return powerSignatures.count(target);
    }

private:
    string countDigits(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }

    static unordered_set<string> generatePowerSignatures() {
        unordered_set<string> signatures;
        for (int i = 0; i < 31; ++i) { 
            int power = 1 << i;
            string sig = to_string(power);
            sort(sig.begin(), sig.end());
            signatures.insert(sig);
        }
        return signatures;
    }
};