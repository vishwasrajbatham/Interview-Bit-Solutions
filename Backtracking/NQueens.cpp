#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<bool> vb;
typedef vector<int> vi;

void print2d(vvs ans){  //Print 2d vector of strings
    for(int i=0;i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)   cout<<ans[i][j]<<"\t";
        cout<<"\n";
    }
}


class Solution {
public:
    void solve(int col,vs &board, vvs &ans, vi &rows,vi &ud, vi &ld, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int r=0; r<n; r++){
            if(rows[r]==0 && ld[r+col]==0 && ud[n-1+col-r]==0){
                board[r][col]='Q';
                rows[r]=1;
                ld[r+col]=1;
                ud[n-1+col-r]=1;
                solve(col+1, board, ans, rows, ud, ld, n);
                board[r][col]='^';
                rows[r]=0;
                ld[r+col]=0;
                ud[n-1+col-r]=0;
            } 
        }
    }
    vvs solveNQueens(int n) {
        vector<vector<string>> ans;
        vs board(n);
        string s(n, '^');
        vector<int> rows(n,0),ld(2*n-1,0),ud(2*n-1,0);
        for(int i=0; i<n; i++)  board[i]=s;
        solve(0, board, ans, rows, ud, ld, n);
        return ans;
    }
};

int main(){
    int n;
    cout<<"Enter the no of rows of the board"<<"\n";
    cin>>n;
    Solution o;
    vector<vector<string>> ans=o.solveNQueens(n);
    print2d(ans);
}