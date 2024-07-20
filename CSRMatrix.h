#pragma once
#include <iostream>
#include "Vector.h"

class CSRMatrix {
private:
	int m{ 0 };
	int n{ 0 };
	double** m_matr;
public:

	// ÊÎÍÑÒÐÓÊÒÎÐÛ

	CSRMatrix(int nn=0, int mm=0);
	CSRMatrix(double** matr);
	CSRMatrix(const CSRMatrix& matr);

	~CSRMatrix();

	Vector operator*(const Vector& vector)const;
	

	friend std::istream& operator>>(std::istream& in, CSRMatrix& m);
	friend std::ostream& operator<<(std::ostream& out, CSRMatrix& m);
	CSRMatrix& operator=(const CSRMatrix& m);
	void getdim(int dim[2])const;

	CSRMatrix operator*(double coaff)const;
	friend CSRMatrix operator*(const double& number, const CSRMatrix& matr);
	int count_not_nul();
};