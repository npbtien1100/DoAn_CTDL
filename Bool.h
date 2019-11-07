#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct cell
{
	int _sotebao = 0;
	vector<vector<char>> mangtebao;
};

vector<int> convert_intonum(const string ttt1);
string convert_intostring(const vector<int>&a);
string convert_intostring(const vector<char>&a);
vector<int> gop_tutoitieu(const string ttt1,const string ttt2);
vector<char> convert_intochar(const string&ttt1);
vector<vector<char>> convert_tovtchar(const vector<string>&s1);
//vector<int> gop_tutoitieu(const vector<int>&ttt1, const vector<int>&ttt2);
bool kt_tontai(const vector<vector<int>> &a,const vector<int>& b);
bool kt_tontai(const vector<int>&a, const vector<int>&b);
bool kt_chuanhoa(const vector<int>&a, const vector<int> &b);

//Tung
bool CompareMinTerms(vector<char>, vector<char>);
vector<char> GroupMinTerms(vector<char>, vector<char>);

class Bool{
private:
	string _dathuc;
	char** _karnaugh;
	vector<vector<int>> list_tebaolon;
	vector<string> list_tutoitieu;
	vector<vector<char>> _kq;
	vector<cell> tb_conlai;
public:
	void Input_dathuc();
	char** karnaugh();
	void Create_tebaolon();
	vector<string> Create_tutoitieu();
	void In_tutoitieu();
	vector<vector<char>> Minimize();
	void Get_essential();
	void Get_nonessential();
	void chontohop_kq(int i);
	int size_listtutoitieu();
	void Chuanhoa_tebaolon();
	Bool();
	Bool(string a);
	~Bool();
};
