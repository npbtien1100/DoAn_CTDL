#include<iostream>
#include <iomanip>
#include<math.h>
#ifndef Matrix_h
#define Matrix_h
using namespace std;
class  Matrix
{
private:
	int _row; // so dong cua ma tran.
	int _col; // so cot cua ma tran.
	float** _a;// con trỏ hai chieu chua gia tri cua tung phan tu trong ma tran.
public:
	Matrix();
	Matrix(int dong, int cot);   // Khoi tao ma tran voi so dong va cot nhap vao.
	~Matrix();
public:
	void Set_Matrix();// Yeu cau ng dung nhap mot ma tran va cac gia tri cua mt.
	void SetRow(int row); //Nhap vao so dong cua ma tran.
	void SetCol(int col);// Nhap vao so cot cua ma tran.
	void SetA(float **B);// Gan tung gia tri cua ma tran bang gia tri mang
	// hai chieu B.
	int GetRow();        // Tra ve gia tri so dong cua ma tran.
	int GetCol();        // Tra ve gia tri so cot cua.
	float **GetA();      // Tra ve mot mang hai chieu cac gia tri cua ma tran.
public:
	void Print();        // In ma tran ra man hinh
	Matrix &operator =(const Matrix &other);// toan tu gan =.
public:
	void Swap_row(int n, int k); // Doi vi tri hai dong cua ma tran, n ,k la
	// thu tu hai dong can doi.
	Matrix RenewMatrix(Matrix A, int bac, int dong, int cot);// Ham tra ve ma tran moi dua tren ma tran cu sau
	// khi xoa di dong thu "dong" va cot thu "cot".
	// Dung trong ham tinh dinh thuc DET().
	void Bacthang();    // Bien doi truc tiep ma tran thanh ma tran bac thang.
	// Dung trong ham tinh hang cua ma tran Hangmatran(). Khong gia tri tra ve.
	int Hangmatran();   // Tim hang cua ma tran.
	Matrix Tichmatran(Matrix other); // Tra ve mot ma tran la tich cua 2 ma tran.
	float DET(Matrix A, int bac);      // Tra ve gia tri so nguyen la dinh thuc cua ma tran.
	Matrix MaChuyenvi(Matrix A);     // Tra ve ma tran moi la ma tran chuyen vi cua ma tran da cho.
	Matrix NghichDao();              // Tra ve mot ma tran moi la ma tran nghich dao.
	void Giai_NghiemPTTT();
	bool Kiemtra_VoNghiem(const Matrix& matr);

};
typedef class Matrix Matrix;
#endif 