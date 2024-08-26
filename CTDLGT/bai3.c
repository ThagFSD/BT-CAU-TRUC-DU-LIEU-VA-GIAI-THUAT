#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h> 

void XuatMang(int a[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int TimTuyenTinh(int a[], int N, int X, int *ss) {
    *ss = 0; 
    for (int i = 0; i < N; i++) {
        (*ss)++; 
        if (a[i] == X) {
            return i; 
        }
    }
    return -1; 
}

int TimNhiPhan(int a[], int N, int X, int *ss) {
    int left = 0, right = N - 1;
    *ss = 0; 
    while (left <= right) {
        (*ss)++; 
        int mid = left + (right - left) / 2;
        if (a[mid] == X) {
            return mid;
        } else if (a[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int TimNhiPhan2(int a[], int N, int X, int *ss) {
    int left = 0, right = N - 1;
    *ss = 0; 
    while (left <= right) {
        (*ss)++; 
        int mid = left + (right - left) / 2;
        if (a[mid] == X) {
            return mid;
        } else if (a[mid] > X) {  
            left = mid + 1;       
        } else {
            right = mid - 1;   
        }
    }
    return -1;
}

bool KiemTraTang(int a[], int N) {
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

// Kiểm tra mảng giảm dần
bool KiemTraGiam(int a[], int N) {
    for (int i = 1; i < N; i++) {
        if (a[i] > a[i - 1]) {
            return false;
        }
    }
    return true;
}

void PhatSinhMang(int a[], int N) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100; 
    }
}

int main() {
    char luaChon[3];
    printf("Nhap NN de phat sinh mang ngau nhien, SX de tao mang sap xep tang, GD de tao mang sap xep giam: ");
    scanf("%s", luaChon);

    int N;
    printf("Nhap kich thuoc mang N: ");
    scanf("%d", &N);

    int a[N];

    if (strcmp(luaChon, "NN") == 0) {
        PhatSinhMang(a, N);
    } else if (strcmp(luaChon, "SX") == 0) {
        for (int i = 0; i < N; i++) {
            a[i] = i;
        }
    } else if (strcmp(luaChon, "GD") == 0) {
        for (int i = 0; i < N; i++) {
            a[i] = N - 1 - i; // Tạo mảng giảm dần từ N-1 về 0
        }
    } else {
        printf("Lua chon khong hop le. Chuong trinh se thoat.\n");
        return 1; 
    }

    printf("Mang da nhap/phat sinh: ");
    XuatMang(a, N);

    int x;
    printf("Nhap gia tri can tim x: ");
    scanf("%d", &x);

    int ss;
    int kq = -1;

    if (KiemTraTang(a, N)) {
        kq = TimNhiPhan(a, N, x, &ss);
        printf("  - Nhi phan (mang tang): ");
    } else if (KiemTraGiam(a, N)) {
        kq = TimNhiPhan2(a, N, x, &ss); // Sử dụng tìm kiếm nội suy cho mảng giảm dần
        printf("  - Nhi phan (mang giam): ");
    } else {
        kq = TimTuyenTinh(a, N, x, &ss);
        printf("  - Tuyen tinh: ");
    }

    if (kq != -1) {
        printf("Tim thay tai vi tri %d. ", kq);
    } else {
        printf("Khong tim thay. ");
    }
    printf("So lan so sanh: %d\n", ss);

    return 0;
}