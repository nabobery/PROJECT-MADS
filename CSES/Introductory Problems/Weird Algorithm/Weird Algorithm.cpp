// Introductory Problems : Weird Algorithm
#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long temp = n;
    cout<<n<<" ";
    while(temp != 1){
        if(temp % 2 == 0){
            temp = temp/2;
        }
        else{
            temp = 3*temp + 1;
        }
        cout<<temp<<" ";
    }
    return 0;
}

