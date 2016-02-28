#include<bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

long long m[205][205];
long long v[205];

int N,M;

long long calc() {
    long long ret = v[1];
    long long curr = 0;
    long long mmin = 0;
    for(int i=1;i<=M;++i){
        curr += v[i];
        ret = max(ret,curr-mmin);
        mmin = min(mmin,curr);
    }
    return ret;
}
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin >> m[i][j];
        }
    }
    long long ret = m[1][1];
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            v[j]=0;
        }
        for(int j=i;j<=N;++j){
            for(int k=1;k<=M;++k){
                v[k] += m[j][k];
            }
            ret = max(ret,calc());
        }
    }
    cout << ret;
}
