//
//

#include <stdio.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bank.h"
#include "io.h"
#include "main.h"

int main(void) {
    char message[512];
    printf(INPUT_FILE);
    initializeIO(INPUT_FILE, OUTPUT_FILE);

    openBank(NO_ACCOUNTS);

    for (int day = 1; day <= FINAL_DAY;) {

        int amount;
        int currentDay;
        char name[256];
        char action[16];
        char type[16];
        if (readRecord(&currentDay, name, action, type, &amount)) {
            currentDay = FINAL_DAY + 1;
        }
        while (day < currentDay) {
            updateData(day);
            day++;
        }
        if (day == (FINAL_DAY + 1)) {
            break;
        }
        if (!strcmp(action, "Open")) {
            openAccount(message, name, type, amount);
        }
        else if (!strcmp(action, "Deposit")) {
            depositAccount(message, name, type, amount);
        }
        else if (!strcmp(action, "Withdraw")) {
            withdrawAccount(message, name, type, amount);
        }
        else if (!strcmp(action, "Report")) {
            reportAccount(message, name);
        }
        else {
            sprintf(message, "Invalid Action by %s!", name);
        }
        printf("%s", message);
        printf("\n");
        writeRecord(day, message);
    }
    if (currentProfit() >= 0) {
        sprintf(message, "The bank made $%.2lf\n", currentProfit() / 100.0);

    }
    else if (currentProfit() < 0) {
        sprintf(message, "The bank lost $%.2lf\n", -currentProfit() / 100.0);

    }
    writeRecord(FINAL_DAY, message);
    closeIO();
    closeBank();
    compare(OUTPUT_FILE, TEST_FILE);
    return 0;
}




