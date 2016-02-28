#include<bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

long long v[200200];
int N,M;

int calc(long long x) {
    long long ret=0;
    for(int i=1;i<=N;++i) {
        if(v[i] > x) return 0;
        ret += x - v[i];
    }
    if(ret >= x) return 1;
    return 0;
}
long long make(long long x, long long y){
    long long left = x;
    long long right = x + N - 1;
    long long ret = 0;
    while(left <= right){
        long long mid = (st+dr) / 2;
        if(v[mid] - v[x-1] <= y){
            ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ret;
}
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;++i){
        cin >> v[i];
    }
    for(int i=N+1;i<=2*N;++i){
        v[i] = v[i-N];
    }
    for(int i=1;i<=2*N;++i){
        v[i] += v[i-1];
    }
    for(int i=1;i<=M;++i){
        long long x,y;
        cin >> x >> y;
        if(v[x] - v[x-1] > y){
            cout << 0 << "\n";
        } else {
            cout << make(x,y) - x + 1 << "\n";
        }
    }
}

