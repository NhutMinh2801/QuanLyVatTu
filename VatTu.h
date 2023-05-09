#pragma once
#include<iostream>
#include<string.h>
#include <fstream>
#include <cmath>
using namespace std;

//Tao Thong Tin cua mot Vat Tu moi
VatTu taoVatTu(char MaVT[], char TenVT[], char DVT[], float ton){
	VatTu vatTuTam;
	
	strcpy(vatTuTam.MAVT, MaVT);
	strcpy(vatTuTam.TENVT, TenVT);
	strcpy(vatTuTam.DVT, DVT);
	vatTuTam.ton = ton;
	
	return vatTuTam;
}
//Tao Mot Node Vat Tu
NodeVatTu *taoNodeVatTu(VatTu vatTu){
	NodeVatTu *nodeVatTuTam = new NodeVatTu;
	
	nodeVatTuTam->vatTu = vatTu;
	nodeVatTuTam->left=NULL;
	nodeVatTuTam->right=NULL;
	
	return nodeVatTuTam;
}
//Chen Node vao Cay chinh cua minh
void themNodeVaoCay(CayVatTu &cayVatTu, NodeVatTu *nodeVatTu){
	if(cayVatTu.root==NULL){
		cayVatTu.root = nodeVatTu;
	}
	else{
		NodeVatTu *tam = cayVatTu.root;
		NodeVatTu *truoctam = tam;
		
		while(tam!=NULL){
			truoctam=tam;
			if(strcmp(nodeVatTu->vatTu.MAVT, tam->vatTu.MAVT)<0){
				tam=tam->left;
			}
			else if(strcmp(nodeVatTu->vatTu.MAVT, tam->vatTu.MAVT)>0){
				tam=tam->right;
			}
		}
		
		if(strcmp(nodeVatTu->vatTu.MAVT, truoctam->vatTu.MAVT)<0){
			truoctam->left=nodeVatTu;
		}
		else if(strcmp(nodeVatTu->vatTu.MAVT, truoctam->vatTu.MAVT)>0){
			truoctam->right=nodeVatTu;
		}
	}
	cayVatTu.soluong++;
}
//Tim kiem vat tu theo MaVt
NodeVatTu *timKiemVatTu(CayVatTu cayVatTu, char MaVT[]){
	NodeVatTu *tam = cayVatTu.root;
	while(tam!=NULL){
		if(strcmp(tam->vatTu.MAVT, MaVT)==0){
			return tam;
		}
		else if(strcmp(MaVT, tam->vatTu.MAVT)<0){
			tam=tam->left;
		}
		else if(strcmp(MaVT, tam->vatTu.MAVT)>0){
			tam=tam->right;
		}
	}
	return NULL;
}
//Hieu Chinh truc tiep vat tu do - chinh su thong tin vat tu
void hieuChinhVatTuTheoMa(CayVatTu &cayVatTu, char MaVT[], char TenVTMoi[], char DVTMoi[]){
	NodeVatTu *tam = timKiemVatTu(cayVatTu, MaVT);
	if(tam!=NULL){
		strcpy(tam->vatTu.TENVT, TenVTMoi);
		strcpy(tam->vatTu.DVT, DVTMoi);
	}
}
// Xoa mot node theo ma vat tu
void xoaNodeKhoiCayTheoMa(CayVatTu &cayVatTu, char MaVT[]){
	if(strcmp(cayVatTu.root->vatTu.MAVT, MaVT)==0){
		if(cayVatTu.root->left==NULL && cayVatTu.root->right==NULL){
			NodeVatTu *xoa = cayVatTu.root;
			cayVatTu.root = NULL;
			delete xoa;
		}
		else if(cayVatTu.root->left==NULL){
			NodeVatTu *xoa = cayVatTu.root;
			cayVatTu.root = cayVatTu.root->right;
			delete xoa;
		}
		else if(cayVatTu.root->right==NULL){
			NodeVatTu *xoa = cayVatTu.root;
			cayVatTu.root = cayVatTu.root->left;
			delete xoa;
		}
		else{
			NodeVatTu *truocThayThe;
			NodeVatTu *thayThe = cayVatTu.root->right;
			truocThayThe = cayVatTu.root;
			
			while(thayThe->left!=NULL){
				truocThayThe = thayThe;
				thayThe = thayThe->left;
			}
			
			if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)<0){
				cayVatTu.root->vatTu = thayThe->vatTu;
				if(thayThe->right!=NULL) truocThayThe->left = thayThe->right;
				else truocThayThe->left=NULL;
			}
			else if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)>0){
				cayVatTu.root->vatTu = thayThe->vatTu;
				if(thayThe->right!=NULL) truocThayThe->right = thayThe->right;
				else truocThayThe->right = NULL;
			}
			delete thayThe;
		}
	}
	else{
		NodeVatTu *xoa = cayVatTu.root;
		NodeVatTu *truocXoa = cayVatTu.root;
		
		while(strcmp(xoa->vatTu.MAVT, MaVT)!=0 && xoa!=NULL){
			truocXoa = xoa;
			if(strcmp(MaVT, xoa->vatTu.MAVT)<0){
				xoa=xoa->left;
			}
			else if(strcmp(MaVT, xoa->vatTu.MAVT)>0){
				xoa = xoa->right;
			}
		}
		
		if(xoa!=NULL){
			if(xoa->left==NULL && xoa->right==NULL){
				if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)<0){
					truocXoa->left = NULL;
				}
				else if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)>0){
					truocXoa->right = NULL;
				}
				delete xoa;
			}
			else if(xoa->left==NULL){
				if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)<0){
					truocXoa->left = xoa->right;
				}
				else if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)>0){
					truocXoa->right = xoa->right;
				}
				delete xoa;
			}
			else if(xoa->right==NULL){
				if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)<0){
					truocXoa->left = xoa->left;
				}
				else if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)>0){
					truocXoa->right = xoa->left;
				}
				delete xoa;
			}
			else{
				NodeVatTu *truocThayThe;
				NodeVatTu *thayThe = xoa->right;
				truocThayThe = xoa;
				
				while(thayThe->left!=NULL){
					truocThayThe = thayThe;
					thayThe = thayThe->left;
				}
				
				if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)<0){
					xoa->vatTu = thayThe->vatTu;
					if(thayThe->right!=NULL) truocThayThe->left = thayThe->right;
					else truocThayThe->left = NULL;
				}
				else if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)>0){
					xoa->vatTu = thayThe->vatTu;
					if(thayThe->right!=NULL) truocThayThe->right = thayThe->right;
					else truocThayThe->right = NULL;
				}
				
				delete thayThe;
			}
		}
	}
	cayVatTu.soluong--;
}
//Xoa toan bo cay 2
void deQuyXoaNode(NodeVatTu *node){
	if(node!=NULL){
		deQuyXoaNode(node->left);
		deQuyXoaNode(node->right);
		delete node;
	}
}
//Xoa toan bo cay
void xoaToanBoCay(CayVatTu &cayVatTu){
	deQuyXoaNode(cayVatTu.root);
	cayVatTu.root=NULL;
	cayVatTu.soluong=0;
}
//Ghi cay Vat Tu vao file txt 2
void duyetNodeGhiVaoFile(fstream &f, NodeVatTu *node){
	if(node!=NULL){
		duyetNodeGhiVaoFile(f, node->left);
		duyetNodeGhiVaoFile(f, node->right);
		f<<node->vatTu.MAVT<<endl;
		f<<node->vatTu.TENVT<<endl;
		f<<node->vatTu.DVT<<endl;
		f<<node->vatTu.ton<<endl;
	}
}
//Ghi cay Vat Tu vao file txt
void ghiVatTuVaoFile(char tenfile[], CayVatTu cayVatTu){
	fstream f;
	
	f.open(tenfile, ios::out);
	
	if(f!=NULL){
		f<<cayVatTu.soluong<<endl;
		duyetNodeGhiVaoFile(f, cayVatTu.root);
	}
	
	f.close();
}
//Doc tu file doc vao cay
void docVatTuTuFile(char tenfile[], CayVatTu &cayVatTu){
	fstream f;
	
	f.open(tenfile, ios::in);
	
	if(f!=NULL){
		xoaToanBoCay(cayVatTu);
		int n=0;
		f>>n;
		f.ignore();
		VatTu tam;
		for(int i=0; i<n; i++){
			f.getline(tam.MAVT, sizeof(tam.MAVT), '\n');
			f.getline(tam.TENVT, sizeof(tam.TENVT), '\n');
			f.getline(tam.DVT, sizeof(tam.DVT), '\n');
			f>>tam.ton;
			f.ignore();
			themNodeVaoCay(cayVatTu, taoNodeVatTu(tam));
		}
	}
	
	f.close();
}

void duyetNode(NodeVatTu *node, VatTu *vt, int &i){
	if(node!=NULL){
		duyetNode(node->left, vt, i);
		vt[i]=node->vatTu;
		i++;
		duyetNode(node->right, vt, i);
	}
}
//Ho tro giao dien:
void doCayVaoMangVatTu(VatTu *&vt, CayVatTu cayVatTu){
	int n=cayVatTu.soluong;
	vt = new VatTu[n];
	int i=0;
	duyetNode(cayVatTu.root, vt, i);
	for(int d=0; d<n;d++){
		for(int d1=0;d1<n;d1++){
			if(strcmp(vt[d].TENVT,vt[d1].TENVT)>0){
				VatTu tem=vt[d];
				vt[d]=vt[d1];
				vt[d1]=tem;
			}
		}
	}
	
}
//chuyen tu chuoi thanh so thuc
float doiSangFloat(char ch[]){
	char chrFloat[7]="";
	char chrAFloat[7]="";
	int j=0;
	bool isAfter=false;
	int k=0;
	for(int i=0; i<strlen(ch); i++){
		if(!isAfter){
			if(ch[i]=='.'){
				chrFloat[j]=0;
				j=0;
				isAfter=true;
				continue;
			}
		}
		if(!isAfter)
		{
			chrFloat[j] = ch[i];
			j++;
		}
		else{
			chrAFloat[j] = ch[i];
			k++;
			j++;
		}
	}
	chrAFloat[j]=0;
	float fFloat=0;
	fFloat = (float) atoi(chrFloat) + ((float)atoi(chrAFloat)/pow(10,k));
	return fFloat;
}
//Chuyen so sang chuoi
void doiSangChuoi(char soTon[], float nFloat){
	strcpy(soTon,"");
	int a = floor(nFloat);
	char chrA[10]="";
	itoa(a, chrA, 10);
	strcat(soTon, chrA);
	a = floor(((float)nFloat-a)*100);
	itoa(a, chrA, 10);
	strcat(soTon, ".");
	strcat(soTon, chrA);
}

void inVatTu(VatTu data,int x, int y)
{
	//int m[]={65,200,200,300,200,100};
   char chrFloat[7]="";
   doiSangChuoi(chrFloat, data.ton);
   outtextxy(x+70,y,data.MAVT);
   outtextxy(x+70+200,y,data.TENVT);
   outtextxy(x+70+200+300,y,chrFloat);
   outtextxy(x+70+200+300+200,y, data.DVT);
}
//Ho tro giao dien: IN Vat tu
void inDSVatTu(VatTu *vt, int size, int x, int y, int trang)
{
	
	if(size==0)
	return;
	for(int i=0;i<10;i++)
	{
		if((trang-1)*10+i>=size)
		return;
		inVatTu(vt[(trang-1)*10+i],x,y);
		y=y+32;
	}
}
//Ho tro giao dien
void layThongTinVatTu(VatTu *vt, int i, int trang, int size, char MAVT[], char TENVT[], char DVT[], char chrFloat[], float &nfloat){
	if(i>=size) return;
	strcpy(MAVT, vt[i].MAVT);
	strcpy(TENVT, vt[i].TENVT);
	strcpy(DVT, vt[i].DVT);
	doiSangChuoi(chrFloat, vt[i].ton);
	nfloat = vt[i].ton;
	
	taoo(425,40,675,72,11,15,0);

	taoo(840,40,1100,72,12,15,0);
	
	taoo(345,80,675,112,13,15,0);
	
	taoo(840,80,1100,112,14,15,0);

outtextxy(425+5,40+5,MAVT);
outtextxy(840+5,40+5,TENVT);
outtextxy(345+5,80+5,chrFloat);
outtextxy(840+5,80+5,DVT);
//	system("pause");
}
