#include <bits/stdc++.h>
using namespace std;

struct Element {
    int value, arrayIndex, elementIndex;
    Element(int v, int ai, int ei) : value(v), arrayIndex(ai), elementIndex(ei) {}
};

struct Compare {
    bool operator()(Element &a, Element &b) {
        return a.value > b.value; // Min-heap based on the value
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays) {
    priority_queue<Element, vector<Element>, Compare> minHeap;
    vector<int> mergedArray;

    // Initialize the heap with the first element of each array
    int numberOfArrays = arrays.size();
    for (int i = 0; i < numberOfArrays; i++) {
        if (!arrays[i].empty()) { // Check if the array is non-empty
            minHeap.push(Element(arrays[i][0], i, 0));
        }
    }

    // Extract elements one by one and add the next element of the extracted element's array
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        mergedArray.push_back(current.value);

        int arrayIndex = current.arrayIndex;
        int elementIndex = current.elementIndex;

        // If there is a next element in the same array, add it to the heap
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push(Element(arrays[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1));
        }
    }

    return mergedArray;
}

int main() {
    int numArrays, arraySize;
    cout << "Enter number of arrays: ";
    cin >> numArrays;
    vector<vector<int>> arrays(numArrays);

    for (int i = 0; i < numArrays; i++) {
        cout << "Enter size of array " << i + 1 << ": ";
        cin >> arraySize;
        cout << "Enter elements of array " << i + 1 << ": ";
        for (int j = 0; j < arraySize; j++) {
            int value;
            cin >> value;
            arrays[i].push_back(value);
        }
    }

    vector<int> result = mergeKSortedArrays(arrays);
    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
