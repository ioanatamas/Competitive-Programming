#include<bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

long long P,K;


long long get(long long N, long long P) {
    long long ret = 0;
    while(N){
        ret += N/P;
        N = N / P;
    }
    return ret;
}

int main() {
    cin >> P >> K;
    long long st = 1;
    long long dr = 1000000000;
    long long ret = 0;
    while(st <= dr){
        long long mid = (st + dr) / 2;
        if(get(mid,P) >= K){
            ret = mid;
            dr = mid-1;
        } else {
            st = mid + 1;
        }
    }
    cout << ret << endl;
}
