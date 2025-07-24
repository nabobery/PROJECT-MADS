// 3170. Lexicographically Minimum String After Removing Stars

// Solution: Using a Set to Track Characters and Their Indices
// Time Complexity: O(nlogn) where n is the length of the string
// Space Complexity: O(n) for the set to store characters and their indices

class Solution {
public:
    string clearStars(string s) {
        string res;
        // Aim is to delete the smallest chracters that appear the latest for smaller lexicographical order
        set<pair<int,int>> st;
        for(int i = 0; i < s.size();i++){
            if(s[i] == '*'){
                if(!st.empty()){
                    auto it = *st.begin();
                    st.erase(it);
                }
            }
            else st.insert({s[i], -i});
        }
        for(int i = 0; i < s.size();i++)
            if(st.count({s[i], - i})) res += s[i];
        return res;
    }
};