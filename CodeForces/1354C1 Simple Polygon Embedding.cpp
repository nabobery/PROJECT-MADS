#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// we rotate the figure such that many of its sides are parallel to sides of the square
// we know that if we draw an arc from the center to the 2 vertices of an edge, we subtend an angle of 2*pi/2*n => theta = pi/n
// we also know that side length is 1 and we also know that distance between 2 parallel sides is equal to side of the square
// therefore tan(theta/2) = (1/2) / x where x is distance from one side to center. Therefore 2*x is required side of square
// 2*x = result = 1/tan(pi/2*n)
void solve(){
    int n;
    cin >> n;
    cout<<fixed;
    double result = tan(M_PI/(2*n));
    result = 1.0/result;
    cout<<setprecision(9)<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}



