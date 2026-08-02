#include<iostream>
using namespace std;
int iterative(int a[],int n,int target){
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    while(low<=high){
        if(a[mid]==target){
            return mid;
        }
       else if(a[mid<target]){
             low=mid+1;
        }
        else{
            high=mid-1;
        }

    } 
    return -1;
}
int recursion(int a[],int low,int high,int target){
    if(low>high){
        return -1;
    }
int mid = (low + high) / 2;

    if (a[mid] == target)
        return mid;
    else if (a[mid] < target)
        return recursion(a, mid + 1, high, target);
    else
        return recursion(a, low, mid - 1, target);
}

int main(){
    
    int n, choice;

    cout << "Enter number of book codes: ";
    cin >> n;

    int a[n];

    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cout << "Enter target code: ";
    cin >> target;

    cout << "\n1. Iterative Binary Search";
    cout << "\n2. Recursive Binary Search";
    cout << "\nEnter choice: ";
    cin >> choice;

    int pos;

    if (choice == 1)
        pos = iterative(a, n, target);
    else if (choice == 2)
        pos = recursion(a, 0, n - 1, target);
    else
    {
        cout << "Invalid Choice";
        return 0;
    }

    if (pos != -1)
        cout << "Book code found at position: " << pos + 1;
    else
        cout << "Book code not found.";

    return 0;


}