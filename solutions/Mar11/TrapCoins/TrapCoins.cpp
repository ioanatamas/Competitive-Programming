#include<bits/stdc++.h>

using namespace std;

int N;
long long v[1010100];
long long din[1010100];

int main() {
    cin.sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;++i){
        cin >> v[i];
    }
    din[1] = max(0LL,v[1]);
    for(int i=2;i<=N;++i){
        din[i] = max(din[i-1],din[i-2] + max(0LL,v[i]));
    }
    cout << max(din[N],din[N-1]);
}
