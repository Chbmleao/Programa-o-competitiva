#include <iostream>
#include <string>
using namespace std;
 
int main(int argc, char const *argv[]) {
    int numPalitos = 6;
    int palitos[numPalitos];
 
    for (int i = 0; i < numPalitos; i++) {
        cin >> palitos[i];
    }
 
    int maxRepetidos = 0;
    int valorMaxRepetidos = 0;
    int contador = 0;
 
    for (int i = 0; i < numPalitos; i++) {
        contador++;
        for (int j = i+1; j < numPalitos; j++) {
            if(palitos[i] == palitos[j])
                contador++;
        }
        if(contador > maxRepetidos) {
            maxRepetidos = contador;
            valorMaxRepetidos = palitos[i];
        }
        contador = 0;
    }
 
    if (maxRepetidos >= 4) {
        int aux = 4;
        int vals[2];
        int auxIndx = 0;
        for (int i = 0; i < numPalitos; i++) {
            if(palitos[i] == valorMaxRepetidos && aux != 0) {
                palitos[i] = 0;
                aux--;
            }
            else {
                vals[auxIndx] = palitos[i];
                auxIndx++;
            }
        }
 
        if(vals[0] != vals[1])
            cout << "Bear";
        else
            cout << "Elephant";
    } else {
        cout << "Alien";
    }
    
    return 0;
}