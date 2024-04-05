#include "Scoreboard.h"

void updateWinnings(char username[MAXUSERNAMELENGTH], float winnings) {
    FILE* file = fopen("File.txt", "r+");
    if (file == NULL) {
        printf("Error: Unable to open file for updating winnings.\n");
        return;
    }

    Account user;
    while (fscanf(file, "%s %d %f %f", user.username, &user.id, &user.balance, &user.winnings) == 4) {
        if (strcmp(user.username, username) == 0) {
            user.winnings += winnings;
            fseek(file, sizeof(Account), SEEK_CUR);
            fprintf(file, "%s %d %.2f %.2f\n", user.username, user.id, user.balance, user.winnings);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("User not found.\n");
}


void updateScoreboard(char username[MAXUSERNAMELENGTH], float winnings) {
    FILE* scoreboard = fopen("Scoreboard.txt", "a");
    if (scoreboard == NULL) {
        printf("Error: Unable to open scoreboard file.\n");
        return;
    }

    fprintf(scoreboard, "%s %.2f\n", username, winnings);
    fclose(scoreboard);
}

void saveTopWinners() {
    FILE* scoreboard = fopen("Scoreboard.txt", "r");
    if (scoreboard == NULL) {
        printf("Error: Unable to open scoreboard file.\n");
        return;
    }

    char topWinners[3][MAXUSERNAMELENGTH];
    float topWinnings[3] = { 0 };
    char username[50];
    float winnings;

    while (fscanf(scoreboard, "%s %f", username, &winnings) != EOF) {
        for (int i = 0; i < 3; i++) {
            if (winnings > topWinnings[i]) {
                for (int j = 2; j > i; j--) {
                    strcpy(topWinners[j], topWinners[j - 1]);
                    topWinnings[j] = topWinnings[j - 1];
                }
                strcpy(topWinners[i], username);
                topWinnings[i] = winnings;
                break;
            }
        }
    }

    fclose(scoreboard);

    FILE* topWinnersFile = fopen("TopWinners.txt", "w");
    if (topWinnersFile == NULL) {
        printf("Error: Unable to open top winners file.\n");
        return;
    }

    fprintf(topWinnersFile, "Top Winners of the Day:\n");
    for (int i = 0; i < 3; i++) {
        fprintf(topWinnersFile, "%d. %s - $%.2f\n", i + 1, topWinners[i], topWinnings[i]);
    }

    fclose(topWinnersFile);
}

void displayTopWinners() {
    FILE* file = fopen("TopWinners.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open top winners file.\n");
        return;
    }

    char line[100];
    printf("Top Winners:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}