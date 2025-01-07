#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	 int sortOrder;
     int choiceSearch;
     int choice;
     User users[100];
     int numUsers = 0;
     FILE *fptr;
     char filename[100] = "userList.bin";
     fptr = fopen(filename, "rb");
     if (fptr != NULL) {
        fread(&numUsers, sizeof(int), 1, fptr);
        fread(users, sizeof(User), numUsers, fptr);
        fclose(fptr);
        printf("Da doc du lieu tu file %s\n", filename);
    } else {
        printf("Khong tim thay file %s. Khoi tao danh sach moi.\n", filename);
    }
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Lua chon khong hop le. Vui long nhap mot so.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (choice) {
        	case 1:
				displayUsers();
				break;
			case 2:
				addUser();
				break;
			case 3:
				printf("Tim kiem nguoi dung theo:\n");
				printf("1. ID\n");
				printf("2. Ten\n");
				printf("Lua chon: ");
				if (scanf("%d", &choiceSearch) != 1) {
 					printf("Lua chon khong hop le. Vui long nhap mot so.\n");
				while (getchar() != '\n');
				break;
				}
				while (getchar() != '\n');
				if (choiceSearch == 1) {
				searchUserById();
				} else if (choiceSearch == 2) {
					searchUserByName();
				} else {
					printf("Lua chon khong hop le.\n");
				}
				break;
			case 4:
				toggleUserLock();
				break;
			case 5:
				if (numUsers == 0) {
				printf("Danh sach nguoi dung trong. Khong the sap xep.\n");
				break;
				}
				printf("Sap xep nguoi dung theo:\n");
				printf("1. Tang dan (A-Z)\n");
				printf("2. Giam dan (Z-A)\n");
				printf("Lua chon: ");
				if (scanf("%d", &sortOrder) != 1) {
					printf("Lua chon khong hop le. Vui long nhap mot so.\n");
					while (getchar() != '\n');
					break;
				}
				while (getchar() != '\n');
				if (sortOrder != 1 && sortOrder != 2) {
				printf("Lua chon khong hop le.\n");
				break;
				}
				sortUsersByName(sortOrder);
				printf("Da sap xep nguoi dung theo ten thanh cong.\n");
				displayUsers();
				break;
            case 0:
                fptr = fopen(filename, "wb");
                if (fptr == NULL) {
                    perror("Loi mo file de ghi");
                } else {
                    fwrite(&numUsers, sizeof(int), 1, fptr);
                    fwrite(users, sizeof(User), numUsers, fptr);
                    fclose(fptr);
                    printf("Da luu du lieu vao file %s\n", filename);
                }
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);
    return 0;
}
