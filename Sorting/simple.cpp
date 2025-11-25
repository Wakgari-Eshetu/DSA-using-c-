#include <iostream>
using namespace std;

void simplesearch(int arr[],int n){
    for(int i =0 ;i<n-1;i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    simplesearch(arr, n);

    cout << "After sorting: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}