#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>	//su dung cho setw
//#include <ctime>
//#include <chrono> 
//#include<conio.h>
using namespace std;

template<class DataType>
class PhieuMuon {
	DataType soPhieuMuon, maBanDoc, maSach, ngayMuon, ngayTra, tinhTrang;
	DataType stt;
public:

	PhieuMuon(DataType _soPhieuMuon = "", DataType _maBanDoc = "", DataType _maSach = "", DataType _ngayMuon = "", DataType _ngayTra = "", DataType _tinhTrang = "");
	PhieuMuon(const PhieuMuon& p);
	~PhieuMuon();

	void muonSach(PhieuMuon arr[1000], int& sl, DataType mabd, DataType masach);
	string traSach(PhieuMuon arr[1000], int sl, DataType sp);
	void capNhatPhieuMuon(PhieuMuon arr[1000], int n);
	void tieuDePhieuMuon();
	void xuat();
	void layThongTinDanhSachPhieuMuon(PhieuMuon arr[1000], int& sl);
};