//
//  Menu.cpp
//  Matrix1
//
//  Created by Admin on 11/1/19.
//  Copyright © 2019 tvt3. All rights reserved.
//

#include "Menu.h"
using namespace std;
int ChooseMenu()
{
	int n = 0;
	cout << "Lua chon cua ban: ";
	cin >> n;
	if (n >= 0 && n < 10)
		return n;
	else return ChooseMenu();
}
void Menu()
{
	//    HANDLE hConsoleColor;
	//    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int choose = 1;
	while (choose)
	{

		cout << "\n\n\n\n " << endl;
		cout << "===============WELCOM===============\n\n" << endl;
		cout << " MATRIX============================  " << endl;
		cout << "  Button [1].Tich 2 ma tran.                  " << endl;
		cout << "  Button [2].Dinh thuc ma tran(det).          " << endl;
		cout << "  Button [3].Hang cua ma tran(rank).          " << endl;
		cout << "  Button [4].Ma tran nghich dao               " << endl;
		cout << "  Button [5].Giai he phuong trinh tuyen tinh \n\n    " << endl;
		cout << "  VECTOR============================    " << endl;
		cout << "  Button [6].Cong 2 vector                    " << endl;
		cout << "  Button [7].Nhan vector vs 1 so  \n\n   " << endl;
		cout << "  BOOL============================" << endl;
		cout << "  Button [8].Cac cong thuc toi thieu    " << endl;
		cout << "  Nhan phim bat ki ngoai 8 phim tren de thoat   " << endl;
		cout << "_______________________________________________" << endl;
		cout << endl;

		choose = ChooseMenu();
		switch (choose)
		{
		case 0:   exit;
			break;
		case 1:
		{
				  system("cls");
				  Test_Tich_Matran();
				  break;
		}
		case 2:
		{
				  system("cls");
				  Test_Dinhthuc();
				  break;
		}
		case 3:
		{
				  system("cls");
				  Test_Hang_Matran();
				  break;
		}
		case 4:
		{
				  system("cls");
				  Test_Matran_Nghichdao();
				  break;
		}
		case 5:
		{
				  system("cls");
				  Test_Giai_HePTTT();
				  break;
		}
		case 6:
		{
				  system("cls");
				  Test_Cong_Hai_Vector();
				  break;
		}
		case 7:
		{
				  system("cls");
				  Test_Nhan_Hai_Vector();
				  break;
		}
		case 8:
		{
				  system("cls");
				  cout << " Hien chua update tinh nang nay!" << endl;
				  break;
		}
		default:
		{ choose = 0;
		break;
		}
		}
	}
}
