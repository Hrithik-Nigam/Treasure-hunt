#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_SIZE 20
#define GAP_SIZE 7
#define Enemy_DIF 45
using namespace std;
char print_board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int count = 5;
int tic_win = 0;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, sn_score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirecton dir;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char ship[3][5] = {' ', '.', '*', '.', ' ',
                   '^', '*', '*', '*', '^',
                   ' ', '.', '*', '.', ' '};
int shipPos = WIN_WIDTH / 2;
int sp_score = 0;
int bullets[20][4];
int bulletsLife[20];
int bIndex = 0;
class information
{
public:
    static string Name;
};
string information::Name = "Invalid!!";
class ttt
{
public:
    int sample_board()
    {
        cout << print_board[1] << " | " << print_board[2] << " | " << print_board[3] << endl;
        cout << print_board[4] << " | " << print_board[5] << " | " << print_board[6] << endl;
        cout << print_board[7] << " | " << print_board[8] << " | " << print_board[9] << endl;
        return 0;
    }
    int check()
    {
        int x, y, i;
        while (count--)
        {
            if (count > 0)
            {
                cout << "player O" << endl;
                cin >> x;
                print_board[x] = 'O';
                cout << "\n";
                sample_board();
                cout << "player X" << endl;
                cin >> y;
            }
            print_board[y] = 'X';
            cout << "\n";
            sample_board();
            i = result();
            if (i == 0)
            {
                cout << "PLAYER O WINS\n";
                tic_win = 20;
            }
            else if (i == 1)
                cout << "PLAYER X WINS\n";
            else
                check();
        }
        return tic_win;
    }
    int result()
    {
        if (print_board[1] == 'O' && print_board[2] == 'O' && print_board[3] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[4] == 'O' && print_board[5] == 'O' && print_board[6] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[7] == 'O' && print_board[8] == 'O' && print_board[9] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[1] == 'O' && print_board[4] == 'O' && print_board[7] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[2] == 'O' && print_board[5] == 'O' && print_board[8] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[3] == 'O' && print_board[6] == 'O' && print_board[9] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[1] == 'O' && print_board[5] == 'O' && print_board[9] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[3] == 'O' && print_board[5] == 'O' && print_board[7] == 'O')
        {
            count = 0;
            return 0;
        }
        else if (print_board[1] == 'X' && print_board[2] == 'X' && print_board[3] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[4] == 'X' && print_board[5] == 'X' && print_board[6] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[7] == 'X' && print_board[8] == 'X' && print_board[9] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[1] == 'X' && print_board[4] == 'X' && print_board[7] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[2] == 'X' && print_board[5] == 'X' && print_board[8] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[3] == 'X' && print_board[6] == 'X' && print_board[9] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[1] == 'X' && print_board[5] == 'X' && print_board[9] == 'X')
        {
            count = 0;
            return 1;
        }
        else if (print_board[3] == 'X' && print_board[5] == 'X' && print_board[7] == 'X')
        {
            count = 0;
            return 1;
        }
        else
        {
            return -1;
        }
        return 0;
    }
};
class snake
{
public:
    void Setup()
    {
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        sn_score = 0;
    }
    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                    cout << "#";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "F";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }

                if (j == width - 1)
                    cout << "#";
            }
            cout << endl;
        }
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score:" << sn_score << endl;
    }
    void Input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }
    int Logic()
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }
        if (x > width || x < 0 || y > height || y < 0)
            gameOver = true;
        if (x >= width)
            x = 0;
        else if (x < 0)
            x = width - 1;
        if (y >= height)
            y = 0;
        else if (y < 0)
            y = height - 1;

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;

        if (x == fruitX && y == fruitY)
        {
            sn_score += 1;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
        }
        return sn_score;
    }
};
class spaceship
{
public:
    void gotoxy(int x, int y)
    {
        CursorPosition.X = x;
        CursorPosition.Y = y;
        SetConsoleCursorPosition(console, CursorPosition);
    }
    void setCursor(bool visible, DWORD size)
    {
        if (size == 0)
            size = 20;

        CONSOLE_CURSOR_INFO lpCursor;
        lpCursor.bVisible = visible;
        lpCursor.dwSize = size;
        SetConsoleCursorInfo(console, &lpCursor);
    }
    void drawBorder()
    {
        for (int i = 0; i < SCREEN_WIDTH; i++)
        {
            gotoxy(i, SCREEN_WIDTH);
            cout << "*";
        }
        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            gotoxy(0, i);
            cout << "*";
            gotoxy(SCREEN_WIDTH, i);
            cout << "*";
        }
        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            gotoxy(WIN_WIDTH, i);
            cout << "*";
        }
    }
    void genEnemy(int ind)
    {
        enemyX[ind] = 3 + rand() % (WIN_WIDTH - 10);
    }
    void drawEnemy(int ind)
    {
        if (enemyFlag[ind] == true)
        {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "VuuV";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << "|--|";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "|--|";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " || ";
        }
    }
    void eraseEnemy(int ind)
    {
        if (enemyFlag[ind] == true)
        {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "     ";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << "     ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "     ";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << "     ";
        }
    }
    void resetEnemy(int ind)
    {
        eraseEnemy(ind);
        enemyY[ind] = 4;
        genEnemy(ind);
    }
    void genBullet()
    {
        bullets[bIndex][0] = 22;
        bullets[bIndex][1] = shipPos;
        bullets[bIndex][2] = 22;
        bullets[bIndex][3] = shipPos + 4;
        bIndex++;
        if (bIndex == 20)
            bIndex = 0;
    }
    void drawBullets()
    {
        for (int i = 0; i < 20; i++)
        {
            if (bullets[i][0] > 1)
            {
                gotoxy(bullets[i][1], bullets[i][0]);
                cout << "|";
                gotoxy(bullets[i][3], bullets[i][2]);
                cout << "|";
            }
        }
    }
    void moveBullet()
    {
        for (int i = 0; i < 20; i++)
        {
            if (bullets[i][0] > 2)
                bullets[i][0]--;
            else
                bullets[i][0] = 0;
            if (bullets[i][2] > 2)
                bullets[i][2]--;
            else
                bullets[i][2] = 0;
        }
    }
    void eraseBullets()
    {
        for (int i = 0; i < 20; i++)
        {
            if (bullets[i][0] >= 1)
            {
                gotoxy(bullets[i][1], bullets[i][0]);
                cout << " ";
                gotoxy(bullets[i][3], bullets[i][2]);
                cout << " ";
            }
        }
    }
    void eraseBullet(int i)
    {
        gotoxy(bullets[i][1], bullets[i][0]);
        cout << " ";
        gotoxy(bullets[i][3], bullets[i][2]);
        cout << " ";
    }
    void drawship()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                gotoxy(j + shipPos, i + 22);
                cout << ship[i][j];
            }
        }
    }
    void eraseship()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                gotoxy(j + shipPos, i + 22);
                cout << " ";
            }
        }
    }
    int collision()
    {
        if (enemyY[0] + 4 >= 23)
        {
            if (enemyX[0] + 4 - shipPos >= 0 && enemyX[0] + 4 - shipPos < 8)
            {
                return 1;
            }
        }
        return 0;
    }
    int bulletHit()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 4; j += 2)
            {
                if (bullets[i][j] != 0)
                {
                    if (bullets[i][j] >= enemyY[0] && bullets[i][j] <= enemyY[0] + 4)
                    {
                        if (bullets[i][j + 1] >= enemyX[0] && bullets[i][j + 1] <= enemyX[0] + 4)
                        {
                            eraseBullet(i);
                            bullets[i][j] = 0;
                            resetEnemy(0);
                            return 1;
                        }
                    }
                }
                if (bullets[i][j] >= enemyY[1] && bullets[i][j] <= enemyY[1] + 4)
                {
                    if (bullets[i][j + 1] >= enemyX[1] && bullets[i][j + 1] <= enemyX[1] + 4)
                    {
                        eraseBullet(i);
                        resetEnemy(1);
                        bullets[i][j] = 0;
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    void gameover()
    {
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t~~~~~~ MAY THE FORCE BE WITH YOU ~~~~~~~~" << endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t****** Press any key to continue ********" << endl;
        cout << "\t\t_________________________________________" << endl;
        getch();
    }
    void updatesp_score()
    {
        gotoxy(WIN_WIDTH + 7, 5);
        cout << "Score: " << sp_score << endl;
    }
    void instructions()
    {
        system("cls");
        cout << "Instructions: ";
        cout << "Press spacebar to make the ship shoot." << endl;
        cout << "Press A for left and D for right movement" << endl;
        cout << "Press any key to go back to main menu." << endl;
        getch();
    }
    int play()
    {
        shipPos = -1 + WIN_WIDTH / 2;
        sp_score = 0;
        enemyFlag[0] = 1;
        enemyFlag[1] = 1;
        enemyY[0] = enemyY[1] = 4;
        for (int i = 0; i < 20; i++)
        {
            bullets[i][0] = bullets[i][1] = 0;
        }
        system("cls");
        drawBorder();
        genEnemy(0);
        genEnemy(1);
        updatesp_score();
        gotoxy(WIN_WIDTH + 5, 2);
        cout << "Space Shooter";
        gotoxy(WIN_WIDTH + 6, 4);
        cout << "*************";
        gotoxy(WIN_WIDTH + 6, 6);
        cout << "Controls ===>";
        gotoxy(WIN_WIDTH + 7, 12);
        cout << "A key-> Left";
        gotoxy(WIN_WIDTH + 7, 13);
        cout << "D key-> Right";
        gotoxy(WIN_WIDTH + 2, 14);
        cout << "Spacebar-> Shoot!";
        gotoxy(10, 5);
        cout << "Press any Key to start.";
        getch();
        gotoxy(10, 5);
        cout << "                       ";

        while (sp_score < 20)
        {
            if (kbhit())
            {
                char ch = getch();
                if (ch == 'a' || ch == 'A')
                {
                    if (shipPos > 2)
                        shipPos -= 2;
                }
                if (ch == 'd' || ch == 'D')
                {
                    if (shipPos < WIN_WIDTH - 7)
                        shipPos += 2;
                }
                if (ch == 32)
                    genBullet();
                if (ch == 27)
                    break;
            }
            drawship();
            drawEnemy(0);
            drawEnemy(1);
            drawBullets();
            if (collision() == 1)
            {
                gameover();
                return sp_score;
            }
            if (bulletHit() == 1)
            {
                sp_score++;
                updatesp_score();
            }
            Sleep(100);
            eraseship();
            eraseEnemy(0);
            eraseEnemy(1);
            eraseBullets();
            moveBullet();

            if (enemyFlag[0] == 1)
            {
                enemyY[0] += 1;
            }
            if (enemyFlag[1] == 1)
            {
                enemyY[1] += 1;
            }
            if (enemyY[0] > SCREEN_HEIGHT - 5)
            {
                resetEnemy(0);
            }
            if (enemyY[1] > SCREEN_HEIGHT - 5)
            {
                resetEnemy(1);
            }
        }
        return sp_score;
    }
};
class path1 : public ttt, public information, public snake, public spaceship
{
public:
    char ch;
    void start1()
    {
    loop:
        cout << "You are: " << information::Name;
        getch();
        cout << "You stand in front of a board displaying Tic-tac-toe. Solve it to prove your worth.\nYou have to play against your past self.\n\n\nMove both the players and let O win." << endl;
        cout << "Win the game as O or face the consequences." << endl;
        sample_board();
        check();
        if (tic_win == 20)
        {
            cout << "Congratulations, on passing the first challenge. Now you may proceed." << endl;
            getch();
            system("cls");
            cout << "LEVEL 2\n\n\n\n";
            cout << "You stand in front of water fountain...\nAs you approach to drink water, you realize that you stepped on something that cracked." << endl;
            cout << "A SNAKE EGG!!!" << endl;
            cout << "An infant snake crawls to your lap. The fountain starts speaking- That snake wasn't ready to see the world. Feed it 10 grapes of life or bear the curse!" << endl;
            getch();
            Setup();
            while (!gameOver && sn_score != 10)
            {
                Draw();
                Input();
                Logic();
                Sleep(10);
            }
            cout << "\n\nPress any key to continue..." << endl;
            getch();
            if (sn_score < 9)
            {
                cout << "\nThe baby snake died, but his soul wants you to replay.\n\nPress any key to continue...";
                getch();
                goto loop;
            }
            else
            {
                cout << "\nThe baby snake is now Energized." << endl;
                Sleep(1000);
                cout << "\n\nSuddenly you notice that a giant snake is coming towards you. Do you retreat?\n\n"
                     << endl;
                cout << "Make a choice(y/n):  ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    cout << "\n\nThe snake chased you out of the forest and you fell off a cliff. RIP!" << endl;
                }
                else
                {
                    cout << "\n\nThe snake spoke- You saved my child, the egg was lost and I didn't know how to find it.\n"
                         << endl;
                    cout << "You will need a Spaceship to continue on your quest.\n\n"
                         << endl;
                    cout << "Survive upto 20 points in the upcoming challenge..." << endl;
                    getch();
                    setCursor(0, 0);
                    srand((unsigned)time(NULL));
                    do
                    {
                        system("cls");
                        gotoxy(10, 5);
                        cout << "---------------------------";
                        gotoxy(10, 6);
                        cout << "|      SPACE SHOOTER      |";
                        gotoxy(10, 7);
                        cout << "---------------------------";
                        gotoxy(10, 9);
                        cout << "1. Start game";
                        gotoxy(10, 11);
                        cout << "2. Instructions";
                        gotoxy(10, 13);
                        cout << "3. Quit";
                        gotoxy(10, 15);
                        cout << "Select option: ";
                        char op = getch();
                        if (op == '1')
                            play();
                        else if (op == '2')
                            instructions();
                        else if (op == '3')
                        {
                            getch();
                            cout << "You lost again!\n\nPress any key to continue..." << endl;
                            goto loop;
                        }
                        else
                            cout << "Enter a valid choice!";
                    } while (1);
                }
            }
        }
        else
        {
            goto loop;
        }
        cout << "\nYou excelled at all the challenges but unfortunately made the wrong choice.\n\nBETTER LUCK NEXT TIME!!" << endl;
    }
};
class path2 : public ttt, public information, public snake, public spaceship
{
public:
    int winacc = 0;
    void start2()
    {
        cout << "Hello " << information::Name << ".\nYou stand at the pool of snake. Feed a snake 10 times for good luck." << endl;
        getch();
        Setup();
        while (!gameOver && sn_score < 10)
        {
            Draw();
            Input();
            Logic();
            Sleep(10);
        }
        if (sn_score >= 10)
        {
            cout << "\nCongratulations you have been rewarded a spaceship" << endl;
            cout << "\nDestroy 20 spaceships to impress the inter-galactic warlord." << endl;
            getch();
            setCursor(0, 0);
            srand((unsigned)time(NULL));
            do
            {
                system("cls");
                gotoxy(10, 5);
                cout << "---------------------------";
                gotoxy(10, 6);
                cout << "|      SPACE SHOOTER      |";
                gotoxy(10, 7);
                cout << "---------------------------";
                gotoxy(10, 9);
                cout << "1. Start game";
                gotoxy(10, 11);
                cout << "2. Instructions";
                gotoxy(10, 13);
                cout << "3. Quit";
                gotoxy(10, 15);
                cout << "Select option: ";
                char op = getch();
                if (op == '1')
                    play();
                else if (op == '2')
                    instructions();
                else if (op == '3')
                    goto forward;
                else
                    cout << "Enter a valid choice!";
            } while (1);
        forward:
            if (sp_score > 19)
            {
                cout << "\nCongratulations, you have reached the final challenge." << endl;
                cout << "\nFor the final challenge try to win with yourself..." << endl;
                getch();
                system("cls");
                sample_board();
                check();
                if (tic_win == 20)
                    goto proceed;
                else
                    cout << "You were on the right path but failed at the last stage." << endl;
            }
            else
            {
                system("cls");
                cout << "You lost the challenge\n\n\t\tGAME OVER!!!" << endl;
                getch();
                exit(0);
            }
        }
        else
        {
            system("cls");
            cout << "You lost the challenge\n\n\t\tGAME OVER!!!" << endl;
            getch();
            exit(0);
        }
    proceed:
        cout << "Wait" << endl;
        getch();
        cout << "\n\n\n\nYOU WIN!!!!!!" << endl;
        cout << "Congratulations " << information::Name << "!" << endl;
        cout << "You won a jackpot of 1 million, enter your Account number to recieve the amount: " << endl;
        cin >> winacc;
        cout << "RBI suggests not to give such information to anyone, don't you watch TV!" << endl;
    }
};
class path3
{
public:
    int x;
    void start3()
    {
        cout << "\n\nCongratulations " << information::Name << "!" << endl;
        cout << "You won a jackpot of 1 million, enter your Account number to recieve the amount: " << endl;
        cin >> x;
        cout << "\n\nRBI suggests not to give such information to anyone, don't you watch TV!" << endl;
        getch();
    }
};
int main()
{
    int gate;
    system("cls");
    string name;
    cout << "\n\nWELCOME   TO  THE   WORLD   OF ADVENTURES\n\n"
         << endl;
    cout << "Enter your name: ";
    cin >> name;
    information::Name = name;
    cout << "\n\nGreeting " << information::Name << "!"
         << " You stand at the entrance of a world of woods. \n You were betrayed by your friend, and now you lost all the savings of your life." << endl;
    Sleep(500);
    cout << "\n\nYou come acros an online game which promises to reward you a huge amount of money..." << endl;
    cout << "Choose a door:\n\n"
         << endl;
    cout << "_____________\t\t_____________\t\t_____________" << endl;
    cout << "|           |\t\t|           |\t\t|           |" << endl;
    cout << "|    [1]    |\t\t|    [2]    |\t\t|    [3]    |" << endl;
    cout << "|           |\t\t|           |\t\t|           |" << endl;
    cout << "|           |\t\t|           |\t\t|           |" << endl;
    cout << "|         O |\t\t|         O |\t\t|         O |" << endl;
    cout << "|           |\t\t|           |\t\t|           |" << endl;
    cout << "|           |\t\t|           |\t\t|           |" << endl;
    cout << "|           |\t\t|           |\t\t|           |" << endl;
    cout << "|-----------|\t\t|-----------|\t\t|-----------|" << endl;
    Sleep(800);
    cout << "\n\nTo guide you through the correct path a tree shows the following symbol, solve the puzzle to proceed:\n"
         << endl;
    cout << "  |  |  |  |       \t+--+--+--+       \t |     |       " << endl;
    cout << "  |  |  |  |       \t|  |  |  |       \t-+-----+-      " << endl;
    cout << "--+--+--+--+-    =4\t+-----+--+    =10\t |     |    = ?" << endl;
    cout << "  |  |  |  |       \t|  |  |  |       \t |     |       " << endl;
    cout << "  |  |  |  |       \t+--+-----+       \t |     |       " << endl;
    Sleep(800);
pathselection:
    cout << "\n\n Choose a path warrior:  ";
    cin >> gate;
    switch (gate)
    {
    case (1):
    {
        cout << "\n\nWelcome to path 1, may the force be with you." << endl;
        path1 p1;
        Sleep(800);
        p1.start1();
        break;
    }
    case (2):
    {
        cout << "Welcome to path 2, May you overcome all the obstacles." << endl;
        path2 p2;
        Sleep(80);
        p2.start2();
        break;
    }
    case (3):
    {
        cout << "Welcome to path 3, many have perished here. May your destiny be different." << endl;
        path3 p3;
        Sleep(150);
        p3.start3();
        break;
    }
    default:
    {
        cout << "No other options, select between 1,2 and 3" << endl;
        goto pathselection;
        break;
    }
    }
}