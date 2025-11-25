#include <iostream>
#include <string>
using namespace std;
int binarysearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}
int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inter the number you want to search: ";
    int target ;
    cin >> target; 
    int result = binarysearch(arr, n, target);
    if (result != -1) { 
        cout<<"Found the "+ to_string(target);
    }

}
