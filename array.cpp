
#include <iostream>
#include <vector>

using namespace std;

void add_elems(int *a, int &n, int pos, int val)
{
    int *temp = new int[n];
    for(int i=0; i<n; i++)
    {
        *(temp+i) = *(a+i); 
    }
    delete[] a;

    a = new int[n+1];
    for(int i=0; i<n; i++)
    {
        *(a+i) = *(temp+i);
    }
    delete[] temp;

    // Them phan tu
    for(int i=n-1; i>=pos; i--)
    {
        *(a+i+1) = *(a+i);
    }
    *(a+pos) = val;
    n++;
}

void del_elems(int *a, int &n, int pos)
{
    int *temp = new int[n];
    for(int i=0; i<n; i++)
    {
        *(temp+i) = *(a+i); 
    }
    delete[] a;

    for(int i=pos; i<n-1; i++)
    {
        *(temp+i) = *(temp+i+1);
    }

    a = new int[n-1];
    for(int i=0; i<n-1; i++)
    {
        *(a+i) = *(temp+i); 
    }
    delete[] temp;
    n--;

}

int main()
{
    int *a = new int[5];
    for(int i=0; i<5; i++)
    {
        a[i] = i+3;
    }

    for(int i=0; i<5; i++)
    {
        cout << *(a+i) << " ";
    }
    cout << endl;

    int n=5;
    int pos = 2;
    int val = 1000;
    // add_elems(a, n, pos, val);
    del_elems(a, n, pos);


//     vector<int> a(5, 2);
//     a.push_back(10);
//     a.clear();
//     a.resize(10, 1);
//     for(int i=0; i<a.size(); i++)
//     {
//         cout << a[i] << " ";
//     }
    return 0;
}
