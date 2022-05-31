
// ================================= ƯU ĐIỂM =================================
//   1. Việc THÊM, XÓA chỉ đơn giản là việc thay đổi các liên kết giữa các NODE
//   2. Các p.tử không cần nằm liên tiếp nhau => Khắc phục tình trạng phân mảnh bộ nhớ


// ================================= NHƯỢC ĐIỂM =================================
//   1. Không thể truy xuất đến từng phần tử thông qua toán tử chỉ số, phải duyệt tuần tự từ đầu cho đến cuối
//   2. Tốn bộ nhớ. Do chưa thêm con trỏ để liên kết giữa các NODE với nhau


#include <iostream>
using namespace std;

//  Biến toàn cục chỉ số lượng NODE trong DSLK
int n = 0;

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

//  Initialize a NODE
NODE *init_node(int x)
{
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}


//  Initialize a link list
void init_lnklst(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}


//  Hàm thêm NODE vào đầu DSLK
void add_first(LIST &l, NODE *p)
{
    // Danh sach đang rỗng
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;  // Node đầu chính là Node cuối và là p luôn
    }
    else
    {
        p->pNext = l.pHead;   // Cho con trỏ của Node cân thêm: Node p l.kết đến Node đầu: pHead
        l.pHead = p;
    }
}


void add_last(LIST &l, NODE *p)
{
    // Danh sach đang rỗng
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;  // Node đầu chính là Node cuối và là p luôn
    }
    else
    {
        l.pTail->pNext = p;   // Cho con trỏ của Node cân thêm: Node pTail l.kết đến Node p
        l.pTail = p;
    }
}


//   Ham xuat DSLKD.
void show_list(LIST l)
{
    for(NODE *i=l.pHead; i!=NULL; i=i->pNext)
    {
        cout << i->data << " ";
    }
    system("pause");
}


void enter_list(LIST &l)
{
    cout << "Nhap so luong phan tu cua DSLK: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cout << "Nhap phan tu cua NODE " << i+1 << ": ";
        cin >> x;

        NODE *p = init_node(x);
        add_last(l, p);
    }    
    cout << "Danh sach lien ket cua ban: ";
    show_list(l);
}

// ==============================================================================
// ============================= THÊM PHẦN TỬ ===================================
// ==============================================================================

//  Thêm NODE p vào sau NODE q
void _add_post_q(LIST &l, NODE *q, int x)
{
    for(NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        if(i->data == q->data)
        {                        
            //  Tạo NODE p ở địa chỉ khác để tránh mất phần tử
            NODE *p = init_node(x);
            p->pNext = i->pNext;
            i->pNext = p;
            n++;
        }
    }
}

//  Thêm NODE p vào trước NODE q
void _add_pre_q(LIST &l, NODE *q, int x)
{
    NODE *g = new NODE;
    for(NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        if(i->data == q->data)
        {
            NODE *p = init_node(x);
            if(i == l.pHead)
            {
                // //  Add first
                p->pNext = l.pHead;
                l.pHead = p;
            }
            else
            {
                p->pNext = g->pNext;
                g->pNext = p;
            }
            n++;
        }
        g = i;
    }
}


//  Thêm NODE tại vị trí bất kỳ
void _add_any(LIST &l, int pos, int val)
{
    if(pos==1)
    {
        add_first(l, init_node(val));
        n++;
    }
    else if(pos > n)
    {
        add_last(l, init_node(val));
        n++;
    } 
    else
    {
        int idx = 1;
        for(NODE *i = l.pHead; i != NULL; i = i->pNext)
        {
            if(idx == pos)
            {
                NODE *q = i;
                _add_pre_q(l, q, val);
                break;
            }
            idx++;
        }           
    }
    show_list(l);
}



// ==============================================================================
// ============================== XÓA PHẦN TỬ ===================================
// ==============================================================================

//  Xóa phần tử ở đầu DS
void del_first(LIST &l)
{
    //  Nếu danh sách rỗng
    if(l.pHead == NULL)
    {
        return;
    }
    // NODE *temp = l.pHead;
    l.pHead = l.pHead->pNext;
    // delete temp;
    n--;    // Update n
}

//  Xóa phần tử ở cuối danh sách
void del_last(LIST &l)
{
    if(l.pHead == NULL)     return;
    //  Trường hợp danh sách có 1 phần tử
    if(l.pHead->pNext == NULL)      del_first(l);
    for(NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        if(i->pNext == l.pTail)
        {
            delete l.pTail;
            i->pNext = NULL;
            l.pTail = i;
            n--;
        }
    }
}


//  Xóa NODE sau NODE q
void del_post_q(LIST &l, NODE *q)
{
    for(NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        if(i->data == q->data)
        {
            NODE *g = i->pNext;     // Này là NODE cần xóa
            i->pNext = g->pNext;    // Liên kết NODE hiện tại đến NODE sau NODE cần xóa(q)
            delete g;               // Xóa NODE q
            n--;
        }
    }
}

//  Xóa NODE trước NODE q
void del_pre_q(LIST &l, NODE *q)
{
    NODE *g = new NODE;
    for(NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        if(i->pNext->data == q->data)
        {
            g->pNext = i->pNext;
            n--;
        }            
        g = i;
    }
}

//  Xóa NODE tại vị trí bất kỳ
void del_any(LIST &l, int pos)
{
    int j=1;
    for(NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        if(j+1 == pos)
        {
            NODE *g = i->pNext;
            i->pNext = g->pNext;
            delete g;
            n--;
        }
        j++;
    }
}


void menu(LIST &l)
{
    while (true)
    {       
        system("cls");
        cout << "\n\n\t\t ================ DANH SACH LIEN KET DON ================" << endl;
        cout << "\t\t\t 1. Nhap - Xuat danh sach lien ket don." << endl;
        cout << "\t\t\t 2. Them NODE p vao sau NODE q." << endl;
        cout << "\t\t\t 3. Them NODE p vao truoc NODE q." << endl;
        cout << "\t\t\t 4. Them NODE p tai vi tri bat ki." << endl;
        cout << "\t\t\t 5. Xoa phan tu dau tien." << endl;
        cout << "\t\t\t 6. Xoa phan tu cuoi cung." << endl;
        cout << "\t\t\t 7. Xoa NODE p sau NODE q." << endl;
        cout << "\t\t\t 8. Xoa NODE p truoc NODE q." << endl;
        cout << "\t\t\t 9. Xoa NODE p tai vi tri bat ki." << endl;
        cout << "\t\t\t 10. So luong phan tu cua mang." << endl;
        cout << "\t\t\t 11. Ket thuc." << endl;
        cout << "\t\t ====================== THE END ======================" << endl;

        int lc;
        cout << "\nNhap lua chon: ";
        cin >> lc;
        if(lc == 1)
        {
            enter_list(l);
        }
        else if(lc == 2)
        {
            cout << "\n================== Them NODE p vao sau NODE q. ==================" << endl;
            int x, val;
            cout << "Phan tu muon them vao nam sau phan tu: ";
            cin >> x;
            cout << "Nhap gia tri cua phan tu muon them vao: ";
            cin >> val;
            NODE *q = init_node(x);
            _add_post_q(l, q, val);
            show_list(l);
        }
        else if(lc == 3)
        {
            cout << "\n================== Them NODE p vao truoc NODE q. ==================" << endl;
            int x, val;
            cout << "Phan tu muon them vao truoc truoc phan tu: ";
            cin >> x;
            cout << "Nhap gia tri cua phan tu muon them vao: ";
            cin >> val;
            NODE *q = init_node(x);
            _add_pre_q(l, q, val);
            show_list(l);
        }
        else if(lc == 4)
        {
            cout << "\n================== Them NODE p vao vi tri bat ky. ==================" << endl;
            int pos, val;
            cout << "Vi tri muon them vao: ";
            cin >> pos;
            cout << "Gia tri cua phan tu muon them vao: ";
            cin >> val;
            _add_any(l, pos, val);
        }
        else if(lc == 5)
        {
            cout << "\n================== Xoa NODE p o dau danh sach. ==================" << endl;
            del_first(l);
            show_list(l);
        }
        else if(lc == 6)
        {
            cout << "\n================== Xoa NODE p o cuoi danh sach. ==================" << endl;
            del_last(l);
            show_list(l);
        }
        else if(lc == 7)
        {
            cout << "\n================== Xoa NODE sau NODE q. ==================" << endl;
            int val;
            cout << "Gia tri cua phan tu sau phan tu can xoa: ";
            cin >> val;
            del_post_q(l, init_node(val));
            show_list(l);
        }
        else if(lc == 8)
        {
            cout << "\n================== Xoa NODE truoc NODE q. ==================" << endl;
            int val;
            cout << "Gia tri cua phan tu truoc phan tu can xoa: ";
            cin >> val;
            del_pre_q(l, init_node(val));
            show_list(l);
        }
        else if(lc == 9)
        {
            cout << "\n================== Xoa NODE tai vi tri bat ky. ==================" << endl;
            int pos;
            cout << "Vi tri cua phan tu can xoa: ";
            cin >> pos;
            del_any(l, pos);
            show_list(l);
        }
        else if(lc == 10)
        {
            cout << "So luong phan tu cua mang hien tai: " << n << endl;
            show_list(l);
        }
        else    break;
    }
}


int main()
{
    LIST l;
    //  Khởi tạo DSLKĐ
    init_lnklst(l);
    
    menu(l);
    
    return 0;
}