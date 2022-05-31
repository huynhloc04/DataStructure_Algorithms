
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

NODE *init_node(int x)
{
    NODE *p = new NODE;
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void init_tree(TREE &t)
{
    t = NULL;
}

void add_tree(TREE &t, int x)
{
    if(t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if(x < t->data)
        {
            add_tree(t->pLeft, x);
        }
        else if (x > t->data)
        {
            add_tree(t->pRight, x);
        }  
    }  
}


void show_tree(TREE t)
{
    if(t != NULL)
    {
        //  NLR -> Xuất phần tử => Duyệt qua trái => duyệt qua phải  
        cout << t->data << " ";    
        show_tree(t->pLeft);
        show_tree(t->pRight);
    }
}

bool IsPrime(int x)
{
    if(x < 2)   return false;
    if(x == 2)  return true;
    int count=0;
    for(int i=2; i<x; i++)
    {
        if(x%i==0)
        {
            count++;
        }
    }
    if(count == 0)
    {
        return true;
    }
    return false;
}


//  Duyệt cây Left-Node-Right
void exam_LNR(TREE t, int &count)
{
    if(t != NULL)
    {
        exam_LNR(t->pLeft, count);
        if(IsPrime(t->data))
        {
            count ++;
            cout << t->data << " ";
        }
        exam_LNR(t->pRight, count);
    }
}

//  Tìm kiếm phần tử trong cây, nếu có trả về NODE đó, ngược lại trả về NULL
NODE *search_tree(TREE t, int x)
{
    if(t == NULL)
    {
        return NULL;
    }
    else
    {
        if(x < t->data)
        {
            search_tree(t->pLeft, x);
        }
        else if(x > t->data)
        {
            search_tree(t->pRight, x);
        }
        else
        {
            return t;
        }    
    }
}

//  Tìm phần tử lớn nhất trong cây
int find_MAX(TREE t)
{
    if(t->pRight == NULL)
    {
        return t->data;
    }
    find_MAX(t->pRight);
}


//  Tìm phần tử nhỏ nhất trong cây
int find_min(TREE t)
{
    if(t->pLeft == NULL)
    {
        return t->data;
    }
    find_min(t->pLeft);
}

//  Hàm tìm NODE thế mạng
void alter_node(TREE &k, TREE &alt)
{
    if(alt->pLeft != NULL)
    {
        alter_node(k, alt->pLeft);
    }
    //  Hàm tìm thấy NODE thế mạng(alter), bản chất xóa Node có 2 Node con là thay giá trị của nó bởi giá trị của Node alter, sau đó ta xóa Node alter đó.
    else
    {
        //  Cập nhật Node cần xóa là Node bên trái dưới cùng của Node bên phải t hiện tại
        k->data = alt->data;
        //  Cho con trỏ tạm thời k (ban đầu trỏ đến Node t hiện tại) trỏ đến Node alter bên trên
        k = alt;
        //  Cho Node bên trên Node alter trỏ đến NULL (Bởi vì bây giờ nó là Node lá do đã xóa mất Node alter)
        alt = alt->pLeft;
    }
}


//  Xóa 1 NODE bất lỳ trong cây nhị phân
void del_NODE(TREE &t, int data)    // data: Giá trị của NODE cần xóa
{
    //  Nếu cây rỗng
    if(t == NULL)
    {
        return;
    }
    if(data < t->data)
    {
        del_NODE(t->pLeft, data);
    }
    else if(data > t->data)
    {
        del_NODE(t->pRight, data);
    }
    else
    {
        NODE *k = t;    //  NODE thế mạng
        if(t->pLeft == NULL)
        {
            t = t->pRight;
        }
        else if(t->pRight == NULL)
        {
            t = t->pLeft;
        }
        else
        {
            NODE *alt = t->pRight;
            alter_node(k, alt);
        }
        delete k;
    }
}


int main()
{
    TREE t;
    init_tree(t);
    while(true)
    {
        system("cls");
        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;
        if(lc == 1)
        {
            int x;
            cout << "Nhap gia tri phan tu: ";
            cin >> x;
            add_tree(t, x);
        }
        else if(lc == 2)
        {
            cout << "Phan tu cua cay nhi phan: ";
            show_tree(t);
            system("pause");
        }
        else if(lc == 3)
        {
            cout << "Cac so nguyen to: ";
            int sl;
            exam_LNR(t, sl);
            cout << "\nSo luong so nguyen to co trong cay nhi phan: " << sl << endl;
            system("pause");
        }
        else if(lc == 4)
        {
            int x; 
            cout << "\nNhap gia tri can tim kiem: ";
            cin >> x;
            NODE *p = search_tree(t, x);
            if (p == NULL)
            {
                cout << "\nKhong co phan tu nao bang " << x << endl;
            }
            else
            {
                cout << "\nPhan tu " << x << " co ton tai trong cay.";
            }
            system("pause");
        }
        else if(lc == 5)
        {
            cout << "Gia tri LON nhat cua cay: " << find_MAX(t) << endl;
            system("pause");
        }
        else if(lc == 6)
        {
            cout << "Gia tri NHO nhat cua cay: " << find_min(t) << endl;
            system("pause");
        }
        else if(lc == 7)
        {
            int x; 
            cout << "=========== Xoa NODE ===========";
            cout << "\nNhap gia tri cua Node can xoa: ";
            cin >> x;
            del_NODE(t, x);
        }
        else    break;
    }
    return 0;
}
