#include <iostream>
#define N 201

using namespace std;

int n, m;
long long S[N][N], x, solution;
long long sum;

int main() {
     solution = -(2 << 30);
     cin >> n >> m;
     for (int i=1; i<=n; ++i) {
          for (int j=1; j<=m; ++j) {
               cin >> x;
               if (x > solution) {
                    solution = x;
               }
               S[i][j] = S[i-1][j] + x;
          }
     }
     for (int i1=1; i1<=n; ++i1) {
          for (int i2=1; i2<=i1; ++i2) {
               // we fix 2 lines and search for the best columns
               sum = 0;
               for (int j=1; j<=m; ++j) {
                    sum += S[i1][j] - S[i2-1][j];
                    if (sum > 0) {
                         if (sum > solution) {
                              solution = sum;
                         }
                    }
                    else sum = 0;
               }
          }
     }
     cout << solution << "\n";
     return 0;
}
