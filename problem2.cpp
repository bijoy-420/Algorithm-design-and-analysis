#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, string>> patientQueue;

void addPatient(string name, int age)
{
    patientQueue.push(make_pair(age, name));
}

void nextPatient()
{
    if (patientQueue.empty())
    {
        cout << "No patients are there.." << endl;
        return;
    }
    cout << "Name:" << patientQueue.top().second << endl;
    cout << "Age:" << patientQueue.top().first << endl;
    patientQueue.pop();
}

int main()
{  int cnt=0;
   while(true){
        string name;
        int age;
        cout<<"Enter a name and age(0 to exit): ";
        cin>>name;
        if(name == "0")break;
        cin>> age;
        addPatient(name, age);
        cnt++;
   }
    while(cnt--)
    nextPatient();
    return 0;
}
