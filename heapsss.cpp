#include<bits/stdc++.h>
#include<time.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {    // Build max heap
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {          // Sort the max heap
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int myarr[n];
    char order;
    cout << "Choose data order - 'i' for increasing or 'd' for decreasing: ";
    cin >> order;

    srand(time(0));
    if (order == 'i') {
        for (int i = 0; i < n; i++) {
            myarr[i] = i;  // Increasing order
        }
    } else if (order == 'd') {
        for (int i = 0; i < n; i++) {
            myarr[i] = n - i;  // Decreasing order
        }
    } else {
        cout << "Invalid input!" << endl;
        return 1;
    }

    cout << "Before heap sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << myarr[i] << " ";
    }

    heapsort(myarr, n);

    cout << endl << "After heap sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << myarr[i] << " ";
    }

    return 0;
}
