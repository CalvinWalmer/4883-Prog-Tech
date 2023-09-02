#include <iostream>
#include <string>

using namespace std;

int main() {
    int k,n,p;

    
    for (int i = 0; i <=32; i++) {
        p = 0;
        cin >> n;
        k = n >> i;
        if (k & 1)
            p++;
    }
}