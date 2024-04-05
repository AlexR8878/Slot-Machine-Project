#include "Account.h"
#include "AgeCheck.h"
#include "Homepage.h"

int main() {

    Account* currentUser = intializeUser();

    appIntialization(currentUser);

    mainMenu(currentUser);

    free(currentUser);

    return 0;
}