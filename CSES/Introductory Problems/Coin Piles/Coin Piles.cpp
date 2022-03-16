// Introductory Problems : Coin Piles
#include "iostream"
using namespace std;

int main(){
    int t,a,b;
    cin >> t;
    for(int i = 0; i < t;i++){
        cin >> a >> b;
        if(a == 0 && b == 0){
            cout<<"YES\n";
        }
        else if(a != 0 && b != 0){
            if((a+b)%3 == 0){
                if(2*b >= a && 2*a >= b){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
