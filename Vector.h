#pragma once
#include <iostream>


class Vector {
private:
	int m_dim{ 0 };
	double* m_coord{nullptr};
public:

	// КОНСТРУКТОРЫ

	Vector(int dim = 0);
	Vector(double* coord);
	Vector(const Vector& vector);

	~Vector();

	//ПЕРЕОПРЕДЕЛЕНИЯ ФУНКЦИЙ

	// переопределение = 
	void operator=(const Vector& vector);
	// переопределение += 
	Vector& operator+=(const Vector& vector);
	// переопределение -= 
	Vector& operator-=(const Vector& vector);
	// переопределение бинарного + 
	Vector operator+(const Vector& vector)const;
	// переопределение унарного + 
	Vector operator+() const;
	// переопределение умножения вектора на число
	Vector operator*(double coaff)const;
	// переопределение унарного - 
	Vector operator-() const;
	// переопределение бинарного - 
	Vector operator-(const Vector& vector) const;
	// переопределение умножение числа на вектор
	friend Vector operator*(const double& number, const Vector& vector);
	// переопределение скалярного произвеления векторов
	friend Vector operator*(const Vector& vector2, const Vector& vector1);
	// переопределение []
	double operator[] (const int index);
	// переопределение оператора приведения типа к указателю на double
	operator double*();
	// переопределение <<

	friend std::istream& operator>>(std::istream& in, Vector& v);
	friend std::ostream& operator<<(std::ostream& out, Vector& v);

	int getdim()const ;
	double lengh()const;
	
	friend class CSRMatrix;
	///friend Vector operator*(const Vector& vector, const CSRMatrix& matr);
};


