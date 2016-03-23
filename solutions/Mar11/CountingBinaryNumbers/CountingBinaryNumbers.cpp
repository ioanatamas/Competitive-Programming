#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define MOD 666013
int N,K;

long long din[101010][12];

int main() {
    cin.sync_with_stdio(false);
    cin >> N >> K;
    din[0][0]=1;
    for(int i=1;i<=N;++i){
        for(int k=0;k<=K;++k){
            din[i][0] += din[i-1][k];
            din[i][0] %= MOD;
        }
        for(int k=0;k<=K;++k){
            din[i][k] += din[i-1][k-1];
            din[i][k] %= MOD;
        }
    }
    long long ret = 0;
    for(int i=0;i<=K;++i)
        ret += din[N][i];
    ret %= MOD;
    cout << ret;
}
