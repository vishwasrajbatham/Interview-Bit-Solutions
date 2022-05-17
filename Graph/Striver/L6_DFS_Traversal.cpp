#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1;  //mark it as visited
        for(auto it : adj[node]) {      //go to its all adjacency nodes one by one 
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:   
    // calling this function first
	vector<int>dfsOfGraph(int V, vector<int> adj[]){    //V = no of vertices and adj[]=adjacency list
	    vector<int> storeDfs;  //store the dfs traversal
	    vector<int> vis(V+1, 0); //creating the visited vector
        for(int i = 1;i<=V;i++) {
            if(!vis[i]) dfs(i, vis, adj, storeDfs);     //will pass "storeDfs" and "vis" vector by reference 
        }
	    return storeDfs; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
    // creating adjacency list and calling function for separate test cases
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];
        //creating adjacency list
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}

        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        //printing ans for each test case
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
