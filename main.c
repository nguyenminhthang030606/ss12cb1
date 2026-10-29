#include <stdio.h>
#include <string.h>

#define MAX_NV 50

typedef struct {
    int maNV;
    char hoTen[50];
    int soPhutDiMuon;
    float luongCoBan;
} NhanVien;

int timTheoMaNV(NhanVien ds[], int soLuong, int maNV);
int themNhanVien(NhanVien ds[], int soLuong);
void hienThiDanhSach(NhanVien ds[], int soLuong);
void capNhatPhutDiMuon(NhanVien ds[], int soLuong);
void timKiemNhanVien(NhanVien ds[], int soLuong);

int timTheoMaNV(NhanVien ds[], int soLuong, int maNV) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (ds[i].maNV == maNV) {
            return i;
        }
    }

    return -1;
}

int themNhanVien(NhanVien ds[], int soLuong) {
    if (soLuong >= MAX_NV) {
        printf("=> Danh sach da day!\n");
        return soLuong;
    }

    NhanVien nv;

    printf("Nhap ma nhan vien: ");
    scanf("%d", &nv.maNV);

    while(getchar() != '\n');

    if (timTheoMaNV(ds, soLuong, nv.maNV) != -1) {
        printf("=> Ma nhan vien da ton tai!\n");
        return soLuong;
    }

    printf("Nhap ho ten: ");
    fgets(nv.hoTen, sizeof(nv.hoTen), stdin);
    nv.hoTen[strcspn(nv.hoTen, "\n")] = '\0';

    printf("Nhap so phut di muon: ");
    scanf("%d", &nv.soPhutDiMuon);

    if (nv.soPhutDiMuon < 0) {
        printf("=> So phut di muon khong hop le!\n");
        return soLuong;
    }

    printf("Nhap luong co ban: ");
    scanf("%f", &nv.luongCoBan);

    if (nv.luongCoBan < 0) {
        printf("=> Luong co ban khong hop le!\n");
        return soLuong;
    }

    ds[soLuong] = nv;

    printf("=> Them nhan vien thanh cong!\n");

    return soLuong + 1;
}

void hienThiDanhSach(NhanVien ds[], int soLuong) {
    int i;

    if (soLuong == 0) {
        printf("=> Danh sach rong!\n");
        return;
    }

    printf("\n--- DANH SACH NHAN VIEN ---\n");
    printf("%-10s %-25s %-15s %-15s\n",
           "Ma NV",
           "Ho Ten",
           "Phut Muon",
           "Luong");

    for (i = 0; i < soLuong; i++) {
        float tienPhat =
            (ds[i].soPhutDiMuon > 15) ? 50000 : 0;

        float luongThucNhan =
            ds[i].luongCoBan - tienPhat;

        printf("%-10d %-25s %-15d %.0f\n",
               ds[i].maNV,
               ds[i].hoTen,
               ds[i].soPhutDiMuon,
               luongThucNhan);
    }
}

void capNhatPhutDiMuon(NhanVien ds[], int soLuong) {
    if (soLuong == 0) {
        printf("=> Danh sach rong!\n");
        return;
    }

    int maNV;

    printf("Nhap ma NV can cap nhat: ");
    scanf("%d", &maNV);

    int viTri = timTheoMaNV(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("=> Khong tim thay nhan vien!\n");
        return;
    }

    int phutMoi;

    printf("Nhap so phut di muon moi: ");
    scanf("%d", &phutMoi);

    if (phutMoi < 0) {
        printf("=> So phut di muon khong hop le!\n");
        return;
    }

    ds[viTri].soPhutDiMuon = phutMoi;

    printf("=> Cap nhat thanh cong!\n");
}

void timKiemNhanVien(NhanVien ds[], int soLuong) {
    if (soLuong == 0) {
        printf("=> Danh sach rong!\n");
        return;
    }

    int maNV;

    printf("Nhap ma NV can tim: ");
    scanf("%d", &maNV);

    int viTri = timTheoMaNV(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("=> Khong tim thay nhan vien!\n");
        return;
    }

    float tienPhat =
        (ds[viTri].soPhutDiMuon > 15) ? 50000 : 0;

    float luongThucNhan =
        ds[viTri].luongCoBan - tienPhat;

    printf("\nThong tin nhan vien:\n");
    printf("Ma NV: %d\n", ds[viTri].maNV);
    printf("Ho ten: %s\n", ds[viTri].hoTen);
    printf("So phut di muon: %d\n",
           ds[viTri].soPhutDiMuon);
    printf("Luong co ban: %.0f\n",
           ds[viTri].luongCoBan);
    printf("Luong thuc nhan: %.0f\n",
           luongThucNhan);
}

int main() {
    NhanVien danhSach[MAX_NV];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n===== HE THONG QUAN LY CHAM CONG HRM =====\n");
        printf("1. Them nhan vien moi\n");
        printf("2. Hien thi danh sach va tinh luong\n");
        printf("3. Cap nhat so phut di muon\n");
        printf("4. Tim kiem nhan vien theo ma\n");
        printf("0. Thoat\n");
        printf("==========================================\n");
        printf("Nhap lua chon: ");

        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                soLuong =
                    themNhanVien(
                        danhSach,
                        soLuong
                    );
                break;

            case 2:
                hienThiDanhSach(
                    danhSach,
                    soLuong
                );
                break;

            case 3:
                capNhatPhutDiMuon(
                    danhSach,
                    soLuong
                );
                break;

            case 4:
                timKiemNhanVien(
                    danhSach,
                    soLuong
                );
                break;

            case 0:
                printf("=> Thoat chuong trinh!\n");
                break;

            default:
                printf("=> Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}