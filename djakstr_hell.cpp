#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> int_p ;
class Graph
{
    int V;
    list<pair<int,int>>*adj;
    public:
    Graph(int v)
    {
        this->V=v;
        adj=new list<pair<int,int>>[V];
    }
    void add_edge(int u,int v,int w,bool bidir=1)
    {   if(bidir==1)
       { adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));}
        else
       { adj[u].push_back(make_pair(v,w));}
        }
     void djakstra(int src)
    {  
        priority_queue<int_p,vector<int_p>,greater<int_p>>pq;
        vector<int>dist(1000);
        dist.resize(V);
        for(int i=0;i<V;i++)
        {   
            dist[i]=INT_MAX;
        }
        pq.push(make_pair(0,src));
        dist[src]=0;
        vector<bool>visit(V,0);
        while(!pq.empty())
        {   
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            list<int_p>::iterator itr;
            for(itr=adj[u].begin();itr!=adj[u].end();itr++)
            {
                int v=(*itr).first;
                int w=(*itr).second;
                 if(dist[v]>w+dist[u])
                {   
                    dist[v]=w+dist[u];
                    
                }
                if(visit[v]==0){
                    pq.push(make_pair(dist[v],v));
                    visit[v]=true;
                } }}
        cout<<"vertex   Distance from source \n";
        for(int i=0;i<V;i++)
        {cout<<char(i+'a')<<"           "<<dist[i]<<"\n";
           
        }}

     void bellman_ford(int src){
        priority_queue<int_p,vector<int_p>,greater<int_p>>pq;
       vector<int>dist(100);
        dist.resize(V);
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        pq.push(make_pair(0,src));
        dist[src]=0;
        vector<bool>visited(V,0);
        while(!pq.empty()){
            //cout<<"here we go again\n";
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            list<int_p>::iterator itr;
            for(itr=adj[u].begin();itr!=adj[u].end();itr++)
            {
                int v=(*itr).first;
                int w=(*itr).second;
                if(dist[v]>w+dist[u])
                {   
                    dist[v]=w+dist[u];
                    
                }
                if(visited[v]==0){
                    pq.push(make_pair(dist[v],v));
                    visited[v]=true;
                }
            }
        }
        for(int i=0;i<V;i++){
             int u=i;
        list<int_p>::iterator itr;
        for(itr=adj[i].begin();itr!=adj[i].end();itr++)
        {
            int v=(*itr).first;
            int w=(*itr).second;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
            {   
                cout<<"Graph contains negative weight";
                return;
            }
        }
        }
         cout<<"vertex   Distance from source \n";
        for(int i=0;i<V;i++)
        {cout<<char(i+'a')<<"           "<<dist[i]<<"\n";
           
        }      
     }
};


int main()
{
Graph g(6);
int m;
cin>>m;
while(m--)
{
    int u,v,w;
    cin>>u>>v>>w;
    g.add_edge(u,v,w);
}
cout<<"Dijasktra algorithm\n";
g.djakstra(0);
cout<<"\nBellman-ford\n";
g.bellman_ford(0);
}