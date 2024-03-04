#include <iostream>
#include "NgayThangNam.h"

bool isValidDate(int iNgay, int iThang, int iNam)
{
    if (iNam < 1)
        return 0;

    if (iThang < 1 || iThang > 12)
        return 0;

    if (iNgay < 1 || iNgay > 31)
        return 0;

    if ((iThang == 2 || iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11) && iNgay > 30)
        return 0;

    if (iThang == 2)
    {
        if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
        {
            if (iNgay > 29)
                return 0;
        }
        else if (iNgay > 28)
            return 0;
    }
    return 1;
}

void NgayThangNam::Nhap()
{
    std::cout << "Nhap ngay thang nam: ";
    std::cin >> iNgay >> iThang >> iNam;
}

void NgayThangNam::Xuat()
{
    std::cout << "Ngay tiep theo la: " << iNgay << "/" << iThang << "/" << iNam;
}

void NgayThangNam::NgayThangTiepTheo()
{
    while (!isValidDate(iNgay, iThang, iNam))
    {
        std::cout << "Ngay thang nam khong hop le, vui long nhap lai: ";
        std::cin >> iNgay >> iThang >> iNam;
    }
    if (iNgay == 31)
    {
        switch (iThang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            iNgay = 1;
            iThang += 1;
            break;
        case 12:
            iNgay = 1;
            iThang = 1;
            iNam += 1;
            break;
        }
    }
    else if (iNgay == 30)
    {
        switch (iThang)
        {
        case 2:
        case 4:
        case 6:
        case 9:
        case 11:
            iNgay = 1;
            iThang += 1;
        }
    }
    else if (iThang == 2)
    {
        if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
        {
            if (iNgay == 28)
            {
                iNgay += 1;
            }
            else if (iNgay == 29)
            {
                iNgay = 1;
                iThang += 1;
            }
        }
    }
    else
        iNgay += 1;
}
int main()
{

    NgayThangNam test;
    test.Nhap();
    test.NgayThangTiepTheo();
    test.Xuat();

    return 0;
}