#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void encrypt(char *text);
extern void decrypt(char *text);

#define MAX_ENTRIES 10
#define MAX_LEN 256

char diary[MAX_ENTRIES][MAX_LEN];
int entry_count = 0;

int verify_user() {
    char password[32];
    printf("Enter password to view diary: ");
    if (fgets(password, sizeof(password), stdin) == NULL) return 0;
    password[strcspn(password, "\n")] = 0;
    return strcmp(password, "mypassword") == 0;
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary full!\n");
        return;
    }
    printf("Write your diary entry (max %d chars):\n", MAX_LEN - 1);
    if (fgets(diary[entry_count], MAX_LEN, stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    diary[entry_count][strcspn(diary[entry_count], "\n")] = 0;
    encrypt(diary[entry_count]);
    entry_count++;
    printf("Entry saved (encrypted).\n");
}

void view_entries() {
    if (!verify_user()) {
        printf("Verification failed.\n");
        return;
    }
    printf("Your diary entries:\n");
    for (int i = 0; i < entry_count; i++) {
        char buffer[MAX_LEN];
        strcpy(buffer, diary[i]);
        decrypt(buffer);
        printf("%d: %s\n", i + 1, buffer);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nDiary Manager\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            printf("Invalid input\n");
            continue;
        }
        while(getchar() != '\n');

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
