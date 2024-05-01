// 752. Open the Lock

// Solution 1 using BFS
// Time complexity: O(10^4)
// Space complexity: O(10^4)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends(deadends.begin(), deadends.end()), visited;
        string start = "0000";
        queue<string> q;
        q.push(start);
        int steps = 0;
        visited.insert(start);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                string curr = q.front();
                if(curr == target) return steps;
                q.pop();
                if(!ends.count(curr)){
                    string temp = curr;
                    for(int i = 0; i < 8;i++){
                        if(i/4){
                            temp[i%4] = ((temp[i%4] - '0')+1)%10 + '0';
                            if(!visited.count(temp) && !ends.count(temp)){
                                visited.insert(temp);
                                q.push(temp);
                            }
                        }
                        else{
                            temp[i%4] = ((temp[i%4] - '0')+9)%10 + '0';
                            if(!visited.count(temp) && !ends.count(temp)){
                                visited.insert(temp);
                                q.push(temp);
                            }
                        }
                        temp = curr;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};



