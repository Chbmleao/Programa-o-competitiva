#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string strInp;
    string strOut;
    cin >> strInp;
    cin >> strOut;

    int num1Inp = 0;
    int num1Out = 0;

    for (int i = 0; i < strInp.length(); i++) {
        if(strInp[i] == '1')
            num1Inp++;
    }
    
    for (int i = 0; i < strOut.length(); i++) {
        if(strOut[i] == '1')
            num1Out++;
    }

    if(num1Inp % 2 == 0) {
        if(num1Out > num1Inp)
            cout << "NO";
        else
            cout << "YES";
    } else {
        if(num1Out > num1Inp+1)
            cout << "NO";
        else
            cout << "YES";
    }

    return 0;
}
