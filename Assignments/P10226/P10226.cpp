#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

void Display(map<string, int>);

int main(){
    string x, xPrev = "null";
    map<string, int> m;

    cin >> x; //numCases not needed

    while(getline(cin, x)){
        if(x != ""){
            m[x]++;
        }else{
            if(m.size() != 0){
                Display(m);
                cout << endl;
                m.clear();
            }
        }
    }

    Display(m);
}

void Display(map<string, int> m){
    int sum = 0;            
    map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        sum = sum + it->second;
        ++it;
    }

    it = m.begin();

    while (it != m.end())
    {   
        cout << it->first << " " << fixed << setprecision(4) << (float(it->second) / sum) * 100 << endl;
        ++it;
    }
}