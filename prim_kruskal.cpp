#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> int_p;
int i=0;
struct edge
{int source;
int dest;
int weight;
};
class Graph_p
{
    int v;
    int e;
    list<int_p>*adj;
    edge*insert;
    public:
    Graph_p(int v,int e1)
    {this->v=v;
    e=e1;
    adj=new list<pair<int,int>>[v];
    insert=new edge[e1];
    }
    void add_edge(int u,int v,int w)
    {     
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    insert[i].source=u;
    insert[i].dest=v;
    insert[i].weight=w;
    i++;
    }
    void print_adj()
    {   
       for (int i = 0; i <v; ++i) 
       { printf("adjacencyList[%d] ", i);
         
        list< pair<int, int> >::iterator itr = adj[i].begin();         
        while (itr != adj[i].end()) {
           
            cout<<(*itr).first<<"  "<<(*itr).second;
            ++itr;
        }
    }}
    void prim()
    {   int weight=0;
        priority_queue< int_p, vector <int_p> , greater<int_p> > pq;
        vector<int>parent(v);
        vector<int>keys(v);
        vector<bool>visited(v);
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            keys[i]=INT_MAX;
            visited[i]=0;
        }
        int src=0;
        pq.push(make_pair(src,0));
        keys[src]=0;
        while(!pq.empty())
        {   int u=pq.top().second;//1st is wt
            visited[u]=1;
             pq.pop();
            list<int_p>::iterator itr;
            for(itr=adj[u].begin();itr!=adj[u].end();itr++)
         {
             int v=(*itr).first;
             int w=(*itr).second;
             if(visited[v]==0 && w<keys[v])
             {   
                 keys[v]=w;
                 pq.push(make_pair(w,v));
                 parent[v]=u;}}}
        for(int i=1;i<v;i++)
        {    weight+=keys[i]  ;  
            cout<<parent[i]+1<<"-->"<<i+1<<"\n";
              }
        cout<<"weight is "<<weight<<"\n"; }    
    
    static bool compare(edge &e1,edge &e2)
    {
        return e1.weight<e2.weight;
    } 
    int get_parent(int e1,vector<int>parent)
    {if(parent[e1]==e1)
        return e1;
     else 
        return get_parent(parent[e1],parent);

    }
    void kruskal()
    {
        sort(insert,insert+e,compare);
        vector<int>parent(v);
        for(int i=0;i<v;i++)
        {
            parent[i]=i;
        }
        edge *output=new edge[v-1];
        int count=0,k=0;
        while(count!=v-1)
        {int sparent=get_parent(insert[k].source,parent);
        int  dparent=get_parent(insert[k].dest,parent);
        if(sparent!=dparent)
        {output[count]=insert[k];
        count++;
        parent[sparent]=dparent;
        }
        k++;
        }
        for(int i=0; i<v-1; i++)
		if(output[i].source < output[i].dest)

			cout << output[i].source+1 << "--> " << output[i].dest+1 << " " << output[i].weight << endl;
		else

			cout << output[i].dest+1 << "--> " << output[i].source+1 << " " << output[i].weight << endl;}};


int main()
{
    int V,e1;
    cin>>V>>e1;
    Graph_p g(V,e1);
    while(e1--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.add_edge(u,v,w);
    
    }
    cout<<"Prim representation of MST in u --> v notation\n"; 
    g.prim();
    cout<<"\nKruskal representation of MST in u --> v notation\n";

    g.kruskal();
}