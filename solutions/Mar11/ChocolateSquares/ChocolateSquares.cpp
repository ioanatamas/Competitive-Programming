#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define MOD 666013
int N,M;
int din[1010][1010];

int solve(int x,int y){
    if(x == y) {
        return 0;
    }
    if(x > y)
        swap(x,y);
    if(din[x][y])
        return din[x][y];
    din[x][y]=x+y+20;
    for(int i=1;i<x;++i){
        din[x][y] = min(din[x][y],1 + solve(i,y) + solve(x - i,y));
    }
    for(int i=1;i<y;++i){
        din[x][y] = min(din[x][y],1 + solve(x,i) + solve(x,y-i));
    }
    return din[x][y];
}


int main() {
    cin >> N >> M;
    cout << solve(N,M);
}
