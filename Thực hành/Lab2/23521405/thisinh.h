#include <string>
using namespace std;

class ThiSinh {
private:
    string Ten;      // Tên thí sinh
    string MSSV;     // Mã số sinh viên
    int iNgay, iThang, iNam;  // Ngày, tháng, năm sinh
    float fToan, fVan, fAnh;  // Điểm các môn Toán, Văn, Anh

public:
    // Phương thức nhập thông tin thí sinh
    void Nhap();

    // Phương thức xuất thông tin thí sinh
    void Xuat() const;

    // Phương thức tính tổng điểm
    float Tong() const;
};
