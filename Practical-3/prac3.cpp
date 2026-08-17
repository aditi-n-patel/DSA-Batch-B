#include <iostream>
using namespace std;


void insert(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}


int bshort(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int swap = 0;

        for (int j = 0; j < n - i - 1; j++) {

            if (a[j] > a[j + 1]) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swap = 1;
            }
        }

        if (swap == 0) {
            break;
        }
    }

    return 0;
}


int selectionSort(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {

            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    return 0;
}


void insertion(int a[], int n) {

    for (int i = 1; i < n; i++) {

        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}


int main() {

    int a[] = {8, 5, 7, 4, 3, 1, 2};

    int n = sizeof(a) / sizeof(a[0]);

    int bubble[n];
    int insertion_arr[n];
    int selection[n];

    
    for (int i = 0; i < n; i++) {

        bubble[i] = a[i];
        selection[i] = a[i];
        insertion_arr[i] = a[i];
    }

    
    bshort(bubble, n);

    cout << "\narray sorted using Bubble Sort:\n";
    insert(bubble, n);

    
    selectionSort(selection, n);

    cout << "\narray sorted using Selection Sort:\n";
    insert(selection, n);

   
    insertion(insertion_arr, n);

    cout << "\narray sorted using Insertion Sort:\n";
    insert(insertion_arr, n);

    return 0;
}