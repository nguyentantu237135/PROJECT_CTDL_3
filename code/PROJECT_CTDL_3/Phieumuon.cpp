#include "Phieumuon.h"

template<class DataType>
PhieuMuon<DataType>::PhieuMuon(DataType _soPhieuMuon, DataType _maBanDoc, DataType _maSach, DataType _ngayMuon, DataType _ngayTra, DataType _tinhTrang)
{
    soPhieuMuon = _soPhieuMuon;
    maBanDoc = _maBanDoc;
    maSach = _maSach;
    ngayMuon = _ngayMuon;
    ngayTra = _ngayTra;
    tinhTrang = _tinhTrang;
}

template<class DataType>
PhieuMuon<DataType>::PhieuMuon(const PhieuMuon<DataType>& p)
{
    soPhieuMuon = p.soPhieuMuon;
    maBanDoc = p.maBanDoc;
    maSach = p.maSach;
    ngayMuon = p.ngayMuon;
    ngayTra = p.ngayTra;
    tinhTrang = p.tinhTrang;
}

template<class DataType>
PhieuMuon<DataType>::~PhieuMuon() {}

template<class DataType>
void PhieuMuon<DataType>::muonSach(PhieuMuon<DataType> arr[1000], int& sl, DataType mabd, DataType masach)
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string nam = to_string(1900 + ltm->tm_year);
    string thang = to_string(1 + ltm->tm_mon);
    string ngay = to_string(ltm->tm_mday);
    string ngaytra = to_string(ltm->tm_mday + 7);

    arr[sl].soPhieuMuon = to_string(sl + 1);
    arr[sl].maBanDoc = mabd;
    arr[sl].maSach = masach;
    arr[sl].ngayMuon = ngay + "/" + thang + "/" + nam;
    arr[sl].ngayTra = ngaytra + "/" + thang + "/" + nam;
    arr[sl].tinhTrang = "1-";
    sl++;
}

template<class DataType>
string PhieuMuon<DataType>::traSach(PhieuMuon arr[1000], int sl, DataType sp)
{
    for (int index = 0; index < sl; index++) {
        if (arr[index].soPhieuMuon == sp) {
            if (arr[index].tinhTrang == "1-") {
                arr[index].tinhTrang = "0";
                //tra sach thanh cong
                return arr[index].maSach;
            }
            else {
                //phieu muon da dc tra
                return "1";
            }
        }
    }
    //ko tim thay phieu muon
    return "0";
}

template<class DataType>
void PhieuMuon<DataType>::capNhatPhieuMuon(PhieuMuon<DataType> arr[1000], int n)
{
    ofstream file_s("../PhieuMuon.txt");
    for (int i = 0; i < n; i++) {
        file_s << arr[i].soPhieuMuon << "," << arr[i].maBanDoc << "," << arr[i].maSach << "," << arr[i].ngayMuon << "," << arr[i].ngayTra << "," << arr[i].tinhTrang << endl;
    }
    file_s.close();
}

template<class DataType>
void PhieuMuon<DataType>::tieuDePhieuMuon()
{
    int w = 25;
    cout << setw(77) << "Danh sach phieu muon" << endl << endl;
    cout << "********************************************************************************************************************************************************************" << endl;
    cout << setw(w) << "So phieu" << setw(w) << "Ma ban doc" << setw(w) << "Ma sach" << setw(w) << "Ngay muon" << setw(w) << "Ngay tra" << setw(w) << "Tinh trang" << endl;
}

template<class DataType>
void PhieuMuon<DataType>::xuat()
{
    int w = 25;
    if (this->soPhieuMuon != "null") {
        cout << setw(w) << soPhieuMuon;
        cout << setw(w) << maBanDoc;
        cout << setw(w) << maSach;
        cout << setw(w) << ngayMuon;
        cout << setw(w) << ngayTra;
        cout << setw(w) << tinhTrang;

        cout << endl;
    }
}

template<class DataType>
void PhieuMuon<DataType>::layThongTinDanhSachPhieuMuon(PhieuMuon<DataType> arr[1000], int& sl)
{
    fstream f;
    int i = 0;
    sl = 0;
    f.open("../PhieuMuon.txt", ios::in);
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
                        arr[sl].soPhieuMuon.push_back(sach_item[index]);
                    }
                    else if (item == 1) {
                        arr[sl].maBanDoc.push_back(sach_item[index]);
                    }
                    else if (item == 2) {
                        arr[sl].maSach.push_back(sach_item[index]);
                    }
                    else if (item == 3) {
                        arr[sl].ngayMuon.push_back(sach_item[index]);
                    }
                    else if (item == 4) {
                        arr[sl].ngayTra.push_back(sach_item[index]);
                    }
                    else if (item == 5) {
                        arr[sl].tinhTrang.push_back(sach_item[index]);
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

template class PhieuMuon<string>;