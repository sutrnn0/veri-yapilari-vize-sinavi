#include <stdio.h>

void birlestir(int dizi1[], int len1, int dizi2[], int len2, int birlestirilmis[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (dizi1[i] < dizi2[j]) {
            birlestirilmis[k++] = dizi1[i++];
        } else {
            birlestirilmis[k++] = dizi2[j++];
        }
    }
    while (i < len1) {
        birlestirilmis[k++] = dizi1[i++];
    }
    while (j < len2) {
        birlestirilmis[k++] = dizi2[j++];
    }
}

int main() {
    int dizi1[] = {1, 3, 5, 7, 9};
    int len1 = sizeof(dizi1) / sizeof(int);
    int dizi2[] = {2, 4, 6, 8, 10};
    int len2 = sizeof(dizi2) / sizeof(int);
    int birlestirilmis[len1 + len2];
    birlestir(dizi1, len1, dizi2, len2, birlestirilmis);
    for (int i = 0; i < len1 + len2; i++) {
        printf("%d ", birlestirilmis[i]);
    }
    printf("\n");
    return 0;
}
