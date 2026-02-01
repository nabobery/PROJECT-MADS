// 2975. Maximum Square Area by Removing Fences From a Field

// Solution 1: Using Sorting, Hash Set and checking all horizontal and vertical gaps and calculating the maximum square area
// Time Complexity: O(H^2 + V^2 + H log H + V log V + H * V)
// Space Complexity: O(H + V)
class Solution {
public:
    const int mod = 1e9 + 7;

    unordered_set<int> getAllDistances(int limit, vector<int>& fences) {
        fences.push_back(1);
        fences.push_back(limit);
        sort(fences.begin(), fences.end());

        unordered_set<int> distances;
        for (int i = 0; i < fences.size(); ++i) {
            for (int j = i + 1; j < fences.size(); ++j) {
                distances.insert(fences[j] - fences[i]);
            }
        }
        return distances;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> hDistances = getAllDistances(m, hFences);
        unordered_set<int> vDistances = getAllDistances(n, vFences);

        long long maxSide = -1;

        for (int d : hDistances) {
            if (vDistances.count(d)) {
                maxSide = max(maxSide, (long long)d);
            }
        }

        if (maxSide == -1) return -1;
        return (maxSide * maxSide) % mod;
    }
};

// Solution 2: Using Two Pointer Technique to find maximum square area
// Time Complexity: O(H log H + V log V + H^2 + V^2 + H + V)
// Space Complexity: O(H + V)
class Solution {
public:
    const int mod = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto getDistances = [](int limit, vector<int>& fences) {
            fences.push_back(1);
            fences.push_back(limit);
            sort(fences.begin(), fences.end());
            
            vector<int> dists;
            dists.reserve((fences.size() * fences.size()) / 2);
            for (int i = 0; i < fences.size(); ++i) {
                for (int j = i + 1; j < fences.size(); ++j) {
                    dists.push_back(fences[j] - fences[i]);
                }
            }
            sort(dists.begin(), dists.end());
            return dists;
        };
        vector<int> hDists = getDistances(m, hFences), vDists = getDistances(n, vFences);
        long long maxSide = -1;
        int i = hDists.size() - 1, j = vDists.size() - 1;
        while (i >= 0 && j >= 0) {
            if (hDists[i] == vDists[j]) {
                maxSide = hDists[i];
                break; 
            } else if (hDists[i] > vDists[j]) {
                i--;
            } else {
                j--;
            }
        }

        return maxSide == -1 ? -1 : (maxSide * maxSide) % mod;
    }
};