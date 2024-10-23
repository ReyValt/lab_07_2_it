#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
bool SearchMinOfMax(int** a, const int k, const int n, int& minMax);

int main() {
    srand((unsigned)time(NULL)); 
    int Low = 1;
    int High = 100;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n; 

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High); 
    Print(a, k, n); 

    int minMax;
    if (SearchMinOfMax(a, k, n, minMax))
        cout << "min of max = " << minMax << endl;
    else
        cout << "there are no even rows" << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1); 
}


void Print(int** a, const int k, const int n) {
   
    cout << "-";
    for (int j = 0; j < n; j++) {
        cout << "--------";
    }
    cout << endl;

    for (int i = 0; i < k; i++) {
        cout << "|"; 
        for (int j = 0; j < n; j++) {
            cout << setw(7) << a[i][j] << "|"; 
        }
        cout << endl;

        
        cout << "-";
        for (int j = 0; j < n; j++) {
            cout << "--------"; 
        }
        cout << endl;
    }
}



bool SearchMinOfMax(int** a, const int k, const int n, int& minMax) {
    bool found = false; 
    int maxInEvenRow;

    for (int i = 0; i < k; i += 2) { 
        maxInEvenRow = a[i][0]; 
        for (int j = 1; j < n; j++) {
            if (a[i][j] > maxInEvenRow) {
                maxInEvenRow = a[i][j]; 
            }
        }
   
        if (!found || (found && maxInEvenRow < minMax)) {
            minMax = maxInEvenRow;
            found = true;
        }
    }

    return found;
}
