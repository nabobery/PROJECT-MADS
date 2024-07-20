// 726. Number of Atoms

// Solution 1: Stack and Map
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> mp;
        int i = 0, n = formula.size();
        while (i < n) {
            if (formula[i] == '(') {
                stk.push(mp);
                mp.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int j = i;
                while (j < n && isdigit(formula[j])) {
                    j++;
                }
                int count = (i == j) ? 1 : stoi(formula.substr(i, j - i));
                i = j;
                for (auto& [atom, val] : mp) {
                    stk.top()[atom] += val * count;
                }
                mp = stk.top();
                stk.pop();
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) {
                    j++;
                }
                string atom = formula.substr(i, j - i);
                i = j;
                j = i;
                while (j < n && isdigit(formula[j])) {
                    j++;
                }
                int count = (i == j) ? 1 : stoi(formula.substr(i, j - i));
                i = j;
                mp[atom] += count;
            }
        }
        string res;
        for (auto& [atom, val] : mp) {
            res += atom;
            if (val > 1) {
                res += to_string(val);
            }
        }
        return res;
    }
};

// Solution 2: Using Map and Recursion
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.size();
        map<string, int> mp = parse(formula, i, n);
        string res;
        for (auto& [atom, val] : mp) {
            res += atom;
            if (val > 1) {
                res += to_string(val);
            }
        }
        return res;
    }
    
    map<string, int> parse(string& formula, int& i, int n) {
        map<string, int> mp;
        while (i < n && formula[i] != ')') {
            if (formula[i] == '(') {
                i++;
                for (auto& [atom, val] : parse(formula, i, n)) {
                    mp[atom] += val;
                }
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) {
                    j++;
                }
                string atom = formula.substr(i, j - i);
                i = j;
                j = i;
                while (j < n && isdigit(formula[j])) {
                    j++;
                }
                int count = (i == j) ? 1 : stoi(formula.substr(i, j - i));
                i = j;
                mp[atom] += count;
            }
        }
        i++;
        int j = i;
        while (j < n && isdigit(formula[j])) {
            j++;
        }
        int count = (i == j) ? 1 : stoi(formula.substr(i, j - i));
        i = j;
        for (auto& [atom, val] : mp) {
            mp[atom] = val * count;
        }
        return mp;
    }
};