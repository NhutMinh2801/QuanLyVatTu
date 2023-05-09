#pragma once
#include <iostream>

const int MaxNV =500;
struct Date{
	int ngay;
	int thang;
	int nam;
	int sgiay;
};
struct VatTu{
	char MAVT[10]="";
	char TENVT[50]="";
	char DVT[20]="";
	float ton;
};

struct NodeVatTu{
	VatTu vatTu;
	NodeVatTu *left=NULL;
	NodeVatTu *right=NULL;
};

struct CayVatTu{
	NodeVatTu *root=NULL;
	int soluong=0;
};

struct ChiTietHoaDon{
	char MAVT[10];
	float SL;
	float DonGia;
	float VAT;
};

struct DanhSachChiTietHoaDon{
	int num=0;
	ChiTietHoaDon dsChitiet[20];
};
struct HoaDon{
	char SoHD[20];
	Date NgayLap;
	char Loai;
	DanhSachChiTietHoaDon ct;
};
struct NodeHoaDon{
	HoaDon data;
	NodeHoaDon *pnext;
};
struct DanhSachHoaDon{
	NodeHoaDon *pHead;
	NodeHoaDon *pTail;
	int n=0;
};


struct NhanVien{
	int MANV;
	char Ho[30];
	char Ten[20];
	char Phai[4];
	DanhSachHoaDon list_HD;
};
struct DS_NhanVien{
	int num;
	NhanVien *DS[MaxNV];
};

