#include<bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

long long m[200][200];
long long v[200200];

int N,M;

int calc(long long x) {
    long long ret=0;
    for(int i=1;i<=N;++i){
        if(v[i] > x) return 0;
        ret += x - v[i];
    }
    if(ret >= x) return 1;
    return 0;
}
int main() {
    cin >> N;

    long long st = 0;
    long long dr = 0;

    for(int i=1;i<=N;++i){
        cin >> v[i];
        dr = max(dr,v[i]*2);
        st = max(st,v[i]);
    }
    long long ret = 0;
    while(st <= dr){
        long long mid = (st+dr)/2;
        if(calc(mid)) {
            dr = mid-1;
            ret = mid;
        } else {
            st = mid+1;
        }
    }
    cout << ret;
}

