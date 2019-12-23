#ifndef CARD_FILE_H
#define CARD_FILE_H

int savecard(const Card* fcard, const char* fpath);
int readcard(Card* fcard, const char* fpath);
int getcardnum(const char* fpath);
Card analyzecard(char* bcup);
int renewcard(lpnode node, const char* fpath);

#endif

