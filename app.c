#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILENAME "inventory.dat"

typedef struct {
    int id;
    char name[30];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Inventory is full!\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    if (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) {
        printf("Error: Invalid quantity!\n");
        return;
    }
    printf("Enter price: ");
    if (scanf("%f", &newItem.price) != 1 || newItem.price < 0) {
        printf("Error: Invalid price!\n");
        return;
    }

    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Error: Invalid ID!\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new quantity: ");
            if (scanf("%d", &inventory[i].quantity) != 1 || inventory[i].quantity < 0) {
                printf("Error: Invalid quantity!\n");
                return;
            }
            printf("Enter new price: ");
            if (scanf("%f", &inventory[i].price) != 1 || inventory[i].price < 0) {
                printf("Error: Invalid price!\n");
                return;
            }

            printf("Item updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
}

void deleteItem() {
    int id, found = 0;
    printf("Enter item ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Error: Invalid ID!\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
}

void saveToFile() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return;
    }
    fwrite(&itemCount, sizeof(int), 1, file);
    fwrite(inventory, sizeof(Item), itemCount, file);
    fclose(file);
    printf("Inventory saved to file.\n");
}

void loadFromFile() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return;
    }
    fread(&itemCount, sizeof(int), 1, file);
    fread(inventory, sizeof(Item), itemCount, file);
    fclose(file);
    printf("Inventory loaded from file.\n");
}

void searchItem() {
    char name[30];
    int found = 0;
    printf("Enter item name to search: ");
    scanf("%s", name);

    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("%d\t%-15s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n2. Display Inventory\n3. Update Item\n4. Delete Item\n5. Save Inventory\n6. Search Item\n7. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid choice!\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                searchItem();
                break;
            case 7:
                saveToFile();
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
