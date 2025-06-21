#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, k;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Input k
    cout << "Enter the value of K: ";
    cin >> k;

    if (k > n) {
        cout << "K cannot be larger than array size.\n";
        return 0;
    }

    // Min heap to store k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove smallest among k+1 elements
        }
    }

    // Extract k largest elements
    vector<int> kLargest;
    while (!minHeap.empty()) {
        kLargest.push_back(minHeap.top());
        minHeap.pop();
    }

    // Sort the result in descending order (optional)
    sort(kLargest.rbegin(), kLargest.rend());

    cout << "The " << k << " largest elements are: ";
    for (int num : kLargest) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}