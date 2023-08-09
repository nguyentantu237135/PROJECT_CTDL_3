#pragma once
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>
#include<conio.h>
#include<Windows.h>
using namespace std;

void gotoXY(int column, int line);

string maHoaPassword(size_t length_max);
bool manHinhDangNhap();
void Menu();
void remove_scrollbar();