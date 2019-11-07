#include "Vector.h"
Vector::Vector()
{
	data = NULL;
	n = 0;
}

Vector::Vector(float *a, int _n)
{
	data = a;
	n = _n;
}

Vector::Vector(const Vector &a)
{
	data = a.data;
	n = a.n;
	data = new float[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = a.data[i];
	}
}

void Vector::input()
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	data = new float[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i + 1 << " : ";
		cin >> data[i];
	}
}

void Vector::output()
{
	if (this->data != NULL)
	{
		cout << "(";
		for (int i = 0; i < n-1; i++)
		{
			cout << this->data[i] << ",";
		}
		cout << this->data[n - 1] << ")" << endl;
	}
}

Vector& Vector::ConghaiVector(const Vector& b)
{
	if (n == b.n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i] += b.data[i];
		}
	}
	else
	{
		this->data = NULL;
		cout << "Hai vecto khong cung chieu!";
	}
	return *this;
}


Vector& Vector::Nhan_alpha(const float &alpha)
{
	for (int i = 0; i < this->n; i++)
	{
		data[i] *= alpha;
	}
	return *this;
}

Vector::~Vector()
{
	if (data != NULL)
		delete[] data;
}
