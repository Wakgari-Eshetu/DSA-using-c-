#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr,int n ){
    int temp ;
    for(int i = 0 ; i<n-1;i++){
        for(int j=0 ; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



int main(){
    vector<int> arr = {5, 3, 8, 4, 2};
    int n = arr.size();
    cout<<"before sorting.";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    bubbleSort(arr,n);

    cout<<"After sorting.";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0 ;
}