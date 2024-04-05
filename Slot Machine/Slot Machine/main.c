#include "Account.h"
#include "AgeCheck.h"
#include "Homepage.h"

int main() {
    double balance;
    checkEligibility();

    char username[MAXUSERNAMELENGTH];
    int id;
    getUserInfo(username, &id);

    int loginResult = loginOrSignUp(username, id, &balance);
    if (loginResult == -1) {
        return 1;
    }

    Account currentUser;
    strcpy(currentUser.username, username);
    currentUser.id = id;
    currentUser.balance = balance;
    automaticFileSave(currentUser);


    //mainMenu(currentUser);



    return 0;
}