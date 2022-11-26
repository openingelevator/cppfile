#include <iostream>
#include <windows.h>
#include <list>
#include <conio.h>

void run();
inline void SetPos(const int& i, const short& j) // ���ù��λ��
{
    COORD pos = { short(i << 1), j };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct SnackSegment // ̰���߽ṹ
{
    int x, y;
};
std::list<SnackSegment> snack;
int FoodX, FoodY, SnackDirection;
bool Dead;

void MoveSnack(std::list<SnackSegment>& snack) // �ƶ�̰����
{
    switch (SnackDirection) // ������ͷ�����������
    {
    case 0: // ����
        snack.insert(begin(snack), { snack.front().x, snack.front().y - 1 });
        break;
    case 1: // ����
        snack.insert(begin(snack), { snack.front().x + 1, snack.front().y });
        break;
    case 2: // ����
        snack.insert(begin(snack), { snack.front().x, snack.front().y + 1 });
        break;
    case 3: // ����
        snack.insert(begin(snack), { snack.front().x - 1, snack.front().y });
        break;
    }
    if (snack.front().x != FoodX || snack.front().y != FoodY) // û�Ե�ʳ�����̰����β��
    {
        SetPos(snack.back().x, snack.back().y);
        std::cout << "  ";
        snack.pop_back();
    }
    else // �Ե�ʳ��
    {
        bool food_CD = false;
        while (true) // ����ʳ������
        {
            FoodX = rand() % 40;
            FoodY = rand() % 25;
            for (auto s : snack)
                if (s.x == FoodX && s.y == FoodY) // �ж�ʳ�������Ƿ�������
                    food_CD = true;
            if (!food_CD)
                break;
            food_CD = false;
        }
        SetPos(FoodX, FoodY); // ��ʾʳ��
        std::cout << "��";
    }
    // �ж�����
    for (auto it = ++snack.begin(); it != snack.end(); ++it)
        if ((*it).x == snack.front().x && (*it).y == snack.front().y)
            Dead = true;
    if (snack.front().x < 0 || snack.front().x > 39 || snack.front().y < 0 || snack.front().y > 24)
        Dead = true;
    // ��ʾ̰����
    SetPos(snack.front().x, snack.front().y);
    std::cout << (Dead ? "x" : "��");
    SetPos((*++snack.begin()).x, (*++snack.begin()).y);
    std::cout << (Dead ? "x" : "��");
    if (Dead) // ��Ϸ����
    {
        SetPos(17, 12);
        std::cout << "Game Over!";
        SetPos(13, 13);
        std::cout << "press Spacebar to restart...";
        while (true)
            if (_kbhit() && _getch() == 32) // ���ո����¿�ʼ
                break;
        run();
    }
}
void run() // ������Ϸ
{
    // ��ʼ����Ϸ
    system("cls");
    FoodX = 20;
    FoodY = 16;
    SnackDirection = 1;
    Dead = false;
    SetPos(FoodX, FoodY);
    std::cout << "��";
    snack = { {15, 17}, {14, 17}, {13, 17} };

    int t = 0;
    bool move = false;
    while (true)
    {
        Sleep(1);
        if (t++ > 10)
        {
            MoveSnack(snack);
            move = true;
            t = 0;
        }
        if (_kbhit())
        {
            int ch = _getch();
            if (ch == 224 && move)
            {
                switch (_getch())
                {
                case 72: // �ϼ�
                    if (SnackDirection != 2)
                        SnackDirection = 0;
                    break;
                case 80: // �¼�
                    if (SnackDirection != 0)
                        SnackDirection = 2;
                    break;
                case 75: // ���
                    if (SnackDirection != 1)
                        SnackDirection = 3;
                    break;
                case 77: // �Ҽ�
                    if (SnackDirection != 3)
                        SnackDirection = 1;
                    break;
                }
                move = false;
            }
            else if (ch == 122)
                MoveSnack(snack);
            else if (ch == 32)
                while (true)
                    if (_kbhit() && _getch() == 32)
                        break;
        }
    }
}

int main()
{
    // ���ô��ڱ��⡢��С����ɫ
    SetConsoleTitle("̰����");
    system("mode con cols=80 lines=25");
    system("color 80");
    // ���ش��ڹ��
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    run();
}