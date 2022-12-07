#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>

using namespace std;

void Display() {
    ifstream input("dis.txt");
    if (input.is_open()) {
        string outfile;
        while (getline(input, outfile)) {
            cout << outfile << endl;
        }
    }
}

wstring StringToWString(const string& str)
{
    wstring wstr;
    size_t size;
    wstr.resize(str.length());
    mbstowcs_s(&size, &wstr[0], wstr.size() + 1, str.c_str(), str.size());
    return wstr;
}

string WStringToString(const wstring& wstr)
{
    string str;
    size_t size;
    str.resize(wstr.length());
    wcstombs_s(&size, &str[0], str.size() + 1, wstr.c_str(), wstr.size());
    return str;
}

int main() {
    Display();
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Nguyễn Hùng Sơn");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    /*memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));*/
    SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);

    std::wcout << L"Nhập tên bệnh cần tìm kiếm:" << std::endl;
    fflush(stdin);
    wstring tenbenh;
    std::getline(std::wcin, tenbenh);
    std::transform(tenbenh.begin(), tenbenh.end(), tenbenh.begin(), ::toupper);
    wcout << tenbenh << endl;
    if (tenbenh == L"CHâN TAY MIệNG") {
        wcout << L"- Các dấu hiệu nhận biết bệnh " << tenbenh << ":" << endl;
        wcout << L"     Sốt: sốt nhẹ hoặc sốt cao. Sốt cao không thể hạ là dấu hiệu cảnh báo bệnh nặng." << endl;
        wcout << L"     Tổn thương ở da : Rát đỏ, mụn nước ở các vị trí đặc biệt như họng, quanh miệng, lòng bàn tay, lòng bàn chân, mông, đầu gối..." << endl;
        wcout << L"     Một số trẻ có thể đau miệng, bỏ ăn, nôn, tăng tiết nước bọt, tiêu chảy, mệt mỏi, quấy khóc..." << endl;
        wcout << endl;
        wcout << L"- Thuốc điều trị: " << endl;
        wcout << L"     + Ibuprofen hoặc acetaminophen (paracetamol) với liều lượng 10 - 15mg/kg." << endl;
        wcout << L"     + Cần bổ sung nước và chất điện giải, nên uống dung dịch oresol hoặc hydritre." << endl;
        wcout << L"     + Triệu chứng sốt và loét miệng cần bổ sung thêm vitamin C và kẽm, cũng như dùng glycerin borat lau sạch miệng bé trước và sau khi ăn." << endl;
        wcout << L"     + Các loại thuốc sát khuẩn có thể dùng là: " << endl;
        wcout << L"         * Lidocain: Dùng cho trẻ mọi lứa tuổi" << endl;
        wcout << L"         * Xịt miệng benzydamine: Cho trẻ trên 5 tuổi" << endl;
        wcout << L"         * Súc miệng benzydamine: Trẻ từ 12 tuổi trở lên" << endl;
        wcout << L"         * Nước muối sinh lý nồng độ NaCl 0,9%" << endl;
        wcout << endl;
        wcout << L"- LƯU Ý: " << endl;
        wcout << L"     + Không nên dùng thuốc hạ sốt quá liều lượng khuyến cáo của nhà sản xuất." << endl;
        wcout << L"     + Không mua các loại thuốc có thành phần aspirin, tránh gây hội chứng Reye nguy hiểm" << endl;
        wcout << L"     + Sát khuẩn, súc miệng bằng nước muối đúng nồng độ 0, 9 %, không pha mặn khiến trẻ bị xót và đau đớn" << endl;
        wcout << L"     + Không được tự ý dùng kháng sinh vì thuốc sẽ không có tác dụng với virus tay chân miệng" << endl;
        wcout << L"     + Kháng sinh chỉ được dùng khi có bội nhiễm vi khuẩn theo yêu cầu của bác sĩ" << endl;
        wcout << L"     + Tham khảo ý kiến dược sĩ tại nhà thuốc trước khi dùng thuốc bôi ngoài da" << endl;
        system("pause");
    }
    if (tenbenh == L"SốT XUấT HUYếT") {
        wcout << L"- Các dấu hiệu nhận biết bệnh " << tenbenh << ":" << endl;
        wcout << L"     Sốt kèm đau bụng và đau họng" << endl;
        wcout << L"     Sau 3 ngày thì sẽ hạ sốt nhưng tới ngày thứ 8 thường xuất hiện xuất huyết nhẹ " << endl;
        wcout << L"     Xuất hiện các nốt ban ở thân, sau đó đến mặt, các chi, lòng bàn tay và gây ngứa" << endl;
        wcout << endl;
        wcout << L"- Thuốc điều trị: " << endl;
        wcout << L"     + Paracetamol để hạ sốt, liều dùng từ 10 – 15mg / 1kg / lần, uống thuốc cách nhau ít nhất 4 giờ." << endl;
        wcout << L"     + Cần bổ sung nước và chất điện giải, nên uống dung dịch oresol hoặc hydritre." << endl;
        wcout << endl;
        wcout << L"- TUYỆT ĐỐI CẤM: " << endl;
        wcout << L"     + Cho người bệnh uống Aspirin, Analgin, Ibuprofen, vì thuốc này có thể làm tình trạng bệnh trở nên nặng do xuất huyết hoặc toan máu" << endl;
        wcout << endl;
        wcout << L"- LƯU Ý: " << endl;
        wcout << L"     + Không nên dùng thuốc hạ sốt quá liều lượng khuyến cáo của nhà sản xuất." << endl;
        wcout << L"     + Không mua các loại thuốc có thành phần aspirin, Analgin, Ibuprofen tránh gây nguy hiểm" << endl;
        wcout << L"     + Không sử dụng chất kích thích như rượu bia, cà phê" << endl;
        wcout << L"     + Hạn chế muỗi tiếp xúc với da" << endl;
        wcout << L"     + Không ăn thực phẩm nhiều dầu mỡ" << endl;
        wcout << L"     + Tham khảo ý kiến dược sĩ tại nhà thuốc trước khi dùng thuốc bôi ngoài da" << endl;
        system("pause");
    }
}