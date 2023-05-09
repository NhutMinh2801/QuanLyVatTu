#pragma once
#include <winbgim.h> 
const int H= 700;
const int W=1360;
short int MID[1350][680];

int mancanhbaoloi(char s[])
{
int msgboxID = MessageBox(
        NULL,
        s,
        "err ",
        MB_ICONWARNING | MB_OK
    );

   
    return msgboxID;
}
void FloatToChar(char soDiem[], float nFloat);
void khoitaoID()
{
	for(int i=10;i<1350;i++)
	{
		for(int j=10;j<680;j++)
		MID[i][j]=0;
	}
}

void taoID(int x1,int y1,int x2,int y2, int ID)
{
	for(int i=x1;i<x2;i++)
	{
		for(int j=y1;j<y2;j++)
		MID[i][j]=ID;
	}
}
const int ENTER = 13;
const int BACKSPACE = 8;
int DisplayResourceNAMessageBox(char s[])
{
//	char *mg=new char;
//strcpy(mg,s);
//mg=	strcat(mg, s);
//mg=	strcat(mg, " KHONG DU DIEU KIEN MO LOP \N BAN MUON HUY LOP KHONG");
	

	
    int msgboxID = MessageBox(
        NULL,
        s,
        " ",
        MB_ICONWARNING | MB_OKCANCEL /*| MB_DEFBUTTON2*/
    );

   
    return msgboxID;
}

void ScannerMa(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
		s[l] ='|';
		s[l+1]=0;
//	cout<<"Nien Khoa in Scanner: "<<s<<endl;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				
				if(c=='-')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					c=c+'A'-'a';
					s[l] = c;
					l++;
					s[l]=0;
				//	continue;
				}
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}
void ScannerString(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				if(c=='/'){
						s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				if(c=='_')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z'))
				s[l]=s[l]+'A'-'a';
				s[l+1]=0;
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

void ScannerName(char s[],int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{

				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';

				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

int ScannerNum(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
					s[l+1]=0;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}

int ScannerLoai(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			
			if(l<max)
			{
				
				if(c=='X' || c=='x'||c=='N'||c=='n')
				{
					if(c<'z')
		   	c=c+'A'-'a';
					s[l] = c;
					s[l+1]=0;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}

void Scannerdate(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
	
		
		if(kbhit())
		{			
		char c = getch();
		if(c==75||c==77||c==80||c==72||c == 13||c==27)
			    {
			    	outtextxy(px,py,s);
			    
			    	return;
				}
		else if(l<max)
			{   
			    
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
					if(l==2||l==5)
			    {
			    	s[l]='/';
			    	l++;
			    	s[l]=0;
				}
				}
			
				outtextxy(px,py,s);	
			}
			if(c == 8&&l>0)
			{
				outtextxy(px,py,s);	
				s[l-1] =' ';
				s[l]=0;
				l--;
			}
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}

void mancanhbao()
{
    setfillstyle(1,11);	
//	bar(20,465,300,675);
	bar(4,275,273,690);
	setbkcolor(11);
	setcolor(12);
	settextstyle(0,0,2);
	setbkcolor(11);
	setcolor(12);
	settextstyle(0,0,2);
	outtextxy(90,285,"CANH BAO");	
	
}
void khungChinh()
{
	setfillstyle(1,11);// man
	bar(0,0,1360,700);
	setcolor(0);
    rectangle(2,2,1353,693);
    rectangle(4,4,273,310);
    rectangle(4,320,273,690);
    rectangle(280,4,1350,220);
    rectangle(280,225,1350,690);

	setbkcolor(11);
	setcolor(12);
	settextstyle(0,0,2);
	outtextxy(90,285,"CANH BAO");	
    
}

void button(int x1, int y1, int x2, int y2, int ID, char* s,int cochu, int clbar, int clw)
{
	setfillstyle(1,clbar);
	bar(x1,y1,x2,y2);
	setcolor(clw);
	setbkcolor(clbar);
	settextstyle(0,0,cochu);
	outtextxy(x1+10,y1+10,s);	
	taoID(x1,y1,x2,y2,ID);
}
void taoo(int x1,int y1,int x2, int y2, int ID,int mau, int mauvien)
{
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);
	taoID(x1,y1,x2,y2,ID);
}
void taodong(int x1,int y1, int docao,int Mangdodai[], int mau, int mauvien,int ID , int socot)
{
	int y2= y1+docao;
	int	x2;
	
	for(int i=0;i<socot;i++)
	{
	    x2=x1+Mangdodai[i];
		taoo(x1,y1,x2,y2,ID,mau,mauvien);
		x1=x2;
	
	}
}
void taobang(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		if(i!=1)
		{
			char temp[4];
			itoa((i-1)+10*(trang-1),temp,10);
			outtextxy(x1+5,y1+5,temp);
		}
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}	
}
void taobang1(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}	
}
//void danhdau(int vt)
//{
//	setcolor(12);
//	setbkcolor(15);
//	settextstyle(0,0,2);
//	int y1=245+35;
//	for(int i=1;i<=10;i++)
//	{
//		
//	    outtextxy(1300,y1," ");
//		y1=y1+32;
//		
//		
//	}
//	outtextxy(1300,245+35+(vt-1)*32,"v");
//		
//}
void giaodiendau()
{
	khoitaoID();
	khungChinh();
	button(6,30,270,90,1,"QUAN LY VAT TU", 2,1,15);
	button(6,100,270,160,2,"QL NHAN VIEN", 2,1,15);
	button(6,170,270,230,3,"QUAN LY HOA DON", 2,1,15);
	button(6,240,270,300,4,"QL THONG KE", 2,1,15);
//	button(106,232,220,262,9999,"Thoat", 2,2,15);
	
}

void giaodiennhapthongtinqlVT()
{
	giaodiendau();
	button(6,30,270,90,1,"QUAN LY VAT TU", 2,1,12);

	button(285,40,425,72,121,"Ma VT:",2,9,15);
	taoo(425,40,675,72,11,15,0);
	
	button(690,40,840,72,122,"TEN VT:",2,9,15);
	taoo(840,40,1100,72,12,15,0);
	
	button(285,80,345,112,123,"SL:",2,9,15);
	taoo(345,80,675,112,13,15,0);
	
	button(690,80,840,112,124,"DON VI:",2,9,15);
	taoo(840,80,1100,112,14,15,0);
	

	
    button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}

void bangVatTu(int trang)
{
	int m[]={65,200,200,300,200,100};
	char td[][50]={"STT","MA VT","TEN VT","SL","DON VI"};
	taobang(280,245,32,5,m,15,0,11,1000,trang,td);// chua sua ID

}

void giaodiennhapthongtinqlNHANVIEN()
{
	giaodiendau();
    	button(6,100,270,160,2,"QL NHAN VIEN", 2,1,12);

	button(285,40,425,72,121,"Ma NV:",2,9,15);
	taoo(425,40,675,72,21,15,0);
	
//	button(690,40,840,72,122,"MSSV:",2,9,15);
//	taoo(840,40,1100,72,12,15,0);
	
	button(285,80,345,112,123,"HO:",2,9,15);
	taoo(345,80,675,112,22,15,0);
	
	button(690,80,840,112,124,"TEN:",2,9,15);
	taoo(840,80,1100,112,23,15,0);
	
	button(1110,80,1220,112,24," NAM",2,9,15);
	button(1225,80,1320,112,25,"  NU",2,9,15);
	
//    button(285,120,345,152,117,"SDT:",2,9,15);
//	taoo(345,120,675,152,17,15,0);
	
    button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}
void bangthongqllNV(int trang)
{
	int m[]={65,200,500,200};
	char td[][50]={"STT","MA NV","HO TEN","PHAI"};
	taobang(280,245,32,4,m,15,0,11,2000,trang,td);// chua sua ID

}

void giaodiennhapthongtinqlHoaDon()
{
	giaodiendau();
	button(6,170,270,230,3,"QUAN LY HOA DON", 2,1,12);

	button(285,40-30,425,72-30,121,"LOAI HD:",2,9,15);
	taoo(425,40-30,485,72-30,31,15,0);
	
	button(490,40-30,590,72-30,122,"NGAY:",2,9,15);
	taoo(590,40-30,800,72-30,32,15,0);
	
	button(810,40-30,970,72-30,122,"SO HD",2,9,15);
	taoo(980,40-30,1300,72-30,33,15,0);
	
	
	button(285,80-30,445,112-30,123,"MA NV:",2,9,15);
	taoo(445,80-30,775,112-30,34,15,0);
	
	button(790,80-30,940,112-30,124,"TEN NV:",2,9,15);
	taoo(940,80-30,1330,112-30,35,15,0);
	
    button(285,120-30,395,152-30,117,"MaVT:",2,9,15);
	taoo(395,120-30,525+50,152-30,311,15,0);
	
	button(580,120-30,680,152-30,117,"TenVT:",2,9,15);
	taoo(680,120-30,1030,152-30,312,15,0);
	
	button(1040,120-30,1100,152-30,117,"Sl:",2,9,15);
	taoo(1100,120-30,1330,152-30,313,15,0);
	
	 button(285,125,445,157,117,"DonGia:",2,9,15);
	taoo(445,125,625,157,314,15,0);
	
	button(630,125,730,157,117,"VAT:",2,9,15);
	taoo(730,125,930,157,315,15,0);
	 
	button(1000,125,1100,157,3110,"Them",1,2,0);
	button(1110,125,1210,157,3111,"Xoa",1,2,0);
	button(1220,125,1330,157,3112,"VT moi",1,2,0);
	

	
    button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}
void giaodientopvt()
{
	giaodiendau();
	button(6,170,270,230,3,"QUAN LY HOA DON", 2,1,12);

}
void bangthongqlHoaDon(int trang)
{
	int m[]={65,100,200,100,200,100,200};
	char td[][50]={"STT","MAVT","TEN VT","SL","GIA","VAT","TIEN"};
	taobang(280,245,32,7,m,15,0,11,3000,trang,td);// chua sua ID

}
void giaodienthongtinThongKe()
{
	giaodiendau();
    button(6,240,270,300,4,"QL THONG KE", 2,1,12);
	button(280,4,520,36,41,"HD_NHANVIEN",2,1,15);
	button(525,4,690,36,42,"Top 10",2,1,15);
	
	button(285,40,425,72,131,"Ma NV:",2,9,15);
	taoo(425,40,675,72,411,15,0);
	
	button(690,40,840,72,132,"TEN NV:",2,9,15);
	taoo(840,40,1100,72,412,15,0);
	
	button(285,80,345,112,133,"Tu Ngay:",2,9,15);
	taoo(345,80,675,112,413,15,0);
	
	button(690,80,840,112,134,"Den Ngay:",2,9,15);
	taoo(840,80,1100,112,414,15,0);
	
	button(925,185,1195,220,1113,"IN THONG KE",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}
void bangthongkeHd(int trang)
{
	int m[]={70,120,200,80,390,200};
	char td[][50]={"STT","MA HD","NGAY","LOAI","NHAN VIEN","TRI GIA"};
	taobang(290,245,32,6,m,15,0,11,1300-1,trang,td);
}


