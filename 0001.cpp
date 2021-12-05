int Solution::solve(vector<int> &A, int B) {
    if(B > A.size())
        return -1;
    
    int max_val = 0;
    for(int i=0;i<B;i++){
        max_val += A[i];
    }
    
    int j = B-1;
    int ans = max_val;
    for(int i=A.size()-1;i>A.size()-B-1;i--){
        ans = max(ans, max_val - A[j] + A[i]);
        max_val = max_val - A[j] + A[i];
        j--;
    }
    return ans;

}