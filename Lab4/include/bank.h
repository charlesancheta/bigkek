//
//

#define INTEREST 0.0001
#define FEE 299

struct account {
    char* name;
    int amount_chk;
    int amount_sv;
};

void openBank(int);
int currentProfit(void);
void updateData(int);
void openAccount(char*, char*, char*, int);
void depositAccount(char*, char*, char*, int);
void withdrawAccount(char*, char*, char*, int);
void reportAccount(char*, char*);
void closeBank(void);

