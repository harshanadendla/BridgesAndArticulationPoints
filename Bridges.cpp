#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
const int N=710;

int nc,n,m,a,b,bridges,inTime;
vector<int> graph[N];
set<pair<int,int>> ans;
vector<bool> vis(N);
vector<int> id(N);
vector<int> low(N);
vector<int> parent(N);

void setMems()
{
    for(int i=1;i<N;i++)
    {
        graph[i].clear();
        vis[i]=false;
        id[i]=0;
        low[i]=0;
        parent[i]=0;
    }
    ans.clear();
    inTime=0;
    bridges=0;
}

void dfs(int u)
{
    vis[u]=true;
    low[u]=inTime;
    id[u]=inTime++;

    for(int v : graph[u])
    {
        if(!vis[v]) 
        {
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(id[u]<low[v])
            {
                bridges++;
                (u<v) ? ans.insert({u,v}) : ans.insert({v,u});
            }
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],low[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    cin>>nc;

    for(int t=1;t<=nc;t++)
    {
        setMems();
        
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }

        cout<<"Caso #"<<t<<"\n";
        if(bridges==0) cout<<"Sin bloqueos\n";
        else
        {
            cout<<bridges<<"\n";
            for(auto p : ans)
            {
                cout<<p.f<<" "<<p.s<<"\n";
            }
        }
    }
    
    return 0;
}