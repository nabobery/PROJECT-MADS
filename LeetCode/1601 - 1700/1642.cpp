// 1642. Furthest Building You Can Reach

// Solution 1 Greedy using Priority Queue
// Time complexity: O(nlogk)
// Space complexity: O(k)
// where n is the size of the heights and k is the size of the priority queue
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size(), temp = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < n; i++)
        {
            if (heights[i] > heights[i - 1])
            {
                int curr = heights[i] - heights[i - 1];
                if (pq.size() < ladders)
                    pq.push(curr);
                else if (!pq.empty() && curr > pq.top())
                {
                    if (temp + pq.top() > bricks)
                        return i - 1;
                    else
                        temp += pq.top();
                    pq.pop();
                    pq.push(curr);
                }
                else if (temp + curr <= bricks)
                    temp += curr;
                else
                    return i - 1;
            }
        }
        return n - 1;
    }
};

// Cleaned up version of Solution 1 using Priority Queue
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size(), sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < n; i++)
        {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0)
            {
                pq.push(diff);
                if (pq.size() > ladders)
                {
                    sum += pq.top();
                    pq.pop();
                }
                if (sum > bricks)
                    return i - 1;
            }
        }
        return n - 1;
    }
};


// Solution 2 using Multiset (worse than priority queue)
// Time complexity: O(nlogk)
// Space complexity: O(k)

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size(), sum = 0;
        multiset<int> ms;
        for (int i = 1; i < n; i++){
            int diff = heights[i] - heights[i - 1];
            if (diff > 0){
                ms.insert(diff);
                if (ms.size() > ladders){
                    sum += *ms.begin();
                    ms.erase(ms.begin());
                }
                if (sum > bricks)
                    return i - 1;
            }
        }
        return n - 1;
    }
};