#include <stdio.h>
#include <windows.h>
#include<conio.h>
COORD position;
void setposition(int x , int y);
void board();
void move(int* x , int* y );
void draw(int* x , int* y , char keyboard);
void decode(char* vooroodi);
void savefile(char* vooroodi);
typedef struct positionme
{
    int x;
    int y;
}makan;

int main()
{
    board();
    makan me;
    me.x = 2;
    me.y = 0;
    while (1)
    {
        setposition(me.x , me.y);
        move(&me.x , &me.y);
        char* vooroodi = (char*) malloc(sizeof(char)*1);
        FILE* input = fopen("dastoor.txt" , "r");
        char a;
        int i ;
        for ( i = 0; (a = fgetc(input)) != EOF; i++)
        {
            vooroodi = (char*)realloc(vooroodi , sizeof(char) * (i+2));
            vooroodi[i] = a;
        }
        vooroodi[i] = '\0';
        decode(vooroodi);
    }
}
void setposition(int x , int y)
{
    position.X = x ;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , position);
}
void board()
{
    for (int y = 0; y < 17 ; y++)
    {
        for (int x = 0; x < 200; x++)
        {
            if (y == 15 && x == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 176);
                //setposition(0 , 15);
                printf(" NORMAL ");
                x = x + 8;
            }
            else if (x == 0  && y < 15)
            {
                printf("%d:" , y+1);
                x++;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 15);
                printf(" ");
            }
        }
        printf("\n");
    }
}
void move(int* x , int* y )
{
    int flag = 0 ;
    char keyboard ;
    if (kbhit())
    {
        keyboard = getch();
        switch (keyboard)
        {
        case 72:
            flag = 0;
            if (*y == 0)
            { 
                return;
            }
            if (*y == 16)
            {
                return;
            }
            *y = *y - 1 ;
            return ;
        case 75:
            flag = 0;
            if (*x == 2 && *y != 16)
            {
                return;
            }
            if (*x == 0)
            {
                return;
            }
            
            *x = *x - 1 ;
            return;
        case 77:
            flag = 0;
            if (*x == 199)
            { 
                return;
            }
            if (*x == 199 && *y == 16)
            {
                return;
            }
            *x = *x + 1 ;
            return;
        case 80:
            flag = 0 ;
            if (*y == 14)
            {
                return;
            }
            if (*y == 16)
            {
                return;
            }
            
            *y = *y + 1 ;
            return;
        case 8:
            flag = 0 ;
            if (*x == 2)
            {
                if (*y == 0)
                {
                    return;
                }
                *y = *y - 1;
                *x = 199 ;
                setposition(*x , *y);
                printf(" ");
                return;
            }
            *x = *x -1 ;
            setposition(*x , *y);
            printf(" ");
            return;
        case 13:
            flag = 0 ;
            if (*y == 16)
            {
                for (int i = *x; i >= 0; i--)
                {
                    printf(" ");
                    *x = *x -1;
                    setposition(*x , *y);
                }
                *x = 2;
                *y = 0;
                return;
            }
            
            if (*y >= 14)
            {
                return;
            }
            *y = *y + 1;
            *x = 2;
            return;
        case 47:
            flag = 0 ;
            FILE* input47 = fopen("dastoor.txt" , "w");
            fclose(input47);
            *y = 16;
            *x = 0;
            return;
        case 58:
            flag = 0;
            FILE* input58 = fopen("dastoor.txt" , "w");
            fclose(input58);
            *y = 16;
            *x = 0 ;
            return;
        }
        flag = 1 ;
        if (flag && keyboard != (char)224)
        {
            draw(x , y , keyboard);
        }
    }
    
}
void draw(int *x , int *y , char keyboard)
{
    if (*y == 16)
    {
        FILE* dastoorha = fopen("dastoor2.txt" , "a");
        fprintf(dastoorha , "%c" , keyboard);
        fclose(dastoorha);
    }
    printf("%c" , keyboard);
    if (*x == 199)
    {
        *y = *y + 1;
        *x = 2 ;
    }
    else
    {
        *x = *x + 1;
    }
}
void decode(char* vooroodi)
{
    if (vooroodi[0] == 's' && vooroodi[1] == 'a' && vooroodi[2] == 'v' && vooroodi[3] == 'e' && vooroodi[4] == ' ')
    {
        savefile(vooroodi);
    }
    
}
void savefile(char* vooroodi)
{
    int count = 0;
    for (int i = 5; vooroodi[i] != '\0' ; i++)
    {
        count++;
    }
    char filename[count+5];
    for (int i = 5; vooroodi[i] != '\0' ; i++)
    {
        filename[i-5] = vooroodi[i];
    }
    filename[count] = '.';
    filename[count+1] = 't';
    filename[count+2] = 'x';
    filename[count+3] = 't';
    filename[count+4] = '\0';
    FILE* saveas = fopen(filename , "w");
    fprintf(saveas , "fuhovz");
    fclose(saveas);
}