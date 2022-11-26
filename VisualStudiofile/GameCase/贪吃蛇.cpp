#include <iostream>
#include <windows.h>
#include <list>
#include <conio.h>

void run();
inline void SetPos(const int& i, const short& j) // 设置光标位置
{
    COORD pos = { short(i << 1), j };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct SnackSegment // 贪吃蛇结构
{
    int x, y;
};
std::list<SnackSegment> snack;
int FoodX, FoodY, SnackDirection;
bool Dead;

void MoveSnack(std::list<SnackSegment>& snack) // 移动贪吃蛇
{
    switch (SnackDirection) // 在链表头部插入坐标对
    {
    case 0: // 上移
        snack.insert(begin(snack), { snack.front().x, snack.front().y - 1 });
        break;
    case 1: // 右移
        snack.insert(begin(snack), { snack.front().x + 1, snack.front().y });
        break;
    case 2: // 下移
        snack.insert(begin(snack), { snack.front().x, snack.front().y + 1 });
        break;
    case 3: // 左移
        snack.insert(begin(snack), { snack.front().x - 1, snack.front().y });
        break;
    }
    if (snack.front().x != FoodX || snack.front().y != FoodY) // 没吃到食物，丢弃贪吃蛇尾部
    {
        SetPos(snack.back().x, snack.back().y);
        std::cout << "  ";
        snack.pop_back();
    }
    else // 吃到食物
    {
        bool food_CD = false;
        while (true) // 生成食物坐标
        {
            FoodX = rand() % 40;
            FoodY = rand() % 25;
            for (auto s : snack)
                if (s.x == FoodX && s.y == FoodY) // 判断食物坐标是否在蛇上
                    food_CD = true;
            if (!food_CD)
                break;
            food_CD = false;
        }
        SetPos(FoodX, FoodY); // 显示食物
        std::cout << "●";
    }
    // 判断死亡
    for (auto it = ++snack.begin(); it != snack.end(); ++it)
        if ((*it).x == snack.front().x && (*it).y == snack.front().y)
            Dead = true;
    if (snack.front().x < 0 || snack.front().x > 39 || snack.front().y < 0 || snack.front().y > 24)
        Dead = true;
    // 显示贪吃蛇
    SetPos(snack.front().x, snack.front().y);
    std::cout << (Dead ? "x" : "□");
    SetPos((*++snack.begin()).x, (*++snack.begin()).y);
    std::cout << (Dead ? "x" : "■");
    if (Dead) // 游戏结束
    {
        SetPos(17, 12);
        std::cout << "Game Over!";
        SetPos(13, 13);
        std::cout << "press Spacebar to restart...";
        while (true)
            if (_kbhit() && _getch() == 32) // 按空格重新开始
                break;
        run();
    }
}
void run() // 运行游戏
{
    // 初始化游戏
    system("cls");
    FoodX = 20;
    FoodY = 16;
    SnackDirection = 1;
    Dead = false;
    SetPos(FoodX, FoodY);
    std::cout << "●";
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
                case 72: // 上键
                    if (SnackDirection != 2)
                        SnackDirection = 0;
                    break;
                case 80: // 下键
                    if (SnackDirection != 0)
                        SnackDirection = 2;
                    break;
                case 75: // 左键
                    if (SnackDirection != 1)
                        SnackDirection = 3;
                    break;
                case 77: // 右键
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
    // 设置窗口标题、大小、颜色
    SetConsoleTitle("贪吃蛇");
    system("mode con cols=80 lines=25");
    system("color 80");
    // 隐藏窗口光标
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    run();
}