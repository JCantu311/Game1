#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void spellOut(const char* message, int delay) {
    for(int i = 0; i < strlen(message); ++i) {
        printf("%c", message[i]);
        #ifdef _WIN32
            Sleep(delay);
        #else
            usleep(delay * 1000);
        #endif
    }
}

int gameStart() {
    char startMessage[] = "The game starts now.\n";
    spellOut(startMessage, 100);
    #ifdef _WIN32
        system("pause > nul");
    #else
        system("sleep 5");
    #endif
    return 0;
}

void creditsNewLineDelay(int delay) {
    #ifdef _WIN32
        Sleep(delay);
    #else
        usleep(delay * 1000);
    #endif
    printf("\n");
}

void credits() {
    char gameOver[] = "Game Over.\n";
    spellOut(gameOver, 100);
    creditsNewLineDelay(1000);

    char credits[] = "Credits:\n";
    spellOut(credits, 100);
    creditsNewLineDelay(1000);

    char writing[] = "Writing: JaimeC311\n";
    spellOut(writing, 100);
    creditsNewLineDelay(1000);

    char development[] = "Development: JaimeC311\n";
    spellOut(development, 100);
    creditsNewLineDelay(1000);

    char everythingElse[] = "Everything Else: JaimeC311\n";
    spellOut(everythingElse, 100);
    creditsNewLineDelay(1000);

    printf("Goodbye.\n");
    Sleep(1500);
    printf("You may now exit by pressing [Enter]...\n");
    system("pause > nul");
}

int intro() {
    printf("Welcome.\n\n");
    Sleep(3000);
    gameStart();
    return 0;
}

int gameRoom1() {
    return gameRoom2();
}

int gameRoom2() {
    return gameRoom3();
}

int gameRoom3() {
    return gameRoom4();
}

int gameRoom4() {
    return gameRoom5();
}

int gameRoom5() {
    gameEnd();
    return 5;
}

int gameEnd() {
    credits();
    return 0;
}

int main() {
    int finalRoom = 5;
    intro();
    bool playing = true;
    while (playing) {
        int x;
        x = gameRoom1();
        if (x == finalRoom) {
            playing = false;
        }
    }
    return 0;
}