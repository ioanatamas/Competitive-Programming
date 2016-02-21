#include <iostream>
#include <cmath>
#define MAXV 1000000000

using namespace std;

int p, k;
int powers[30], plen=0;

void calculatePowers(int p) {
     int value = p;
     powers[0] = value;
     while (1LL * value * p <= MAXV) {
          value *= p;
          plen++;
          powers[plen] = value;
     }
}

int getPCount(int value) {
     int count = 0;
     int index = 0;
     while (powers[index] <= value && index <= plen) {
          count += value / powers[index];
          index++;
     }
     return count;
}

int bs(int k) {
     if (k == 0) {
          return 1;
     }
     int left = 0, mid;
     int right = MAXV;
     int pCount, result;
     while (left <= right) {
          mid = left + ((right - left) / 2);
          pCount = getPCount(mid);
          if (pCount < k) {
               left = mid + 1;
          }
          else if (pCount >= k) {
               result = mid;
               right = mid - 1;
          }
     }
     return result;
}

int main() {
     cin >> p >> k;
     calculatePowers(p);
     cout << bs(k) << "\n";
     return 0;
}
