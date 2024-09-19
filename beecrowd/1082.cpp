#include <iostream>
#include <vector>

using namespace std;
#define MAX 26
 
int main() {
  int numCases;
  cin >> numCases;

  for (int i = 0; i < numCases; i++) {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    vector<int> connectedComponents(MAX, -1);
    int currentComponent = -1;

    for (int j = 0; j < numEdges; j++) {
      char char1, char2;
      cin >> char1 >> char2;
     
      int vertice1, vertice2;
      vertice1 = (int)char1 - 97;
      vertice2 = (int)char2 - 97;

      int component1 = connectedComponents[vertice1];
      int component2 = connectedComponents[vertice2];
      if (component1 == -1 && component2 == -1) {
        currentComponent++;
        connectedComponents[vertice1] = currentComponent;
        connectedComponents[vertice2] = currentComponent;
      } else if (component1 != -1 && component2 == -1) {
        connectedComponents[vertice2] = component1;
      } else if (component1 == -1 && component2 != -1) {
        connectedComponents[vertice1] = component2;
      } else {
        if (component1 != component2) {
          for (int k = 0; k < MAX; k++) {
            if (connectedComponents[k] == component2) {
              connectedComponents[k] = component1;
            }
          }
        }
      }
    }

    int numComponents = 0;
    vector<bool> componentWasPrinted(MAX, false);
    cout << "Case #" << i + 1 << ":" << endl;
    for (int j = 0; j < numVertices; j++) {
      int componentJ = connectedComponents[j];

      if (componentJ == -1) {
        cout << (char)(j + 97) << "," << endl;
        numComponents++;
        continue;
      }  

      if (componentWasPrinted[componentJ]) {
        continue;
      }

      for (int k = 0; k < MAX; k++) {
        if (connectedComponents[k] == componentJ) {
          cout << (char)(k + 97) << ",";
        }
      }
      cout << endl;
      componentWasPrinted[componentJ] = true;
      numComponents++;
    }

    cout << numComponents << " connected components" << endl << endl;
  }
  return 0;
}