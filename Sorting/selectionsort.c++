#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i =0 ;i<n;i++){
        int min_idx = i;
        for(int j = i+1; j <n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx]= temp;
    }
}

int main(){

    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting:";
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
    selectionSort(arr,n);
    cout<<"After sorting:";
    for(int i : arr){
        cout<<i<<" ";
    }

}