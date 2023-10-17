// We make our program in Visual Studio Code. So, it is better to run it on visual studio code compiler.
// Umar Khan
// Navaal Iqbal
// Sara Adnan
// BESE-13B

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int pwstatus[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int pbstatus[8] = {0, 0, 0, 0, 0, 0, 0, 0};

char board[8][8] = { // Chess Board
    {'R', 'H', 'B', 'K', 'Q', 'B', 'H', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};

// Total Functions used in This Program
void display();
void change(int, int, int, int);
void pawn(int, int);
void rook(int, int);
void rook2(int, int);
void horse(int, int);
void horse2(int, int);
void bishop(int, int);
void bishop2(int, int);
void king(int, int);
void king2(int, int);
void queen(int, int);
void queen2(int, int);
void pawnb(int, int);
void player1();
void player2();
int check(int, int);
int check2(int, int);

int main()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc, 0x0B);
    system("cls");
    int put;
    printf("\n\n***********************************************************************************************\n\n");
    printf("\t\t\t  *****   *        *    *******    ******    ***** \n");
    printf("\t\t\t *        *        *    *          *         *     \n");
    printf("\t\t\t*         *        *    *          *         *     \n");
    printf("\t\t\t*         **********    *******    ******    ***** \n");
    printf("\t\t\t*         *        *    *               *        * \n");
    printf("\t\t\t *        *        *    *               *        *  \n");
    printf("\t\t\t  *****   *        *    *******    ******    *****  \n");
    printf("\n\n************************************************************************************************\n");
    printf("\t\t\t\t>>>>>WELCOME TO THE CHESS GAME<<<<<\n");
    printf("\t\t\t\t    >>>>>By SARA,NAVAAL,UMAR<<<<<\n\n");
    printf("\t\t\t\t>>>>>Choose the options<<<<<\n");
    printf("\t\t\t\t>>>>> 1. Check Rules");
    printf("\n\t\t\t\t>>>>> 2. Check the winner of previous games");
    printf("\n\t\t\t\t>>>>> 3. Play Game\n");
    printf("\t\t\t\t>>>>>  ");
    scanf("%d", &put);
    system("cls");
    switch (put)
    {
    case 1:
    {

        FILE *rule = NULL; // File Handling
        rule = fopen("Rules.txt", "r");

        char line[1024];
        while (fgets(line, 1024, rule) != '\0')
        {
            printf("%s\n", line);
        }
        fclose(rule);

        int num;
        printf("\n\t\t>>>>Choose the option<<<<");
        printf("\n\n\t\t>>>> 1. Play Game");
        printf("\n\n\t\t>>>> 0. Exit the Game");
        printf("\n\n\t\t>>>> ");
        scanf("%d", &num);
        printf("\n\n");
        if (num == 1)
        {
            goto start;
        }
        else
        {
            exit(0);
        }
    }
   case 2:
    {

        FILE *score = NULL; // File Handling
        score = fopen("score.txt", "r");

        char line[1024];
        while (fgets(line, 1024, score) != '\0')
        {
            printf("%s\n", line);
        }
        fclose(score);

        int num;
        printf("\n\t\t>>>>Choose the option<<<<");
        printf("\n\n\t\t>>>> 1. Play Game");
        printf("\n\n\t\t>>>> 0. Exit the Game");
        printf("\n\n\t\t>>>> ");
        scanf("%d", &num);
        printf("\n\n");
        if (num == 1)
        {
            goto start;
        }
        else
        {
            exit(0);
        }
    }
    case 3:
    {
        int x = 0;
        char ch;
        char str1[100];
    start:
        system("cls");
        printf("\n\n\t>>>Enter the name of Player 1 (Enter name without any space):  ");
        scanf("%s", str1);
        char str2[100];
        printf("\n\n\t>>>Enter the name of Player 2 (Enter name without any space):  ");
        scanf("%s", str2);

        printf("\n\n\t\t>>>Press Enter to Continue !");
        getch();
        system("cls");

        do
        {
            x++;
            system("cls");
            display();

            if ((x % 2) == 0)
            {
                player2(str2);
            }
            else
            {
                player1(str1);
            }

            printf("\n>>>Press Enter To Continue ! \n<<< ");

            ch = getch();
        } while (ch == 13);
        break;
    }
    }
}

void display() // It Display The Chess board
{
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);// It gives the color to output
    SetConsoleTextAttribute(hd, 0x0E);
    int i, j, k;

    printf(" ");
    for (i = 0; i < 8; i++)
        printf("    %d", i);
    printf("\n");

    for (k = 0; k < 8; k++)
    {
        printf("  ");
        for (i = 0; i < 42; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("%d ", k);

        for (j = 0; j < 8; j++)
        {
            printf("|| %c ", board[k][j]);
        }
        printf("|| \n");
    }

    printf("  ");
    for (i = 0; i < 42; i++)
    {
        printf("-");
    }
    printf("\n");
}

void change(int r1, int c1, int r2, int c2) // Change the position of chess piece
{
    char temp;

    temp = board[r1][c1];
    board[r1][c1] = ' ';
    board[r2][c2] = temp;
}

void pawn(int r1, int c1) // Movement of Pawn
{
    int c2, r2, p2;

    int a1, a2, a3, a4, a5, a6, a7;
    pwstatus[c1]++;

    printf("\n\t\t>>>Available Positions are: ");

    if (pwstatus[c1] == 1)
    {
        if (board[r1 + 1][c1] == ' ')
        {
            printf("%d%d , ", r1 + 1, c1);
            a1 = ((r1 + 1) * 10) + c1;
        }

        if (board[r1 + 2][c1] == ' ')
        {
            printf("%d%d , ", r1 + 2, c1);
            a2 = ((r1 + 2) * 10) + c1;
        }
        if (check(r1 + 1, c1 + 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate chess piece %d%d* , ", r1 + 1, c1 + 1);
            a3 = ((r1 + 1) * 10) + (c1 + 1);
        }
        if (check(r1 + 1, c1 - 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate chess piece %d%d* , ", r1 + 1, c1 - 1);
            a4 = ((r1 + 1) * 10) + (c1 - 1);
        }
    }
    else
    {
        if (board[r1 + 1][c1] == ' ')
        {
            printf("%d%d , ", r1 + 1, c1);
            a5 = ((r1 + 1) * 10) + c1;
        }
        if (check(r1 + 1, c1 + 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate chess piece %d%d* , ", r1 + 1, c1 + 1);
            a6 = ((r1 + 1) * 10) + (c1 + 1);
        }
        if (check(r1 + 1, c1 - 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate chess piece %d%d* , ", r1 + 1, c1 - 1);
            a7 = ((r1 + 1) * 10) + (c1 - 1);
        }
    }
// Checking the invalid position
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if (p2 == a1 || p2 == a2 || p2 == a3 || p2 == a4 || p2 == a5 || p2 == a6 || p2 == a7)
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void rook(int r1, int c1) // Movement of Rook
{
    int i, j, n;
    int count_l = 0, count_r = 0, count_u = 0, count_d = 0;

    printf("\n\n\t\t>>>Available Position are: ");

    n = c1;

    printf("\n\n\t\t>>>Horizontally: ");

    while (board[r1][n - 1] == ' ')
    {
        if (n == 0)
        {
            break;
        }
        printf("%d%d , ", r1, n - 1);
        count_l++;
        n--;
    }

    n = c1;

    while (board[r1][n + 1] == ' ' && (n + 1) <= 7)
    {

        printf("%d%d , ", r1, n + 1);
        count_r++;
        ++n;
    }

    printf("\n\n\t\t>>>Vertically: ");

    n = r1;

    while (board[n - 1][c1] == ' ' && n > -1)
    {
        printf("%d%d , ", n - 1, c1);
        count_u++;
        --n;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ') && ((n) <= 7))
    {
        printf("%d%d , ", n + 1, c1);
        count_d++;
        ++n;
    }

    printf("\n\n\t\t>>>Eliminate the chess piece : ");

    n = c1;
    while ((n - 1) >= 0)
    {
        if (check2(r1, n - 1) == 1)
        {
            break;
        }

        if (check(r1, n - 1) == 1)
        {
            printf("%d%d* , ", r1, n - 1);
            count_l++;
            break;
        }

        n--;
    }

    count_l = c1 - count_l;

    n = c1;
    while ((n + 1) <= 7)
    {
        if (check2(r1, n + 1) == 1)
        {
            break;
        }

        if (check(r1, n + 1) == 1)
        {
            printf("%d%d* , ", r1, n + 1);
            count_r++;
            break;
        }

        n++;
    }

    count_r = c1 + count_r;

    n = r1;
    while ((n - 1) >= 0)
    {
        if (check2(n - 1, c1) == 1)
        {
            break;
        }

        if (check(n - 1, c1) == 1)
        {
            printf("%d%d* , ", n - 1, c1);
            count_u++;
            break;
        }

        n--;
    }

    count_u = r1 - count_u;

    n = r1;
    while ((n + 1) <= 7)
    {
        if (check2(n + 1, c1) == 1)
        {
            break;
        }

        if (check(n + 1, c1) == 1)
        {
            printf("%d%d* , ", n + 1, c1);
            count_d++;
            break;
        }
        n++;
    }

    count_d = r1 + count_d;

    // Check the Invalid Position

    int c2, r2, p2;

again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if ((c2 >= count_l && c2 < c1) && (r1 == r2)) // Left
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= count_r) && (r1 == r2))
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 >= count_u && r2 < r1) && (c1 == c2))
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 > r1 && r2 <= count_d) && (c1 == c2))
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void rook2(int r1, int c1) // Movement of Rook2
{
    int i, j, n;

    int count_l = 0, count_r = 0, count_u = 0, count_d = 0;

again:
    printf("\n\n>>>Available Positions are: ");

    n = c1;

    printf("\n\n>>>Horizontally: ");

    while (board[r1][n - 1] == ' ')
    {
        if (n == 0)
        {
            break;
        }
        printf("%d%d , ", r1, n - 1);
        count_l++;
        n--;
    }

    n = c1;

    while (board[r1][n + 1] == ' ' && (n + 1) <= 7)
    {

        printf("%d%d , ", r1, n + 1);
        count_r++;
        ++n;
    }

    printf("\n\n>>>Vertically: ");

    n = r1;

    while (board[n - 1][c1] == ' ' && n > -1)
    {
        printf("%d%d , ", n - 1, c1);
        count_u++;
        --n;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ') && ((n) <= 7))
    {
        printf("%d%d , ", n + 1, c1);
        count_d++;
        ++n;
    }

    printf("\n\n>>>Eliminate the chess piece : ");

    n = c1;
    while ((n - 1) >= 0)
    {
        if (check(r1, n - 1) == 1)
        {
            break;
        }

        if (check2(r1, n - 1) == 1)
        {
            printf("%d%d* , ", r1, n - 1);
            count_l++;
            break;
        }

        n--;
    }

    count_l = c1 - count_l;

    n = c1;
    while ((n + 1) <= 7)
    {
        if (check(r1, n + 1) == 1)
        {
            break;
        }

        if (check2(r1, n + 1) == 1)
        {
            printf("%d%d* , ", r1, n + 1);
            count_r++;
            break;
        }

        n++;
    }

    count_r = c1 + count_r;

    n = r1;
    while ((n - 1) >= 0)
    {
        if (check(n - 1, c1) == 1)
        {
            break;
        }

        if (check2(n - 1, c1) == 1)
        {
            printf("%d%d* , ", n - 1, c1);
            count_u++;
            break;
        }

        n--;
    }

    count_u = r1 - count_u;

    n = r1;
    while ((n + 1) <= 7)
    {
        if (check(n + 1, c1) == 1)
        {
            break;
        }

        if (check2(n + 1, c1) == 1)
        {
            printf("%d%d* , ", n + 1, c1);
            count_d++;
            break;
        }
        n++;
    }

    count_d = r1 + count_d;

    // Check the Invalid Position

    int c2, r2, p2;

    printf("\n\n>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if ((c2 >= count_l && c2 < c1) && (r1 == r2)) // Left
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= count_r) && (r1 == r2))
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 >= count_u && r2 < r1) && (c1 == c2))
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 > r1 && r2 <= count_d) && (c1 == c2))
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n>>>Enter a VALID position<<<");
        goto again;
    }
}

void horse(int r1, int c1) // Movement of horse
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int b1, b2, b3, b4, b5, b6, b7, b8;
again:
    printf("\n\n>>>Available Positions are: ");

    if ((board[r1 + 2][c1 + 1] == ' ') && (r1 + 2 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d, ", r1 + 2, c1 + 1);
        a1 = ((r1 + 2) * 10) + (c1 + 1);
    }

    if (board[r1 + 2][c1 - 1] == ' ' && ((c1 - 1) > -1) && (r1 + 2 <= 7))
    {
        printf("%d%d, ", r1 + 2, c1 - 1);
        a2 = ((r1 + 2) * 10) + (c1 - 1);
    }

    if (board[r1 + 1][c1 + 2] == ' ' && ((c1 + 2) <= 7) && (r1 + 1 <= 7))
    {
        printf("%d%d, ", r1 + 1, c1 + 2);
        a3 = ((r1 + 1) * 10) + (c1 + 2);
    }

    if (board[r1 - 1][c1 + 2] == ' ' && ((c1 + 2) <= 7) && (r1 - 1 >= 0))
    {
        printf("%d%d, ", r1 - 1, c1 + 2);
        a4 = ((r1 - 1) * 10) + (c1 + 2);
    }

    if (board[r1 - 2][c1 - 1] == ' ' && ((c1 - 1) >= 0) && ((r1 - 2) >= 0))
    {
        printf("%d%d, ", r1 - 2, c1 - 1);
        a5 = ((r1 - 2) * 10) + (c1 - 1);
    }

    if (board[r1 - 2][c1 + 1] == ' ' && ((c1 + 1) <= 7) && ((r1 - 2) >= 0))
    {
        printf("%d%d, ", r1 - 2, c1 + 1);
        a6 = ((r1 - 2) * 10) + (c1 + 1);
    }

    if (board[r1 + 1][c1 - 2] == ' ' && ((c1 - 2) >= 0) && ((r1 + 2) <= 7))
    {
        printf("%d%d, ", r1 + 1, c1 - 2);
        a7 = ((r1 + 1) * 10) + (c1 - 2);
    }

    if (board[r1 - 1][c1 - 2] == ' ' && ((c1 - 2) >= 0) && ((r1 - 1) >= 0))
    {
        printf("%d%d, ", r1 - 1, c1 - 2);
        a8 = ((r1 - 1) * 10) + (c1 - 2);
    }

    printf("\n\n>>>Eliminate chess piece : ");

    if ((check(r1 + 2, c1 + 1) == 1) && (r1 + 2 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d*,", r1 + 2, c1 + 1);
        b1 = ((r1 + 2) * 10) + (c1 + 1);
    }

    if (check(r1 + 2, c1 - 1) == 1 && ((c1 - 1) > -1) && (r1 + 2 <= 7))
    {
        printf("%d%d*,", r1 + 2, c1 - 1);
        b2 = ((r1 + 2) * 10) + (c1 - 1);
    }

    if (check(r1 + 1, c1 + 2) == 1 && ((c1 + 2) <= 7) && (r1 + 1 <= 7))
    {
        printf("%d%d*,", r1 + 1, c1 + 2);
        b3 = ((r1 + 1) * 10) + (c1 + 2);
    }

    if (check(r1 - 1, c1 + 2) == 1 && ((c1 + 2) <= 7) && (r1 - 1 >= 0))
    {
        printf("%d%d*,", r1 - 1, c1 + 2);
        b4 = ((r1 - 1) * 10) + (c1 + 2);
    }

    if (check(r1 - 2, c1 - 1) == 1 && ((c1 - 1) >= 0) && ((r1 - 2) >= 0))
    {
        printf("%d%d*,", r1 - 2, c1 - 1);
        b5 = ((r1 - 2) * 10) + (c1 - 1);
    }

    if (check(r1 - 2, c1 + 1) == 1 && ((c1 + 1) <= 7) && ((r1 - 2) >= 0))
    {
        printf("%d%d*,", r1 - 2, c1 + 1);
        b6 = ((r1 - 2) * 10) + (c1 + 1);
    }

    if (check(r1 + 1, c1 - 2) == 1 && ((c1 - 2) >= 0) && ((r1 + 2) <= 7))
    {
        printf("%d%d*,", r1 + 1, c1 - 2);
        b7 = ((r1 + 1) * 10) + (c1 - 2);
    }

    if (check(r1 - 1, c1 - 2) == 1 && ((c1 - 2) >= 0) && ((r1 - 1) >= 0))
    {
        printf("%d%d*,", r1 - 1, c1 - 2);
        b8 = ((r1 - 1) * 10) + (c1 - 2);
    }
    int r2, c2, p2;
    // Check invalid position

    printf("\n\n>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if (a1 == p2 || a2 == p2 || a3 == p2 || a4 == p2 || a5 == p2 || a6 == p2 || a7 == p2 || a8 == p2 ||
        b1 == p2 || b2 == p2 || b3 == p2 || b4 == p2 || b5 == p2 || b6 == p2 || b7 == p2 || b8 == p2)
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n>>>Enter a VALID position<<<");
        goto again;
    }
}

void horse2(int r1, int c1) // Movement of horse2
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int b1, b2, b3, b4, b5, b6, b7, b8;
again:
    printf("\n\n>>>Available Positions are: ");

    if ((board[r1 + 2][c1 + 1] == ' ') && (r1 + 2 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d, ", r1 + 2, c1 + 1);
        a1 = ((r1 + 2) * 10) + (c1 + 1);
    }

    if (board[r1 + 2][c1 - 1] == ' ' && ((c1 - 1) > -1) && (r1 + 2 <= 7))
    {
        printf("%d%d, ", r1 + 2, c1 - 1);
        a2 = ((r1 + 2) * 10) + (c1 - 1);
    }

    if (board[r1 + 1][c1 + 2] == ' ' && ((c1 + 2) <= 7) && (r1 + 1 <= 7))
    {
        printf("%d%d, ", r1 + 1, c1 + 2);
        a3 = ((r1 + 1) * 10) + (c1 + 2);
    }

    if (board[r1 - 1][c1 + 2] == ' ' && ((c1 + 2) <= 7) && (r1 - 1 >= 0))
    {
        printf("%d%d, ", r1 - 1, c1 + 2);
        a4 = ((r1 - 1) * 10) + (c1 + 2);
    }

    if (board[r1 - 2][c1 - 1] == ' ' && ((c1 - 1) >= 0) && ((r1 - 2) >= 0))
    {
        printf("%d%d, ", r1 - 2, c1 - 1);
        a5 = ((r1 - 2) * 10) + (c1 - 1);
    }

    if (board[r1 - 2][c1 + 1] == ' ' && ((c1 + 1) <= 7) && ((r1 - 2) >= 0))
    {
        printf("%d%d, ", r1 - 2, c1 + 1);
        a6 = ((r1 - 2) * 10) + (c1 + 1);
    }

    if (board[r1 + 1][c1 - 2] == ' ' && ((c1 - 2) >= 0) && ((r1 + 2) <= 7))
    {
        printf("%d%d, ", r1 + 1, c1 - 2);
        a7 = ((r1 + 1) * 10) + (c1 - 2);
    }

    if (board[r1 - 1][c1 - 2] == ' ' && ((c1 - 2) >= 0) && ((r1 - 1) >= 0))
    {
        printf("%d%d, ", r1 - 1, c1 - 2);
        a8 = ((r1 - 1) * 10) + (c1 - 2);
    }

    printf("\n\n>>>Eliminate chess piece : ");

    if ((check2(r1 + 2, c1 + 1) == 1) && (r1 + 2 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d*,", r1 + 2, c1 + 1);
        b1 = ((r1 + 2) * 10) + (c1 + 1);
    }

    if (check2(r1 + 2, c1 - 1) == 1 && ((c1 - 1) > -1) && (r1 + 2 <= 7))
    {
        printf("%d%d*,", r1 + 2, c1 - 1);
        b2 = ((r1 + 2) * 10) + (c1 - 1);
    }

    if (check2(r1 + 1, c1 + 2) == 1 && ((c1 + 2) <= 7) && (r1 + 1 <= 7))
    {
        printf("%d%d*,", r1 + 1, c1 + 2);
        b3 = ((r1 + 1) * 10) + (c1 + 2);
    }

    if (check2(r1 - 1, c1 + 2) == 1 && ((c1 + 2) <= 7) && (r1 - 1 >= 0))
    {
        printf("%d%d*,", r1 - 1, c1 + 2);
        b4 = ((r1 - 1) * 10) + (c1 + 2);
    }

    if (check2(r1 - 2, c1 - 1) == 1 && ((c1 - 1) >= 0) && ((r1 - 2) >= 0))
    {
        printf("%d%d*,", r1 - 2, c1 - 1);
        b5 = ((r1 - 2) * 10) + (c1 - 1);
    }

    if (check2(r1 - 2, c1 + 1) == 1 && ((c1 + 1) <= 7) && ((r1 - 2) >= 0))
    {
        printf("%d%d*,", r1 - 2, c1 + 1);
        b6 = ((r1 - 2) * 10) + (c1 + 1);
    }

    if (check2(r1 + 1, c1 - 2) == 1 && ((c1 - 2) >= 0) && ((r1 + 2) <= 7))
    {
        printf("%d%d*,", r1 + 1, c1 - 2);
        b7 = ((r1 + 1) * 10) + (c1 - 2);
    }

    if (check2(r1 - 1, c1 - 2) == 1 && ((c1 - 2) >= 0) && ((r1 - 1) >= 0))
    {
        printf("%d%d*,", r1 - 1, c1 - 2);
        b8 = ((r1 - 1) * 10) + (c1 - 2);
    }
    int r2, c2, p2;
    // Check invalid position

    printf("\n\n>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if (a1 == p2 || a2 == p2 || a3 == p2 || a4 == p2 || a5 == p2 || a6 == p2 || a7 == p2 || a8 == p2 ||
        b1 == p2 || b2 == p2 || b3 == p2 || b4 == p2 || b5 == p2 || b6 == p2 || b7 == p2 || b8 == p2)
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n>>>Enter a VALID position<<<");
        goto again;
    }
}

void bishop(int r1, int c1) // Movement of Bishop1
{
    int a, b, c, d;
    int r2, c2, p2;
    int count_ul = 0, count_dr = 0, count_ur = 0, count_dl = 0;
    int ulr = 0, ulc = 0, drr = 0, drc = 0, urr = 0, urc = 0, dlr = 0, dlc = 0;

    printf("\n\n\t\t>>>Available Positions are: ");

    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 - a, c1 + b);
        count_ur++;
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 + a, c1 - b);
        count_dl++;
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 + b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 + a, c1 + b);
        count_dr++;
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 - a, c1 - b);
        count_ul++;
        a++;
        b++;
    }

    printf("\n\n\t\t>>>Eliminate chess piece: ");

    a = 1, b = 1;

    while ((r1 - a) >= 0 && (c1 + b) <= 7)
    {
        if (check2(r1 - a, c1 + b) == 1)
        {
            break;
        }

        if (check(r1 - a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 + b);
            count_ur++;
            break;
        }
        a++;
        b++;
    }

    urr = r1 - count_ur;
    urc = c1 + count_ur;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 - b) >= 0)
    {
        if (check2(r1 + a, c1 - b) == 1)
        {
            break;
        }

        if (check(r1 + a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 - b);
            count_dl++;
            break;
        }
        a++;
        b++;
    }

    dlr = r1 + count_dl;
    dlc = c1 - count_dl;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 + b) <= 7)
    {
        if (check2(r1 + a, c1 + b) == 1)
        {
            break;
        }

        if (check(r1 + a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 + b);
            count_dr++;
            break;
        }
        a++;
        b++;
    }

    drr = r1 + count_dr;
    drc = c1 + count_dr;

    a = 1;
    b = 1;

    while ((r1 - a) >= 0 && (c1 - b) >= 0)
    {
        if (check2(r1 - a, c1 - b) == 1)
        {
            break;
        }

        if (check(r1 - a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 - b);
            count_ul++;
            break;
        }
        a++;
        b++;
    }

    ulr = r1 - count_ul;
    ulc = c1 - count_ul;

// Check the Invalid Position
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if ((r2 >= urr && r2 < r1) && (c2 > c1 && c2 <= urc))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= dlc && c2 < c1) && (r2 > r1 && r2 <= dlr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= drc) && (r2 > r1 && r2 <= drr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= ulc && c2 < c1) && (r2 >= ulr && r2 < r1))
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void bishop2(int r1, int c1) // Movement of Bishop2
{
    int a, b, c, d;
    int r2, c2, p2;
    int count_ul = 0, count_dr = 0, count_ur = 0, count_dl = 0;
    int ulr = 0, ulc = 0, drr = 0, drc = 0, urr = 0, urc = 0, dlr = 0, dlc = 0;

    printf("\n\n\t\t>>>Available Positions are: ");
// hhhhh
    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 - a, c1 + b);
        count_ur++;
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 + a, c1 - b);
        count_dl++;
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 + b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 + a, c1 + b);
        count_dr++;
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 - a, c1 - b);
        count_ul++;
        a++;
        b++;
    }

    printf("\n\n\t\t>>>Eliminate chess piece: ");

    a = 1, b = 1;

    while ((r1 - a) >= 0 && (c1 + b) <= 7)
    {
        if (check(r1 - a, c1 + b) == 1)
        {
            break;
        }

        if (check2(r1 - a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 + b);
            count_ur++;
            break;
        }
        a++;
        b++;
    }

    urr = r1 - count_ur;
    urc = c1 + count_ur;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 - b) >= 0)
    {
        if (check(r1 + a, c1 - b) == 1)
        {
            break;
        }

        if (check2(r1 + a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 - b);
            count_dl++;
            break;
        }
        a++;
        b++;
    }

    dlr = r1 + count_dl;
    dlc = c1 - count_dl;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 + b) <= 7)
    {
        if (check(r1 + a, c1 + b) == 1)
        {
            break;
        }

        if (check2(r1 + a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 + b);
            count_dr++;
            break;
        }
        a++;
        b++;
    }

    drr = r1 + count_dr;
    drc = c1 + count_dr;

    a = 1;
    b = 1;

    while ((r1 - a) >= 0 && (c1 - b) >= 0)
    {
        if (check(r1 - a, c1 - b) == 1)
        {
            break;
        }

        if (check2(r1 - a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 - b);
            count_ul++;
            break;
        }
        a++;
        b++;
    }

    ulr = r1 - count_ul;
    ulc = c1 - count_ul;

// Check the Invalid Position
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if ((r2 >= urr && r2 < r1) && (c2 > c1 && c2 <= urc))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= dlc && c2 < c1) && (r2 > r1 && r2 <= dlr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= drc) && (r2 > r1 && r2 <= drr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= ulc && c2 < c1) && (r2 >= ulr && r2 < r1))
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void king(int r1, int c1) // Movement of King
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int b1, b2, b3, b4, b5, b6, b7, b8;

    printf("\n\n\t\t>>>Available Positions are: ");
    if (board[r1][c1 + 1] == ' ' && (c1 + 1 <= 7))
    {
        printf("%d%d , ", r1, c1 + 1);
        a1 = ((r1)*10) + (c1 + 1);
    }

    if (board[r1][c1 - 1] == ' ' && (c1 - 1 >= 0))
    {
        printf("%d%d , ", r1, c1 - 1);
        a2 = ((r1)*10) + (c1 - 1);
    }

    if (board[r1 + 1][c1] == ' ' && (r1 + 1 <= 7))
    {
        printf("%d%d , ", r1 + 1, c1);
        a3 = ((r1 + 1) * 10) + (c1);
    }

    if (board[r1 - 1][c1] == ' ' && (r1 - 1 >= 0))
    {
        printf("%d%d , ", r1 - 1, c1);
        a4 = ((r1 - 1) * 10) + (c1);
    }

    if (board[r1 + 1][c1 + 1] == ' ' && (r1 + 1 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d , ", r1 + 1, c1 + 1);
        a5 = ((r1 + 1) * 10) + (c1 + 1);
    }

    if (board[r1 - 1][c1 - 1] == ' ' && (r1 - 1 >= 0) && (c1 - 1 >= 0))
    {
        printf("%d%d , ", r1 - 1, c1 - 1);
        a6 = ((r1 - 1) * 10) + (c1 - 1);
    }

    if (board[r1 - 1][c1 + 1] == ' ' && (r1 - 1 >= 0) && (c1 + 1 <= 7))
    {
        printf("%d%d , ", r1 - 1, c1 + 1);
        a7 = ((r1 - 1) * 10) + (c1 + 1);
    }

    if (board[r1 + 1][c1 - 1] == ' ' && (r1 + 1 <= 7) && (c1 - 1 >= 0))
    {
        printf("%d%d , ", r1 + 1, c1 - 1);
        a8 = ((r1 + 1) * 10) + (c1 - 1);
    }

    printf("\n\n\t\t>>>Eliminate chess piece: ");

    if (check(r1, c1 + 1) == 1 && (c1 + 1 <= 7))
    {
        printf("%d%d* , ", r1, c1 + 1);
        b1 = ((r1)*10) + (c1 + 1);
    }

    if (check(r1, c1 - 1) == 1 && (c1 - 1 >= 0))
    {
        printf("%d%d* , ", r1, c1 - 1);
        b2 = ((r1)*10) + (c1 - 1);
    }

    if (check(r1 + 1, c1) == 1 && (r1 + 1 <= 7))
    {
        printf("%d%d* , ", r1 + 1, c1);
        b3 = ((r1 + 1) * 10) + (c1);
    }

    if (check(r1 - 1, c1) == 1 && (r1 - 1 >= 0))
    {
        printf("%d%d* , ", r1 - 1, c1);
        b4 = ((r1 - 1) * 10) + (c1);
    }

    if (check(r1 + 1, c1 + 1) == 1 && (r1 + 1 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d* , ", r1 + 1, c1 + 1);
        b5 = ((r1 + 1) * 10) + (c1 + 1);
    }

    if (check(r1 - 1, c1 - 1) == 1 && (r1 - 1 >= 0) && (c1 - 1 >= 0))
    {
        printf("%d%d* , ", r1 - 1, c1 - 1);
        b6 = ((r1 - 1) * 10) + (c1 - 1);
    }

    if (check(r1 - 1, c1 + 1) == 1 && (r1 - 1 >= 0) && (c1 + 1 <= 7))
    {
        printf("%d%d* , ", r1 - 1, c1 + 1);
        b7 = ((r1 - 1) * 10) + (c1 + 1);
    }

    if (check(r1 + 1, c1 - 1) == 1 && (r1 + 1 <= 7) && (c1 - 1 >= 0))
    {
        printf("%d%d* , ", r1 + 1, c1 - 1);
        b8 = ((r1 - 1) * 10) + (c1 - 1);
    }

    // Check invalid position
    int r2, c2, p2;
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if (a1 == p2 || a2 == p2 || a3 == p2 || a4 == p2 || a5 == p2 || a6 == p2 || a7 == p2 || a8 == p2 ||
        b1 == p2 || b2 == p2 || b3 == p2 || b4 == p2 || b5 == p2 || b6 == p2 || b7 == p2 || b8 == p2)
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void king2(int r1, int c1) // Movement of King2
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int b1, b2, b3, b4, b5, b6, b7, b8;

    printf("\n\n\t\t>>>Available Positions are: ");
    if (board[r1][c1 + 1] == ' ' && (c1 + 1 <= 7))
    {
        printf("%d%d , ", r1, c1 + 1);
        a1 = ((r1)*10) + (c1 + 1);
    }

    if (board[r1][c1 - 1] == ' ' && (c1 - 1 >= 0))
    {
        printf("%d%d , ", r1, c1 - 1);
        a2 = ((r1)*10) + (c1 - 1);
    }

    if (board[r1 + 1][c1] == ' ' && (r1 + 1 <= 7))
    {
        printf("%d%d , ", r1 + 1, c1);
        a3 = ((r1 + 1) * 10) + (c1);
    }

    if (board[r1 - 1][c1] == ' ' && (r1 - 1 >= 0))
    {
        printf("%d%d , ", r1 - 1, c1);
        a4 = ((r1 - 1) * 10) + (c1);
    }

    if (board[r1 + 1][c1 + 1] == ' ' && (r1 + 1 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d , ", r1 + 1, c1 + 1);
        a5 = ((r1 + 1) * 10) + (c1 + 1);
    }

    if (board[r1 - 1][c1 - 1] == ' ' && (r1 - 1 >= 0) && (c1 - 1 >= 0))
    {
        printf("%d%d , ", r1 - 1, c1 - 1);
        a6 = ((r1 - 1) * 10) + (c1 - 1);
    }

    if (board[r1 - 1][c1 + 1] == ' ' && (r1 - 1 >= 0) && (c1 + 1 <= 7))
    {
        printf("%d%d , ", r1 - 1, c1 + 1);
        a7 = ((r1 - 1) * 10) + (c1 + 1);
    }

    if (board[r1 + 1][c1 - 1] == ' ' && (r1 + 1 <= 7) && (c1 - 1 >= 0))
    {
        printf("%d%d , ", r1 + 1, c1 - 1);
        a8 = ((r1 + 1) * 10) + (c1 - 1);
    }

    printf("\n\n\t\t>>>Eliminate chess piece: ");

    if (check2(r1, c1 + 1) == 1 && (c1 + 1 <= 7))
    {
        printf("%d%d* , ", r1, c1 + 1);
        b1 = ((r1)*10) + (c1 + 1);
    }

    if (check2(r1, c1 - 1) == 1 && (c1 - 1 >= 0))
    {
        printf("%d%d* , ", r1, c1 - 1);
        b2 = ((r1)*10) + (c1 - 1);
    }

    if (check2(r1 + 1, c1) == 1 && (r1 + 1 <= 7))
    {
        printf("%d%d* , ", r1 + 1, c1);
        b3 = ((r1 + 1) * 10) + (c1);
    }

    if (check2(r1 - 1, c1) == 1 && (r1 - 1 >= 0))
    {
        printf("%d%d* , ", r1 - 1, c1);
        b4 = ((r1 - 1) * 10) + (c1);
    }

    if (check2(r1 + 1, c1 + 1) == 1 && (r1 + 1 <= 7) && (c1 + 1 <= 7))
    {
        printf("%d%d* , ", r1 + 1, c1 + 1);
        b5 = ((r1 + 1) * 10) + (c1 + 1);
    }

    if (check2(r1 - 1, c1 - 1) == 1 && (r1 - 1 >= 0) && (c1 - 1 >= 0))
    {
        printf("%d%d* , ", r1 - 1, c1 - 1);
        b6 = ((r1 - 1) * 10) + (c1 - 1);
    }

    if (check2(r1 - 1, c1 + 1) == 1 && (r1 - 1 >= 0) && (c1 + 1 <= 7))
    {
        printf("%d%d* , ", r1 - 1, c1 + 1);
        b7 = ((r1 - 1) * 10) + (c1 + 1);
    }

    if (check2(r1 + 1, c1 - 1) == 1 && (r1 + 1 <= 7) && (c1 - 1 >= 0))
    {
        printf("%d%d* , ", r1 + 1, c1 - 1);
        b8 = ((r1 - 1) * 10) + (c1 - 1);
    }

    // Check invalid position
    int r2, c2, p2;
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if (a1 == p2 || a2 == p2 || a3 == p2 || a4 == p2 || a5 == p2 || a6 == p2 || a7 == p2 || a8 == p2 ||
        b1 == p2 || b2 == p2 || b3 == p2 || b4 == p2 || b5 == p2 || b6 == p2 || b7 == p2 || b8 == p2)
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void queen(int r1, int c1) // Movement of  Queen
{
    int x = 1, y = 1, a, b;
    int count_l = 0, count_r = 0, count_u = 0, count_d = 0;
    int r2, c2, p2;
    int count_ul = 0, count_dr = 0, count_ur = 0, count_dl = 0;
    int ulr = 0, ulc = 0, drr = 0, drc = 0, urr = 0, urc = 0, dlr = 0, dlc = 0;

    printf("\n\n\t\t>>>Available Positions are: ");

    printf("\n\n\t\t>>>Horizontal: ");

    while (board[r1][c1 - y] == ' ')
    {
        if ((c1 - y) == -1)
            break;
        printf("%d%d , ", r1, c1 - y);
        count_l++;

        y++;
    }
    y = 1;

    while (board[r1][c1 + y] == ' ')
    {
        if ((c1 + y) == 8)
            break;
        printf("%d%d , ", r1, c1 + y);
        count_r++;
        y++;
    }

    printf("\n\n\t\t>>>Vertical: ");

    x = 1;

    while (board[r1 - x][c1] == ' ')
    {
        if ((r1 - x) == -1)
            break;
        printf("%d%d , ", r1 - x, c1);
        count_u++;
        x++;
    }

    x = 1;

    while (board[r1 + x][c1] == ' ')
    {
        if ((r1 + x) == 8)
            break;
        printf("%d%d , ", r1 + x, c1);
        count_d++;
        x++;
    }

    printf("\n\n\t\t>>>Diagonally: ");

    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 - a, c1 + b);
        count_ur++;
        a++;
        b++;
    }

    a = 1, b = 1;
    while (board[r1 + a][c1 - b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 + a, c1 - b);
        count_dl++;
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 + b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 + a, c1 + b);
        count_dr++;
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 - a, c1 - b);
        count_ul++;
        a++;
        b++;
    }
    printf("\n\n\t\t>>>Eliminate the chess piece : ");

    y = 1;
    while ((c1 - y) >= 0)
    {
        if (check2(r1, c1 - y))
        {
            break;
        }

        if (check(r1, c1 - y) == 1)
        {
            printf("%d%d* , ", r1, c1 - y);
            count_l++;
            break;
        }

        y++;
    }

    count_l = c1 - count_l;

    y = 1;

    while ((c1 + y) <= 7)
    {
        if (check2(r1, c1 - y))
        {
            break;
        }

        if (check(r1, c1 + y) == 1)
        {
            printf("%d%d* , ", r1, c1 + y);
            count_r++;
            break;
        }

        y++;
    }

    count_r = c1 + count_r;

    x = 1;

    while ((r1 - x) >= 0)
    {
        if (check2(r1 - x, c1))
        {
            break;
        }

        if (check(r1 - x, c1) == 1)
        {
            printf("%d%d* , ", r1 - x, c1);
            count_u++;
            break;
        }

        x++;
    }

    count_u = r1 - count_u;

    x = 1;

    while ((r1 + x) <= 7)
    {
        if (check2(r1 + x, c1))
        {
            break;
        }

        if (check(r1 + x, c1) == 1)
        {
            printf("%d%d* , ", r1 + x, c1);
            count_d++;
            break;
        }

        x++;
    }

    count_d = r1 + count_d;

    a = 1, b = 1;

    while ((r1 - a) >= 0 && (c1 + b) <= 7)
    {
        if (check2(r1 - a, c1 + b) == 1)
        {
            break;
        }

        if (check(r1 - a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 + b);
            count_ur++;
            break;
        }
        a++;
        b++;
    }

    urr = r1 - count_ur;
    urc = c1 + count_ur;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 - b) >= 0)
    {
        if (check2(r1 + a, c1 - b) == 1)
        {
            break;
        }

        if (check(r1 + a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 - b);
            count_dl++;
            break;
        }
        a++;
        b++;
    }

    dlr = r1 + count_dl;
    dlc = c1 - count_dl;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 + b) <= 7)
    {
        if (check2(r1 + a, c1 + b) == 1)
        {
            break;
        }

        if (check(r1 + a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 + b);
            count_dr++;
            break;
        }
        a++;
        b++;
    }

    drr = r1 + count_dr;
    drc = c1 + count_dr;

    a = 1;
    b = 1;

    while ((r1 - a) >= 0 && (c1 - b) >= 0)
    {
        if (check2(r1 - a, c1 - b) == 1)
        {
            break;
        }

        if (check(r1 - a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 - b);
            count_ul++;
            break;
        }
        a++;
        b++;
    }

    ulr = r1 - count_ul;
    ulc = c1 - count_ul;

// Check the Invalid Position
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if ((c2 >= count_l && c2 < c1) && (r1 == r2)) // Left
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= count_r) && (r1 == r2)) // Right
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 >= count_u && r2 < r1) && (c1 == c2)) // Up
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 > r1 && r2 <= count_d) && (c1 == c2)) // Down
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 >= urr && r2 < r1) && (c2 > c1 && c2 <= urc))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= dlc && c2 < c1) && (r2 > r1 && r2 <= dlr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= drc) && (r2 > r1 && r2 <= drr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= ulc && c2 < c1) && (r2 >= ulr && r2 < r1))
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter Valid Position\n");
        goto again;
    }
}

void queen2(int r1, int c1) // Movement of  Queen2
{
    int x = 1, y = 1, a, b;
    int count_l = 0, count_r = 0, count_u = 0, count_d = 0;
    int r2, c2, p2;
    int count_ul = 0, count_dr = 0, count_ur = 0, count_dl = 0;
    int ulr = 0, ulc = 0, drr = 0, drc = 0, urr = 0, urc = 0, dlr = 0, dlc = 0;

    printf("\n\n\t\t>>>Available Positions are: ");

    printf("\n\n\t\t>>>Horizontal: ");

    while (board[r1][c1 - y] == ' ')
    {
        if ((c1 - y) == -1)
            break;
        printf("%d%d , ", r1, c1 - y);
        count_l++;

        y++;
    }
    y = 1;

    while (board[r1][c1 + y] == ' ')
    {
        if ((c1 + y) == 8)
            break;
        printf("%d%d , ", r1, c1 + y);
        count_r++;
        y++;
    }

    printf("\n\n\t\t>>>Vertical: ");

    x = 1;

    while (board[r1 - x][c1] == ' ')
    {
        if ((r1 - x) == -1)
            break;
        printf("%d%d , ", r1 - x, c1);
        count_u++;
        x++;
    }

    x = 1;

    while (board[r1 + x][c1] == ' ')
    {
        if ((r1 + x) == 8)
            break;
        printf("%d%d , ", r1 + x, c1);
        count_d++;
        x++;
    }

    printf("\n\n\t\t>>>Diagonally: ");

    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 - a, c1 + b);
        count_ur++;
        a++;
        b++;
    }

    a = 1, b = 1;
    while (board[r1 + a][c1 - b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 + a, c1 - b);
        count_dl++;
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 + b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8)
            break;
        printf("%d%d , ", r1 + a, c1 + b);
        count_dr++;
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1)
            break;
        printf("%d%d , ", r1 - a, c1 - b);
        count_ul++;
        a++;
        b++;
    }
    printf("\n\n\t\t>>>Eliminate the chess piece :");

    y = 1;
    while ((c1 - y) >= 0)
    {
        if (check(r1, c1 - y))
        {
            break;
        }

        if (check2(r1, c1 - y) == 1)
        {
            printf("%d%d* , ", r1, c1 - y);
            count_l++;
            break;
        }

        y++;
    }

    count_l = c1 - count_l;

    y = 1;

    while ((c1 + y) <= 7)
    {
        if (check(r1, c1 - y))
        {
            break;
        }

        if (check2(r1, c1 + y) == 1)
        {
            printf("%d%d* , ", r1, c1 + y);
            count_r++;
            break;
        }

        y++;
    }

    count_r = c1 + count_r;

    x = 1;

    while ((r1 - x) >= 0)
    {
        if (check(r1 - x, c1))
        {
            break;
        }

        if (check2(r1 - x, c1) == 1)
        {
            printf("%d%d* , ", r1 - x, c1);
            count_u++;
            break;
        }

        x++;
    }

    count_u = r1 - count_u;

    x = 1;

    while ((r1 + x) <= 7)
    {
        if (check(r1 + x, c1))
        {
            break;
        }

        if (check2(r1 + x, c1) == 1)
        {
            printf("%d%d* , ", r1 + x, c1);
            count_d++;
            break;
        }

        x++;
    }

    count_d = r1 + count_d;

    a = 1, b = 1;

    while ((r1 - a) >= 0 && (c1 + b) <= 7)
    {
        if (check(r1 - a, c1 + b) == 1)
        {
            break;
        }

        if (check2(r1 - a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 + b);
            count_ur++;
            break;
        }
        a++;
        b++;
    }

    urr = r1 - count_ur;
    urc = c1 + count_ur;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 - b) >= 0)
    {
        if (check(r1 + a, c1 - b) == 1)
        {
            break;
        }

        if (check2(r1 + a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 - b);
            count_dl++;
            break;
        }
        a++;
        b++;
    }

    dlr = r1 + count_dl;
    dlc = c1 - count_dl;

    a = 1, b = 1;

    while ((r1 + a) <= 7 && (c1 + b) <= 7)
    {
        if (check(r1 + a, c1 + b) == 1)
        {
            break;
        }

        if (check2(r1 + a, c1 + b) == 1)
        {
            printf("%d%d* , ", r1 + a, c1 + b);
            count_dr++;
            break;
        }
        a++;
        b++;
    }

    drr = r1 + count_dr;
    drc = c1 + count_dr;

    a = 1;
    b = 1;

    while ((r1 - a) >= 0 && (c1 - b) >= 0)
    {
        if (check(r1 - a, c1 - b) == 1)
        {
            break;
        }

        if (check2(r1 - a, c1 - b) == 1)
        {
            printf("%d%d* , ", r1 - a, c1 - b);
            count_ul++;
            break;
        }
        a++;
        b++;
    }

    ulr = r1 - count_ul;
    ulc = c1 - count_ul;

// Check the Invalid Position
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if ((c2 >= count_l && c2 < c1) && (r1 == r2)) // Left
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= count_r) && (r1 == r2)) // Right
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 >= count_u && r2 < r1) && (c1 == c2)) // Up
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 > r1 && r2 <= count_d) && (c1 == c2)) // Down
    {
        change(r1, c1, r2, c2);
    }
    else if ((r2 >= urr && r2 < r1) && (c2 > c1 && c2 <= urc))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= dlc && c2 < c1) && (r2 > r1 && r2 <= dlr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 > c1 && c2 <= drc) && (r2 > r1 && r2 <= drr))
    {
        change(r1, c1, r2, c2);
    }
    else if ((c2 >= ulc && c2 < c1) && (r2 >= ulr && r2 < r1))
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter a VALID position<<<");
        goto again;
    }
}

void pawnb(int r1, int c1) //// Movement of  pawn2
{
    int a1, a2, a3, a4, a5, a6, a7;
    pbstatus[c1]++;

    printf("\n\n\t\t>>>Available Positions are: ");

    if (pbstatus[c1] == 1)
    {
        if (board[r1 - 1][c1] == ' ')
        {
            printf("%d%d , ", r1 - 1, c1);
            a1 = ((r1 - 1) * 10) + c1;
        }
        if (board[r1 - 2][c1] == ' ')
        {
            printf("%d%d , ", r1 - 2, c1);
            a2 = ((r1 - 2) * 10) + c1;
        }
        if (check2(r1 - 1, c1 + 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate chess piece %d%d* , ", r1 - 1, c1 + 1);
            a3 = ((r1 - 1) * 10) + (c1 + 1);
        }
        if (check2(r1 - 1, c1 - 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate chess piece %d%d* , ", r1 - 1, c1 - 1);
            a4 = ((r1 - 1) * 10) + (c1 - 1);
        }
    }
    else
    {
        if (board[r1 - 1][c1] == ' ')
        {
            printf("%d%d , ", r1 - 1, c1);
            a5 = ((r1 - 1) * 10) + c1;
        }
        if (check2(r1 - 1, c1 - 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate the chess piece %d%d* , ", r1 - 1, c1 - 1);
            a6 = ((r1 - 1) * 10) + (c1 - 1);
        }
        if (check2(r1 - 1, c1 + 1) == 1)
        {
            printf("\n\n\t\t>>>Eliminate the chess piece %d%d* , ", r1 - 1, c1 + 1);
            a7 = ((r1 - 1) * 10) + (c1 + 1);
        }
    }

    int c2, r2, p2;
again:
    printf("\n\n\t\t>>>Enter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    if (p2 == a1 || p2 == a2 || p2 == a3 || p2 == a4 || p2 == a5 || p2 == a6 || p2 == a7)
    {
        change(r1, c1, r2, c2);
    }
    else
    {
        printf("\n\n\t\t>>>Enter Valid Position<<<");
        goto again;
    }
}

void player1(char str1[100])  // Input of player 1
{
    int p1, p2, c1, r1, c2, r2;

    printf("\n\n\t\t>>>%s it is your turn(Big Case)\n",str1);
again1:
    printf("\n\n\t\t>>>Enter Position of Element to change ( RC ): ");
    scanf("%d", &p1);

    c1 = p1 % 10;
    r1 = p1 / 10;

    switch (board[r1][c1])
    {
    case 'P':
        pawn(r1, c1);
        break;
    case 'R':
        rook(r1, c1);
        break;
    case 'H':
        horse(r1, c1);
        break;
    case 'B':
        bishop(r1, c1);
        break;
    case 'K':
        king(r1, c1);
        break;
    case 'Q':
        queen(r1, c1);
        break;
    default:
        printf("\n\n\t\t>>>Invalid Position ! <<<");
        goto again1;
    }

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'k')
            {
                count = 1;
                break;
            }
        }
    }
    if (count == 0)
    {
        printf("\n\n****************************\n\n");
        printf("\n\n>>>%s is the Winner\n", str1);
        printf("\n\n****************************\n\n");
        FILE *score;
        score=fopen("score.txt", "a");
        fprintf(score,"%s is winner \n",str1);
        fclose(score);
        exit(0);
    }
}

void player2(char str2[100])  // Input of player2
{
    int p1, p2, c1, r1, c2, r2;

    printf("\n\n\t\t>>>%s it is your turn(Small Case)\n",str2);
again2:
    printf("\n\n\t\t>>>Enter Position of Element to change ( RC ): ");
    scanf("%d", &p1);

    c1 = p1 % 10;
    r1 = p1 / 10;

    switch (board[r1][c1])
    {
    case 'p':
        pawnb(r1, c1);
        break;
    case 'r':
        rook2(r1, c1);
        break;
    case 'h':
        horse2(r1, c1);
        break;
    case 'b':
        bishop2(r1, c1);
        break;
    case 'k':
        king2(r1, c1);
        break;
    case 'q':
        queen2(r1, c1);
        break;
    default:
        printf("\n\n\t\t>>>Invalid Position ! <<<");
        goto again2;
    }

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'K')
            {
                count = 1;
                break;
            }
        }
    }
    if (count == 0)
    {
        printf("\n\n****************************\n\n");
        printf("\n\n>>>%s is the Winner\n", str2);
        printf("\n\n****************************\n\n");
        FILE *score;
        score=fopen("score.txt", "a");
        fprintf(score,"%s_is_winner\n",str2);
        fclose(score);
        exit(0);
    }
}

int check(int x, int y) // check for player 1
{
    switch (board[x][y])
    {
    case 'p':
    case 'r':
    case 'h':
    case 'b':
    case 'k':
    case 'q':
        return 1;
        break;
    default:
        return 0;
    }
}

int check2(int x, int y) // check for player 2
{
    switch (board[x][y])
    {
    case 'P':
    case 'R':
    case 'H':
    case 'B':
    case 'K':
    case 'Q':
        return 1;
        break;
    default:
        return 0;
    }
}
