
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


//  Khởi tạo cây nhị phân
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
    else    // Cây có tồn tại phần tử
    {
        if(x < t->data)     //   Giá trị của x nhỏ hơn node gốc, thêm vào bên trái
        {
            add_tree(t->pLeft, x);
        }
        else if(x > t->data)
        {
            add_tree(t->pRight, x);   //   Giá trị của x lớn hơn node gốc, thêm vào bên phải
        }
    }
}

//  Xuất cây nhị phân theo NLR (Node-Left-Right)
void exam_NLR(TREE t)
{
    if(t != NULL)
    {
        //  NLR -> Xuất phần tử, duyệt qua trái rồi qua phải
        cout << t->data << " ";
        exam_NLR(t->pLeft);     
        exam_NLR(t->pRight);
    }
}

//  Xuất cây nhị phân theo NRL (Node-Right-Left)
void exam_NRL(TREE t)
{
    if(t != NULL)
    {
        //  NRL -> Xuất phần tử, duyệt qua phải rồi qua trái 
        cout << t->data << " ";
        exam_NRL(t->pRight);     
        exam_NRL(t->pLeft);
    }
}

//  Xuất cây nhị phân theo LNR (Left-Node-Right)    (Xuất các phần tử từ nhỏ -> lớn / bài toán sắp xếp tăng dần)
void exam_LNR(TREE t)
{
    if(t != NULL)
    {
        //  LNR -> Duyệt qua trái => Xuất phàn tử => duyệt qua phải      
        exam_LNR(t->pLeft);
        cout << t->data << " ";
        exam_LNR(t->pRight);
    }
}

//  Xuất cây nhị phân theo LNR (Right-Node-Left)    (Xuất các phần tử từ lớn -> nhỏ/ bài toán sắp xếp giảm dần)
void exam_RNL(TREE t)
{
    if(t != NULL)
    {
        //  RNL -> Duyệt qua PHẢI => Xuất phàn tử => duyệt qua TRÁI      
        exam_RNL(t->pRight);
        cout << t->data << " ";
        exam_RNL(t->pLeft);
    }
}

//  Xuất cây nhị phân theo LRN (Left-Right-Node)    
void exam_LRN(TREE t)
{
    if(t != NULL)
    {
        //  LRN -> Duyệt qua TRÁI => duyệt qua PHẢI => Xuất phàn tử 
        exam_LRN(t->pLeft);   
        exam_LRN(t->pRight);
        cout << t->data << " ";
    }
}

//  Xuất cây nhị phân theo RLN (Right-Left-Node)    
void exam_RLN(TREE t)
{
    if(t != NULL)
    {
        //  RLN -> Duyệt qua PHẢI => duyệt qua TRÁI => Xuất phàn tử      
        exam_RLN(t->pRight);
        exam_RLN(t->pLeft);
        cout << t->data << " ";
    }
}



void menu(TREE &t)
{
    while (true)
    {       
        system("cls");
        cout << "\n\n\t\t ================ STACK ================" << endl;
        cout << "\t\t\t 1. Nhap du lieu vao cay." << endl;
        cout << "\t\t\t 2. Xuat Node-Left-Right." << endl;
        cout << "\t\t\t 3. Xuat Node-Right-Left." << endl;
        cout << "\t\t\t 4. Xuat Left-Node-Right." << endl;
        cout << "\t\t\t 5. Xuat Right-Node-Left." << endl;
        cout << "\t\t\t 6. Xuat Left-Right-Node." << endl;
        cout << "\t\t\t 6. Xuat Right-Left-Node." << endl;
        cout << "\t\t\t 10. Ket thuc." << endl;
        cout << "\t\t ====================== THE END ======================" << endl;

        int lc;
        cout << "\nNhap lua chon: ";
        cin >> lc;

        if(lc == 1)
        {
            int x;
            cout << "Nhap phan tu: ";
            cin >> x;
            add_tree(t, x);
        }
        else if(lc == 2)    // (Node-Left_Right)
        {
            cout << "Phan tu cua tree: ";
            exam_NLR(t);
            system("pause");
        }
        else if(lc == 3)    //  (Node-Right-Left)
        {            
            cout << "Phan tu cua tree: ";
            exam_NRL(t);
            system("pause");
        }
        else if(lc == 4)    //  (Left-Node-Right)
        {            
            cout << "Phan tu cua tree: ";
            exam_LNR(t);
            system("pause");
        }
        else if(lc == 5)    //  (Right-Node-Left)
        {            
            cout << "Phan tu cua tree: ";
            exam_RNL(t);
            system("pause");
        }
        else if(lc == 6)    //  (Right-Left-Node)
        {            
            cout << "Phan tu cua tree: ";
            exam_LRN(t);
            system("pause");
        }
        else if(lc == 7)    //  (Left-Right-Node)
        {            
            cout << "Phan tu cua tree: ";
            exam_RLN(t);
            system("pause");
        }
        else     break;
    }
}


int main()
{
    TREE t;
    init_tree(t);

    menu(t);
    
    return 0;
}