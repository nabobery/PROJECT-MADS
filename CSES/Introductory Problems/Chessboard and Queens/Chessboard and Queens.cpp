#include<iostream>
using namespace std;

char board[8][8];
int result = 0;
// for knowing if queen is there in the left diagonal, right diagonal (number of ld or rd = 2n-1) or row
bool row[8],ld[15],rd[15];

void solve(int j){
    // column number is 8 which means all queens have been placed therefore count++ and return
    if(j == 8){
        result++;
        return;
    }
    for(int i = 0;i < 8;i++) {
        // check if the given position is safe and place queen
        if (board[i][j] == '.' && !ld[i - j + 7] && !rd[i + j] && !row[i]) {
            // ld can be uniquely represented as i - j + n - 1 whereas rd can be identified by i + j (if 2 cells have same ld and rd value it means that they're in the ld or rd)
            ld[i - j + 7] = true;
            rd[i + j] = true;
            row[i] = true;
            // check if this configuration can place 8 queens
            solve(j + 1);
            // backtrack
            ld[i - j + 7] = false;
            rd[i + j] = false;
            row[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++) cin>>board[i][j];
        row[i] = false;
    }
    for(int i = 0;i < 15;i++){
        ld[i] = false;
        rd[i] = false;
    }
    solve(0);
    cout<<result<<"\n";
}


