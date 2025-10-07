#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// en funktion der laver en caesar cryptreing
// ud fra en tekst og en nøgle
char *ceaserCrypter(char *tekst, int nøgle) {

  // finder længden af "tekst"
  size_t lengde = strlen(tekst);
  // alokere hukmelse som kan rattes til variablen "caesarkode"
  char *caesarkode = malloc(lengde + 1);

  // en funktion som ligger nøglen til hvert bogstav i tekst
  for (size_t i = 0; i < lengde; ++i) {
    // her tjkes der om bogstavet på i's plads er gyldig
    if (tekst[i] >= 'A' && tekst[i] <= 'Z') {
      // ser om bogstavet på i's plads + nøglen er støre end det maksimum
      // gyldige output
      if (tekst[i] + nøgle > 'Z') {
        // dette går at funktion kan overflowe fra Z til A
        caesarkode[i] = tekst[i] - 26 + nøgle;

      } else {
        // hvis bogstavet på i's plads + nøglen er gyldigt
        // ligger vi nøglen bogstavet
        caesarkode[i] = tekst[i] + nøgle;
      }
    } else {
      // hvis bogstavet på i's plads ikke er gyldigt ingnorare funktioen den
      caesarkode[i] = tekst[i];
    }
  }
  // her sørger vi for at vi kun for det vi skal bruge
  caesarkode[lengde] = '\0';
  // retunere den ctyptrede besked
  return caesarkode;
}

// en funktion der laver en vigenere cryptreing
// ud fra en tekst og en nøgle
char *vigenereCrypter(char *tekst, char *nøgle) {

  // finder længden af "tekst"
  size_t lengde = strlen(tekst);

  size_t nøgleLængde = strlen(nøgle);

  // alokere hukmelse som kan rattes til variablen "vigenerekode"
  char *vigenerekode = malloc(lengde + 1);

  // en funktion som ligger "nøglen - A" til hvert bogstav i "tekst"
  // (+ "nøglen -A") er en matematisk funktionder efter ligner en vigenerekode
  for (size_t i = 0; i < lengde; ++i) {
    // her tjkes der om bogstavet på i's plands er gyldigt
    if (tekst[i] >= 'A' && tekst[i] <= 'Z') {

      int shift = nøgle[i % nøgleLængde] - 'A';
      // ser om bogstavet på i's plads + (nøglen - A) er støre end det maksimum
      // gyldige output
      if (tekst[i] + shift > 'Z') {
        // dette går at funktion kan overflowe fra Z til A
        vigenerekode[i] = tekst[i] - 26 + shift;
      } else {
        // ligger "nøglen - A" til hvert bogstav i "tekst"
        vigenerekode[i] = tekst[i] + shift;
      }
    } else {
      // hvis bogstavet på i's plads ikke er gyldigt ingnorare funktioen den
      vigenerekode[i] = tekst[i];
    }
  }
  // her sørger vi for at vi kun for det vi skal bruge
  vigenerekode[lengde] = '\0';
  // ud fra en tekst og en nøgle
  return vigenerekode;
}

char *ceasarDecrypter(char *kodetekst, int nøgle) {
  size_t lengde = strlen(kodetekst);
  char *normalteskt = malloc(lengde + 1);
  for (size_t i = 0; i < lengde; ++i) {
    if (kodetekst[i] >= 'A' && kodetekst[i] <= 'Z') {
      if (kodetekst[i] - nøgle < 'A') {
        normalteskt[i] = kodetekst[i] + 26 - nøgle;
      } else {
        normalteskt[i] = kodetekst[i] - nøgle;
      }
    } else {
      normalteskt[i] = kodetekst[i];
    }
  }
  normalteskt[lengde] = '\0';
  return normalteskt;
}

char *vigenereDecrypter(char *kode, char *nøgle) {
  size_t lengde = strlen(kode);
  char *normaltekst = malloc(lengde + 1);
  size_t nøgleLængde = strlen(nøgle);

  for (size_t i = 0; i < lengde; ++i) {

    if (kode[i] >= 'A' && kode[i] <= 'Z') {

      int shift = nøgle[i % nøgleLængde] - 'A';

      if (kode[i] - shift < 'A') {

        normaltekst[i] = kode[i] + 26 - shift;

      } else {
        normaltekst[i] = kode[i] - shift;
      }
    } else {

      normaltekst[i] = kode[i];
    }
  }

  normaltekst[lengde] = '\0';
  return normaltekst;
}