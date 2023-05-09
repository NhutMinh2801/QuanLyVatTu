#pragma once
#include "HoaDon.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int trungay(Date t1, Date t2) {
        if (t1.thang < 3) {
            t1.nam--;
            t1.thang += 12;
        }
        if (t2.thang < 3) {
            t2.nam--;
            t2.thang += 12;
        }
        return 365*t1.nam + t1.nam/4 - t1.nam/100 + t1.nam/400 + (153*t1.thang - 457)/5 + t1.ngay - 306
		     -(365*t2.nam + t2.nam/4 - t2.nam/100 + t2.nam/400 + (153*t2.thang - 457)/5 + t2.ngay - 306);
    }
int ngay(int year, int month, int day) {
        if (month < 3) {
            year--;
            month += 12;
        }
        return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
    }

//Khoi tao danh sach mang con tro
void khoiTaoDanhSachNhanVien(DS_NhanVien &ds)
{
	ds.num =0;
	for(int i=0;i<MaxNV;i++)
	{
		ds.DS[i]=NULL;
	}
}
//Tao Mot nhan vien moi
NhanVien taoNhanVien(int MANV,char Ho[],char Ten[],char Phai[])
{
	NhanVien temp;
	temp.MANV=MANV;
	strcpy(temp.Ho,Ho);
	strcpy(temp.Ten,Ten);
	strcpy(temp.Phai,Phai);
	khoiTaoDanhSachHoaDon(temp.list_HD);
	return temp;
}
//Chen NV moi vao danh sach chinh
void themNhanVien(DS_NhanVien &ds, NhanVien data)
{
	ds.DS[ds.num]=new NhanVien;
	*ds.DS[ds.num]=data;
	ds.num++;
	return;
}
//Sua NV theo vi tri
void suaNhanVien(DS_NhanVien &ds, NhanVien data, int vt)
{
	*ds.DS[vt]=data;
	return;
}
//tra ve vi tri cua nhan vien trong ds theo MaNV
int timKiemViTriNhanVien(DS_NhanVien &ds, int MaNV)
{ 
//cout<<" mnv "<<MaNV;
	if(ds.num==0) return -1;
	for(int i=0;i<ds.num;i++)
	{
//		cout<<" duyet r";
		if(ds.DS[i]->MANV==MaNV)
		return i;
	}
	return -1;
}
//Xoa NV khoi ds theo vi tri
void xoaNhanVien(DS_NhanVien &ds, int vt)
{
	if(ds.num==0||vt==-1||vt>=ds.num) return;
	for(int i=vt;i<ds.num;i++)
	{
		ds.DS[i]=ds.DS[i+1];
	}
	ds.DS[ds.num-1]=NULL;
//	delete ds.DS[ds.num-1];
	ds.num--;
	return;
}

void xoaNhanVientheoma(DS_NhanVien &ds, int manv)
{

	for(int i=0;i<ds.num;i++)
	{
	   if(ds.DS[i]->MANV==manv){
	   	for(int j=i;j<ds.num;j++){
	   		ds.DS[j]=ds.DS[j+1];
		   }
	   }
	}
	ds.DS[ds.num-1]=NULL;
//	delete ds.DS[ds.num-1];
	ds.num--;
	return;
}
//Ho tro tao moi NV: Kiem tra xem NV moi nhap co Ma NV hoac CMND da ton tai
bool kiemtratrungnhanvien(DS_NhanVien ds, int MANV)
{
	for(int i=0;i<ds.num;i++)
	{
		if(ds.DS[i]->MANV==MANV)
		{
			return true;
		}
	}
	return false;
}
//Ho tro giao dien: IN thong tn NV ra man hinh
void inNhanVien(NhanVien data,int x, int y)
{
   char  cMNV[16]="";
   char HoTen[40]="";
   strcpy(HoTen,data.Ho);
   strcat(HoTen," ");
   strcat(HoTen,data.Ten);
   itoa(data.MANV,cMNV,10);
  
   outtextxy(x+65,y,cMNV);
   outtextxy(x+65+200,y,HoTen);
   outtextxy(x+65+200+500,y,data.Phai); 
}
//Ghi Danh Sach NV vao file txt
void ghiNhanVienVaoFile(char tenfile[], DS_NhanVien &dsNhanVien){
	fstream f;
	f.open(tenfile, ios::out);
	f<<dsNhanVien.num<<endl;
	for(int i=0; i<dsNhanVien.num; i++){
		f<<dsNhanVien.DS[i]->MANV<<endl;
		f<<dsNhanVien.DS[i]->Ho<<endl;
		f<<dsNhanVien.DS[i]->Ten<<endl;
		f<<dsNhanVien.DS[i]->Phai<<endl;
		f<<dsNhanVien.DS[i]->list_HD.n<<endl;
		NodeHoaDon *hoaDon = dsNhanVien.DS[i]->list_HD.pHead;
		while(hoaDon!=NULL){
			f<<hoaDon->data.SoHD<<endl;
			f<<hoaDon->data.NgayLap.ngay<<endl;
			f<<hoaDon->data.NgayLap.thang<<endl;
			f<<hoaDon->data.NgayLap.nam<<endl;
			f<<hoaDon->data.NgayLap.sgiay<<endl;
			f<<hoaDon->data.Loai<<endl;
			f<<hoaDon->data.ct.num<<endl;
		for(int ct=0;ct<hoaDon->data.ct.num;ct++){
				f<<hoaDon->data.ct.dsChitiet[ct].MAVT<<endl;
				f<<hoaDon->data.ct.dsChitiet[ct].SL<<endl;
				f<<hoaDon->data.ct.dsChitiet[ct].DonGia<<endl;
				f<<hoaDon->data.ct.dsChitiet[ct].VAT<<endl;
		}
		
			hoaDon = hoaDon->pnext;
		}
	}
	
	f.close();
}
//Doc thong tin txt vao DSNV
void docNhanVienTuFile(char tenfile[], DS_NhanVien &dsNhanVien){
	fstream f;
	f.open(tenfile, ios::in);
	
	int n=0;
	f>>n;
	f.ignore();
	NhanVien tamNhanVien;
	for(int i=0; i<n; i++){
		f>>tamNhanVien.MANV;
		f.ignore();
		f.getline(tamNhanVien.Ho, sizeof(tamNhanVien.Ho), '\n');
		cout<<tamNhanVien.Ho;
		f.getline(tamNhanVien.Ten, sizeof(tamNhanVien.Ten), '\n');
		cout<<tamNhanVien.Ten;
		f.getline(tamNhanVien.Phai, sizeof(tamNhanVien.Phai), '\n');
		khoiTaoDanhSachHoaDon(tamNhanVien.list_HD);
		themNhanVien(dsNhanVien, tamNhanVien);
		int HDn=0;
		f>>HDn;
		f.ignore();
		HoaDon tamHoaDon;
		for(int j=0; j<HDn; j++){
			f.getline(tamHoaDon.SoHD, sizeof(tamHoaDon.SoHD), '\n');
			cout<<endl<<"/"<<tamHoaDon.SoHD<<"/"<<endl;
			f>>tamHoaDon.NgayLap.ngay;
			f.ignore();
			f>>tamHoaDon.NgayLap.thang;
			f.ignore();
			f>>tamHoaDon.NgayLap.nam;
			f.ignore();
			f>>tamHoaDon.NgayLap.sgiay;
			f.ignore();
			f>>tamHoaDon.Loai;
			f.ignore();
			khoiTaoDanhSachChiTietHoaDon(tamHoaDon.ct);
			int nCTHD;
			f>>nCTHD;
			f.ignore();
			ChiTietHoaDon ctHD;
			for(int j=0; j<nCTHD; j++){
				f.getline(ctHD.MAVT, sizeof(ctHD.MAVT), '\n');
				f>>ctHD.SL;
				f.ignore();
				f>>ctHD.DonGia;
				f.ignore();
				f>>ctHD.VAT;
				f.ignore();
				themChiTietHoaDon(tamHoaDon.ct,ctHD);
			}
			
			themHoaDon(dsNhanVien.DS[dsNhanVien.num-1]->list_HD, tamHoaDon);

		}
	}
	
	f.close();
}
//Ho giao dien: IN DSNV ra man hinh
void inDSNhanVien(DS_NhanVien &ds, int x, int y, int trang)
{
	if(ds.num==0)
	return;
	for(int i=0;i<ds.num;i++)
	{
		for(int j=0;j<ds.num;j++)
		{
			if(strcmp(ds.DS[i]->Ten,ds.DS[j]->Ten)<0)
			{
				NhanVien *tam=ds.DS[i];
				ds.DS[i]=ds.DS[j];
				ds.DS[j]=tam;
			}
			if(strcmp(ds.DS[i]->Ten,ds.DS[j]->Ten)==0)
			{
				if(strcmp(ds.DS[i]->Ho,ds.DS[j]->Ho)<0)
				{
				NhanVien *tam=ds.DS[i];
				ds.DS[i]=ds.DS[j];
				ds.DS[j]=tam;
				}
				
			}
			
		}
	}
	for(int i=0;i<10;i++)
	{
		if((trang-1)*10+i>=ds.num)
		return;
		inNhanVien(*ds.DS[(trang-1)*10+i],x,y);
		y=y+32;
	}
}
//Tim nv theo ma NV
NhanVien *timNhanVien(DS_NhanVien dsNhanVien, int MANV){
	for(int i=0; i<dsNhanVien.num; i++){
			cout<<"\n tim :"<<MANV<<"/"<<dsNhanVien.DS[i]->MANV;
		if(dsNhanVien.DS[i]->MANV==MANV) 
		return dsNhanVien.DS[i];
	}
	return NULL;
}
//Tim xem HD nao do co ton tai hay chua
NodeHoaDon *timTatCaHoaDon(DS_NhanVien &dsNhanVien, char SOHD[], NhanVien &nhanVien){
	for(int i=0; i<dsNhanVien.num; i++){
		NodeHoaDon *tmp = dsNhanVien.DS[i]->list_HD.pHead;
		while(tmp!=NULL){
			if(strcmp(tmp->data.SoHD, SOHD)==0){
				nhanVien = *dsNhanVien.DS[i];
				return tmp;
			}
			tmp=tmp->pnext;
		}
	}
	return NULL;
}
//Tim xem VT da ton tai trong cac hoa don hay chua
bool timTatCaVatTu(DS_NhanVien &dsNhanVien, char MaVT[]){
	for(int i=0; i<dsNhanVien.num; i++){
		NodeHoaDon *tmp = dsNhanVien.DS[i]->list_HD.pHead;
		while(tmp!=NULL){
			for(int j=0;j<tmp->data.ct.num;j++){
				if(strcmp(tmp->data.ct.dsChitiet[j].MAVT, MaVT)==0){
					return true;
				}
			}
//			NodeChiTiet *nodeCT = tmp->data.ct.first;
//			while(nodeCT!=NULL){
//				
//				nodeCT = nodeCT->next;
		//	}
			tmp=tmp->pnext;
		}
	}
	return false;
}
//Ho tro giao dien
void inhoadon(NodeHoaDon *n, int x, int y){
	
}


void inDSHoaDonTrongNhanVien(int x, int &y, NhanVien nv, CayVatTu t, Date t1, Date t2, int &dem, int trang)
{
	
	for(NodeHoaDon *k=nv.list_HD.pHead;k!=NULL;k=k->pnext)
	{
		if(ngay(t2.nam,t2.thang,t2.ngay)>=ngay(k->data.NgayLap.nam,k->data.NgayLap.thang,k->data.NgayLap.ngay)&&ngay(t1.nam,t1.thang,t1.ngay)<=ngay(k->data.NgayLap.nam,k->data.NgayLap.thang,k->data.NgayLap.ngay))
		{
		if((trang-1)*10<=dem&&dem<trang*10){
	dem++;
			
		outtextxy(x+70,y,k->data.SoHD);
			
	char ngay[15]="", ng[10]="";
	itoa(k->data.NgayLap.ngay,ngay,10);
	strcat(ngay,"/");
	itoa(k->data.NgayLap.thang,ng,10);
	strcat(ngay,ng);
	strcat(ngay,"/");
	itoa(k->data.NgayLap.nam,ng,10);
	strcat(ngay,ng);
	outtextxy(x+70+120,y,ngay);
	char lo[2]="";
	lo[0]=k->data.Loai;
		outtextxy(x+70+120+200,y,lo);
	char hoten[50]="";
	strcat(hoten,nv.Ho);
	strcat(hoten," ");
	strcat(hoten,nv.Ten);
	outtextxy(x+70+120+200+80,y,hoten);
	char ctong[20]=""; 
int tong =0;
tong=tinhtonghoadon(k->data.ct)*1;
 //doiSangChuoi(trigia1, tong*1.0);
  itoa(tong*1,ctong,10);
 cout<<" tri gia"<<ctong;
 
outtextxy(x+70+120+200+80+390,y,ctong);
           y=y+32;}
		}
		
	}

}
void intoanbohoadon(int x, int y, CayVatTu t,DS_NhanVien dsnv, Date t1, Date t2, int trang){
	int dem =0;
	
	for(int i=0; i<dsnv.num;i++){
		inDSHoaDonTrongNhanVien(x,y,*dsnv.DS[i],t,t1,t2,dem,trang);
	}
}
