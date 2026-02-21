// 401. Binary Watch

// Solution 1: Going through all possible times and counting the bits
// Time Complexity: O(1) since we are only checking a fixed number of times (12 hours * 60 minutes = 720)
// Space Complexity: O(1) for the result vector, as it can contain at most 720 entries
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn > 9) return {};

        vector<string> result;
        vector<int> hourBits(12);
        vector<int> minuteBits(60);

        for (int i = 0; i < 12; ++i) {
            hourBits[i] = __builtin_popcount(i);
        }

        for (int i = 0; i < 60; ++i) {
            minuteBits[i] = __builtin_popcount(i);
        }

        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (hourBits[h] + minuteBits[m] == turnedOn) {
                    string time = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    result.push_back(time);
                }
            }
        }

        return result;
    }
};

// Solution 2: Using buckets to group hours and minutes by their bit counts
// Time Complexity: O(1) since we are only checking a fixed number of times 
// Space Complexity: O(1) for the result vector, as it can contain at most
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn > 9) return {};

        vector<vector<int>> hBuckets(4); 
        for (int h = 0; h < 12; ++h) {
            hBuckets[__builtin_popcount(h)].push_back(h);
        }

        vector<vector<int>> mBuckets(6);
        for (int m = 0; m < 60; ++m) {
            mBuckets[__builtin_popcount(m)].push_back(m);
        }

        vector<string> result;
        for (int hBits = 0; hBits <= 3; ++hBits) {
            for (int mBits = 0; mBits <= 5; ++mBits) {
                if (hBits + mBits == turnedOn) {
                    for (int h : hBuckets[hBits]) {
                        for (int m : mBuckets[mBits]) {
                            result.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                        }
                    }
                }
            }
        }

        return result;
    }
};