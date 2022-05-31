#include <iostream>

using namespace std;

void show_arr(int a[], int n)
{
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
}

//  ===================== Bubble_Sort =====================
void bubble_sort(int a[], int n)
//  So sánh và chuyển giá trị lớn nhất về cuối hàng
{
    int k=0;
    while(k<n)
    {
        int isSorted = 1;
        for(int i=0; i<n-1; i++)
        {
            int temp;
            if(a[i] > a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                isSorted = 0;
            }
        }
        k++;
        if(isSorted == 1)
        {
            break;
        }
        show_arr(a, n);
    }
}


//  ===================== Insertion_Sort =====================
void insertion_sort(int a[], int n)
//  Giả sử phần tử bên trái sắp xếp tăng và chèn phần tử bên phải gtr hiện tại qua bên trái theo thứ tự tăng dần
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        int ai = a[i];
        if(ai>a[j])
        {
            continue;
        }
        while(j>=0 && ai<a[j])
        {
            int temp;
            temp = a[j];
            a[j] = ai;
            a[j+1] = temp;
            j--;
        }
        show_arr(a, n);
    }
}


//  ===================== Selection_Sort =====================
//  Hoán đổi vị trí phần tử hiện tại và giá trị min của ptu i+1 đến cuối
void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int temp;
        int idx_min = i+1;
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[idx_min])
            {
                idx_min = j;
            }
        }
        temp = a[i];
        a[i] = a[idx_min];
        a[idx_min] = temp;
        show_arr(a, n);
    }
}

int main()
{
    int a[] = {5, 3, 2, 7, 8, 1, 2};
    int n = sizeof(a)/sizeof(int);
    show_arr(a, n);
    selection_sort(a, n);
    // cout << "\nArray after sorting: \n";
    // show_arr(a, n);

    return 0;
}