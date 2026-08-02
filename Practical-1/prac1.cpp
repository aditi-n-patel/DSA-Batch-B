#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "ENTER N:";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int h;
    cout << "how many time to rotate?:\n";
    cin >> h;
    
    h = (h % n + n) % n;
    
    cout << "\n roteted:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[(i + h) % n] << " ";
    }
    
    int m;
    cout << "\nenter number of words:";
    cin >> m;
    vector<string> brr(m);
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }
    int k;
    cout << "how many time to rotate?:\n";
    cin >> k;
    
    k = (k % m + m) % m;
    
    cout << "\n roteted:\n";
    for (int i = 0; i < m; i++) {
        cout << brr[(i + k) % m] << " ";
    }
    
    return 0;
}
