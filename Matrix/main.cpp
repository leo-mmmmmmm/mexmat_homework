// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Matrix.cpp"

int main()
{
    Matrix matrix1(3, 'e');
    matrix1.printMatrix();

    matrix1.getE(2, 1);
    matrix1.setE(2, 1, 10);
    matrix1.printMatrix();
    Matrix matrix2 = matrix1;
    matrix2.printMatrix();
    matrix2 += matrix1;
    matrix2.printMatrix();
    matrix2.printSize();

    matrix2.transpose();
    matrix2.printMatrix();
    double vector[3] = { 1, 2, 3 };
    matrix2.matrixVector(vector);
    std::cout << vector[0] << " " << vector[1] << " " << vector[2] << " " << std::endl;
    std::cout << vector[0] << " " << vector[1] << " " << vector[2] << " " << std::endl;

    /*
    Matrix matrix3(3);
    matrix3.printMatrix();
    matrix3 = matrix2 + matrix1;
    matrix3.printMatrix();
    matrix2 = matrix2 + matrix1;
    matrix2.printMatrix();
    */

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
