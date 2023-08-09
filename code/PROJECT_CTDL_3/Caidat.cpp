#include "Caidat.h"
#include "Sach.h"
#include "Phieumuon.h"
#include "Bandoc.h"


void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string maHoaPassword(size_t length_max)
{
    string strRet;
    char ch = 0;
    bool bShow = false;
    do
    {
        ch = _getch();
        if ((strRet.size() < length_max) &&
            (isalpha(ch) || isalnum(ch)))
        {
            cout << (bShow ? ch : '*');
            strRet.push_back(ch);
        }
        else
        {
            if (0x1B == ch)
            {
                bShow = !bShow;
                cout << string(strRet.size(), '\b');

                if (bShow)
                    cout << strRet;
                else
                    cout << string(strRet.size(), '*');

            }
            if ('\b' == ch && !strRet.empty())
            {
                cout << "\b \b";
                strRet.resize(strRet.size() - 1);
            }
        }

    } while ('\r' != ch);
    cout << endl;
    return strRet;
}

bool manHinhDangNhap()
{
    int sl = 0;
tryagain:

    fstream f;
    f.open("../Admin.txt", ios::in);
    string datalogin;
    string line;
    string username, pass, login;
    HANDLE hConsoleColor;
    short x = 67;
    short y = 20;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 14);
    gotoXY(x, y);   cout << setw(30) << "************************************" << endl;
    gotoXY(x, y + 1); cout << setw(30) << "*        DANG NHAP HE THONG        *" << endl;
    gotoXY(x, y + 2); cout << setw(30) << "************************************" << endl;
    gotoXY(x, y + 3); cout << setw(30) << "====================================" << endl;
    gotoXY(x, y + 4); cout << setw(20) << "User : "; cin >> username;
    gotoXY(x, y + 5); cout << setw(20) << "Password : "; pass = maHoaPassword(20);

    login = username + "," + pass;

    while (!f.eof())
    {
        getline(f, line);
        datalogin = line;

        if (datalogin == login) {
            system("cls");
            HANDLE hConsoleColor;
            hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsoleColor, 12);
            gotoXY(63, 1);   cout << setw(20) << "Ban da dang nhap thanh cong, enter de tiep tuc." << endl;
            _getch();
            f.close();
            return true;
        }
    }
    if (sl >= 2) {
        exit(0);
    }
    system("cls");
    sl++;
    gotoXY(58, y + 7); cout << setw(20) << "Sai ten dang nhap hoac mat khau , ban con " << 3 - sl << " lan nhap sai." << endl;
    goto tryagain;
}

void Menu()
{
    int tab, tab_sach, tab_phieu, tab_bd, n_s = 0, n_pm = 0, n_bd = 0;
    Sach<string> list_s[1000], s, s_input;
    PhieuMuon<string> l, pm, list_pm[1000], pm_input;
    BanDoc<string> list_bd[1000], bandoc_input, bd;
    //system("cls");
    s.layThongTinDSSach(list_s, n_s);
    l.layThongTinDanhSachPhieuMuon(list_pm, n_pm);
    bd.layThongTinDanhSachBanDoc(list_bd, n_bd);
menu:
    system("cls");
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 12);
    short x = 67;
    short y = 0;
    gotoXY(x, y); cout << setw(20) << "MENU" << endl;
    gotoXY(x, y + 1); cout << "*************************************" << endl;

    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 14);
    gotoXY(x, y + 2); cout << "1. Quan ly sach" << endl;
    gotoXY(x, y + 3); cout << "2. Quan ly phieu muon" << endl;
    gotoXY(x, y + 4); cout << "3. Quan ly ban doc" << endl;
    gotoXY(x, y + 5); cout << "0. Thoat chuong trinh" << endl;

    gotoXY(x, y + 6); cout << setw(20) << "Chon tac vu: ";
    cin >> tab;

    if (tab == 1)
    {
    lb_sach:
        system("cls");
        HANDLE hConsoleColor;
        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 12);
        short x = 67;
        short y = 0;
        gotoXY(x, y); cout << setw(20) << "SACH" << endl;
        gotoXY(x, y + 1); cout << "*************************************" << endl;

        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 14);
        gotoXY(x, y + 2); cout << "1. Xem danh sach Sach" << endl;
        gotoXY(x, y + 3); cout << "2. Them sach moi" << endl;
        gotoXY(x, y + 4); cout << "3. Xoa sach" << endl;
        gotoXY(x, y + 5); cout << "0. Tro lai menu" << endl;

        gotoXY(x, y + 6); cout << setw(20) << "Chon tac vu: ";
        cin >> tab_sach;
        if (tab_sach == 1) {
            //xem danh sach sach
            s.xuatTieuDe();

            for (int i = 0; i < n_s; i++) {
                list_s[i].xuat();
            }
            _getch();
            goto lb_sach;
        }
        else if (tab_sach == 2) {
            //them sach
            s_input.themSach(s_input);
            list_s[n_s] = s_input;
            n_s++;

            s_input.cap_nhat_sach(list_s, n_s, true);
            _getch();
            goto lb_sach;
        }
        else if (tab_sach == 3) {
            //Xoa sach
            s.xoaSach(list_s, n_s);
            s_input.cap_nhat_sach(list_s, n_s, false);
            _getch();
            goto lb_sach;
        }
        else if (tab_sach == 0) {
            goto menu;
        }
        cout << endl;
        goto lb_sach;
    }
    else if (tab == 2)
    {
    lb_pm:
        system("cls");
        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 12);
        short x = 67;
        short y = 0;
        gotoXY(x, y); cout << setw(20) << "MUON TRA SACH" << endl;
        gotoXY(x, y + 1); cout << "*************************************" << endl;
        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 14);
        gotoXY(x, y + 2); cout << "1. Xem danh sach phieu muon" << endl;
        gotoXY(x, y + 3); cout << "2. Muon sach" << endl;
        gotoXY(x, y + 4); cout << "3. Tra sach" << endl;
        gotoXY(x, y + 5); cout << "0. Tro lai menu" << endl;
        gotoXY(x, y + 6); cout << setw(20) << "Chon tac vu: ";
        cin >> tab_phieu;
        if (tab_phieu == 1) {
            //xem danh sach sach
            l.tieuDePhieuMuon();

            for (int i = 0; i < n_pm; i++) {
                list_pm[i].xuat();
            }

            cout << endl;
            _getch();
            goto lb_pm;

        }
        else if (tab_phieu == 2) {
            //Muon sach
            string id_bd, id_sach;
            int err;
            hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsoleColor, 12);
            cout << endl << setw(20) << "Nhap ma ban doc : ";
            cin >> id_bd;
            cout << endl << setw(20) << "Nhap ma sach muon :";
            cin >> id_sach;
            err = s.timSach(list_s, n_s, id_sach);
            if (err == 0) {
                cout << endl << setw(20) << "Khong tim thay sach muon muon.";
                system("pause");
            }
            else if (err == 1) {
                cout << endl << setw(20) << "Sach da duoc muon.";
                system("pause");
            }
            else {
                bool flag;
                flag = bd.timBanDoc(list_bd, n_bd, id_bd);
                if (flag) {
                    l.muonSach(list_pm, n_pm, id_bd, id_sach);
                    l.capNhatPhieuMuon(list_pm, n_pm);
                    s.tinhTrangSach(list_s, n_s, id_sach, "1");
                    s.cap_nhat_sach(list_s, n_s, true);
                    cout << endl << setw(20) << "Muon sach thanh cong.";
                    system("pause");
                }
                else {
                    cout << endl << setw(20) << "Khong tim thay ma ban doc.";
                    system("pause");
                }
            }
            cout << endl;
            goto lb_pm;
        }
        else if (tab_phieu == 3) {
            //Tra sach
            string sp;
            string err;
            hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsoleColor, 12);
            cout << "Nhap so phieu muon tra: ";
            cin >> sp;
            //tra ve id sach
            err = l.traSach(list_pm, n_pm, sp);
            if (err == "0") {
                cout << endl << setw(20) << "Khong tim thay phieu muon.";
                system("pause");
            }
            else if (err == "1") {
                cout << endl << setw(20) << "Phieu muon da d tra.";
                system("pause");
            }
            else {
                cout << endl << setw(20) << "Tra sach thanh cong";
                s.tinhTrangSach(list_s, n_s, err, "0");
                s.cap_nhat_sach(list_s, n_s, false);
                system("pause");

            }
            l.capNhatPhieuMuon(list_pm, n_pm);
            cout << endl;
            _getch();
            goto lb_pm;
        }
        else if (tab_phieu == 0) {
            goto menu;
        }
        cout << setw(20) << "Tac vu duoc chon khong ton tai" << endl;
        goto lb_pm;
    }
    else if (tab == 3) {
    lb_bd:
        system("cls");
        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 12);
        short x = 67;
        short y = 0;
        gotoXY(x, y); cout << setw(20) << "BAN DOC" << endl;
        gotoXY(x, y + 1); cout << "*************************************" << endl;
        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 14);
        gotoXY(x, y + 2); cout << "1. Xem danh sach ban doc" << endl;
        gotoXY(x, y + 3); cout << "2. Them ban doc" << endl;
        gotoXY(x, y + 4); cout << "0. Tro lai menu" << endl;
        gotoXY(x, y + 5); cout << setw(20) << "Chon tac vu: ";
        cin >> tab_bd;
        if (tab_bd == 1) {
            //xem danh sach ban doc
            bd.xuat_ds_bd();

            for (int i = 0; i < n_bd; i++) {
                list_bd[i].xuat_bd();
            }
            _getch();
            goto lb_bd;
        }
        else if (tab_bd == 2) {
            //them ban doc
            bd.themBanDoc(bandoc_input, n_bd + 1);
            list_bd[n_bd] = bandoc_input;
            n_bd++;

            bd.capNhatBanDoc(list_bd, n_bd);

            goto lb_bd;
        }
        else if (tab_bd == 0) {
            goto menu;
        }
        goto lb_bd;
    }
    else {
        exit(0);
    }
}

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}