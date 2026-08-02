#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bool found = false;

    for(int i = 0; i < n; i++) {

        bool already = false;

        
        for(int k = 0; k < i; k++) {
            if(arr[k] == arr[i]) {
                already = true;
                break;
            }
        }

        if(already)
            continue;

        int count = 1;
        
        for(int j = i + 1; j < n; j++) {
            if(arr[j] == arr[i])
                count++;
        }

        if(count > 1) {
            cout << arr[i] << " repeated " << count << " times\n";
            found = true;
        }
    }

    if(!found)
        cout << "No duplicates!";

    return 0;
}