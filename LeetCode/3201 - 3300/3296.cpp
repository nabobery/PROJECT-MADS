// 3296. Minimum Number of Seconds to Make Mountain Height Zero

// Solution 1: Using Priority Queue and Greedy
// Time Complexity: O(h log n)
// Space Complexity: O(n)
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> countMap(workerTimes.size(), 0);
        long long maxTime = 0;

        for (int i = 0; i < (int)workerTimes.size(); ++i) {
            pq.push({(long long)workerTimes[i], i});
        }

        while (mountainHeight > 0) {
            auto [finishTime, idx] = pq.top();
            pq.pop();

            countMap[idx]++;
            mountainHeight--;
            maxTime = finishTime;

            if (mountainHeight == 0)
                break;

            long long nextUnit = countMap[idx] + 1;
            long long nextFinishTime = finishTime + (nextUnit * workerTimes[idx]);
            pq.push({nextFinishTime, idx});
        }

        return maxTime;
    }
};

// Solution 2: Using Binary Search
// Time Complexity: O(n log (h * max(workerTimes)))
// Space Complexity: O(1)
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 1, r = 1e18, res = r;
        auto check = [&](long long mid) {
            long long totalHeight = 0;
            for (int w : workerTimes) {
                totalHeight += (-1 + sqrt(1 + 8.0 * mid / w)) / 2;
                if (totalHeight >= mountainHeight) return true;
            }
            return totalHeight >= mountainHeight;
        };

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};