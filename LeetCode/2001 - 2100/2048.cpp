// 2048. Next Greater Numerically Balanced Number

// Solution 1: Using Precomputation, Math and Set lookup
// Time Complexity: O(1) amortized (due to precomputation and set lookup)
// Space Complexity: O(1) amortized (due to precomputation and set storage)
// 1 -> 1
// 2 -> 22
// 3 -> 122 (3 p), 333
// 4 -> 1333 (4p), 4444
// 5 -> 14444( 5 permutations) , 22333 (10 permutations), 55555 (1)
// 6 -> 122333 (60 p), 155555 (6 p), 224444 (15 p), 666666 (1)
// 7 -> 1224444 (1p)
class Solution {
public:
    vector<string> startVector = {
        "1",      // N=1
        "22",     // N=2
        "122",    // N=3
        "333",    // N=3
        "1333",   // N=4
        "4444",   // N=4
        "14444",  // N=5
        "22333",  // N=5
        "55555",  // N=5
        "122333", // N=6
        "155555", // N=6
        "224444", // N=6
        "666666"  // N=6
    };
    int largest = 1224444; // N = 7
    set<int> balancedNumbers;
    void generate() {
        if (!balancedNumbers.empty())
            return;
        for (string num : startVector) {
            do {
                balancedNumbers.insert(stoi(num));
            } while (next_permutation(num.begin(), num.end()));
        }
    }
    int nextBeautifulNumber(int n) {
        generate();
        auto it = balancedNumbers.upper_bound(n);
        return it != balancedNumbers.end() ? *it : largest;
    }
};