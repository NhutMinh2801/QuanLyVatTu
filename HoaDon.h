#pragma once
#include "CT_HoaDon.h"
#include <ctime>
//#include "VatTu.h"
using namespace std;


//Khoi tao DSLK
void khoiTaoDanhSachHoaDon(DanhSachHoaDon &ds)
{
	ds.pHead=ds.pTail=NULL;
}
//Tao thong tin mot hoa don moi
HoaDon taoHoaDon(char SoHD[],Date NgayLap, char Loai)
{
	HoaDon temp;
	strcpy(temp.SoHD,SoHD);
	temp.NgayLap=NgayLap;
    temp.Loai=Loai;
    khoiTaoDanhSachChiTietHoaDon(temp.ct);
    return temp;
}
//Tao mot node hoa don
NodeHoaDon *taoNodeHoaDon(HoaDon data)
{
	NodeHoaDon *p =new NodeHoaDon;
	p->data=data;
	p->pnext=NULL;
	return p;
}
//chen node HD moi vao DSLK don chinh
void themHoaDon(DanhSachHoaDon &ds, HoaDon data)
{
	NodeHoaDon *p=taoNodeHoaDon(data);
	if(ds.pHead==NULL)
	{
		ds.pHead=p;
		ds.pTail=p;
	}
	else
	{
		ds.pTail->pnext=p;
		ds.pTail=p;
	}
	ds.n++;
}
void themvattuvaohoadon(DanhSachHoaDon &ds, char *mahd, ChiTietHoaDon data){
	for(NodeHoaDon *p = ds.pHead; p!=NULL;p=p->pnext ){
		if(strcmp(p->data.SoHD,mahd)==0){
			themChiTietHoaDon(p->data.ct,data);
			return;
		}
	}
}
//xoa node (hoa don) khoi dslk don 
void xoaHoaDon(DanhSachHoaDon &ds, char SoHD[])
{
	if(ds.pHead==NULL)
	return;
	if(strcmp(ds.pHead->data.SoHD,SoHD)==0)
	{
			NodeHoaDon *t=ds.pHead;
			ds.pHead=t->pnext;
			delete t;
			ds.n--;
			return;
	}
	if(strcmp(ds.pTail->data.SoHD,SoHD)==0)
	{
			NodeHoaDon *t=ds.pTail;
			for(NodeHoaDon *k=ds.pHead;k!=NULL;k=k->pnext)
			{
		       if(k->pnext->pnext==NULL)
		       {
		       	ds.pTail=k;
		       	delete t;
		       	ds.n--;
		       	return;
			   }
	    	}
	}
			
			
	for(NodeHoaDon *k=ds.pHead;k!=NULL;k=k->pnext)
	{
		if(strcmp(k->data.SoHD,SoHD)==0)
		{
			NodeHoaDon *t=k->pnext;
			k->data=k->pnext->data;
			k->pnext=k->pnext->pnext;
			delete t;
			ds.n--;
			return;
		}
	}
	return;
}
//Tim HD theo so HD
NodeHoaDon *timHoaDon(DanhSachHoaDon &list, char SOHD[]){
	NodeHoaDon *tmp = list.pHead;
	while(tmp!=NULL){
		if(strcmp(tmp->data.SoHD, SOHD)) return tmp;
		tmp=tmp->pnext;
	}
	return NULL;
}
//Ho tro giao dien
void doDSLKVaoMang(DanhSachHoaDon &list, HoaDon *&hoaDon){
	hoaDon = new HoaDon[list.n];
	NodeHoaDon *tmp = list.pHead;
	int i=0;
	while(tmp!=NULL){
		hoaDon[i] = tmp->data;
		tmp=tmp->pnext;
	}
}
//Lay thoi gian hien tai
Date GetNow(char chrDate[]){
	Date dNow;
	time_t now = time(0);
	dNow.sgiay = now;
 	tm *ltm = localtime(&now);
 	dNow.nam = 1900 + ltm->tm_year;
 	dNow.thang = 1 + ltm->tm_mon;
 	dNow.ngay = ltm->tm_mday;
 	
 	strcpy(chrDate,"");
 	char tmpString[13]="";
 	itoa(dNow.ngay, tmpString, 10);
 	strcpy(chrDate,tmpString);
 	strcat(chrDate,"-");
 	strcpy(tmpString,"");
 	itoa(dNow.thang, tmpString, 10);
 	strcat(chrDate,tmpString);
 	strcat(chrDate,"-");
 	strcpy(tmpString,"");
 	itoa(dNow.nam, tmpString, 10);
 	strcat(chrDate,tmpString);
 	
 	return dNow;
}
//Chuyen tu chuoi thanh ngay thang
Date chuyenchuoithoigian(char s[])
{
	Date time;
	int l= strlen(s);
	time.ngay=(s[0]-48)*10+s[1]-48;
	time.thang=(s[3]-48)*10+s[4]-48;
	time.nam=(s[6]-48)*1000+(s[7]-48)*100+(s[8]-48)*10+s[9]-48;
	time.sgiay=0;
	return time;

}
//Ho tro giao dien
void inDSChiTietTrongHoaDon(HoaDon data,CayVatTu t,int &x, int &y,int &dem)
{

//	NodeChiTiet *nodeCT = data.ct.first;
//	outtextxy(x,y,data.SoHD);
//	char ngay[15]="", ng[10]="";
//	itoa(data.NgayLap.ngay,ngay,10);
//	strcat(ngay,"/");
//	itoa(data.NgayLap.thang,ng,10);
//	strcat(ngay,ng);
//	strcat(ngay,"/");
//	itoa(data.NgayLap.nam,ng,10);
//	strcat(ngay,ng);
//	outtextxy(x+10,y,ngay);
//	outtextxy(x+10+20,y,data.Loai+"");
//	float tong=tinhtonghoadon(nodeCT);
//	doiSangChuoi(ng,tong);
//	outtextxy(x+10+20+10+20+30+20+10+20,y,ng);

}

