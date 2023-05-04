#include <stdio.h>
#include <stdlib.h>

// Baðlantýlý listelerin düðüm yapýsý
struct Node {
    int val;
    struct Node* next;
};

// Yeni düðüm oluþturma fonksiyonu
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

// Ýki baðlantýlý listenin toplamýný hesaplayan fonksiyon
struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (l1 != NULL || l2 != NULL) {
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = newNode(sum);

        if (res == NULL) {
            res = temp;
        }
        else {
            prev->next = temp;
        }

        prev = temp;

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }

    if (carry > 0) {
        temp->next = newNode(carry);
    }

    return res;
}

// Test için bir main fonksiyonu
int main() {
    struct Node* l1 = newNode(9);
    l1->next = newNode(2);
    l1->next->next = newNode(3);

    struct Node* l2 = newNode(8);
    l2->next = newNode(1);
    l2->next->next = newNode(5);

    struct Node* res = addLists(l1, l2);

    printf("Toplam: ");

    while (res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }

    return 0;
}
