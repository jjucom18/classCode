#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H

Card* querycard(const char*bcardname);
Card* querycards(const char* bcardname, int *p2);
Card* doLogin(const char* fcardname, const char* fpassword);
Card* doSettle(const char* acardname, const char* apassword);
Card* doAddMoney(const char* fcardname, const char* fpassword, double money);
Card* doRefunMoney(const char* fcardname, const char* fpassword, double money);
Card* doAnnul(const char* fcardname, const char* fpassword);
Card* doRenew(const char* fcardname, const char* fpassword);
Card* doChangePwd(const char* fcardname, const char* fpassword);
int checkcardname(const char* fcardname);
double consume(time_t tstar, time_t tend);
void freelist();
int putcard();
void showAll();

#endif

