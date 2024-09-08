#include <stdio.h>
#include <string.h>

struct ttsinhvien {
    char MSSV[10], hoten[30];
    int gioitinh; // 1: nữ, 0: nam
    char diachi[50];
    float dtb;
};
typedef struct ttsinhvien SINHVIEN;

// Function prototypes
void Nhap1SV(SINHVIEN *sv);
void NhapDSSV(SINHVIEN dssv[], int *n);
void Xuat1SV(SINHVIEN sv);
void XuatDSSV(SINHVIEN dssv[], int n);
int TimSV(SINHVIEN dssv[], int n, char maso[]);
void XoaSV(SINHVIEN dssv[], int *n, char maso[]);
void SapTheoDTB(SINHVIEN dssv[], int n);
void SapTheoHoTen(SINHVIEN dssv[], int n);
void Hoanvi(SINHVIEN *a, SINHVIEN *b);

int main() {
    SINHVIEN dssv[50];
    int n;
    char masoXoa[10];

    // Nhập danh sách sinh viên
    NhapDSSV(dssv, &n);

    // Xuất danh sách sinh viên
    printf("\nDanh sach sinh vien:\n");
    XuatDSSV(dssv, n);

    // Nhập MSSV cần xóa
    printf("\nNhap MSSV can xoa: ");
    scanf("%s", masoXoa);

    // Xóa sinh viên
    XoaSV(dssv, &n, masoXoa);

    // Xuất danh sách sinh viên sau khi xóa
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    XuatDSSV(dssv, n);

    // Sắp xếp theo điểm trung bình và xuất kết quả
    SapTheoDTB(dssv, n);
    printf("\nDanh sach sinh vien sau khi sap xep theo diem trung binh:\n");
    XuatDSSV(dssv, n);

    // Sắp xếp theo họ tên và xuất kết quả
    SapTheoHoTen(dssv, n);
    printf("\nDanh sach sinh vien sau khi sap xep theo ho ten:\n");
    XuatDSSV(dssv, n);

    return 0;
}

void Nhap1SV(SINHVIEN *sv) {
    printf("Nhap MSSV: ");
    scanf("%s", sv->MSSV);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]", sv->hoten); 
    printf("Nhap gioi tinh (1: Nu, 0: Nam): ");
    scanf("%d", &sv->gioitinh);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", sv->diachi);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->dtb);
}

void NhapDSSV(SINHVIEN dssv[], int *n) {
    do {
        printf("Nhap so luong sinh vien (toi da 50): ");
        scanf("%d", n);
    } while (*n <= 0 || *n > 50);

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        Nhap1SV(&dssv[i]); 
    }
}

void Xuat1SV(SINHVIEN sv) {
    printf("%-10s %-30s %-6s %-50s %.2f\n", 
           sv.MSSV, sv.hoten, (sv.gioitinh == 1 ? "Nu" : "Nam"), sv.diachi, sv.dtb);
}

void XuatDSSV(SINHVIEN dssv[], int n) {
    printf("%-10s %-30s %-6s %-50s %-8s\n", "MSSV", "Ho va ten", "Gioi tinh", "Dia chi", "DTB");
    for (int i = 0; i < n; i++) {
        Xuat1SV(dssv[i]);
    }
}

int TimSV(SINHVIEN dssv[], int n, char maso[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(dssv[i].MSSV, maso) == 0) {
            return i; 
        }
    }
    return -1; 
}

void XoaSV(SINHVIEN dssv[], int *n, char maso[]) {
    int viTri = TimSV(dssv, *n, maso);
    if (viTri == -1) {
        printf("Khong tim thay sinh vien co MSSV %s\n", maso);
    } else {
        for (int i = viTri; i < *n - 1; i++) {
            dssv[i] = dssv[i + 1];
        }
        (*n)--;
        printf("Da xoa sinh vien co MSSV %s\n", maso);
    }
}

void SapTheoDTB(SINHVIEN dssv[], int n) {
    for (int i = 1; i < n; i++) {
        SINHVIEN key = dssv[i];
        int j = i - 1;
        while (j >= 0 && dssv[j].dtb > key.dtb) {
            dssv[j + 1] = dssv[j];
            j--;
        }
        dssv[j + 1] = key;
    }
}

void SapTheoHoTen(SINHVIEN dssv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcasecmp(dssv[j].hoten, dssv[minIndex].hoten) < 0) {
                minIndex = j;
            }
        }
        Hoanvi(&dssv[i], &dssv[minIndex]);
    }
}

void Hoanvi(SINHVIEN *a, SINHVIEN *b) {
    SINHVIEN temp = *a;
    *a = *b;
    *b = temp;
}