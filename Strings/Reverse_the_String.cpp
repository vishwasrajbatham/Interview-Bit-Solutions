#include<bits/stdc++.h>
using namespace std;
/*
Input 2:
    A = "this is ib"
Output 2:
    "ib is this"*/
string solve(string A) {
    int n=A.size();
    stack<string> v;
    string temp="";
    for(int i=0;i<n;i++){
        if(A[i]==' '){
            v.push(temp);
            temp="";
            v.push(" ");
        }
        else{
            temp+=A[i];
        }
    }
    v.push(temp);
    temp="";
    while(!v.empty()){
        temp+=v.top();
        v.pop();
    }
    if(temp.size()==0)  return temp;
    while(temp[0]==' '){
        temp.erase(temp.begin());
    }
    if(temp.size()==0)  return temp;
    while(temp[temp.size()-1]==' '){
        temp.erase(temp.begin()+temp.size()-1);
    }
    return temp;
}

int main(){
    string A="this is ib";
    string b=solve(A);
    cout<<b;
    return 0;
}