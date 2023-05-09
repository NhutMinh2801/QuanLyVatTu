#pragma once
#include "CauTruc.h"
#include "dohoa.h"
#include "VatTu.h"
#include "NhanVien.h"

void laythongtinnhanvien(DS_NhanVien ds, int vt, char cMNV[],char Ho[],char Ten[],char Phai[])
{
	setcolor(0);
	setbkcolor(15);
	if(vt>ds.num||vt==-1)
	return;
	itoa(ds.DS[vt]->MANV,cMNV,10);
	outtextxy(425+5,40+5,cMNV);
	strcpy(Ho,ds.DS[vt]->Ho);
	outtextxy(345+5,80+5,Ho);
	strcpy(Ten,ds.DS[vt]->Ten);
	outtextxy(840+5,80+5,Ten);
	button(1110,80,1220,112,24," NAM",2,9,15);
	button(1225,80,1320,112,25,"  NU",2,9,15);
	if(strcmp(ds.DS[vt]->Phai,"NAM")==0)
	button(1110,80,1220,112,24," NAM",2,9,12);
	else
		button(1225,80,1320,112,25,"  NU",2,9,12);
	
	

}
void run(){
	CayVatTu root;
	DS_NhanVien dsNV;
	khoiTaoDanhSachNhanVien(dsNV);
	docNhanVienTuFile("nhanvien.txt",dsNV);
	docVatTuTuFile("VatTu.txt", root);
	giaodiendau();
	int x=-1,y=-1,key=0;
while(1)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x==-1&&y==-1) continue;
		key=MID[x][y];
	    trolai:
		switch(key)
		{
			
//			
			case 1:
			{
				giaodiennhapthongtinqlVT();
					char MAVT[10]="";
					char TENVT[50]="";
					char DVT[20]="";
					char cton[10]="";
					float ton;
					
					VatTu *mangTamVatTu=NULL;
					int trang=1;
					bool isNew=true;
					
			   		bangVatTu(1);
			   		doCayVaoMangVatTu(mangTamVatTu, root);
					inDSVatTu(mangTamVatTu, root.soluong, 280, 245+40,1);
					while(1)
					{
						delay(1);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							clearmouseclick(WM_LBUTTONDOWN);
						}
						if(x==-1&&y==-1) continue;
						key=MID[x][y];
					    trove1:
						switch(key)
						{
								case 11:
			    			{
			    				if(isNew)
								ScannerMa(MAVT,20,425+5,40+5,key,key);
								key=0;
								x=y=-1;
			    				goto trove1;
			    				break;
							}
						case 12:{
							ScannerString(TENVT,100,840+5,40+5,key,key);
							if(!isNew) key = 14;
							key=0;
								x=y=-1;
							goto trove1;
			    			break;
						
								}
						case 13:{
							if(isNew==false)
							{
								key=(key==12)?14:12;
								goto trove1;
							}
							ScannerString(cton,100,345+5,80+5,key,key);
							key=0;
							x=y=-1;
							goto trove1;
							break;
						}
						case 14:{
							ScannerString(DVT,140,840+5,80+5,key,key);
							key=0;
								x=y=-1;
							goto trove1;
							break;
						}
						case 1110:{

						   if(strlen(MAVT)==0 || strlen(TENVT)==0 || strlen(DVT)==0){
//						   		outtextxy(2,35,"Khong duoc de");
//							   	outtextxy(2,36,"trong");
                               mancanhbaoloi("khong duoc de trong");
							   	key=0;
								x=y=-1;
							goto trove1;
						   	break;
						   }
							if(isNew){
								if(timKiemVatTu(root, MAVT)==NULL){
						   			ton = doiSangFloat(cton);
									themNodeVaoCay(root,taoNodeVatTu(taoVatTu(MAVT, TENVT, DVT, ton)));
								
								}
							   	else{
//							   		outtextxy(2,35,"Ma VT da");
//							   		outtextxy(2,36,"duoc su dung");
 mancanhbaoloi("Ma VT da duoc su dung");
							   		key=0;
								x=y=-1;
							goto trove1;
							   	break;
								}
						   }
						   else{
								hieuChinhVatTuTheoMa(root, MAVT, TENVT, DVT);
							
								isNew=true;
							
						   }
						   	
						   	ghiVatTuVaoFile("VatTu.txt", root);
						   
					   		bangVatTu(trang);
							
					   		if(mangTamVatTu!=NULL) delete[] mangTamVatTu;
					   		doCayVaoMangVatTu(mangTamVatTu, root);
				        	inDSVatTu(mangTamVatTu, root.soluong, 280, 245+40,1);
						   	
//						   	strcpy(MAVT,"");
//						   	strcpy(TENVT,"");
//						   	strcpy(DVT,"");
//						   	strcpy(cton,"");
//						   	ton=0;
//						   	
							goto trove1;
						   	
							break;
						}
						case 1112:{
  	
						   	strcpy(MAVT,"");
						   	strcpy(TENVT,"");
						   	strcpy(DVT,"");
						   	strcpy(cton,"");
						   	ton=0;
						   	button(285,40,425,72,121,"Ma VT:",2,9,15);
	taoo(425,40,675,72,11,15,0);
	
	button(690,40,840,72,122,"TEN VT:",2,9,15);
	taoo(840,40,1100,72,12,15,0);
	
	button(285,80,345,112,123,"SL:",2,9,15);
	taoo(345,80,675,112,13,15,0);
	
	button(690,80,840,112,124,"DON VI:",2,9,15);
	taoo(840,80,1100,112,14,15,0);
	x=y=-1;key=0;
						   	isNew =true;
							break;
						}
						case 1111:{
                       
					
						   if(timTatCaVatTu(dsNV, MAVT) || timKiemVatTu(root, MAVT)->vatTu.ton>0){
//						   		outtextxy(2,35,"Khong the xoa");
//							   	outtextxy(2,36,"vat tu nay");
                               mancanhbaoloi("khong the xao vat tu nay");
							   	key=0;
							   	x=y=-1;
							   	goto trove1;
						   }
						   
						xoaNodeKhoiCayTheoMa(root, MAVT);
						
						ghiVatTuVaoFile("VatTu.txt", root);
					
				   		bangVatTu(trang);
				   		if(mangTamVatTu!=NULL) delete[] mangTamVatTu;
				   		doCayVaoMangVatTu(mangTamVatTu, root);
				        inDSVatTu(mangTamVatTu, root.soluong, 280, 245+40,1);
						isNew=true;
						
						key=11;
						goto trove1;
						break;
						}
						case 1001: case 1002: case 1003: case 1004: case 1005: case 1006: case 1007: case 1008: case 1009: case 1010: case 1011: case 1012:{
						if((trang-1)*10+ key-1002 <root.soluong){
						layThongTinVatTu(mangTamVatTu, (trang-1)*10+ key-1002, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
						   isNew=false;
						   key=0;
						  x=y=-1;
						   goto trove1;
						}
							 key=0;
						  x=y=-1;
						   goto trove1;
							break;
						}
					 case 1114:{
					 	//lui
					 	if(trang>1){
					 		trang--;
					 	bangVatTu(trang);
					 	if(mangTamVatTu!=NULL) delete[] mangTamVatTu;
				   		doCayVaoMangVatTu(mangTamVatTu, root);
				        inDSVatTu(mangTamVatTu, root.soluong, 280, 245+40,trang);
						 }
						 cout<<" lui";
						 x=y=-1;
						 key=0;
						break;
					 }
					 case 1115:{
					 	trang++;
					 	bangVatTu(trang);
					 	if(mangTamVatTu!=NULL) delete[] mangTamVatTu;
				   		doCayVaoMangVatTu(mangTamVatTu, root);
				        inDSVatTu(mangTamVatTu, root.soluong, 280, 245+40,trang);
					  cout<<" tien";
					  key=0;
					  x=y=-1;
						break;
					 }

						default:{
							if(key==1||key==2||key==3||key==4)
							{
								x=y=-1;
								goto trolai;
							}
							break;
						}

							
						}
					}
					
	}
//			
		
			case 2:
			{
				     	int MANV;
		            	char cMANV[6]="";
                    	char Ho[30]="";
              			char Ten[20]="";
						char Phai[4]="";
					
                        int vt=-1;
				giaodiennhapthongtinqlNHANVIEN();
				bool trangthailuu=true;
				int trang =1;
			    bangthongqllNV(trang);
			    inDSNhanVien(dsNV,280+5,245+32+2,trang);
			    while(1)
					{
						delay(1);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							clearmouseclick(WM_LBUTTONDOWN);
						}
						if(x==-1&&y==-1) continue;
						key=MID[x][y];
					    trove2:
						switch(key)
						{
								case 21:{
									MANV = ScannerNum(cMANV,30,425+5,40+5,key,key);
									goto trove2;
									break;
								}
								case 22:{
									ScannerName(Ho,30,345+5,80+5,key,key);
									goto trove2;
									
									break;
								}
								case 23:{
									ScannerName(Ten,30,840+5,80+5,key,key);
									goto trove2;
									
									break;
								}
								case 24:{
										button(1110,80,1220,112,24," NAM",2,9,15);
									button(1110,80,1220,112,24," NAM",2,9,12);
                                	button(1225,80,1320,112,25,"  NU",2,9,15);
                                	strcpy(Phai,"NAM");
									break;
								}
								case 25:{
									button(1110,80,1220,112,24," NAM",2,9,15);
										button(1225,80,1320,112,25,"  NU",2,9,15);
                              	button(1225,80,1320,112,25,"  NU",2,9,12);
                              		strcpy(Phai,"NU");
									break;
								}
								
								
								case 1110:{
								
						   	if(cMANV[0]*Ho[0]*Ten[0]*Phai[0]==0)
						{
						//	outtextxy(20,13,"Thong tin khong duoc de trong !");
						 mancanhbaoloi("Thong tin khong duoc de trong !");
							
							key=21;
							goto trove2;
							
						}
						if(kiemtratrungnhanvien(dsNV,atoi(cMANV))==true&&trangthailuu==true)
						{
							mancanhbaoloi("Thong tin khong duoc de trong !");
						
							key=21;
							goto trove2;
						}
							NhanVien temp;
							if(trangthailuu==true)
							{
							temp=taoNhanVien(atoi(cMANV),Ho,Ten,Phai);
							themNhanVien(dsNV,temp);
							ghiNhanVienVaoFile("nhanvien.txt",dsNV);
						  MANV=0;
		            	 memset(cMANV,0,6);
		            	 memset(Ho,0,30);
		            	 memset(Ten,0,20);
		            	 memset(Phai,0,4);
		            
						bangthongqllNV(trang);
			           inDSNhanVien(dsNV,280+5,245+32+2,trang);
			           
						
							key=21;
							goto trove2;
							break;
							}
							if(trangthailuu==false)
							{
								if(atoi(cMANV)!=dsNV.DS[vt]->MANV&&kiemtratrungnhanvien(dsNV,atoi(cMANV))==true)
								{
									mancanhbaoloi("Thong tin da duoc su dung !");
						
							key=21;
							goto trove2;
								}
								temp=taoNhanVien(atoi(cMANV),Ho,Ten,Phai);
								suaNhanVien(dsNV,temp,vt);
								vt=-1;
							memset(cMANV,0,6);
		            	 memset(Ho,0,30);
		            	 memset(Ten,0,20);
		            	 memset(Phai,0,4);
		            	
						 
			            bangthongqllNV(trang);
			            inDSNhanVien(dsNV,280+5,245+32+2,trang);
							}
						
									break;
								}
								
								case 1111:{
									cout<<endl<<"vt"<<vt<<endl;
						if(vt==-1) break;
						     if(dsNV.DS[vt]->list_HD.pHead!=NULL)
					    {
//					    	outtextxy(20,13,"Khong xoa duoc nhan vien nay !");
	mancanhbaoloi("Khong xoa duoc nhan vien nay !");
						
						x=y=-1;
						key=0;
							goto trove2;
						}
						   xoaNhanVien(dsNV,vt);
						   vt=-1;
						  	giaodiennhapthongtinqlNHANVIEN();
						  		bangthongqllNV(trang);
			           inDSNhanVien(dsNV,280+5,245+32+2,trang);
						  	
							break;
								}
								case 1112:{
									giaodiennhapthongtinqlNHANVIEN();
									 MANV=0;
		            	 memset(cMANV,0,6);
		            	 memset(Ho,0,30);
		            	 memset(Ten,0,20);
		            	 memset(Phai,0,4);
		            
						 	bangthongqllNV(trang);
			           inDSNhanVien(dsNV,280+5,245+32+2,trang);

		             	key=21;
		             	x=20;
				       	y=4;
				       	  trangthailuu=true;
		                goto trove2;
						break;
									break;
								}
								
								case 1114:{
									if(trang>1){
										trang--;
											bangthongqllNV(trang);
			           inDSNhanVien(dsNV,280+5,245+32+2,trang);
										x=y=-1; key=0;
									}
									break;
								}
								case 1115:{
									trang++;
										bangthongqllNV(trang);
			           inDSNhanVien(dsNV,280+5,245+32+2,trang);
			           	x=y=-1; key=0;
									break;
								}
								case 2001: case 2002: case 2003: case 2004: case 2005: case 2006: case 2007: case 2008: case 2009: case 2010: case 2011:{
									
								  vt=(trang-1)*10+key-2002;
                               if(vt>=dsNV.num)
									break;
									
									laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai);
									trangthailuu=false;
									x=y=-1;key=0;
									goto trove2;
								}
									default:{
							if(key==1||key==2||key==3||key==4)
							{
								x=y=-1;
								goto trolai;
							}
							break;
						}
						}
					}
			    
			    
				x=y=-1;
				break;
			}
			case 3:{
				giaodiennhapthongtinqlHoaDon();
				bangthongqlHoaDon(1);
			    	char LOAIHD[3]="";
					char NGAYLAP[50]="";
					char SOHD[25]="";
					int MANV;
					char cMaNV[10]="";
					char chrMANV[10]="";
					Date ngayLap = GetNow(NGAYLAP);
					
					int trang=1;
					bool isRemove=false;
					bool isnew=true;
					int vt=0;
				
					
					HoaDon tmpHoaDon  = taoHoaDon("", ngayLap, ' ');
					
					char MaVT[15]="";
					char chrSL[10]="";
					char chrDonGia[20]="";
					char chrVAT[10]="";
					
			   		outtextxy(590+5,10+5, NGAYLAP);
			   		
			   		  while(1)
					{
						delay(1);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							clearmouseclick(WM_LBUTTONDOWN);
						}
						if(x==-1&&y==-1) continue;
						key=MID[x][y];
					    trove3:
						switch(key)
						{
								case 31:{
									ScannerLoai(LOAIHD,1,425+5,10+5,key,key);
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 32:{
									break;
								}
								case 33:{
									ScannerString(SOHD,10,980+5,10+5,key,key);
									
										NhanVien tmpNV;
						  	if( timTatCaHoaDon(dsNV, SOHD, tmpNV)!=NULL){
						  		 
								if(tmpHoaDon.ct.num==0){
									isnew =false;
									NodeHoaDon *tmpHD = timTatCaHoaDon(dsNV, SOHD, tmpNV);
									char la[2]="";
									la[0]=tmpHD->data.Loai;
									outtextxy(425+5,10+5,la );
									char chrNL[20] = "";
									char chrString[10]="";
									itoa(tmpHD->data.NgayLap.ngay, chrString, 10);
									strcat(chrNL, chrString);
									strcat(chrNL, "-");
									itoa(tmpHD->data.NgayLap.thang, chrString, 10);
									strcat(chrNL, chrString);
									strcat(chrNL, "-");
									itoa(tmpHD->data.NgayLap.nam, chrString, 10);
									strcat(chrNL, chrString);
									outtextxy(590+5,10+5, chrNL);
									itoa(tmpNV.MANV, chrString, 10);
									outtextxy(445+5,50+5, chrString);
									char TenNV[60]="";
									strcat(TenNV, tmpNV.Ho);
									strcat(TenNV, " ");
									strcat(TenNV, tmpNV.Ten);
									outtextxy(940+5,50+5, TenNV);
										bangthongqlHoaDon(1);
									inDSChiTietHoaDon(tmpHD->data.ct, root,tmpHoaDon.ct.num,285, 245+35);
								}
								x=y=-1;key=0;
			    				goto trove3;
							}
							else{
								strcpy(tmpHoaDon.SoHD, SOHD);
						
			    				bangthongqlHoaDon(1);
							}
							goto trove3;
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 34:{
									// check ma r hien thi ho ten
								  MANV =ScannerNum(chrMANV,10,445+5,50+5,key,key);
								   if(timNhanVien(dsNV,atoi(chrMANV)) == NULL ){
								   	mancanhbaoloi("nhan vien khong ton tai");
								   }else{
								   	NhanVien *tem = timNhanVien(dsNV,atoi(chrMANV));
								   	char t[40]="";
									strcat(t,tem->Ho);
								   	strcat(t," ");
								   	strcat(t,tem->Ten);
								   	taoo(940,80-30,1330,112-30,35,15,0);
								   	outtextxy(940+5,50+5, t);
								   }
								   
					               	x=y=-1;
									key=0;
									goto trove3;
									
									break;
								}
								case 35:{
									
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 311:{
									taoo(395,120-30,525+50,152-30,311,15,0);
									ScannerMa(MaVT,15,395+5,90+5,key,key);
									if(timKiemVatTu(root,MaVT)!=NULL){
										outtextxy(680+5,120-30+5,timKiemVatTu(root,MaVT)->vatTu.TENVT);
									}
									else{
										mancanhbaoloi(" khong ton tai vat tu nay");
									}
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 312:{
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 313:{
									ScannerNum(chrSL,15,1100+5,90+5,key,key);
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 314:{
										ScannerNum(chrDonGia,15,445+5,125+5,key,key);
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 315:{
									ScannerNum(chrVAT,15,730+5,125+5,key,key);
									x=y=-1;
									key=0;
									goto trove3;
									break;
								}
									case 3110:{

										if(strlen(LOAIHD)*strlen(MaVT)*strlen(chrSL)*strlen(chrDonGia)*strlen(chrVAT)==0){
											mancanhbaoloi("dien dau du thong tin");
											x=-1;y=-1;
											break;
										}
										if(LOAIHD[0]=='X'){
						   	    if(0>timKiemVatTu(root, MaVT)->vatTu.ton-doiSangFloat(chrSL))
						   	    {
                            
                                  
			    					char s[10]="";
			    				   	doiSangChuoi(s,timKiemVatTu(root, MaVT)->vatTu.ton);
			    				   	char s1[100]=" so luong vat tu khong du, sl ton :";
			    				   	strcat(s1,s);
			    					 mancanhbaoloi(s1)	;
			    					 	x=-1;y=-1;
										
			    					break;
								}
								timKiemVatTu(root, MaVT)->vatTu.ton -= doiSangFloat(chrSL);
						   }
						   else if(LOAIHD[0]=='N'){
						   		timKiemVatTu(root, MaVT)->vatTu.ton += doiSangFloat(chrSL);
						   }
						   themChiTietHoaDon(tmpHoaDon.ct, chiTietHoaDon(MaVT, doiSangFloat(chrSL), doiSangFloat(chrDonGia), doiSangFloat(chrVAT)));
						   ghiVatTuVaoFile("VatTu.txt", root);
						  // ghiNhanVienVaoFile("nhanvien.txt",dsNV);
						  mancanhbaoloi(" them chi tiet thanh cong");
						  	bangthongqlHoaDon(1);
							inDSChiTietHoaDon(tmpHoaDon.ct, root, tmpHoaDon.ct.num, 285, 245+35);

						   
										x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 3111:{
									if(isnew ==false) {
										mancanhbaoloi(" khong the sua hoa don cu");
									break;
									}
									if(tmpHoaDon.ct.num<=0) break;
										if(strlen(LOAIHD)*strlen(MaVT)*strlen(chrSL)*strlen(chrDonGia)*strlen(chrVAT)==0){
											mancanhbaoloi("dien dau du thong tin");
											x=-1;y=-1;
											break;
										}
									if(LOAIHD[0]=='X'){
									timKiemVatTu(root, MaVT)->vatTu.ton += doiSangFloat(chrSL);
							   	}
							   	else if(LOAIHD[0]=='N'){
							   		timKiemVatTu(root, MaVT)->vatTu.ton -= doiSangFloat(chrSL);
							   	}
							   	ghiVatTuVaoFile("VatTu.txt", root);
								xoaMotChiTietHoaDon(tmpHoaDon.ct, MaVT);
								bangthongqlHoaDon(1);
                            inDSChiTietHoaDon(tmpHoaDon.ct, root, tmpHoaDon.ct.num, 285, 245+35);

										x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 3112:{
									
	taoo(395,120-30,525+50,152-30,311,15,0);
	
	taoo(680,120-30,1030,152-30,312,15,0);

	taoo(1100,120-30,1330,152-30,313,15,0);

	taoo(445,125,625,157,314,15,0);

	taoo(730,125,930,157,315,15,0);
	strcpy(MaVT,"");
	strcpy( chrSL,"");
		strcpy( chrDonGia,"");
			strcpy( chrVAT,"");
	
										x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 1110:{
									  if(strlen(SOHD)==0 || strlen(chrMANV)==0 || tmpHoaDon.ct.num==0){
//						   		outtextxy(2, 35, "khong duoc bo");
//			    				outtextxy(2, 36, "trong");	
mancanhbaoloi(" Khong bo trong thong tin");
			    				x=y=-1;key=0;
						   		goto trove3;
						   		
						   }
						   
//							if(isNew){
 // MANV =ScannerNum(chrMANV
 tmpHoaDon.Loai=LOAIHD[0];
								themHoaDon(timNhanVien(dsNV, atoi(chrMANV))->list_HD, tmpHoaDon);
							    
//						   }
						   	
						   	ghiNhanVienVaoFile("NhanVien.txt", dsNV);
						   mancanhbaoloi(" Tao hoa don thanh cong");
						   	
						   	strcpy(SOHD,"");
						   	strcpy(LOAIHD,"");
						   	strcpy(NGAYLAP,"");
						   	strcpy(chrMANV,"");
						   	tmpHoaDon  = taoHoaDon("", ngayLap, ' ');
										x=y=-1;
										
									key=0;
									goto trove3;
									break;
								}
								case 1111:{
										x=y=-1;
									key=0;
									goto trove3;
									break;
								}
								case 1112:{
									isnew=true;
							
								taoo(425,40-30,485,72-30,31,15,0);
								taoo(980,40-30,1300,72-30,33,15,0);
									taoo(445,80-30,775,112-30,34,15,0);
									taoo(940,80-30,1330,112-30,35,15,0);
		taoo(395,120-30,525+50,152-30,311,15,0);
	taoo(680,120-30,1030,152-30,312,15,0);
	taoo(1100,120-30,1330,152-30,313,15,0);
		taoo(445,125,625,157,314,15,0);
			taoo(730,125,930,157,315,15,0);
								
										x=y=-1;
									key=0;
									goto trove3;
									break;
								}
							
								case 3001: case 3002: case 3003: case 3004: case 3005: case 3006: case 3007: case 3008: case 3009: case 3010: case 3011:{
									vt=key-3002;
									layThongTinMotChiTietHoaDon(tmpHoaDon.ct.dsChitiet, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);

									x=y=-1;
									key=0;
									goto trove3;
									break;
								} 
									default:{
							if(key==1||key==2||key==3||key==4)
							{
								x=y=-1;
								goto trolai;
							}
							break;
						}
								
							}
					}
			   		
			   		
				x=y=-1;
				break;
			}
			case 4:{
				///--------------------
				giaodienthongtinThongKe();
				 char MANV[10]="";
				 char Ngay1[10]="";
				 char Ngay2[10]="";
				 Date t1;
				 Date t2;
				 int vt=-1;
				 int tranghd=1;
  while(1)
					{
						delay(1);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							clearmouseclick(WM_LBUTTONDOWN);
						}
						if(x==-1&&y==-1) continue;
						key=MID[x][y];
					    trove4:
						switch(key)
						{
								case 41:{
									giaodienthongtinThongKe();
									bangthongkeHd(1);
										button(280,4,520,36,41,"HD_NHANVIEN",2,1,12);
									button(525,4,690,36,42,"Top 10",2,1,15);
								  	  while(1)
					{
						delay(1);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							clearmouseclick(WM_LBUTTONDOWN);
						}
						if(x==-1&&y==-1) continue;
						key=MID[x][y];
					   trove41:
						switch(key)
						{
								case 411:{
									ScannerMa(MANV,20,425+5,40+5,key,key);
									if(MANV[0]=='0')
			    				{
			    					if(strlen(Ngay1)<10)
								{
									mancanhbaoloi(" dien chinh xac cac thong tin");
								}
								}
			    				vt= timKiemViTriNhanVien(dsNV,atoi(MANV));
			    				if(vt==-1||vt>dsNV.num) 
							{
								mancanhbaoloi("Nhan vien khong ton tai");
			    					x=30;
			    					y=8;
			    					key=0;
			    				x=y=-1;
							  key =0;
								goto trove41;
								break;
							}
							   taoo(840,40,1100,72,412,15,0);
							   char ten[50]="";
							   strcat(ten,dsNV.DS[vt]->Ho);
							   strcat(ten," ");
							   strcat(ten,dsNV.DS[vt]->Ten);
			    				outtextxy(845,45,ten);
			    			
							x=y=-1;
							  key =0;
								goto trove41;
								}
								case 412:{
									
									break;
								}
								case 413:{
										ScannerString(Ngay1,15,345+5,80+5,key,key);
								if(strlen(Ngay1)<10)
								{
								mancanhbaoloi(" ngay khong dung dinh dang dd/mm/yyyy");
			    					x=y=-1;
							  key =0;
								goto trove41;
			    					break;
								}
								t1=chuyenchuoithoigian(Ngay1);
//								cout<<"\n"<<t1.ngay<<" "<<t1.thang<<" "<<t1.nam;
							x=y=-1;
							  key =0;
							//	goto trove41;
									break;
								}
								case 414:{
									ScannerString(Ngay2,15,840+5,80+5,key,key);
							if(strlen(Ngay2)<10)
								{
									mancanhbaoloi(" ngay khong dung dinh dang dd/mm/yyyy");
			    				x=y=-1;
							  key =0;
								goto trove41;
									break;
								}
							t2=chuyenchuoithoigian(Ngay2);
							  x=y=-1;
							  key =0;
							//	goto trove41;
									break;
								}
								case 1113:{
									
								
							if(strlen(MANV)>0){
                           		if(vt==-1||vt>dsNV.num) 
							{
									mancanhbaoloi("nhan vien khong ton tai");
			    				x=y=-1;
			    					key=0;
			    				x=y=-1;
							  key =0;
								
								break;
							}
						   
							int dem=0;
							int ychay=245+35;
							cout<<" vo rrrrrrrrrrrrrrrrrr";
							inDSHoaDonTrongNhanVien(290+5,ychay,*dsNV.DS[vt],root,t1,t2,dem,tranghd);
						
								key=0;
							x=y=-1;
							break;
						
                             }
						
						if(MANV[0]=='0'||strlen(MANV)==0){
							intoanbohoadon(290+5,245+35,root,dsNV,t1,t2,tranghd);
							key=0;
							x=y=-1;
							break;
						}
                          
									break;
								}
									default:{
										if(key==42){
												goto trove4;
										}
							if(key==1||key==2||key==3||key==4)
							{
								x=y=-1;
								goto trolai;
							}}
								//-------
								}
								}
									key=0;
									x=y=-1;
									goto trove4;
									break;
								}
								case 42:{
									giaodientopvt();
									button(280,4,520,36,41,"HD_NHANVIEN",2,1,15);
									button(525,4,690,36,42,"Top 10",2,1,12);
										key=0;
									x=y=-1;
									goto trove4;
									break;
								}
									default:{
							if(key==1||key==2||key==3||key==4)
							{
								x=y=-1;
								goto trolai;
							}
								
							}
			
	                  	}
                    }
			//-=----------------------------------------
				x=y=-1;
				break;
			}
		}
}
	
	
	
}

