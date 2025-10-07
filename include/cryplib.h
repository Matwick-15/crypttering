#ifndef CRYP_LIB
#define CRYP_LIB

// Cryptreings funktioner
char *ceaserCrypter(char *tekst, int nøgle);
char *vigenereCrypter(char *tekst, char *nøgle);

// Decryptreings funktioner
char *ceasarDecrypter(char *kodetekst, int nøgle);
char *vigenereDecrypter(char *kode, char *nøgle);

#endif