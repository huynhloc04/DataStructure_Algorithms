
//  ========================= QUEUE =========================
//          (Thêm cuối lấy đầu)
//  Là 1 cấu trúc trừu tượng, các đối tượng trong stack phải làm việc theo 1 cơ chế FIFO(First In First Out) đối tượng vào trước sẽ ra trước
//  Các thao tác cơ bản
//   1. IsEmpty: Kiểm tra xem queue có rỗng hay ko
//   2. Push: Thêm 1 đối tượng vào cuối queue => Theo cơ chế FIFO
//   3. Pop: Lấy phần tử đầu queue và trả về giá trị, đồng thời phải HỦY nó đi => Theo cơ chế FLIFO
//   4. Top: Xem thông tin của đầu queue và không hủy nó đi

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct queue
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct queue QUEUE;

//  Initialize new node
NODE *init_node(int x)
{
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}


void init_queue(QUEUE &q)
{
    q.pHead = NULL;
    q.pTail = NULL;
}


// =========================== KIỂM TRA QUEUE CÓ RỖNG HAY KHÔNG ===========================
bool IsEmpty(QUEUE q)
{
    if(q.pHead == NULL)
    {
        return true;
    }
    return false;    //  queue có phần tử
}

//  =========================== THÊM PHẦN TỬ VÀO CUỐI QUEUE - FIFO ===========================
bool Push(QUEUE &q, NODE *p)
{
    if(p == NULL)
    {
        return false;
    }
    if(IsEmpty(q) == true)
    {
        q.pHead = q.pTail = p;
    }
    else
    {
        q.pTail->pNext = p;
        q.pTail = p;
    }    
    return true;
}

//  =========================== Pop: LẤY PHẦN TỬ ĐẦU QUEUE-TRẢ VỀ VÀ XÓA NÓ ĐI - FIFO ===========================\

bool Pop(QUEUE &q, int &x)
{
    if(IsEmpty(q) == true)
    {
        return false;
    }
    x = q.pHead->data;
    q.pHead = q.pHead->pNext;
    return true;
}

// =========================== Top: XEM THÔNG TIN CỦA PHẦN TỬ ĐẦU QUEUE (ko xóa nó) ===========================

bool Top(QUEUE &q, int &x)
{
    if(IsEmpty(q) == true)
    {
        return false;
    }
    x = q.pHead->data;
    return true;
}

void show_queue(QUEUE q)
{
    while(IsEmpty(q) == false)
    {
        int x;
        Pop(q, x);
        cout << "Phan tu trong queue: " << x << endl;
    }
    system("pause");
}

void menu(QUEUE &q)
{
    while (true)
    {       
        system("cls");
        cout << "\n\n\t\t ================ QUEUE ================" << endl;
        cout << "\t\t\t 1. Nhap phan tu vao QUEUE." << endl;
        cout << "\t\t\t 2. Xuat QUEUE." << endl;
        cout << "\t\t\t 3. Xem phan tu dau QUEUE." << endl;
        cout << "\t\t\t 4. Ket thuc." << endl;
        cout << "\t\t ====================== THE END ======================" << endl;

        int lc;
        cout << "\nNhap lua chon: ";
        cin >> lc;
        if(lc == 1)
        {
            int val;
            cout << "Nhap gia tri cua phan tu: ";
            cin >> val;
            NODE *p = init_node(val);
            Push(q, p);
        }
        else if(lc==2)
        {
            show_queue(q);
        }
        else if(lc==3)
        {
            int x;
            Top(q, x);
            cout << "Phan tu dau tien cua QUEUE: " << x << endl;
            system("pause");
        }
        else
        {
            break;
        }    
    }
}

int main()
{
    QUEUE q;
    init_queue(q);

    menu(q);

    return 0;
}



