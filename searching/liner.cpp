#include <iostream>
#include <string>
using namespace std;

int linearsearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the number you want to search: ";
    int target;
    cin >> target;
    int result = linearsearch(arr, n, target);
    if (result != -1) {
        cout << "Found the " + to_string(target) + " at index " + to_string(result) << endl;
    } else {
        cout << "Number not found." << endl;
    }
    return 0;
}