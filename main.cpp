#include <iostream>

using namespace std;
int n;
struct Node{
    int data;
    Node *next;//chua dia chi node ke tiep ma no tro toi
};

struct List{
    Node *head;
    Node * tail;
};

//khoi tao list

void Init(List &l){
    l.head=l.tail=NULL;
}
Node *createNode(int x){
    //tao node moi
    Node *p=new Node;
    if(p==NULL) return NULL;
    p->data=x;
    p->next=NULL;
    return p;
}

//kiem tra danh sach
bool isEmpty(List l){
    if(l.head==NULL) return true;
    return false;
}

//chen vao dau list
void addHead(List &l,int x){
    Node *p=createNode(x);
    if(isEmpty(l)) l.head=l.tail=p;
    else{
        p->next=l.head;//
        l.head=p;
    }
}
void addTail(List &l,int x){
    Node *p=createNode(x);
    if(isEmpty(l)) l.head=l.tail=p;
    else{
        l.tail->next=p;
        l.tail=p;
    }
}

//tim kiem node
Node *Search(List &l,int k){
    Node *p=l.head;
    if(p->next!=NULL){
        while(p!=NULL){
        if(p->data==k ) return p;
        else
            p=p->next;
        }
        return NULL;
    }
    return NULL;
}

//addMid
void addMid(List &l,int x,int k){
    Node *p=Search(l,k);
    if(p!=NULL){
         Node *q=createNode(x);
         Node *r=p->next;
         q->next=r;
         p->next=q;

    }
}
//nhap vao mot list bat ki
void addAtK(List &l,int x,int k){
    if(isEmpty(l)|| k<=1) addHead(l,x);
    else if(k>=n) addTail(l,x);
    else{
        Node *p=createNode(x);
        Node *q=new Node,*w=new Node;
        Node *r=l.head;
        int dem=0;
        while(r!=NULL){
            dem++;
            q=r;
            if(dem==k) break;
            else r=r->next;
        }
        w=l.head;
        while(w->next!=q){
            w=w->next;
        }
        p->next=q;
        w->next=p;

    }
}

//void nhap
void nhap(List &l){
    cout << "\Nhap so ptu ban dau cua List: "; cin >>n;
    for(int i=1;i<=n;i++) {addTail(l,i);}
}
//void xuat
void xuat(List l){
    Node *p=l.head;
    while(p!=NULL){
        cout << " " << p->data << " ";
        p=p->next;
    }
}

//delHead

void delHead(List &l){
    if(!isEmpty(l)){
        Node *p=l.head;
        l.head=l.head->next;//
        delete p;//xoa bo node ban dau
    }
}
//xoa Tail
void delTail(List &l){
    if(!isEmpty(l)){
        Node *p=l.head;
        Node *q=new Node;
        while(p->next!=l.tail) p=p->next;
        q=p;//gan node nay cho node q;
        p=p->next;
        l.tail=q;//cap nhat node tail
        l.tail->next=NULL;//cap nhat node tail
        delete p;
    }
}

//xoa vi tri batg ki

void delAtK(List &l,int k){
    if(k<=1) delHead(l);
    else if(k>=n) delTail(l);
    else{
        int dem=0;
        if(!isEmpty(l)){
            Node *p=l.head;
            Node *q=new Node;//doe can xoa
            while(p!=NULL){
                dem++;
                q=p;
                if(dem==k) break;
                else{
                    p=p->next;
                }
            }
            Node *r=l.head;//node truoc node can xoa
            while(r->next!=q) r=r->next;

            //capp nhat lại
            r->next=q->next;
            delete q;

        }
    }
}
void menu(){
    List l;
    Init(l);
    nhap(l);
    xuat(l);
    int k,x,luachon;
    do{
        cout <<"\n_____________MENU______________\n1.Chen dau \n2.Chen cuoi"
            << "\n3.chen sau vi tri node data=x\n4.Chen vao vi tri bat ki"
            <<"\5.Xuat thong tin List\n6.Xoa phan tu dau list"
            <<"\7.Xoa phan tu o cuoi list\n8.Xoa node o vi tri k"
            <<"\n0.Thoat \nMoi ban chon";
            cin >>luachon;
            switch(luachon){
                case 0:break;
                case 1:cout<<"Nhap x: "; cin >>x; addHead(l,x);n++;break;
                case 2:cout<<"Nhap x: "; cin >>x; addTail(l,x);n++;break;
                case 3:cout<<"Nhap x,k: "; cin >>x>>k; addMid(l,x,k);n++;break;
                case 4:cout<<"Nhap x, vi tri k: "; cin >>x>>k; addAtK(l,x,k);n++;break;
                case 5:xuat(l);break;
                case 6:delHead(l); n--;break;
                case 7:delTail(l);n--;break;
                case 8: cout << "Nhap vi tri k can xoa";cin >>k;delAtK(l,k); n--;break;
            }

    }while(luachon!=0);
}
int main()
{
    menu();
    return 0;
}
