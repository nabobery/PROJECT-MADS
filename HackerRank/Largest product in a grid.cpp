// Project Euler #11: Largest product in a grid

#include <bits/stdc++.h>
using namespace std;

// Working Solution
int main(){
    vector< vector<int> > grid(20,vector<int>(20));
    for(int grid_i = 0;grid_i < 20;grid_i++){
    	for(int grid_j = 0;grid_j < 20;grid_j++){
    		cin >> grid[grid_i][grid_j];
    	}
    }
    int result = 0;
    // adjacent left and right
    for(int i = 0; i < 20;i++){
        for(int j = 0; j < 17;j++){
            int curr = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
            result = max(curr, result);
        }
    }
    // adjacent up and down
    for(int i = 0; i < 17;i++){
        for(int j = 0; j < 20;j++){
            int curr = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
            result = max(curr, result);
        }
    }
    // minor diagonal
    for(int i = 3; i < 20;i++){
        for(int j = 0; j < 17;j++){
            int curr = grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3];
            result = max(curr, result);
        }
    }
    // major diagonal
    for(int i = 0; i < 17;i++){
        for(int j = 0; j < 17;j++){
            int curr = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
            result = max(curr, result);
        }
    }
    cout<<result<<"\n";
    return 0;
}



// solution failed
// int main(){
//     vector< vector<int> > grid(20,vector<int>(20));
//     for(int grid_i = 0;grid_i < 20;grid_i++){
//     	for(int grid_j = 0;grid_j < 20;grid_j++){
//     		cin >> grid[grid_i][grid_j];
//     	}
//     }
//     int result = 0;
//     // adjacent right left
//     for(int i = 0; i < 20;i++){
//         int curr = 1;
//         multiset<int> vis;
//         for(int j = 0; j < 4;j++){
//             vis.insert(grid[i][j]);
//         }
//         if(!vis.count(0)){
//             for(auto it : vis) curr *= it;
//             result = max(curr, result);
//         }
//         for(int j = 4; j < 20;j++){
//             vis.erase(vis.find(grid[i][j-4]));
//             vis.insert(grid[i][j]);
//             if(!vis.count(0)){
//                 curr = 1;
//                 for(auto it : vis) curr *= it;
//                 result = max(curr, result);
//             }
//         }
//     }
//     // adjacent up down
//     for(int j = 0; j < 20;j++){
//         int curr = 1;
//         multiset<int> vis;
//         for(int i = 0; i < 4;i++){
//             vis.insert(grid[i][j]);
//         }
//         if(!vis.count(0)){
//             for(auto it : vis) curr *= it;
//             result = max(curr, result);
//         }
//         for(int i = 4; i < 20;i++){
//             vis.erase(vis.find(grid[i-4][j]));
//             vis.insert(grid[i][j]);
//             if(!vis.count(0)){
//                 curr = 1;
//                 for(auto it : vis) curr *= it;
//                 result = max(curr, result);
//             }
//             //cout<<i<<" "<<j<<"\n";
//         }
//     }
//     // adjacent diagonal /(minor diagonal)
//     for(int k = 3; k < 20;k++){
//         int i  = 0, j = k;
//         deque<int> vis;
//         while(j >= 0){
//             if(vis.size() == 4) vis.pop_front();
//             vis.push_back(grid[i][j]);
//             if(vis.size() == 4){
//                 int curr = 1;
//                 for(auto it : vis) curr *= it;
//                 result = max(curr, result);
//             }
//             i++,j--;
//         }
//     }
//     for (int j = 1; j < 20; j++) {
//         int col = 19, row = j;
//         deque<int> vis;
//         while (row < 20) {
//             if(vis.size() == 4) vis.pop_front();
//             vis.push_back(grid[row][col]);
//             if(vis.size() == 4){
//                 int curr = 1;
//                 for(auto it : vis) curr *= it;
//                 result = max(curr, result);
//             }
//             row++, col--;
//         }
//     }
//     // adjacent diagonal  \ (major diagonal)
//     for(int k = 3; k < 20;k++){
//         int i  = 19, j = k;
//         deque<int> vis;
//         while(j >= 0){
//             if(vis.size() == 4) vis.pop_front();
//             vis.push_back(grid[i][j]);
//             if(vis.size() == 4){
//                 int curr = 1;
//                 for(auto it : vis) curr *= it;
//                 result = max(curr, result);
//             }
//             i--,j--;
//         }
//     }
//     for(int i = 18; i >= 3;i--){
//         int j = 19;
//         deque<int> vis;
//         while(i >= 0){
//             if(vis.size() == 4) vis.pop_front();
//             vis.push_back(grid[i][j]);
//             if(vis.size() == 4){
//                 int curr = 1;
//                 for(auto it : vis) curr *= it;
//                 result = max(curr, result);
//             }
//             i--,j--;
//         }
//     }
//     cout<<result<<"\n";
//     return 0;
// }

