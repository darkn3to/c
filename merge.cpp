#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int>& arr, int l, int m, int r, int& comp) {
    int i, j, k, inv=0;
    int n1=m-l+1, n2=r-m;
    vector<int> L(n1), R(n2);
    for (i=0; i<n1; i++) L[i]=arr[l+i];
    for (j=0; j<n2; j++) R[j]=arr[m+1+j];
    i=0, j=0, k=l;
    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        } 
        else {
            arr[k]=R[j];
            j++;
            inv+=(m-i+1); 
        }
        comp++; 
        k++;
    }
    while (i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
    return inv;
}
int mergeSort(vector<int>& arr, int l, int r, int& comp) {
    int inv=0;
    if (l<r) {
        int m=l+(r-l)/2;
        inv+=mergeSort(arr, l, m, comp);
        inv+=mergeSort(arr, m+1, r, comp);
        inv+=merge(arr, l, m, r, comp);
    }
    return inv;
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
        int comp=0;
        int inv=mergeSort(arr, 0, arr.size()-1, comp);
        cout << "Sorted array is \n";
        for (int i=0; i<arr.size(); i++) cout << arr[i] << " ";
        cout << "\nNumber of comparisons: " << comp;
        cout << "\nNumber of inversions: " << inv << endl;
    }
    return 0;
}