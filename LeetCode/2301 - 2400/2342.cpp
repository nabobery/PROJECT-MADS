// 2342. Max Sum of a Pair With Equal Sum of Digits

// Solution 1 using priority queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int res = -1;
        unordered_map<int, priority_queue<int>> mp;
        for (int &num : nums)
        {
            int digitSum = 0, temp = num;
            while (temp > 0)
            {
                digitSum += temp % 10;
                temp /= 10;
            }
            mp[digitSum].push(num);
        }
        for (auto &it : mp)
        {
            if (it.second.size() >= 2)
            {
                // auto it1 = it.second.rbegin(), it2 = it1;
                // it2--;
                // cout<<*it1<<" "<<*it2<<"\n";
                // res = max(res, *it1 + *it2);
                int mx1 = it.second.top();
                it.second.pop();
                int mx2 = it.second.top();
                res = max(mx1 + mx2, res);
            }
        }
        return res;
    }
};

// Solution 2 using unordered_map of int to pairs storing max1 and max2
// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int res = -1;
        unordered_map<int, pair<int, int>> mp;

        for (int num : nums)
        {
            int digitSum = 0, temp = num;
            while (temp > 0)
            {
                digitSum += temp % 10;
                temp /= 10;
            }

            auto &p = mp[digitSum];
            if (num > p.first)
            {
                p.second = p.first;
                p.first = num;
            }
            else if (num > p.second)
            {
                p.second = num;
            }
        }

        for (auto &[_, p] : mp)
        {
            if (p.second > 0)
            {
                res = max(res, p.first + p.second);
            }
        }

        return res;
    }
};