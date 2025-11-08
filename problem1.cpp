#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minheap;

int add(int k, int num)
{
    if (minheap.size() < k)
    {
        minheap.push(num);
    }
    else if (minheap.top() < num)
    {
        minheap.pop();
        minheap.push(num);
    }
    return minheap.top();
}

int main()
{
    cout << "Enter the value of K: ";
    int k;
    cin >> k;
    while (true)
    {
        bool cnt;
        cout << "Enter 1 to add a number, or 0 to exit: ";
        cin >> cnt;
        if (cnt!=1)
            break;
        int x;
        cout << "Add a number in the stream: ";
        cin >> x;
        cout << k << "th largest: " << add(k, x)<<endl;
    }
}