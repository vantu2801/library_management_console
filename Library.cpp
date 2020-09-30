#include<iostream> // cout,cin
#include<string> //xuat string
#include<cstdlib> 
#include<conio.h>
#include<iomanip> //setw
#include<cstring>
#include<fstream>
#include<vector>
#include<Windows.h>

using namespace std;
void Alert();
void move(string** p, int n);
string StrToUpperCase(string arg);
struct Date
{
	unsigned int day, month, year;
};
struct Book
{
	int ms;
	string tenSach;
	string tenTG;
	string nhaXB;
	int namXB;
	int soLuong; // Tong so sach nhap vao kho
	int soSachMuon;//So luong sach da duoc muon
	bool trangthai;//True="Con sach" , False="Het sach"
	Book* next;
};
struct person
{
	int mssv;
	string tenSV;
	int soLuong;
	int* data;
	string ngayMuon;
	string ngayTra;
	Book** sachMuon;
	person* pNext;
};
typedef person* SinhVien;
SinhVien firstSV, lastSV, tSV,preSV;
unsigned long sumSV;
int pFile;
Book* first, * last, * t;
Book* coppyfirst, *coppylast,*coppyt;
unsigned long sum;
Book* MSBookSearch(int);
bool CheckNumber(string arg);
bool MSSearch(int);

bool CheckMSSV(int mssv)
{
	SinhVien sv;
	sv = firstSV;
	while (sv != NULL)
	{
		if (mssv == sv->mssv)
		{
			tSV = sv;
			return true;
		}
		else
		{
			preSV = sv;
			sv = sv->pNext;
		}
	}
	return false;
}

void ShowSV()
{

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SinhVien run = firstSV;
	bool fun;
	system("cls");
	if (run == NULL)
	{
		
		Alert();
		system("pause");
	}
	else {
		cout << "\n";
		cout << "\t\t\t\t\t\t\t      BANG THONG KE SINH VIEN MUON SACH THU VIEN      " << endl << endl;
		/*Title*/
		SetConsoleTextAttribute(hConsoleColor, 96);
		cout << left << setw(30) << "Ho & ten sinh vien";
		cout << left << setw(25) << "Ma so sinh vien";
		cout << left << setw(20) << "Ngay muon sach";
		cout << left << setw(20) << "Ngay tra sach";
		cout << left << setw(25) << "Ten sach da dang ky";
		cout << left << setw(15) << "Ma so sach";
		cout << left << setw(25) << "Ten tac gia ";
		cout << left << setw(8) << "So Luong";
		cout << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		/*Title*/
		while (run != NULL)
		{
			fun = true;
			SetConsoleTextAttribute(hConsoleColor, 224);
			for (int i = 0; i < run->soLuong; i++)
			{
				if (fun)
				{
					cout << left << setw(30) << run->tenSV;
				}
				else
				{
					cout << left << setw(30) << "";
				}
				if (fun)
				{
					cout << left << setw(25) << run->mssv;
				}
				else
				{
					cout << left << setw(25) << "";
				}
				if (fun)
				{
					cout << left << setw(20) << run->ngayMuon;
				}
				else
				{
					cout << left << setw(20) << "";
				}
				if (fun)
				{
					cout << left << setw(20) << run->ngayTra;
					fun = false;
				}
				else
				{
					cout << left << setw(20) << "";
				}
				cout << left << setw(25) << (run->sachMuon)[i]->tenSach;
				cout << left << setw(15) << (run->sachMuon)[i]->ms;
				cout << left << setw(25) << (run->sachMuon)[i]->tenTG;
				cout << left << setw(8) << (run->data)[i];
				cout << endl;
			}
			run = run->pNext;
		}
		SetConsoleTextAttribute(hConsoleColor, 112);
		system("pause");
	}



}
void Dangky()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	bool check;
	bool kt;
	char c;
	char rac;
	int index;
	string* point;
	int ms;
	int sl;
	SinhVien sinhvien = new person();
	SinhVien run;
	string danhmuc[5][2] =
	{
		{"Ho & Ten              :",""},
		{"Ma so sinh vien       :",""},
		{"Ngay muon	      :",""},
		{"Ngay tra              :",""},
		{"So dau sach dang ky   :",""}
	};
	string choose[2] =
	{
		"                      NEXT TO                        ",
		"                       BACK                          "
	};
	point = &danhmuc[0][1];
	do {
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << "                INFORMATION OF PERSON                " << endl << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		for (int i = 0; i < 5; i++)
		{
			if (point < &danhmuc[0][1]) point = &danhmuc[4][1];
			else if (point > & danhmuc[4][1]) point = &danhmuc[0][1];
			if (point == &danhmuc[i][1])
			{
				index = i;
				cout << danhmuc[i][0] << "_" << danhmuc[i][1] << endl;
			}
			else cout << danhmuc[i][0] << danhmuc[i][1] << endl;
		}
		if (danhmuc[0][1] != "" && danhmuc[1][1] != "" && danhmuc[2][1] != "" &&
			danhmuc[3][1] != "" && danhmuc[4][1] != "")
		{
			char ch;
			point = &choose[0];
			do {
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "                INFORMATION OF PERSON                " << endl << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				for (int i = 0; i < 5; i++)
				{
					cout << danhmuc[i][0] << danhmuc[i][1] << endl;
				}
				if (point < &choose[0]) point = &choose[1];
				else if (point > & choose[1]) point = &choose[0];
				cout << endl;
				for (int i = 0; i < 2; i++)
				{
					if (point == &choose[i])
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);

					}
					else
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
				}

				ch = _getch();
				if (ch == -32) move(&point, 1);
			} while (ch != 13);
			if (point == &choose[0])
			{
				sinhvien->tenSV = danhmuc[0][1];
				if (CheckNumber(danhmuc[1][1]))
				{
					sinhvien->mssv = stoi(danhmuc[1][1]);
					if (CheckMSSV(sinhvien->mssv))
					{
						SetConsoleTextAttribute(hConsoleColor, 113);
						cout << "Ma so sinh vien nay da ton tai trong he thong." << endl << "Vui long tra sach lan muon truoc de tiep tuc su dung dich vu." << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
						system("pause");
						break;
					}
				}
				else
				{
					throw string("  Error  ");
				}

				sinhvien->ngayMuon = danhmuc[2][1];
				sinhvien->ngayTra = danhmuc[3][1];

				if (CheckNumber(danhmuc[4][1]))
				{
					sinhvien->soLuong = stoi(danhmuc[4][1]);
				}
				else
				{
					throw string("  Error  ");
				}


				sinhvien->sachMuon = new Book * [sinhvien->soLuong];
				sinhvien->data = new int[sinhvien->soLuong];
				sinhvien->pNext = NULL;
				for (int i = 0; i < sinhvien->soLuong; i++)
				{
					(sinhvien->sachMuon)[i] = NULL;
				}
				for (int i = 0; i < sinhvien->soLuong; i++)
				{

					do {
						system("cls");
						SetConsoleTextAttribute(hConsoleColor, 224);
						cout << "               TITLE OF BOOK " << i + 1 << "                 " << endl << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
						cout << "Nhap ms      :";
						cin >> ms;
						(sinhvien->sachMuon)[i] = MSBookSearch(ms);

						if ((sinhvien->sachMuon)[i] == NULL )
						{
							SetConsoleTextAttribute(hConsoleColor, 116);
							cout << ms;
							cout << " is not found " << endl;
							cout << "Press any key to retype..." << endl;
							SetConsoleTextAttribute(hConsoleColor, 112);
							rac = _getch();

						}
						else
						{
							kt = true;
							if (kt)
							{
								for (int j = 0; j < i; j++)
								{

									if (ms == (sinhvien->sachMuon)[j]->ms)
									{
										kt = false;
										SetConsoleTextAttribute(hConsoleColor, 116);
										cout << "Sach nay da duoc dang ky  " << endl;
										cout << "Press any key to retype..." << endl;
										SetConsoleTextAttribute(hConsoleColor, 112);
										rac = _getch();
									}
								}
							}
							if(kt)
							{
								cout << "Nhap so luong:";
								cin >> sl;
								if (sl <= 0)
								{
									throw string("  Error  ");
								}
								if (sl <= (sinhvien->sachMuon)[i]->soLuong - (sinhvien->sachMuon)[i]->soSachMuon)
								{
									(sinhvien->sachMuon)[i]->soSachMuon += sl;
									(sinhvien->data)[i] = sl;
									SetConsoleTextAttribute(hConsoleColor, 160);
									cout << "\n         Dang ky muon sach thanh cong          " << endl;
									SetConsoleTextAttribute(hConsoleColor, 112);	
									system("pause");

									break;
								}
								else
								{
									SetConsoleTextAttribute(hConsoleColor, 78);
									cout << "\n       Vuot qua so luong sach hien co          " << endl;
									SetConsoleTextAttribute(hConsoleColor, 112);
									system("pause");

								}
							}
							
						};
					} while (1);
				}
				if (firstSV == NULL)
				{
					firstSV = lastSV = sinhvien;
					sumSV++;
				}
				else
				{
					lastSV->pNext = sinhvien;
					lastSV = sinhvien;
					sumSV++;
				}
				break;
			}
			else
			{
				break;
			}
		}
		c = _getch();
		if (c == -32) {
			move(&point, 2);
		}
		else if (c != 13) {
			cout << c;
			getline(cin, danhmuc[index][1]);
			danhmuc[index][1] = c + danhmuc[index][1];
		}
	} while (1);
}

void CreateBook()
{
	first = last = t = NULL;
	sum = 0;
}
void CreateSV()
{
	firstSV = lastSV = tSV = preSV = NULL;
	sumSV = 0;
}
void Create()
{
	CreateBook();
	CreateSV();
}
void Show(Book* rd)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 224);
	cout << left << setw(15) << rd->ms;
	cout << left << setw(25) << rd->tenSach;
	cout << left << setw(25) << rd->tenTG;
	cout << left << setw(25) << rd->nhaXB;
	cout << left << setw(8) << rd->namXB;
	cout << right << setw(20) << rd->soLuong - rd->soSachMuon;
	cout << right << setw(20) << rd->soLuong;
	if ((rd->soLuong) - (rd->soSachMuon) == 0)
	{
		rd->trangthai = false;
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 228);
		cout << right << setw(30) << "      Het sach   ";
		SetConsoleTextAttribute(hConsoleColor, 224);
	}
	else {
		rd->trangthai = true;
		cout << right << setw(30) << "      Con sach   ";
	}
	SetConsoleTextAttribute(hConsoleColor, 112);
	cout << endl;
}

void TitleShow()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 96);
	cout << left << setw(15) << "Ma so sach";
	cout << left << setw(25) << "Ten sach";
	cout << left << setw(25) << "Ten tac gia";
	cout << left << setw(25) << "Nha xuat ban";
	cout << left << setw(8) << "Nam XB";
	cout << left << setw(20) << "     Sach con trong kho ";
	cout << right << setw(20) << "      Sach nhap ve ban dau ";
	cout << right << setw(15) << "      Trang thai   ";
	cout << endl;
	SetConsoleTextAttribute(hConsoleColor, 112);
}
void Alert()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 96);
	cout << "                ALERT                " << endl;
	SetConsoleTextAttribute(hConsoleColor, 224);
	cout << "                                     " << endl;
	cout << "                                     " << endl;
	cout << "           Danh sach rong            " << endl;
	cout << "                                     " << endl;
	cout << "                                     " << endl;
	SetConsoleTextAttribute(hConsoleColor, 112);

}
void ShowAll()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* p = first;
	system("cls");
	if (p == NULL)
	{
		Alert();
		
	}
	else {
		cout << "\n";
		cout << "\t\t\t\t\t\t\t\t     BANG THONG KE SACH THU VIEN" << endl;
		cout << "\n";
		TitleShow();
		while (p != NULL)
		{
			Show(p);
			p = p->next;
		}
		SetConsoleTextAttribute(hConsoleColor, 112);
		
	}
	system("pause");
}
void ShowAllLendingBook()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* p = first;
	system("cls");
	if (p == NULL)
	{
		Alert();
	}
	else {
		cout << "\n";
		cout << "\t\t\t\t\t\t\t\t     BANG THONG KE NHUNG SACH DA HET" << endl;
		cout << "\n";
		TitleShow();
		while (p != NULL)
		{
			if (p->trangthai == false)
			{
				Show(p);
			}
			p = p->next;
		}
		SetConsoleTextAttribute(hConsoleColor, 112);
		
	}
	system("pause");
}
void ShowAllNotLendingBook()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* p = first;
	system("cls");
	if (p == NULL)
	{
		Alert();
		
	}
	else {
		cout << "\n";
		cout << "\t\t\t\t\t\t\t\t     BANG THONG KE NHUNG SACH CON TRONG THU VIEN" << endl;
		cout << "\n";
		TitleShow();
		while (p != NULL)
		{
			if (p->trangthai == true)
			{
				Show(p);
			}
			p = p->next;
		}
		SetConsoleTextAttribute(hConsoleColor, 112);
		
	}
	system("pause");
}
void move(string** p, int n)
{
	//cho mang n cot
	char c;
	c = _getch();
	switch (c)
	{
	case 72:
		(*p) -= n;
		break;
	case 80:
		(*p) += n;
		break;
	}
}
string StrToUpperCase(string arg)
{
	for (int i = 0; i < arg.length(); i++)
	{
		if (arg[i] >= 'a' && arg[i] <= 'z')
		{
			arg[i] -= 32;
		}
	}
	return arg;
}
//string Trim(string arg)
//{
//
//	for (int i = 0; i < arg.length(); i++)
//	{
//		if (arg[i] == 32)
//		{
//			if(arg[i+1]==32)
//			{
//			}
//		}
//	}
//
//}
bool CompareStr(string a, string b)
{
	a = StrToUpperCase(a);
	b = StrToUpperCase(b);
	if (a.compare(b) == 0) return true;
	return false;
}
bool CheckNumber(string arg)
{
	char* check;
	check = &arg[0];
	if (arg.length() > 9) return false;
	for (int i = 0; i < arg.length(); i++)
	{
		if (*check >= '0' && *check <= '9')
		{
			check++;
		}
		else return false;
	}
	return true;
}
Book* InputInforOfTheBook()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* temp = new Book;
	char c;
	int index;
	string choose[2] =
	{ "               OK                " ,
	  "             CANCEL              "
	};
	string danhmuc[6][2] =
	{
		{"Ma so       :",""},
		{"Ten sach    :",""},
		{"Ten tac gia :",""},
		{"Nha xuat ban:",""},
		{"Nam xuat ban:",""},
		{"So luong    :",""},
	};
	string* point = &danhmuc[0][1];
	do {
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << "     INFORMATION OF THE BOOK     " << endl << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		for (int i = 0; i < 6; i++) {
			if (point < &danhmuc[0][1]) point = &danhmuc[5][1];
			else if (point > & danhmuc[5][1]) point = &danhmuc[0][1];

			if (point == &danhmuc[i][1])
			{
				index = i;
				cout << danhmuc[i][0] << "_" << danhmuc[i][1] << endl;
			}
			else
			{
				cout << danhmuc[i][0] << danhmuc[i][1] << endl;
			}
		}
		if (danhmuc[0][1] != "" && danhmuc[1][1] != "" && danhmuc[2][1] != "" &&
			danhmuc[3][1] != "" && danhmuc[4][1] != "" && danhmuc[5][1] != "")
		{
			char ch;

			point = &choose[0];
			do {
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "     INFORMATION OF THE BOOK     " << endl << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				for (int i = 0; i < 6; i++)
				{
					cout << danhmuc[i][0] << danhmuc[i][1] << endl;
				}
				if (point < &choose[0]) point = &choose[1];
				else if (point > & choose[1]) point = &choose[0];
				cout << endl;

				for (int i = 0; i < 2; i++)
				{
					if (point == &choose[i])
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
				}
				ch = _getch();
				if (ch == -32) move(&point, 1);


			} while (ch != 13);
			if (point == &choose[0]) {
				if (CheckNumber(danhmuc[0][1]))
				{
					temp->ms = stoi(danhmuc[0][1]);
				}
				else
				{
					throw string("   Input Error   ");
				}
				if (MSSearch(temp->ms))
				{
					throw - 1;
				}
				temp->tenSach = danhmuc[1][1];
				temp->tenTG = danhmuc[2][1];
				temp->nhaXB = danhmuc[3][1];
				if (CheckNumber(danhmuc[4][1]))
				{
					temp->namXB = stoi(danhmuc[4][1]);
				}
				else
				{
					throw string("   Input Error   ");
				}
				if (CheckNumber(danhmuc[5][1]))
				{
					temp->soLuong = stoi(danhmuc[5][1]);
				}
				else
				{
					throw string("   Input Error   ");
				}
				temp->soSachMuon = 0;
				temp->trangthai = true;
				temp->next = NULL;
				t = temp;
				return temp;
			}
			else if (point == &choose[1]) {
				return NULL;
			}

		}
		c = _getch();
		if (c == -32) {
			move(&point, 2);
		}
		else if (c != 13)//Tranh lan dau tien ma nhap Enter 
		{
			cout << c;
			getline(cin, danhmuc[index][1]);
			danhmuc[index][1] = c + danhmuc[index][1];
		}
	} while (1);
}

void Append()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* p;
	Book* run;
	bool check;
	int ms;
	string choose[3] =
	{ "      Vi tri dau tien      ",
	  "      Vi tri cuoi cung     ",
	  "       Vi tri bat ky       "
	};

	string AddBook = "         ADD A BOOK        ";
	string* point = choose;
	char ch;
	do {
		//NOTE
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << AddBook << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		for (int i = 0; i < 3; i++)
		{
			if (point < &choose[0]) point = &choose[2];
			else if (point > & choose[2]) point = &choose[0];

			if (point == &choose[i])
			{
				SetConsoleTextAttribute(hConsoleColor, 143);
				cout << choose[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 240);
				cout << choose[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
		}
		ch = _getch();
		if (ch == -32)
		{
			move(&point, 1);
		}
	} while (ch != 13);
	
	do
	{
		check = true;
		try
		{
			InputInforOfTheBook();
		}
		catch (const string & s)
		{
			cout << "\n\t";
			SetConsoleTextAttribute(hConsoleColor, 78);
			cout << s << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			check = false;
			system("pause");
		}
		catch (const int ammot)
		{
			cout << "\n     ";
			SetConsoleTextAttribute(hConsoleColor, 78);
			cout << "  \"Ma So\" has existed  " << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			check = false;
			system("pause");
		}


	} while (!check);
	p = t;
	t = NULL;
	if (point == &choose[2])
	{
		    check = false;
			system("cls");
			SetConsoleTextAttribute(hConsoleColor, 224);
			cout << "         ENTER INTO MS          " << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			cout << "Them vao sau ma so duoi day:";
			cout << "\nNhap ma so sach: ";
			cin >> ms;
			run = first;
			while (run != NULL && !check)
			{
				if (run->ms == ms)
				{
					check = true;
				}
				else
				{
					run = run->next;
				}
			}
			if (!check)
			{
				cout << "  ";
				SetConsoleTextAttribute(hConsoleColor, 78);
				cout << "  \"Ma So\" isn't existing   " << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
			else
			{
				p->next = run->next;
				run->next = p;
			}
			sum++;
			system("pause");
	}
	if (first == NULL && p != NULL) {
		first = p;
		last = p;
		sum++;
	}
	else
	{
		if (point == &choose[0] && p != NULL)
		{
			p->next = first;
			first = p;
			sum++;
		}
		else if (point == &choose[1] && p != NULL)
		{
			last->next = p;
			last = p;
			sum++;
		}

	}
}
bool AuthorNameSearch(string tenTacGia);
void ShowList(vector<Book>& list)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	if (list.empty())
	{
		cout << endl;
		cout << "Khong tim thay..." << endl;
	}
	else
	{
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t        BANG TRA CUU KET QUA   " << endl;
		cout << "\n";
		TitleShow();
		for (int i = 0; i < list.size(); i++)
		{
			SetConsoleTextAttribute(hConsoleColor, 224);
			cout << left << setw(15) << list.at(i).ms;
			cout << left << setw(25) << list.at(i).tenSach;
			cout << left << setw(25) << list.at(i).tenTG;
			cout << left << setw(25) << list.at(i).nhaXB;
			cout << left << setw(8) << list.at(i).namXB;
			cout << right << setw(20) << list.at(i).soLuong - list.at(i).soSachMuon;
			cout << right << setw(20) << list.at(i).soLuong;
			if ((list.at(i).soLuong - list.at(i).soSachMuon) == 0)
			{
				list.at(i).trangthai = false;
				hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsoleColor, 228);
				cout << right << setw(30) << "      Het sach   ";
				SetConsoleTextAttribute(hConsoleColor, 224);
			}
			else {
				list.at(i).trangthai = true;
				cout << right << setw(30) << "      Con sach   ";
			}
			SetConsoleTextAttribute(hConsoleColor, 112);
			cout << endl;
		}
	}
}
void Search()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* p = first;
	bool check; // check TH3
	char c;//move
	int index;
	vector<Book> list;
	string danhmuc[6][2] =
	{
		{"Ten sach    :",""},
		{"Ten tac gia :",""},
		{"Nha xuat ban:",""},
		{"\n                 SEARCH                ",""},
		{"                 BACK                  ",""},
		{"                 RESET                 ",""},
	};
	string* point = &danhmuc[0][1];
	do {
		while (1)
		{
			system("cls");
			SetConsoleTextAttribute(hConsoleColor, 224);
			cout << "               SEARCH BOX              " << endl << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			for (int i = 0; i < 6; i++) {
				if (point < &danhmuc[0][1]) point = &danhmuc[5][1];
				else if (point > & danhmuc[5][1]) point = &danhmuc[0][1];
				if (point == &danhmuc[i][1])
				{
					if (i == 3 || i == 4 || i == 5)
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << danhmuc[i][0] << danhmuc[i][1] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						index = i;
						cout << danhmuc[i][0] << "_" << danhmuc[i][1] << endl;
					}
				}
				else
				{
					if (i == 3 || i == 4 || i == 5)
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << danhmuc[i][0] << danhmuc[i][1] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						cout << danhmuc[i][0] << danhmuc[i][1] << endl;
					}
				}
			}
			c = _getch();
			if (c == -32)
			{
				move(&point, 2);
			}
			else if (point != &danhmuc[3][1] && point != &danhmuc[4][1] && point != &danhmuc[5][1] && c != 13)
			{
				cout << c;
				getline(cin, danhmuc[index][1]);
				danhmuc[index][1] = c + danhmuc[index][1];
			}
			else if ((point == &danhmuc[3][1] || point == &danhmuc[4][1] || point == &danhmuc[5][1]) && c == 13) break;
		}
		if (point == &danhmuc[3][1] && c == 13)
		{
			c = 0;
			for (int i = list.size() - 1; i >= 0; i--)
			{
				list.erase(list.begin() + i);
			}
			if (first == NULL)
			{
				system("cls");
				Alert();
				system("pause");
			}
			else
			{
				system("cls");
				if (danhmuc[0][1] != "" || danhmuc[1][1] != "" || danhmuc[2][1] != "")
				{
					p = first;
					if (danhmuc[0][1] != "")
					{

						while (p != NULL)
						{
							if (CompareStr(danhmuc[0][1], p->tenSach))
							{
								list.push_back(*p);
							}
							p = p->next;
						}
						if (danhmuc[1][1] != "")
						{
							index = 0;
							while (index < list.size())
							{   //
								if (!CompareStr(danhmuc[1][1], list.at(index).tenTG)) list.erase(list.begin() + index);
								else index++;
							}
							if (danhmuc[2][1] != "")
							{
								index = 0;
								while (index < list.size())
								{   //
									if (!CompareStr(danhmuc[2][1], list.at(index).nhaXB)) list.erase(list.begin() + index);
									else index++;
								}
								ShowList(list);
							}
							else
							{
								ShowList(list);
							}

						}
						else
						{
							if (danhmuc[2][1] != "")
							{
								index = 0;
								while (index < list.size())
								{   //
									if (!CompareStr(danhmuc[2][1], list.at(index).nhaXB)) list.erase(list.begin() + index);
									else index++;
								}
								ShowList(list);
							}
							else
							{
								ShowList(list);
							}
						}
					}
					else if (danhmuc[1][1] != "")
					{
						while (p != NULL)
						{  //
							if (CompareStr(danhmuc[1][1], p->tenTG))
							{
								list.push_back(*p);
							}
							p = p->next;
						}
						if (danhmuc[2][1] != "")
						{
							index = 0;
							while (index < list.size())
							{  //
								if (!CompareStr(danhmuc[2][1], list.at(index).nhaXB)) list.erase(list.begin() + index);
								else index++;
							}
							ShowList(list);
						}
						else
						{
							ShowList(list);
						}

					}
					else if (danhmuc[2][1] != "")
					{
						check = false;
						while (p != NULL)
						{
							if (CompareStr(danhmuc[2][1], p->nhaXB))
							{
								check = true;
								break;
							}
							p = p->next;
						}
						if (check == false)
						{
							cout << endl;
							cout << "Khong tim thay..." << endl;
						}
						else {
							cout << endl;
							cout << "\t\t\t\t\t       BANG TRA CUU KET QUA   " << endl;
							cout << endl;
							TitleShow();
							p = first;
							while (p != NULL)
							{   //CompareStr(,)
								if (CompareStr(danhmuc[2][1], p->nhaXB))
								{
									Show(p);
								}
								p = p->next;
							}
						}

					}
				}
				system("pause");
			}

		}
		else if (point == &danhmuc[5][1])
		{
			for (int i = 0; i < 3; i++)
			{
				danhmuc[i][1] = "";
			}
		}
		else if (point == &danhmuc[4][1] && c == 13) break;

	} while (1);
}

/*2 chuc nang
-Xoa phan tu dau tien trong danh sach
-Xoa 1 phan tu duy nhat trong danh sach*/
void FirstDelete()
{
	t = first;
	first = first->next;
	delete t;
	t = NULL;
}

/*1 chuc nang
-Xoa phan tu cuoi cung trong danh sach (co hon 1 phan tu)*/
void LastDelete()
{
	Book* run;
	run = first;
	while (run->next != NULL)
	{
		t = run;
		run = run->next;
	}
	t->next = NULL;
	delete run;
	last = t;
	t = NULL;
}
Book* MSBookSearch(int ms)
{
	Book* temp = first;
	while (temp != NULL)
	{
		if (ms == temp->ms) return temp;
		else temp = temp->next;
	}
	return NULL;
}
bool MSSearch(int ms)
{
	Book* temp = first;
	while (temp != NULL)
	{
		if (ms != temp->ms) temp = temp->next;
		else return true;
	}
	return false;
}
bool BookNameSearch(string tenSach)
{
	Book* temp = first;
	while (temp != NULL)
	{
		if (StrToUpperCase(tenSach) != StrToUpperCase(temp->tenSach)) temp = temp->next;
		else return true;
	}
	return false;
}
bool AuthorNameSearch(string tenTacGia)
{
	Book* temp = first;
	while (temp != NULL)
	{
		if (StrToUpperCase(tenTacGia) != StrToUpperCase(temp->tenTG)) temp = temp->next;
		else return true;
	}
	return false;
}
void BookNameDelete()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* temp, * temp1;
	string thongbao = "Khong tim thay...";
	char ch;
	string Bdanhmuc[2] =
	{
		"            DELETE HERE            ",
		"              CANCEL               ",
	};
	string choose[2] =
	{
		"             RETYPE                ",
		"             CANCEL                "
	};
	string* point;
	string tensach;
	do {
		point = Bdanhmuc;
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << "            DELETE BOX             " << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		cout << "Nhap ten sach:";
		getline(cin, tensach);
		if (BookNameSearch(tensach))
		{
			do
			{
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "            DELETE BOX             " << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				cout << "Nhap ten sach:" << tensach << endl;
				for (int i = 0; i < 2; i++)
				{
					if (point < &Bdanhmuc[0]) point = &Bdanhmuc[1];
					else if (point > & Bdanhmuc[1]) point = &Bdanhmuc[0];
					if (point == &Bdanhmuc[i])
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << Bdanhmuc[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << Bdanhmuc[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);

					}
				}
				ch = _getch();
				if (ch == -32) {
					move(&point, 1);
				}
			} while (ch != 13);

			if (point == &Bdanhmuc[0])
			{

				while (StrToUpperCase(tensach) == StrToUpperCase(first->tenSach) && sum > 1)
				{
					if (first->soSachMuon == 0)
					{
						FirstDelete();
						sum--;
					}
					else
					{
						throw string("You can't delete here.Because this \n      is a reference or more.      ");
					}
				}
				if (StrToUpperCase(tensach) == StrToUpperCase(first->tenSach) && sum == 1)
				{
					if (first->soSachMuon == 0)
					{
						FirstDelete();
						sum--;
					}
					else
					{
						throw string("You can't delete here.Because this \n      is a reference or more.      ");
					}
				}
				else if (StrToUpperCase(tensach) != StrToUpperCase(first->tenSach) && sum > 1)
				{
					temp = first;
					while (temp != NULL)
					{

						if (StrToUpperCase(tensach) == StrToUpperCase(temp->tenSach))
						{
							if (temp->soSachMuon == 0)
							{
								t->next = temp->next;
								temp1 = temp;
								temp = t;
								t = temp1;
								delete t;
								sum--;
								t = temp;
							}
							else
							{
								throw string("You can't delete here.Because this \n      is a reference or more.      ");
							}
		
						}
						else
						{
							t = temp;
						}
						temp = temp->next;
					}
					t = NULL;
				}
			}
			else if (point == &Bdanhmuc[2])
			{
				//CANCEL
			}
		}
		else
		{
			point = choose;
			do
			{
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "            DELETE BOX             " << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				cout << "Nhap ten sach:" << tensach << endl;
				cout << thongbao << endl;
				for (int i = 0; i < 2; i++)
				{
					if (point < &choose[0]) point = &choose[1];
					else if (point > & choose[1]) point = &choose[0];
					if (point == &choose[i])
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);

					}
					else
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
				}
				ch = _getch();
				if (ch == -32) {
					move(&point, 1);
				}
			} while (ch != 13);
			if (point == &choose[0])
			{
				// thay doi gia tri ch de khong thoat khoi loop
				ch = 0;
			}
			else if (point == &choose[1])
			{
				//CANCEL
			}
		}
	} while (ch != 13);

}
void AuthorNameDelete()
{
	Book* temp, * temp1;
	string thongbao = "Khong tim thay...";
	char ch;
	string Bdanhmuc[2] =
	{
		"            DELETE HERE            ",
		"              CANCEL               ",
	};
	string choose[2] =
	{
		"             RETYPE                ",
		"             CANCEL                "
	};
	string* point;
	string tentacgia;
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		point = Bdanhmuc;
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << "            DELETE BOX             " << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		cout << "Nhap ten tac gia:";
		getline(cin, tentacgia);
		if (AuthorNameSearch(tentacgia))
		{
			do
			{
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "            DELETE BOX             " << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				cout << "Nhap ten tac gia:" << tentacgia << endl;
				for (int i = 0; i < 2; i++)
				{
					if (point < &Bdanhmuc[0]) point = &Bdanhmuc[1];
					else if (point > & Bdanhmuc[1]) point = &Bdanhmuc[0];
					if (point == &Bdanhmuc[i])
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << Bdanhmuc[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << Bdanhmuc[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
				}
				ch = _getch();
				if (ch == -32) {
					move(&point, 1);
				}
			} while (ch != 13);


			if (point == &Bdanhmuc[0])
			{

				while (StrToUpperCase(tentacgia) == StrToUpperCase(first->tenTG) && sum > 1)
				{
					if (first->soSachMuon == 0)
					{
						FirstDelete();
						sum--;
					}
					else
					{
						throw string("You can't delete here.Because this \n      is a reference or more.      ");
					}
				}
				if (StrToUpperCase(tentacgia) == StrToUpperCase(first->tenTG) && sum == 1)
				{
					if (first->soSachMuon == 0)
					{
						FirstDelete();
						sum--;
					}
					else
					{
						throw string("You can't delete here.Because this \n      is a reference or more.      ");
					}
				}
				else if (StrToUpperCase(tentacgia) != StrToUpperCase(first->tenTG) && sum > 1)
				{
					temp = first;
					while (temp != NULL)
					{

						if (StrToUpperCase(tentacgia) == StrToUpperCase(temp->tenTG))
						{
							if (temp->soSachMuon == 0)
							{
								t->next = temp->next;
								temp1 = temp;
								temp = t;
								t = temp1;
								delete t;
								sum--;
								t = temp;
							}
							else
							{
								throw string("You can't delete here.Because this \n      is a reference or more.      ");
							}
						}
						else
						{
							t = temp;
						}
						temp = temp->next;
					}
					t = NULL;
				}
			}
			else if (point == &Bdanhmuc[2])
			{
				//CANCEL
			}
		}
		else
		{
			point = choose;
			do
			{
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "            DELETE BOX             " << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				cout << "Nhap ten tac gia:" << tentacgia << endl;
				cout << thongbao << endl;
				for (int i = 0; i < 2; i++)
				{
					if (point < &choose[0]) point = &choose[1];
					else if (point > & choose[1]) point = &choose[0];
					if (point == &choose[i])
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << choose[i] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
				}
				ch = _getch();
				if (ch == -32) {
					move(&point, 1);
				}
			} while (ch != 13);
			if (point == &choose[0])
			{
				// thay doi gia tri ch de khong thoat khoi loop
				ch = 0;
			}
			else if (point == &choose[1])
			{
				//CANCEL
			}
		}
	} while (ch != 13);

}
void Delete()
{
	//Neu danh sach rong khong cho xoa
	/*Set mau*/
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* temp, * temp1;
	int ms;
	int index;
	char ch;
	string thongbao = "Khong tim thay...";
	string danhmuc[5] =
	{
		{"        Xoa sach dau tien          "},
		{"        Xoa sach cuoi cung         "},
		{"       Xoa sach theo ma so         "},
		{"      Xoa sach theo ten sach       "},
		{"     Xoa sach theo ten tac gia     "},
	};
	string MSdanhmuc[3] =
	{
		"            DELETE HERE            ",
		"          DELETE NEXT HERE         ",
		"              CANCEL               ",
	};
	string choose[2] =
	{
	  "              RETYPE               ",
	  "              CANCEL               "
	};
	string* point = &danhmuc[0];
	do
	{
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << "            DELETE BOX             " << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		for (int i = 0; i < 5; i++)
		{
			if (point < &danhmuc[0]) point = &danhmuc[4];
			else if (point > & danhmuc[4]) point = &danhmuc[0];
			if (point == &danhmuc[i])
			{
				index = i;
				SetConsoleTextAttribute(hConsoleColor, 143);
				cout << danhmuc[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 240);
				cout << danhmuc[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
		}
		ch = _getch();
		if (ch == -32) {
			move(&point, 1);
		}

	} while (ch != 13);
	if (first != NULL)
	{
		if (point == &danhmuc[0])
		{
			if (first->soSachMuon == 0)
			{
				FirstDelete();
				sum--;
			}
			else
			{
				throw string("You can't delete here.Because this \n      is a reference or more.      ");
			}
		}
		else if (point == &danhmuc[1])
		{
			if (sum == 1)
			{
				if (first->soSachMuon == 0)
				{
					FirstDelete();
					sum--;
				}
				else
				{
					throw string("You can't delete here.Because this \n      is a reference or more.      ");
				}
			}
			else if (sum > 1)
			{
				if (last->soSachMuon == 0)
				{
					LastDelete();
					sum--;
				}
				else
				{
					throw string("You can't delete here.Because this \n      is a reference or more.      ");
				}
				
			}
		}
		else if (point == &danhmuc[2])
		{

			do
			{
				point = MSdanhmuc;
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 224);
				cout << "            DELETE BOX             " << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				cout << "Nhap ma so sach:";
				cin >> ms;
				if (MSSearch(ms))
				{
					do
					{
						system("cls");
						SetConsoleTextAttribute(hConsoleColor, 224);
						cout << "            DELETE BOX             " << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
						cout << "Nhap ma so sach:" << ms << endl;
						for (int i = 0; i < 3; i++)
						{
							if (point < &MSdanhmuc[0]) point = &MSdanhmuc[2];
							else if (point > & MSdanhmuc[2]) point = &MSdanhmuc[0];
							if (point == &MSdanhmuc[i])
							{
								SetConsoleTextAttribute(hConsoleColor, 143);
								cout << MSdanhmuc[i] << endl;
								SetConsoleTextAttribute(hConsoleColor, 112);
							}
							else
							{
								SetConsoleTextAttribute(hConsoleColor, 240);
								cout << MSdanhmuc[i] << endl;
								SetConsoleTextAttribute(hConsoleColor, 112);

							}
						}
						ch = _getch();
						if (ch == -32) {
							move(&point, 1);
						}
					} while (ch != 13);
					if (point == &MSdanhmuc[0])
					{

						if (ms == first->ms)
						{
							if (first->soSachMuon == 0)
							{
								FirstDelete();
								sum--;
							}
							else
							{
								throw string("You can't delete here.Because this \n      is a reference or more.      ");
							}
						}
						else if (ms != first->ms)
						{
							temp = first;
							while (temp != NULL)
							{
								if (ms == temp->ms)
								{
									if (temp->soSachMuon == 0)
									{
										t->next = temp->next;
										temp1 = temp;
										temp = t;
										t = temp1;
										delete t;
										sum--;
										t = temp;
									}
									else
									{
										throw string("You can't delete here.Because this \n      is a reference or more.      ");
									}
									
								}
								else
								{
									t = temp;
								}
								temp = temp->next;
							}
							t = NULL;
						}
					}
					else if (point == &MSdanhmuc[1])
					{
						temp = first;
						while (temp != NULL)
						{
							if (ms == temp->ms && temp->next != NULL)
							{
								if ((temp->next)->soSachMuon == 0)
								{
									t = temp->next;
									temp->next = t->next;
									delete t;
									sum--;
									break;
								}
								else
								{
									throw string("You can't delete here.Because this \n      is a reference or more.      ");
								}
								
							}
							else {
								temp = temp->next;
							}
						}

					}
					else if (point == &MSdanhmuc[2])
					{
						//CANCEL
					}
				}
				else
				{
					point = choose;
					do
					{
						system("cls");
						SetConsoleTextAttribute(hConsoleColor, 224);
						cout << "            DELETE BOX             " << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
						cout << "Nhap ma so sach:" << ms << endl;
						cout << thongbao << endl;
						for (int i = 0; i < 2; i++)
						{
							if (point < &choose[0]) point = &choose[1];
							else if (point > & choose[1]) point = &choose[0];
							if (point == &choose[i])
							{
								SetConsoleTextAttribute(hConsoleColor, 143);
								cout << choose[i] << endl;
								SetConsoleTextAttribute(hConsoleColor, 112);

							}
							else
							{
								SetConsoleTextAttribute(hConsoleColor, 240);
								cout << choose[i] << endl;
								SetConsoleTextAttribute(hConsoleColor, 112);

							}
						}
						ch = _getch();
						if (ch == -32) {
							move(&point, 1);
						}
					} while (ch != 13);
					if (point == &choose[0])
					{
						// thay doi gia tri ch de khong thoat khoi loop
						ch = 0;
					}
					else if (point == &choose[1])
					{
						//CANCEL
					}
				}

			} while (ch != 13);
		}
		else if (point == &danhmuc[3])
		{
			BookNameDelete();
		}
		else if (point == &danhmuc[4])
		{
			AuthorNameDelete();
		}
	}


}
void ReturnBook()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	bool check; // check TH3
	char c;//move
	int ms;
	int index;
	string danhmuc[4][2] =
	{
		{"Ma so sinh vien    :",""},
	 {"\n                SEARCH                  ",""},
		{"                 BACK                   ",""},
		{"                 RESET                  ",""},
	};
	string choose[2] =
	{
	  "          OK           ",
	  "        CANCEL         "
	};
	string* point2;
	string* point = &danhmuc[0][1];
	do 
	{
		while (1)
		{
			system("cls");
			SetConsoleTextAttribute(hConsoleColor, 224);
			cout << "       SEARCH INFOMATION OF STUDENT     " << endl << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			for (int i = 0; i < 4; i++) {
				if (point < &danhmuc[0][1]) point = &danhmuc[3][1];
				else if (point > & danhmuc[3][1]) point = &danhmuc[0][1];
				if (point == &danhmuc[i][1])
				{
					if (i == 1 || i == 2|| i == 3)
					{
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << danhmuc[i][0] << danhmuc[i][1] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						index = i;
						cout << danhmuc[i][0] << "_" << danhmuc[i][1] << endl;
					}
				}
				else
				{
					if (i == 1 || i == 2|| i ==3)
					{
						SetConsoleTextAttribute(hConsoleColor, 240);
						cout << danhmuc[i][0] << danhmuc[i][1] << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
					}
					else
					{
						cout << danhmuc[i][0] << danhmuc[i][1] << endl;
					}
				}
			}
			c = _getch();
			if (c == -32)
			{
				move(&point, 2);
			}
			else if (point != &danhmuc[1][1] && point != &danhmuc[2][1] && point != &danhmuc[3][1] && c != 13)
			{
				cout << c;
				getline(cin, danhmuc[index][1]);
				danhmuc[index][1] = c + danhmuc[index][1];
			}
			else if ((point == &danhmuc[1][1] || point == &danhmuc[2][1] || point == &danhmuc[3][1]) && c == 13) break;
		}
		if (point == &danhmuc[1][1])
		{
			/*primary key of student*/
			if (danhmuc[0][1] != "")
			{
				if (CheckNumber(danhmuc[0][1]))
				{
					ms = stoi(danhmuc[0][1]);
				}
				else
				{
					throw string("  Error  ");
				}
				if (CheckMSSV(ms))
				{
					point2 =choose;
					do {
						system("cls");
						SetConsoleTextAttribute(hConsoleColor, 224);
						cout << "                INFOMATION OF STUDENT             " << endl << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
						cout << "Ma so sinh vien: " << tSV->mssv << endl;
						cout << "Ten sinh vien  : " << tSV->tenSV << endl;
						cout << "Ngay muon      : " << tSV->ngayMuon << endl;
						cout << "Ngay tra       : " << tSV->ngayTra << endl;
						SetConsoleTextAttribute(hConsoleColor, 143);
						cout << left << setw(25) << "Ten sach da muon";
						cout << left << setw(15) << "Ma so sach";
						cout << left << setw(10) << "So luong" << endl;
						for (int i = 0; i < tSV->soLuong; i++)
						{
							SetConsoleTextAttribute(hConsoleColor, 240);
							cout << left << setw(25) << (tSV->sachMuon)[i]->tenSach;
							cout << left << setw(15) << (tSV->sachMuon)[i]->ms;
							cout << left << setw(10) << (tSV->data)[i] << endl;
							SetConsoleTextAttribute(hConsoleColor, 112);
						}				
						cout << "\t     Thuc hien tra sach?" << endl;
						cout << endl;
						for (int i = 0; i < 2; i++) {
							if (point2 < &choose[0]) point2 = &choose[1];
							else if (point2 > & choose[1]) point2 = &choose[0];
							if (point2 == &choose[i])
							{
								cout << "\t   ";
								SetConsoleTextAttribute(hConsoleColor, 143);
								cout << choose[i] << endl;
								SetConsoleTextAttribute(hConsoleColor, 112);
							}
							else
							{
								cout << "\t   ";
								SetConsoleTextAttribute(hConsoleColor, 240);
								cout << choose[i] << endl;
								SetConsoleTextAttribute(hConsoleColor, 112);
							}

						}
						c = _getch();
						if (c == -32)
						{
							move(&point2, 1);
						}
						if ((point2 == &choose[0] || point2 == &choose[1]) && c == 13) break;
					} while (1);
					if (point2 == &choose[0])
					{
						SinhVien temp;
						temp = tSV;
						tSV = NULL;
						if (temp == firstSV)
						{
							firstSV = firstSV->pNext;
							for (int i = 0; i < temp->soLuong; i++)
							{
								(temp->sachMuon)[i]->soSachMuon -= (temp->data)[i];
							}
							delete temp;
						}
						else 
						{
							preSV->pNext = temp->pNext;
							for (int i = 0; i < temp->soLuong; i++)
							{
								(temp->sachMuon)[i]->soSachMuon -= (temp->data)[i];
							}
							delete temp;
						}
						SetConsoleTextAttribute(hConsoleColor, 160);
						cout << "\n                Hoan tat tra sach                 " << endl;
						SetConsoleTextAttribute(hConsoleColor, 112);
						sumSV--;
						system("pause");
						break;
					}
					else
					{
						break;
					}
					
					
					
				}
				else
				{
					SetConsoleTextAttribute(hConsoleColor, 116);
					cout << ms;
					cout << " is not found " << endl;
					SetConsoleTextAttribute(hConsoleColor, 112);
					system("pause");
					break;
				}
			}
		
		}
		else if (point == &danhmuc[2][1])
		{
			break;
		}
		else if (point == &danhmuc[3][1])
		{
			danhmuc[0][1] = "";
		}
	} while (1);
		
}
void OuputFileSinhVien()
{
	ofstream outFile;
	SinhVien temp = firstSV;
	outFile.open("DataForStudent.txt");
	outFile << sumSV << endl;
	while (temp != NULL)
	{
		
		outFile << temp->mssv << endl;
		outFile << temp->tenSV << endl;
		outFile << temp->ngayMuon << endl;
		outFile << temp->ngayTra << endl;
		outFile << temp->soLuong << endl;
		for (int i = 0; i < temp->soLuong; i++)
		{
			outFile << (temp->sachMuon)[i]->ms<<endl;
			outFile << (temp->data)[i]<<endl;
		}
		temp = temp->pNext;
		outFile << endl;
	}
	outFile.close();
}
void InputFileSinhVien()
{
	ifstream inFile("DataForStudent.txt");
	inFile >> sumSV;
	inFile.ignore();
	int i = sumSV;
	int ms;
	bool check;
	Book* run;
	while (i > 0)
	{
		
		SinhVien temp = new person;//EMPTY
		inFile >> temp->mssv;
		inFile.ignore();
		getline(inFile, temp->tenSV);	
		getline(inFile, temp->ngayMuon);
		getline(inFile, temp->ngayTra);
		inFile >> temp->soLuong;
		inFile.ignore();
		temp->sachMuon = new Book * [temp->soLuong];
		temp->data = new int[temp->soLuong];
		for (int j = 0; j < temp->soLuong; j++)
		{
			inFile >> ms;
			inFile.ignore();
			run = first;
			check = false;
			while (run != NULL)
			{
				if (run->ms == ms)
				{
					(temp->sachMuon)[j] = run;
				}
				run = run->next;
			}
			inFile >> (temp->data)[j];
			inFile.ignore();
		}
		
		temp->pNext = NULL;
		i--;
		if (firstSV == NULL)
		{
			firstSV = lastSV = temp;
		}
		else
		{
			lastSV->pNext = temp;
			lastSV = temp;
		}
	}
	inFile.close();
}
void OutputFile()
{
	ofstream outFile;

	Book* temp = first;
	outFile.open("Data.txt");
	outFile << sum << endl;
	while (temp != NULL)
	{
		outFile << temp->ms << endl;
		outFile << temp->tenSach << endl;
		outFile << temp->tenTG << endl;
		outFile << temp->nhaXB << endl;
		outFile << temp->namXB << endl;
		outFile << temp->soSachMuon << endl;
		outFile << temp->soLuong << endl;
		outFile << temp->trangthai << endl;

		temp = temp->next;
		outFile << endl;
	}
	outFile.close();
}
void InputFile()
{
	ifstream inFile("Data.txt");
	inFile >> sum;
	int i = sum;
	while (i > 0)
	{
		Book* temp = new Book;//EMPTY
		string text;
		inFile >> temp->ms;
		inFile.ignore();
		getline(inFile, temp->tenSach);
		getline(inFile, temp->tenTG);
		getline(inFile, temp->nhaXB);
		inFile >> temp->namXB;
		inFile >> temp->soSachMuon;
		inFile >> temp->soLuong;
		inFile >> temp->trangthai;
		temp->next = NULL;
		i--;
		if (first == NULL)
		{
			first = last = temp;
		}
		else
		{
			last->next = temp;
			last = temp;
		}
	}
	inFile.close();
}
/*Dung de check loi : Dat lai du lieu*/
void ResetData()
{
	Book* temp = first;
	while (temp != NULL)
	{
		t = temp->next;
		delete temp;
		temp = t;
	}
	Create();
	remove("Data.txt");
}
void SwapBook(Book* p, Book* q)
{
	Book temp;
	temp = *p;
	*p = *q;
	*q = temp;
	q->next = p->next;
	p->next = temp.next;
}
void BookNameSort()
{

	Book temp1,temp2;
	Book* run1;
	Book* run2;
	run1 = coppyfirst;
	while (run1 !=NULL )
	{
		run2 = run1->next;
		while (run2 != NULL)
		{
			if (StrToUpperCase(run1->tenSach).compare(StrToUpperCase(run2->tenSach)) > 0)
			{
				
				SwapBook(run1, run2);
			}
			run2 = run2->next;
		}
		run1 = run1->next;
	}
	
}
void AuthorNameSort()
{
	Book temp1, temp2;
	Book* run1;
	Book* run2;
	run1 = coppyfirst;
	while (run1 != NULL)
	{
		run2 = run1->next;
		while (run2 != NULL)
		{
			if (StrToUpperCase(run1->tenTG).compare(StrToUpperCase(run2->tenTG)) > 0)
			{
				SwapBook(run1, run2);
			}
			run2 = run2->next;
		}
		run1 = run1->next;
	}
}
void ManufacturerNameSort()
{
	Book temp1, temp2;
	Book* run1;
	Book* run2;
	run1 = coppyfirst;
	while (run1 != NULL)
	{
		run2 = run1->next;
		while (run2 != NULL)
		{
			if (StrToUpperCase(run1->nhaXB).compare(StrToUpperCase(run2->nhaXB)) > 0)
			{
				SwapBook(run1, run2);
			}
			run2 = run2->next;
		}
		run1 = run1->next;
	}
}
void PublishingYearSort()
{
	Book temp1, temp2;
	Book* run1;
	Book* run2;
	run1 = coppyfirst;
	while (run1 != NULL)
	{
		run2 = run1->next;
		while (run2 != NULL)
		{
			if (run1->namXB<run2->namXB)
			{
				SwapBook(run1, run2);
			}
			run2 = run2->next;
		}
		run1 = run1->next;
	}
}
Book* CoppyBook(Book a)
{
	Book* temp=new Book;
	*temp = a;
	return temp;
}
void CoppyAllBook()
{
	coppyfirst = coppylast = NULL;
	Book* run;
	run = first;	
	while (run != NULL)
	{
		if (coppyfirst == NULL)
		{
			coppyfirst = coppylast = CoppyBook(*run);
		}
		else
		{
			coppyt=CoppyBook(*run);
			coppyt->next = NULL;
			coppylast->next = coppyt;
			coppylast = coppyt;	
		}
		run = run->next;
	}
}
void ShowCoppy()
{

		HANDLE hConsoleColor;
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		Book* p = coppyfirst;
		system("cls");
		if (p == NULL)
		{
			Alert();
			system("pause");
		}
		else {
			cout << "\n";
			cout << "\t\t\t\t\t\t\t\t     BANG THONG KE SACH THU VIEN" << endl;
			cout << "\n";
			TitleShow();
			while (p != NULL)
			{
				Show(p);
				p = p->next;
			}
			SetConsoleTextAttribute(hConsoleColor, 112);
			system("pause");
		}


}
void Sort()
{
	
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Book* p;
	string choose[4] =
	{
	 "     Sap xep theo ten sach      ",
	 "    Sap xep theo ten tac gia    ",
	 "    Sap xep theo nha xuat ban   ",
	 "    Sap xep theo nam xuat ban   ",
	};
	string* point = choose;
	char ch;
	do {
		//NOTE
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << "           SORT BOOK            " << endl ;
		SetConsoleTextAttribute(hConsoleColor, 112);
		for (int i = 0; i < 4; i++)
		{
			if (point < &choose[0]) point = &choose[3];
			else if (point > & choose[3]) point = &choose[0];
			if (point == &choose[i])
			{
				SetConsoleTextAttribute(hConsoleColor, 143);
				cout << choose[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 240);
				cout << choose[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
		}
		ch = _getch();
		if (ch == -32)
		{
			move(&point, 1);
		}
	} while (ch != 13);
	if (point == &choose[0])
	{
		CoppyAllBook();
		BookNameSort();
		ShowCoppy();
	}
	else if (point == &choose[1])
	{
		CoppyAllBook();
		AuthorNameSort();
		ShowCoppy();
	}
	else if (point == &choose[2])
	{
		CoppyAllBook();
		ManufacturerNameSort();
		ShowCoppy();
	}
	else if (point == &choose[3])
	{
		CoppyAllBook();
		PublishingYearSort();
		ShowCoppy();
	}

}
void MainMenu(bool& a)
{
	bool check; //su dung trong try catch function dangky()
	char ch,c;
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 112);
	string Menu = "         MAIN MENU         ";
	string choose[10] =
	{ "  Them sach vao thu vien   ",
	  "  Hien thi thong tin sach  ",
	  "  Sap xep thong tin sach   ",
	  "  Tim kiem thong tin sach  ",
	  "  Xoa sach khoi thu vien   ",
	  "    Dang ky muon sach      ",
	  "   Hien thi thong tin SV   ",
	  "         Tra sach          ",
	  "          Thoat            "
	};
	string* point = choose;
	string Tu[3] =
	{
	  "      Hien thi tat ca      ",
	  "     Nhung sach da het     ",
	  "     Nhung sach van con    "
	};
	string* p1 = Tu;
	do {
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 224);
		cout << Menu << endl;
		SetConsoleTextAttribute(hConsoleColor, 112);
		for (int i = 0; i < 9; i++)
		{
			if (point < &choose[0]) point = &choose[8];
			else if (point > & choose[8]) point = &choose[0];
			if (point == &choose[i])
			{
				SetConsoleTextAttribute(hConsoleColor, 143);
				cout << choose[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 240);
				cout << choose[i] << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
			}

		}
		ch = _getch();
		if (ch == -32)
		{
			move(&point, 1);
		}
	} while (ch != 13);
	if (point == &choose[0])
	{
		Append();
		OutputFile();
	}
	else if (point == &choose[1])
	{
		do {
			system("cls");
			SetConsoleTextAttribute(hConsoleColor, 224);
			cout << "           MENU            " << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			for (int i = 0; i < 3; i++)
			{
				if (p1 < &Tu[0]) p1 = &Tu[2];
				else if (p1 > & Tu[2]) p1 = &Tu[0];
				if (p1 == &Tu[i])
				{
					SetConsoleTextAttribute(hConsoleColor, 143);
					cout << Tu[i] << endl;
					SetConsoleTextAttribute(hConsoleColor, 112);
				}
				else
				{
					SetConsoleTextAttribute(hConsoleColor, 240);
					cout << Tu[i] << endl;
					SetConsoleTextAttribute(hConsoleColor, 112);
				}
			}
			c = _getch();
			if (c == -32)
			{
				move(&p1, 1);
			}
		} while (c!=13);
		if(p1==&Tu[0])
		{ 
			ShowAll();
		}
		else if (p1 == &Tu[1])
		{
			ShowAllLendingBook();
		}
		else if (p1 == &Tu[2])
		{
			ShowAllNotLendingBook();

		}
	}
	else if (point == &choose[2])
	{
		Sort();
	}
	else if (point == &choose[3])
	{
		Search();
	}
	else if (point == &choose[4])
	{
		try
		{
			Delete();
			OutputFile();
		}
		catch (const string & e)
		{
			SetConsoleTextAttribute(hConsoleColor, 78);
			cout << e << endl;
			SetConsoleTextAttribute(hConsoleColor, 112);
			system("pause");
		}
	}
	else if (point == &choose[5])
	{
		do
		{
			check = false;
			try
			{
				Dangky();
				OuputFileSinhVien();
				OutputFile();
			}
			catch (const string e)
			{
				check = true;
				cout << "\t\t    ";
				SetConsoleTextAttribute(hConsoleColor, 78);
				cout << e << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				system("pause");
			}
		} while (check);

	}
	else if (point == &choose[6])
	{
		ShowSV();
	}
	else if (point == &choose[7])
	{
		do
		{
			check = false;
			try
			{
				ReturnBook();
				OuputFileSinhVien();
				OutputFile();
			}
			catch (const string e)
			{
				check = true;
				cout << "\t      ";
				SetConsoleTextAttribute(hConsoleColor, 78);
				cout << e << endl;
				SetConsoleTextAttribute(hConsoleColor, 112);
				system("pause");
			}
		} while (check);	
	}
	else if (point == &choose[8])
	{
		a = false;
	}
}
int main()
{
	bool Check = true;
	Create();
	InputFile();
	InputFileSinhVien();
	do {
		MainMenu(Check);
	} while (Check);

	return 0;
}
