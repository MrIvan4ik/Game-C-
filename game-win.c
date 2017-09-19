#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
// Декларация функций
char getWidth();
char getHeight();
void shMatrix(char width, char height, char array[height][width], char saved_attributes);

void main(void)
{
  // Декларация цветов
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  char width = getWidth(),
     height = getHeight(),
     array[height][width],
                    i = 1,
                    j = 0;
  memset(array, 0, height * width);

  array[i][j] = 1;
  shMatrix(width, height, array, saved_attributes);
  // Бесконечный цыкл
  while(1)
  {
    // If сработает если нажата любая кнопка
    if(kbhit())
    {
      switch (getch())
      {
      case  'w':
        if(i - 1 < 0) {
          shMatrix(width, height, array, saved_attributes);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
          printf("You go beyond\r\n");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
        } else {
          memset(array, 0, height * width);
          i--;
          array[i][j] = 1;
          shMatrix(width, height, array, saved_attributes);
        }
        break;

      case  'a':
        if(j - 1 < 0 ) {
          shMatrix(width, height, array, saved_attributes);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
          printf("You go beyond\r\n");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
        } else {
          memset(array, 0, height * width);
          j--;
          array[i][j] = 1;
          shMatrix(width, height, array, saved_attributes);
          
        }
      break;

      case  's':
        if(i > height - 2 ) {
          shMatrix(width, height, array, saved_attributes);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
          printf("You go beyond\r\n");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
        } else {
          memset(array, 0, height * width);
          i++;
          array[i][j] = 1;
          shMatrix(width, height, array, saved_attributes);
        }
      break;

      case  'd':
        if(j > width - 2 ) {
          shMatrix(width, height, array, saved_attributes);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
          printf("You go beyond\r\n");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
        } else {
          memset(array, 0, height * width);
          j++;
          array[i][j] = 1;
          shMatrix(width, height, array, saved_attributes);
        }
      break;

      case 27:
        return;
      break;

      default:
        shMatrix(width, height, array, saved_attributes);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        printf("To play use: WASD\r\nTo exit: ESC\r\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
        break;
      }
    }
  }

  return;
}
char getWidth(void) 
{
  char width[30] = {0};

  do
  {
    printf("Print here width(Max 15): ");
    scanf("%s", width);
  } while ( atoi(width) >= 16 );

  return atoi(width);
}

char getHeight(void) 
{
  char height[30] = {0};

  do
  {
    printf("Print here height(Max 15): ");
    scanf("%s", height);
  } while ( atoi(height) >= 16 );

  return atoi(height);
}
void shMatrix(char width, char height, char array[height][width], char saved_attributes) 
{
  system("cls");
  for(char i = 0;i < height;i++)
  {
      for(char j = 0;j < width;j++){
        if (array[i][j] == 1) {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
          printf("1 ");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
        } else {printf("0 ", array[i][j]);}
      }
      printf("\r\n");
  }
}
