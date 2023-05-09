#pragma once
#include<iostream>
#include<string.h>
using namespace std;

//Khoi tao danh sach moi
void khoiTaoDanhSachChiTietHoaDon(DanhSachChiTietHoaDon &ds)
{
	ds.num=0;
	
}
//Tao mot chi tiet HD moi
ChiTietHoaDon chiTietHoaDon(char MAVT[],float SL,float DonGia,float VAT)
{
	ChiTietHoaDon temp;
	strcpy(temp.MAVT,MAVT);
	temp.SL=SL;
	temp.DonGia=DonGia;
	temp.VAT=VAT;
	return temp;
	
}

//chen chi tiet hoa don vao danh sach
void themChiTietHoaDon(DanhSachChiTietHoaDon &ds, ChiTietHoaDon data)
{
if(ds.num>=20) return;
bool kt =false;
for(int i=0;i<ds.num;i++){
	if(strcmp(ds.dsChitiet[i].MAVT,data.MAVT)==0){
		ds.dsChitiet[i].SL+=data.SL;
		return;
	}
}

ds.dsChitiet[ds.num++]= data;
}

//Xoa mot chi tiet VT nao khoi khoi danh sach chi tiet hoa don
void xoaMotChiTietHoaDon(DanhSachChiTietHoaDon &ds, char MAVT[]){
	
for(int i=0;i<ds.num;i++){
	if(strcmp(ds.dsChitiet[i].MAVT,MAVT)==0){
		for(int j=i;j<ds.num;j++){
			ds.dsChitiet[j]=ds.dsChitiet[j+1];
		}
		ds.num--;
	}
	
}
}

//Ho tro giao dien
void inChiTietHoaDon(ChiTietHoaDon data,char TenVatTu[], int x, int y)
{
   char chrSL[7]="", chrDonGia[20]="", chrVAT[7]="";
   doiSangChuoi(chrSL, data.SL);
   doiSangChuoi(chrDonGia, data.DonGia);
   doiSangChuoi(chrVAT, data.VAT);
//   cout<<"Float: "<<chrFloat;
   outtextxy(x+65,y,data.MAVT);
   outtextxy(x+65+100,y,TenVatTu);
   outtextxy(x+65+100+200,y,chrSL);
   outtextxy(x+65+100+200+100,y,chrDonGia);
   outtextxy(x+65+100+200+100+200,y,chrVAT);
   
   cout<<endl<<" thong tin chi tiet hoa don :"<<data.MAVT<<"/"<<TenVatTu<<"/"<<chrSL<<"/"<<chrDonGia<<"/"<<chrVAT<<endl;
}
////Ho tro giao dien
void inDSChiTietHoaDon(DanhSachChiTietHoaDon dsCTHD, CayVatTu root,int &n, int x, int y)
{
	cout<<" sl chi tiet"<<dsCTHD.num;
	if(dsCTHD.num==0)
	return;

	for(int i=0;i<10;i++)
	{
		if(i>=dsCTHD.num) return;
		NodeVatTu *tmp = timKiemVatTu(root, dsCTHD.dsChitiet[i].MAVT);
		inChiTietHoaDon(dsCTHD.dsChitiet[i],tmp->vatTu.TENVT,x,y);
		y=y+32;
	}
}

float doiSangFloat(char ch[]);
void doiSangChuoi(char soTon[], float nFloat);
NodeVatTu *TimKiemVatTu(CayVatTu cayVatTu, char MaVT[]);
void layThongTinMotChiTietHoaDon(ChiTietHoaDon dsCTHD[], CayVatTu root, int vitri, int size, char MAVT[], char chrSL[], char chrDonGia[], char chrVAT[]){
	cout<<"vt"<<vitri<<size;
	if(vitri>=size) return;	
	taoo(395,120-30,525+50,152-30,311,15,0);
	
	taoo(680,120-30,1030,152-30,312,15,0);

	taoo(1100,120-30,1330,152-30,313,15,0);

	taoo(445,125,625,157,314,15,0);

	taoo(730,125,930,157,315,15,0);
	strcpy(MAVT, dsCTHD[vitri].MAVT);
	doiSangChuoi(chrSL, dsCTHD[vitri].SL);
	doiSangChuoi(chrDonGia, dsCTHD[vitri].DonGia);
	doiSangChuoi(chrVAT, dsCTHD[vitri].VAT);
	cout<<" vt co ma la "<<MAVT;
	outtextxy(400,95,MAVT);
	outtextxy(680+5,120-30+5,timKiemVatTu(root, MAVT)->vatTu.TENVT);
	outtextxy(1100+5,120-30+5,chrSL);
	outtextxy(445+5,125+5,chrDonGia);
	outtextxy(730+5,125+5,chrVAT);
}
int tinhtonghoadon( DanhSachChiTietHoaDon ds){
	int tong =0;
	for(int i=0;i<ds.num;i++){
			tong = tong+ ds.dsChitiet[i].DonGia*ds.dsChitiet[i].SL*(100+ds.dsChitiet[i].VAT)/100;
	}
//	for(NodeChiTiet *p=dsCTHD;p!=NULL;p=p->next){
//		cout<<endl<<p->chiTiet.DonGia<<" "<<p->chiTiet.SL<<"  "<<p->chiTiet.VAT<<endl;
//	}
//		while(dsCTHD!=NULL)
//	{
//		tong = tong+ dsCTHD->chiTiet.DonGia*dsCTHD->chiTiet.SL*(100+dsCTHD->chiTiet.VAT)/100;
//	dsCTHD=dsCTHD->next;
//	}
return tong;
	
}
