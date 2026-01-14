// Khai báo struct NhanVien, Node
// Công thức tính Thực Lĩnh
#include <iostream>
#include <string>

using namespace std;
// CẤU TRÚC NHÂN VIÊN
struct NhanVien {
    string Ma;        // Mã nhân viên
    string HoTen;     // Họ tên
    string NgaySinh;  // Ngày sinh
    string Email;     // Email
    string DiaChi;    // Địa chỉ
    string Sdt;       // Số điện thoại
    int SoNgayCong;   // Số ngày công
    double LuongNgay; // Lương theo ngày
    double ThucLinh;  // Lương thực lĩnh
};
// NODE DANH SÁCH LIÊN KẾT ĐƠN
struct Node {
    NhanVien NV;  // Dữ liệu nhân viên
    Node* next;   // Con trỏ node kế tiếp
};
// Con trỏ đầu danh sách
Node* head = NULL;
// HÀM TÍNH LƯƠNG THỰC LĨNH
// Thực lĩnh = số ngày công * lương ngày
double TinhThucLinh(const NhanVien& nv) {
    return nv.SoNgayCong * nv.LuongNgay;
}
// HÀM TẠO NODE MỚI
Node* TaoNode(const NhanVien& nv) {
    Node* p = new Node;
    p->nv = nv;
    p->nv.ThucLinh = TinhThucLinh(nv);
    p->next = NULL;
    return p;
}
