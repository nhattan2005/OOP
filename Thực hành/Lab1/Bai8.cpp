#include<bits/stdc++.h>
using namespace std;

// Cấu trúc để lưu trữ ngày
struct day{
    int d, m, y; // Ngày, tháng, năm
};

// Cấu trúc để lưu trữ thông tin tài khoản tiết kiệm
struct info{
    string ma; // Mã số
    string type; // Loại tài khoản (ngắn hạn, dài hạn)
    string name; // Tên chủ tài khoản
    day time; // Ngày mở sổ
    string cmnd; // Số CMND
    double tien; // Số tiền gửi
};

// Map để quản lý mã số tài khoản và lãi suất
map<string,bool> quan_ly;
map<string,int> lai_suat;

// Biến lưu trữ ngày hiện tại
day t;
// Vector chứa danh sách tài khoản tiết kiệm
vector<info> ds;
info a; // Biến để lưu thông tin tài khoản tạm thời
string s; // Biến lưu trữ lựa chọn của người dùng

// Hàm hiển thị hướng dẫn sử dụng
void help(){
    cout<<"1: Mo so tiet kiem moi\n"; // Mở sổ tiết kiệm mới
    cout<<"2: tim kiem du lieu so tiet kiem\n"; // Tìm kiếm dữ liệu sổ tiết kiệm
    cout<<"3: Cap nhat lai xuat\n"; // Cập nhật lãi suất
    cout<<"4: Tinh toan tien lai\n"; // Tính toán tiền lãi
    cout<<"5: Rut tien\n"; // Rút tiền
    cout<<"6.1: Sap xep danh sach giam dan theo tien gui\n"; // Sắp xếp danh sách giảm dần theo số tiền gửi
    cout<<"6.2: Sap xep theo ngay mo so tang dan\n"; // Sắp xếp theo ngày mở sổ tăng dần
    cout<<"end: Thoat\n"; // Thoát chương trình
}

// Kiểm tra mã số có hợp lệ không
bool check_ma_so(string ma){
    if(quan_ly[ma]==true) {cout<<"Da ton tai\n"; return false;} // Kiểm tra mã đã tồn tại
    if(ma.size()>5) return false; // Mã không được dài quá 5 ký tự
    bool OK=true; // Biến kiểm tra tính hợp lệ
    for(char v: ma){
        // Kiểm tra ký tự có phải là chữ cái hoặc số không
        if('0'<=v && v<='9') continue;
        if('a'<=v && v<='z') continue;
        if('A'<=v && v<='Z') continue;
        OK=false; // Nếu không hợp lệ thì đánh dấu
    }
    return OK; // Trả về kết quả kiểm tra
}

// Kiểm tra loại tài khoản có hợp lệ không
bool check_type(string type){
    return (type=="ngan han" || type=="dai han"); // Chỉ chấp nhận "ngan han" hoặc "dai han"
}

// Kiểm tra tên chủ tài khoản có hợp lệ không
bool check_name(string ten){
    if(ten.size()>30) return false; // Tên không được dài quá 30 ký tự
    bool OK=true; // Biến kiểm tra tính hợp lệ
    for(char v: ten){
        // Kiểm tra ký tự có phải là chữ cái hoặc khoảng trắng không
        if('a'<=v && v<='z') continue;
        if('A'<=v && v<='Z') continue;
        if(v==' ') continue;
        OK=false; // Nếu không hợp lệ thì đánh dấu
    }
    return OK; // Trả về kết quả kiểm tra
}

// Kiểm tra số CMND có hợp lệ không
bool check_cmnd(string a){
    if(a.size()!=9 && a.size()!=12) return false; // CMND phải có độ dài 9 hoặc 12
    bool OK=true; // Biến kiểm tra tính hợp lệ
    for(char v: a){
        // Kiểm tra ký tự có phải là số không
        if('0'<=v && v<='9') continue;
        OK=false; // Nếu không hợp lệ thì đánh dấu
    }
    return OK; // Trả về kết quả kiểm tra
}

// Nhập ngày tháng năm
void inp_time(){
    cout<<"nhap ngay thang nam, moi so cach 1 khoang trang (ex: 1 1 1999):";
    cin>>a.time.d>>a.time.m>>a.time.y; // Nhập ngày tháng năm
}

// Mảng chứa số ngày trong từng tháng
int limit_day[13]={0,31,28,31,30,31,30,31,30,31,30,31,30};
// Kiểm tra thời gian có hợp lệ không
bool check_time(day a){
    if(a.y<1) return false; // Năm phải lớn hơn 0
    if(a.m<1 || a.m>12) return false; // Tháng phải trong khoảng 1-12
    bool OK= ((a.y%100==0 && a.y%400==0) || (a.y%100!=0 && a.y%4==0)); // Kiểm tra năm nhuận
    if(a.d<1 || limit_day[a.m]+ OK<a.d) return false; // Ngày phải hợp lệ
    return true; // Trả về kết quả kiểm tra
}

// Hàm nhập thông tin tài khoản
void nhap(){
    cout<<"Ma so :"<<'\n'; // Nhập mã số
    getline(cin,a.ma); // Đọc mã số
    while(!check_ma_so(a.ma)){ // Kiểm tra tính hợp lệ
        cout<<"Khong hop le\n"; // Thông báo không hợp lệ
        cout<<"Nhap lai: ";
        getline(cin,a.ma); // Nhập lại mã số
    }
    quan_ly[a.ma]=true; // Đánh dấu mã số là đã tồn tại
    cout<<"Chon loai tiet kiem trong hai loai duoi day (nhap ngan han hoac dai han)\n"; // Lựa chọn loại tài khoản
    cout<<"ngan han (6 thang) (6%/nam) \n"; // Thông tin về lãi suất ngắn hạn
    cout<<"dai han (12 thang) (7%/nam) \n"; // Thông tin về lãi suất dài hạn
    getline(cin,a.type); // Nhập loại tài khoản
    while(!check_type(a.type)){ // Kiểm tra tính hợp lệ
        cout<<"Khong hop le, vui long chi dien ngan han hoac dai han\n"; // Thông báo không hợp lệ
        cout<<"Nhap lai: ";
        getline(cin,a.type); // Nhập lại loại tài khoản
    }
    // Gán lãi suất tương ứng
    if(a.type=="ngan han") lai_suat[a.ma]=6;
    else lai_suat[a.ma]=7;

    cout<<"Nhap ho va ten: "; // Nhập họ và tên
    getline(cin,a.name); // Đọc họ và tên
    while(!check_name(a.name)){ // Kiểm tra tính hợp lệ
        cout<<"Ten khong duoc chua ky tu dac biet hoac chu so\n"; // Thông báo không hợp lệ
        cout<<"Nhap lai: ";
        getline(cin,a.name); // Nhập lại họ và tên
    }

    cout<<"Nhap chung minh nhan dan: "; // Nhập số CMND
    getline(cin,a.cmnd); // Đọc số CMND
    while(!check_cmnd(a.cmnd)){ // Kiểm tra tính hợp lệ
        cout<<"Khong hop le\n"; // Thông báo không hợp lệ
        cout<<"Nhap lai: ";
        getline(cin,a.cmnd); // Nhập lại số CMND
    }

    cout<<"Ngay mo so: \n"; // Nhập ngày mở sổ
    inp_time(); // Gọi hàm nhập thời gian
    while(!check_time(a.time)){ // Kiểm tra tính hợp lệ
        cout<<"Khong hop le\n"; // Thông báo không hợp lệ
        cout<<"nhap lai \n";
        inp_time(); // Nhập lại ngày mở sổ
    }

    cout<<"so tien gui: \n"; // Nhập số tiền gửi
    cin>>a.tien; // Đọc số tiền gửi
    while(a.tien<0){ // Kiểm tra số tiền có hợp lệ không
        cout<<"So tien khong the am\n"; // Thông báo không hợp lệ
        cout<<"Nhap lai: \n";
        cin>>a.tien; // Nhập lại số tiền gửi
    }
    cin.ignore(); // Xóa bộ đệm
    ds.push_back(a); // Thêm thông tin tài khoản vào danh sách
}

// Hàm so sánh hai ngày
bool so_sanh(day a, day b){
    if(a.y!=b.y) return a.y<b.y; // So sánh năm
    if(a.m!=b.m) return a.m<b.m; // So sánh tháng
    return a.d<b.d; // So sánh ngày
}

// Hàm so sánh để sắp xếp theo tiền gửi giảm dần
bool cmp1(info a,info b){
    return a.tien>b.tien;
}

// Hàm so sánh để sắp xếp theo ngày mở sổ tăng dần
bool cmp2(info a,info b){
    return so_sanh(a.time,b.time)==true;
}

// Vector để chứa kết quả tìm kiếm
vector<info> tap_xuat;

// Hàm tìm kiếm tất cả tài khoản
void search_1(){
    tap_xuat=ds; // Sao chép toàn bộ danh sách
}

// Hàm tìm kiếm theo mã số tài khoản
void search_2(){
    string ma_so;
    cout<<"Nhap ma so can tim\n"; // Nhập mã số cần tìm
    cin>>ma_so; // Đọc mã số
    for(info a: ds){ // Duyệt qua danh sách tài khoản
        if(a.ma==ma_so){ // Nếu mã số khớp
            tap_xuat.push_back(a); // Thêm vào danh sách kết quả
        }
    }
}

// Hàm tìm kiếm theo khoảng thời gian
void search_3(){
    day a,b; // Hai ngày để lưu khoảng thời gian
    cout<<"Nhap ngay,thang,nam bat dau moi so cach 1 khoang trang: \n"; // Nhập ngày bắt đầu
    cin>>a.d>>a.m>>a.y; // Đọc ngày bắt đầu
    while(!check_time(a)){ // Kiểm tra tính hợp lệ
        cout<<"Khong hop le\n"; // Thông báo không hợp lệ
        cout<<"nhap lai \n";
        cin>>a.d>>a.m>>a.y; // Nhập lại ngày bắt đầu
    }

    cout<<"Nhap ngay,thang,nam ket thuc moi so cach 1 khoang trang: \n"; // Nhập ngày kết thúc
    cin>>b.d>>b.m>>b.y; // Đọc ngày kết thúc
    while(!check_time(b)){ // Kiểm tra tính hợp lệ
        cout<<"Khong hop le\n"; // Thông báo không hợp lệ
        cout<<"nhap lai \n";
        cin>>b.d>>b.m>>b.y; // Nhập lại ngày kết thúc
    }

    for(info v: ds){ // Duyệt qua danh sách tài khoản
        if(so_sanh(a,v.time) && so_sanh(v.time,b)){ // Kiểm tra xem ngày mở sổ có nằm trong khoảng không
            tap_xuat.push_back(v); // Thêm vào danh sách kết quả
        }
    }
}

// Hàm xuất danh sách kết quả tìm kiếm
void xuat_tap_xuat(){
    cout<<"\n\n";
    cout<<"ma so, ho va ten, loai tiet kiem, cmnd, thoi gian mo so, so tien\n"; // Tiêu đề
    for(info v: tap_xuat){ // Duyệt qua danh sách kết quả
        cout<<v.ma<<", "<<v.name<<", "<<v.type<<", "<<v.cmnd<<", "<<v.time.d<<' '<<v.time.m<<' '<<v.time.y<<", "<<v.tien<<'\n'; // Xuất thông tin
    }
}

// Hàm tìm kiếm thông tin tài khoản
void search_info(){
    cout<<"Go 1 chu so tuong ung voi cac lua chon sau day:\n"; // Hiển thị lựa chọn tìm kiếm
    cout<<"1: In ra tat ca\n"; // Tìm tất cả
    cout<<"2: Tim kiem thong tin so\n"; // Tìm kiếm theo mã số
    cout<<"3: In ra cac thong tin so trong khoang thoi gian\n"; // Tìm kiếm theo khoảng thời gian
    int op;
    cin>>op; // Đọc lựa chọn
    tap_xuat.clear(); // Xóa danh sách kết quả
    if(op==1){ // Nếu chọn 1
        search_1(); // Tìm tất cả
        xuat_tap_xuat(); // Xuất kết quả
    }
    else if(op==2){ // Nếu chọn 2
        search_2(); // Tìm kiếm theo mã số
        xuat_tap_xuat(); // Xuất kết quả
    }
    else if(op==3){ // Nếu chọn 3
        search_3(); // Tìm kiếm theo khoảng thời gian
        xuat_tap_xuat(); // Xuất kết quả
    }
    else{
        cout<<"Khong hop le\n"; // Thông báo không hợp lệ
    }
}

// Biến lưu trữ ngày hiện tại
day now;
day han; // Biến lưu trữ hạn
// Hàm lấy thời gian hiện tại
void get_now_time(){
    time_t old = time(0); // Lấy thời gian hiện tại
    tm *ltm = localtime(&old); // Chuyển đổi thành định dạng địa phương
    now.y=1900+ltm->tm_year; // Lấy năm
    now.m=1+ltm->tm_mon; // Lấy tháng
    now.d=ltm->tm_mday; // Lấy ngày
}

// Hàm rút tiền
void rut_tien(){
    string ma_so;
    cout<<"Nhap ma so can rut tien\n"; // Nhập mã số cần rút tiền
    cin>>ma_so; // Đọc mã số
    while(quan_ly[ma_so]==false){ // Kiểm tra mã số có tồn tại không
        cout<<"Khong ton tai: \n"; // Thông báo không tồn tại
        cout<<"Nhap lai hoac ghi go out de thoat\n"; // Nhập lại hoặc thoát
        cin>>ma_so; // Nhập lại mã số
        if(ma_so=="go out") return; // Nếu nhập "go out" thì thoát
    }

    double rut; // Biến lưu trữ số tiền rút
    for(info &a: ds){ // Duyệt qua danh sách tài khoản
        if(a.ma==ma_so){ // Nếu mã số khớp
            cout<<"So tien can rut: \n"; // Nhập số tiền rút
            cin>>rut; // Đọc số tiền rút
            while(rut<0 || a.tien<rut){ // Kiểm tra số tiền có hợp lệ không
                cout<<"Tien rut phai duong va khong the vuot qua so tien dang co \n"; // Thông báo không hợp lệ
                cout<<"Nhap lai: \n";
                cin>>rut; // Nhập lại số tiền rút
            }

            get_now_time(); // Lấy thời gian hiện tại
            if(a.type=="ngan han"){ // Nếu loại tài khoản là ngắn hạn
                han=a.time; // Gán hạn
                han.m+=6; // Cộng 6 tháng vào ngày mở sổ
                if(han.m>12){ // Nếu tháng vượt quá 12
                    han.y++; // Cộng 1 năm
                    han.m-=12; // Giảm tháng
                }
            }
            else{ // Nếu loại tài khoản là dài hạn
                han=a.time; // Gán hạn
                han.y+=1; // Cộng 1 năm
            }
            if(so_sanh(now,han)){ // Kiểm tra xem có rút trước hạn không
                cout<<"Rut truoc han, tu dong tinh lai suat la 5%/nam \n"; // Thông báo rút trước hạn
                lai_suat[a.ma]=5; // Cập nhật lãi suất
            }

            a.tien-=rut; // Giảm số tiền trong tài khoản
            break; // Kết thúc vòng lặp
        }
    }
}

// Hàm cập nhật lãi suất
void cap_nhat_lai_suat(){
    string ma_so;
    cout<<"Nhap ma so can cap nhat lai suat\n"; // Nhập mã số cần cập nhật lãi suất
    getline(cin,ma_so); // Đọc mã số
    while(quan_ly[ma_so]==false){ // Kiểm tra mã số có tồn tại không
        cout<<"Khong ton tai: \n"; // Thông báo không tồn tại
        cout<<"Nhap lai hoac ghi go out de thoat\n"; // Nhập lại hoặc thoát
        cin>>ma_so; // Nhập lại mã số
        if(ma_so=="go out") return; // Nếu nhập "go out" thì thoát
    }
    double lai; // Biến lưu trữ lãi suất
    cout<<"Nhap lai suat\n"; // Nhập lãi suất
    cin>>lai; // Đọc lãi suất
    if(lai<0){ // Kiểm tra lãi suất có hợp lệ không
        cout<<"Loi so am \n"; // Thông báo không hợp lệ
        cout<<"Nhap lai \n";
        cin>>lai; // Nhập lại lãi suất
    }

    for(info &a: ds){ // Duyệt qua danh sách tài khoản
        if(a.ma==ma_so){ // Nếu mã số khớp
            cout<<a.tien*lai<<'\n'; // Tính lãi suất và xuất kết quả
        }
    }
}

// Hàm tính số ngày giữa hai ngày
int diff(day borrow, day pay){
    int days_of_month[13] = {0,
                             31,28,31,30,31,30,
                             31,31,30,31,30,31}; // Số ngày trong từng tháng

    long total_borrow_day = borrow.y * 365 + borrow.d; // Tổng số ngày cho ngày mượn
    for(int i = 1; i < borrow.m; i++){
        total_borrow_day += days_of_month[i]; // Cộng số ngày cho tháng
    }

    long total_pay_day = pay.y * 365 + pay.d; // Tổng số ngày cho ngày trả
    for(int i = 1; i < pay.m; i++){
        total_pay_day += days_of_month[i]; // Cộng số ngày cho tháng
    }
    return (total_pay_day - total_borrow_day); // Trả về số ngày khác nhau
}

// Hàm tính toán tiền lãi
void tinh_toan_tien_lai(){
    string ma_so;
    cout<<"Nhap ma so can tinh lai\n"; // Nhập mã số cần tính lãi
    getline(cin,ma_so); // Đọc mã số
    while(1){ // Vòng lặp kiểm tra mã số
        if(quan_ly[ma_so]==true) break; // Nếu mã số tồn tại thì thoát vòng lặp
        cout<<"Khong ton tai:"<<'\n'; // Thông báo không tồn tại
        cout<<"Nhap lai hoac ghi go out de thoat"<<'\n'; // Nhập lại hoặc thoát
        getline(cin,ma_so); // Nhập lại mã số
        cin.ignore(); // Xóa bộ đệm
        if(ma_so=="go out") return; // Nếu nhập "go out" thì thoát
    }
    for(info a: ds){ // Duyệt qua danh sách tài khoản
        if(a.ma==ma_so){ // Nếu mã số khớp
            cout<<"So tien lai: \n"; // Xuất thông báo
            get_now_time(); // Lấy thời gian hiện tại
            cout<<a.tien*(diff(a.time,now))*lai_suat[a.ma]<<'\n'; // Tính và xuất số tiền lãi
        }
    }
}

int main(){
    cout<<"Kinh chao quy khach\n"; // Chào khách hàng
    help(); // Hiển thị hướng dẫn
    cout<<"help : danh sach dich vu\n"; // Hiển thị danh sách dịch vụ

    while(1){ // Vòng lặp chính
        cout<<"\n\n";
        cout<<"dich vu (chon mot so tu 1 den 6.2, help hoac end) \n "; // Hiển thị dịch vụ
        cin>>s; // Nhập lựa chọn
        cin.ignore(); // Xóa bộ đệm
        if(s=="1"){ // Nếu chọn 1
            nhap(); // Nhập tài khoản mới
        }
        else if(s=="2"){ // Nếu chọn 2
            search_info(); // Tìm kiếm thông tin tài khoản
        }
        else if(s=="3"){ // Nếu chọn 3
            cap_nhat_lai_suat(); // Cập nhật lãi suất
        }
        else if(s=="4"){ // Nếu chọn 4
            tinh_toan_tien_lai(); // Tính toán tiền lãi
        }
        else if(s=="5"){ // Nếu chọn 5
            rut_tien(); // Rút tiền
        }
        else if(s=="6.1"){ // Nếu chọn 6.1
            sort(ds.begin(),ds.end(),cmp1); // Sắp xếp theo số tiền giảm dần
        }
        else if(s=="6.2"){ // Nếu chọn 6.2
            sort(ds.begin(),ds.end(),cmp2); // Sắp xếp theo ngày mở sổ tăng dần
        }
        else if(s=="help"){ // Nếu chọn help
            help(); // Hiển thị hướng dẫn
        }
        else if(s == "end"){ // Nếu chọn end
            break; // Thoát vòng lặp
        }
        else{
            cout<<"khong hop le\n"; // Thông báo không hợp lệ
        }
    }
    return 0; // Kết thúc chương trình
}
