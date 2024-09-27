#include <iostream>
#include <vector>
using namespace std;

// Cấu trúc để tìm kiếm mảng con trong mảng
struct SubArraySearch {
    vector<int> A, B; // Mảng A (mảng con) và mảng B (mảng chính)

    // Constructor để khởi tạo mảng A và B
    SubArraySearch(const vector<int>& a, const vector<int>& b) : A(a), B(b) {}

    // Hàm tính mảng LPS (Longest Prefix Suffix) cho mảng A
    vector<int> computeLPSArray() {
        int M = A.size(); // Kích thước của mảng A
        vector<int> lps(M); // Mảng LPS khởi tạo với kích thước M
        int len = 0; // Độ dài của prefix
        lps[0] = 0; // LPS của ký tự đầu tiên là 0
        int i = 1; // Bắt đầu từ ký tự thứ hai

        // Tính toán mảng LPS
        while (i < M) {
            if (A[i] == A[len]) { // Nếu ký tự hiện tại bằng ký tự ở vị trí len
                len++;
                lps[i] = len; // Cập nhật giá trị LPS
                i++; // Chuyển sang ký tự tiếp theo
            }
            else { // Nếu ký tự không khớp
                if (len != 0) {
                    len = lps[len - 1]; // Trở lại với giá trị LPS trước đó
                }
                else {
                    lps[i] = 0; // Không có prefix nào
                    i++; // Chuyển sang ký tự tiếp theo
                }
            }
        }
        return lps; // Trả về mảng LPS
    }

    // Hàm tìm kiếm mảng A trong mảng B sử dụng thuật toán KMP
    vector<int> KMPSearch() {
        vector<int> result; // Mảng chứa vị trí của các lần xuất hiện
        int N = B.size(); // Kích thước của mảng B
        int M = A.size(); // Kích thước của mảng A

        vector<int> lps = computeLPSArray(); // Tính toán mảng LPS

        int i = 0; // Chỉ số cho mảng B
        int j = 0; // Chỉ số cho mảng A
        // Duyệt mảng B
        while (i < N) {
            if (A[j] == B[i]) { // Nếu ký tự tại mảng A và B khớp
                j++; // Tăng chỉ số của A
                i++; // Tăng chỉ số của B
            }

            // Nếu đã tìm thấy toàn bộ mảng A trong B
            if (j == M) {
                result.push_back(i - j); // Lưu vị trí bắt đầu
                j = lps[j - 1]; // Trở lại chỉ số của mảng A theo LPS
            }
            // Nếu không khớp
            else if (i < N && A[j] != B[i]) {
                if (j != 0)
                    j = lps[j - 1]; // Quay lại chỉ số của mảng A theo LPS
                else
                    i++; // Chuyển sang ký tự tiếp theo trong mảng B
            }
        }

        return result; // Trả về danh sách các vị trí xuất hiện
    }
};

int main() {
    int sizeA, sizeB;

    // Nhập kích thước của mảng A và B từ người dùng
    cout << "Enter the number of elements in array A and array B: ";
    cin >> sizeA >> sizeB;

    vector<int> A(sizeA), B(sizeB); // Khởi tạo mảng A và B với kích thước đã nhập

    // Nhập các phần tử của mảng A
    cout << "Enter the elements of array A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i]; // Nhập từng phần tử
    }

    // Nhập các phần tử của mảng B
    cout << "Enter the elements of array B: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i]; // Nhập từng phần tử
    }

    // Khởi tạo đối tượng tìm kiếm mảng con
    SubArraySearch searcher(A, B);
    vector<int> result = searcher.KMPSearch(); // Tìm kiếm mảng A trong mảng B

    // In ra số lần xuất hiện của mảng A trong mảng B
    cout << "Number of occurrences of A in B: " << result.size() << endl;
    cout << "Starting indices of occurrences: ";
    for (int pos : result) {
        cout << pos << " "; // In ra các vị trí bắt đầu
    }
    cout << endl;

    return 0; // Kết thúc chương trình
}
