#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> spiralOrder(const vector<vector<int> > &);
};

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int bottom_most=A.size()-1;
    int right_most=A[0].size()-1;
    int top_most=0,left_most=0;
    int direction=0;
    int curr_row=0,curr_col=0;
    vector<int> result;
    while(top_most<=bottom_most && left_most<=right_most){
        if(direction==0){
            for(curr_col=left_most;curr_col<=right_most;curr_col++)    
                result.push_back(A[curr_row][curr_col]);
            direction=1;
            top_most++;
            curr_col--;
        }
        else if(direction==1){
            for(curr_row=top_most;curr_row<=bottom_most;curr_row++)    
                result.push_back(A[curr_row][curr_col]);

            direction=2;
            right_most--;
            curr_row--;
        }
        else if(direction==2){
            for(curr_col=right_most;curr_col>=left_most;curr_col--)    
                result.push_back(A[curr_row][curr_col]);
            direction=3;
            bottom_most--;
            curr_col++;
        }
        else{
            for(curr_row=bottom_most;curr_row>=top_most;curr_row--)    
                result.push_back(A[curr_row][curr_col]);
            direction=0;
            left_most++;
            curr_row++;
        }       
    }
    return result;
}