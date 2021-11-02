#include <iostream>	//Quan li thu vien gom nhieu Sach		//main file
#include <string.h>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//tao cau truc sach
typedef struct Sach {
    int ma;
    char ten[100];
    char tacgia[100];
    char nxb[150];
    char namxb[10];
}Sach;
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
//doc ghi file
/*void Filein(Sach *sa){	//ON_dev
	ifstream filein("input.txt");
	while(filein.eof() == true){
		Sach *sa= new Sach;
		
		cout << "Nhap ma so sach: ";
	    cin >> sa->ma;
	    cin.ignore();
	    cout << "Nhap ten sach: ";
	    gets(sa->ten);
	    cout << "Nhap ten tac gia: " ;
	    gets(sa->tacgia);
	    cout << "Nhap ten nha xuat ban sach: " ;
	    gets(sa->nxb);
	    cout << "Nhap nam xuat ban sach: ";
	    cin >> sa->namxb;
	    cin.ignore();
    
		
		//them(ds_khach, a);
	}
	filein.close();
}*/
//nhap thong tin Sach
Sach *NhapSach() {
    Sach *sa = new Sach; //khoi tao Sach
    
    cout << "Nhap ma so sach: ";
    cin >> sa->ma;
    cin.ignore();
    cout << "Nhap ten sach: ";
    gets(sa->ten);
    cout << "Nhap ten tac gia: " ;
    gets(sa->tacgia);
    cout << "Nhap ten nha xuat ban sach: " ;
    gets(sa->nxb);
    cout << "Nhap nam xuat ban sach: ";
    cin >> sa->namxb;
    cin.ignore();
    
    return sa;
}
//tao node sinh vien
Node *CreateNode(Sach *sa)
{
    Node *pNode = new Node;
    if(pNode != NULL) {
        pNode->data = sa;
        pNode->pNext = NULL;
    }
    else {
        cout << "Cap phat bo nho that bai!";
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
        cout << sa->ma << "\t\t" << sa->ten << "\t\t" << sa->tacgia << "\t\t" << sa->nxb << "\t\t"<< sa->namxb<< endl;
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
                char ten[100];
                char tacgia[100];
                char nxb[150];
                char namxb[10];
                
                strcpy(ten, saTmp->ten);
                
                saTmp->ma = saTmp2->ma;
                strcpy(saTmp->ten, saTmp2->ten);
                saTmp2->ma = ma;
                strcpy(saTmp2->ten, ten);
				//--------- modified ten tac gia ------------
				strcpy(tacgia, saTmp->tacgia);
                
               // saTmp->ma = saTmp2->ma;
              //  saTmp->tacgia = saTmp2->tacgia;
                strcpy(saTmp->tacgia, saTmp2->tacgia);
               // saTmp2->ma = ma;
           //     saTmp2->tacgia = tacgia;
                strcpy(saTmp2->tacgia, tacgia);
                
				//--------- modified ten nha xuat ban (nxb) ------------
				strcpy(nxb, saTmp->nxb);
                strcpy(saTmp->nxb, saTmp2->nxb);
                strcpy(saTmp2->nxb, nxb);
                
                //--------- modified string nam xuat ban (namxb) ------------
            	strcpy(namxb, saTmp->namxb);
                strcpy(saTmp->namxb, saTmp2->namxb);
                strcpy(saTmp2->namxb, namxb);
            }
        }   
    }
}
//xoa Node
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
	string pass;	//pass = abc
	cout << "------------- DANG NHAP VAO CHUONG TRINH -------------" <<endl << endl;
	cout << "Nhap mat khau cua admin:  ";		cin >> pass;
	if(pass == "abc"){
		system("cls");
		
		SingleList *list;
	    Initialize(list);
	    cout << "-------------- CHAO MUNG DEN VOI THU VIEN DH SU PHAM HCMUE ----------------" << endl << endl << endl;
	    cout << "Ban can phai khai bao mot vai thong tin de co the truy cap vao thu vien" << endl;
	    Sleep(2000);
	    system("cls");
	    cout << "-------------- CHAO MUNG DEN VOI THU VIEN DH SU PHAM HCMUE ----------------" << endl << endl << endl;
	    //Filein(Sach);
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
	    
	    Sleep(3500);
	    system("cls");
	    cout << "Ban muon loai bo quyen sach co ma la: ";
	    int ma;
	    cin >> ma;
	    RemoveNode(list, ma);
	    cout << "\nKet qua sau khi loai bo: \n";
	    PrintList(list);
	    cout << endl << endl;
	    cout << "************* Chuong trinh da ket thuc, nhom I_nhom_4 xin dung lai tai day ************" << endl;
	}
	else cout<<pass << " la mat khau sai, vui long nhap lai. Nhan Enter de thoat";
    
    
    return 0;
}
