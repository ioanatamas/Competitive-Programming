#include <iostream>

using namespace std;

int n, x;
long long result = -(2<<30);
long long totalSum, partMin, partMax, maxSum, minSum;
bool isPositive;

int main() {
     cin >> n;
     totalSum = partMin = partMax = maxSum = minSum = 0;
     isPositive = false;
     for (int i=0; i<n; ++i) {
          cin >> x;
          if (x > result) {
               result = x;
               isPositive = (!isPositive && x > 0) ? true : isPositive;
          }
          totalSum += x;
          partMax += x;
          partMin += x;
          // construct the max-sum subsequence as a potential solution
          if (partMax > 0) {
               if (partMax > maxSum) {
                    maxSum = partMax;
               }
          }
          else partMax = 0;
          // if the solution splits into 2 parts then construct the min-sum subsequence and extract it from the total sum
          if (partMin < 0) {
               if (partMin < minSum) {
                    minSum = partMin;
               }
          }
          else partMin = 0;

     }
     result = isPositive ? max(totalSum - minSum, maxSum) : result;
     cout << result << "\n";
     return 0;
}
