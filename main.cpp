#include "run.h"
#include "CauTruc.h"
int main(int argc, char *argv[])
{
	initwindow(1360, 690);			// init window graphics
	setbkcolor(1);					// set background
   	cleardevice();
	setcolor(14);					// set text color
 run();
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
//#include<iostream>
//
////#include "run.h"
//using namespace std;
//
//VatTu taoVatTu(char MaVT[], char TenVT[], char DVT[], float ton);
//NodeVatTu *taoNodeVatTu(VatTu vatTu);
//void themNodeVaoCay(CayVatTu &cayVatTu, NodeVatTu *nodeVatTu);
//NodeVatTu *timKiemVatTu(CayVatTu cayVatTu, char MaVT[]);
//void hieuChinhVatTuTheoMa(CayVatTu &cayVatTu, char MaVT[], char TenVTMoi[], char DVTMoi[]);
//void xoaNodeKhoiCayTheoMa(CayVatTu &cayVatTu, char MaVT[]);
//void deQuyXoaNode(NodeVatTu *node);
//void xoaToanBoCay(CayVatTu &cayVatTu);
//void duyetNodeGhiVaoFile(fstream &f, NodeVatTu *node);
//void ghiVatTuVaoFile(char tenfile[], CayVatTu cayVatTu);
//void docVatTuTuFile(char tenfile[], CayVatTu &cayVatTu);
//void duyetNode(NodeVatTu *node, VatTu *vt, int &i);
//void doCayVaoMangVatTu(VatTu *&vt, CayVatTu cayVatTu);
//float doiSangFloat(char ch[]);
//void doiSangChuoi(char soTon[], float nFloat);
//void inVatTu(VatTu data,int x, int y);
//void inDSVatTu(VatTu *vt, int size, int x, int y, int trang);
//void layThongTinVatTu(VatTu *vt, int i, int trang, int size, char MAVT[], char TENVT[], char DVT[], char chrFloat[], float &nfloat);
//
//void khoiTaoDanhSachChiTietHoaDon(DanhSachChiTietHoaDon &ds);
//ChiTietHoaDon chiTietHoaDon(char MAVT[],float SL,float DonGia,float VAT,bool TrangThai);
//NodeChiTiet *nodeChiTiet(ChiTietHoaDon ct);
//void themChiTietHoaDon(DanhSachChiTietHoaDon &ds, ChiTietHoaDon data);
//void suaThongTinChiTietHoaDon(DanhSachChiTietHoaDon &ds,char MAVT[], bool TT);
//void xoaMotChiTietHoaDon(DanhSachChiTietHoaDon &ds, char MAVT[]);
//ChiTietHoaDon *danhSachTuyenTinhChiTiet(DanhSachChiTietHoaDon &ds, int &n);
//void inChiTietHoaDon(ChiTietHoaDon data,char TenVatTu[], int x, int y);
//void inDSChiTietHoaDon(DanhSachChiTietHoaDon dsCTHD, CayVatTu root, ChiTietHoaDon *&mangTam, int &n, int x, int y);
//float doiSangFloat(char ch[]);
//void doiSangChuoi(char soTon[], float nFloat);
//void layThongTinMotChiTietHoaDon(ChiTietHoaDon *dsCTHD, CayVatTu root, int vitri, int size, char MAVT[], char chrSL[], char chrDonGia[], char chrVAT[]);
//
//void khoiTaoDanhSachHoaDon(DanhSachHoaDon &ds);
//HoaDon taoHoaDon(char SoHD[],Date NgayLap, char Loai);
//NodeHoaDon *taoNodeHoaDon(HoaDon data);
//void themHoaDon(DanhSachHoaDon &ds, HoaDon data);
//void xoaHoaDon(DanhSachHoaDon &ds, char SoHD[]);
//NodeHoaDon *timHoaDon(DanhSachHoaDon &list, char SOHD[]);
//void doDSLKVaoMang(DanhSachHoaDon &list, HoaDon *&hoaDon);
//Date GetNow(char chrDate[]);
//Date chuyenchuoithoigian(char s[]);
//void inDSChiTietTrongHoaDon(HoaDon data,CayVatTu t,int &x, int &y,int &dem);
//
//void khoiTaoDanhSachNhanVien(DS_NhanVien &ds);
//NhanVien taoNhanVien(int MANV,char Ho[],char Ten[],char Phai[],char CMND[]);
//void themNhanVien(DS_NhanVien &ds, NhanVien data);
//void suaNhanVien(DS_NhanVien &ds, NhanVien data, int vt);
//int timKiemViTriNhanVien(DS_NhanVien &ds, int MaNV);
//void xoaNhanVien(DS_NhanVien &ds, int vt);
//bool kiemtratrungnhanvien(DS_NhanVien ds, char CMND[13],int MANV);
//void inNhanVien(NhanVien data,int x, int y);
//void ghiNhanVienVaoFile(char tenfile[], DS_NhanVien &dsNhanVien);
//void docNhanVienTuFile(char tenfile[], DS_NhanVien &dsNhanVien);
//void inDSNhanVien(DS_NhanVien &ds, int x, int y, int trang);
//NhanVien *timNhanVien(DS_NhanVien &dsNhanVien, int MANV);
//NodeHoaDon *timTatCaHoaDon(DS_NhanVien &dsNhanVien, char SOHD[], NhanVien &nhanVien);
//bool timTatCaVatTu(DS_NhanVien &dsNhanVien, char MaVT[]);
//void inDSHoaDonTrongNhanVien(int x, int y, NhanVien nv, CayVatTu t, Date t1, Date t2);
//

//void gdnhapvattu();
//void bangvattu(int trang);
//void gdnhapnhanvien();
//void bangnhanvien(int trang);
//void gdhoahon();
//void banghoadon();
//void gdthongke();
//void gdthongke_NV();
//void bangthongke_hdnv(int trang);
//void gdthongke_doanhthu();
//void bangthongkedoanhthu();
//
//void gotoxy(short x,short y);
////int wherex( void );
////int wherey( void );
////void clreol( );
////void SetColor(WORD color);
////void SetBGColor(WORD color);
////void clrscr();
//void outtextxy1(int x, int y, char str[]);
//void outtextxy(int x, int y, char c);
//void trodichuyen( int &X, int &Y, int &key, int MID[][70], char hd);
//void trodichuyentraiphai( int &X, int &Y, int &key, int MID[][70], char hd);
//void trodichuyenlenxuong( int &X, int &Y, int &key, int MID[][70], char hd);
//void DelScreeen(int x, int y, int cd, int cr);
//void rectangle(int x, int y, int m, int n, int mau,int kieu);
//void button(int x, int y,int ID, int cd, int cr, int color,int colorw, char str[],int MID[][70]);
//void taoo(int x, int y, int cd, int cr, int ID,int MID[][70]);
//void taodong(int x, int y,int m[],int cr, int sc,int ID,int MID[][70]);
//void bangcoSTT( int x, int y, int m[], char td[][30],int sh, int sc,int cr,int ID,int MID[][70]);
//void bangKcoSTT(int x, int y, int m[], char td[][30],int sh, int sc,int cr,int ID,int MID[][70]);
//void ScannerString(char s[],int max, int px ,int py,int ID,int &IDnext, int &xn, int &yn);
//void Scannerdate(char s[],int max, int px ,int py,int ID,int &IDnext, int &xn, int &yn);
//void nutchucnang(int loai);
//bool buocdem(int &x, int &y, int &key, int cn);
//bool buocdem1(int &x, int &y, int &key, int cn);
//int trungay(Date t1, Date t2);
//int ngay(int year, int month, int day);
//
//void laythongtinnhanvien(DS_NhanVien ds, int vt, char cMNV[],char Ho[],char Ten[],char Phai[],char CMND[]);
//void run();
//
//int main()
//{	
//run();
//
//return 0;
//}
