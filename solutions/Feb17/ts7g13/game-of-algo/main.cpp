#include <iostream>
#define N 100005
#define INF (1 << 30)
using namespace std;

int n, maxv = 0, minv = INF;
int A[N];

long long getPotentialRefs(int v) {
     long long sum = 0;
     for (int i=0; i<n; ++i) {
          sum += v - A[i];
     }
     return sum;
}

int bs(int l, int r) {
     int left = l, right = r;
     int mid, result;
     long long sum;
     while (left <= right) {
          mid = left + ((right - left) / 2);
          sum = getPotentialRefs(mid);
          if (sum >= mid) {
               result = mid;
               right = mid - 1;
          }
          else {
               left = mid + 1;
          }
     }
     return result;
}

int main() {
     cin >> n;
     for (int i=0; i<n; ++i) {
          cin >> A[i];
          maxv = max(maxv, A[i]);
          minv = min(minv, A[i]);
     }
     cout << bs(maxv, maxv + minv);;
     return 0;
}

