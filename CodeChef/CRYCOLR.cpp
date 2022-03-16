#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t,n;
	cin >> t;
	int grid[3][3];
	for(int i = 0; i < t;i++){
	    cin >> n;
	    for(int j = 0; j < 3;j++){
	        for(int k = 0; k < 3;k++){
	            cin >> grid[j][k];
	        }
	    }
        int result = 0,k;
        for(int j = 0; j < 3;j++){
            k = (j+1)%3;
            int temp = min(grid[j][k],grid[k][j]);
            if(temp == 0){
                continue;
            }
            grid[j][j] += temp;
            grid[k][k] += temp;
            result += temp;
            grid[j][k] -= temp;
            grid[k][j] -= temp;
        }
        result += 2*(n - grid[0][0]);
        cout<<result<<"\n";
	}
	return 0;
}
