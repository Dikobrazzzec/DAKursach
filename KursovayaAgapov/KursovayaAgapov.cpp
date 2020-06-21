#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

class MatrixWorker {
public:
	int rows, cols, i, j;
	int** Matrix;

	MatrixWorker() {}

	MatrixWorker(int rows_, int cols_) {
		rows = rows_;
		cols = cols_;
	}

	void Maker() {
		Matrix = new int* [rows];
		for (i = 0; i < rows; i++) {
			Matrix[i] = new int[cols];
		}
	}

	void  Filler() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				Matrix[i][j] = rand() % 20;
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
			int i2 = 0;
			int j2 = 0;
			int j3 = 0;
			int i3 = 0;
			int counter = rows * B_.cols;
			for (int y = 0; y < counter; y++) {
				for (int i1 = 0; i1 < rows; i1++) {
					for (int j1 = 0; j1 < cols; j1++) {
						C_.Matrix[i3][j3] += Matrix[i1][j1] * B_.Matrix[i2][j2];
						i2++;
						if (i2 == 3) { i2 = 0; }
						//смотри блокнот
					}
				}
			}
		}
		return C_;
	}

	//c = new double* [row1];
	//for (int i = 0; i < row1; i++)
	//{
	//	c[i] = new double[col2];
	//	for (int j = 0; j < col2; j++)
	//	{
	//		c[i][j] = 0;
	//		for (int k = 0; k < col1; k++)
	//			c[i][j] += a[i][k] * b[k][j];
	//	}
	//}
	////
	


	void test(MatrixWorker A_, MatrixWorker B_) {
		MatrixWorker C_(A_.rows, B_.cols);
		C_.Maker();
		for (int i = 0; i < A_.rows; i++) {
			for (int j = 0; j < B_.cols; j++) {
				C_.Matrix[i][j] = 0;
				for (int k = 0; k < A_.cols; k++) {
					C_.Matrix[i][j] += A_.Matrix[i][k] * B_.Matrix[k][j];
				}
			}
		}
		C_.Print();
	}
};

void StarterTest() {
	MatrixWorker Q(4, 4);
	Q.Maker();
	Q.Filler();
	Q.Print();
	MatrixWorker W(4, 4);
	W.Maker();
	W.Filler();
	W.Print();
	Q.test(Q, W);
}

int main()
{
	MatrixWorker A (4,4);
	A.Maker();
	A.Filler();
	A.Print();
	cout << "........................................................" << endl;
	////cout << A.Matrix[0][2]<<endl;
	//cout << A.Matrix[1][3] << endl;
	////cout << A.Matrix[3][2] << endl;
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			cout << A.Matrix[i][j] << endl;
		}
	}
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
	cout << "..................Addition................" << endl;
	cout << "........................................................" << endl;
	C = A + B;
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................Substraction............................" << endl;
	cout << "........................................................" << endl;
	C = A - B;
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................MultiplicationNumber............................" << endl;
	cout << "........................................................" << endl;
	C = A.MultNum(5);
	C.Print();
	cout << "........................................................" << endl;
	cout << "..................Multiplication............................" << endl;
	cout << "........................................................" << endl;
	//C = A * B;
	//C.Print();
	cout << "-----------------------------------------------------------------------" << endl;
	StarterTest();
}
