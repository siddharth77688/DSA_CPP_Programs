#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> maxSubarraySum(n + 1, 0);
    vector<int> increasingSum(n + 1, 0);
    vector<int> bestIncreasingStart(n + 1, 0);
    vector<int> suffixMaxSum(n + 1, 0);

    // 1. Maximum subarray sum ending at index i
    maxSubarraySum[1] = arr[1];

    for (int i = 2; i <= n; i++) {

        maxSubarraySum[i] = max(
            arr[i],
            arr[i] + maxSubarraySum[i - 1]
        );
    }

    // 2. Calculate increasing subarray sums from right to left
    increasingSum[n] = arr[n];
    bestIncreasingStart[n] = increasingSum[n];

    for (int i = n - 1; i >= 1; i--) {

        if (arr[i] < arr[i + 1]) {
            increasingSum[i] = arr[i] + increasingSum[i + 1];
        } 
        else {
            increasingSum[i] = arr[i];
        }

        bestIncreasingStart[i] = max(
            arr[i],
            increasingSum[i]
        );

        suffixMaxSum[i] = max(
            bestIncreasingStart[i],
            suffixMaxSum[i + 1]
        );
    }

    // 3. Combine two non-overlapping subarrays
    int maxTotalSum = 0;

    for (int i = 1; i <= n - 1; i++) {

        int totalSum = maxSubarraySum[i] + suffixMaxSum[i + 1];

        maxTotalSum = max(maxTotalSum, totalSum);
    }

    cout << maxTotalSum << endl;

    return 0;
}