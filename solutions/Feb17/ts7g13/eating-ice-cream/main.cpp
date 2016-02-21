#include <iostream>
#include <cmath>
#define N 100005
using namespace std;

int n, m, studIndex;
long long S[2*N];
long long value, money, result;

int bs(int value, int l, int r) {
     int result = -1;
     int left, index;
     index = left = l;
     int right = r, mid;
     while (left <= right) {
          mid = left + ((right - left) / 2);
          if (S[mid] - S[index - 1] <= value) {
               result = mid;
               left = mid + 1;
          }
          else right = mid - 1;
     }
     return result;
}

int main() {
     cin >> n >> m;
     S[0] = 0;
     for (int i=1; i<=n; ++i) {
          cin >> value;
          S[i] = S[i - 1] + value;
     }
     for (int i=1; i<=n; ++i) {
          S[i + n] = S[i + n - 1] + (S[i] - S[i - 1]);
     }
     for (int i=1; i<=m; ++i) {
          cin >> studIndex >> money;
          result = bs(money, studIndex, studIndex + n - 1); 
          result = (result != -1) ? result - studIndex + 1 : 0;
          cout << result << "\n";
     }
     return 0;
}
