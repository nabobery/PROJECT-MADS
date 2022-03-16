//Introductory Problems : Number Spiral
#include "iostream"
using namespace std;

int main(){
    int t;
    cin >> t;
    int y, x;
    long long int result;
    for(int i = 0; i < t;i++){
        cin >> y >> x;
        if(x == 1 && y == 1){
            cout<<1<<"\n";
        }
        else if(x == 1 || y == 1){
            if(y == 1){
                if(x % 2 == 1){
                    result = x;
                    result *= result;
                    cout<<result<<"\n";
                }
                else{
                    result = x - 1;
                    result *= result;
                    result += 1;
                    cout<<result<<"\n";
                }

            }
            else{
                if(y % 2 == 0){
                    result = y;
                    result *= result;
                    cout<<result<<"\n";
                }
                else{
                    result = y - 1;
                    result *= result;
                    result += 1;
                    cout<<result<<"\n";
                }
            }
        }
        else{
            if(x > y){
                if(x % 2 == 0) {
                    result = x-1;
                    result *= result;
                    result += y;
                    cout<<result<<"\n";
                }
                else{
                    result = x;
                    result *= x;
                    result -= (y-1);
                    cout<<result<<"\n";
                }
            }
            else if(y > x){
                if(y % 2 == 0){
                    result = y;
                    result *= y;
                    result -= (x-1);
                    cout<<result<<"\n";
                }
                else{
                    result = y-1;
                    result *= result;
                    result += x;
                    cout<<result<<"\n";
                }
            }
            else{
                result = x;
                result *= result;
                result -= (x-1);
                cout<<result<<"\n";
            }
        }
    }
    return 0;
}

