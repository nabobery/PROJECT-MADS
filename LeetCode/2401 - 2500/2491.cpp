// 2491. Divide Players Into Teams of Equal Skill

// Solution 1 using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0, n = skill.size();
        long long res = 0;
        for(int s : skill) sum += s;
        if(sum % (n/2)) return -1;
        sort(skill.begin(), skill.end());
        int ts = sum/(n/2);
        for(int l = 0; l < n/2;l++){
            if(skill[l] + skill[n-l-1] == ts) res += skill[l]*skill[n-l-1];
            else return -1;
        }
        return res;
    }
};