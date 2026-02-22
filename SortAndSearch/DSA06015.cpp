#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

// merge sort = recursively divide array in 2, sort and re_combine
// run time complexity = O(nlogn)
// space complexity = O(n)

void merge(int leftArray[], int rightArray[], int lenLeft, int lenRight, int a[]) {
    int i = 0, j = 0, k = 0;
    while(i < lenLeft && j < lenRight) {
        if(leftArray[i] < rightArray[j]) {
            a[k++] = leftArray[i++];
        }
        else{
            a[k++] = rightArray[j++];
        }
    }

    while(i < lenLeft) {
        a[k++] = leftArray[i++];
    }
    while(j < lenRight) {
        a[k++] = rightArray[j++];
    }
}

void mergeSort(int a[], int length) {
    if(length <= 1) return; // base case

    int mid = length / 2;  // divide array in 2
    int leftArray[mid], rightArray[length - mid];
    int i = 0, j = 0;
    for (; i < length; ++i) {
        if(i < mid) {
            leftArray[i] = a[i];
        }
        else {
            rightArray[j] = a[i];
            ++j;
        }
    }

    mergeSort(leftArray, mid);
    mergeSort(rightArray, length - mid);

    merge(leftArray, rightArray, mid, length - mid, a);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        mergeSort(a, n);

        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}