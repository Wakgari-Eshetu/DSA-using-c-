#include <iostream>
using namespace std;

void merge(int nums[],int n){
    if n<=1{
        return nums ;
    }
    

}

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting:";
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    merge(arr);

    cout<<"After sorting:";
    for(int i : arr){
        cout<<i<<" ";
    }

}


