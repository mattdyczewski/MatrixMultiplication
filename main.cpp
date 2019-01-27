/**
 * main.cpp is a matrix multiplication program
 *
 * @author Matthew Dyczewski
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * function memberSum calculates the dot product of the specified row of a by the specified column of b
 *
 * @param a The first array
 * @param b The second array
 * @param row The specified row of A
 * @param column The specified column of B
 * @param a1RowSize The size of n (number of entries in a row of A which is equal to the number of entries in a column of B)
 * @return returns the sum of the dot product calculated in the funciton
 */
int memberSum(vector<vector<int>> a, vector<vector<int>> b, int row, int column, int a1RowSize);

/**
 * function main begins with program execution
 *
 * @return 0 if code ran to completion
 */
int main() {
    int numRowsArr1, numColumnsArr1, numRowsArr2, numColumnsArr2, temp;
    bool valid;
    cout << "Enter the size of the 1st matrix (m x n)" << endl;
    cin >> numRowsArr1 >> numColumnsArr1;
    cout << "Enter the size of the 2nd matrix (n x p)" << endl;
    cin >> numRowsArr2 >> numColumnsArr2;

    //Verifies the result is defined and asks for new input if it is not
    if(numColumnsArr1 == numRowsArr2){
        cout << "Result is defined as a " << numRowsArr1 << " x " << numColumnsArr2 << endl;
        valid = true;
    }
    else {
        cout << "Result is not defined, please try again." << endl;

        valid = false;
    }
    while (!valid){
        cout << "Enter the size of the 1st matrix (m x n)" << endl;
        cin >> numRowsArr1 >> numColumnsArr1;
        cout << "Enter the size of the 2nd matrix (n x p)" << endl;
        cin >> numRowsArr2 >> numColumnsArr2;
        if(numColumnsArr1 == numRowsArr2){
            cout << "Result is defined as a " << numRowsArr1 << " x " << numColumnsArr2 << endl;
            valid = true;
        }
        else {
            cout << "Result is not defined, please try again." << endl;

            valid = false;
        }
    }

    //Defines matrices and row vector which is used to populate matrices
    vector<vector<int>> arr1;
    vector<vector<int>> arr2;
    vector<vector<int>> result;
    vector<int> row;

    //Populates matrix 1
    for (int i = 0; i < numRowsArr1; i++){
        for(int j = 0; j < numColumnsArr1; j++){
            cout << "Enter the value for " << i + 1 << ", " << j + 1 << " of matrix 1" << endl;
            cin >> temp;
            row.push_back(temp);
        }
        arr1.push_back(row);
        row.clear();
    }

    //Populates matrix 2
    for (int i = 0; i < numRowsArr2; i++){
        for(int j = 0; j < numColumnsArr2; j++){
            cout << "Enter the value for " << i + 1 << ", " << j + 1 << " of matrix 2" << endl;
            cin >> temp;
            row.push_back(temp);
        }
        arr2.push_back(row);
        row.clear();
    }

    //Populates result matrix with all 0's
    row.resize(numRowsArr1);
    for(int i = 0; i < numColumnsArr2; i++){
        result.push_back(row);
    }

    //Populates result matrix with entries such that the ith row is multiplied by the jth column
    for (int i = 0; i < numRowsArr1; i++){
        for (int j = 0; j < numColumnsArr2; j++){
            result[i][j] = memberSum(arr1, arr2, i, j, numColumnsArr1);
        }
     }

    cout << "The result of multiplying: " << endl;

    //Prints first matrix
    for (int i = 0; i < numRowsArr1; i++){
        for (int j = 0; j < numColumnsArr1; j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "by: " << endl;

    //Prints second matrix
    for (int i = 0; i < numRowsArr2; i++){
        for (int j = 0; j < numColumnsArr2; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Is: " << endl;

    //Prints result matrix
    for (int i = 0; i < numRowsArr1; i++){
        for (int j = 0; j < numColumnsArr2; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int memberSum(vector<vector<int>> a, vector<vector<int>> b, int row, int column, int a1RowSize){
    int sum = 0;
    for (int i = 0; i < a1RowSize; i++){
            sum += a[row][i]*b[i][column];
    }
    return sum;
}