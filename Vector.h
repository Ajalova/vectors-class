#pragma once
#include <iostream>


class Vector {
private:
	int m_dim{ 0 };
	double* m_coord{nullptr};
public:

	// ������������

	Vector(int dim = 0);
	Vector(double* coord);
	Vector(const Vector& vector);

	~Vector();

	//��������������� �������

	// ��������������� = 
	void operator=(const Vector& vector);
	// ��������������� += 
	Vector& operator+=(const Vector& vector);
	// ��������������� -= 
	Vector& operator-=(const Vector& vector);
	// ��������������� ��������� + 
	Vector operator+(const Vector& vector)const;
	// ��������������� �������� + 
	Vector operator+() const;
	// ��������������� ��������� ������� �� �����
	Vector operator*(double coaff)const;
	// ��������������� �������� - 
	Vector operator-() const;
	// ��������������� ��������� - 
	Vector operator-(const Vector& vector) const;
	// ��������������� ��������� ����� �� ������
	friend Vector operator*(const double& number, const Vector& vector);
	// ��������������� ���������� ������������ ��������
	friend Vector operator*(const Vector& vector2, const Vector& vector1);
	// ��������������� []
	double operator[] (const int index);
	// ��������������� ��������� ���������� ���� � ��������� �� double
	operator double*();
	// ��������������� <<

	friend std::istream& operator>>(std::istream& in, Vector& v);
	friend std::ostream& operator<<(std::ostream& out, Vector& v);

	int getdim()const ;
	double lengh()const;
	
	friend class CSRMatrix;
	///friend Vector operator*(const Vector& vector, const CSRMatrix& matr);
};


