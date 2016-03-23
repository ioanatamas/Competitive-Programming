#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define MOD 666013
int N,M;

long long best[2020][2020];
int v[2020][2020];

int main() {
    cin.sync_with_stdio(false);
    cin >> N >> M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin >> v[i][j];
        }
    }
    if(v[1][1] == 1) {
        cout << 0;
        return 0;
    }
    best[1][1]=1;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(v[i][j]) {
                best[i][j]=0;
                continue;
            }
            best[i][j] += best[i-1][j] + best[i][j-1];
            best[i][j] %= MOD;
        }
    }
    cout << best[N][M];
}
