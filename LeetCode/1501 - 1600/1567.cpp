// 1567. Maximum Length of Subarray With Positive Product

// my naive O(n) time and space greedy solution
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        vector<int> zeroes;
        int result = 0, n = nums.size();
        zeroes.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeroes.push_back(i);
        }
        zeroes.push_back(n);
        for (int i = 0; i < zeroes.size() - 1; i++)
        {
            int neg = 0, first = -1, last = -1;
            for (int j = zeroes[i] + 1; j < zeroes[i + 1]; j++)
            {
                if (nums[j] < 0)
                {
                    neg++;
                    if (first == -1)
                        first = j;
                    last = j;
                }
            }
            cout << first << ' ' << last << "\n";
            if (neg % 2 == 0)
            {
                result = max(result, zeroes[i + 1] - zeroes[i] - 1);
            }
            else
            {
                if (first != last)
                {
                    result = max(result, last - zeroes[i] - 1);
                    result = max(result, zeroes[i + 1] - first - 1);
                }
                else
                {
                    result = max(result, first - zeroes[i] - 1);
                    result = max(result, zeroes[i + 1] - first - 1);
                    cout << result << "\n";
                }
            }
        }
        return result;
    }
};


// O(n) Time and O(1) Space solutionusing the above logic
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int start = -1, first = -1, result = 0, neg = 0,n = nums.size();
        for(int i = 0; i < n;i++){
            if(nums[i] == 0){
                neg = 0;
                start = i;
                first = -1;
            }
            else{
                if(nums[i] < 0) neg++;
                if(neg == 1 && first == -1) first = i;
                if(neg % 2 == 0) result = max(result, i - start);
                else result = max(result, i - first);
            }
        }
        return result;
    }
};

// O(n) Time and O(1) Space solution using positive and negative subarray product length
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int result = 0, pos = 0, neg = 0;
        for(auto& num : nums){
            if(num == 0){
                pos = 0;
                neg = 0;
            }
            else{
                if(num < 0) swap(pos,neg);
                if(pos > 0 || num > 0) ++pos;
                if(neg > 0 || num < 0) ++neg;
                result = max(pos,result);
            }
        }
        return result;
    }
};