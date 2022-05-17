#include "iostream"
using namespace std;



int main() {
    //declare matrices
    int A[3][3] = {};
    int B[3][3] = {};
    int C[3][3] = {};

    //input matrix A
    cout << "\nEnter the numbers of matrix A (3x3) : \n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> A[i][j];
        }
    }

    //input matrix B
    cout << "\nEnter the numbers of matrix B (3x3) : \n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> B[i][j];
        }
    }
    

    //Matrix A
    cout << "\nA Matrix\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }

    //Matrix B
    cout << "\nB Matrix\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << B[i][j] << "\t";
        }
        cout << "\n";
    }

    //Matrix C (= A + B)
    cout << "\nC Matrix\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }


    //Matrix C multiply by 3
    cout << "\nC Matrix x 3\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << C[i][j] * 3 << "\t";
        }
        cout << endl;
    }


    return 0;
}



