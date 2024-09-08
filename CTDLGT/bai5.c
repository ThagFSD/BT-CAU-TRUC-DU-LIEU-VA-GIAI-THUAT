#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Hàm xuất mảng
void XuatMang(int a[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm phát sinh mảng ngẫu nhiên bai3
void PhatSinhMang(int a[], int N) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100; 
    }
}

// Hàm phát sinh mảng tăng dần bai1
void PhatSinhMangTang(int a[], int N) {
    srand(time(0));
    a[0] = rand() % 10; 
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] + rand() % 10 + 1; 
    }
}

// Hàm phát sinh mảng giảm dần
void PhatSinhMangGiam(int a[], int N) {
    PhatSinhMangTang(a, N); // Tạo mảng tăng dần trước
    for (int i = 0; i < N / 2; i++) {
        HoanVi(&a[i], &a[N - 1 - i]); // Đảo ngược mảng để có mảng giảm dần
    }
}

// Hàm hoán vị hai phần tử 
void HoanVi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function prototypes
void SelectionSort(int a[], int N, int *soSanh, int *soGan);
void InsertionSort(int a[], int N, int *soSanh, int *soGan);
void InterchangeSort(int a[], int N, int *soSanh, int *soGan);
void BubbleSort(int a[], int N, int *soSanh, int *soGan);
int Partition(int a[], int low, int high, int *soSanh, int *soGan);
void QuickSort(int a[], int low, int high, int *soSanh, int *soGan);

// 1. Sắp xếp chọn trực tiếp - Selection Sort
void SelectionSort(int a[], int N, int *soSanh, int *soGan) {
    *soSanh = 0;
    *soGan = 0;
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            (*soSanh)++;
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        HoanVi(&a[i], &a[minIndex]);
        (*soGan)++;
        printf("Buoc %d: ", i + 1);
        XuatMang(a, N);
    }
}

// 2. Sắp xếp chèn trực tiếp - Insertion Sort
void InsertionSort(int a[], int N, int *soSanh, int *soGan) {
    *soSanh = 0;
    *soGan = 0;
    for (int i = 1; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            (*soSanh)++;
            a[j + 1] = a[j];
            j--;
            (*soGan)++;
        }
        a[j + 1] = key;
        (*soGan)++;
        printf("Buoc %d: ", i);
        XuatMang(a, N);
    }
}

// 3. Sắp xếp đổi chỗ trực tiếp - Interchange Sort
void InterchangeSort(int a[], int N, int *soSanh, int *soGan) {
    *soSanh = 0;
    *soGan = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            (*soSanh)++;
            if (a[i] > a[j]) {
                HoanVi(&a[i], &a[j]);
                (*soGan)++;
                printf("Buoc %d-%d: ", i + 1, j + 1);
                XuatMang(a, N);
            }
        }
    }
}

// 4. Sắp xếp nổi bọt - Bubble Sort
void BubbleSort(int a[], int N, int *soSanh, int *soGan) {
    *soSanh = 0;
    *soGan = 0;
    bool daSapXep;
    for (int i = 0; i < N - 1; i++) {
        daSapXep = true;
        for (int j = 0; j < N - i - 1; j++) {
            (*soSanh)++;
            if (a[j] > a[j + 1]) {
                HoanVi(&a[j], &a[j + 1]);
                (*soGan)++;
                daSapXep = false;
                printf("Buoc %d-%d: ", j + 1, j + 2);
                XuatMang(a, N);
            }
        }
        if (daSapXep) {
            break;
        }
    }
}

// 5. Sắp xếp nhanh - Quick Sort
int Partition(int a[], int low, int high, int *soSanh, int *soGan) {
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*soSanh)++;
        if (a[j] < pivot) {
            i++;
            HoanVi(&a[i], &a[j]);
            (*soGan)++;
        }
    }
    HoanVi(&a[i + 1], &a[high]);
    (*soGan)++;
    return (i + 1);
}

void QuickSort(int a[], int low, int high, int *soSanh, int *soGan) {
    if (low < high) {
        int pi = Partition(a, low, high, soSanh, soGan);
        printf("Pivot %d tai vi tri %d: ", a[pi], pi);
        XuatMang(a, high + 1); 

        QuickSort(a, low, pi - 1, soSanh, soGan);
        QuickSort(a, pi + 1, high, soSanh, soGan);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// ... (Các hàm khác giữ nguyên)

int main() {
    int N;
    printf("Nhap kich thuoc mang N: ");
    scanf("%d", &N);

    int a[N], b[N], c[N]; // 3 mảng cho 3 yêu cầu

    // Yêu cầu 1: Dữ liệu ngẫu nhiên
    PhatSinhMang(a, N);
    memcpy(b, a, sizeof(a)); 
    memcpy(c, a, sizeof(a)); 

    printf("\n--- Yeu cau 1: Du lieu phat sinh ngau nhien ---\n");
    printf("Mang ban dau: ");
    XuatMang(a, N);

    int soSanh, soGan;

    printf("\n1. Sap xep chon truc tiep:\n");
    SelectionSort(a, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n2. Sap xep chen truc tiep:\n");
    InsertionSort(b, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n3. Sap xep doi cho truc tiep:\n");
    InterchangeSort(c, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    memcpy(b, a, sizeof(a)); 
    memcpy(c, a, sizeof(a)); 

    printf("\n4. Sap xep noi bot:\n");
    BubbleSort(b, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n5. Sap xep nhanh:\n");
    soSanh = 0;
    soGan = 0;
    QuickSort(c, 0, N - 1, &soSanh, &soGan);
    printf("Ket qua sap xep nhanh: ");
    XuatMang(c, N);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    // Yêu cầu 2: Dữ liệu tăng dần
    PhatSinhMangTang(a, N);
    memcpy(b, a, sizeof(a));
    memcpy(c, a, sizeof(a));

    printf("\n--- Yeu cau 2: Du lieu phat sinh tang dan ---\n");
    printf("Mang ban dau: ");
    XuatMang(a, N);

    printf("\n1. Sap xep chon truc tiep:\n");
    SelectionSort(a, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n2. Sap xep chen truc tiep:\n");
    InsertionSort(b, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n3. Sap xep doi cho truc tiep:\n");
    InterchangeSort(c, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    memcpy(b, a, sizeof(a));
    memcpy(c, a, sizeof(a));

    printf("\n4. Sap xep noi bot:\n");
    BubbleSort(b, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n5. Sap xep nhanh:\n");
    soSanh = 0;
    soGan = 0;
    QuickSort(c, 0, N - 1, &soSanh, &soGan);
    printf("Ket qua sap xep nhanh: ");
    XuatMang(c, N);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    // Yêu cầu 3: Dữ liệu giảm dần
    PhatSinhMangGiam(a, N);
    memcpy(b, a, sizeof(a));
    memcpy(c, a, sizeof(a));

    printf("\n--- Yeu cau 3: Du lieu phat sinh giam dan ---\n");
    printf("Mang ban dau: ");
    XuatMang(a, N);

    printf("\n1. Sap xep chon truc tiep:\n");
    SelectionSort(a, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n2. Sap xep chen truc tiep:\n");
    InsertionSort(b, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n3. Sap xep doi cho truc tiep:\n");
    InterchangeSort(c, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    memcpy(b, a, sizeof(a));
    memcpy(c, a, sizeof(a));

    printf("\n4. Sap xep noi bot:\n");
    BubbleSort(b, N, &soSanh, &soGan);
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    printf("\n5. Sap xep nhanh:\n");
    soSanh = 0;
    soGan = 0;
    QuickSort(c, 0, N - 1, &soSanh, &soGan);
    printf("Ket qua sap xep nhanh: ");
    XuatMang(c, N); 
    printf("So sanh: %d, So gan: %d\n", soSanh, soGan);

    return 0;
}