// 3661. Maximum Walls Destroyed by Robots

// Solution 1: Using Sorting, Binary Search, and Dynamic Programming
// Time Complexity: O(n log n + m log m) where n is the number of robots and m is the number of walls
// Space Complexity: O(n) for the dp array
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int numRobots = robots.size();
        
        // Pair each robot's position with its distance and sort by position
        vector<pair<int, int>> sortedRobots(numRobots);
        for (int i = 0; i < numRobots; ++i) {
            sortedRobots[i] = {robots[i], distance[i]};
        }
        // Sort robots by their positions and walls by their positions
        sort(sortedRobots.begin(), sortedRobots.end());
        sort(walls.begin(), walls.end());

        // Helper function to count how many walls are in the range [low, high] using binary search
        auto countWallsInRange = [&](long long low, long long high) {
            if (low > high)
                return 0;
            auto lower = lower_bound(walls.begin(), walls.end(), (int)low);
            auto upper = upper_bound(walls.begin(), walls.end(), (int)high);
            return (int)(upper - lower);
        };

        // dp[i][0] = max walls destroyed if the i-th robot fires to the left
        // dp[i][1] = max walls destroyed if the i-th robot fires to the right
        vector<vector<int>> dp(numRobots, vector<int>(2, 0));

        // Initialize dp for the first robot
        long long firstPos = sortedRobots[0].first;
        long long firstDist = sortedRobots[0].second;
        
        // For the first robot, calculate walls destroyed if it fires to the left and right
        dp[0][0] = countWallsInRange(firstPos - firstDist, firstPos);

        long long rightBoundary =
            (numRobots > 1) ? sortedRobots[1].first : 3000000000LL;
        dp[0][1] = countWallsInRange(firstPos,
                                     min(firstPos + firstDist, rightBoundary));
        
        // Fill the dp table for subsequent robots
        for (int i = 1; i < numRobots; ++i) {
            long long currPos = sortedRobots[i].first;
            long long currDist = sortedRobots[i].second;
            long long prevPos = sortedRobots[i - 1].first;
            long long prevDist = sortedRobots[i - 1].second;

            // Calculate walls destroyed if the current robot fires to the left
            long long leftFireStart = max(prevPos, currPos - currDist);
            int wallsFromLeftFire = countWallsInRange(leftFireStart, currPos);

            long long nextRobotPos = (i + 1 < numRobots)
                                         ? (long long)sortedRobots[i + 1].first
                                         : 3000000000LL;
            long long rightFireEnd = min(currPos + currDist, nextRobotPos);
            // Calculate walls destroyed if the current robot fires to the right
            int wallsFromRightFire = countWallsInRange(currPos, rightFireEnd);

            // Calculate overlaps to avoid double counting walls destroyed by consecutive robots
            // if the previous robot's right fire overlaps with the current robot's left fire, count the overlap
            int overlapPrevRightCurrLeft = countWallsInRange(
                leftFireStart, min(currPos, prevPos + prevDist));
            // If the current robot's left fire overlaps with the previous robot's left fire, count the overlap
            // The overlap occurs when current robot's left range extends past the previous robot's position
            // We check if there's a wall at prevPos (the boundary) to avoid double-counting
            int overlapPrevLeftCurrLeft =
                (currPos - currDist <= prevPos)
                    ? countWallsInRange(prevPos, prevPos)
                    : 0;
            // If the current robot's right fire overlaps with the previous robot's right fire, count the overlap
            // The overlap occurs when the previous robot's right range extends past the current robot's position
            // We check if there's a wall at currPos (the boundary) to avoid double-counting
            int overlapPrevRightCurrRight =
                (prevPos + prevDist >= currPos)
                    ? countWallsInRange(currPos, currPos)
                    : 0;
            
            // Update dp for the current robot based on the previous robot's choices and the walls destroyed by firing left or right
            // If the current robot fires to the left, it can either follow the previous robot's left fire or right fire, but we need to subtract the overlaps to avoid double counting
            dp[i][0] = max(
                dp[i - 1][0] + wallsFromLeftFire - overlapPrevLeftCurrLeft,
                dp[i - 1][1] + wallsFromLeftFire - overlapPrevRightCurrLeft);

            // If the current robot fires to the right, it can either follow the previous robot's left fire or right fire, but we need to subtract the overlaps to avoid double counting
            dp[i][1] = max(dp[i - 1][0] + wallsFromRightFire,
                           dp[i - 1][1] + wallsFromRightFire -
                               overlapPrevRightCurrRight);
        }
        // The answer is the maximum walls destroyed by the last robot firing either left or right
        return max(dp[numRobots - 1][0], dp[numRobots - 1][1]);
    }
};