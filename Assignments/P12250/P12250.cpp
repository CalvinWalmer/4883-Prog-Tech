#include <iostream>
#include <string>

using namespace std;

int main(){
    string x;
    int c = 0;
    while(cin >> x){
        if (x != "#"){
            c++;
            cout << "Case " << c << ":";
            if (x == "HELLO"){ cout << " ENGLISH" << endl;}
            else if (x == "HOLA"){ cout << " SPANISH" << endl; }
            else if (x == "HALLO"){ cout << " GERMAN" << endl; }
            else if (x == "BONJOUR"){ cout << " FRENCH" << endl; }
            else if (x == "CIAO") { cout << " ITALIAN" << endl; }
            else if (x == "ZDRAVSTVUJTE") { cout << " RUSSIAN" << endl; }
            else { cout << " UNKNOWN" << endl; }
        }
    }

    return(0);
}