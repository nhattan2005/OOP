#include <iostream>
using namespace std;

// Cấu trúc để lưu trữ ngày tháng năm
struct Date {
    int day, month, year;

    // Hàm kiểm tra năm nhuận
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Hàm trả về số ngày trong một tháng, tính theo năm nhuận nếu cần
    int daysInMonth(int m, int y) {
        switch (m) {
            case 4: case 6: case 9: case 11: return 30; // Các tháng có 30 ngày
            case 2: return isLeapYear(y) ? 29 : 28;     // Tháng 2 có 28 hoặc 29 ngày
            default: return 31;                         // Các tháng còn lại có 31 ngày
        }
    }

    // Hàm trả về ngày tiếp theo dựa trên ngày hiện tại
    Date nextDay() {
        int d = day, m = month, y = year;
        // Nếu còn ngày trong tháng hiện tại thì tăng ngày
        if (d < daysInMonth(m, y)) {
            d++;
        } else { // Nếu hết ngày trong tháng, chuyển sang tháng mới
            d = 1;
            if (m < 12) {
                m++; // Chuyển sang tháng tiếp theo
            } else { // Nếu là tháng 12, chuyển sang năm mới
                m = 1;
                y++;
            }
        }
        return {d, m, y}; // Trả về ngày mới
    }

    // Hàm trả về ngày trước đó dựa trên ngày hiện tại
    Date previousDay() {
        int d = day, m = month, y = year;
        // Nếu ngày lớn hơn 1 thì giảm ngày
        if (d > 1) {
            d--;
        } else { // Nếu là ngày 1, quay lại tháng trước
            if (m > 1) {
                m--;
                d = daysInMonth(m, y); // Lấy số ngày cuối cùng của tháng trước
            } else { // Nếu là tháng 1, quay lại ngày cuối cùng của tháng 12 năm trước
                m = 12;
                d = 31;
                y--;
            }
        }
        return {d, m, y}; // Trả về ngày trước đó
    }

    // Hàm trả về số thứ tự ngày trong năm
    int dayOfYear() {
        // Mảng chứa số ngày của các tháng trong năm
        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year)) { // Nếu là năm nhuận, tháng 2 có 29 ngày
            daysInMonths[1] = 29;
        }
        int dayOfYear = 0;
        // Cộng dồn số ngày của các tháng trước tháng hiện tại
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonths[i];
        }
        // Cộng thêm số ngày của tháng hiện tại
        dayOfYear += day;
        return dayOfYear; // Trả về số thứ tự ngày trong năm
    }

    // Hàm in ra ngày tháng theo định dạng dd/mm/yyyy
    void print() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    int day, month, year;
    // Nhập ngày tháng năm
    cout << "Enter a date (dd mm yyyy): ";
    cin >> day >> month >> year;

    // Tạo một đối tượng Date
    Date date = {day, month, year};

    // Tính và in ra ngày tiếp theo
    cout << "The next day is: ";
    Date next = date.nextDay();
    next.print();

    // Tính và in ra ngày trước đó
    cout << "The previous day was: ";
    Date previous = date.previousDay();
    previous.print();

    // In ra số thứ tự của ngày trong năm
    cout << "This day is day number " << date.dayOfYear() << " of the year." << endl;

    return 0;
}
