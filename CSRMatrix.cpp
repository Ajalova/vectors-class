#include "CSRMatrix.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include "Vector.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"


// конструктор принимающий размерность вектора
CSRMatrix::CSRMatrix(int nn,int mm)
{
	if (nn * mm > 0)
	{
		m = mm;
		n = nn;
		m_matr = new double* [n];
		for (int i = 0; i < n; i++)
		{
			m_matr[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				m_matr[i][j] = 0;
			}
		}
	}
	else if (nn * mm == 0)
	{
		m_matr = nullptr;
		n = 0;
		m = 0;
	}
	else throw OutOfRangeException();
};

// конструктор принимающий массив координат
CSRMatrix::CSRMatrix(double** matr)
{
	if (_msize(matr) / sizeof(matr[0]) != 0)
	{
		n = _msize(matr) / sizeof(matr[0]);
		m_matr = new double* [n];
		for (int i = 0; i < n; i++)
		{
			m = _msize(matr[0]) / sizeof(matr[0][0]);
			m_matr[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				m_matr[i][j] = matr[i][j];
			}
		}
	}
	else m_matr = nullptr;
	}
// конструктор копирования
CSRMatrix::CSRMatrix(const CSRMatrix& matr)
{
	n = matr.n;
	m = matr.m;
	if (matr.m*matr.n != 0)
	{
		m_matr = new double* [n];
		for (int i = 0; i < n; i++)
		{
			m_matr[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				m_matr[i][j] = matr.m_matr[i][j];
			}
		}
	}
	else m_matr = nullptr;
}
// деструктор
CSRMatrix::~CSRMatrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] m_matr[i];
	}
	delete[] m_matr;
}



std::istream& operator>>(std::istream& in, CSRMatrix& m) {
	for (int i = 0; i < m.n; ++i)
	{
		for (int j = 0; j < m.m; ++j)
		{
			in >> m.m_matr[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, CSRMatrix& m) 
{
	if (m.n * m.m != 0)
	{
		for (int i = 0; i < m.n; ++i)
		{
			if ((m.n % 2 != 0) && (m.n - i == i + 1)) out << "M=";
			else if ((m.n % 2 == 0) && (i == m.n / 2)) out << "M=";
			else out << "  ";

			out << "|";
			for (int j = 0; j < m.m; ++j)
			{

				if (m.m_matr[i][j] > 99)	out << " " << m.m_matr[i][j];
				else if (m.m_matr[i][j] > 9)	out << " " << m.m_matr[i][j] << " ";
				else out << " " << m.m_matr[i][j] << "  ";
			}
			out << "|\n";
		}
	}
	else out << "M=|...|\n";
	return out;
}
void CSRMatrix::getdim(int dim[2]) const 
{
	dim[0]=n;
	dim[1] = m;
}

CSRMatrix& CSRMatrix::operator=(const CSRMatrix& matr)
{

	n = matr.n;
	m = matr.m;
	m_matr = new double* [n];
	for (int i = 0; i < n; ++i)
	{
		m_matr[i] = new double [m];
		for (int j = 0; j < m; ++j)
		{
			m_matr[i][j]=matr.m_matr[i][j];
		}
	}
	return *this;

}


Vector CSRMatrix::operator*(const Vector& vector) const
{
	Vector res(n);
	double elem;
	if (vector.m_dim == m)
	{
		res.m_dim = n;
		res.m_coord = new double[n];
		for (int i = 0; i < n; ++i)
		{
			elem = 0;
			for (int j = 0; j < m; ++j)
			{
				elem += m_matr[i][j] * vector.m_coord[j];
			}
			res.m_coord[i] = elem;
		}
	}
	else throw OutOfRangeException();
	return res;
}


CSRMatrix CSRMatrix::operator*(double coaff)const
{
	CSRMatrix res = *this;
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m; j++)
		{
			res.m_matr[i][j] *= coaff;
		}
	}
	return res;
}
CSRMatrix operator*(const double& number, const CSRMatrix& matr)
{
	return matr * number;
}

int CSRMatrix::count_not_nul()
{
	int nn=0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			if(m_matr[i][j]!=0)nn++;
		}
	}
	return nn;
}