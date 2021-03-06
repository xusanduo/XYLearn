#include "MyList.h"
#include <iostream>
using namespace std;
CMyList::CMyList(const int a[], int n) {
    if (n > MAXSIZE) throw "too large!";
    for (int i = 0; i < n; i++) {
        this->data[i] = a[i];
    }
    this->length = n;
}

CMyList::~CMyList() {
}

int CMyList::GetValue(int index) {
    if (index >= length || index < 0) throw "wrong place!";
    return this->data[index];
}

int CMyList::GetIndex(int key) {
    for (int i = 0; i < length; i++) {
        if (data[i] == key)
            return i;
    }
    return -1;
}
void CMyList::Print() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
void CMyList::Insert(int i, int key) {
    if (i < 0 || i > length) throw "wrong place!";
    if (length > MAXSIZE - 1) throw "too large!!";
    for (int j = length; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = key;
    length++;
}

int CMyList::Delete(int i) {
    if (length == 0) throw "wrong!";
    if (i < 0 || i > length) throw "wrong place!";
    int x = data[i];
    for (int j = i; j < length; j++) {
        data[j] = data[j + 1];
    }
    length--;
    return x;
}

// void CMyList::Joseph(int i)
// {
//     int start = 1;
//     while (this->GetLength() != 1)
//     {
//         int m = (start + i - 1) % GetLength();
//         start = (m==0?length:m);
//         cout << this->GetValue(start) << ' ';
//         this->Delete(start );
//     }
//     cout << this->GetValue(1) << endl;
// }
