// 767. Reorganize String

// Solution using priority queue and alternate placing of most common characters
// Time complexity: O(nlog26) = O(n) and Space complexity: O(26) = O(1) 
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        for(auto ch : s) count[ch -'a']++;
        int ma = 0;
        for(auto i : count){
            ma = max(i, ma);
        }
        string result;
        if(2*ma - 1 > s.size()) return result;
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i < 26;i++){
            if(count[i]) pq.push({count[i], i + 'a'});
        }
        pair<char,int> p = pq.top();
        pq.pop();
        while(!pq.empty()){
            if(p.first != 0){
                auto temp = pq.top();
                pq.pop();
                result += p.second;
                result += temp.second;
                p.first--;
                temp.first--;
                if(temp.first != 0) pq.push(temp);
            }
            else{
                p = pq.top();
                pq.pop();
            }
        }
        if(p.first != 0) result += p.second;
        return result;
    }
};

// Solution by keeping characters in even and odd positions
// Time complexity: O(n) and Space complexity: O(26) = O(1)
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        for(auto ch : s) count[ch -'a']++;
        int ma = 0;
        char ch = 'a';
        for(int i = 0; i < 26;i++){
            if(count[i] > ma){
                ma = count[i];
                ch = i + 'a';
            }
        }
        if(2*ma - 1 > s.size()) return "";
        string result(s.size(), 'a');
        int ind = 0;
        while(count[ch - 'a'] != 0){
            result[ind] = ch;
            ind += 2;
            count[ch-'a']--;
        }
        for(int i = 0; i < 26;i++){
            while(count[i] > 0){
                if(ind >= s.size()){
                    ind = 1;
                }
                result[ind] = i + 'a';
                ind += 2;
                count[i]--;
            }
        }
        return result;
    }
};