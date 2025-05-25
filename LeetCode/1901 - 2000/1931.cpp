// 1931. Painting a Grid With Three Different Colors

// Solution 1 using Dynamic Programming
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    using State = vector<int>;
    const int mod = 1e9 + 7;
    bool isValidState(const State& state) {
        for (int i = 0; i < state.size() - 1; ++i) {
            if (state[i] == state[i + 1])
                return false;
        }
        return true;
    }
    bool isValidTransition(const State& a, const State& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i])
                return false;
        }
        return true;
    }
    void generateStates(int length, State& current,
                        vector<State>& validStates) {
        if (current.size() == length) {
            if (isValidState(current))
                validStates.push_back(current);
            return;
        }

        for (int i = 0; i < 3; ++i) {
            current.push_back(i);
            generateStates(length, current, validStates);
            current.pop_back();
        }
    }
    int colorTheGrid(int m, int n) {
        long res = 0;
        vector<State> validStates;
        State temp;
        map<State, vector<State>> adjacencyMap;
        generateStates(m, temp, validStates);
        map<State, int> curr, prev;
        for (const auto& state : validStates)
            prev[state] = 1;
        curr = prev;
        for (const auto& from : validStates) {
            for (const auto& to : validStates) {
                if (from == to)
                    continue;
                if (isValidTransition(from, to)) {
                    adjacencyMap[from].push_back(to);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (auto& it : curr)
                it.second = 0;
            for (const auto& state : validStates) {
                for (const auto& nextState : adjacencyMap[state]) {
                    curr[nextState] =
                        ((long)curr[nextState] + prev[state]) % mod;
                }
            }
            prev = curr;
        }
        for (auto& it : curr)
            res = (res + it.second) % mod;
        return res;
    }
};

// Optimized Solution by using index of valid states
class Solution {
public:
    using State = vector<int>;
    const int mod = 1e9 + 7;

    bool isValidState(const State& state) {
        for (int i = 1; i < state.size(); ++i)
            if (state[i] == state[i - 1]) return false;
        return true;
    }

    bool isValidTransition(const State& a, const State& b) {
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == b[i]) return false;
        return true;
    }

    void generateStates(int length, State& current, vector<State>& validStates) {
        if (current.size() == length) {
            if (isValidState(current)) validStates.push_back(current);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            current.push_back(i);
            generateStates(length, current, validStates);
            current.pop_back();
        }
    }

    int colorTheGrid(int m, int n) {
        vector<State> validStates;
        State temp;
        generateStates(m, temp, validStates);
        int sz = validStates.size();
        vector<vector<int>> transitions(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (isValidTransition(validStates[i], validStates[j])) {
                    transitions[i].push_back(j);
                }
            }
        }
        vector<int> dp(sz, 1), new_dp(sz);
        for (int col = 1; col < n; ++col) {
            fill(new_dp.begin(), new_dp.end(), 0);
            for (int i = 0; i < sz; ++i) {
                for (int j : transitions[i]) {
                    new_dp[j] = (new_dp[j] + dp[i]) % mod;
                }
            }
            dp.swap(new_dp);
        }
        int res = 0;
        for (int count : dp) res = (res + count) % mod;
        return res;
    }
};

