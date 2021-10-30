#include <iostream>	//Quan li thu vien gom nhieu Sach		//main file
#include <string.h>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;
//tao cau truc sach
struct Sach {
    int ma;
    char ten[100];
};
//tao cau truc danh sach lien ket don
typedef struct Node
{
    Sach *data;
    Node *pNext;
}Node;
struct SingleList
{
    Node *pHead;
};
//khoi tao danh sach lien ket don
void Initialize(SingleList *&list)
{
    list = new SingleList;
    list->pHead = NULL;
}
//nhap thong tin Sach
Sach *NhapSach()
{
    Sach *sa = new Sach;	//khoi tao Sach
    
    cout << "Nhap ma so sach: ";
    cin >> sa->ma;
    cin.ignore();
    cout << "Nhap ten sach: ";
    gets(sa->ten);
    return sa;
}
//tao node sach
Node *CreateNode(Sach *sa)
{
    Node *pNode = new Node;
    if(pNode != NULL) {
        pNode->data = sa;
        pNode->pNext = NULL;
    }
    else {
        cout<<"Cap phat bo nho that bai!!!";
    }
    return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList *&list,Sach *sa) {
    Node *pNode = CreateNode(sa);
    if(list->pHead == NULL)
    {
        list->pHead = pNode;
    }
    else
    {
        Node *pTmp = list->pHead;
         
        while(pTmp->pNext != NULL)
        {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNode;
    }
}
//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp = list->pHead;
    if(pTmp == NULL) {
        cout << "Danh sach rong";
        return;
    }
    while(pTmp != NULL)
    {
        Sach *sa = pTmp->data;
        cout << sa->ma << "\t" << sa->ten << "\n";
        pTmp = pTmp->pNext;
    }
}
//sap xep
void SortList(SingleList *&list)
{
    for(Node *pTmp = list->pHead ; pTmp != NULL ; pTmp = pTmp->pNext)
    {
        for(Node *pTmp2 = pTmp->pNext ; pTmp2 != NULL ; pTmp2 = pTmp2->pNext)
        {   
            Sach *saTmp = pTmp->data;
            Sach *saTmp2 = pTmp2->data;
            if(saTmp2->ma < saTmp->ma)
            {
                int ma = saTmp->ma;
                char ten[150];
                strcpy(ten, saTmp->ten);
                 
                saTmp->ma = saTmp2->ma;
                strcpy(saTmp->ten, saTmp2->ten);
                saTmp2->ma = ma;
                strcpy(saTmp2->ten, ten);             
            }
        }   
    }
}
//xoa
void RemoveNode(SingleList *&list, int ma)
{
    Node *pDel = list->pHead;
    if(pDel == NULL) {
        cout << "Danh sach rong!";
    }
    else
    {
        Node *pPre = NULL;
        while(pDel != NULL)
        {
            Sach *sa = pDel->data;
            if(sa->ma == ma)
                break;
            pPre = pDel;
            pDel = pDel->pNext;
        }
        if(pDel == NULL)
        {
            cout << "Khong tim thay ma sach co san: " << ma;
        }
        else {
            if(pDel == list->pHead) {
                list->pHead = list->pHead->pNext;
                pDel->pNext = NULL;
                delete pDel;
                pDel= NULL;
            }
            else {
                pPre->pNext = pDel->pNext;
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
int main(int argc, char** argv) {	//main
    SingleList *list;
    Initialize(list);
    cout << "-------------- CHAO MUNG DEN VOI THU VIEN SU PHAM HCMUE ----------------" << endl << endl << endl;
    cout << "Ban can phai khai bao mot vai thong tin de co the truy cap vao thu vien" << endl;
    Sleep(2000);
    system("cls");
    cout << "-------------- CHAO MUNG DEN VOI THU VIEN SU PHAM HCMUE ----------------" << endl << endl << endl;
    Sach *first_book = NhapSach();
    InsertLast(list, first_book);	cout << endl << endl;
    Sach *second_book = NhapSach();
    InsertLast(list , second_book);		cout << endl << endl;
    Sach *third_book = NhapSach();
    InsertLast(list, third_book);	cout << endl << endl;
    PrintList(list);
    SortList(list);
    cout << "\nSau khi sap xep:\n";
    PrintList(list);
    cout << "\Ban muon loai bo quyen sach co ma la: ";
    int ma;
    cin >> ma;
    RemoveNode(list, ma);
    cout << "\nSau khi xoa:\n";
    PrintList(list);
    cout << endl << endl;
    cout << "************* Chuong trinh da ket thuc, nhom I_nhom_4 xin dung lai tai day ************" << endl;
    
    return 0;
}


/*#include<iostream>	//find replace 'sv' thanh 'khach'
#include<string>		// DANH SACH LIEN KET ____ QUAN LY THU VIEN
#include<fstream>
#include<bits/stdc++.h>
#include<Windows.h>

using namespace std;

typedef struct diem{
	float dai_so = 0;
	float Mac = 0;
	float cpp = 0;
}diem;

typedef struct khach{
	string ho;
	string ten;
	string ma_khach;
	string phai;
	diem ds_diem;
	
}khach;

struct node_khach{
	khach data;	//data
	node_khach *pnext;	//pointer tro toi data
};

typedef struct danh_sach_khach{
	node_khach *phead = NULL;
	node_khach *ptail = NULL;
}danh_sach_khach;

typedef struct node_khach node_khach;
void load_file(danh_sach_khach &ds_khach)
istream&operator >> (istream&is, khach &a);	//expected intializer before istream error
void menu();
node_khach* khoi_tao_node(khach x);
void them(danh_sach_khach &ds_khach, khach x);
void xuat(danh_sach_khach ds_khach);

void load_file(danh_sach_khach &ds_khach){
	ifstream filein("test_dslk.txt"); //duong dan file D:\Cau truc du lieu\test_dslk.txt
	
	while(filein.eof() == false){
		khach a;
		getline(filein, a.ho, ',');
		getline(filein, a.ten, ',');
		getline(filein, a.ma_khach, ',');
		getline(filein, a.phai, ',');
		filein >> a.ds_diem.dai_so;		filein.ignore();	//vuong dau phay trong bo test
		filein >> a.ds_diem.Mac;	filein.ignore();	//tuongtu
		filein >> a.ds_diem.cpp;	filein.ignore();	// bo dau \n xuong dong
		
		them(ds_khach, a);
	}
	//khach a;

	filein.close();
}



void menu(){	//Xu ly chinh
	//---Settings
	danh_sach_khach ds_khach;
	// ---- load du lieu nhap tu file co san
	load_file(ds_khach);
	//---- menu -----
	bool kt_menu = true;
	while (kt_menu == true){
		system("cls");
		cout << "1. Nhap thong tin khach" << endl;
		cout << "2. Xuat danh sach khach" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		
		cout << "Chon 1 lua chon"; 	int choice;	cin >> choice;
		//khach x;
		switch(choice){
			//khach x;
			case 1: 
				//khach x;
				int soluong;	cout << "Nhap so luong khach can them:" ;	cin >> soluong;
				cin.ignore();
				for(int i=1; i<= soluong;i++){
					cout << "\t\t ----------- Nhap Quy Khach thu "<< i << " ----------"<<endl; //trang tri
					
					khach x;	// luu tam du lieu ma ng dung nhap vao
					//cin.ignore();	
					cin >> x; 
					//getline(cin, x); cin.ignore();
					them(ds_khach, x);
				}
				break;
			
			case 2:
				xuat(ds_khach);
				system("pause");
				break;
				
			case 0:
				kt_menu = false;
				break;
		}
	}
	
}


istream&operator >> (istream&is, khach&a){
	cout << "Nhap ho: ";	getline(is, a.ho);
	cout << "Nhap ten: ";	getline(is, a.ten);
	cout << "Nhap phai: "	;	getline(is, a.phai);
	cout << "Nhap ma so khach (ID): ";	getline(is, a.ma_khach);
	return is;
}


node_khach* khoi_tao_node(khach x){
	node_khach *p = new node_khach;
	p->data = x;
	p->pnext = NULL;
}


void them(danh_sach_khach &ds_khach, khach x){
	node_khach *p = khoi_tao_node(x);
	if(ds_khach.phead == NULL){	//danh sach rong && dau cuoi = p
		//node_khach *p = khoi_tao_node(x);
		ds_khach.phead = ds_khach.ptail=p;
	}
	else{	// danh sach co n phan tu && them dau cuoi
		ds_khach.ptail->pnext = p;
		ds_khach.ptail = p;
	}
}

//check lai ham void them va ham void xuat
void xuat(danh_sach_khach ds_khach){
	for(node_khach *k = ds_khach.phead; k != NULL; k = k->pnext){
		//cout << "\t\t ---------- Sinh vien thu " << i++ << " -----------" << endl;
		cout << "Ho va ten: " << k->data.ho << " " << k->data.ten << endl;
		cout << "Ma Khach Hang: " << k->data.ma_khach << endl;
 		cout << "Gioi tinh (phai): " << k->data.phai << endl;
 		cout << "-------- BANG THONG TIN ------------" << endl;
 		
 		cout << "Diem dai so: " << k->data.ds_diem.dai_so << endl;
 		cout << "Diem Triet hoc Mac Lenin: " << k->data.ds_diem.Mac << endl;
 		cout << "Diem Lap trinh co ban C++: " << k->data.ds_diem.cpp << endl;
 		//cout << "Diem Triet hoc Mac Lenin: " << k->data.ds_diem.Mac << endl;
	}
}

int main(){
	
	//danh_sach_khach ds_khach;
	
	//ds_khach.phead->data.phai;
	menu();	//goi menu ra %% menu la ham chinh, main chi viec goi lai menu()
	
	return 0;
}
*/
