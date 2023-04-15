#include <iostream>
#include <string>
using namespace std;
 
int verificaVencedor(string primeiro, string segundos) {
    if(primeiro == "paper" && segundos == "rock")
        return 1;
    if(primeiro == "rock" && segundos == "scissors")
        return 1;
    if(primeiro == "scissors" && segundos == "paper")
        return 1;
 
    return 0;
}
 
int main(int argc, char const *argv[]) {
    string bruno;
    string felipe;
    string rafael;
 
    cin >> bruno;
    cin >> felipe;
    cin >> rafael;
    
    int brunoFelipe = bruno == felipe;
    int brunoRafael = bruno == rafael;
    int felipeRafael = felipe == rafael;
    int brunoFelipeRafael = bruno == felipe && bruno == rafael;
 
    if((brunoFelipe || brunoRafael || felipeRafael) && !brunoFelipeRafael) {
        if(brunoFelipe) {
            if(verificaVencedor(rafael, bruno))
                cout << "S";
            else
                cout << "?";
        } else if(brunoRafael) {
            if (verificaVencedor(felipe, bruno))
                cout << "M";
            else
                cout << "?";
        } else if(felipeRafael) {
            if(verificaVencedor(bruno, felipe))
                cout << "F";
            else
                cout << "?";
        }
    } else {
        cout << "?";
    }
 
    return 0;
}