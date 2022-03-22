// 763. Partition Labels
// Greedy O(n) time and O(1) space solution
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[26] = {0};
        for(int i = 0; i < n;i++){
            last[s[i] - 'a'] = i;
        }
        vector<int> result;
        int temp = 0, index = 0;
        for(int i = 0; i < n;i++){
            temp = max(temp, last[s[i] - 'a']);
            if(temp == i){
                result.push_back(i - index + 1);
                index = i + 1;
            }
        }
        return result;
    }
};

