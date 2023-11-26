#include <iostream>
#include<math.h>
#include<sstream>
using namespace std;
#define N  12
string string_A, string_B;
int columns, rows;
float matrix_A[N][N], matrix_B[N][N], matrix_C[N][N], matrix_D[N][N], matrix_E[N][N],
matrix_Fac[N][N], matrix_G[N][N], matrix_H[N][N], matrix_J[N][N];
static float temp[N][N];
int rows1, columns1, rows2, columns2;
string op, ost;
void input_matrix(float[N][N], string);
void view_matrix(float[N][N], int, int);
void addSub(float[N][N], float[N][N], int, int);
void multiply(float[N][N], float[N][N], int, int, int);
void transpose(float[N][N], int, int);
float determinant(float[N][N], int);
void cofactors(float[N][N], float temp[N][N], int, int, int);

int main()
{

	cout << "A= ";
	getline(cin, string_A);
	if (string_A == "exit")
		return 0;

	input_matrix(matrix_A, string_A);
	rows1 = rows;
	columns1 = columns;
	cout << endl << "A matrix is" << endl;

	view_matrix(matrix_A, rows1, columns1);

	cout << "B= ";
	getline(cin, string_B);
	if (string_B == "exit")
		return 0;

	input_matrix(matrix_B, string_B);
	rows2 = rows;
	columns2 = columns;

	cout << endl << "B matrix is" << endl;

	view_matrix(matrix_B, rows2, columns2);

	while (true)
	{
		cout << "select operation to be performed" << endl << endl
			<< "Type 1 to show matrix A" << endl
			<< "Type 2 to show matrix B " << endl
			<< "Type 3 to edit matrix A " << endl
			<< "Type 4 to edit matrix B " << endl
			<< "Type 5 for Addition A+B" << endl
			<< "Type 6 for subtraction A-B" << endl
			<< "Type 7 for multiplication A*B" << endl
			<< "Type 8 for transpose of A " << endl
			<< "Type 9 for transpose of B " << endl
			<< "Type 10 for determinant of A " << endl
			<< "Type 11 for determinant of B " << endl
			<< "Type 12 for division A/B" << endl;

		cin >> op;
		cout << endl;

		if (op == "1")
		{
			cout << endl << "A matrix is" << endl;

			view_matrix(matrix_A, rows1, columns1);
		}
		else if (op == "2")
		{
			cout << endl << "B matrix is" << endl;

			view_matrix(matrix_B, rows2, columns2);
		}
		else if (op == "3") {

			cout << "A= ";
			cin.ignore();
			getline(cin, string_A);
			if (string_A == "exit")
				return 0;
			input_matrix(matrix_A, string_A);
			rows1 = rows;
			columns1 = columns;

			cout << endl << "A matrix is" << endl;

			view_matrix(matrix_A, rows1, columns1);

		}
		else if (op == "4") {

			cout << "B= ";
			cin.ignore();
			getline(cin, string_B);
			if (string_B == "exit")
				return 0;
			input_matrix(matrix_B, string_B);
			rows2 = rows;
			columns2 = columns;

			cout << endl << "B matrix is" << endl;
			view_matrix(matrix_B, rows2, columns2);

		}
		else if (op == "5")
		{
			if (rows1 == rows2 && columns1 == columns2)
			{
				addSub(matrix_A, matrix_B, rows1, columns1);

				cout << endl << "A+B is" << endl;

				view_matrix(matrix_C, rows1, columns1);

			}

			else
				cout << "Can not be added" << endl << endl;

		}
		else if (op == "6") {
			if (rows1 == rows2 && columns1 == columns2)
			{
				addSub(matrix_A, matrix_B, rows1, columns1);

				cout << endl << "A-B is" << endl;

				view_matrix(matrix_J, rows1, columns1);
			}
			else
				cout << "Can not be subtracted" << endl << endl;
		}
		else if (op == "7")
		{
			if (columns1 == rows2)
			{
				multiply(matrix_A, matrix_B, rows1, columns1, columns2);

				cout << "A*B is" << endl;

				view_matrix(matrix_D, rows1, columns2);
			}
			else
				cout << "can not be multiplied" << endl << endl;
		}
		else if (op == "8")
		{
			transpose(matrix_A, rows1, columns1);

			cout << "transpose of A is" << endl;

			view_matrix(matrix_E, columns1, rows1);
		}
		else if (op == "9")
		{
			transpose(matrix_B, rows2, columns2);

			cout << "transpose of B is" << endl;

			view_matrix(matrix_E, columns2, rows2);
		}
		else if (op == "10")
		{
			if (rows1 == columns1)
			{
				cout << "the determinant of A is " << endl
					<< determinant(matrix_A, rows1) << endl;
			}
			else
				cout << "The matrix is not a square matrix " << endl;
		}
		else if (op == "11")
		{
			if (rows2 == columns2) {
				cout << "the determinant of B is " << endl
					<< determinant(matrix_B, rows2) << endl;
			}
			else

				cout << "The matrix is not a square matrix " << endl;
		}
		else if (op == "12")
		{
			if (determinant(matrix_B, rows2) != 0 && rows2 == columns2 && columns1 == rows2) {
				for (int i = 0; i < rows2; i++)
				{
					for (int k = 0; k < columns2; k++)
					{
						cofactors(matrix_B, temp, i, k, rows2);

						matrix_Fac[i][k] = pow(-1, i + k) * determinant(temp, rows2 - 1);

					}
				}
				for (int i = 0; i < rows2; i++)
					for (int k = 0; k < columns2; k++)
						matrix_G[i][k] = matrix_Fac[k][i] / determinant(matrix_B, rows2);

				multiply(matrix_A, matrix_G, rows1, columns1, rows2);

				cout << "A/B is" << endl;

				view_matrix(matrix_D, rows1, rows2);
			}
			else
				cout << "can not be divited" << endl;
		}
		else if (op == "exit")
		{
			cout << "program finished " << endl;
			return 0;
		}
		else
		{
			cout << "Not a valid operation " << endl;
		}
	}

	return 0;
}

void input_matrix(float arr[N][N], string string_A)
{
	columns = 0;
	rows = 0;
	string check1, ign, s;
	stringstream s1(string_A);
	stringstream s2(string_A);
	s1 >> s;
	s2 >> s;
	string n;
	int c = 0;
	for (int i = 0; i <= rows; i++)
	{
		for (int k = 0; k <= c; ++k)
		{
			s1 >> check1;
			if (check1 == ";") {
				rows++;
				s2 >> ign;
			}
			else if (check1 == "]")
				break;
			else
			{
				s2 >> arr[i][k];
				c++;
			}
		}
		columns = c;
		c = 0;
	}
	rows++;
}
void view_matrix(float arr[N][N], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{

		for (int k = 0; k < columns; k++)

			cout << arr[i][k] << "\t";

		cout << endl << endl;
	}

}
float determinant(float arr[N][N], int n) {
	float det = 0;
	float submatrix[N][N];
	if (n == 2)
		return ((arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = arr[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * arr[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}
void cofactors(float matrixIN[N][N], float temp[N][N], int p, int q, int d) {
	int n = 0, m = 0;
	for (int i = 0; i < d; i++)
	{
		for (int k = 0; k < d; k++)
		{
			if (i != p && k != q) {
				temp[n][m] = matrixIN[i][k];
				m++;
			}

			if (m == d - 1)
			{
				n++;
				m = 0;
			}
		}
	}
}
void addSub(float matrix_1[N][N], float matrix_2[N][N], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for (int k = 0; k < columns; k++) {
			matrix_C[i][k] = matrix_1[i][k] + matrix_2[i][k];
			matrix_J[i][k] = matrix_1[i][k] - matrix_2[i][k];
		}
}
void multiply(float matrix_A[N][N], float matrix_B[N][N], int rows1, int columns1, int columns2)
{
	for (int i = 0; i < rows1; i++)
		for (int k = 0; k < columns2; k++)
			matrix_D[i][k] = 0;
	for (int i = 0; i < rows1; i++)
		for (int j = 0; j < columns2; j++)
			for (int k = 0; k < columns1; k++)
				matrix_D[i][j] += matrix_A[i][k] * matrix_B[k][j];
}
void transpose(float[N][N], int rows, int columns)
{
	for (int i = 0; i < columns1; i++)
		for (int k = 0; k < rows1; k++)
			matrix_E[i][k] = matrix_A[k][i];
}