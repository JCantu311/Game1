#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

int menu() {
  restart:;
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
  printf("-----------------------------------------------\n");
  printf("*                                             *\n");
  printf("*                    Game 1                   *\n");
  printf("*                                             *\n");
  printf("-----------------------------------------------\n\n");
  printf("Welcome to Game 1.\n\n");
  printf("Main Menu:\n");
  printf("[S]tart\n");
  printf("[D]ocumentation\n");
  printf("[E]xit\n");
  for(int i = 0; i < 2; ++i) {
    printf("\n");
  }
  char choice;
  scanf(" %c", &choice);
  if (choice == 'S' || choice == 's') {
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
    system("game1.exe");
  } else if (choice == 'E' || choice == 'e') {
      system("exit");
  } else {
      system("start docs.html > nul");
      goto restart;
  }
  return 0;
}

int main() {
  menu();
}