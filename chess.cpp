#include <iostream>
#include <string>
using namespace std;
 
void movimentosTorre(int r1, int c1, int r2, int c2) {
    if(r1 == r2 || c1 == c2)
        cout << 1 << " ";
    else
        cout << 2 << " ";
}
 
void movimentosBispo(int r1, int c1, int r2, int c2) {
    int dif1, dif2;
 
    if(r1 > c1)
        dif1 = r1-c1;
    else 
        dif1 = c1-r1;
 
    if(r2 > c2)
        dif2 = r2-c2;
    else
        dif2 = c2-r2;
 
    int dist1, dist2;
 
    if(c1 > c2)
        dist1 = c1 -c2;
    else 
        dist1 = c2 - c1;
 
    if(r1 > r2)
        dist2 = r1 - r2;
    else
        dist2 = r2 - r1;
 
    if (dif1 % 2 != dif2 % 2) {
        cout << 0 << " ";
    } else {
        if(dist1 == dist2)
            cout << 1 << " ";
        else
            cout << 2 << " ";
    }
    
}
 
void movimentosRei(int r1, int c1, int r2, int c2) {
    int numMov = 0; 
 
    while(r1 != r2 || c1 != c2) {
        if(r1 == r2) {
            if(c1 > c2)
                numMov += c1 - c2;
            else
                numMov += c2 - c1;
            c1 = c2;
        } 
        else if (c1 == c2) {
            if(r1 > r2)
                numMov += r1 - r2;
            else
                numMov += r2 - r1;
            r1 = r2;
        } else {
            if(c1 > c2) 
                c1--;
            else
                c1++;
            if(r1 > r2)
                r1--;
            else
                r1++;
            numMov++;
        }
    }
    
    cout << numMov;
} 
 
int main(int argc, char const *argv[]) {
    int r1;
    int c1;
    int r2;
    int c2;
 
    cin >> r1;
    cin >> c1;
    cin >> r2;
    cin >> c2;
 
    movimentosTorre(r1, c1, r2, c2);
    movimentosBispo(r1, c1, r2, c2);
    movimentosRei(r1, c1, r2, c2);
 
    return 0;
}