#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <cstdlib>
#include <iomanip>
#pragma warning(disable:4996)

using namespace std;
// khai bao cau truc sinh vien
struct sinhvien
{
	string mssv;
	string ho;
	string ten;
	string ns;
	string gt;
	string lop;
	string toan;
	string ly;
	string tin;
	float diemToan;
	float diemLy;
	float diemTin;

};
typedef struct sinhvien SinhVien;

// ham doc file thing tin cua sinh vien
void DocDuLieuSV(ifstream &filein, SinhVien &sv)
{
	getline(filein, sv.mssv, ',');
	getline(filein, sv.ho, ',');
	getline(filein, sv.ten, ',');
	getline(filein, sv.ns, ',');
	getline(filein, sv.gt, ',');
	getline(filein, sv.lop, ',');
	getline(filein, sv.toan, ':');
	filein >> sv.diemToan;
	getline(filein, sv.ly, ':');
	filein >> sv.diemLy;
	getline(filein, sv.tin, ':');
	filein >> sv.diemTin;
}

// ham doc thong tin cau sinh vien
void Doc_File(ifstream &filein, vector< SinhVien> &ds_sinhvien)
{
	while (filein.eof() == false)
	{
		string temp;
		SinhVien sv;
		DocDuLieuSV(filein, sv);
		getline(filein, temp);
		ds_sinhvien.push_back(sv);
	}
}

// ham tinh diem trung binh va hoc bong cua 1 sinh vien
float DTB(SinhVien sv) {
	float avg;
	avg = (sv.diemToan + sv.diemLy + sv.diemTin) / 3;
	return avg;
}
int HB(SinhVien sv){
	int hb;
	DTB(sv);
	if (DTB(sv) >= 8)
	{
		hb = 200;
	}
	else if (DTB(sv) >= 7 && DTB(sv) < 8)
	{
		hb = 100;
	}
	else
	{
		hb = 0;
	}
	return hb;
}

// ham xuat thong tin cua sinh vien
void XuatSV(SinhVien sv)
{
	cout << left << setw(10) << sv.mssv << "|" << setw(7) << sv.ho << "|" << setw(7) << sv.ten << "|" << setw(12) << sv.ns << "|" << setw(6) << sv.gt << "|" << setw(5) << sv.lop << "|";
	cout << setw(5) << sv.diemToan << "|" << setw(5) << sv.diemLy << "|" << setw(5) << sv.diemTin << "|";
	cout << setw(10) << DTB(sv) << "|";
	if (DTB(sv) >= 8)
	{
		cout << setw(8) << HB(sv) << "||";
	}
	if (DTB(sv) >= 7 && DTB(sv)<8)
	{
		cout << setw(8) << HB(sv) << "||";
	}
	if (DTB(sv)<7)
	{
		cout << setw(8) << HB(sv) << "||";
	}
	cout << "\n";
	cout << "||----|----------|-------|-------|------------|------|-----|-----|-----|-----|----------|--------||" << endl;
}

// ham show ket qua
void Show(vector<SinhVien> ds)
{
	cout << "DANH SACH TAT CA CAC SINH VIEN" << endl;
	cout << "__________________________________________________________________________________________________" << endl;
	cout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "MSSV" << "|" << setw(7) << "Ho" << "|" << setw(7) << "Ten" << "|" << setw(12) << "NgSinh" << "|" << setw(6) << "GTinh" << "|" << setw(5) << "Lop" << "|"
		<< setw(5) << "Toan" << "|" << setw(5) << "Ly" << "|" << setw(5) << "Tin" << "|"
		<< setw(10) << "DiemTB" << "|" << setw(8) << "HocBong" << "||" << "\n";
	cout << "||====|==========|=======|=======|============|======|=====|=====|=====|=====|==========|========||" << endl;
	for (int i = 0; i < ds.size(); i++) {
		cout << "||" << setw(4) << i + 1 << "|";
		XuatSV(ds[i]);
	}
}

// ham tim kien sinh vien theo mssv
void TimKiemMSSV(vector <SinhVien> ds, string mssv){
	cout << "Nhap mssv can tim kiem: ";
	cin >> mssv;
	//show ra man hinh
	cout << "Sinh Vien co MSSV "<<mssv<<" :" << endl;
	cout << "__________________________________________________________________________________________________" << endl;
	cout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "MSSV" << "|" << setw(7) << "Ho" << "|" << setw(7) << "Ten" << "|" << setw(12) << "NgSinh" << "|" << setw(6) << "GTinh" << "|" << setw(5) << "Lop" << "|"
		<< setw(5) << "Toan" << "|" << setw(5) << "Ly" << "|" << setw(5) << "Tin" << "|"
		<< setw(10) << "DiemTB" << "|" << setw(8) << "HocBong" << "||" << "\n";
	cout << "||====|==========|=======|=======|============|======|=====|=====|=====|=====|==========|========||" << endl;
	bool kq = false;
	for (int i = 0; i < ds.size(); i++){
		if (stricmp(ds[i].mssv.c_str(), mssv.c_str()) == 0){
			cout << "||" << setw(4) << i + 1 << "|";
			XuatSV(ds[i]);
			kq = true;
		}
	}
	if (kq == false){
		cout << "mssv ban vua nhap khong co!";
	}
}

// ham tim kiem sinh vien theo ho ten
void TimKiemTen(vector <SinhVien> ds, string ho, string ten){
	cout << "Nhap ho ten sinh vien can tim kiem: ";
	cin >> ho;
	//cout << "Nhap ten sinh vien can tim kiem: ";
	cin >> ten;
	//show ra man hinh
	cout << "Sinh vien co ho ten "<<ho<<" "<<ten<<" :" << endl;
	cout << "__________________________________________________________________________________________________" << endl;
	cout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "MSSV" << "|" << setw(7) << "Ho" << "|" << setw(7) << "Ten" << "|" << setw(12) << "NgSinh" << "|" << setw(6) << "GTinh" << "|" << setw(5) << "Lop" << "|"
		<< setw(5) << "Toan" << "|" << setw(5) << "Ly" << "|" << setw(5) << "Tin" << "|"
		<< setw(10) << "DiemTB" << "|" << setw(8) << "HocBong" << "||" << "\n";
	cout << "||====|==========|=======|=======|============|======|=====|=====|=====|=====|==========|========||" << endl;
	bool kq = false;
	for (int i = 0; i < ds.size(); i++){
		if (stricmp(ds[i].ho.c_str(), ho.c_str()) == 0){
			if (stricmp(ds[i].ten.c_str(), ten.c_str()) == 0){
				//show ra man hinh
				cout << "||" << setw(4) << i + 1 << "|";
				XuatSV(ds[i]);
				kq = true;
			}
		}
	}
	if (kq == false){
		cout << "ten sinh vien ban vua nhap khong co!";
	}
}
// ham ghi thong tin sinh vien vao file
void GhiIFSV(ofstream &fileout, SinhVien sv)
{
	fileout << left << setw(10) << sv.mssv << "|" << setw(7) << sv.ho << "|" << setw(7) << sv.ten << "|" << setw(12) << sv.ns << "|" << setw(6) << sv.gt << "|" << setw(5) << sv.lop << "|";
	fileout << setw(5) << sv.diemToan << "|" << setw(5) << sv.diemLy << "|" << setw(5) << sv.diemTin << "|";
	fileout << setw(10) << DTB(sv) << "|";
	if (DTB(sv) >= 8)
	{
		fileout << setw(8) << HB(sv) << "||";
	}
	if (DTB(sv) >= 7 && DTB(sv)<8)
	{
		fileout << setw(8) << HB(sv) << "||";
	}
	if (DTB(sv)<7)
	{
		fileout << setw(8) << HB(sv) << "||";
	}
	fileout << "\n";
	fileout << "||----|----------|-------|-------|------------|------|-----|-----|-----|-----|----------|--------||" << endl;
}

// ham save danh sach sinh vien ra file 'QLSV.txt'
void SaveDSSV(ofstream &fileout, vector<SinhVien> ds) {

	fileout << "DANH SACH TAT CA CAC SINH VIEN" << endl;
	fileout << "__________________________________________________________________________________________________" << endl;
	fileout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "MSSV" << "|" << setw(7) << "Ho" << "|" << setw(7) << "Ten" << "|" << setw(12) << "NgSinh" << "|" << setw(6) << "GTinh" << "|" << setw(5) << "Lop" << "|"
		<< setw(5) << "Toan" << "|" << setw(5) << "Ly" << "|" << setw(5) << "Tin" << "|"
		<< setw(10) << "DiemTB" << "|" << setw(8) << "HocBong" << "||" << "\n";
	fileout << "||====|==========|=======|=======|============|======|=====|=====|=====|=====|==========|========||" << endl;
	for (int i = 0; i < ds.size(); i++) {
		fileout << "||" << setw(4) << i + 1 << "|";
		GhiIFSV(fileout, ds[i]);
	}
}
//ham hoan vi
void HoanVi(SinhVien &sv1, SinhVien &sv2) {
	SinhVien temp;
	temp.mssv = sv1.mssv;
	temp.ho = sv1.ho;
	temp.ten = sv1.ten;
	temp.ns = sv1.ns;
	temp.gt = sv1.gt;
	temp.lop = sv1.lop;
	temp.diemToan = sv1.diemToan;
	temp.diemLy = sv1.diemLy;
	temp.diemTin = sv1.diemTin;


	sv1.mssv = sv2.mssv;
	sv1.ho = sv2.ho;
	sv1.ten = sv2.ten;
	sv1.ns = sv2.ns;
	sv1.gt = sv2.gt;
	sv1.lop = sv2.lop;
	sv1.diemToan = sv2.diemToan;
	sv1.diemLy = sv2.diemLy;
	sv1.diemTin = sv2.diemTin;

	sv2.mssv = temp.mssv;
	sv2.ho = temp.ho;
	sv2.ten = temp.ten;
	sv2.ns = temp.ns;
	sv2.gt = temp.gt;
	sv2.lop = temp.lop;
	sv2.diemToan = temp.diemToan;
	sv2.diemLy = temp.diemLy;
	sv2.diemTin = temp.diemTin;
}

//sap xep
void SapXep(vector< SinhVien> &ds) {
	for (int i = 0; i < ds.size(); i++) {
		for (int j = i + 1; j < ds.size(); j++){
			if (DTB(ds[i]) < DTB(ds[j])) {
				HoanVi(ds[i], ds[j]);
			}
		}
	}
	Show(ds);
	ofstream fileout;
	fileout.open("SapXepSV.txt", ios_base::out);
	SaveDSSV(fileout, ds);
	cout << "\nDanh sach sinh vien da duoc sap xep va luu o file 'SapXepSV.txt'" << endl;
	fileout.close();
}
// ham tach nam sinh tu chuoi string ngay sinh
string TachNS(string str)
{
	string temp;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			temp.insert(temp.begin() + 0, str[i]);
		}
		else
		{
			break;
		}
	}
	return temp;
}

// ham luu thong tin sinh vien theo nam sinh vao file NSSinhVien.TXT
void SaveDSSVNS(ofstream &fileout, vector<SinhVien> ds, string ns)
{
	bool kq = false;
	//ghi vao file
	fileout << "DANH SACH CAC SINH VIEN SINH NAM " << ns << endl;
	fileout << "__________________________________________________________________________________________________" << endl;
	fileout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "MSSV" << "|" << setw(7) << "Ho" << "|" << setw(7) << "Ten" << "|" << setw(12) << "NgSinh" << "|" << setw(6) << "GTinh" << "|" << setw(5) << "Lop" << "|"
		<< setw(5) << "Toan" << "|" << setw(5) << "Ly" << "|" << setw(5) << "Tin" << "|"
		<< setw(10) << "DiemTB" << "|" << setw(8) << "HocBong" << "||" << "\n";
	fileout << "||====|==========|=======|=======|============|======|=====|=====|=====|=====|==========|========||" << endl;
	//show ra man hinh
	cout << "DANH SACH CAC SINH VIEN SINH NAM " << ns << endl;
	cout << "__________________________________________________________________________________________________" << endl;
	cout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "MSSV" << "|" << setw(7) << "Ho" << "|" << setw(7) << "Ten" << "|" << setw(12) << "NgSinh" << "|" << setw(6) << "GTinh" << "|" << setw(5) << "Lop" << "|"
		<< setw(5) << "Toan" << "|" << setw(5) << "Ly" << "|" << setw(5) << "Tin" << "|"
		<< setw(10) << "DiemTB" << "|" << setw(8) << "HocBong" << "||" << "\n";
	cout << "||====|==========|=======|=======|============|======|=====|=====|=====|=====|==========|========||" << endl;
	for (int i = 0; i < ds.size(); i++)
	{
		string temp = TachNS(ds[i].ns); // tach nam sinh tu chuoi ngay sinh cua sinh vien thu i
		if (stricmp(temp.c_str(), ns.c_str()) == 0)
		{
			//ghi vao file
			fileout << "||" << setw(4) << i + 1 << "|";
			GhiIFSV(fileout, ds[i]);
			//show ra man hinh
			cout << "||" << setw(4) << i + 1 << "|";
			XuatSV(ds[i]);
			kq = true;
		}
	}
	if (kq == false){
		cout << "mssv ban vua nhap khong co!" << endl;
	}
}

// ham xoa sinh vien theo mssv
void XoaSV(vector <SinhVien> ds, string mssv){
	cout << "\nNhap mssv cua sinh vien can xoa: ";
	cin >> mssv;
	bool kq = false;
	for (int i = 0; i < ds.size(); i++){
		if (stricmp(ds[i].mssv.c_str(), mssv.c_str()) == 0){
			ds.erase(ds.begin() + i);
			Show(ds);
			cout << "\nSinh vien co mssv " << mssv << " da duoc xoa!" << endl;
			ofstream fileout;
			fileout.open("QLSV.txt", ios_base::out);
			SaveDSSV(fileout, ds);
			cout << "\nDanh sach sinh vien da duoc luu o file 'QLSV.txt'";
			fileout.close();
			kq = true;
		}
	}
	if (kq == false){
		cout << "mssv ban vua nhap khong co!" << endl;
	}
}
// ham tach khoa tu chuoi string lop
string TachKhoa(string str)
{
	string temp;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			temp.insert(temp.begin() + 0, str[i]);
		}
		else
		{
			break;
		}
	}
	return temp;
}
// ham Xoa cac sinh vien nu khoa 08
void XoaSVNu08(vector<SinhVien> ds, string khoa){
	for (int i = 0; i < ds.size(); i++)
	{
		string temp = TachKhoa(ds[i].lop);
		if (stricmp(temp.c_str(), khoa.c_str()) == 0 && ds[i].gt == "Nu")
		{
			ds.erase(ds.begin() + i);
		}
	}
	Show(ds);
	cout << "\nSinh vien nu 08 da duoc xoa!" << endl;
	ofstream fileout;
	fileout.open("QLSV.txt", ios_base::out);
	SaveDSSV(fileout, ds);
	cout << "\nDanh sach sinh vien da duoc luu o file 'QLSV.txt'";
	fileout.close();
}
// ham lay hoc bong cua 1 sinh vien
int LayHB(SinhVien sv){
	float dtb = 0;
	int hb = 0;
	dtb = (sv.diemToan + sv.diemLy + sv.diemTin) / 3;
	if (dtb >= 8)
	{
		hb = 200;
	}
	else if (dtb >= 7 && dtb < 8)
	{
		hb = 100;
	}
	else
	{
		hb = 0;
	}
	return hb;
}
//ham in ra bang thong ke theo lop
void ThongKe(ofstream &fileout, vector<SinhVien> ds, string lop){
	int s = 0;
	int thb = 0;
	bool kq = false;
	//show ra man hinh
	cout << "BANG THONG KE LOP " << lop << endl;
	cout << "_________________________" << endl;
	cout << left << "||" << setw(6) << "Lop" << "|" << setw(6) << "So SV" << "|" << setw(7) << "Tong HB" << "||" << endl;
	cout << "||======|======|=======||" << endl;
	//in vao file
	fileout << "BANG THONG KE LOP " << lop << endl;
	fileout << "_________________________" << endl;
	fileout << left << "||" << setw(6) << "Lop" << "|" << setw(6) << "So SV" << "|" << setw(7) << "Tong HB" << "||" << endl;
	fileout << "||======|======|=======||" << endl;
	for (int i = 0; i < ds.size(); i++){
		if (stricmp(ds[i].lop.c_str(), lop.c_str()) == 0){
			s = s + 1;
			thb += LayHB(ds[i]);
			kq = true;
		}
	}
	if (kq == false){
		cout << "Lop ban nhap khong co trong danh sach!" << endl;
	}
	//show ra man hinh
	cout << left << "||" << setw(6) << lop << "|" << setw(6) << s << "|" << setw(7) << thb << "||" << endl;
	cout << "||---------------------||";
	//in vao file
	fileout << left << "||" << setw(6) << lop << "|" << setw(6) << s << "|" << setw(7) << thb << "||" << endl;
	fileout << "||---------------------||";
}

//ham de hien thi menu tuy chon
void displaymenu(){
	cout << "================================================" << "\n";
	cout << " MENU  ||         Quan Ly Sinh Vien           ||" << "\n";
	cout << "================================================" << "\n";
	cout << "* 1. In thong tin cua tat ca cac sinh vien     |" << "\n";
	cout << "* 2. Luu danh sach cac sinh vien theo nam      |" << "\n";
	cout << "* 3. Tim kiem sinh vien theo mssv              |" << "\n";
	cout << "* 4. Tim kiem sinh vien theo ten               |" << "\n";
	cout << "* 5. Sap xep sinh vien theo diem trung binh    |" << "\n";
	cout << "* 6. Xoa thong tin cua 1 sinh vien             |" << "\n";
	cout << "* 7. Chen thong tin cua 1 SV theo thu tu DTB   |" << "\n";
	cout << "* 8. In ra bang thong ke theo lop              |" << "\n";
	cout << "* 9. Xoa cac sinh vien nu khoa 08              |" << "\n";
	cout << "================================================" << "\n";
}

// ham main
int main()
{
	ifstream filein;
	filein.open("SinhVien.txt", ios_base::in);
	// khai bao danh sach sinh vien
	vector< SinhVien> ds_sinhvien;
	// doc tat ca du lieu tu file SinhVien.txt
	Doc_File(filein, ds_sinhvien);
	cout << "Du lieu da doc thanh cong !" << endl;
	// show ket qua ra man hinh
	char luachon;
	char confirm;
	do
	{
		displaymenu();
		cout << "\nNhap lua chon cua ban (0-9): ";
		cin >> luachon;
		switch (luachon){
		case '1':{
			Show(ds_sinhvien);
			ofstream fileout;
			fileout.open("QLSV.txt", ios_base::out);
			SaveDSSV(fileout, ds_sinhvien);
			cout << "\nDanh sach sinh vien da duoc luu o file 'QLSV.txt'" << endl;
			fileout.close();
		} break;
		case '2':{
			ofstream fileout;
			fileout.open("NSSinhVien.txt", ios_base::out);
			string ns;
			cout << "\nNhap nam sinh: ";
			cin >> ns;
			SaveDSSVNS(fileout, ds_sinhvien, ns);
			cout << "\n";
			cout << "Danh sach sinh vien sinh nam " << ns << " da duoc luu o file 'FindNS.txt'" << endl;
			fileout.close();
		}; break;
		case '3':{
			string mssv;
			TimKiemMSSV(ds_sinhvien, mssv);
			cout << "\n";
		} break;
		case '4':{
			string ho, ten;
			TimKiemTen(ds_sinhvien, ho, ten);
			cout << "\n";
		} break;
		case '5': SapXep(ds_sinhvien); break;
		case '6':{
			string mssv;
			XoaSV(ds_sinhvien, mssv);
			cout << "\n";
		} break;
		case '7':; break;
		case '8':{
			ofstream fileout;
			fileout.open("ThongKe.txt", ios_base::out);
			string lop;
			cout << "\nNhap lop can thong ke: ";
			cin >> lop;
			ThongKe(fileout, ds_sinhvien, lop);
			cout << "\n";
			cout << "Bang thong ke lop " << lop << " da duoc luu o file 'ThongKe.txt' !" << endl;
			fileout.close();
		}; break;
		case '9':{
			string khoa = "80";
			XoaSVNu08(ds_sinhvien, khoa);
		} break;
		default:cout << "lua chon khong hop le!";
		}
		cout << "\nNhan phim bat ki de tiep tuc: ";
		cin >> confirm;
	} while (confirm);
	filein.close();
	return 0;
}
