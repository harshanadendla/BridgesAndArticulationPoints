#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
const int N=1e5+1;
const int mod=1e9+7;

int n,m,a,b,inTime;
vector<int> graph[N];
int low[N],id[N],parent[N];
bool vis[N];
set<int> subs; 

void setMems()
{
    subs.clear();
    inTime=0;
    for(int i=0;i<=N;i++)
    {
        graph[i].clear();
        id[i]=0;
        low[i]=0;
        parent[i]=-1;
        vis[i]=false;
    }
}

void dfs(int u)
{
    vis[u]=true;

    id[u]=inTime;
    low[u]=inTime++;

    int children=0;
    for(int v : graph[u])
    {
        if(!vis[v])
        {
            parent[v]=u;
            children++;

            dfs(v);
            
            low[u]=min(low[u],low[v]);

            if(parent[u]==-1 && children>1) subs.insert(u);

            if(parent[u]!=-1 && id[u]<=low[v]) subs.insert(u);
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],id[v]);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    //o0badboy0o

    cin>>n>>m;
    while(n && m)
    {
        setMems();

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

        cout<<subs.size()<<"\n";
        cin>>n>>m;
    }

    return 0;
}