// 3494. Find the Minimum Amount of Time to Brew Potions

// Solution: Prefix Sum + Dynamic Programming
// Time Complexity: O(n*m)
// Space Complexity: O(n)
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        // now: the time at the current step
        long long now = 0;
        // f[j]: the time at which the jth wizard finishes brewing their potion step
        vector<long long> f(n, 0);
        for(int i = 0; i < m;i++){
            // initialize now for the current iteration with f[0] from the previous iteration
            // f[0] is the time at which the first wizard finishes brewing their potion step
            now = f[0];
            // currMana: the mana of the current wizard
            int currMana = mana[i];
            // update now for j from 1 to n-1 (forward)
            // now = max of (now + skill[j-1]*currMana, f[j])
            // where f[j] is the time at which the jth wizard finishes brewing their potion step
            // skill[j-1]*currMana is the time taken by the (j-1)th wizard to brew their potion step
            // so now + skill[j-1]*currMana is the time at which the jth wizard can start brewing their potion step
            // we take the max of these two values to ensure that the jth wizard starts brewing their potion step only after the (j-1)th wizard has finished
            // this helps us start the brewing process as early as possible while ensuring that the wizards brew their potions in the correct order
            for(int j = 1; j < n;j++)
                now = max(now + skill[j-1]*currMana, f[j]);
            // the final potion brew step completion time is now plus the time taken by the last wizard
            f[n-1] = now + skill[n - 1]*currMana;
            // update f[j] for j from n-2 to 0 (backward)
            for(int j = n-2; j >= 0;j--)
                f[j] = f[j+1] - skill[j+1]*currMana;
        }
        // return the minimum time to brew all potions
        return f[n-1];
    }
};
