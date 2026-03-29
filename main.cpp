#include <iostream>

using namespace std;

const int SIZE = 4;

class Matrix
{
private:                  // private = only the class can use it
    int data[SIZE][SIZE]; // this is just my matrix (4 rows and 4 collims)

public: // public => anything can here can be used outside the class
    // PART 1: read matrix => it just reads the values that it gets from user and it will fills the  matrix
    void readFromStdin() // reads input
    {
        int i, j;

        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    // PART 2: display matrix: will go through each row(i) & collum(j) then prints each value in matrixdata. adds a space between #'s and moves
    // to a new line after each row(i) will also add an blank one at the end
    void display() const
    {
        int i, j;

        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    // PART 3: add matrices : It just adds the matching positions from two matrices and gives you a new matrix with the sums which is how you
    // actually do noremal matrix addition
    Matrix operator+(const Matrix &other) const
    {
        Matrix result;
        int i, j;

        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // PART 4: multiply matrices: It just multiplies mt matrix rows from the first matrix with columns from the second matrix, then adds them up.
    // this is how you actually do normal matrix multiplcation
    Matrix operator*(const Matrix &other) const
    {
        Matrix result;
        int i, j, k;

        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                result.data[i][j] = 0;

                for (k = 0; k < SIZE; k++)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // PART 5: diagonal sum: This just adds all values from both diagonals of the matrix
    int sumOfDiagonals() const
    {
        int i;
        int sum = 0;

        for (i = 0; i < SIZE; i++)
        {
            sum += data[i][i];
            sum += data[i][SIZE - 1 - i];
        }

        return sum;
    }

    // PART 6: swap rows: it will swap 2 rows in my matrix
    void swapRows(int row1, int row2)
    {
        int j;
        int temp;

        if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE)
        {
            cout << "Invalid row numbers!!!" << endl;
            return;
        }

        for (j = 0; j < SIZE; j++)
        {
            temp = data[row1][j];
            data[row1][j] = data[row2][j];
            data[row2][j] = temp;
        }
    }
};

// pretty much all from code source program template
int main()
{
    Matrix mat1, mat2, sum, product;

    // PART 1
    cout << "Enter Matrix 1: " << endl;
    mat1.readFromStdin();

    cout << "Enter Matrix 2: " << endl;
    mat2.readFromStdin();

    // PART 2
    cout << "Matrix 1: " << endl;
    mat1.display();

    cout << "Matrix 2: " << endl;
    mat2.display();

    // PART 4
    product = mat1 * mat2;
    cout << "Product of matrices: " << endl;
    product.display();

    // PART 4
    sum = mat1 + mat2;
    cout << "Sum of matrices: " << endl;
    sum.display();

    // PART 5
    cout << "Sum of diagonals of Matrix 1: "
         << mat1.sumOfDiagonals() << endl;

    // PART 6
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows: " << endl;
    mat1.display();

    return 0;
}