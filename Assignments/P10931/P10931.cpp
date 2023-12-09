#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n,p,k;
    string str;

    while(cin >> n)
        if(n != 0){
            p = 0;
            k = 0;
            str = "";
            cout << "The parity of ";
            for (int i = 0; i <=32; i++) {
                str.append(to_string(k & 1));
                if (k & 1){
                    p++;
                }
                k = n >> i;
            }
            reverse(str.begin(), str.end());
            str.erase(str.begin(), str.begin() + str.find("1"));
            str.erase(str.end() - 1);
            cout << str << " is " << p << " (mod 2)." << endl;
        }

}