#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int N;
long long v[101010];
long long din[101010][2];
vector<int> g[101010];
int viz[101010];

void dfs(int x){
    viz[x]=1;
    din[x][1]=max(v[x],0LL);
    for(auto n : g[x]){
        if(!viz[n]){
            dfs(n);
            din[x][1] += din[n][0];
            din[x][0] += max(din[n][0],din[n][1]);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;++i){
        cin >> v[i];
    }
    for(int i=1;i<N;++i){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    cout << max(din[1][0],din[1][1]);
}
