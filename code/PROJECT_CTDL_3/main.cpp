#include"Caidat.h"

int main()
{
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    remove_scrollbar();
    srand(time_t(NULL));

    if (manHinhDangNhap()) {
        Menu();
    }

    return 0;
}