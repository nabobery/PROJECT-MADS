// 1665. Minimum Initial Energy to Finish Tasks

// Solution 1: Greedy and Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks based on the difference between minimum energy and actual energy required
        // so that we can prioritize tasks that require more energy upfront
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });
        
        // totalRequired keeps track of the total initial energy required
        int totalRequired = 0, currentEnergy = 0;
        
        // Iterate through the sorted tasks and calculate the total initial energy required
        for (const auto& task : tasks) {
            // actual is the energy required to complete the task, minimum is the minimum energy required to start the task
            int actual = task[0], minimum = task[1];

            // if current energy is less than the minimum required to start the task, we need to increase totalRequired
            if (currentEnergy < minimum) {
                // Increase totalRequired by the difference between minimum and currentEnergy
                totalRequired += (minimum - currentEnergy);
                // Update currentEnergy to the minimum required for the task
                currentEnergy = minimum;
            }
            // After completing the task, decrease currentEnergy by the actual energy required
            currentEnergy -= actual;
        }
        // Return the total initial energy required to complete all tasks
        return totalRequired;
    }
};