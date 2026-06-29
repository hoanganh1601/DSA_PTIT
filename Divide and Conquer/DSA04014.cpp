#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll merge(vector<ll> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;

    vector<ll> l(n1), r(n2);

    for (int i = 0; i < n1; ++i) l[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) r[j] = arr[mid + 1 + j];

    ll ans = 0;
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(l[i] <= r[j]) arr[k++] = l[i++];
        else {
            arr[k++] = r[j++];

            // ALL remaining elements in L are also > R[j]
            ans += (n1 - i);
        }
    }

    // Copy remaining elements of L[] if any
    while (i < n1) arr[k++] = l[i++];

    // Copy remaining elements of R[] if any
    while (j < n2) arr[k++] = r[j++];

    return ans;
}

ll mergeSort(vector<ll> &arr, int left, int right) {
    ll ans = 0;
    if(left < right) {
        int mid = (left + right) / 2;

        // Count inversions in the left half
        ans += mergeSort(arr, left, mid);
        // Count inversions in the right half
        ans += mergeSort(arr, mid + 1, right);

        // Count cross-inversions during the merge step
        ans += merge(arr, left, mid, right);
    }

    return ans;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        vector<ll> arr(n + 1);
        
        for (int i = 0; i < n; ++i) cin >> arr[i];
        cout << mergeSort(arr, 0, n - 1) << endl;
    }

    return 0;
}
