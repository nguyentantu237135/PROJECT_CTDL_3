#include"Bandoc.h"

template<class DataType>
BanDoc<DataType>::BanDoc(DataType _id, DataType _hoten, DataType _sodienthoai, DataType _diachi, DataType _ngaythamgia)
{
	id = _id;
	hoten = _hoten;
	sodienthoai = _sodienthoai;
	diachi = _diachi;
	ngaythamgia = _ngaythamgia;
}

template<class DataType>
BanDoc<DataType>::BanDoc(const BanDoc<DataType>& f)
{
	id = f.id;
	hoten = f.hoten;
	sodienthoai = f.sodienthoai;
	diachi = f.diachi;
	ngaythamgia = f.ngaythamgia;
}

template<class DataType>
BanDoc<DataType>::~BanDoc() {}

template<class DataType>
void BanDoc<DataType>::themBanDoc(BanDoc<DataType>& bd, int id)
{
	string _id = to_string(id);
	bd.id = _id;
	cout << "Ho va ten: " << endl;
	getline(cin, bd.hoten);
	getline(cin, bd.hoten);
	cout << "SDT: " << endl;
	getline(cin, bd.sodienthoai);
	cout << "Dia chi : " << endl;
	getline(cin, bd.diachi);
	cout << "Ngay tham gia : " << endl;
	getline(cin, bd.ngaythamgia);
	cout << "Them sach thanh cong";
}

template<class DataType>
void BanDoc<DataType>::xuat_ds_bd()
{
	int w = 25;
	cout << setw(90) << "Danh sach ban doc" << endl << endl;
	cout << "*******************************************************************************************************************************************************" << endl;
	cout << setw(w) << "Ma ban doc" << setw(w) << "Ho va ten" << setw(w) << "So dien thoai" << setw(w) << "Dia chi" << setw(w) << "Ngay tham gia" << endl;
}

template<class DataType>
void BanDoc<DataType>::xuat_bd()
{
	int w = 25;
	if (id != "null")
	{
		cout << setw(w) << id;
		cout << setw(w) << hoten;
		cout << setw(w) << sodienthoai;
		cout << setw(w) << diachi;
		cout << setw(w) << ngaythamgia;
		cout << endl;
	}
}

template<class DataType>
void BanDoc<DataType>::capNhatBanDoc(BanDoc<DataType> arr[1000], int n)
{
	ofstream file_s("../Bandoc.txt");
	for (int i = 0; i < n; i++) {
		if (arr[i].id != "null")
			file_s << arr[i].id << "," << arr[i].hoten << "," << arr[i].sodienthoai << "," << arr[i].diachi << "," << arr[i].ngaythamgia << endl;
	}
	file_s.close();
}

template<class DataType>
void BanDoc<DataType>::layThongTinDanhSachBanDoc(BanDoc<DataType> arr[1000], int& sl)
{
	fstream f;
	int i = 0;
	sl = 0;
	f.open("../Bandoc.txt", ios::in);
	string line, sach_item;
	int  item = 0;
	while (!f.eof())
	{
		getline(f, line);
		sach_item = line;
		if (sach_item != "") {
			for (int index = 0; index <= sach_item.size() - 1; index++) {
				if (sach_item[index] != ',') {
					if (item == 0) {
						arr[sl].id.push_back(sach_item[index]);
					}
					else if (item == 1) {
						arr[sl].hoten.push_back(sach_item[index]);
					}
					else if (item == 2) {
						arr[sl].sodienthoai.push_back(sach_item[index]);
					}
					else if (item == 3) {
						arr[sl].diachi.push_back(sach_item[index]);
					}
					else if (item == 4) {
						arr[sl].ngaythamgia.push_back(sach_item[index]);
					}
				}
				else
				{
					item++;
				}
			}
			item = 0;
			sl++;
		}
	}
	f.close();
}

template<class DataType>
bool BanDoc<DataType>::timBanDoc(BanDoc<DataType> arr[1000], int n, DataType id)
{
	for (int index = 0; index < n; index++) {
		if (arr[index].id == id) {
			return true;
		}
	}
	return false;
}

template class BanDoc<string>;