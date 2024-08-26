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

int TimNoiSuy(int a[], int N, int X, int *ss) {
    int left = 0, right = N - 1;
    *ss = 0; 
    while (left <= right && X >= a[left] && X <= a[right]) {
        (*ss)++; 
        int pos = left + ((double)(right - left) / (a[right] - a[left])) * (X - a[left]);

        if (a[pos] == X) {
            return pos;
        } else if (a[pos] < X) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
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

    int ssTuyenTinh, ssNhiPhan, ssNoiSuy; // Biến lưu số lần so sánh

    int kqTuyenTinh = TimTuyenTinh(a, N, x, &ssTuyenTinh);
    int kqNhiPhan = TimNhiPhan(a, N, x, &ssNhiPhan);
    int kqNoiSuy = TimNoiSuy(a, N, x, &ssNoiSuy);

    printf("Ket qua tim kiem:\n");

    printf("  - Tuyen tinh: ");
    if (kqTuyenTinh != -1) {
        printf("Tim thay tai vi tri %d. ", kqTuyenTinh);
    } else {
        printf("Khong tim thay. ");
    }
    printf("So lan so sanh: %d\n", ssTuyenTinh);

    printf("  - Nhi phan: ");
    if (kqNhiPhan != -1) {
        printf("Tim thay tai vi tri %d. ", kqNhiPhan);
    } else {
        printf("Khong tim thay. ");
    }
    printf("So lan so sanh: %d\n", ssNhiPhan);

    printf("  - Noi suy: ");
    if (kqNoiSuy != -1) {
        printf("Tim thay tai vi tri %d. ", kqNoiSuy);
    } else {
        printf("Khong tim thay. ");
    }
    printf("So lan so sanh: %d\n", ssNoiSuy);

    return 0;
}