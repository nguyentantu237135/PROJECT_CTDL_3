#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>	//su dung cho setw
#pragma once
using namespace std;

template<class DataType>
class BanDoc {		//bạn đọc
	DataType id, hoten, sodienthoai, diachi, ngaythamgia;
public:

	BanDoc(DataType _id = "", DataType _hoten = "", DataType _sodienthoai = "", DataType _diachi = "", DataType _ngaythamgia = "");
	BanDoc(const BanDoc& f);
	~BanDoc();	

	void themBanDoc(BanDoc& bd, int id);		//thêm bạn đọc
	void xuat_ds_bd();
	void xuat_bd();
	void capNhatBanDoc(BanDoc arr[1000], int n);
	void layThongTinDanhSachBanDoc(BanDoc arr[1000], int& sl);
	bool timBanDoc(BanDoc arr[1000], int n, DataType id);
};

