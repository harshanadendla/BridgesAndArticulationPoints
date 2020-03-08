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
#define bug1 cout<<"hi1"
#define bug2 cout<<"hi2"
#define bug3 cout<<"hi3"
const int N=5e5+1;
const int mod=1e9+7;

int n,m,a,b,c,d,type,q;
vector<int> graph[N],children[N];
bool vis[N]={false};
int parent[N]={-1},finish[N],id[N],low[N];
set<pii> bridges;
unordered_set<int> verts;
int inTime=0;

bool desc(int one,int two) {return id[one]>=id[two] && finish[one]<=finish[two] ;}

int root(int one,int two)
{
    if(desc(one,two))
    {
        int lowest=*prev(upper_bound(children[two].begin(),children[two].end(),one,[](int i,int j){return id[i]<id[j];}));
        if(id[two]<=low[lowest]) return lowest;
        else return -1;
    }
    return -1;
}

void dfs(int u)
{
    vis[u]=true;
    id[u]=low[u]=inTime++;

    int child=0;
    for(int v : graph[u])
    {
        if(!vis[v])
        {
            child++;
            parent[v]=u;
            children[u].pb(v);

            dfs(v);

            low[u]=min(low[u],low[v]);

            if(id[u]<low[v]) bridges.insert({u,v});

            if(parent[u]==-1 && child>1) verts.insert(u);

            if(parent[u]!=-1 && id[u]<=low[v]) verts.insert(u);
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],id[v]);
        }
    }

    finish[u]=inTime++;
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

    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>type>>a>>b;
        
        if(type==1)
        {
            cin>>c>>d;
            if(id[d]<id[c]) swap(c,d);
            if(bridges.find({c,d}) == bridges.end())
            {
                cout<<"da\n";
            }
            else
            {
                if(desc(a,d)==desc(b,d))
                {
                    cout<<"da\n";
                }
                else
                {
                    cout<<"ne\n";
                }
            }
        }
        else
        {
            cin>>c;
            if(verts.find(c)==verts.end())
            {
                cout<<"da\n";
            }
            else
            {
                if(root(a,c)==root(b,c))
                {
                    cout<<"da\n";
                }
                else
                {
                    cout<<"ne\n";
                }
            }
        }
    }

    return 0;
}