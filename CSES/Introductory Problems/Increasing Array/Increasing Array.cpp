// Introductory Problems : Increasing Array
#include "iostream"
using namespace std;

int main(){
    int n;
    long long int result = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i < n;i++){
        if(arr[i] >= arr[i - 1])
            continue;
        else{
            while(arr[i] < arr[i - 1]){
                arr[i]++;
                result++;
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}

