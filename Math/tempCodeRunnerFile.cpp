int Solution::solve(int n) {
    n=n-2;
    int f1=1,f2=1,temp;
    int m=(pow(10,9)+7);
    for(int i=0;i<n;i++){
        temp=f2;
        f2+=f1;
        f1=temp;
    }
    return f2%m;
}