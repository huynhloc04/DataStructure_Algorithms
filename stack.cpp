//  ========================= STACK =========================
//  Là 1 cấu trúc trừu tượng, các đối tượng trong stack phải làm việc theo 1 cơ chế LIFO(LAst In First Out) đối tượng vào sau sẽ ra trước
//  Các thao tác cơ bản
//   1. IsEmpty: Kiểm tra xem stack có rỗng hay ko
//   2. Push: Thêm 1 đối tượng vào đầu stack => Theo cơ chế LIFO
//   3. Pop: Lấy phần tử đầu stack và trả về giá trị của đối tượng đầu stack, đồng thời phải HỦY nó đi => Theo cơ chế LIFO
//   4. Top: Xem thông tin của đầu stack và không hủy nó đi


//  Nhập danh sacsh stack chứa các số nguyên, sau đó xuất ra màn  hình các giá trị số nguyên đó

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

//  Khi thao tác với stack, ta luôn thao tác với phần tử đầu tiên của stack, cần 1 con trỏ để quản lý => pTop
//  Khai báo cấu trúc stack, khác với DSLKĐ cần pHead/pTail, ta chỉ cần 1 con trỏ quản lý struct stack
struct stack
{
    NODE *pTop;
};
typedef struct stack STACK;

//  Khởi tạo 1 Node
NODE *init_node(int x)
{
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}

//  Khởi tạo stack
void init_stack(STACK &s)
{
    s.pTop = NULL;
}

// =========================== KIỂM TRA STACK CÓ RỖNG HAY KHÔNG ===========================
bool IsEmpty(STACK s)
{
    //  Nếu stack rỗng
    if(s.pTop == NULL)
    {
        return true;
    }
    return false;   // Stack có phần tử
}


//  =========================== THÊM PHẦN TỬ VÀO ĐẦU STACK - LIFO ===========================
bool Push(STACK &s, NODE *p)
{
    if(p == NULL)
    {
        return false; 
    }
    //  Nếu stack rỗng
    if(IsEmpty(s) == true)
    {
        s.pTop = p;     // Node p cũng chính là node đầu của stack luôn
    }
    else    // Stack đã có phần tử, thêm vào đầu stack tương tự như DSLKĐ
    {
        p->pNext = s.pTop;
        s.pTop = p;     // Cập nhật lại Node đầu
    }
    return true;
}


//  =========================== Pop: LẤY PHẦN TỬ ĐẦU STACK-TRẢ VỀ VÀ HỦY NÓ ĐI - LIFO ===========================
bool Pop(STACK &s, int &x)   //  x chính là giá trị cần lấy
{
    if(IsEmpty(s) == true)
    {
        return false;
    }
    x = s.pTop->data;   
    s.pTop = s.pTop->pNext;
    return true;    //  Lấy phần tử đầu stack thành công
}


// =========================== Top: XEM THÔNG TIN CỦA PHẦN TỬ ĐẦU STACK (ko xóa nó) ===========================

bool Top(STACK s, int &x)   // x là giá trị cần lấy ra để xem
{
    //  Nếu danh sách rỗng
    if(IsEmpty(s) == true)
    {
        return false;
    }
    x = s.pTop->data;   // Lấy giá trị của phần tử đầu stack để xem
    return true;
}

void show_stack(STACK s)
{
    while(IsEmpty(s) == false)
    {
        int x;
        Pop(s, x);
        cout << "Phan tu cua stack: " << x << endl;
    }
    system("pause");
}

void menu(STACK &s)
{
    while (true)
    {       
        system("cls");
        cout << "\n\n\t\t ================ STACK ================" << endl;
        cout << "\t\t\t 1. Nhap phan tu vao STACK." << endl;
        cout << "\t\t\t 2. Xuat STACK." << endl;
        cout << "\t\t\t 3. Xem phan tu dau STACK." << endl;
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
            Push(s, p);
        }
        else if(lc==2)
        {
            show_stack(s);
        }
        else if(lc==3)
        {
            int x;
            Top(s, x);
            cout << "Phan tu dau tien cua danh sach: " << x << endl;
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
    STACK s;
    init_stack(s);

    menu(s);

    return 0;
}