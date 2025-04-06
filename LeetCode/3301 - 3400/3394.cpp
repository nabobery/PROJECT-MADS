// 3394. Check if Grid can be Cut into Sections

// Solution 1: By Sorting and then checking if the number of necessary merged directions is greater than 2
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            int index = 0, l = rectangles.size();
            vector<vector<int>> xdirections(l), ydirections(l);
            for(int i = 0; i < l;i++){
                int startx = rectangles[i][0], starty = rectangles[i][1], endx = rectangles[i][2], endy = rectangles[i][3];
                xdirections[i] = {startx, endx};
                ydirections[i] = {starty, endy};
            }
            sort(xdirections.begin(), xdirections.end());
            for(int i = 1; i < l;i++){
                if(xdirections[index][1] > xdirections[i][0]) xdirections[index][1] = max(xdirections[i][1], xdirections[index][1]); 
                else{
                    index++;
                    if(index >= 2) return true;
                    xdirections[index] = xdirections[i];
                }
            }
            index = 0;
            sort(ydirections.begin(), ydirections.end());
            for(int i = 1; i < l;i++){
                if(ydirections[index][1] > ydirections[i][0]) ydirections[index][1] = max(ydirections[i][1], ydirections[index][1]); 
                else{
                    index++;
                    if(index >= 2) return true;
                    ydirections[index] = ydirections[i];
                }
            }
            return false;
        }
    };