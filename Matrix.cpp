#include "Matrix.h"
// Dinh nghia class ma tran

Matrix::Matrix()
{
	_row = 0;
	_col = 0;
	_a = NULL;
}
Matrix::Matrix(int dong, int cot)
{
	this->_row = dong;
	this->_col = cot;
	this->_a = new float*[dong];
	for (int i = 0; i<dong; i++)
	{
		this->_a[i] = new float[cot];
	}
}
Matrix::~Matrix()
{
}
//========================================================






// Cac ham GETTER , SETTER
void Matrix::Set_Matrix()
{
	cout << "Nhap so dong: ";
	cin >> _row;
	cout << "Nhap so cot: ";
	cin >> _col;
	// Khoi tao mang hai chieu chua cac gia tri cua ma tran
	_a = new float*[_row];
	for (int i = 0; i < _row; i++)
		_a[i] = new float[_col];
	// Nhap gia tri tung phan tu vao mang hai chieu _a
	for (int i = 0; i < _row; i++)
	for (int j = 0; j < _col; j++)
	{
		cout << "a[" << i << "]" << "[" << j << "] = ";
		cin >> _a[i][j];
	}
}
void Matrix::SetRow(int row)
{
	this->_row = row;
}
void Matrix::SetCol(int col)
{
	this->_col = col;
}
void Matrix::SetA(float **B)
{

	for (int dong = 0;; dong++)
	{
		if (B[dong][0] == NULL) // Dieu kien de dung khi "dong" > so dong cua B
			break;
		else
		{
			for (int cot = 0;; cot++)
			{
				if (B[dong][cot] == NULL)// Dieu kien de dung khi "cot" < so cot cua B
					break;
				else
					this->_a[dong][cot] = B[dong][cot];

			}
		}
	}
}
int Matrix::GetCol()
{
	return this->_col;
}
int Matrix::GetRow()
{
	return this->_row;
}
float **Matrix::GetA()
{
	return this->_a;
}

//===========================================================




// Ham coppy
Matrix &Matrix::operator =(const Matrix &other)
{
	if (this->_a != NULL) // Kiem tra xem mang "_a" co ton tai hay ko
	{
		delete[]_a;
	}  // Neu co thi giai phong "_a"
	// Khoi tao lai "_a" bang mang hai chieu "other._a"
	this->_row = other._row;
	this->_col = other._col;
	this->_a = new float*[_row];
	for (int i = 0; i < _row; i++)
		_a[i] = new float[_col];
	// Gan gia tri cua "this->_a" bang cac gia tri trong mang hai chieu "other._a"
	for (int i = 0; i < _row; i++)
	for (int j = 0; j < _col; j++)
	{
		_a[i][j] = other._a[i][j];
	}
	return *this;
}
//========================================================




// Ham in ma tran
void Matrix::Print()
{
	for (int i = 0; i < this->_row; i++)
	{
		for (int j = 0; j < this->_col; j++)
			cout << setw(5) << this->_a[i][j];
		cout << endl;
	}
}//========================================================









// Cac ham hỗ trợ cho cac ham chinh
Matrix Matrix::RenewMatrix(Matrix A, int bac, int dong, int cot)
// Dung trong ham tinh DET,tao cac matrancon sau khi xoa dong va cot
{
	Matrix B(bac, bac);
	B.SetCol(bac);
	B.SetRow(bac);
	float** b;
	b = new float*[bac - 1];
	for (int i = 0; i < bac; i++)
	{
		b[i] = new float[bac - 1];
	}
	B.SetA(b);
	int rowB = 0;
	int colB = 0;
	for (int j = 0; j < bac; j++)
	{
		if (j != dong)
		{
			for (int k = 0; k < bac; k++)
			{
				if (k != cot)
				{

					B._a[rowB][colB] = A._a[j][k];
					colB++;
					if (colB >= bac - 1)
					{
						colB = 0;
						rowB++;
					}
				}
			}

		}
	}
	return B;
}
void Matrix::Swap_row(int i, int k)
{
	float temp;
	for (int col = 0; col < _col; col++)
	{
		temp = _a[i][col];
		_a[i][col] = _a[k][col];
		_a[k][col] = temp;
	}
}
bool Matrix::Kiemtra_VoNghiem(const Matrix& matr)
{
	bool flag;
	for (int dong = matr._row - 1; dong >= 0; dong--)
	{
		flag = true;
		for (int cot = 0; cot < matr._col - 1; cot++)
		{
			if (matr._a[dong][cot] != 0)
				flag = false;
		}
		if (flag == true && matr._a[dong][matr._col - 1] != 0)
			return true;
	}
	return false;
}
//========================================================






// Cac hàm chính trên ma trận
void Matrix::Bacthang() // Tra ve dang bac thang rut gon cua ma tran
{
	int i = 0;
	int j = 0;
	bool flag = false;
	// su dung cong thuc rut gon bac thang : Bien doi so cap tren dong
	while (i < _row && j < _col)
	{
		if (_a[i][j] != 0)
		{
			for (int k = i + 1; k < _row; k++)
			{
				float temp = _a[k][j] / _a[i][j];
				for (int c = j; c < _col; c++)
				{
					_a[k][c] -= temp*_a[i][c];
					if (_a[k][c] < 0.000001 && _a[k][c]>-0.000001)
						_a[k][c] = 0;
				}
			}
			i++;
			j++;
		}
		else
		{
			for (int k = i + 1; k < _row; k++)
			{
				if (_a[k][j] != 0)
				{
					flag = true;
					Swap_row(k, i);
					break;
				}
			}
			if (flag == false)
			{
				j++;
			}
		}
	}
}
int Matrix::Hangmatran()
{
	this->Bacthang();
	int dem = 0;
	// Dem so dong co it nhat mot phan tu khac 0
	for (int i = 0; i<this->_row; i++)
	{
		int flag = 0;
		for (int j = 0; j<this->_col; j++)
		{
			if (this->_a[i][j] != 0)
			{
				flag = 1;
				break;
			}
		}
		dem += flag;
	}
	return dem;
}
float Matrix::DET(Matrix A, int bac)  // Tinh dinh thuc, "bac" la bac cua ma tran A
{
	if (!bac)
	{
		return 0;
	}
	if (bac == 1)
	{
		return A._a[0][0];
	}

	if (bac == 2)
	{
		return A._a[0][0] * A._a[1][1] - A._a[1][0] * A._a[0][1];

	}

	float Det = 0;
	// Tinh dinh thuc cua cac ma tran sau khi da xoa dong "i" va cot "0", dung de quy
	for (int i = 0; i < bac; i++)
	{
		Det += pow(-1, i) * A._a[i][0] * DET(RenewMatrix(A, bac, i, 0), bac - 1);
	}
	return Det;
}
Matrix Matrix::Tichmatran(Matrix B)
{
	int dongA = this->_row; int cotA = this->_col; int dongB = B._row; int cotB = B._col;
	Matrix Non(2, 2);
	if (cotA == dongB)
	{
		Matrix C(dongA, cotB);
		C._row = dongA;
		C._col = cotB;
		int dongC = 0;
		int cotC = 0;
		for (int donga = 0; donga<dongA; donga++)
		{
			for (int cotb = 0; cotb<cotB; cotb++)
			{
				int temp = 0;
				for (int dongb = 0; dongb<dongB; dongb++)
				{
					int cota = dongb;
					temp = temp + _a[donga][cota] * B._a[dongb][cotb];
				}
				C._a[dongC][cotC] = temp;
				cotC++;
				if (cotC >= C._col)
				{
					cotC = 0;
					dongC++;
				}
			}
		}
		cout << " Tich hai ma tran la:" << endl;
		C.Print();
		return C;
	}
	else
		return Non;
}
Matrix Matrix::NghichDao()
{
	int bac = this->_row;
	Matrix phuhop(bac, bac);
	for (int i = 0; i<bac; i++)
	{
		for (int j = 0; j<bac; j++)
		{
			phuhop._a[i][j] = pow(-1, i + j)*DET(RenewMatrix(*this, bac, i, j), bac - 1);
		}
		cout << endl;
	}
	Matrix Chuyenvi(bac, bac);
	int dongCV = 0;
	int cotCV = 0;
	for (int cot = 0; cot<bac; cot++)
	{
		for (int dong = 0; dong<bac; dong++)
		{
			Chuyenvi._a[dongCV][cotCV] = phuhop._a[dong][cot];
			cotCV++;
			if (cotCV >= bac)
			{
				cotCV = 0;
				dongCV++;
			}
		}
	}
	float detA = this->DET(*this, bac);
	for (int i = 0; i<bac; i++)
	{
		for (int j = 0; j<bac; j++)
		{
			Chuyenvi._a[i][j] = Chuyenvi._a[i][j] / detA;
		}
	}
	return Chuyenvi;
}
void Matrix::Giai_NghiemPTTT()
{
	int rank = this->Hangmatran();
	this->Bacthang();
	if (Kiemtra_VoNghiem(*this) == true)
		cout << "Phuong trinh vo nghiem!" << endl;
	else
	{
		if (rank < _col - 1)
			cout << "Phuong trinh vo so nghiem voi " << _col - 1 - rank << " an tu do!" << endl;
		else if (rank == _col - 1)
		{
			float kq = 0;
			float* nghiem = new float[rank];
			int dong, cot;
			nghiem[_col - 2] = _a[rank - 1][_col - 1] / _a[rank - 1][_col - 2];
			for (dong = rank - 2; dong >= 0; dong--)
			{
				kq = _a[dong][_col - 1];
				for (cot = _col - 2; cot >= dong + 1; cot--)
					kq -= _a[dong][cot] * nghiem[cot];
				nghiem[cot] = kq / _a[dong][cot];
			}
			cout << "Nghiem cua phuong trinh: " << endl;
			for (int i = 0; i < rank; i++)
				cout << "x[" << i + 1 << "] = " << nghiem[i] << "\t";
			delete[] nghiem;
		}
	}
}
