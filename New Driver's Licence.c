#include <stdio.h>
#include <string.h>

int main() {
    char myName[50];
    int agents;
    char others[200];
    char allNames[5][50]; // Menyimpan 5 nama (Anda + 4 orang lain)
    char temp[50];

    // 1. Input data
    scanf("%s", myName);
    scanf("%d", &agents);
    
    // Mengambil sisa nama (4 orang lainnya)
    for(int i = 0; i < 4; i++) {
        scanf("%s", allNames[i]);
    }
    
    // Masukkan nama Anda ke urutan ke-5
    strcpy(allNames[4], myName);

    // 2. Mengurutkan nama secara alfabetis (Bubble Sort)
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (strcmp(allNames[j], allNames[j + 1]) > 0) {
                // Tukar posisi
                strcpy(temp, allNames[j]);
                strcpy(allNames[j], allNames[j + 1]);
                strcpy(allNames[j + 1], temp);
            }
        }
    }

    // 3. Mencari posisi nama Anda setelah diurutkan
    int myPosition = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(allNames[i], myName) == 0) {
            myPosition = i + 1; // Posisi manusia (1, 2, 3...)
            break;
        }
    }

    // 4. Menghitung waktu
    // Batch = (posisi / jumlah agen) dibulatkan ke atas
    int batches = (myPosition + agents - 1) / agents;
    int totalTime = batches * 20;

    // 5. Output hasil
    printf("%d\n", totalTime);

    return 0;
}
