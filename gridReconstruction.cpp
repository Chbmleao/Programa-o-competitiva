#include <iostream>
#include <vector>
using namespace std;

void printGrid(vector<vector<int>> grid, int n) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

int main(int argc, char const *argv[]) {
    int numTests = 0;
    std::cin >> numTests;

    for (int i = 0; i < numTests; i++) {
        int n = 0;
        std::cin >> n;

        vector<vector<int>> grid(2, vector<int> (n, 0));

        grid[1][n-1] = n * 2;
        grid[0][0] = n*2 - 1;

        int max = n*2 - 1;
        int min = 0;
        int sum1 = 0;
        int sum2 = 0;
        int negative = true;

        for (int j = 0; j+1 < n; j++) {
            if(negative) {
                if(abs((sum1 - min+1) - (sum2 - min+2)) < abs((sum2 - min+1) - (sum1 - min+2))) {
                    sum1 -= min++;
                    grid[0][j+1] = min;
                    sum2 -= min++;
                    grid[1][j] = min;
                } else {
                    sum2 -= min++;
                    grid[1][j] = min;
                    sum1 -= min++;
                    grid[0][j+1] = min;
                }
            } else {
                if(abs((sum1 + max-1) - (sum2 + max-2)) < abs((sum2 + max-1) - (sum2 + max-2))) {
                    sum1 += max--;
                    grid[0][j+1] = max;
                    sum2 += max--;
                    grid[1][j] = max;
                } else {
                    sum2 += max--;
                    grid[1][j] = max;
                    sum1 += max--;
                    grid[0][j+1] = max;
                }
            }
            negative = !negative;
        }
        
        printGrid(grid, n);
    }
    

    return 0;
}
