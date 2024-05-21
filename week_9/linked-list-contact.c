#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define PHONE_SIZE 20

struct Contact
{
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    struct Contact *next; // Self Referential Structure
};

void add_contact(struct Contact **head_ref, char name[], char phone[])
{
    struct Contact *new_contact = (struct Contact *)malloc(sizeof(struct Contact));
    if (new_contact == NULL)
    {
        printf("Memori tidak cukup.\n");
        return;
    }

    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);

    // Set the next pointer of the new contact to NULL
    new_contact->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_contact;
    }
    else
    {
        struct Contact *current = *head_ref;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_contact;
    }

    printf("Kontak berhasil ditambahkan.\n");
}

struct Contact *find_contact(struct Contact *head, char name[])
{
    struct Contact *current = head;
    while (current != NULL)
    {
        if (strcasecmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_contacts(struct Contact *head)
{
    if (head == NULL)
    {
        printf("Daftar kontak kosong.\n");
        return;
    }

    printf("Daftar Kontak:\n");
    int index = 1;
    while (head != NULL)
    {
        printf("%d. Nama: %s Nomor Telepon: %s\n", index, head->name, head->phone);
        head = head->next;
        index++;
    }
    return;
}

void free_contacts(struct Contact *head)
{
    struct Contact *current = head;
    while (current != NULL)
    {
        struct Contact *next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    struct Contact *contact_list = NULL;
    char choice;
    char name[50];
    char phone[20];

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Cari Kontak\n");
        printf("3. Cetak Daftar Kontak\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("\n");
            printf("Masukkan nama kontak: ");
            scanf(" %[^\n]s", name);
            printf("Masukkan nomor telepon: ");
            scanf(" %[^\n]s", phone);

            add_contact(&contact_list, name, phone);
            break;
        case '2':
            printf("\n");
            printf("Masukkan nama kontak yang ingin dicari: ");
            scanf(" %[^\n]s", name);

            struct Contact *contact = find_contact(contact_list, name);
            if (contact != NULL)
            {
                printf("Data ditemukan!\n");
                printf("Nama: %s, Nomor Telepon: %s\n", contact->name, contact->phone);
                break;
            }

            printf("Data tidak ditemukan!\n");
            break;
        case '3':
            printf("\n");
            print_contacts(contact_list);
            break;
        case '4':
            free_contacts(contact_list);
            printf("Terima kasih!\n");
            return 0;
        default:
            printf("Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n");
        }
    }

    return 0;
}