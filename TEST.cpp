#include"TEST.h"
void Test_Hang_Matran(Matrix a)
{
	cout << " Hang cua ma tran la:" << a.Hangmatran() << endl;
}
void Test_Hang_Matran()
{
	Matrix a;
	a.Set_Matrix();
	a.Print();
	cout << " Hang cua ma tran la:" << a.Hangmatran() << endl;
}

void Test_Tich_Matran()
{
	Matrix a;
	a.Set_Matrix();
	a.Print();
	Matrix b;
	b.Set_Matrix();
	b.Print();
	Matrix c;
	a.Tichmatran(b);
}
void Test_Dinhthuc()
{
	Matrix a;
	a.Set_Matrix();
	int bac = a.GetCol();
	cout << " Det cua ma tran la:" << a.DET(a, bac) << endl;
}
void Test_Dinhthuc(Matrix a)
{
	cout << " Det cua ma tran la:" << a.DET(a, a.GetCol());
}
void Test_Matran_Nghichdao()
{
	Matrix a;
	a.Set_Matrix();
	if (a.GetCol() == a.GetRow())
	{
		cout << " Ma tran nghich dao cua A la:" << endl;
		if (a.DET(a, a.GetCol()) != 0)
			(a.NghichDao()).Print();
	}
	else
		cout << " Ma tran nay khong co ma tran nghich dao" << endl;
}
void Test_Matran_Nghichdao(Matrix a)
{
	if (a.GetCol() == a.GetRow())
	{
		cout << " Ma tran nghich dao cua A la:" << endl;
		if (a.DET(a, a.GetCol()) != 0)
			(a.NghichDao()).Print();
	}
	else cout << " Ma tran nay khong co ma tran nghich dao" << endl;
}
void Test_Giai_HePTTT()
{
	Matrix a;
	a.Set_Matrix();
	a.Giai_NghiemPTTT();
}
void Test_Cong_Hai_Vector()
{
	Vector A, B, C;
	A.input();
	B.input();
	A.ConghaiVector(B);
	A.output();
}
void Test_Nhan_Hai_Vector()
{
	Vector A;
	A.input();
	cout << " Nhap so A de nhan" << endl;
	float a;
	cin >> a;
	Vector B;
	B = A*a;
	B.output();
}
