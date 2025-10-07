#include "cryplib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sætter globale vraiabler
int caesarkodeWhile = 0;
int Vigenerekodewhile = 0;
int hovedemenu = 1;
int krypterings_menu = 0;
int dekryptere = 0;
int kryptere = 0;

void clearIndputBuffer() {
  int k;
  while ((k = getchar()) != '\n' && k != EOF) {
  }
}

int main() {

  printf("hej\n");
  // hvodemenu
  while (hovedemenu == 1) {
    // printer menu
    printf("vilken type kode skal vi arbejde med idag\n");
    printf("caeserkode(c) \nVigenerekode(v) \nexit(e) \n");
    // henter indput fra bruger
    char menukode = getchar();
    clearIndputBuffer();

    // menu logik
    if (menukode == 'c' || menukode == 'C') {

      printf("starter ceasarkode program\n");
      caesarkodeWhile = 1;
      krypterings_menu = 1;
      hovedemenu = 0;
      break;

    } else if (menukode == 'v' || menukode == 'V') {
      printf("starter Vigenerekode program\n");
      Vigenerekodewhile = 1;
      krypterings_menu = 1;
      hovedemenu = 0;
      break;
    } else if (menukode == 'e' || menukode == 'E') {
      printf("lukker programet\n");
      hovedemenu = 0;
      break;
    } else {
      printf("ikke gyldigt indput\n");
    }
  }

  while (krypterings_menu == 1) {
    // printer menu
    printf("skal vi dekryptere eller kryptere\n");
    printf("dekryptere(d) \nkryptere(k) \n");
    // henter indput fra bruger
    char K_menukode = getchar();
    clearIndputBuffer();
    // menu logik
    if (K_menukode == 'd' || K_menukode == 'D') {
      dekryptere = 1;
      krypterings_menu = 0;

      // satter kryptering
    } else if (K_menukode == 'k' || K_menukode == 'K') {
      kryptere = 1;
      krypterings_menu = 0;

    } else {
      printf("ikke gyldigt indput\n");
    }
  }

  // cæsar
  while (caesarkodeWhile == 1 && (dekryptere == 1 || kryptere == 1)) {
    char bruger_indput[50];
    int nøgle = 0;

    if (dekryptere == 1) {
      printf("indtast tekst:");
      fgets(bruger_indput, sizeof(bruger_indput), stdin);
      // Remove trailing newline if present
      size_t len = strlen(bruger_indput);
      if (len > 0 && bruger_indput[len - 1] == '\n') {
        bruger_indput[len - 1] = '\0';
      }

      printf("indatst nøgle:");

      scanf("%d", &nøgle);

      char *tekst = ceasarDecrypter(bruger_indput, nøgle);
      printf("%s", tekst);

    } else {
      printf("indtast tekst:");
      fgets(bruger_indput, sizeof(bruger_indput), stdin);
      // Remove trailing newline if present
      size_t len = strlen(bruger_indput);
      if (len > 0 && bruger_indput[len - 1] == '\n') {
        bruger_indput[len - 1] = '\0';
      }

      printf("indatst nøgle:");

      scanf("%d", &nøgle);

      char *tekst = ceaserCrypter(bruger_indput, nøgle);
      printf("%s", tekst);
    }
    caesarkodeWhile = 0;
  }

  // veginere
  while (Vigenerekodewhile == 1 && (dekryptere == 1 || kryptere == 1)) {
    char bruger_indput[50];
    char nøgle[50];

    if (dekryptere == 1) {

      printf("indtast tekst:");
      fgets(bruger_indput, sizeof(bruger_indput), stdin);
      // Remove trailing newline if present
      size_t len = strlen(bruger_indput);
      if (len > 0 && bruger_indput[len - 1] == '\n') {
        bruger_indput[len - 1] = '\0';
      }

      printf("indatst nøgle:");

      fgets(nøgle, sizeof(nøgle), stdin);
      // Remove trailing newline if present
      size_t lengde = strlen(nøgle);
      if (lengde > 0 && nøgle[lengde - 1] == '\n') {
        nøgle[lengde - 1] = '\0';
      }

      char *tekst = vigenereDecrypter(bruger_indput, nøgle);
      printf("%s", tekst);

    } else {

      printf("indtast tekst:");
      fgets(bruger_indput, sizeof(bruger_indput), stdin);
      // Remove trailing newline if present
      size_t len = strlen(bruger_indput);
      if (len > 0 && bruger_indput[len - 1] == '\n') {
        bruger_indput[len - 1] = '\0';
      }

      printf("indatst nøgle:");

      fgets(nøgle, sizeof(nøgle), stdin);
      // Remove trailing newline if present
      size_t lengde = strlen(nøgle);
      if (lengde > 0 && nøgle[lengde - 1] == '\n') {
        nøgle[lengde - 1] = '\0';
      }
      char *tekst = vigenereCrypter(bruger_indput, nøgle);
      printf("%s", tekst);
    }
    Vigenerekodewhile = 0;
  }
}