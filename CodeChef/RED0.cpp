#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    long long int x,y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        long long int result = 0;
        if(x == y) cout<<x<<"\n";
        else{
            if(x == 0 || y == 0) cout<<"-1\n";
            else{
                if(x > y){
                    swap(x,y);
                }
                if(x < y - x){
                    while(x < y - x){
                        x *= 2;
                        result++;
                    }
                }
                result += (y+1);
                cout<<result<<"\n";
            }
        }
    }
	return 0;
}
