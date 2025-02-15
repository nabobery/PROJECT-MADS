// 2698. Find the Punishment Number of an Integer

// Solution 1: Brute Force
// Time Complexity: O(n * 2^log10(n^2))
// Space Complexity: O(1)
unordered_map<int,bool> isPunishable; // global caching
class Solution {
    public:
        // unordered_map<int,bool> isPunishable;
        bool punishable(string& num, int ind, vector<string>& currParts, int& origNum){
            if(ind == num.size()){
                int partSum = 0;
                for(auto& part: currParts)
                    partSum += stoi(part);
                return partSum == origNum;
            }
            for(int i = ind; i < num.size();i++){
                string part = num.substr(ind, i - ind+1);
                currParts.push_back(part);
                if(punishable(num, i+1, currParts, origNum)) return true;
                currParts.pop_back();
            }
            return false;
        }
        int punishmentNumber(int n) {
            int res = 0;
            for(int i = 1; i <= n;i++){
                int sq = i*i;
                if(!isPunishable.count(i)){
                    vector<string> parts;
                    string num = to_string(sq);
                    isPunishable[i] = punishable(num, 0, parts, i);
                }
                if(isPunishable[i]) res += sq;
            }
            return res;
        }
    };