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
const int N=1e5;
const int mod=1e9+7;

int t,n,m,inTime=1,a,b,artics;
vector<int> graph[N],ans;
bool vis[N];
int parent[N],low[N],id[N];

void art(int u)
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
            
            art(v);

            low[u]=min(low[u],low[v]);
            
            if(parent[u]!=-1 && id[u]<=low[v])
            {
                artics++;
                ans.pb(u);
            }

            if(parent[u]==-1 && children>1)
            {
                artics++;
                ans.pb(u);
            }
        }
        else if(parent[u] != v)
        {
            low[u]=min(low[u],low[v]);
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

    memset(parent,-1,sizeof(parent));
    memset(vis,false,sizeof(vis));
    memset(low,0,sizeof(low));
    memset(id,0,sizeof(id));

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
            art(i);
        }
    }

    for(int i : ans) cout<<i<<" ";

    return 0;
}