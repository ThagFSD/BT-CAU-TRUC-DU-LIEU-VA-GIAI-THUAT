#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PhatSinhMangTang(int a[], int N) {
    srand(time(0));
    a[0] = rand() % 10; 
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] + rand() % 10 + 1; 
    }
}

// Hàm xuất mảng
void XuatMang(int a[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int TimTuyenTinh(int a[], int N, int X) {
    int soSanh = 0; // Biến đếm số lần so sánh
    for (int i = 0; i < N; i++) {
        soSanh++;
        if (a[i] == X) {
            printf("  - So lan so sanh (Tuyen tinh): %d\n", soSanh);
            return i;
        }
    }
    printf("  - So lan so sanh (Tuyen tinh): %d\n", soSanh);
    return -1; 
}

int TimNhiPhan(int a[], int N, int X) {
    int left = 0, right = N - 1;
    int soSanh = 0; // Biến đếm số lần so sánh
    while (left <= right) {
        soSanh++;
        int mid = left + (right - left) / 2;
        if (a[mid] == X) {
            printf("  - So lan so sanh (Nhi phan): %d\n", soSanh);
            return mid;
        } else if (a[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("  - So lan so sanh (Nhi phan): %d\n", soSanh);
    return -1;
}

int TimNoiSuy(int a[], int N, int X) {
    int left = 0, right = N - 1;
    int soSanh = 0; // Biến đếm số lần so sánh
    while (left <= right && X >= a[left] && X <= a[right]) {
        soSanh++;
        int pos = left + ((double)(right - left) / (a[right] - a[left])) * (X - a[left]);

        if (a[pos] == X) {
            printf("  - So lan so sanh (Noi suy): %d\n", soSanh);
            return pos;
        } else if (a[pos] < X) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    printf("  - So lan so sanh (Noi suy): %d\n", soSanh);
    return -1;
}


int main() {
    int N;
    printf("Nhap kich thuoc mang N: ");
    scanf("%d", &N);

    int a[N];
    PhatSinhMangTang(a, N);

    printf("Mang da phat sinh: ");
    XuatMang(a, N);

    int x;
    printf("Nhap gia tri can tim x: ");
    scanf("%d", &x);

    int kqTuyenTinh = TimTuyenTinh(a, N, x);
    int kqNhiPhan = TimNhiPhan(a, N, x);
    int kqNoiSuy = TimNoiSuy(a, N, x);

    printf("Ket qua tim kiem:\n");
    printf("  - Phuong phap tuyen tinh: ");
    if (kqTuyenTinh != -1) {
        printf("Tim thay tai vi tri %d\n", kqTuyenTinh);
    } else {
        printf("Khong tim thay\n");
    }

    printf("  - Phuong phap nhi phan: ");
    if (kqNhiPhan != -1) {
        printf("Tim thay tai vi tri %d\n", kqNhiPhan);
    } else {
        printf("Khong tim thay\n");
    }

    printf("  - Phuong phap noi suy: ");
    if (kqNoiSuy != -1) {
        printf("Tim thay tai vi tri %d\n", kqNoiSuy);
    } else {
        printf("Khong tim thay\n");
    }

    return 0;
}