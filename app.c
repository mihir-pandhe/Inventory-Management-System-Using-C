#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    int quantity;
    float price;
} Item;

Item inventory[100];
int itemCount = 0;

void addItem() {
    Item newItem;
    newItem.id = itemCount + 1;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void displayInventory() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
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
    scanf("%d", &id);
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

int main() {
    int choice;
    while(1) {
        printf("1. Add Item\n2. Display Inventory\n3. Update Item\n4. Delete Item\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            addItem();
        } else if (choice == 2) {
            displayInventory();
        } else if (choice == 3) {
            updateItem();
        } else if (choice == 4) {
            deleteItem();
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
