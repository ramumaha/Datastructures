#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>>adj;
    public:
    Graph(int v)
    {
        V=v;
        for(int i=0;i<v;i++)
        {
            vector<int>row;
            adj.push_back(row);
            for(int j=0;j<v;j++)
            {
                adj[i].push_back(0);
            }
        }
        adj[0][1]=4;
        adj[0][3]=3;
        adj[2][3]=3;
        adj[3][4]=6;
        adj[4][5]=6;
        adj[1][2]=4;
        adj[2][5]=2;
        }
    bool bfs(int &source,int &sink,vector<int>&parent,vector<vector<int>>&resadj)
    {
        bool visited[V]={false};
        queue<int>q;
        q.push(source);
        visited[source]=1;
        parent[source]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<V;i++)
            {
                int v=i;
                int capacity=resadj[u][v];
                if(visited[v]==false && capacity>0)
                {   visited[v]=true;
                    parent[v]=u;
                    q.push(v);

                }
            }
        }
        if(visited[sink]==true)
            return true;
        else    
            return false;
    }

    int ford_fulkerson(int &source,int &sink)
    {
        int maxflow=0;
        vector<vector<int>>resadj;
        //int n=adj.size();
       for(int i = 0; i < V; i++)
        {
        vector<int> row;
        resadj.push_back(row);
        for(int j = 0; j < adj[i].size(); j++)
            {
            resadj[i].push_back(adj[i][j]);
            }
        }
        vector<int>parent(V,-1);
        while(bfs(source,sink,parent,resadj)==true)
        {   
            int pathflow=INT_MAX;
            int v=sink;
            while(v!=source)
            {
                int u=parent[v];
                int capacity=resadj[u][v];
                pathflow=min(pathflow,capacity);
                v=u;
            }
            v=sink;
            while(v!=source)
            {
                int u=parent[v];
                resadj[u][v]-=pathflow;
                resadj[v][u]+=pathflow;
                v=u;
            }
            maxflow+=pathflow;
        }
        return maxflow;

    }
    

};


int main()
{   Graph g(6);
   int source=0;
   int sink=7;
    for(int i = 0; i < 6; i++)
        {
        for(int j = 0; j < 6; j++)
            {
            int source = i;
            int sink = j;
            
            if(i == j) { continue; }
            
            cout << "The max flow from " << source << " to " << sink << " is: ";
            cout << g.ford_fulkerson( source, sink) << endl;
            }
             cout << endl;
}
sink-=2;
cout<<"total max_flow is "<<g.ford_fulkerson(source,sink);
}