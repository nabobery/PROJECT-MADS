#include <iostream>

using namespace std;

int main() {
    int t,n,x;
    cin >> t;
    while(t--){
       cin >> n;
       cin >> x;
       int t1 = x, t2 = 2*x;
       for(int i = 2; i < n;i++){
           cin >> x;
           if(t1 + x >= t2){
               t2 += (t1 + x - t2);
               t2 += x;
               t1 += x;
           }
           else{
               t1 += x;
               t2 += x;
           }
       }
       cout<<t2<<"\n";
    }
	return 0;
}
