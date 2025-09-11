// 1733. Minimum Number of People to Teach

// Solution 1: Using Brute Force + Greedy
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(), res = m;
        // to keep track of which users speak which languages
        vector<vector<bool>> userLangs(m, vector<bool>(n, false));
        // to keep track of users who cannot communicate with their friends
        unordered_set<int> cantCommunicate;
        for(int i = 0; i < m;i++){
            for(auto& l : languages[i]) userLangs[i][l-1] = true;
        }
        // find all users who cannot communicate with their friends
        for(auto& friendship : friendships){
            int f1 = friendship[0]-1, f2 = friendship[1] - 1;
            bool b = false;
            // check if they have a common language
            for(int i = 0; i < n;i++){
                if(userLangs[f1][i] && userLangs[f2][i]) {
                    b = true;
                    break;
                }
            }
            if(!b){
                cantCommunicate.insert(f1);
                cantCommunicate.insert(f2);
            }
        }
        // go through all languages to check if we can pick a language and teach them to people who can't communicate
        // so that they can understand each other
        for(int i = 0; i < n;i++){
            int curr = 0;
            // count how many users need to learn this language
            for(auto& it : cantCommunicate){
                if(!userLangs[it][i]) curr++;
            }
            // find the minimum number of users to teach a language so that they can communicate with their friends
            res = min(res, curr);
        }
        return res;
    }
};