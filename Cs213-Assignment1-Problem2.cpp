// Program: Cs213-Assignment1-Problem2.cpp
// Purpose: Demonstrate use of sturctures and overloading
// Author:  Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0
// Students : Mounir Sabry Youssef Ahmed   20170301.
//            Mostafa Mohamed Mohamed      20170295.
//            Mostafa Mohamed Abd Al-Hamid 20170294.

#include <iostream>
#include <valarray>
#include <iomanip>

using namespace std;

// A structure to store a matrix
struct matrix
{
  valarray<int> data;       //valarray that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
// Functions.

// Mounir Functions.

matrix operator+ (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator- (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator* (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+ (matrix mat1, int scalar); // Add a scalar
matrix operator- (matrix mat1, int scalar); // Subtract a scalar
matrix operator* (matrix mat1, int scalar); // Multiple by scalar

// Mostafa Abd-Hamid Functions.

// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar); // change mat & return new
matrix operator-= (matrix& mat, int scalar); // change mat & return new
void operator++ (matrix& mat); // Add 1 to each element ++mat
void operator-- (matrix& mat); // Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

// Mostafa Mohamed Functions.

// The first operator << takes an ostream and a matrix and return the
// the same ostream so it is possible to cascade output like
// cout << matrix1 << matrix2 << endl;
ostream& operator<< (ostream& out, matrix mat);
// Print matrix as follows (2 x 3) 4 6 8
// and return ostream to cascade printing 9 12 123
bool operator== (matrix mat1, matrix mat2); // True if identical
bool operator!= (matrix mat1, matrix mat2); // True if not same
bool isSquare (matrix mat); // True if square matrix
bool isSymetric (matrix mat); // True if square and symmetric
bool isIdentity (matrix mat); // True if square and identity
matrix transpose(matrix mat); // Return new matrix with the transpose

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);

 cout<<matrix transpose(data1)<<endl;


  return 0;
}

// Functions Definitions.
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data.resize (row * col);
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}

/// Mounir Functions.

matrix operator+ (matrix mat1, matrix mat2) // Add if same dimensions
{
    if( ( mat1.row == mat2.row ) && ( mat1.col == mat2.col ) )
    {
        int array_sum[mat1.row * mat1.col]; // OR [mat2.row * mat2.col]
        for (int i = 0 ; i < mat1.row * mat1.col ; i++)
        {
            array_sum[i] = mat1.data[i] + mat2.data[i];
        }
        matrix mat_sum;
        createMatrix(mat1.row, mat1.col, array_sum, mat_sum);
        return mat_sum;
    }
    else
    {
        cout << "The Matrices Can not be Added" << endl
             << "Because The Dimensions are not Equal." << endl
             << "The Program Will End." << endl;
        exit(1);
    }
}
matrix operator- (matrix mat1, matrix mat2) // Sub if same dimensions
{
    if( ( mat1.row == mat2.row ) && ( mat1.col == mat2.col ) )
    {
        int array_sub[mat1.row * mat1.col]; // OR [mat2.row * mat2.col]
        for(int i = 0 ; i < mat1.row * mat1.col ; i++)
        {
            array_sub[i] = mat1.data[i] - mat2.data[i];
        }
        matrix mat_sub;
        createMatrix(mat1.row, mat1.col, array_sub, mat_sub);
        return mat_sub;
    }
    else
    {
        cout << "The Matrices Can not be Subtracted" << endl
             << "Because The Dimensions are not Equal." << endl
             << "The Program Will End." << endl;
        exit(1);
    }
}
matrix operator* (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    if( mat1.col == mat2.row )
    {

    }
    else
    {
        cout << "The Matrices Can not Be Multiplied" << endl
             << "Because The # Of Columns Of The First Matrix doesn't " << endl
             << "Equal The # Of Rows Of The Second Matrix." << endl
             << "The Program Will End." << endl;
             exit(1);
    }
}
matrix operator+ (matrix mat1, int scalar) // Add a scalar
{
    for (int i = 0; i < mat1.row * mat1.col; i++)
    {
        mat1.data[i] += scalar;
    }
}
matrix operator- (matrix mat1, int scalar) // Subtract a scalar
{
    for (int i = 0; i < mat1.row * mat1.col; i++)
    {
        mat1.data[i] -= scalar;
    }
}
matrix operator* (matrix mat1, int scalar) // Multiple by scalar
{
    for (int i = 0; i < mat1.row * mat1.col; i++)
    {
        mat1.data[i] *= scalar;
    }
}


/// Mostafa Abd-Hamid Functions.

// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2) // mat1 changes & return
// new matrix with the sum
{

}
matrix operator-= (matrix& mat1, matrix mat2) // mat1 changes + return new
// matrix with difference
{

}
matrix operator+= (matrix& mat, int scalar) // change mat & return new
{

}
matrix operator-= (matrix& mat, int scalar) // change mat & return new
{

}
void operator++ (matrix& mat) // Add 1 to each element ++mat
{

}
void operator-- (matrix& mat) // Sub 1 from each element --mat
{

}
istream& operator>> (istream& in, matrix& mat)
{

}
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

/// Mostafa Mohamed Functions.

// The first operator << takes an ostream and a matrix and return the
// the same ostream so it is possible to cascade output like
// cout << matrix1 << matrix2 << endl;
ostream& operator<< (ostream& out, matrix mat)
{
    cout<<"the data of the matrix is: ";
    for(int i=0; i<mat.col*mat.row;i++)
    {
        out<<mat.data[i];
    }
    return out;
}
// Print matrix as follows (2 x 3) 4 6 8
// and return ostream to cascade printing 9 12 123
bool operator== (matrix mat1, matrix mat2) // True if identical
{
    for(int i=0; i<mat1.row*mat1.col; i++)
    {
        if(mat1.data[i]!=mat2.data[i])
        {
            return false;
        }
    }
    return true;
}
bool operator!= (matrix mat1, matrix mat2) // True if not same
{
     for(int i=0; i<mat1.row*mat1.col; i++)
        {
            if(mat1.data[i]!=mat2.data[i])
            {
                return true;
            }
        }
        return false;
}
bool isSquare (matrix mat) // True if square matrix
{
    if(mat.col==mat.row)
    {
        return true;
    }
    else{
        return false;
    }
}
bool isSymetric (matrix mat) // True if square and symmetric
{
    matrix c=transpose(mat);
    for(int i=0 ; i<mat.data.size();i++)
    {
        if(c.data[i]!=mat.data[i])
        {
            return false;
        }
    }
    return true;
}
bool isIdentity (matrix mat) // True if square and identity
{
    for (int i=0; i<mat.col*mat.row; i++)
    {
        if (i*(mat.col+1)!=1)
        {
            return false;
        }
    }
    int counter=0;
    for (int i=0; i<mat.col*mat.row; i++)
    {
        if(mat.data[i]!=0 && mat.data[i]!=1)
        {
            return false;
        }
        if(mat.data[i]==1)
        {
            counter++;
        }
        if(counter==mat.col)
        {
            return true;
        }
        else{
            return false;
        }
    }
}
matrix transpose(matrix mat) // Return new matrix with the transpose
{
    matrix c;
    c.col=mat.row;
    c.row=mat.col;
    c.data.resize(mat.col*mat.row);
    int x=0;
    for(int i=0; i<c.row; i++)
    {
        for(int j=0; j<mat.data.size();j+=c.row)
        {
            c.data[x]=mat.data[i+j];
            x++;
        }
    }
    return c;
}
