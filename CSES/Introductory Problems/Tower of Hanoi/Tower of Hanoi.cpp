// Introductory Problems : Tower of Hanoi
#include "iostream"
#include "cmath"
using namespace std;

void printMoves(int n, int left, int right, int middle){
    // base case to exit
    if(n == 0){
        return;
    }
    // first move n-1 disks to middle from left
    printMoves(n-1,left,middle,right);
    // then move nth disk to right
    cout<<left<<" "<<right<<"\n";
    // then move n-1 disks from middle to right
    printMoves(n-1,middle,right,left);

}

int main(){
    int n;
    cin >> n;
    cout<< pow(2,n) - 1<<"\n";
    printMoves(n,1,3,2);
    return 0;
}

