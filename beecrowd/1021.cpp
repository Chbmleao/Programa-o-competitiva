#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
 
int main() {
  double total;
  cin >> total;

  vector<int> notes = {100, 50, 20, 10, 5, 2};
  vector<int> coins = {100, 50, 25, 10, 5, 1};
  vector<string> coinsStr = {"1.00", "0.50", "0.25", "0.10", "0.05", "0.01"};

  cout << "NOTAS:" << endl;
  for (int i = 0; i < notes.size(); ++i) {
    int quantity = total / notes[i];
    total -= quantity * notes[i];
    cout << quantity << " nota(s) de R$ " << notes[i] << ".00" << endl;
  }
  cout << "MOEDAS:" << endl;
  total *= 100;
  for (int i = 0; i < coins.size(); ++i) {
    int quantity = total / coins[i];
    total -= quantity * coins[i];
    cout << quantity << " moeda(s) de R$ " << coinsStr[i] << endl;
  }
  return 0;
}