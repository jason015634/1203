#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "InputSystem.h" // 기능 별로 모듈화를 한다는 개념에 대해 생각해 봅시다!


namespace global
{
    namespace time
    {
        ULONGLONG previousTime;
        ULONGLONG currentTime;
        ULONGLONG deltaTime;

        int updateCount;
        int fixedUpdateCount;

        void InitTime()
        {
            currentTime = previousTime = GetTickCount64();
        }

        void UpdateTime()
        {
            previousTime = currentTime;
            currentTime = GetTickCount64();

            deltaTime = currentTime - previousTime;
        }

        ULONGLONG GetDeltaTime()
        {
            return deltaTime;
        }
    };

    COORD prePlayerPos; // 기존 플레이어 위치
    COORD curPlayerPos; // 현재 플레이어 위치
    int x, y;
    SMALL_RECT consoleScreenSize;

    const int playerMoveSpeed = 1000;

};

enum {
    black,
    blue,
    green,
    cyan,
    red,
    purple,
    brown,
    lightgray,
    darkgray,
    lightblue,
    lightgreen,
    lightcyan,
    lightred,
    lightpurple,
    yellow,
    white
};



void setColor(int forground, int background)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}

void GotoXY(int x, int y)
{
    COORD Cur = { x, y };
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

bool Quiz1()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("수도퀴즈!\n");
    GotoXY(30, 10);
    printf("캐나다의 수도는?\n");
    GotoXY(30, 12);
    printf("1. 보고타   2. 오타와   3. 벤쿠버   4. 부다페스트   5. 토론토");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '2')
        {
            GotoXY(30, 14);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '3' || userAnswer == '4' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 14);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 14);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }
        
    }
}

bool Quiz2()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("북한에서는 이것을 얼음 보숭이라고 부르는데\n");
    GotoXY(30, 11);
    printf("이것은 무엇 일까요?");
    GotoXY(30, 13);
    printf("1. 북금곰   2. 시베리안 허스키   3. 아이스 하키   4. 아이스크림   5. 고드름");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '4')
        {
            GotoXY(30, 15);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '3' || userAnswer == '2' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 15);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 15);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz3()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("줄임말퀴즈!\n");
    GotoXY(30, 12);
    printf("좋댓구알은 무엇의 줄임말일까요? 답 입력 후 엔터를 눌러주세요. (띄어쓰기X, 쉼표X)");
    char str1[40]; 
    GotoXY(30, 14);
    std::cin >> str1;
    GotoXY(30, 14);
    std::cout << str1 << std::endl;
    Sleep(1000);
    GotoXY(30, 14);
    printf("                             ");

    for (int i = 1; i <= 3; i++)
    {
        char str2[40] = "좋아요댓글구독알림설정";
        if (strcmp(str1, str2) == 0)
        {
            GotoXY(30, 16);
            printf("$1 획득하셨습니다!");
            Sleep(2000);
            return true;
            break;
        }
        else if (strcmp(str1, str2) == 1 || strcmp(str1, str2) == -1)
        {
            if (i == 3)
            {
                GotoXY(30, 16);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 16);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                GotoXY(30, 14);
                std::cin >> str1;
                GotoXY(30, 14);
                std::cout << str1 << std::endl;
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz4()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("북한에서는 이것을 얼음 보숭이라고 부르는데\n");
    GotoXY(30, 11);
    printf("이것은 무엇 일까요?");
    GotoXY(30, 13);
    printf("1. 북금곰   2. 시베리안 허스키   3. 아이스 하키   4. 아이스크림   5. 고드름");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '4')
        {
            GotoXY(30, 15);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '3' || userAnswer == '2' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 15);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 15);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

void UpdatePlayerPosition()
{

    global::prePlayerPos = global::curPlayerPos; // 현재 위치 경신 전에 일단, 저장. 구조체를 쓰면 이런게 편한겁니다. :)

    if (global::input::IsUpKeyOn())
    {
        global::input::Set(global::input::UP_KEY_INDEX, false);

        global::curPlayerPos.Y = --global::y;
    }

    if (global::input::IsDownKeyOn())
    {
        global::input::Set(global::input::DOWN_KEY_INDEX, false);

        global::curPlayerPos.Y = ++global::y;

    }

    if (global::input::IsLeftKeyOn())
    {
        global::input::Set(global::input::LEFT_KEY_INDEX, false);

        global::curPlayerPos.X = --global::x;

    }

    if (global::input::IsRightKeyOn())
    {
        global::input::Set(global::input::RIGHT_KEY_INDEX, false);

        global::curPlayerPos.X = ++global::x;

    }
}

void UpdatePlayer()
{
    // 키 입력과 화면 출력과 게임 로직 갱신을 분리해서 생각해 봅시다.
    static ULONGLONG elapsedTime;

    elapsedTime += global::time::GetDeltaTime();

    while (elapsedTime >= global::playerMoveSpeed)
    {
        UpdatePlayerPosition();

        elapsedTime -= global::playerMoveSpeed;
    }
}

void StartGame()
{
    // 깜박이는 커서를 좀 진정 시키자.
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
    cursorInfo.dwSize = 1; // 커서의 크기를 결정 (1~100 사이만 가능)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // 콘솔창 크기를 가져 오고
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    global::consoleScreenSize.Left = csbi.srWindow.Left;
    global::consoleScreenSize.Right = csbi.srWindow.Right;
    global::consoleScreenSize.Bottom = csbi.srWindow.Bottom;
    global::consoleScreenSize.Top = csbi.srWindow.Top;

    // 플레이어 시작 위치 설정
    global::prePlayerPos.X = 1;
    global::prePlayerPos.Y = 2;
    global::curPlayerPos.X = 1;
    global::curPlayerPos.Y = 2;


}

void EndGame()
{

}

void ProcessInput()
{
    global::input::UpdateInput();
}

void PrintCountsPerSecond();
void PrintPlayerPostion();

void Lobby()
{
    printf("\n\n\n\n");
    printf("       $$$$$$      $$      $$   $$   $$    $$          $$$$$$    $$$$$$   $$$$$$      $$      $$    $$\n");
    printf("       $$   $$    $$$$     $$$  $$   $$  $$            $$   $$   $$  $$   $$         $$$$     $$  $$  \n");
    printf("       $$$$$     $$  $$    $$ $ $$   $$$$              $$$$$     $$$$     $$$$$     $$  $$    $$$$    \n");
    printf("       $$   $$  $$$$$$$$   $$  $$$   $$  $$            $$   $$   $$  $$   $$       $$$$$$$$   $$  $$  \n");
    printf("       $$$$$$  $$      $$  $$   $$   $$    $$          $$$$$$    $$   $$  $$$$$$  $$      $$  $$    $$\n");
}

int menuDraw()
{
    int x = 45;
    int y = 12;
    GotoXY(x - 2, y);
    printf("> 탈 출 시 작 :)");
    GotoXY(x - 2, y + 1);
    printf("    포  기 :(   ");

    while (1)
    {
        int n = global::input::keyControl();
        switch (n)
        {
        case global::input::UP_KEY_INDEX:
        {
            if (y > 12)
            {
                GotoXY(x - 2, y);
                printf(" ");
                GotoXY(x - 2, --y);
                printf(">");
            }
            break;
        }
        case global::input::DOWN_KEY_INDEX:
        {
            if (y < 13)
            {
                GotoXY(x - 2, y);
                printf(" ");
                GotoXY(x - 2, ++y);
                printf(">");
            }
            break;
        }

        case global::input::SUBMIT:
        {
            return y - 12;
        }
        }

    }

}

char tempMaze[22][53];

char b_Maze[22][53] = // width=50, height=20
{
    {"111111111111111111111111111111111111111111111111111"},
    {"111111111111111111111111111111110000002110000000111"},
    {"1s0000100000000000000001111111110111111110111110111"},
    {"101110101111110111110101111111110111111110001110111"},
    {"1000100011111101111101011000000001111111111011100?1"},
    {"101110111111110151110101101111111111110000001111111"},
    {"101000000011110001110101101111111111110111111111111"},
    {"101011111011111111100100000000011111110111111111111"},
    {"101011111011111111101111101111011111110111111000021"},
    {"101000111011000001101111101111011100000111111011111"},
    {"101011111011011101101111101111011101020111111011111"},
    {"101011111011011101100111101111011101000111111011111"},
    {"101000111000011101110111101111000001101111111011111"},
    {"101110111011111101110111101111111111101111111011111"},
    {"101110111011111101110011100000011111100000000011111"},
    {"101110111011111141111011111111011121111111111111111"},
    {"101000111011111111111001111111011100111111111111111"},
    {"101011111000000111111101111111011110000011111111111"},
    {"101000031110111111011101111111011111111000001111111"},
    {"101011111110111000011101111111011111111111101111111"},
    {"121000011110000011111100000000000000000000000000021"},
    {"111111111111111111111111111111111111111111111111111"}
};

void drawMap(int* x, int* y)
{
    system("cls");
    DWORD dw;
    int h, w;
    for (h = 0; h < 22;h++)
    {
        for (int w = 0; w < 53; w++)
        {
            char temp = tempMaze[h][w];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7) | 0 << 4);

            if (temp == '0')
                printf("  ");
            else if (temp == '1')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7) << 4);
                WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "  ", 2, &dw, NULL);
            }
            else if (temp == '2' || temp == '3' || temp == '4' || temp == '5')
            {
                setColor(lightred, black);
                printf("▣");
            }
            else if (temp == '?')
            {
                setColor(lightgreen, black);
                printf("Ⅲ");
            }
            else if (temp == 's')
            {
                *x = w;
                *y = h;
                setColor(lightblue, black);
                printf("♀");
            }
        }
        printf("\n");

    }

}
void Update()
{
    global::time::updateCount += 1;

    UpdatePlayer();
    //DrawPlayer(false);
}
void FixedUpdate()
{
    static ULONGLONG elapsedTime;

    elapsedTime += global::time::GetDeltaTime();

    while (elapsedTime >= 20) //0.02초
    {
        global::time::fixedUpdateCount += 1;

        elapsedTime -= 20;
    }
}

void move(int* x, int* y, int _x, int _y, int* vault)
{

    char& mapObject = tempMaze[*y + _y][*x + _x];
    setColor(white, black);
    if (mapObject == '0')
    {
        GotoXY(2 * (*x), *y);
        printf("  ");
        tempMaze[*y][*x] = '0';
        setColor(lightblue, black);
        GotoXY(2 * (*x + _x), *y + _y);
        printf("♀");

        *x += _x;
        *y += _y;
        tempMaze[*y][*x] = 's';
    }
    else if (mapObject == '2')
    {
        
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz1() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '3')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz2() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '4')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz3() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '5')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz4() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    

}

void drawUI(int* x, int* y, int * vault)
{
    setColor(white, black);
    GotoXY(3, 25);
    printf("위치 : %02d, %02d", *x, *y);

    setColor(green, black);
    GotoXY(34, 25);
    printf("Money : $%d", *vault);
}

void gLoop(int mapCode)
{
    int x, y;
    int playing = 1;
    int vault = 0;

    if (mapCode == 0)
    {
        memcpy(tempMaze, b_Maze, sizeof(tempMaze));
    }

    drawMap(&x, &y);

    while (playing)
    {
        drawUI(&x, &y, &vault);

        global::time::UpdateTime();
        ProcessInput();
        FixedUpdate();
        Update();
        switch (global::input::keyControl())
        {
        case global::input::UP_KEY_INDEX:
        {
            move(&x, &y, 0, -1, &vault);
            break;
        }
        case global::input::DOWN_KEY_INDEX:
        {
            move(&x, &y, 0, 1, &vault);
            break;
        }
        case global::input::LEFT_KEY_INDEX:
        {
            move(&x, &y, -1, 0, &vault);
            break;
        }
        case global::input::RIGHT_KEY_INDEX:
        {
            move(&x, &y, 1, 0, &vault);
            break;
        }

        case global::input::SUBMIT:
        {
            playing = 0;
        }
        }
    }

}




void Render(int* x, int* y, int _x, int _y)
{
    //GotoXY(0, 0); // 프레임 카운트 출력 위치
    //PrintCountsPerSecond();

    //GotoXY(50, 0); // 플레이어 위치 정보
    //PrintPlayerPostion();

    // 위치가 달라지면 갱신
    /*if ((global::prePlayerPos.X + 1 == global::curPlayerPos.X))
    {
        GotoXY(*x-1, *y);
        printf(" ");
        GotoXY(*x, *y);
        printf("▲");
    }*/
}

bool IsGameRun()
{
    return true;
}

void PrintPlayerPostion()
{
    printf("Player Position (%d, %d)", global::curPlayerPos.X, global::curPlayerPos.Y);
}

void PrintCountsPerSecond()
{
    static ULONGLONG elapsedTime;

    elapsedTime += global::time::GetDeltaTime();
    if (elapsedTime >= 1000)
    {
        printf("updateCount : %d \t fixedUpdateCount : %d \n",
            global::time::updateCount, global::time::fixedUpdateCount);


        elapsedTime = 0;
        global::time::updateCount = 0;
        global::time::fixedUpdateCount = 0;
    }
}

int main()
{
    global::time::InitTime();

    StartGame();
    bool isDrawMenu = false;

    while (IsGameRun())
    {
        Lobby();

        int menucode = menuDraw();
        if (menucode == 0)			//탈출시작
        {
            gLoop(0);
        }
        else if (menucode == 1)		//포기..
        {
            return 0;
        }
        system("cls");

    }

    EndGame();

    return 0;
}