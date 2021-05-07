#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> d(n+1, vector<int> (n+1,INT_MAX));
    while(m--)
    {   int i,j,w;
       cin>>i>>j>>w;
        d[i][j]=min(d[i][j],w);
        d[j][i]=min(d[j][i],w);
        
    }
    for(int i=0;i<=n;i++)
    {
        d[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(d[j][i]!=INT_MAX && d[i][k]!=INT_MAX)
                {
                    d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
                }
            }
        }
    }
    cout<<"\n The All pair shortest path distance matrix\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }

}