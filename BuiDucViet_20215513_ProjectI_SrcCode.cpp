#include<iostream>
#include<fstream>
#include<string.h>
#include <cstdlib>
#include<vector>
#include <iomanip>
using namespace std;
int nMathang, nHoadon;
struct Date {
    unsigned int ngay;
    unsigned int thang;
    unsigned int nam;
    bool Bangthangnam(Date d){
        if(d.nam == nam && d.thang == thang){
            return true;
        }
        else return false;

    }
    bool BangNgay(Date d){
        if(d.nam == nam && d.thang == thang && d.ngay == ngay){
            return true;
        }
        else return false;

    }
    void TangNgayThang() {
        // Số ngày trong mỗi tháng
        const int soNgayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        ngay += 1;

        // Kiểm tra và điều chỉnh nếu ngày vượt quá số ngày trong tháng
        if (ngay > soNgayTrongThang[thang]) {
            ngay = 1;
            thang += 1;

            // Kiểm tra và điều chỉnh nếu tháng vượt quá 12
            if (thang > 12) {
                thang = 1;
                nam += 1;
            }
        }
    }
};
struct Mathang {
    string maMH;
    string tenMH;
    char NCC[50];
    int soluongcon;
    double gianhap;
    double giaban;
    bool operator<(const Mathang& other) const {
        return maMH < other.maMH;
    }
    bool operator>(const Mathang& other) const {
        return tenMH > other.tenMH;
    }
    Date date;
    bool valid;

   
};

struct Hoadon {
    string maHĐ;
    Date ngaynhapdon;
    char nguoiNhap[50];
    char khachHang[50];
    double tongHD;
    double cost;

    vector<Mathang> dsmh;
    vector<int> count_each_mh;
    int soLuongMH;
    int daTT;
    bool operator<(const Hoadon& other) const {
        return maHĐ < other.maHĐ;
    }

};
int compareString(const std::string& str1, const std::string& str2) {
    return str1.compare(str2);
}
void getNgayThangNam(string ngay, Date &d){
    char temp[5];
    int i = 0;
    int so=0;
    int len = ngay.length();
    while(ngay[i]!='/' && i < len){
        so = so*10 + (ngay[i]-'0');
        i++;
    }
    i++;
    d.ngay = so;
    so = 0;
    while(ngay[i]!='/' && i < len){
        so = so*10 + (ngay[i]-'0');
        i++;
    }
    i++;
    d.thang=so;
    so = 0;
    while(ngay[i]!='/' && i < len){
        so = so*10 + (ngay[i]-'0');
        i++;
    }
    d.nam = so;
}

string dateToString(const Date& date) {
    string s ="";
    s+= to_string(date.ngay);
    s+="/";
    s+= to_string(date.thang);
    s+="/";
    s+= to_string(date.nam);
    return s;
};
void Menu();
void MenuQLMH();
void MenuQLHĐ();
void MenuThongKe();
int find_vitri_maMH(string maMH);
vector<Mathang> listMH;
vector<Hoadon> listHĐ;
void merge(std::vector<Mathang>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo các vector tạm để lưu trữ hai nửa
    std::vector<Mathang> leftArr(n1);
    std::vector<Mathang> rightArr(n2);

    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    
    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (leftArr[i] < rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp mặt hàng theo mã
void mergeSort(std::vector<Mathang>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
bool compareDate(const Date& date1, const Date& date2) {
    if (date1.nam < date2.nam || (date1.nam == date2.nam && date1.thang < date2.thang) || (date1.nam == date2.nam && date1.thang == date2.thang && date1.ngay <= date2.ngay)) {
        return true;
    }
    return false;
}
bool compareDatee(const Date& date1, const Date& date2) {
    if (date1.nam < date2.nam || (date1.nam == date2.nam && date1.thang < date2.thang) || (date1.nam == date2.nam && date1.thang == date2.thang && date1.ngay < date2.ngay)) {
        return true;
    }
    return false;
}
//sắp xếp theo mã đơn
void mergehd(std::vector<Hoadon>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo các vector tạm để lưu trữ hai nửa
    std::vector<Hoadon> leftArr(n1);
    std::vector<Hoadon> rightArr(n2);

    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    
    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (leftArr[i] < rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp hd theo mã
void mergeSorthd(std::vector<Hoadon>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSorthd(arr, left, mid);
        mergeSorthd(arr, mid + 1, right);
        mergehd(arr, left, mid, right);
    }
}
// sắp xếp hóa đơn theo ngày
void mergee(vector<Hoadon>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;


    vector<Hoadon> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareDate(L[i].ngaynhapdon, R[j].ngaynhapdon)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSortt(vector<Hoadon>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortt(arr, left, mid);
        mergeSortt(arr, mid + 1, right);
        mergee(arr, left, mid, right);
    }
}

void mergedate(vector<Mathang>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;


    vector<Mathang> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareDate(L[i].date, R[j].date)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSortdate(vector<Mathang>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortdate(arr, left, mid);
        mergeSortdate(arr, mid + 1, right);
        mergedate(arr, left, mid, right);
    }
}

vector<Mathang> binarySearchOutDate(const std::vector<Mathang>& danhSachMathang, const Date& ngayCanTim) {
    vector<Mathang> ketQua;

    int left = 0;
    int right = listMH.size() - 1;
    cout << 1 << endl;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (compareDatee(listMH[mid].date, ngayCanTim)) {
            // Nếu tìm thấy, duyệt qua các hóa đơn có cùng ngày và thêm vào danh sách kết quả
            int index = mid;
            while (index >= 0 && compareDatee(listMH[index].date, ngayCanTim)) {
                 listMH[index].valid=false;
                ketQua.push_back(listMH[index]);
               
                index--;
            }
            index = mid + 1;
            while (index < listMH.size() && compareDatee(listMH[index].date, ngayCanTim)) {
                 listMH[index].valid=false;
                ketQua.push_back(listMH[index]);
                index++;
            }
            break; // Kết thúc vòng lặp vì đã tìm thấy và duyệt xong
        } else if (compareDatee(ngayCanTim,listMH[mid].date)) {
             right = mid - 1; // Tìm ở bên trái mid
        } 
    }
    mergeSortdate(ketQua, 0, ketQua.size()-1);
    cout << ketQua.size() << endl;
    cout << 1 << endl;
    return ketQua;
}
/*bool compareDateInMonth(const Date& date1, const Date& date2) {
    if (date1.nam = date2.nam || (date1.nam == date2.nam && date1.thang < date2.thang) || (date1.nam == date2.nam && date1.thang == date2.thang && date1.ngay < date2.ngay)) {
        return true;
    }
    return false;
}*/
vector<Mathang> binarySearchOutDateInMonth(const std::vector<Mathang>& danhSachMathang, int month, int year) {
    vector<Mathang> ketQua;

    int left = 0;
    int right = listMH.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ( listMH[mid].date.nam == year && listMH[mid].date.thang==month) {
            // Nếu tìm thấy, duyệt qua các hóa đơn có cùng ngày và thêm vào danh sách kết quả
            int index = mid;
            while (index >= 0 && listMH[index].date.nam == year && listMH[index].date.thang==month) {
                listMH[index].valid=false;
                ketQua.push_back(listMH[index]);
               
                index--;
            }
            index = mid + 1;
            while (index < listMH.size() && listMH[index].date.nam == year && listMH[index].date.thang==month) {
                listMH[index].valid=false;
                ketQua.push_back(listMH[index]);
                index++;
            }
            break; // Kết thúc vòng lặp vì đã tìm thấy và duyệt xong
        }  else if(listMH[mid].date.nam < year || listMH[mid].date.nam == year && listMH[mid].date.thang<month){
            left = mid + 1; // Tìm ở bên phải mid
        }else  {
             right = mid - 1; // Tìm ở bên trái mid
        }
    }
    mergeSortdate(ketQua, 0, ketQua.size()-1);
    return ketQua;
    
}
void docFileMH(){
    ifstream out;
    out.open("C:\\Users\\Administrator\\Downloads\\Project 1\\dsmathang.txt");
     std::time_t t = std::time(nullptr);
    
    // Chuyển đổi thời gian thành cấu trúc tm
    std::tm* time_info = std::localtime(&t);
    
    // Sử dụng stringstream để tạo chuỗi ngày hiện tại
    std::ostringstream oss;
    oss << std::setfill('0') << time_info->tm_mday << '/'
        << std::setw(2) << std::setfill('0') << (time_info->tm_mon + 1) << '/'
        << std::setw(4) <<  (time_info->tm_year + 1900);
    // Lấy chuỗi ngày hiện tại
    std::string current_date = oss.str();
    Date d;
    getNgayThangNam(current_date,d);
    
    out >> nMathang;
    
    for(int i =0; i < nMathang; i++){
       Mathang mh ;
       int STT;
       string temp;
       out >> STT >> mh.maMH >> mh.tenMH >> mh.NCC >> mh.soluongcon >> mh.gianhap >> mh.giaban >> temp;
       getNgayThangNam(temp,mh.date);
       if(compareDatee(mh.date,d)){
          mh.valid=false;
       }
       else mh.valid = true;
       listMH.push_back(mh);
    }
    out.close();
};
void luuFileMH (){
    ofstream out;
    out.open("C:\\Users\\Administrator\\Downloads\\Project 1\\dsmathang.txt");
    out << nMathang << endl;
    mergeSortdate(listMH, 0 , nMathang-1);
    /*mergeSort(listMH, 0, listMH.size() - 1);*/
    for(int i =0; i < nMathang; i++){
        string temp = dateToString(listMH[i].date);
        out << std::setw(5) << i+1 ;
        out << std::setw(10)<< listMH[i].maMH  ;
        out << std::setw(15) << listMH[i].tenMH ;
        out << std::setw(15)<< listMH[i].NCC ;
        out << std::setw(5)<< listMH[i].soluongcon ;
        out << std::setw(10)<< listMH[i].gianhap  ;
        out << std::setw(10)<< listMH[i].giaban ;
        out << std::setw(12) << temp << endl;
    }
    out.close();
}

void docFileHD(){
    ifstream out;
    out.open("C:\\Users\\Administrator\\Downloads\\Project 1\\dshoadon.txt");
    out >> nHoadon;
    for(int i =0; i < nHoadon; i++){
       Hoadon hd ;
       string ngay;
       out >> hd.maHĐ >> ngay >> hd.nguoiNhap >> hd.khachHang;
       string datt;     
       out  >> hd.tongHD >> hd.cost >> hd.soLuongMH;
       out >> datt;
       if(compareString(datt,"daTT")==0) hd.daTT=1; else hd.daTT=0;
       for(int j=0; j< hd.soLuongMH; j++){
          string maMH;
          int soluongmh;
          out >> maMH >> soluongmh;
          Mathang mh  = listMH[find_vitri_maMH(maMH)];
          hd.dsmh.push_back(mh);
          hd.count_each_mh.push_back(soluongmh);
        
       }
       getNgayThangNam(ngay, hd.ngaynhapdon);
       listHĐ.push_back(hd);
    }
    out.close();
};
void luuFileHD(){
    ofstream out;
    out.open("C:\\Users\\Administrator\\Downloads\\Project 1\\dshoadon.txt");
    out << nHoadon << endl;
    mergeSortt(listHĐ, 0, listHĐ.size() - 1);
    for(int i = 0; i < nHoadon; i++){
        out << listHĐ[i].maHĐ <<" ";
        out << listHĐ[i].ngaynhapdon.ngay << "/" << listHĐ[i].ngaynhapdon.thang << "/"<< listHĐ[i].ngaynhapdon.nam<<" ";  
        out << listHĐ[i].nguoiNhap << " ";
        out << listHĐ[i].khachHang << " ";
        out << listHĐ[i].tongHD << " ";
        out << listHĐ[i].cost << " ";
        out << listHĐ[i].soLuongMH << " ";
        if(listHĐ[i].daTT==1) out <<"daTT" <<" ";
        else  out <<"chuaTT" <<" "; 
        for(int j =0 ; j < listHĐ[i].soLuongMH; j++){
            out << listHĐ[i].dsmh[j].maMH <<" "<< listHĐ[i].count_each_mh[j] << " ";
        }
        out << endl;
    }
    out.close();
}
vector<Hoadon> binarySearchTatCaTheoThang(const std::vector<Hoadon>& danhSachHoaDon, int thang, int nam) {
    vector<Hoadon> ketQua;

    int left = 0;
    int right = listHĐ.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (listHĐ[mid].ngaynhapdon.nam == nam &&
            listHĐ[mid].ngaynhapdon.thang == thang ) {
            // Nếu tìm thấy, duyệt qua các hóa đơn có cùng ngày và thêm vào danh sách kết quả
            int index = mid;
            while (index >= 0 && listHĐ[index].ngaynhapdon.nam == nam && listHĐ[index].ngaynhapdon.thang == thang) {
                ketQua.push_back(listHĐ[index]);
                index--;
            }
            index = mid + 1;
            while (index < listHĐ.size() && listHĐ[index].ngaynhapdon.nam == nam && listHĐ[index].ngaynhapdon.thang == thang) {
                ketQua.push_back(listHĐ[index]);
                index++;
            }
            break; // Kết thúc vòng lặp vì đã tìm thấy và duyệt xong
        } else if (listHĐ[mid].ngaynhapdon.nam < nam || listHĐ[mid].ngaynhapdon.nam <=nam && listHĐ[mid].ngaynhapdon.thang <= thang) {
            left = mid + 1; // Tìm ở bên phải mid
        } else {
            right = mid - 1; // Tìm ở bên trái mid
        }
    }

    return ketQua;
}
void baoCaoMHtrongThang(){
    mergeSortdate(listMH,0,nMathang-1);
    int month, year;
    cout << "Nhap vao nam can thong ke: ";
    cin >> year;
    cout << "Nhap vao thang can thong ke: ";
    cin >> month;
    vector<Hoadon> hd = binarySearchTatCaTheoThang(listHĐ, month, year);
    vector<Mathang> mh = binarySearchOutDateInMonth(listMH, month, year);
    if(hd.size()==0){
        cout << "Thang nay chua ban duoc mat hang nao" << endl;
        return;
    }
    //mảng danh sách thứ tự mặt hàng
    int dem[nMathang];
    for(int i =0 ; i < nMathang; i++){
        dem[i]=0;
    }
    for(int i =0; i <hd.size(); i++){
        
        if(hd[i].daTT==1){
        for(int j = 0; j < hd[i].soLuongMH; j++){
            int index = find_vitri_maMH(hd[i].dsmh[j].maMH);
            int temp = hd[i].count_each_mh[j];
            dem[index] +=temp; 
        }}
    }
    double lo =0;
    for(int i = 0; i < mh.size(); i++){
        lo +=mh[i].gianhap*mh[i].soluongcon;
    }
    printf("%20s%30s%20s%20s%20s%20s\n","MaMH","TenMH","Soluongban","Dongianhap","Dongiaban","Loinhuan");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
    double tien = 0;
    double tong = 0;
    for(int i =0; i <nMathang; i++){
        if(dem[i]>0){
            tien = (listMH[i].giaban-listMH[i].gianhap)*dem[i];
            tong+=tien;
            cout << "              " << listMH[i].maMH;
            cout << "                   " <<listMH[i].tenMH;
            printf("%20d%20f%20f%20f\n",dem[i],listMH[i].gianhap*1000,listMH[i].giaban*1000,tien*1000);
        }
    }
        printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    cout << "Co " << mh.size() << " mat hang het han trong thang nay" << endl;
    cout << "Tong tien hang het han la: " << lo << endl;
    tong-=lo;
    if (tong > 0)
        printf("%20s%10f\n","Tong loi nhuan sau khi tru hang het han la: ",tong*1000);
    else  printf("%s%10f\n","Thang nay lo: ",-tong*1000) ;
}   
bool soSanhNgay(const Date& a, const Date& b) {
    if(a.ngay == b.ngay && a.thang == b.thang && a.nam == b.nam) return true;
    else return false;
}

vector<Hoadon> binarySearchTatCaTheoNgay(const std::vector<Hoadon>& danhSachHoaDon, const Date& ngayCanTim) {
    vector<Hoadon> ketQua;

    int left = 0;
    int right = listHĐ.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (listHĐ[mid].ngaynhapdon.nam == ngayCanTim.nam &&
            listHĐ[mid].ngaynhapdon.thang == ngayCanTim.thang &&
            listHĐ[mid].ngaynhapdon.ngay == ngayCanTim.ngay) {
            // Nếu tìm thấy, duyệt qua các hóa đơn có cùng ngày và thêm vào danh sách kết quả
            int index = mid;
            while (index >= 0 && soSanhNgay(listHĐ[index].ngaynhapdon, ngayCanTim)) {
                ketQua.push_back(listHĐ[index]);
                index--;
            }
            index = mid + 1;
            while (index < listHĐ.size() && soSanhNgay(ngayCanTim, listHĐ[index].ngaynhapdon)) {
                ketQua.push_back(listHĐ[index]);
                index++;
            }
            break; // Kết thúc vòng lặp vì đã tìm thấy và duyệt xong
        } else if (compareDate(listHĐ[mid].ngaynhapdon, ngayCanTim)) {
            left = mid + 1; // Tìm ở bên phải mid
        } else {
            right = mid - 1; // Tìm ở bên trái mid
        }
    }

    return ketQua;
}
void tinhDSMotNgay(){
    Date d;
    char temp[50];
    cout <<"Nhap ngay thang nam (dd/mm/yy): ";
    cin.getline(temp,50);
    getNgayThangNam(temp,d);
    double tongtien  = 0;
    vector<Hoadon> hd = binarySearchTatCaTheoNgay( listHĐ, d);
    for(int i=0; i < hd.size();i++){
        if(hd[i].daTT==1)
        tongtien+= hd[i].tongHD;
    }
    cout <<  "Tong doanh so trong ngay la: " << tongtien*1000 << " dong" << endl;

}


int find_vitri_maMH(string maMH){
    mergeSort(listMH, 0, nMathang-1);
    int left = 0;
    int right = listMH.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
         int compareResult = compareString(listMH[mid].maMH, maMH);
        if (compareResult==0) {
            return mid; // Tìm thấy mã mặt hàng
        } else if (compareResult < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Không tìm thấy mã mặt hàng
};
/*hoa don*/
int find_vitri_hoadon(string maHD){
    mergeSorthd(listHĐ, 0, listHĐ.size() - 1);
    int left = 0;
    int right = listHĐ.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
         int compareResult = compareString(listHĐ[mid].maHĐ, maHD);
        if (compareResult==0) {
            return mid; // Tìm thấy mã mặt hàng
        } else if (compareResult < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Không tìm thấy mã hóa đơn
};
void themHD(){
    Hoadon hd;
    string date;
    hd.tongHD =0;
    hd.cost=0;
    cout << "Nhap vao ma hoa don: " ; cin>> hd.maHĐ;
    cout << "Nhap vao ngay nhap don (dd/mm/yyyy): "; cin >> date;
    cout << "Nhap vao nguoi nhap don: "; cin >> hd.nguoiNhap;
    cout << "Nhap vao ten khach hang: "; cin >> hd.khachHang;
    cout << "Nhap vao so luong mat hang: "; cin >> hd.soLuongMH;
    cout << "Da thanh toan hay chua? (1:daTT, 0:chuaTT): "; cin >> hd.daTT;
    cout << "Nhap vao danh sanh mat hang: "<< endl;

    for(int i =0 ; i<hd.soLuongMH; i++){
        Mathang mh;
        int soluong;
        cout << "Nhap vao ma mh thu " << i+1 <<": " ; cin >> mh.maMH;
        while(listMH[find_vitri_maMH(mh.maMH)].valid==false){
            cout << "Mat hang nay da het han, nhap vao mat hang khac" << endl;
            cout << "Nhap vao ma mh thu " << i+1 <<": " ; cin >> mh.maMH;
        }
        cout << "Nhap vao so luong mat hang: "; cin >> soluong;

        double temp_1=listMH[find_vitri_maMH(mh.maMH)].giaban;
        double temp_2 = listMH[find_vitri_maMH(mh.maMH)].gianhap;
        hd.tongHD+= double(temp_1*soluong);
        hd.cost+= double(temp_2*soluong);
        hd.dsmh.push_back(mh);
        hd.count_each_mh.push_back(soluong);
        listMH[find_vitri_maMH(mh.maMH)].soluongcon-=soluong;       
    }
    getNgayThangNam(date, hd.ngaynhapdon);
    listHĐ.push_back(hd);
    nHoadon+=1;
};
void xoaHĐtheSHĐ(){
    string maHD;
    cout << "Nhap vao ma hoa don can xoa: "; cin>> maHD;
    int it = find_vitri_hoadon(maHD);
    if(it==-1){
        cout << "Khong tim thay hoa don co ma nhu tren. Nhap lai" << endl;
        return;
    }
    if(listHĐ[it].daTT==1) {
        cout << "Khong the xoa hoa don da thanh toan" << endl;
        return;
    }
    Hoadon hd = listHĐ[it];
    for (int i = 0; i < hd.soLuongMH; i++){
        string mamh = hd.dsmh[i].maMH;
        int index = find_vitri_maMH(mamh);
        listMH[index].soluongcon+= hd.count_each_mh[i];
    }
    if (it < listHĐ.size()) {
        // Dịch chuyển các phần tử phía sau mặt hàng cần xóa lên một vị trí
        for (int itMove = it; itMove != listHĐ.size() - 1; ++itMove) {
            listHĐ[itMove] = listHĐ[itMove+1];
        }
        // Giảm kích thước của vector
        listHĐ.pop_back();
        nHoadon = listHĐ.size();

        std::cout << "Da xoa hoa don co ma: " << maHD<< " khoi danh sach.\n";
    } 
}

void suaHoaDon(){

    string mahd;
    cout <<  "Nhap vao ma hoa don can sua: "; cin >> mahd;
    Hoadon hd= listHĐ[find_vitri_hoadon(mahd)];
    if(hd.daTT == 1){
        cout << "Hoa don da thanh toan, khong the sua!" << endl;
        return;

    }
    char temp[40];
    char c;
    do{
        printf("Ban muon sua ten khach hang(c: co, k: khong): ");
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap ten khach hang: ";
        cin.getline(temp,40);
        strcpy(hd.khachHang,temp);
    }
    do{
        printf("Ban muon sua ngay nhap don(c: co, k: khong): "); 
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap ngay thang nam (dd/mm/yy): ";
        cin.getline(temp,40);
        getNgayThangNam(temp, hd.ngaynhapdon);
    }

    do{
        printf("Ban muon sua nguoi nhap don(c: co, k: khong): ");
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap ten nguoi nhap don: ";
        cin.getline(temp,40);
        strcpy(hd.nguoiNhap,temp);

    }
    do{
        printf("Ban muon sua trang thai da thanh toan hay khong? (c: co, k: khong): ");
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Hoa don da thanh toan hay chua?(1: da thanh toan, 0: chua thanh toan): ";
        cin.getline(temp,40);
        if(temp[0] == '0') hd.daTT = 0;
        else hd.daTT = 1;
        
    }
    do{
        printf("Ban muon sua mathang(c: co, k: khong): ");
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));

    
        
    if(c=='c'){
        cout << "Nhap vao so mat hang: "; cin >> hd.soLuongMH;
        hd.cost=0;
        hd.tongHD=0;
        
        for(int j= 0 ; j < hd.soLuongMH; j++){
            int tempp;
            string tmp;
            cout << "Nhap ma mat hang " << j+1 << ": " ;
            cin >> hd.dsmh[j].maMH;
            
            listMH[find_vitri_maMH(hd.dsmh[j].maMH)].soluongcon+=hd.count_each_mh[j];
            cout << "Nhap so luong mh: ";
            cin >> tempp;
            hd.count_each_mh[j]=tempp;
            listMH[find_vitri_maMH(hd.dsmh[j].maMH)].soluongcon-=hd.count_each_mh[j];
            hd.cost+=  listMH[find_vitri_maMH(hd.dsmh[j].maMH)].gianhap*tempp;
            hd.tongHD +=  listMH[find_vitri_maMH(hd.dsmh[j].maMH)].giaban*tempp;
            cin.ignore();
        }
        

    }
    listHĐ[find_vitri_hoadon(mahd)] = hd;
    cout << "Ban da sua hoa don!" << endl;
}


void xuat1HD (){
    /*docFileHD();*/
    string mahd;
    cout << "Nhap ma hoa don can xuat: "; cin >>mahd;
    Hoadon hd = listHĐ[find_vitri_hoadon(mahd)];
    printf("\t\t\t HOA DON BAN HANG \n");
    printf("Ma HD: "); 
    cout << mahd << endl;
    cout << "Ngay nhap don: "<< hd.ngaynhapdon.ngay <<"/"<< hd.ngaynhapdon.thang<<"/"<< hd.ngaynhapdon.nam <<endl;
    printf("Ten nguoi nhap: %s\n", hd.nguoiNhap);
    printf("Ten khach hang: %s\n", hd.khachHang);
    printf("%10s%30s%20s%20s%20s\n","STT","Ten mat hang", "So luong", "Gia", "Thanh tien");
    
    for(int i =0; i < hd.soLuongMH ; i++){
        double thanhtien = hd.count_each_mh[i]*hd.dsmh[i].giaban;
         cout << setw(10) << right << i+1 ;
         cout << setw(30) << right << hd.dsmh[i].tenMH ;
         cout << setw(20) << right << hd.count_each_mh[i] ;
        printf("%20.2f%20.2f\n",hd.dsmh[i].giaban*1000,thanhtien*1000);
       
    }
    printf("-------------------------------------------------------------------------------------------\n") ;
    cout << "Tong hoa don: " << hd.tongHD*1000<< endl;
}



void xuathd_all(){
    
    printf("\t\t\t HOA DON BAN HANG \n");
    printf("-------------------------------------------------------------------------------------------\n");
  
    printf("%10s%20s%20s%20s%20s%20s%20s\n","MaHD","Tinh trang","Ngay nhap don", "Nguoi nhap", "Khach hang", "Tong hoa don", "Tong lai");
    for (int i = 0; i< nHoadon; i++){
        Hoadon hd= listHĐ[i];
        
        cout << setw(10) << hd.maHĐ;
        if(hd.daTT == 1) cout << "                daTT" ;
        else cout << "              chuaTT";
        cout << "            "<< dateToString(hd.ngaynhapdon);
        
        printf("%20s%20s%20.2f%20.2f\n", hd.nguoiNhap,hd.khachHang,hd.tongHD*1000,1000*(hd.tongHD-hd.cost));
        
        
    }

};
void timhoadontheongay() {
    Date date1, date2;
    string ngay1, ngay2;
    cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
    cin >> ngay1;
    cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
    cin >> ngay2;
    getNgayThangNam(ngay1,date1);
    getNgayThangNam(ngay2, date2);
    while (compareDate(date1, date2)){
        vector<Hoadon> hd= binarySearchTatCaTheoNgay(listHĐ, date1);
        cout << "----------------------------------------------------" << endl;
        if(hd.size()==0) cout << "Ngay " << dateToString(date1) << " khong co hoa don nao "<< endl;
        else {
            cout << "Ngay " << dateToString(date1) << " co cac hoa don la: "<< endl;
            cout << "   MaHD" << "          TongHD" << endl;
            for(int i = 0; i < hd.size(); i++){
                cout <<"  "<< hd[i].maHĐ <<"         "<< hd[i].tongHD <<  endl;
            }
        }
        
        date1.TangNgayThang();
    }
};





void searchOutdate() {
    
    string temp;
    std::time_t t = std::time(nullptr);
    
    // Chuyển đổi thời gian thành cấu trúc tm
    std::tm* time_info = std::localtime(&t);
    
    // Sử dụng stringstream để tạo chuỗi ngày hiện tại
    std::ostringstream oss;
    oss << std::setfill('0') << time_info->tm_mday << '/'
        << std::setw(2) << std::setfill('0') << (time_info->tm_mon + 1) << '/'
        << std::setw(4) <<  (time_info->tm_year + 1900);
    // Lấy chuỗi ngày hiện tại
    std::string current_date = oss.str();
    Date d;
    
    getNgayThangNam(current_date,d);
    vector<Mathang> mh = binarySearchOutDate(listMH, d);
    cout << "Co " << mh.size() << " mat hang da het han" << endl;
    cout << "Danh sach mat hang het han la: \n" ;
    cout << setw(20) << "Ten MH"<< setw(20) << "Nha cung cap"<< setw(10) << "SL con" << setw(15) << "Gia nhap"<< setw(15) << "Gia ban" << setw(15) << "HSD" << endl;
    cout << mh.size() << endl;
    double total = 0;
    for (int i = 0; i < mh.size(); i++){
        mh[i].valid=false;
        string tempp = dateToString(mh[i].date);
        cout << setw(20)<<mh[i].tenMH << setw(20)<<mh[i].NCC << setw(10)<<mh[i].soluongcon << setw(15)<<mh[i].gianhap << setw(15)<<mh[i].giaban << setw(15) << tempp << endl;
        total+=mh[i].gianhap;
    }
    cout << "Tong so tien nhap hang het han la: " << int(total*1000) << " dong"<< endl;
}
/*mặt hàng*/
void themMH() {
    
    Mathang mh;
    string temp;
    cout << "Nhap vao ma mh: " ; cin >> mh.maMH;
    cout << "Nhap vao ten mat hang: " ; cin >> mh.tenMH;
    cout << "Nhap vao ten ncc: "; cin >> mh.NCC;
    cout << "Nhap vao so luong mat hang: "; cin >> mh.soluongcon;
    cout << "Nhap vao gia nhap (nhap den hang nghin VD: 192.500d thi nhap 192.5): "; cin>> mh.gianhap;
    cout << "Nhap vao gia ban: "; cin>> mh.giaban;
    cout << "Nhap vao han su dung (dd/mm/yyyy): "; cin>> temp;
    getNgayThangNam(temp, mh.date);
    listMH.push_back(mh);
    nMathang+=1;
};


void xoaMHtheoma(){
    string maMH;
    cout << "Nhap vao ma mat hang can xoa: "; cin>> maMH;
    int it = find_vitri_maMH(maMH);
    if (it < listMH.size()) {
        // Dịch chuyển các phần tử phía sau mặt hàng cần xóa lên một vị trí
        for (int itMove = it; itMove != listMH.size() - 1; ++itMove) {
            listMH[itMove] = listMH[itMove+1];
        }

        // Giảm kích thước của vector
        listMH.pop_back();
        nMathang = listMH.size();
        std::cout << "Da xoa mat hang co ma: " << listMH[it].maMH << " khoi danh sach.\n";
    } 
};
void timKiemMH(){
    string maMH;
    cout << "Nhap vao ma mat hang can tim: "; cin>> maMH;
    int it = find_vitri_maMH(maMH);
    if (it == -1){
        cout << "Khong tim thay mat hang co ma " << maMH << endl;
        return;
    }
    string temp = dateToString(listMH[it].date);
    cout << "Thong tin mat hang co ma: " << maMH << endl;
    cout << setw(20) << "Ten MH"<< setw(20) << "Nha cung cap"<< setw(10) << "SL con" << setw(15) << "Gia nhap"<< setw(15) << "Gia ban" << setw(15) << "HSD" << endl;
    cout << setw(20)<<listMH[it].tenMH << setw(20)<<listMH[it].NCC << setw(10)<<listMH[it].soluongcon << setw(15)<<listMH[it].gianhap << setw(15)<<listMH[it].giaban << setw(15) << temp << endl;
}
void suaMH(){
    string mamh;
    cout <<  "Nhap vao ma mat hang can sua: "; cin >> mamh;
    if(find_vitri_maMH(mamh)==-1){
        cout << "Khong ton tai mat hang co ma nhu tren!" ;
        return;
    }
    Mathang mh= listMH[find_vitri_maMH(mamh)];
    char temp[40];
    char c;
    
    do{
        printf("Ban muon sua ten mat hang khong? (c: co, k: khong): "); 
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap ten mat hang: ";
        cin >> mh.tenMH;
    }
    do{
        printf("Ban muon sua ten ncc khong? (c: co, k: khong): "); 
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap ten nha cung cap: ";
        cin >> mh.NCC;
    }
    do{
        printf("Ban muon sua so hang con trong kho khong? (c: co, k: khong): "); 
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap so hang con trong kho: ";
        cin >> mh.soluongcon;
    }

    do{
        printf("Ban muon sua gia nhap? (c: co, k: khong): ");
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap gia nhap vao: ";
        cin >> mh.gianhap;

    }
     do{
        printf("Ban muon sua gia ban? (c: co, k: khong): ");
        cin.getline(temp,40);
        c=temp[0];
    }
    while(!(c=='c' || c=='k'));
    if(c=='c'){
        cout << "Nhap gia ban ra: ";
        cin >> mh.giaban;

    }
    
    listMH[find_vitri_maMH(mamh)] = mh;
    cout << "Ban da sua mat hang!" << endl;
}

void mergeTen(vector<Mathang>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<Mathang> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (R[j] > L[i]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortTen(vector<Mathang>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortTen(arr, l, m);
        mergeSortTen(arr, m + 1, r);

        mergeTen(arr, l, m, r);
    }
}
bool isSubstring(const std::string& subStr, const std::string& str) {
    if(subStr.length() > str.length()) return false;
   if (subStr.empty()) {
        return true; // Chuỗi rỗng luôn là chuỗi con của mọi chuỗi
    }

    // Lặp qua từng vị trí trong chuỗi lớn
    for (size_t i = 0; i <= str.length() - subStr.length(); i++) {
        // Kiểm tra từng ký tự của chuỗi con
        size_t j;
        for (j = 0; j < subStr.length(); j++) {
            if ( tolower(str[i + j]) != tolower(subStr[j]) ){
                break; // Nếu có ký tự khác nhau, thoát khỏi vòng lặp
            }
        }

        // Nếu đã kiểm tra qua toàn bộ chuỗi con mà không có khác nhau, trả về true
        if (j == subStr.length()) {
            return true;
        }
    }

    // Nếu không tìm thấy chuỗi con
    return false;
}


vector<Mathang> binarySearchMh(const std::vector<Mathang>& arr, const std::string& key) {
    vector<Mathang> ketqua;
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isSubstring(key,arr[mid].tenMH )) {
            // Nếu tìm thấy, duyệt qua các hóa đơn có cùng ngày và thêm vào danh sách kết quả
            int index = mid;
            while (index >= 0 && isSubstring(key,listMH[index].tenMH )) {
                ketqua.push_back(listMH[index]);
                index--;
            }
            index = mid + 1;
            while (index < listMH.size() && isSubstring(key,listMH[index].tenMH)) {
                ketqua.push_back(listMH[index]);
                index++;
            }
            break; // Kết thúc vòng lặp vì đã tìm thấy và duyệt xong
        } else if (listMH[mid].tenMH < key) {
            left = mid + 1; // Tìm ở bên phải mid
        } else {
            right = mid - 1; // Tìm ở bên trái mid
        }
    }
    return ketqua;
    
}
void luuFileMHtheoTen(){
    ofstream out;
    out.open("C:\\Users\\Administrator\\Downloads\\randomfile.txt");
    out << nMathang << endl;
    mergeSortTen(listMH, 0, listMH.size() - 1);
    for(int i =0; i < nMathang; i++){
       // out << "------------------------------------" << endl;
        out << i+1 << " ";
        out << listMH[i].maMH  << " ";
        out << listMH[i].tenMH << " ";
        out << listMH[i].NCC << " ";
        out << listMH[i].soluongcon  << " ";
        out << listMH[i].gianhap  << " ";
        out << listMH[i].giaban << endl;
    }
    out.close();
}
void timmathangtheoten(){
    string temp;
    cout << "Nhap vao ten goi y: ";
    cin >> temp;
    vector<Mathang> mh = binarySearchMh(listMH, temp);
    if (mh.size()==0) cout << "khong co mat hang nao!" << endl;
    else {
        cout << "Co " << mh.size() << " ket qua tim thay" << endl;
        cout << "Ds mat hang co chu " << temp << " trong ten la:" << endl;
        cout << "     MaMH" << "            TenMH" << "         NCC" << "                Gia ban" << endl;
        for(int i = 0; i < mh.size();i++){
            cout <<"   " <<mh[i].maMH << "        " << mh[i].tenMH <<"    "<< mh[i].NCC << "            " <<mh[i].giaban << endl;
        }
    }
    
}


void timmhtheokhoanggiaban(){
    double from, to;
    cout << "Nhap vao khoang gia (den nghin dong): " << endl;
    cout << "Tu: "; cin >> from;
    cout << "Den: "; cin >> to;
    cout << "Danh sach mat hang: " << endl;
    cout << "     MaMH" << "            TenMH" << "         NCC" << "                Gia ban" << endl;
    for(int i = 0; i < nMathang; i ++){
        if(listMH[i].giaban >= from  && listMH[i].giaban <=to)
        cout <<"   " <<listMH[i].maMH << "        " << listMH[i].tenMH <<"    "<< listMH[i].NCC << "            " <<listMH[i].giaban << endl;   
    }
}
/*Menu*/
void Menu(){
    cout << "*********************************************\n";
    cout << "**      CHUONG TRINH QUAN LY BAN HANG      **\n";
    cout << "**         1.Quan ly mat hang              **\n";
    cout << "**         2.Quan ly hoa don               **\n";
    cout << "**         3.Thong ke                      **\n";
    cout << "**         0.Thoat                         **\n";
    cout << "*********************************************\n";
    cout << "**       Nhap lua chon cua ban:            **\n";

}
void MenuQLMH(){
    cout << "*********************************************\n";
    cout << "**       MENU QUAN LY MAT HANG             **\n";
    cout << "**         1.Them mat hang moi             **\n";
    cout << "**         2.Sua mat hang                  **\n";
    cout << "**         3.Xoa mat hang                  **\n";
    cout << "**         4.Tim kiem mat hang theo ma     **\n";
    cout << "**         5.Tim kiem mat hang theo ten    **\n";
    cout << "**         6.Tim kiem tren khoang gia ban  **\n";
    cout << "**         7.Tim kiem mat hang het han     **\n";
    cout << "**         0.Thoat                         **\n";
    cout << "*********************************************\n";
    cout << "**       Nhap lua chon cua ban:            **\n";

}

void MenuQLHĐ(){
    cout << "*********************************************\n";
    cout << "**       MENU QUAN LY HOA DON                    **\n";
    cout << "**         1.Them hoa don                        **\n";
    cout << "**         2.Sua hoa don                         **\n";
    cout << "**         3.Xoa hoa don                         **\n";
    cout << "**         4.Xuat hoa don theo ma                **\n";
    cout << "**         5.Tim kiem hoa don theo khoang ngay   **\n";
    cout << "**         6.Liet ke tat ca hoa don              **\n";
    cout << "**         0.Thoat                               **\n";
    cout << "***************************************************\n";
    cout << "**       Nhap lua chon cua ban:                  **\n";
}
void MenuThongKe(){
    cout << "**********************************************************\n";
    cout << "**          MENU THONG KE                               **\n";
    cout << "**         1.Tinh doanh so trong 1 ngay                 **\n";
    cout << "**         2.Bao cao mat hang ban duoc trong thang      **\n";
    cout << "**         0.Thoat                                      **\n";
    cout << "**********************************************************\n";
    cout << "**       Nhap lua chon cua ban:                         **\n";
}

int main(){


    docFileMH();
    luuFileMH();
    docFileHD();
    luuFileHD();
    int choice;
    do{
    Menu();
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int luachon = 0;
        do{
            MenuQLMH();
            cin >> luachon;
            getchar();
            switch (luachon)
            {
            case 1:{
                luuFileMH();
                themMH();
                luuFileMH();
                break;

            }
            case 2:{
                luuFileMH();
                suaMH();
                luuFileMH();
                break;
            }
            case 3: {
                luuFileMH();
                xoaMHtheoma();
                luuFileMH();
                break;
            }
            case 4: {
                luuFileMH();
                timKiemMH(); 
                break;
            }
            case 5: {
                luuFileMHtheoTen();
                timmathangtheoten(); 
                break;
            }
            case 6: {
                luuFileMH();
                timmhtheokhoanggiaban(); 
                break;
            }
            case 7: {
                luuFileMH();
                mergeSortdate(listMH, 0 , nMathang-1);
                searchOutdate(); 
                luuFileMH();
                break;
            }
            case 0: {
                cout << "Ban chon thoat\n";
                cout << "Nhan phim bat ky de thoat\n";
                system("pause");
                break;
            }
                
            default:
                break;
            }
           
            

        }
        while (luachon!=0);
        break;
    }
       
    case 2:
    {
        int luachon = 0;
        do{
            MenuQLHĐ();
            cin >> luachon;
            getchar();
            switch (luachon)
            {
            case 1:{
                luuFileHD();
                themHD();
                luuFileMH();
                luuFileHD();
                break;

            }
            case 2:{
                luuFileHD();
                suaHoaDon();
                luuFileMH();
                luuFileHD();
                break;
            }
            case 3: {
                luuFileHD();
                xoaHĐtheSHĐ();
                luuFileMH();
                luuFileHD();
                break;
            }
            case 4: {
                luuFileHD();
                
                xuat1HD();
                
                
                break;
            }
            case 5: {
                
                timhoadontheongay();
                break;
            }
            case 6: {
                luuFileHD();
                xuathd_all();
                break;
            }
            case 0: {
                cout << "Ban chon thoat\n";
                cout << "Nhan phi bat ky de thoat\n";
                system("pause");
                break;
            }
                
            default:
                break;
            }
           
            

        }
        while (luachon!=0);
        break;
    }
    case 3:
    {
        int luachon = 0;
        do{
            MenuThongKe();
            cin >> luachon;
            getchar();
            switch (luachon)
            {
            case 1:{
                tinhDSMotNgay();
                break;

            }
            case 2:{
                baoCaoMHtrongThang();
                break;
            }
            case 0: {
                cout << "Ban chon thoat\n";
                cout << "Nhan phi bat ky de thoat\n";
                system("pause");
                break;
            }
                
            default:
                break;
            }
           
            

        }
        while (luachon!=0);
        break;
    }
    case 0:{
        cout << "Ban chon thoat chuong trinh\n";
        cout << "Nhan phim bat ky de thoat\n";
        system("pause");
        break;
    }
    default:
        break;
    }
    }while (choice!=0);
   
    
}