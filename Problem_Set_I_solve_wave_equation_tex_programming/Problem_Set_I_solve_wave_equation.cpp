// The C++ standard version:
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std ;

int main(int argc, char** argv)
{
    // Declaring 2D array
    int arr[4][4];

    // Initialize 2D array using loop
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i + j;
        }
    }
    return 0;
}
