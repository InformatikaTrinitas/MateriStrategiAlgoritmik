#include <stdio.h>
#include <string.h>

void caesarEncrypt(char *text, int key) {
	int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Masukkan teks (huruf besar semua): ");
    scanf("%s", text);

    printf("Masukkan key (geser berapa huruf): ");
    scanf("%d", &key);

    caesarEncrypt(text, key);

    printf("Hasil enkripsi: %s\n", text);

    return 0;
}

