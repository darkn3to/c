#include<iostream>
#include<vector>
#include<cstdlib> // for rand() function
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); // move pivot to end

    int i = (low - 1); // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) // If the list contains only one element
        return arr[low];

    int pi = partition(arr, low, high);

    if (k == pi)
        return arr[k];
    else if (k < pi)
        return quickSelect(arr, low, pi - 1, k);
    else
        return quickSelect(arr, pi + 1, high, k);
}

int main() {
    int t, n, k;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t-->0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements: ";
        for(int i=0; i<n; i++) cin >> arr[i];
        cout << "Enter the K value: ";
        cin >> k;
        cout << "Kth smallest element is " << quickSelect(arr, 0, n - 1, k - 1) << endl;
    }
    return 0;
}