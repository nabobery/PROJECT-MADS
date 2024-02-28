// 433. Minimum Genetic Mutation

// Solution 1 using BFS and Hashset
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    const char choices[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> visited(bank.begin(), bank.end());
        bool b = false;
        int res = 0;
        queue<string> q;
        q.push(startGene);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                if(curr == endGene){
                    b = true;
                    break;
                }
                visited.erase(curr);
                for(int i = 0; i < 8;i++){
                    string temp = curr;
                    for(char choice : choices){
                        temp[i] = choice;
                        if(visited.count(temp)) q.push(temp);
                    }
                }
            }
            if(b) break;
            res++;
        }
        return (b ? res : -1);
    }
};
