class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto e: edges)
        {
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);

        queue<int>q;
        q.push(source);
        vis[source]=true;

        while(!q.empty())
        {
            int front=q.front();
            q.pop();

            if(front==destination)
            {
                return true;
            }
            for(auto it:adj[front])
            {
                 if(!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
return false;
        
    }
};