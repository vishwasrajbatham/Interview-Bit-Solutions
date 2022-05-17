#include<bits/stdc++.h>
using namespace std;
/*using adjacency matrix
int main(){
    int n,m;
    cin>>n>>m;
    //declare the adjacent matrix
    int adj[n+1][m+1];
    //take edges as input
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[u][v]=1;
    }   
    return 0;
}*/
//using adjacency list;
vector<int> create_adj_list(int n, int m){
    vector<int> adj[n+1]; //makes an array of size n+1 of vectors
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //add the next line if undirected graph
        //adj[v].push_back(u);
    }
    return adj;
}