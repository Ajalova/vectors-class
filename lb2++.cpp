#include "Vector.h"
#include <malloc.h>
#include "CSRMatrix.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"

using namespace std;



int main()
{
	double* a = new double[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = 1;
	}
	Vector c1(a);
	cout << "c1=" << c1 << endl;

	for (int i = 0; i < 3; i++)
	{
		a[i] = i;
	}
	Vector m1(a);
	cout << "m1=" << m1 << endl;
	
	for (int i = 0; i < 3; i++)
	{
		a[i] = i*i;
	}
	Vector v1(a);
	cout << "v1=" << v1 << endl;

	for (int i = 0; i < 3; i++)
	{
		a[i] = 2*i;
	}
	Vector c2(a);
	cout << "c2=" << c2 << endl;

	for (int i = 0; i < 3; i++)
	{
		a[i] = 3;
	}
	Vector v3(a);
	cout << "v3=" << v3 << endl;

	for (int i = 0; i < 3; i++)
	{
		a[i] = 3-i;
	}
	Vector v2(a);
	cout << "v2=" << v2 << endl;

	for (int i = 0; i < 3; i++)
	{
		a[i] = -i;
	}
	Vector c3(a);
	cout << "c3=" << c3 << endl;

	
	Vector res = -c1 * m1 * (v1 - c2 * v2) + v3 * c3;
	
	cout << "-c1 * m1 * (v1 - c2 * v2) + v3 * c3=" << res << endl;


	setlocale(0, "russian");
	int ans;
	int n;
	try
		{
		puts("Введите номер команды");
		puts("1- ввод количества векторов и последующий ввод векторов");
		puts("0- завершение программы");

		cin >> ans;

		while ((ans - 1) * ans != 0)
		{
			puts("Введите номер команды еще раз");
			cin >> ans;
		}

		if (ans != 0)
		{
			do {
				puts("Введите кол-во векторов");
				cin >> n;
			} while (n < 1);


			Vector* a = new Vector[n];


			for (int i = 0; i < n; i++)
			{

				puts("Введите способ ввода текущего вектора");
				puts("Тест конструкторов");
				puts("1- задать пустой вектор");
				puts("2- задать пустой вектор n-ной размерности");
				puts("3- задать вектор списком значений");

				cin >> ans;

				while (ans < 0 || ans>3)
				{
					puts("Введите номер команды еще раз");
					cin >> ans;
				}

				if (ans == 1)
				{
					Vector inp1;
					*(a + i) = inp1;

					//cout << (inp1);
				}
				else if (ans == 2)
				{
					int m;
					do {
						puts("Введите размерность текущего вектора");
						cin >> m;
					} while (m < 0);

					Vector inp2(m);
					*(a + i) = inp2;

					//cout << (inp2) << endl;
				}
				else if (ans == 3)
				{
					int m;
					do {
						puts("Введите размерность текущего вектора");
						cin >> m;
					} while (m < 0);
					puts("Введите координаты текущего вектора");

					double* input = new double[m];

					for (int j = 0; j < m; j++)
					{
						cin >> (*(input + j));
					}

					Vector inp3(input);
					(*(a + i)) = inp3;

					//cout << (*(a + i)) << endl;

					delete[] input;

				}


			}
			cout << "введенные вектора сохранены\n\n"
				<< "0- завершение программы\n"
				<< "1  - длинна вектора\n"
				<< "2  - печать тест <<\n"
				<< "3  - тест +=\n"
				<< "4  - тест -=\n"
				<< "5  - тест =\n"
				<< "6  - тест +\n"
				<< "7  - тест -\n"
				<< "8  - тест * на скаляр\n"
				<< "9  - тест скалярного произведения\n"
				<< "10 - тест + унарного\n"
				<< "11 - тест - унарного\n"
				<< "12 - тест оператора приведения типа к указателю на double\n"
				<< "13 - тест []\n"
				<< "14 - размерность вектрора\n"
				<< "15 - ввести матрицу\n"
				<< "16 - печать матрицы\n"
				<< "17 - размерность матрицы\n"
				<< "18 - умножить матрицу на выбранный вектор\n"
				<< "19 - умножить матрицу на скаляр\n"
				<< "20 - кол-во ненулевых элементов в матрице\n";

			ans = 0;
			cin >> ans;

			while (ans < 0 && ans>3)
			{
				puts("Введите номер команды еще раз");
				cin >> ans;
			}
			int num1, nn, num2;
			double scal;
			CSRMatrix matr;
			CSRMatrix matrsk;
			Vector sum;
			int* dim = new int[2];

			while (ans != 0)
			{
				try{
				switch (ans)
				{
				case 1:
					do {
						cout << "Введите номер вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;
					scal = (*(a + num1 - 1)).lengh();
					cout << "|a|=" << scal << endl;
					break;
				case 2:
					for (int i = 0; i < n; i++)
					{
						cout << *(a + i) << "\n";
					}
					break;
				case 3:

					do {
						cout << "Введите номер первого вектора a1" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a1=" << *(a + num1 - 1) << endl;

					do {
						cout << "Введите номер второго вектора a2" << endl;
						cin >> num2;
					} while (num2 < 0 || num2>n);

					cout << "a2=" << *(a - 1 + num2) << endl;

					*(a + num1 - 1) += *(a + num2 - 1);
					cout << "a1+=a2=" << *(a + num1 - 1) << endl;

					break;
				case 4:

					do {
						cout << "Введите номер первого вектора a1" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a1=" << *(a + num1 - 1) << endl;

					do {
						cout << "Введите номер второго вектора a2" << endl;
						cin >> num2;
					} while (num2 < 0 || num2>n);

					cout << "a2=" << *(a - 1 + num2) << endl;

					*(a + num1 - 1) -= *(a + num2 - 1);
					cout << "a1-=a2=" << *(a + num1 - 1) << endl;

					break;

				case 5:

					do {
						cout << "Введите номер первого вектора a1" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a1=" << *(a + num1 - 1) << endl;

					do {
						cout << "Введите номер второго вектора a2" << endl;
						cin >> num2;
					} while (num2 < 0 || num2>n);

					cout << "a2=" << *(a - 1 + num2) << endl;

					*(a + num1 - 1) = *(a + num2 - 1);
					cout << "a1=a2=" << *(a + num1 - 1) << endl;

					break;
				case 6:

					do {
						cout << "Введите номер первого вектора a1" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a1=" << *(a + num1 - 1) << endl;

					do {
						cout << "Введите номер второго вектора a2" << endl;
						cin >> num2;
					} while (num2 < 0 || num2>n);

					cout << "a2=" << *(a - 1 + num2) << endl;

					sum = (*(a + num1 - 1)) + (*(a + num2 - 1));

					cout << "a1+a2=" << sum << endl;

					break;
				case 7:

					do {
						cout << "Введите номер первого вектора a1" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a1=" << *(a + num1 - 1) << endl;

					do {
						cout << "Введите номер второго вектора a2" << endl;
						cin >> num2;
					} while (num2 < 0 || num2>n);

					cout << "a2=" << *(a - 1 + num2) << endl;

					sum = *(a + num1 - 1) - *(a + num2 - 1);

					cout << "a1-a2=" << sum << endl;

					break;
				case 8:

					do {
						cout << "Введите номер вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;

					cout << "Введите  действительное число" << endl;
					cin >> scal;

					sum = (*(a + num1 - 1)) * scal;
					cout << "a*" << scal << "=" << sum << endl;

					sum = scal * (*(a + num1 - 1));
					cout << scal << "*a=" << sum << endl;
					break;
				case 9:

					do {
						cout << "Введите номер первого вектора a1" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a1=" << *(a + num1 - 1) << endl;

					do {
						cout << "Введите номер второго вектора a2" << endl;
						cin >> num2;
					} while (num2 < 0 || num2>n);

					cout << "a2=" << *(a - 1 + num2) << endl;

					sum = (*(a + num1 - 1)) * (*(a + num2 - 1));

					cout << "(a1,a2)=" << sum << endl;

					break;
				case 10:

					do {
						cout << "Введите номер  вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;

					sum = +*(a + num1 - 1);

					cout << "+a" << sum << endl;

					break;
				case 11:

					do {
						cout << "Введите номер  вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;

					sum = -*(a + num1 - 1);

					cout << "-a" << sum << endl;

					break;
				case 12:


					do {
						cout << "Введите номер вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;

					double* d;
					d = static_cast<double*>(*(a + num1 - 1));
					cout << "*(double*(a))={" << *d;
					for (int i = 1; i < (*(a + num1 - 1)).getdim(); i++)
					{
						cout << ", " << *(d + i);
					}
					cout << "}" << endl;
					break;

				case 13:

					do {
						cout << "Введите номер  вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;

					cout << "Введите номер координаты" << endl;
					cin >> nn;

					cout << "a[" << nn << "]=" << (*(a + num1 - 1))[nn] << endl;

					break;
				case 14:

					do {
						cout << "Введите номер вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);

					cout << "a=" << *(a + num1 - 1) << endl;

					nn = (*(a + num1 - 1)).getdim();
					cout << "dim(a)=" << nn << endl;
					break;

				case 15:
					int answer;
					puts("Введите способ ввода текущей матрицы");
					puts("Тест конструкторов");
					puts("1- задать пустой матрицу");
					puts("2- задать пустой матрицу n-ной размерности");
					puts("3- задать матрицу списком значений");

					cin >> answer;

					while (answer < 0 || answer>3)
					{
						puts("Введите номер команды еще раз");
						cin >> answer;
					}

					if (answer == 1)
					{
						CSRMatrix inp1;
						cout << inp1 << endl;
						matr = inp1;
					}
					else if (answer == 2)
					{
						int m, n;
						do {
							puts("Введите кол-во строк матрицы");
							cin >> m;
						} while (m < 0);
						do {
							puts("Введите кол-во столбцов матрицы");
							cin >> n;
						} while (n < 0);

						CSRMatrix inp2(n, m);

						matr = inp2;
					}
					else if (answer == 3)
					{
						int m = 0, n = 0;
						do {
							puts("Введите кол-во строк матрицы");
							cin >> n;
						} while (n < 0);
						do {
							puts("Введите кол-во столбцов матрицы");
							cin >> m;
						} while (m < 0);

						puts("Введите элементы матрицы");

						double** input = new double* [n];

						for (int i = 0; i < n; i++)
						{
							input[i] = new double[m];
							for (int j = 0; j < m; j++)
							{
								cin >> input[i][j];
							}
						}

						CSRMatrix inp3(input);
						cout << inp3;;
						matr = inp3;

						//delete[] input;
					}
					cout << "введенная матрица сохранена\n";
					break;
				case 16:

					cout << matr << "\n";

					break;
				case 17:

					matr.getdim(dim);
					cout << "dim(M)={" << dim[0] << ", " << dim[1] << "}\n";
					break;
				case 18:
					do {
						cout << "Введите номер вектора a" << endl;
						cin >> num1;
					} while (num1 < 0 || num1>n);
					sum = matr * (*(a + num1 - 1));
					cout << "a=" << *(a + num1 - 1) << "\n" << matr << "\n" << "M*a=" << sum << endl;


					break;
				case 19:

					cout << "Введите  действительное число" << endl;
					cin >> scal;

					matrsk = matr * scal;
					cout << "M*" << scal << "=\n" << matrsk << endl;
					matrsk = scal * matr;
					cout << scal << "*M=\n" << matrsk << endl;

					cout << "Присвоить новое значение матрице?\n 1 - да\n 2 - нет\n" << endl;
					cin >> answer;

					while ((answer * answer - 3 * answer + 2) != 0)
					{
						puts("Введите номер команды еще раз");
						cin >> answer;
					}
					if (answer == 1)matr = matrsk;

					break;
				case 20:
					nn = matr.count_not_nul();
					cout << "Ненулевых элементов в матрице - " << nn << endl;
					break;
				}
			}
				catch (std::bad_alloc& exception) {
					cerr << "size error" << endl;
				}
				catch (OutOfRangeException& exception) {
					cerr << exception.what() << endl;
				}
				catch (IncompatibleDimException& exception) {
					cerr << exception.what() << endl;
				}
				catch (std::exception& exception) {
					cerr << exception.what() << endl;
				}

				cout << "0 - завершение программы\n"
					<< "1  - длинна вектора\n"
					<< "2  - печать тест <<\n"
					<< "3  - тест +=\n"
					<< "4  - тест -=\n"
					<< "5  - тест =\n"
					<< "6  - тест +\n"
					<< "7  - тест -\n"
					<< "8  - тест * на скаляр\n"
					<< "9  - тест скалярного произведения\n"
					<< "10 - тест + унарного\n"
					<< "11 - тест - унарного\n"
					<< "12 - тест оператора приведения типа к указателю на double\n"
					<< "13 - тест []\n"
					<< "14 - размерность вектрора\n"
					<< "15 - ввести матрицу\n"
					<< "16 - печать матрицы\n"
					<< "17 - размерность матрицы\n"
					<< "18 - умножить матрицу на выбранный вектор\n"
					<< "19 - умножить матрицу на скаляр\n"
					<< "20 - кол-во ненулевых элементов в матрице\n";

				cin >> ans;

				while (ans < 0 && ans>3)
				{
					puts("Введите номер команды еще раз");
					cin >> ans;
				}
			}
		}
	}


	catch (std::bad_alloc& exception) {
		cerr << "size error" << endl;
	}
	catch (OutOfRangeException& exception) {
		cerr << exception.what() << endl;
	}
	catch (IncompatibleDimException& exception) {
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception) {
		cerr << exception.what() << endl;
	}

	

	return 0;
}






