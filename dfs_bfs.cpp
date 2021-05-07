#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    int e;
    int **adj;
    public:
    Graph(){}
    Graph(int v,int e)
    {   
       this->v = v;
        this->e = e;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
        adj[i] = new int[v];
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }
    }
    void add_edge(int u,int v,bool bi=1)
    {   adj[u][v]=1;
        if(bi)
        {
            adj[v][u]=1;
        }
    }

    void print_adj()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void dfshelper(int src,unordered_set<int>&visited) //stacks used;
    {
        visited.insert(src);
        cout<<char('A'+src)<<" ";
       for(int i=0;i<v;i++)
       {
           if(adj[src][i]==1 && visited.count(i)==0)
           {
               dfshelper(i,visited);
           }
       }
    }

    void dfs()
    {
        unordered_set<int>visited;
        dfshelper(0,visited);}

    void bfshelper(int src)
    {   queue<int>q;
        bool *visited=new bool[this->v];
        for(int i=0;i<this->v;i++)
        {visited[i]=0;}
        q.push(src);
        visited[src]=1;
        while(!q.empty())
        {   src=q.front();
            cout<<char(src+'A')<<" ";
            q.pop();
            for (int i = 0; i < v; i++) {
            if (adj[src][i] == 1 && (!visited[i])) {
                q.push(i);
                visited[i] = true;
            }           
        }}}

    void bfs()
    {
        bfshelper(0);
    }
    
};

int main()
{
  int n,m;
  cin>>n>>m;
  Graph G(n,m);
 
  while(m--)
  {   
      int u,v;
      cin>>u>>v;
      G.add_edge(u,v);
  }
  cout<<"The adjacency matrix of the graph \n";
  G.print_adj();
  cout<<"\nDFS traversal between cities \n";
  G.dfs();
  cout<<"\nBFS traversal between cities \n";
  G.bfs();
  

}