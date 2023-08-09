#pragma once
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>	//su dung cho setw
using namespace std;

// khai báo đối tượng sách
template<class DataType>
class Sach {
	DataType masach, tensach, tacgia, nhaxuatban, giaban, namphathanh, sotrang, ngaynhapkho, tinhtrangsach;
public:

	Sach(DataType _masach = "", DataType _tensach = "", DataType _tacgia = "", DataType _nhaxuatban = "", DataType _giaban = "", DataType _namphathanh = "", DataType _sotrang = "", DataType _ngaynhapkho = "", DataType _tinhtrangsach = "");
	Sach(const Sach& s);
	~Sach();

	void themSach(Sach& s);
	void cap_nhat_sach(Sach arr[1000], int& n, bool f);
	void xoaSach(Sach arr[1000], int& n);
	int timSach(Sach arr[1000], int sl, DataType id);

	void xuatTieuDe();
	void xuat();
	void layThongTinDSSach(Sach arr[1000], int& sl);
	void tinhTrangSach(Sach arr[1000], int sl, DataType id, DataType cd);
};