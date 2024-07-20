#include "Vector.h"
#include "CSRMatrix.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"

using namespace std;




// конструктор принимающий размерность вектора
Vector::Vector(int dim)
{
	if (dim > 0)
	{
		m_dim = dim;
		m_coord = new double[dim];
		for (int i = 0; i < m_dim; i++)
		{
			m_coord[i] = 0;
		}
	}
	else if (dim == 0)
	{
		m_dim = 0;
		m_coord = nullptr;
	}
	else throw IncompatibleDimException();
};

// конструктор принимающий массив координат
Vector::Vector(double* coord )
{
	m_dim = _msize(coord) / sizeof(coord[0]);
	m_coord = new double[m_dim];
	for (int i = 0; i < m_dim; i++)
	{
		m_coord[i] = coord[i];
	}
};

// конструктор копирования
Vector::Vector(const Vector& vector)
{
	m_dim = vector.m_dim;
	if (m_dim != 0)
	{
		m_coord = new double[m_dim];
		for (int i = 0; i < m_dim; i++)
		{
			m_coord[i] = vector.m_coord[i];
		}
	}
};

// деструктор
Vector::~Vector() 
{
	delete[] m_coord;
}

Vector Vector::operator+(const Vector& vector) const
{
	Vector sum;
	if (m_dim == vector.m_dim)
	{
		
		sum.m_dim = vector.m_dim;
		sum.m_coord = new double[m_dim];
		for (int i = 0; i < m_dim; i++)
		{
			sum.m_coord[i] = vector.m_coord[i]+m_coord[i];
		}
	}
	else throw IncompatibleDimException();;
	return sum;
}

void Vector::operator=(const Vector& vector) 
{
	m_dim = vector.m_dim;
	m_coord = new double(m_dim);
	for (int i = 0; i < m_dim; ++i) 
	{
		m_coord[i] = vector.m_coord[i];
	}

}


Vector& Vector::operator+=(const Vector& vector)
{
	if (m_dim == vector.m_dim)
	{
		for (int i = 0; i < m_dim; i++)
		{
			m_coord[i] += vector.m_coord[i];
		}

	}
	else throw IncompatibleDimException();
	return *this;

}
Vector& Vector::operator-=(const Vector& vector)
{
	if (m_dim == vector.m_dim)
	{
		for (int i = 0; i < m_dim; i++)
		{
			m_coord[i] -= vector.m_coord[i];
		}

	}
	else throw IncompatibleDimException();
	return *this;

}

Vector Vector::operator+() const 
{
	return *this;
}

Vector Vector::operator*(double coaff)const
{
	Vector ans(m_dim);
	for (int i = 0; i < m_dim; i++)
	{
		ans.m_coord[i]=m_coord[i]*coaff;
	}
	return ans;

}

Vector Vector::operator-() const
{
	return (*this)*(-1);
}


Vector Vector::operator-(const Vector& vector) const
{
	return (*this)+(-1)*vector;
}

Vector operator*(const double& number, const Vector& vector)
{
	return vector * number;
}

Vector operator*(const Vector& vector2, const Vector& vector1)
{
	Vector ans(vector1.m_dim);
	if (vector2.m_dim == vector1.m_dim)
	{
		ans.m_dim = vector1.m_dim;
		for (int i = 0; i < vector1.m_dim; i++)
		{
			ans.m_coord[i] = vector1.m_coord[i]* vector2.m_coord[i];;
		}

	}
	 else throw IncompatibleDimException();

	return ans;
}

double Vector::operator[] (const int index)
{
	if (index<0 || index>(m_dim - 1))
	{
		cout << "в данном векторе нет координаты с номером" << index << endl;
		return index;
	}
	else throw OutOfRangeException();
	return m_coord[index-1];
}

Vector::operator double* ()
{
	return m_coord;
}

std::istream& operator>>(std::istream& in, Vector& v) {
	for (int i = 0; i < v.m_dim; ++i) in >> v.m_coord[i];
	return in;
}

std::ostream& operator<<(std::ostream& out, Vector& v) {
	
	if (v.m_dim > 0)
	{
		double help;
		out << "(";
		for (int i = 0; i < v.m_dim - 1; ++i)
		{
			help = v.m_coord[i];
			out << help << ", ";
		}
		out << v.m_coord[v.m_dim - 1] << ")";
	}
	else out << "(...)";
	return out;
}

int Vector::getdim()const
{
	return m_dim;
}

double Vector::lengh()const
{
	double len=0;
	for (int i = 0; i < m_dim; i++) len += m_coord[i] * m_coord[i];
	return sqrt(len);
}


