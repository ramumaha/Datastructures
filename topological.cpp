#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    int e;
    int **adj;
    int *in_degree;
    bool *visited;
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
       in_degree=new int[v];
       visited=new bool[v];
       memset(in_degree,0,sizeof(in_degree));
        memset(visited,0,sizeof(visited));



    }

    }
    void add_edge(int u,int v)
    {   adj[u][v]=1;
    }

    void topological_sort()
    {int c=0,i;
        for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            in_degree[i]+=adj[j][i];
        }
    }
    
    while(c<v)
    {for(i=0;i<v;i++)
    {
        if(in_degree[i]==0 && visited[i]==0)
        {
            cout<<i<<" ";
            visited[i]=1;
        }
        for(int k=0;k<v;k++)
    {
        if(adj[k][i]==1)
        {
            in_degree[i]--;
        }
    }       
    }
    
    
    c++;
    }
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
  cout<<"Topological sort of the above graph \n";
  G.topological_sort();
  cout<<"\n";
}