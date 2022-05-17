#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> bfs(int ver,vector<int> adj[]){
            vector<int> bfs;    // vector for storing the traversal
            vector<int> vis(ver,0);     //vector for checking whether the string has been visited or not
            queue <int> q;  //temporary queue
            q.push(0);  //initializing the queue with first node
            vis[0]=1;   //marking it as visited
            while(!q.empty()){  //traversing for the rest
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            return bfs;
        }
};

int main(){
    int tc; //no of test cases
    cin>>tc;
    //for multiple graphs or for same graph with multiple components
    while(tc--){
        int ver,e;    //v=no of vertices  //e=no of edges
        cin>>ver>>e;
        vector<int> adj[ver];
        
        //creating adjacency list
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        // save the bfs traversal in a a vector named ans
        vector<int> ans=obj.bfs(ver,adj);
        //print ans
        for(int i=0; i<ans.size(); i++)     cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
