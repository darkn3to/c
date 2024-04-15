#include<iostream>
#include<vector>
#include<cstdlib> 
using namespace std;
int partition(vector<int>& arr, int low, int high, int& comp, int& swaps) {
    int pivotIndex=low+rand() % (high-low+1);
    int pivot=arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); 
    swaps++;
    int i=(low-1); 
    for (int j=low; j <= high-1; j++) {
        comp++; 
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1], arr[high]);
    swaps++;
    return (i+1);
}
void quickSort(vector<int>& arr, int low, int high, int& comp, int& swaps) {
    if (low < high) {
        int pi=partition(arr, low, high, comp, swaps);
        quickSort(arr, low, pi-1, comp, swaps);
        quickSort(arr, pi+1, high, comp, swaps);
    }
}
int main() {
    int t, n;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t-->0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements: ";
        for(int i=0; i<n; i++) cin >> arr[i];
        int comp=0, swaps=0;
        quickSort(arr, 0, arr.size()-1, comp, swaps);
        cout << "Sorted array is \n";
        for (int i=0; i<arr.size(); i++) cout << arr[i] << " ";
        cout << "\nNumber of comparisons: " << comp;
        cout << "\nNumber of swaps: " << swaps << endl;
    }
    return 0;
}