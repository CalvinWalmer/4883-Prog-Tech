#include <iostream>

using namespace std;

void insertionSort(int[], int);

int main(){
    int arr[3], to;

    cin >> to;

    for(int i = 0; i < to; i++){
        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];

        insertionSort(arr, 3);

        cout << "Case " << i+1 << ": " << arr[1] << endl; 
    } 

    return(0);
}

// Code taken from Geeks for Geeks https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}