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
const int N=3000;
const int mod=1e9+7;

vector<string> board;
bool flag=false,vis[N]={false};
char c;
int n,m,inTime=0,idx;
vector<int> graph[N];
int parent[N],low[N],id[N];

void dfs(int u)
{
    vis[u]=true;
    id[u]=low[u]=inTime++;

    int children=0;
    for(int v : graph[u])
    {
        if(!vis[v])
        {
            children++;
            parent[v]=u;
            dfs(v);

            low[u]=min(low[u],low[v]);

            if(parent[u]==-1 && children>1) 
            {
                flag=true;
            }

            if(parent[u]!=-1 && id[u]<=low[v]) 
            {
                flag=true;
            }
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

    int counter=0;
    string str,lpp;
    board.pb(" ");
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        lpp=" ";
        cin>>str;
        lpp+=str;
        board.pb(lpp);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(board[i][j]=='.') continue;
            counter++;
            idx=m*(i-1)+j;
            if(i+1<=n && board[i+1][j]=='#')
            {
                graph[m*(i-1)+j].pb(m*i+j);
            }

            if(i-1>=1 && board[i-1][j]=='#')
            {
                graph[m*(i-1)+j].pb(m*(i-2)+j);
            }

            if(j+1<=m && board[i][j+1]=='#')
            {
                graph[m*(i-1)+j].pb(m*(i-1)+j+1);
            }

            if(j-1>=1 && board[i][j-1]=='#')
            {
                graph[m*(i-1)+j].pb(m*(i-1)+j-1);
            }
        }
    }

    if(counter<3) 
    {
        cout<<"-1";
        return 0;
    }

    memset(parent,-1,sizeof(parent));
    dfs(idx);

    (flag) ? cout<<"1" : cout<<"2" ;

    return 0;
}