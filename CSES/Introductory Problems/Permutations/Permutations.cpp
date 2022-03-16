// Introductory Problems : Permutations
#include "iostream"
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout<<1<<"\n";
    }
    else if(n < 4){
        cout<<"NO SOLUTION \n";
    }
    else{
        int start, mid;
        if(n % 2 == 0){
            start = n;
            mid = n-1;
        }
        else{
            start = n -1;
            mid = n;
        }
        for(int i = 2; i <= start;i+=2){
            cout<<i<<" ";
        }
        for(int i = 1; i <= mid;i+=2){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
