#include <iostream>
#include <cmath>

using namespace std;

void insertionSort(int[], int);

int main(){
    int x, y, z, arr[3];

    while(cin >> x){
        cin >> y;
        cin >> z;
        if (x || y || z)
        {
            arr[0] = x;
            arr[1] = y;
            arr[2] = z;
            insertionSort(arr, 3);

            if(pow(arr[0],2) + pow(arr[1],2) == pow(arr[2],2)){
                cout << "right" << endl;
            }else{
                cout << "wrong" << endl;
            }
        }else{
            break;
        }
    }
    return(0);
}


//Insertion Sort Code Taken from Geeks for Geeks https://www.geeksforgeeks.org/insertion-sort/
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