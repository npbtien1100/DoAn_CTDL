#include "Bool.h"

char* arr_x[4] = { "x", "x", "x'", "x'" };
char* arr_y[4] = { "y'", "y", "y", "y'" };
char* arr_z[4] = { "z", "z", "z'", "z'" };
char* arr_t[4] = { "t'", "t", "t", "t'" };
char** Bool::karnaugh()
{
	string str = _dathuc;
	char** karnau = new char*[4];
	for (int i = 0; i < 4; i++)
		karnau[i] = new char[4];
	for (int i = 0; i < 4;i++)
	for (int j = 0; j < 4; j++)
		karnau[i][j] = 48;
	vector<string> SS; //Vector of string
	while (!str.empty())
	{
		SS.push_back(str.substr(0, str.find("v")));// add word to vector
		if (str.find("v") > str.size()) //Check if found " " (Space)
		{
			break;
		}
		else
		{
			str.erase(0, str.find("v") + 1); // Update string
		}
	}
	for (int i = 0; i < SS.size(); i++)
	{
		int col[2] = { 0, 3 };
		int row[2] = { 0, 3 };
		bool chay1 = true;
		bool chay2 = true;
		string temp = SS[i];
		if (temp.find("x'") != -1)
		{
			if (temp.find("y'") != -1)
				col[0] = col[1] = 3;
			else if (temp.find("y") != -1)
				col[0] = col[1] = 2;
			else
			{
				col[0] = 2; col[1] = 3;
			}
		}
		else if (temp.find("x") != -1)
		{
			if (temp.find("y'") != -1)
				col[0] = col[1] = 0;
			else if (temp.find("y") != -1)
				col[0] = col[1] = 1;
			else
			{
				col[0] = 0; col[1] = 1;
			}
		}
		else{
			if (temp.find("y'") != -1)
			{
				col[0] = 0; col[1] = 3;
				chay1 = false;
			}
			else if (temp.find("y") != -1)
			{
				col[0] = 1; col[1] = 2;
			}
		}
		if (temp.find("z'") != -1)
		{
			if (temp.find("t'") != -1)
				row[0] = row[1] = 3;
			else if (temp.find("t") != -1)
				row[0] = row[1] = 2;
			else
			{
				row[0] = 2; row[1] = 3;
			}
		}
		else if (temp.find("z") != -1)
		{
			if (temp.find("t'") != -1)
				row[0] = row[1] = 0;
			else if (temp.find("t") != -1)
				row[0] = row[1] = 1;
			else
			{
				row[0] = 0; row[1] = 1;
			}
		}
		else{
			if (temp.find("t'") != -1)
			{
				row[0] = 0; row[1] = 3;
				chay2 = false;
			}
			else if (temp.find("t") != -1)
			{
				row[0] = 1; row[1] = 2;
			}
		}
		if (chay2 == true)
		{
			for (int dong = row[0]; dong <= row[1]; dong++)
			{
				if (chay1==true)
				for (int cot = col[0]; cot <= col[1]; cot++)
					karnau[dong][cot] = 49;
				else{
					karnau[dong][col[0]] = 49;
					karnau[dong][col[1]] = 49;
				}
			}
		}
		else
		{
			if (chay1==true)
			for (int cot = col[0]; cot <= col[1]; cot++)
			{
				karnau[row[0]][cot] = 49;
				karnau[row[1]][cot] = 49;
			}
			else
			{
				karnau[row[0]][col[0]] = 49;
				karnau[row[1]][col[1]] = 49;
			}
		}
	}
	_karnaugh = karnau;
	return karnau;
}

int Bool::size_listtutoitieu()
{
	return list_tutoitieu.size();
}

void Bool::Input_dathuc()
{
	cout << "Nhap vao cong thuc da thuc: " << endl;
	getline(cin, _dathuc);
}

vector<string> Bool::Create_tutoitieu()
{
	string kq;
	char**temp = this->karnaugh();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << temp[i][j] << "  ";
			if (temp[i][j] == '1')
			{
				kq = arr_x[j];
				kq += arr_y[j];
				kq += arr_z[i];
				kq += arr_t[i];
				list_tutoitieu.push_back(kq);
			}
		}
		cout << endl;
	}
	return list_tutoitieu;
}
void Bool::In_tutoitieu()
{
	cout << list_tutoitieu.size() << endl;
	for (int i = 0; i < list_tutoitieu.size(); i++)
		cout << list_tutoitieu[i]<<" v ";
	cout << "------------------" << endl;
	vector<vector<char>> kq = convert_tovtchar(this->list_tutoitieu);
	for (int i = 0; i < kq.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			cout << kq[i][j];
		cout << " v ";
	}
	cout << "-----------------" << endl;
	vector<vector<char>> tebaolon = Minimize();
	for (int i = 0; i < tebaolon.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			cout << tebaolon[i][j];
		cout << " v ";
	}
}

vector<int> convert_intonum(const string ttt1)
{
	vector<int> result(4);
	if (ttt1.find("x'") != -1)
		result[0]=0;
	else if (ttt1.find("x") != -1)
		result[0] = 1;
	else result[0] = 2;
	if (ttt1.find("y'")!=-1)
		result[1] = 0;
	else if (ttt1.find("y") != -1)
		result[1] = 1;
	else result[1] = 2;
	if (ttt1.find("z'") != -1)
		result[2] = 0;
	else if (ttt1.find("z") != -1)
		result[2] = 1;
	else result[2] = 2;
	if (ttt1.find("t'") != -1)
		result[3] = 0;
	else if (ttt1.find("t") != -1)
		result[3] = 1;
	else result[3] = 2;
	return result;
}
string convert_intostring(const vector<int>&a)
{
	string str;
	if (a[0] == 1)
		str.push_back('x');
	else if (a[0] == 0)
		str += "x'";
	if (a[1] == 1)
		str.push_back('y');
	else if (a[1] == 0)
		str += "y'";
	if (a[2] == 1)
		str.push_back('z');
	else if (a[2] == 0)
		str += "z'";
	if (a[3] == 1)
		str.push_back('t');
	else if (a[3] == 0)
		str += "t'";
	return str;
}
vector<int> gop_tutoitieu(const string ttt1,const string ttt2)
{
	vector<int> t1 = convert_intonum(ttt1);
	vector<int> t2 = convert_intonum(ttt2);
	vector<int> kq(4);
	int sam_num = 0;
	int leng;
	if (ttt1.length()>ttt2.length())
		leng = ttt2.length();
	else if (ttt1.length() <= ttt2.length())
		leng = ttt1.length();
	//kiem tra 2 tu toi tieu co phai la con cua nhau
	bool flag = true;
	for (int i = 0; i < leng; i++)
	{
		if (t1[i] != t2[i])
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		if (ttt1.length()>ttt2.length())
			return t2;
		else
			return t1;
	}
	//dem so ki tu giong nhau
	for (int i = 0; i < 4; i++)
	{
		if (t1[i] == t2[i])
			sam_num++;
	}
	//dieu kien so giong nhau phai lon hon (so bien - 1)
	if (sam_num>=3)
	{
		for (int i = 0; i < 4; i++)
		{
			if (t1[i] == t2[i])
				kq[i] = t1[i];
			else
				kq[i] = 2;
		}
	}
	else {
		kq = convert_intonum(ttt1);
	}
	return kq;
}

bool kt_tontai(const vector<int>&a, const vector<int>&b)
{
	//kiem tra trung
	bool trung = true;
	for (int i = 0; i < 4;i++)
	if (a[i] != 2 && a[i] != b[i])
		trung = false;
	//kiem tra con
	bool con = false;
	string s1 = convert_intostring(a);
	string s2 = convert_intostring(b);
	if (s2.find(s1) != -1)
	{
		int index = s2.find(s1) + s1.length();
		if (s2[index] != '\'')
			con = true;
	}
	return (trung || con);
}
bool kt_tontai(const vector<vector<int>>&a,const vector<int>& b)
{
	bool check;
	for (int i = 0; i < a.size(); i++)
	{
		if (kt_tontai(a[i], b) == true)
			return true;
	}
	return false;
}
bool kt_chuanhoa(const vector<int>&a, const vector<int> &b)
{
	for (int i = 0; i < 4; i++)
	{
		if (b[i] != 2 && b[i] != a[i])
			return false;
	}
	return true;
}
void Bool::Chuanhoa_tebaolon()
{
	for (int i = 0; i < list_tebaolon.size()-1; i++)
	for (int j = 0; j < list_tebaolon.size(); j++)
	{
		if (kt_chuanhoa(list_tebaolon[i], list_tebaolon[j]))
		{
			vector<int> temp = list_tebaolon[list_tebaolon.size() - 1];
			list_tebaolon[list_tebaolon.size() - 1] = list_tebaolon[i];
			list_tebaolon[i] = temp;
			list_tebaolon.pop_back();
			break;
		}
	}
}
void Bool::Create_tebaolon()
{
	vector<int> temp;
		for (int i = 0; i < list_tutoitieu.size(); i++)
		{
			for (int j = i + 1; j < list_tutoitieu.size(); j++)
			{
				temp = gop_tutoitieu(list_tutoitieu[i], list_tutoitieu[j]);
				for (int k = 0; k <= 3; k++)
					cout << temp[k];
				cout << "\t";
				if (kt_tontai(list_tebaolon, temp) == false)
				{
					this->list_tebaolon.push_back(temp);
				}
			}
		}
		this->Chuanhoa_tebaolon();
		for (int i = 0; i < 3; i++)
		{
			for (int index = 0; index < list_tebaolon.size(); index++)
			{
				for (int j = index + 1; j < list_tebaolon.size(); j++)
				{
					string t1 = convert_intostring(list_tebaolon[index]);
					string t2 = convert_intostring(list_tebaolon[j]);
					temp = gop_tutoitieu(t1, t2);
					if (kt_tontai(list_tebaolon, temp) == false)
					{
						this->list_tebaolon.push_back(temp);
					}
				}
			}
			this->Chuanhoa_tebaolon();
		}
	cout << "\n" << "\n";
	for (int i = 0; i < list_tebaolon.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			cout << list_tebaolon[i][j];
		cout << "\t";
	}
}
vector<char> convert_intochar(const string&ttt1)
{
	vector<char> kq(4);
	if (ttt1.find("x'") != -1)
		kq[0] = '0';
	else if (ttt1.find("x") != -1)
		kq[0] = '1';
	else kq[0] = '2';
	if (ttt1.find("y'") != -1)
		kq[1] = '0';
	else if (ttt1.find("y") != -1)
		kq[1] = '1';
	else kq[1] = '2';
	if (ttt1.find("z'") != -1)
		kq[2] = '0';
	else if (ttt1.find("z") != -1)
		kq[2] = '1';
	else kq[2] = '2';
	if (ttt1.find("t'") != -1)
		kq[3] = '0';
	else if (ttt1.find("t") != -1)
		kq[3] = '1';
	else kq[3] = '2';
	return kq;
}
vector<vector<char>> convert_tovtchar(const vector<string>&s1)
{
	vector<vector<char>> kq;
	for (int i = 0; i < s1.size(); i++)
	{
		kq.push_back(convert_intochar(s1[i]));
	}
	return kq;
}
bool CompareMinTerms(vector<char> X1, vector<char> X2)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (X1[i] != X2[i]) count++;
	}
	if (count > 1) return false;
	else return true;
}
vector<char> GroupMinTerms(vector<char> X1, vector<char> X2)
{
	vector<char> res;
	for (int i = 0; i < 4; i++)
	{
		if (X1[i] == X2[i]) res.push_back(X1[i]);
		else res.push_back('2');
	}
	return res;
}
vector<vector<char>> Bool::Minimize()
{
	vector<vector<char>> minTerms = convert_tovtchar(list_tutoitieu);
	vector<vector <char>> temp1 = minTerms, temp2;
	vector<int> flag;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < temp1.size(); j++) flag.push_back(0);
		for (int j = 0; j < temp1.size() - 1; j++)
		for (int z = j + 1; z < temp1.size(); z++)
		{
			if (CompareMinTerms(temp1[j], temp1[z]) != false)
			{
				temp2.push_back(GroupMinTerms(temp1[j], temp1[z]));
				flag[j] = 1;
				flag[z] = 1;
			}
		}
		for (int j = 0; j < temp1.size(); j++) if (flag[j] == 0) temp2.push_back(temp1[j]);
		temp1.clear();
		temp1 = temp2;
		temp2.clear();
		flag.clear();
	}
	return temp1;
}
string convert_intostring(const vector<char>&a)
{
	string kq;
	if (a[0] == '1')
		kq.push_back('x');
	else if (a[0] == '0')
		kq += "x'";
	if (a[1] == '1')
		kq.push_back('y');
	else if (a[1] == '0')
		kq += "y'";
	if (a[2] == '1')
		kq.push_back('z');
	else if (a[2] == '0')
		kq += "z'";
	if (a[3] == '1')
		kq.push_back('t');
	else if (a[3] == '0')
		kq += "t'";
	return kq;
}
void Bool::Get_essential()
{
	cell karnau2[4][4];
	vector<vector<char>> SS = this->Minimize();
	for (int i = 0; i < SS.size(); i++)
	{
		int col[2] = { 0, 3 };
		int row[2] = { 0, 3 };
		bool chay1 = true;
		bool chay2 = true;
		string temp = convert_intostring(SS[i]);
		if (temp.find("x'") != -1)
		{
			if (temp.find("y'") != -1)
				col[0] = col[1] = 3;
			else if (temp.find("y") != -1)
				col[0] = col[1] = 2;
			else
			{
				col[0] = 2; col[1] = 3;
			}
		}
		else if (temp.find("x") != -1)
		{
			if (temp.find("y'") != -1)
				col[0] = col[1] = 0;
			else if (temp.find("y") != -1)
				col[0] = col[1] = 1;
			else
			{
				col[0] = 0; col[1] = 1;
			}
		}
		else{
			if (temp.find("y'") != -1)
			{
				col[0] = 0; col[1] = 3;
				chay1 = false;
			}
			else if (temp.find("y") != -1)
			{
				col[0] = 1; col[1] = 2;
			}
		}
		if (temp.find("z'") != -1)
		{
			if (temp.find("t'") != -1)
				row[0] = row[1] = 3;
			else if (temp.find("t") != -1)
				row[0] = row[1] = 2;
			else
			{
				row[0] = 2; row[1] = 3;
			}
		}
		else if (temp.find("z") != -1)
		{
			if (temp.find("t'") != -1)
				row[0] = row[1] = 0;
			else if (temp.find("t") != -1)
				row[0] = row[1] = 1;
			else
			{
				row[0] = 0; row[1] = 1;
			}
		}
		else{
			if (temp.find("t'") != -1)
			{
				row[0] = 0; row[1] = 3;
				chay2 = false;
			}
			else if (temp.find("t") != -1)
			{
				row[0] = 1; row[1] = 2;
			}
		}
		if (chay2 == true)
		{
			for (int dong = row[0]; dong <= row[1]; dong++)
			{
				if (chay1 == true)
				for (int cot = col[0]; cot <= col[1]; cot++)
				{
					karnau2[dong][cot]._sotebao++;
					karnau2[dong][cot].mangtebao.push_back(SS[i]);
				}
				else{
					karnau2[dong][col[0]]._sotebao++;
					karnau2[dong][col[0]].mangtebao.push_back(SS[i]);
					karnau2[dong][col[1]]._sotebao++;
					karnau2[dong][col[1]].mangtebao.push_back(SS[i]);
				}
			}
		}
		else
		{
			if (chay1 == true)
			for (int cot = col[0]; cot <= col[1]; cot++)
			{
				karnau2[row[0]][cot]._sotebao++;
				karnau2[row[0]][cot].mangtebao.push_back(SS[i]);
				karnau2[row[1]][cot]._sotebao++;
				karnau2[row[1]][cot].mangtebao.push_back(SS[i]);
			}
			else
			{
				karnau2[row[0]][col[0]]._sotebao++;
				karnau2[row[0]][col[0]].mangtebao.push_back(SS[i]);
				karnau2[row[1]][col[1]]._sotebao++;
				karnau2[row[1]][col[1]].mangtebao.push_back(SS[i]);
			}
		}
	}
	// lay cac te bao bat buoc phai co va dua cac te bao khong bat buoc vao vector
	for (int i = 0; i < 4;i++)
	for (int j = 0; j < 4; j++)
	{
		if (karnau2[i][j]._sotebao == 1)
		{

			this->_kq.push_back(karnau2[i][j].mangtebao[0]);
			karnau2[i][j]._sotebao = 0;
		}
		else if (karnau2[i][j]._sotebao>1)
			tb_conlai.push_back(karnau2[i][j]);
	}
	//lay cac te bao con lai
	/*cout << "Cac te bao con lai: " << endl;
	for (int i = 0; i < tb_conlai.size(); i++)
	{
		for (int k = 0; k < tb_conlai[i]._sotebao; k++)
		{
			for (int j = 0; j < tb_conlai[i].mangtebao[k].size(); j++)
				cout << tb_conlai[i].mangtebao[k][j];
			cout << endl;
		}

	}*/
}
void Bool::chontohop_kq(int i)
{
	if (i < tb_conlai.size())
	{
		for (int j = 0; j < tb_conlai[i]._sotebao; j++)
		{
			_kq.push_back(tb_conlai[i].mangtebao[j]);
			chontohop_kq(i + 1);
		}
	}
	else{
		//in te bao
		for (int k = 0; k < _kq.size(); k++)
		{
			for (int j = 0; j < _kq[k].size()-1; j++)
			{
				cout << _kq[k][j];
			}
			cout << " v ";
		}
	/*	for (int i = 0; i < _kq[k].size(); i++)
			cout << _kq[k][i];*/
		cout << endl;
		_kq.pop_back();
	}
}
void Bool::Get_nonessential()
{
	chontohop_kq(0);

}

Bool::Bool()
{
	_karnaugh = NULL;
	_dathuc = "";
}

Bool::Bool(string a)
{
	_dathuc = a;
	_karnaugh = this->karnaugh();
}

Bool::~Bool()
{
	if (_karnaugh != NULL)
	{
		for (int i = 0; i < 4; i++)
			delete _karnaugh[i];
		delete _karnaugh;
	}
	_karnaugh == NULL;
}