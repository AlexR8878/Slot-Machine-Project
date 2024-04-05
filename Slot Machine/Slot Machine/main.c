#include "Account.h"
#include "AgeCheck.h"
#include "Homepage.h"

int main() {

    Account* currentUser = NULL;
    intializeUser(&currentUser);

    mainMenu(&currentUser);



    return 0;
}