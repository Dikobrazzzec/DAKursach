#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

class MatrixWorker {
protected:

	int rows, cols, i, j;
	double** Matrix;

public:

	MatrixWorker() {}

	MatrixWorker(int rows_, int cols_) {
		rows = rows_;
		cols = cols_;
	}

	void Maker() {
		Matrix = new double* [rows];
		for (i = 0; i < rows; i++) {
			Matrix[i] = new double[cols];
		}
	}

	void  Filler() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				Matrix[i][j] = rand() % 40-20;
			}
		}
	}

	void HandFiller() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << "Enter [" << i + 1 << "][" << j + 1 << "]" << endl;
				cin >> Matrix[i][j];
			}
		}
	}

	void Print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	MatrixWorker operator+( MatrixWorker B_) {
		MatrixWorker C_(rows, cols);
		C_.Maker();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				C_.Matrix[i][j] = Matrix[i][j] + B_.Matrix[i][j];
			}
		}
		return C_;
	}

	MatrixWorker operator-(MatrixWorker B_) {
		MatrixWorker C_(rows, cols);
		C_.Maker();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				C_.Matrix[i][j] = Matrix[i][j] - B_.Matrix[i][j];
			}
		}
		return C_;
	}

	MatrixWorker MultNum( float number) {
		MatrixWorker C_(rows, cols);
		C_.Maker();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				C_.Matrix[i][j] = Matrix[i][j] * number;
			}
		}
		return C_;
	}

	MatrixWorker operator*(MatrixWorker B_) {
		MatrixWorker C_(rows, B_.cols);
		C_.Maker();
		if (cols != B_.rows) {
			cout << "The number of columns of the first matrix is ​​not equal to the number of rows of the second matrix. Multiplication is not possible";
		}
		else {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < B_.cols; j++) {
					C_.Matrix[i][j] = 0;
					for (int k = 0; k < cols; k++) {
						C_.Matrix[i][j] += Matrix[i][k] * B_.Matrix[k][j];
					}
				}
			}
			return C_;
		}
	}

	void DiagonalProperty() {
		if (rows != cols) {
			cout << "Matrix isn't diagonal"<<endl;
		}
		else {
			bool tester = false;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (i != j) {
						if (Matrix[i][j] == 0) {
							tester = true;
						}
						else {
							tester = false;
						}
						if (tester == false) {
							cout << "Matrix isn't diagonal" << endl;
							break;
						}
					}
				}
				if (tester == false) {
					break;
				}
			}
			if (tester == true) {
				cout << "Matrix is diagonal" << endl;
			}
		}
	
	}

    int TranspositionRows() {
		float container;
		int row1, row2;
		cout << "Enter row1" << endl;
		cin >> row1;
		if (row1==0) {
			cout << "There isn't " << row1 << ". Enter correct value" << endl;
			return 0;
		}
		if (row1 > rows) {
			cout << "There isn't " << row1 << ". Enter correct value"<<endl;
			return 0;
		}
		else {
			cout << "Enter row2" << endl;
			cin >> row2;
		}
		if (row2 == 0) {
			cout << "There isn't " << row2 << ". Enter correct value" << endl;
			return 0;
		}
		if (row2 > rows) {
			cout << "There isn't " << row2 << ". Enter correct value" << endl;
		}
		else {
			row1--;
			row2--;
			for (int j = 0; j < cols; j++) {
				container = Matrix[row1][j];
				Matrix[row1][j] = Matrix[row2][j];
				Matrix[row2][j] = container;
			}
		}
		return 0;
	}

	int TranspositionCols() {
		float container;
		int col1, col2;
		cout << "Enter col1" << endl;
		cin >> col1;
		if (col1 == 0) {
			cout << "There isn't " << col1 << ". Enter correct value" << endl;
			return 0;
		}
		if (col1 > cols) {
			cout << "There isn't " << col1 << ". Enter correct value" << endl;
			return 0;
		}
		else {
			cout << "Enter col2" << endl;
			cin >> col2;
		}
		if (col2 == 0) {
			cout << "There isn't " << col2 << ". Enter correct value" << endl;
			return 0;
		}
		if (col2 > cols) {
			cout << "There isn't " << col2 << ". Enter correct value" << endl;
		}
		else {
			col1--;
			col2--;
			for (int i = 0; i < rows; i++) {
				container = Matrix[i][col1];
				Matrix[i][col1] = Matrix[i][col2];
				Matrix[i][col2] = container;
			}
		}
		return 0;
	}

	MatrixWorker Transpose() {
		MatrixWorker C_(cols, rows);
		C_.Maker();
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				C_.Matrix[j][i] = Matrix[i][j];
			}
		}
		return C_;
	}


	void ClassTest(MatrixWorker A_, MatrixWorker B_) {

	}
};

class ComplexMatrix : public MatrixWorker {
private:
	ComplexMatrix** Matrix;
	double Im, Re;
public:
	ComplexMatrix() {}
	
	ComplexMatrix(int rows_, int cols_) {
		rows = rows_;
		cols = cols_;
	}

	void Maker() {
		Matrix = new ComplexMatrix* [rows];
		for (i = 0; i < rows; i++) {
			Matrix[i] = new ComplexMatrix[cols];
		}
	}

	void  Filler() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				Matrix[i][j].Re = rand() % 40-20;
				Matrix[i][j].Im = rand() % 40-20;
			}
		}
	}

	void HandFiller() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << "Enter Re [" << i + 1 << "][" << j + 1 << "]" << endl;
				cin >> Matrix[i][j].Re;
				cout << "Enter Im [" << i + 1 << "][" << j + 1 << "]" << endl;
				cin >> Matrix[i][j].Im;
			}
		}
	}

	void Print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << Matrix[i][j].Re;
				if (Matrix[i][j].Im < 0) {
					cout << Matrix[i][j].Im<<"*i ";
				}
				else {
					cout <<"+"<< Matrix[i][j].Im << "*i ";
				}
			}
			cout << endl;
		}
	}

	ComplexMatrix Transpose() {
		ComplexMatrix C_(cols, rows);
		C_.Maker();
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				C_.Matrix[j][i] = Matrix[i][j];
			}
		}
		return C_;
	}


	void ComplexConjugate() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j ++) {
				Matrix[i][j].Im = 0 - Matrix[i][j].Im;
			}
		}
	}

	ComplexMatrix HermitConjugate(ComplexMatrix Parametr) {
		Parametr = Parametr.Transpose();
		Parametr.ComplexConjugate();
		return Parametr;
	}
};


void FirstStarter() {
	MatrixWorker A(4, 4);
	A.Maker();
	A.Filler();
	A.Print();
	cout << "........................................................" << endl;
	MatrixWorker B(4, 4);
	B.Maker();
	B.Filler();
	B.Print();
	cout << "........................................................" << endl;
	MatrixWorker C(4, 4);
	C.Maker();
	C.Filler();
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................Addition.............................." << endl;
	cout << "........................................................" << endl;
	C = A + B;
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................Substraction.........................." << endl;
	cout << "........................................................" << endl;
	C = A - B;
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................MultiplicationNumber.................." << endl;
	cout << "........................................................" << endl;
	C = A.MultNum(5);
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................Multiplication........................" << endl;
	cout << "........................................................" << endl;
	C = A * B;
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................Transpose............................." << endl;
	cout << "........................................................" << endl;
	C = C.Transpose();
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................DiagonalProperty......................" << endl;
	cout << "........................................................" << endl;
	C.DiagonalProperty();
	cout << "........................................................" << endl;
	cout << "..................TranspositionCols....................." << endl;
	cout << "........................................................" << endl;
	C.TranspositionCols();
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................TranspositionRows....................." << endl;
	cout << "........................................................" << endl;
	C.TranspositionRows();
	C.Print();
}

void SecondStarter() {
	ComplexMatrix Q(3, 3);
	Q.Maker();
	Q.Filler();
	Q.Print();
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "|||||||||||||||||||ComplexConjugate|||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	Q.ComplexConjugate();
	Q.Print();
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "|||||||||||||||||||HermitConjugate||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	Q=Q.HermitConjugate(Q);
	Q.Print();
}

void Test() {
	 
}

double determ(int** Arr, int size)
{
	int i, j;
	double det = 0;
	int** matr;
	if (size == 1)
	{
		det = Arr[0][0];
	}
	else if (size == 2)
	{
		det = Arr[0][0] * Arr[1][1] - Arr[0][1] * Arr[1][0];
	}
	else
	{
		matr = new int* [size - 1];
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size - 1; ++j)
			{
				if (j < i)
					matr[j] = Arr[j];
				else
					matr[j] = Arr[j + 1];
			}
			det += pow((double)-1, (i + j)) * determ(matr, size - 1) * Arr[i][size - 1];
		}
		delete[] matr;
	}
	return det;
}

int main()
{
	//srand(time(NULL));
	int size = 3;
	int** Arr;
	Arr = new int* [size];
	for (int i = 0; i < size; ++i)
		Arr[i] = new int[size];
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			Arr[i][j] = 0 + rand() % 5 - 1 + 1;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			std::cout << Arr[i][j] << ' ';
		std::cout << std::endl;
	}
	std::cout << determ(Arr, size) << '\n';
	for (int i = 0; i < size; ++i)
		delete[] Arr[i];
	delete[] Arr;
	return 0;
}


