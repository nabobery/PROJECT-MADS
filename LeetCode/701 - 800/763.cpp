// 763. Partition Labels
// Greedy O(n) time and O(1) space solution
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map <char,int> last;
        for(int i = 0; i < n;i++){
            last[s[i]] = i;
        }
        vector<int> result;
        int temp = last[s[0]], index = 0;
        for(int i = 1; i < n;i++){
            if(last[s[i]] < temp){
                continue;
            }
            else{
                result.push_back(last[s[i]] - index + 1);
                i = last[s[i]] + 1;
                index = i;
                temp = last[s[i]];
            }
        }
        return result;
    }
};

