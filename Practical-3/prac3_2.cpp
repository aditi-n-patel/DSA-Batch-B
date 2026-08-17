#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1) {
            mid++;
        }

        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortColors(arr);

    cout << "Sorted colour codes: ";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}