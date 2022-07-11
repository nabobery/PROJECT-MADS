#include <iostream>

using namespace std;

int main() {
    int t,maxT,maxN,sumN;
    cin >> t;
    long long int result;
    while(t--){
        cin >> maxT >> maxN >> sumN;
        double temp = sumN;
        temp /= maxN;
        if(maxT >= temp){
            result = maxN * maxN;
            result *= (int)temp;
            result += (sumN%maxN) * (sumN%maxN);
        }
        else{
            result = maxN * maxN;
            result *= maxT;
        }
        cout<<result<<"\n";
    }
	return 0;
}
