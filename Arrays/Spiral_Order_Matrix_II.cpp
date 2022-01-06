#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int> > generateMatrix(int);
};

vector<vector<int> > Solution::generateMatrix(int A) {
    int bottom_most=A-1, right_most=A-1, top_most=0, left_most=0, direction=0, curr_row=0,curr_col=0, n=1;
    vector<vector<int> > result(A,vector<int>(A,0));
    //vector <vector<int> > vec2D(5, vector<int>(4, 1));
    /*for(int i=0;i<A;i++){
        for(int j=0;j<A;j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }*/

    while(n<=A*A){
        if(direction==0 && n<=A*A){
            for(curr_col=left_most; curr_col<=right_most; curr_col++)    
                result[curr_row][curr_col]=n;
                n++;
            direction=1;
            top_most++;
            curr_col--;
        }
        else if(direction==1 && n<=A*A){
            for(curr_row=top_most;curr_row<=bottom_most;curr_row++)    
                result[curr_row][curr_col]=n;
                n++;

            direction=2;
            right_most--;
            curr_row--;
        }
        else if(direction==2 && n<=A*A){
            for(curr_col=right_most;curr_col>=left_most;curr_col--)    
                result[curr_row][curr_col]=n;
                n++;

            direction=3;
            bottom_most--;
            curr_col++;
        }
        else{
            for(curr_row=bottom_most;curr_row>=top_most;curr_row--)    
                result[curr_row][curr_col]=n;
                n++;

            direction=0;
            left_most++;
            curr_row++;
        }       
    }
    return result;
}

int main(){
    vector<vector<int> > res;
    Solution obj;
    res=obj.generateMatrix(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}