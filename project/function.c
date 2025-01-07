#include "function.h"
User users[100];
int numUsers = 0;
int isValidID(char *id) { 
    if (strlen(id) == 0) 
	 return 0;
    for (int i = 0; id[i] != '\0'; i++) {
        if (!isdigit(id[i])) {
		 return 0;
	    }
    }
    return 1;
}
int isValidEmail(char *email) { 
    if (strlen(email) == 0) {
	 return 0;
	}
    if (strstr(email, "@gmail.com") == NULL) {
	 return 0;
	}
    return 1;
}
int isValidPhoneNumber(char *phone) {
    if (strlen(phone) == 0) {
	 return 0;
	}
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i])) {
		 return 0;
		 }
    }
    return 1;
}
int isInfoExists(char *id, char *email, char *phone, char *name) { 
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].id, id) == 0 || strcmp(users[i].email, email) == 0 ||
            strcmp(users[i].phone, phone) == 0 || strcmp(users[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}
void displayMenu() {
    printf("================= MENU ================\n");
    printf("1. Hien thi danh sach nguoi dung\n");
    printf("2. Them nguoi dung\n");
    printf("3. Tim kiem nguoi dung\n");
    printf("4. Khoa/Mo khoa nguoi dung\n");
    printf("5. Sap xep nguoi dung\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
void displayUsers() {
    if (numUsers == 0) {
        printf("Danh sach nguoi dung trong.\n");
        return;
    }
    printf("===================================================================================================================\n");
    printf("|     ID     |             Name            |               Email              |   Phone Number | Age |    Status  |\n");
    printf("===================================================================================================================\n");
    for (int i = 0; i < numUsers; i++) {
        char status[10];
        if (users[i].locked == 1) {
            strcpy(status, "Locked");
        } else {
            strcpy(status, "Open");
        }
        printf("| %-10s | %-27s | %-32s | %-14s | %3d | %-10s |\n", 
               users[i].id, users[i].name, users[i].email, users[i].phone, users[i].age, status);
    	printf("------------------------------------------------------------------------------------------------------------------- \n");
    }
    printf("===================================================================================================================\n");
}
void searchUserById() {
    char searchId[100];
    int found = 0;
    printf("\n--- TIM KIEM NGUOI DUNG THEO ID ---\n");
    printf("Nhap ID nguoi dung: ");
    scanf("%s", searchId);
    while (getchar() != '\n');
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].id, searchId) == 0) {
    	printf("===================================================================================================================\n");
    	printf("|     ID     |             Name            |               Email              |   Phone Number | Age |    Status  |\n");
    	printf("===================================================================================================================\n");
            char status[10];
            if (users[i].locked == 1) {
                strcpy(status, "Locked");
            } else {
                strcpy(status, "Open");
            }
        	printf("| %-10s | %-27s | %-32s | %-14s | %3d | %-10s |\n", 
              users[i].id, users[i].name, users[i].email, users[i].phone, users[i].age, status);
    		printf("------------------------------------------------------------------------------------------------------------------- \n");
    		printf("===================================================================================================================\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nguoi dung co ID '%s'.\n", searchId);
    }
}
void searchUserByName() {
    char searchName[100];
    int found = 0;
    printf("\n--- TIM KIEM NGUOI DUNG THEO TEN ---\n");
    printf("Nhap ten nguoi dung: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    	printf("===================================================================================================================\n");
    	printf("|     ID     |             Name            |               Email              |   Phone Number | Age |    Status  |\n");
    	printf("===================================================================================================================\n");
    for (int i = 0; i < numUsers; i++) {
        if (strstr(users[i].name, searchName) != NULL) {
            char status[10];
            if (users[i].locked == 1) {
                strcpy(status, "Locked");
            } else {
                strcpy(status, "Open");
            }
        	printf("| %-10s | %-27s | %-32s | %-14s | %3d | %-10s |\n", 
              users[i].id, users[i].name, users[i].email, users[i].phone, users[i].age, status);
    		printf("------------------------------------------------------------------------------------------------------------------- \n");
            found = 1;
        }
    }
    printf("===================================================================================================================\n");
    if (!found) {
        printf("Khong tim thay nguoi dung nao co ten '%s'.\n", searchName);
    }
}
void addUser(User users[], int *numUsers) {
    if (numUsers >= 100) {
        printf("Vuot qua so luong nguoi dung toi da.\n");
        return;
    }
    User newUser;
    char inputId[100], inputEmail[100], inputPhone[100], inputName[100];
    int validInput = 0;
    while (!validInput) {
        printf("Nhap ID: ");
        if (fgets(inputId, sizeof(inputId), stdin) == NULL || inputId[0] == '\n') {
            printf("ID khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        inputId[strcspn(inputId, "\n")] = 0;
        printf("Nhap ten: ");
        if (fgets(inputName, sizeof(inputName), stdin) == NULL || inputName[0] == '\n') {
            printf("Ten khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        inputName[strcspn(inputName, "\n")] = 0;
        int nameIsValid = 1;
        for (int i = 0; inputName[i] != '\0'; i++) {
            if (!isalpha(inputName[i]) && !isspace(inputName[i])) { 
                nameIsValid = 0; 
                break;
            }
        }
        if (!nameIsValid) {
            printf("Ten chi chua cac ky tu chu cai. Vui long nhap lai.\n");
            continue; 
        }
        printf("Nhap email: ");
        if (fgets(inputEmail, sizeof(inputEmail), stdin) == NULL || inputEmail[0] == '\n') {
            printf("Email khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        inputEmail[strcspn(inputEmail, "\n")] = 0;
        printf("Nhap so dien thoai: ");
        if (fgets(inputPhone, sizeof(inputPhone), stdin) == NULL || inputPhone[0] == '\n') {
            printf("So dien thoai khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        inputPhone[strcspn(inputPhone, "\n")] = 0;
        if (!isValidID(inputId)) {
            printf("ID khong hop le. Vui long nhap lai.\n");
        } else if (isInfoExists(inputId, inputEmail, inputPhone, inputName)) {
            printf("Thong tin da ton tai. Vui long nhap lai.\n");
        } else if (!isValidEmail(inputEmail)) {
            printf("Email khong hop le. Vui long nhap lai.\n");
        } else if (!isValidPhoneNumber(inputPhone)) {
            printf("So dien thoai khong hop le. Vui long nhap lai.\n");
        } else {
            strcpy(newUser.id, inputId);
            strcpy(newUser.name, inputName);
            strcpy(newUser.email, inputEmail);
            strcpy(newUser.phone, inputPhone);
            validInput = 1;
        }
    }
    printf("Nhap tuoi: ");
    while (scanf("%d", &newUser.age) != 1 || newUser.age < 0) {
        printf("Tuoi khong hop le. Vui long nhap lai.\n");
        while (getchar() != '\n');
    }
     newUser.locked = 0;
     users[*numUsers] = newUser;
    (*numUsers)++;
    printf("Them nguoi dung thanh cong!\n");
}
void toggleUserLock() {
    char idStr[10];
    int idToToggle;
    int userIndex = -1;
    printf("Nhap ID nguoi dung muon khoa/mo khoa: ");
    scanf("%s", idStr); 
    idToToggle = atoi(idStr); 
    for (int i = 0; i < numUsers; i++) {
        if (atoi(users[i].id) == idToToggle) {
            userIndex = i;
            break;
        }
    }
    if (userIndex == -1) {
        printf("Khong tim thay nguoi dung voi ID %d.\n", idToToggle);
        return;
    }
    if (users[userIndex].locked == 1) {
        printf("Nguoi dung %d dang bi khoa. Ban co muon MO KHOA? (1: Co, 0: Khong): ", idToToggle);
    } else {
        printf("Nguoi dung %d dang duoc mo. Ban co muon KHOA? (1: Co, 0: Khong): ", idToToggle);
    }
    int confirm;
    scanf("%d", &confirm); 
    if (confirm == 1) {
        users[userIndex].locked = 1 - users[userIndex].locked; 
        if (users[userIndex].locked == 1) {
            printf("Da khoa nguoi dung %d thanh cong.\n", idToToggle);
        } else {
            printf("Da mo khoa nguoi dung %d thanh cong.\n", idToToggle);
        }
    } else {
        printf("Hanh dong bi huy.\n");
    }
}
int compareUsers( void *a,  void *b) {
    User *userA = (User *)a;
    User *userB = (User *)b;
    return strcmp(userA->name, userB->name);
}
void sortUsersByName(int sortOrder) {
    if (numUsers <= 1) {
        printf("Khong co du lieu de sap xep.\n");
        return;
    }
    for (int i = 0; i < numUsers - 1; i++) {
        for (int j = 0; j < numUsers - i - 1; j++) {
            int comparisonResult;
            if (sortOrder == 1) { 
                comparisonResult = strcmp(users[j].name, users[j + 1].name);
            } else {
                comparisonResult = strcmp(users[j + 1].name, users[j].name);
            }
            if (comparisonResult > 0) {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}
