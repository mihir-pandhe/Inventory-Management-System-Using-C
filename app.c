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

int main() {
    int choice;
    while(1) {
        printf("1. Add Item\n2. Display Inventory\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            addItem();
        } else if (choice == 2) {
            displayInventory();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
