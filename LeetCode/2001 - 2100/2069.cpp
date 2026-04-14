// 2069. Walking Robot Simulation II

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

// Solution 1: Simulation with Modulo Arithmetic
// because the robot moves in a loop around the perimeter, we can use modulo arithmetic to determine its position and direction after a given number of steps. We calculate the total perimeter of the rectangle and use the current distance traveled to determine the robot's position and direction.
// Time Complexity: O(1) for each method call
// Space Complexity: O(1) 
class Robot {
private:
    int w, h, perimeter;
    int currentDist = 0;
    bool hasMoved = false;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
    }

    void step(int num) {
        hasMoved = true;
        currentDist = (currentDist + num) % perimeter;
    }

    vector<int> getPos() {
        int d = currentDist;
        // The robot starts at (0, 0) and moves in the following order: East, North, West, South.
        //  We can determine the position based on the distance traveled along the perimeter.
        // 1. If d < w, the robot is moving East along the bottom edge.
        if (d < w)
            return {d, 0};
        // 2. If d < w + h - 1, the robot is moving North along the right edge.
        if (d < w + h - 1)
            return {w - 1, d - (w - 1)};
        // 3. If d < 2 * w + h - 2, the robot is moving West along the top edge.
        if (d < 2 * w + h - 2)
            return {w - 1 - (d - (w + h - 2)), h - 1};
        // 4. Otherwise, the robot is moving South along the left edge.
        return {0, h - 1 - (d - (2 * w + h - 3))};
    }

    string getDir() {
        // The direction can be determined based on the current distance traveled along the perimeter.
        if (currentDist == 0)
            // If the robot has not moved, it is facing East. If it has moved, it is facing South because it would have completed a full loop and returned to the starting point.
            return hasMoved ? "South" : "East";

        int d = currentDist;
        if (d > 0 && d < w)
            return "East";
        if (d >= w && d < w + h - 1)
            return "North";
        if (d >= w + h - 1 && d < 2 * w + h - 2)
            return "West";
        return "South";
    }
};
