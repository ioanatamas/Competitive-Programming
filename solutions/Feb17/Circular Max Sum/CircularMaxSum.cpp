#include<bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

long long v[201010];
long long dq[202020];
long long ret;
int N;
int main() {
    cin >> N;
    for(int i=1;i<=N;++i) {
        cin >> v[i];
    }
    ret = v[1];
    for(int i=N+1;i<=N*2;++i) {
        v[i] = v[i - N];
    }
    for(int i=1;i<=2*N;++i){
        v[i] += v[i-1];
    }
    int left = 1,right = 1;
    for(int i=1;i<=2*N;++i){
        ret = max(ret, v[i] - v[dq[left]]);
        while(left <= right && v[dq[right]] >= v[i]) {
            --right;
        }
        dq[++right] = i;
        while(dq[left] <= i - N){
            ++left;
        }
    }
    cout << ret;
}
