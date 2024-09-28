#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <regex>
using namespace std;

// Struct Flight đại diện cho chuyến bay
struct Flight {
    string flightCode;
    string departureDate;  // Định dạng: DD/MM/YYYY
    string departureTime;  // Định dạng: HH:MM (24h)
    string departurePlace;
    string destinationPlace;

    // Hàm hiển thị thông tin chuyến bay
    void display() const {
        cout << "Ma chuyen bay: " << flightCode << "\n"
             << "Ngay bay: " << departureDate << "\n"
             << "Gio bay: " << departureTime << "\n"
             << "Noi di: " << departurePlace << "\n"
             << "Noi den: " << destinationPlace << "\n\n";
    }

    // Hàm kiểm tra định dạng mã chuyến bay (tối đa 5 ký tự, không khoảng trắng, ký tự đặc biệt)
    static bool isValidFlightCode(const string& code) {
        return regex_match(code, regex("^[A-Za-z0-9]{1,5}$"));
    }

    // Hàm kiểm tra định dạng ngày (DD/MM/YYYY)
    static bool isValidDate(const string& date) {
        return regex_match(date, regex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([0-9]{4})$"));
    }

    // Hàm kiểm tra định dạng giờ bay (HH:MM - 24h)
    static bool isValidTime(const string& time) {
        return regex_match(time, regex("^([01][0-9]|2[0-3]):[0-5][0-9]$"));
    }

    // Hàm kiểm tra định dạng nơi đi/nơi đến (tối đa 20 ký tự, không chứa số hoặc ký tự đặc biệt)
    static bool isValidPlace(const string& place) {
        return regex_match(place, regex("^[A-Za-z ]{1,20}$"));
    }

    // Hàm so sánh ngày giờ khởi hành (phục vụ cho việc sắp xếp)
    bool operator<(const Flight& other) const {
        if (departureDate == other.departureDate)
            return departureTime < other.departureTime;
        return departureDate < other.departureDate;
    }
};

// Hàm nhập thông tin chuyến bay
Flight inputFlight() {
    Flight flight;
    do {
        cout << "Nhap ma chuyen bay (toi da 5 ky tu, khong khoang trang hoac ky tu dac biet): ";
        cin >> flight.flightCode;
    } while (!Flight::isValidFlightCode(flight.flightCode));

    do {
        cout << "Nhap ngay bay (DD/MM/YYYY): ";
        cin >> flight.departureDate;
    } while (!Flight::isValidDate(flight.departureDate));

    do {
        cout << "Nhap gio bay (HH:MM - 24h): ";
        cin >> flight.departureTime;
    } while (!Flight::isValidTime(flight.departureTime));

    do {
        cout << "Nhap noi di (khong chua so hoac ky tu dac biet): ";
        cin.ignore();
        getline(cin, flight.departurePlace);
    } while (!Flight::isValidPlace(flight.departurePlace));

    do {
        cout << "Nhap noi den (khong chua so hoac ky tu dac biet): ";
        getline(cin, flight.destinationPlace);
    } while (!Flight::isValidPlace(flight.destinationPlace));

    return flight;
}

// Hàm tìm chuyến bay theo mã chuyến bay
Flight* findFlightByCode(vector<Flight>& flights, const string& code) {
    for (Flight& flight : flights) {
        if (flight.flightCode == code)
            return &flight;
    }
    return nullptr;
}

// Hàm sắp xếp danh sách chuyến bay theo ngày và giờ khởi hành
void sortFlights(vector<Flight>& flights) {
    sort(flights.begin(), flights.end());
}

// Hàm hiển thị danh sách chuyến bay khởi hành từ một nơi trong ngày cụ thể
void displayFlightsFromPlaceOnDate(const vector<Flight>& flights, const string& place, const string& date) {
    cout << "Danh sach chuyen bay khoi hanh tu " << place << " vao ngay " << date << ":\n";
    for (const Flight& flight : flights) {
        if (flight.departurePlace == place && flight.departureDate == date)
            flight.display();
    }
}

// Hàm đếm số chuyến bay từ nơi đi đến nơi đến
int countFlightsBetweenPlaces(const vector<Flight>& flights, const string& fromPlace, const string& toPlace) {
    int count = 0;
    for (const Flight& flight : flights) {
        if (flight.departurePlace == fromPlace && flight.destinationPlace == toPlace)
            count++;
    }
    return count;
}

int main() {
    vector<Flight> flights;
    int n;

    cout << "Nhap so luong chuyen bay: ";
    cin >> n;

    // Nhập thông tin các chuyến bay
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin chuyen bay thu " << i + 1 << ":\n";
        flights.push_back(inputFlight());
    }

    // Sắp xếp danh sách chuyến bay theo ngày giờ khởi hành
    sortFlights(flights);

    // Hiển thị danh sách sau khi sắp xếp
    cout << "\nDanh sach chuyen bay da sap xep theo ngay gio khoi hanh:\n";
    for (const Flight& flight : flights) {
        flight.display();
    }

    // Tìm kiếm chuyến bay theo mã chuyến bay
    string code;
    cout << "Nhap ma chuyen bay can tim: ";
    cin >> code;
    Flight* foundFlight = findFlightByCode(flights, code);
    if (foundFlight) {
        cout << "Chuyen bay tim thay:\n";
        foundFlight->display();
    } else {
        cout << "Khong tim thay chuyen bay voi ma " << code << "\n";
    }

    // Hiển thị chuyến bay khởi hành từ nơi cụ thể trong ngày cụ thể
    string place, date;
    cout << "Nhap noi di de liet ke cac chuyen bay: ";
    cin.ignore();
    getline(cin, place);
    cout << "Nhap ngay khoi hanh (DD/MM/YYYY): ";
    cin >> date;
    displayFlightsFromPlaceOnDate(flights, place, date);

    // Đếm số chuyến bay từ nơi đi đến nơi đến
    string fromPlace, toPlace;
    cout << "Nhap noi di: ";
    cin.ignore();
    getline(cin, fromPlace);
    cout << "Nhap noi den: ";
    getline(cin, toPlace);
    int count = countFlightsBetweenPlaces(flights, fromPlace, toPlace);
    cout << "So chuyen bay tu " << fromPlace << " den " << toPlace << ": " << count << "\n";

    return 0;
}
