#include"Sach.h" // gọi thư viện sach.h đã khai báo ở Header Files

//dinh nghia
template<class DataType>
Sach<DataType>::Sach(DataType _masach, DataType _tensach, DataType _tacgia, DataType _nhaxuatban, DataType _giaban, DataType _namphathanh, DataType _sotrang, DataType _ngaynhapkho, DataType _tinhtrangsach)
{
	masach = _masach;
	tensach = _tensach;
	tacgia = _tacgia;
	nhaxuatban = _nhaxuatban;
	giaban = _giaban;
	namphathanh = _namphathanh;
	sotrang = _sotrang;
	ngaynhapkho = _ngaynhapkho;
	tinhtrangsach = _tinhtrangsach;
}

template<class DataType>
Sach<DataType>::Sach(const Sach<DataType>& s)
{
	masach = s.masach;
	tensach = s.tensach;
	tacgia = s.tacgia;
	nhaxuatban = s.nhaxuatban;
	giaban = s.giaban;
	namphathanh = s.namphathanh;
	sotrang = s.sotrang;
	ngaynhapkho = s.ngaynhapkho;
	tinhtrangsach = s.tinhtrangsach;
}

template<class DataType>
Sach<DataType>::~Sach() {}


template<class DataType>
void Sach<DataType>::themSach(Sach<DataType>& s)
{
	cout << "Ma sach : " << endl;
	getline(cin, s.masach);
	getline(cin, s.masach);
	cout << "Ten sach : " << endl;
	getline(cin, s.tensach);
	cout << "Tac gia : " << endl;
	getline(cin, s.tacgia);
	cout << "Gia sach : " << endl;
	getline(cin, s.giaban);
	cout << "Nha xuat ban : " << endl;
	getline(cin, s.nhaxuatban);
	s.tinhtrangsach = "0";
	cout << "Nam phat hanh : " << endl;
	getline(cin, s.namphathanh);
	cout << "So trang : " << endl;
	getline(cin, s.sotrang);
	cout << "Ngay nhap kho : " << endl;
	getline(cin, s.ngaynhapkho);
}

template<class DataType>
void Sach<DataType>::cap_nhat_sach(Sach<DataType> arr[1000], int& n, bool f)
{
	bool flag = true;
	ofstream file_s("../Sach.txt");
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].masach != "null")
			file_s << arr[i].masach << "," << arr[i].tensach << "," << arr[i].tacgia << "," << arr[i].giaban << "," << arr[i].nhaxuatban << "," << arr[i].tinhtrangsach << "," << arr[i].namphathanh << "," << arr[i].sotrang << "," << arr[i].ngaynhapkho << endl;

		if (arr[i].masach == arr[n - 1].masach)
			flag = false;
	}
	if (f == true) {
		if (flag) {
			file_s << arr[n - 1].masach << "," << arr[n - 1].tensach << "," << arr[n - 1].tacgia << "," << arr[n - 1].giaban << "," << arr[n - 1].nhaxuatban << "," << arr[n - 1].tinhtrangsach << "," << arr[n - 1].namphathanh << "," << arr[n - 1].sotrang << "," << arr[n - 1].ngaynhapkho << endl;
			cout << setw(20) << "Them sach thanh cong.";
		}
		else {
			n--;
			cout << setw(20) << "Ma sach bi trung, khong the them sach vao" << endl;
		}
	}
	else {
		if (flag) {
			file_s << arr[n - 1].masach << "," << arr[n - 1].tensach << "," << arr[n - 1].tacgia << "," << arr[n - 1].giaban << "," << arr[n - 1].nhaxuatban << "," << arr[n - 1].tinhtrangsach << "," << arr[n - 1].namphathanh << "," << arr[n - 1].sotrang << "," << arr[n - 1].ngaynhapkho << endl;
		}
		else {
			n--;
		}
	}

	file_s.close();
}

template<class DataType>
void Sach<DataType>::xoaSach(Sach<DataType> arr[1000], int& n)
{
	string id_xoa;
	bool flag = false;

	cout << setw(20) << "Nhap id sach ban muon xoa: ";
	cin >> id_xoa;

	for (int index = 0; index < n; index++) {
		if (arr[index].masach == id_xoa && arr[index].tinhtrangsach == "0") {
			arr[index].masach = "null";
			flag = true;
		}
	}
	if (!flag) {
		cout << setw(20) << "Ma sach khong ton tai hoac sach dang duoc muon.";
	}
	else {
		cout << setw(20) << "Xoa sach thanh cong";
	}
}

template<class DataType>
int Sach<DataType>::timSach(Sach<DataType> arr[1000], int sl, DataType id)
{
	for (int index = 0; index < sl; index++) {
		if (arr[index].masach == id) {
			if (arr[index].tinhtrangsach == "0")
				//sach muon đuoc
				return 2;
			else
				//sach khong muon dc
				return 1;
		}
	}
	//khong tim thay ma sach
	return 0;
}

template<class DataType>
void Sach<DataType>::xuatTieuDe()
{
	int w = 17;
	cout << setw(90) << "Danh sach sach trong thu vien" << endl << endl;
	cout << "************************************************************************************************************************************************************************" << endl;
	cout << setw(w) << "Ma sach" << setw(w) << "Ten sach" << setw(w) << "Tac gia" << setw(w) << "Gia sach" << setw(w) << "NXB" << setw(w) << "Tinh trang" << setw(20) << "Nam phat hanh" << setw(20) << "So trang" << setw(20) << "Ngay nhap kho" << setw(w) << endl;
}

template<class DataType>
void Sach<DataType>::xuat()
{
	int w = 16;
	if (masach != "null") {
		cout << setw(w) << masach;
		cout << setw(20) << tensach;
		cout << setw(w) << tacgia;
		cout << setw(w) << giaban;
		cout << setw(w) << nhaxuatban;
		cout << setw(w) << tinhtrangsach;
		cout << setw(20) << namphathanh;
		cout << setw(20) << sotrang;
		cout << setw(20) << ngaynhapkho;
		cout << endl;
	}
}

template<class DataType>
void Sach<DataType>::layThongTinDSSach(Sach<DataType> arr[1000], int& sl)
{
	fstream f;
	int i = 0;
	sl = 0;
	f.open("../Sach.txt", ios::in);
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
						arr[sl].masach.push_back(sach_item[index]);
					}
					else if (item == 1) {
						arr[sl].tensach.push_back(sach_item[index]);
					}
					else if (item == 2) {
						arr[sl].tacgia.push_back(sach_item[index]);
					}
					else if (item == 3) {
						arr[sl].giaban.push_back(sach_item[index]);
					}
					else if (item == 4) {
						arr[sl].nhaxuatban.push_back(sach_item[index]);
					}
					else if (item == 5) {
						arr[sl].tinhtrangsach.push_back(sach_item[index]);
					}
					else if (item == 6) {
						arr[sl].namphathanh.push_back(sach_item[index]);
					}
					else if (item == 7) {
						arr[sl].sotrang.push_back(sach_item[index]);
					}
					else if (item == 8) {
						arr[sl].ngaynhapkho.push_back(sach_item[index]);
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
void Sach<DataType>::tinhTrangSach(Sach<DataType> arr[1000], int sl, DataType id, DataType cd)
{
	for (int index = 0; index < sl; index++) {
		if (arr[index].masach == id) {
			//doi tinh trang sach
			arr[index].tinhtrangsach = cd;
		}
	}
}

template class Sach<string>;