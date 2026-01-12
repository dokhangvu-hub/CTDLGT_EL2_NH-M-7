// Chuc nang tim kiem nhan vien
// Tim theo ma nhan vien
// Tim theo ho ten (khong phan biet hoa thuong)
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

//cấu trúc
struct NhanVien {
    string ma;
    string hoTen;
    double luong;
};

struct Node {
    NhanVien nv;
    Node* next;
};

//biến toàn cục
Node* head = NULL;

//hàm hổ trợ
string chuyenThuong(string s) {
    for (char &c : s)
        c = tolower((unsigned char)c);
    return s;
}

void inTieuDe() {
    cout << left
         << setw(10) << "Ma NV"
         << setw(25) << "Ho ten"
         << setw(10) << "Luong" << endl;
}

void inNhanVien(const NhanVien& nv) {
    cout << left
         << setw(10) << nv.ma
         << setw(25) << nv.hoTen
         << setw(10) << nv.luong << endl;
}

//tìm kiếm theo mã
void timTheoMa() {
    string ma;
    cout << "Nhap ma can tim: ";
    cin >> ma;

    Node* p = head;
    while (p != NULL) {
        if (p->nv.ma == ma) {
            inTieuDe();
            inNhanVien(p->nv);
            return;
        }
        p = p->next;
    }

    cout << "Khong tim thay nhan vien co ma " << ma << endl;
}

//tìm kiếm theo tên
void timTheoTen() {
    string ten;
    cin.ignore();
    cout << "Nhap ten can tim: ";
    getline(cin, ten);
    ten = chuyenThuong(ten);

    bool timThay = false;
    inTieuDe();

    Node* p = head;
    while (p != NULL) {
        if (chuyenThuong(p->nv.hoTen).find(ten) != string::npos) {
            inNhanVien(p->nv);
            timThay = true;
        }
        p = p->next;
    }

    if (!timThay)
        cout << "Khong tim thay nhan vien phu hop!\n";
}
