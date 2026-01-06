// TP3 - Nhap va xuat du lieu nhan vien
// Nhap danh sach nhan vien
// Xuat thong tin nhan vien ra man hinh
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "nhanvien.h"

using namespace std;


// Tao node moi
Node* taoNode(NhanVien nv) {
    Node* p = new Node;
    p->data = nv;
    p->next = NULL;
    return p;
}

// Them nhan vien vao cuoi danh sach
void themCuoi(Node*& head, NhanVien nv) {
    Node* p = taoNode(nv);

    if (head == NULL) {
        head = p;
        return;
    }

    Node* q = head;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
}

// Kiem tra trung ma nhan vien
bool trungMa(Node* head, string ma) {
    Node* p = head;
    while (p != NULL) {
        if (p->data.maNV == ma)
            return true;
        p = p->next;
    }
    return false;
}

// Nhap 1 nhan vien
NhanVien nhap1NhanVien(Node* head) {
    NhanVien nv;

    do {
        cout << "Nhap ma nhan vien: ";
        getline(cin, nv.maNV);
        if (trungMa(head, nv.maNV))
            cout << "Ma bi trung, nhap lai!\n";
    } while (trungMa(head, nv.maNV));

    cout << "Nhap ho ten: ";
    getline(cin, nv.hoTen);

    cout << "Nhap ngay sinh: ";
    getline(cin, nv.ngaySinh);

    cout << "Nhap email: ";
    getline(cin, nv.email);

    cout << "Nhap dia chi: ";
    getline(cin, nv.diaChi);

    cout << "Nhap so dien thoai: ";
    getline(cin, nv.sdt);

    cout << "Nhap so ngay cong: ";
    cin >> nv.soNgayCong;

    cout << "Nhap luong ngay: ";
    cin >> nv.luongNgay;
    cin.ignore();

    nv.thucLinh = nv.soNgayCong * nv.luongNgay;

    return nv;
}

// Nhap danh sach nhan vien
void nhapDanhSach(Node*& head) {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        NhanVien nv = nhap1NhanVien(head);
        themCuoi(head, nv);
    }
}

// Xuat 1 nhan vien
void xuat1NhanVien(NhanVien nv) {
    cout << left
         << setw(10) << nv.maNV
         << setw(20) << nv.hoTen
         << setw(12) << nv.ngaySinh
         << setw(15) << nv.sdt
         << setw(10) << nv.soNgayCong
         << setw(12) << nv.luongNgay
         << setw(12) << nv.thucLinh
         << endl;
}

// Xuat danh sach nhan vien
void xuatDanhSach(Node* head) {
    if (head == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << left
         << setw(10) << "MaNV"
         << setw(20) << "HoTen"
         << setw(12) << "NgaySinh"
         << setw(15) << "SDT"
         << setw(10) << "NgayCong"
         << setw(12) << "LuongNgay"
         << setw(12) << "ThucLinh"
         << endl;

    Node* p = head;
    while (p != NULL) {
        xuat1NhanVien(p->data);
        p = p->next;
    }
}

// Ghi danh sach ra file DSNV.txt
void ghiFile(Node* head) {
    ofstream file("data/DSNV.txt");

    Node* p = head;
    while (p != NULL) {
        file << p->data.maNV << "|"
             << p->data.hoTen << "|"
             << p->data.ngaySinh << "|"
             << p->data.email << "|"
             << p->data.diaChi << "|"
             << p->data.sdt << "|"
             << p->data.soNgayCong << "|"
             << p->data.luongNgay << "|"
             << p->data.thucLinh << endl;
        p = p->next;
    }

    file.close();
}

// Doc danh sach tu file DSNV.txt
void docFile(Node*& head) {
    ifstream file("data/DSNV.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        NhanVien nv;
        string temp;

        getline(ss, nv.maNV, '|');
        getline(ss, nv.hoTen, '|');
        getline(ss, nv.ngaySinh, '|');
        getline(ss, nv.email, '|');
        getline(ss, nv.diaChi, '|');
        getline(ss, nv.sdt, '|');

        getline(ss, temp, '|');
        nv.soNgayCong = stoi(temp);

        getline(ss, temp, '|');
        nv.luongNgay = stod(temp);

        getline(ss, temp);
        nv.thucLinh = stod(temp);

        themCuoi(head, nv);
    }

    file.close();
}
