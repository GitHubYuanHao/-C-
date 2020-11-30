#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <Mmsystem.h>
using namespace std;
#pragma comment(lib,"winmm.lib")
#define FrameX  16    //��Ϸ�������Ͻǵ�X������
#define FrameY  4  //��Ϸ�������Ͻǵ�Y������
#define height  20 //��Ϸ���ڵĸ߶�
#define width   10//��Ϸ���ڵĿ��
#define StartX  1+width/2//����˹�������ĳ���λ�ú����� 
#define StartY  2//����˹�������ĳ���λ��������

//����˹������������ 
//��*********��*********��**************����*******����***����
//������***������***������***��������*****����***����*****����
int tetris_data[7][4][5][5] = {
    {
        { { 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0 }, { 0, 1, 1, 1, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 0 }, { 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 0, 0, 0 } }
    },
    {
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 1, 1, 1, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } }
    },
    {
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0 }, { 0, 1, 1, 1, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 0 }, { 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } }
    },
    {
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 } }
    },
    {
        { { 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 } },
    },
    {
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0 } },
    },
    {
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } },
        { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } }
    }
};

class Tetris_Data
{
    friend class BackGround;
    friend class Env;
    friend class Logic;
    friend void Welcom(class Tetris_Data &data);
    friend void Welcom(class Tetris_Data &data);
    friend void GamePlay(class Tetris_Data &data);
public:
    Tetris_Data()
        :kind_current(0), state_current(0), kind_next(0), state_next(0)
        , left(1), right(1), down(1), trans(1), X(StartX), Y(StartY)
        , time1(0), time2(0), Line(0), Level(1), Score(0), Music(1)
    {
        int i = 0, j = 0;
        for (i = 0; i < height + 2; i++)
            for (j = 0; j < width + 2; j++)
                a[height + 2][width + 2] = 0;
    }
  
protected:
    //���Բ���
    int kind_current = 0;//��ǰ��������
    int state_current = 0;//��ǰ����״̬
    int kind_next = 0;//��һ��������
    int state_next = 0;//��һ����״̬
    int left = 1;//1Ϊ�����ƣ�0Ϊ�������� 
    int right = 1;//1Ϊ�����ƣ�0Ϊ��������
    int down = 1;//1Ϊ�����ƣ�0Ϊ��������
    int trans = 1;//1Ϊ����ת��0Ϊ������ת 
    int X = StartX;//���ķ��������
    int Y = StartY;//���ķ���������
    //��������
    long time1 = 0;
    long time2 = 0;
    int Line = 0;//���������� 
    int Level = 1;//�ȼ�
    int Score = 0;//����
    int Music = 1;
    int a[height + 2][width + 2];//����˹������������
};

class Tetris_Method :public BackGround, public Env, public Logic
{};

class BackGround
{
    friend class Env;
    friend class Logic;
public:
    virtual void DrwaGameframe(class Tetris_Data &data);/*��ӡ����˹����߿�*/
    virtual void FacePlate();/*��Ϸ��ʼ����*/
    virtual void GameOver(class Tetris_Data &data);/*��Ϸ��������*/
    virtual void Explation(class Tetris_Data &data);/*��Ϸ�������ܽ���*/
    virtual void Regulation(class Tetris_Data &data);/*��Ϸ������ܽ���*/
};

class Env
{
    friend class BackGround;
    friend class Logic;
public:
    virtual void GotoXY(int x, int y);/*ȷ����Ļ���λ��*/
    virtual void HideCursor();/*������Ļ���*/
    virtual void KeyControl(class Tetris_Data &data);/*���������ж�*/
    virtual void PlayMusic();/*���ִ򿪲����ź���*/
    virtual void RestartMusic();/*�������²��ź���*/
    virtual void PauseMusic();/*������ͣ���ź���*/
};

class Logic
{
    friend class BackGround;
    friend class Env;
public:
    virtual void MakeTetris(class Tetris_Data &data);/*���ɶ���˹����*/
    virtual void PrintTetris(class Tetris_Data &data);/*��ӡ������˹����*/
    virtual void CleanOld(class Tetris_Data &data);/*����ɵĶ���˹����*/
    virtual void DrawNew(class Tetris_Data &data);/*��ӡ�µĶ���˹����*/
    virtual void Transform(class Tetris_Data &data);/*��ת����˹����*/
    virtual void Judge_MoveAndTansform(class Tetris_Data &data);/*�ж϶���˹�����Ƿ���ƶ��ͱ���*/
    virtual void PrintNextTetris(class Tetris_Data &data);/*��ӡ��һ������˹����*/
    virtual void CleanLine(class Tetris_Data &data);/*�������*/
    virtual void AutoDown(class Tetris_Data &data);/*�Զ����亯��*/
};

/*****************************************����BackGround*****************************************/
/****************************************
* ��ӡ����˹����߿�
****************************************/
void BackGround::DrwaGameframe(class Tetris_Data &data)
{
    int i = 0;
    GotoXY(FrameX + width - 5, FrameY - 2);
    cout << "�� �� ˹ �� ��";
    for (i = 1; i <= width; i++)
    {
        GotoXY(FrameX + 2 * i, FrameY);//��ӡ�Ϻ��
        cout << "��";
        GotoXY(FrameX + 2 * i, FrameY + height + 1);//��ӡ�º��
        cout << "��";
        data.a[height + 1][i] = 1;
    }
    for (i = 0; i <= height + 1; i++)
    {
        GotoXY(FrameX, FrameY + i);//��ӡ������
        cout << "��";
        GotoXY(FrameX + 2 * width + 2, FrameY + i);//��ӡ������
        cout << "��";
        data.a[i][0] = 1;
        data.a[i][width + 1] = 1;
    }
    GotoXY(FrameX + 2 * width + 8, FrameY - 1);
    cout << "Level:" << data.Level;
    GotoXY(FrameX + 2 * width + 8, FrameY + 1);
    cout << "����:" << data.Score;
    GotoXY(FrameX + 2 * width + 8, FrameY + 3);
    cout << "��ȥ������:%d", data.Line;
}
/****************************************
* ��Ϸ��ʼ����
****************************************/
void BackGround::FacePlate()
{
    cout << "\n\n\n";
    cout << "                           ��  ��  ˹  ��  ��             \n";
    cout << "\n\n";
    cout << "                  ��                         ��           \n";
    cout << "                  ����   ����       ����     ��         ��\n";
    cout << "                  ��       ����     ����     ��     ������\n";
    cout << "                                             ��           \n";
    cout << "\n\n";
    cout << "                         1.��ʼ��Ϸ   2.����˵��          \n";
    cout << "\n\n";
    cout << "                         3.��Ϸ����   4.�˳���Ϸ          \n";
    cout << "\n\n";
    cout << "                           ��ѡ��[1 2 3 4]:";
}
/****************************************
* ��Ϸ��������
****************************************/
void BackGround::GameOver(class Tetris_Data &data)
{
    int n;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n";
    cout << "          ������      ��       ��    ��   ��������        ����    ��      �� ��������   ������  \n";
    cout << "        ��           ����     �� ���� ��  ��            ��    ��   ��    ��  ��         ��   �� \n";
    cout << "        ��   ����   ��  ��   ��   ��   �� ������       ��      ��   ��  ��   ������     ������  \n";
    cout << "        ��     ��  ��������  ��   ��   �� ��            ��    ��     ����    ��         ��   �� \n";
    cout << "          ������  ��      �� ��   ��   �� ��������        ����        ��     ��������   ��    ��\n";
    cout << "\n\n\n\n\n";
    cout << "                                       1:����һ��          2:�˳���Ϸ                             ";
    cout << "\n\n";
    cout << "                                                 ѡ��[1/2]:";
    scanf("%d", &n);
    switch (n)
    {
    case 1:GamePlay(data); break;
    case 2:exit(0); break;
    }
}
/****************************************
* ��Ϸ�������ܽ���
****************************************/
void BackGround::Explation(class Tetris_Data &data)
{
    system("cls");
    cout << "\n\n\n";
    cout << "                                    ����˵��                \n\n\n";
    cout << "                ************************************************\n";
    cout << "                *   tip1: ��ҿ���ͨ�� �� ����������ƶ�����   *\n";
    cout << "                *                                              *\n";
    cout << "                *   tip2: ͨ�� ��ʹ������ת                    *\n";
    cout << "                *                                              *\n";
    cout << "                *   tip3: ͨ�� �����ٷ�������                  *\n";
    cout << "                *                                              *\n";
    cout << "                *   tip4: ���ո����ͣ��Ϸ���ٰ��ո������     *\n";
    cout << "                *                                              *\n";
    cout << "                *   tip5: ��ESC�˳���Ϸ����tab����ͣ/��������  *\n";
    cout << "                ************************************************\n";
    getch();//�����������������
    system("cls");
    Welcom(data);
}
/****************************************
* ��Ϸ������ܽ���
****************************************/
void BackGround::Regulation(class Tetris_Data &data)
{
    system("cls");
    GotoXY(0, 3);
    cout << "                                         ����˵��                     \n\n\n";
    cout << "                **********************************************************\n";
    cout << "                *   tip1: ��ͬ��״��С�������Ļ�Ϸ����£����ͨ������   *\n";
    cout << "                *         �����λ�úͷ���ʹ��������Ļ�ײ�ƴ��������   *\n";
    cout << "                *         һ������                                     *\n";
    cout << "                *                                                        *\n";
    cout << "                *   tip2: ÿ����һ�У���������100                        *\n";
    cout << "                *                                                        *\n";
    cout << "                *   tip3: ÿ�ۼ�1000�֣�������һ���ȼ�                   *\n";
    cout << "                *                                                        *\n";
    cout << "                *   tip4: �����ȼ���ʹ���������ٶȼӿ죬��Ϸ�ѶȼӴ�     *\n";
    cout << "                **********************************************************\n";
    getch();//�����������������
    system("cls");
    Welcom(data);
}



/*****************************************����Env*****************************************/
/****************************************
* ȷ����Ļ���λ��
****************************************/
void Env::GotoXY(int x, int y)
{
    COORD pos;
    pos.X = x;//������
    pos.Y = y;//������
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/****************************************
* ������Ļ���
****************************************/
void Env::HideCursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
    CursorInfo.bVisible = 0; //���ؿ���̨���
    SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
}
/****************************************
* ���������ж�
****************************************/
void Env::KeyControl(class Tetris_Data &data)
{
    int i = 0, j = 0, ch = 0;
    if (_kbhit())
    {
        ch = getch();
        Judge_MoveAndTansform(data);
        switch (ch)
        {
        case 72:if (data.trans){ CleanOld(data); Transform(data); DrawNew(data); }break;//����
        case 75:if (data.left){ CleanOld(data); data.X--; DrawNew(data); }break;//����
        case 77:if (data.right){ CleanOld(data); data.X++; DrawNew(data); }break;//->����
        case 80:if (data.down){ CleanOld(data); data.Y++; DrawNew(data); }break;//����
        case 32:getch(); break;//�ո�� ��ͣ��Ϸ
        case 9: data.Music = -data.Music;
            if (data.Music > 0)RestartMusic();
            else RestartMusic(); break;//tap�� ��ͣ����
        case 27:system("cls"); exit(0); break;//ESC�� �˳� 
        default:break;
        }
    }
}
/****************************************
* ���ִ򿪲����ź���
****************************************/
void Env::PlayMusic()
{
    mciSendString(TEXT("open D:\\Music\\˦�и�.mp3 alias Song1"), NULL, 0, NULL);
    mciSendString(TEXT("play Song1 repeat"), NULL, 0, NULL);
}
/****************************************
* �������²��ź���
****************************************/
void Env::RestartMusic()
{
    mciSendString(TEXT("resume Song1"), NULL, 0, NULL);
}
/****************************************
* ������ͣ���ź���
****************************************/
void Env::PauseMusic()
{
    mciSendString(TEXT("pause Song1"), NULL, 0, NULL);
}
/*****************************************����Logic*****************************************/
/****************************************
* ���ɶ���˹����
****************************************/
void Logic::MakeTetris(class Tetris_Data &data)
{
    srand(time(NULL));
    data.kind_current = data.kind_next;
    data.state_current = data.state_next;
    data.kind_next = rand() % 7;
    data.state_next = rand() % 4;
}
/****************************************
* ��ӡ������˹����
****************************************/
void Logic::PrintTetris(class Tetris_Data &data)
{
    int i = 0, j = 0;
    for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
        data.a[data.Y - 2 + i][data.X - 2 + j] += tetris_data[data.kind_current][data.state_current][i][j];
    for (i = 1; i <= height; i++)
    {
        GotoXY(FrameX + 2, FrameY + i);
        for (j = 1; j <= width; j++)
        if (data.a[i][j])cout << "��";
        else cout << "  ";
    }
}
/****************************************
* ����ɵĶ���˹����
****************************************/
void Logic::CleanOld(class Tetris_Data &data)
{
    int i = 0, j = 0;
    for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
    if (tetris_data[data.kind_current][data.state_current][i][j])
    {
        data.a[data.Y - 2 + i][data.X - 2 + j] = 0;
        GotoXY(FrameX + 2 * data.X - 4 + 2 * j, FrameY + data.Y - 2 + i);
        cout << "  ";
    }
}
/****************************************
* ��ӡ�µĶ���˹����
****************************************/
void Logic::DrawNew(class Tetris_Data &data)
{
    int i = 0, j = 0;
    for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
    if (tetris_data[data.kind_current][data.state_current][i][j])
    {
        data.a[data.Y + i - 2][data.X + j - 2] = tetris_data[data.kind_current][data.state_current][i][j];
        GotoXY(FrameX + 2 * data.X - 4 + 2 * j, FrameY + data.Y - 2 + i);
        cout << "��";
    }
}
/****************************************
* ��ת����˹����
****************************************/
void Logic::Transform(class Tetris_Data &data)
{
    if (data.state_current != 3)data.state_current++;
    else data.state_current = 0;
}
/****************************************
* �ж϶���˹�����Ƿ���ƶ��ͱ���
****************************************/
void Logic::Judge_MoveAndTansform(class Tetris_Data &data)
{
    int t;
    switch (data.kind_current)
    {
    case 0:
    case 1:
    case 2:t = 4 * data.kind_current + data.state_current + 1; break;
    case 3:
    case 4:
    case 5:t = 2 * data.kind_current + data.state_current % 2 + 7; break;
    case 6:t = 19; break;
    }
    switch (t)
    {
    case 1:
        if (data.a[data.Y - 1][data.X - 2] == 0 && data.a[data.Y][data.X - 2] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X] == 0 && data.a[data.Y][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X] == 0 && data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y + 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 2:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 2] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X] == 0 && data.a[data.Y][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y][data.X - 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 3:
        if (data.a[data.Y][data.X - 2] == 0 && data.a[data.Y + 1][data.X] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 2][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X] == 0 && data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 4:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 2] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X - 1] == 0 && data.a[data.Y + 2][data.X] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 5:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 2] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y + 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 6:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y][data.X - 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 7:
        if (data.a[data.Y][data.X - 2] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 2][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 8:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 2] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 2][data.X] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 9:
        if (data.a[data.Y][data.X - 2] == 0 && data.a[data.Y - 1][data.X] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 2] == 0 && data.a[data.Y][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 10:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X] == 0 && data.a[data.Y + 2][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 11:
        if (data.a[data.Y][data.X - 2] == 0 && data.a[data.Y + 1][data.X - 2] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y - 1][data.X] == 0 && data.a[data.Y + 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 12:
        if (data.a[data.Y - 1][data.X - 2] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 2][data.X] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 13:
        if (data.a[data.Y][data.X - 2] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y][data.X + 3] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 2] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 2][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 14:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 2][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0 && data.a[data.Y + 2][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 3][data.X] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y][data.X - 1] == 0 && data.a[data.Y][data.X + 1] == 0 && data.a[data.Y][data.X + 2] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 15:
        if (data.a[data.Y - 1][data.X - 2] == 0 && data.a[data.Y][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y + 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 16:
        if (data.a[data.Y - 1][data.X] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 2] == 0 && data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y - 1][data.X] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 17:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 2] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 2] == 0 && data.a[data.Y][data.X + 1] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0 && data.a[data.Y][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y][data.X + 1] == 0 && data.a[data.Y + 1][data.X + 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 18:
        if (data.a[data.Y - 1][data.X - 1] == 0 && data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 1][data.X] == 0 && data.a[data.Y + 2][data.X + 1] == 0)data.down = 1; else data.down = 0;
        if (data.a[data.Y - 1][data.X + 1] == 0 && data.a[data.Y][data.X - 1] == 0)data.trans = 1; else data.trans = 0;
        break;
    case 19:
        if (data.a[data.Y][data.X - 1] == 0 && data.a[data.Y + 1][data.X - 1] == 0)data.left = 1; else data.left = 0;
        if (data.a[data.Y][data.X + 2] == 0 && data.a[data.Y + 1][data.X + 2] == 0)data.right = 1; else data.right = 0;
        if (data.a[data.Y + 2][data.X] == 0 && data.a[data.Y + 2][data.X + 1] == 0)data.down = 1; else data.down = 0;
        data.trans = 0;
        break;
    default:break;
    }
}


/****************************************
* ��ӡ��һ������˹����
****************************************/
void Logic::PrintNextTetris(class Tetris_Data &data)
{
    int i = 0, j = 0;
    GotoXY(FrameX + 2 * width + 8, FrameY + 5);
    cout << "��һ������:%2d" << data.kind_next;
    for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
    {
        GotoXY(FrameX + 2 * width + 2 * j + 8, FrameY + 6 + i);
        if (tetris_data[data.kind_next][data.state_next][i][j])printf("��");
        else printf("  ");
    }
}
/****************************************
* �������
****************************************/
void Logic::CleanLine(class Tetris_Data &data)
{
    int i = height, j = 1, k = 0, sum = 0;
    for (i = height; i > 0; i--)
    {
        sum = 0;
        for (j = 1; j <= width; j++)sum += data.a[i][j];
        if (sum == width)
        {
            data.Line++;
            for (k = i; k > 1; k--)
            for (j = 1; j <= width; j++)data.a[k][j] = data.a[k - 1][j];
            i++;
        }
    }
    data.Level = 1 + data.Line / 10;
    data.Score = data.Line * 100;
    GotoXY(FrameX + 2 * width + 8, FrameY - 1);
    cout << "Level:%d", data.Level;
    GotoXY(FrameX + 2 * width + 8, FrameY + 1);
    cout << "����:%d", data.Score;
    GotoXY(FrameX + 2 * width + 8, FrameY + 3);
    cout << "��ȥ������:%d", data.Line;
}
/****************************************
* �Զ����亯��
****************************************/
void Logic::AutoDown(class Tetris_Data &data)
{
    int i = 0, j = 0;
    data.time2 = clock();
    if (data.time2 - data.time1 > 1000 - 100 * data.Level)
    {
        Judge_MoveAndTansform(data);
        if (data.down)
        {
            CleanOld(data);
            data.Y++;
            DrawNew(data);
            //JustForDebugging();
        }
        if (!data.down)
        {
            CleanLine();
            data.X = StartX;
            data.Y = StartY;
            MakeTetris(data);
            Judge_MoveAndTansform(data);
            if (!data.down)
            {
                PrintTetris(data);
                Sleep(2000);//ͣ������
                GameOver(data);
            }
            PrintTetris(data);
            PrintNextTetris(data);
        }
        //JustForDebugging();
        data.time1 = clock();
    }
}

/*****************************************ȫ�ֺ���*****************************************/
/****************************************
* ��Ϸ��ӭ����
****************************************/
void Welcom(class Tetris_Data &data)
{
    int n = 0;
    class Env::HideCursor(data);
    class Env::FacePlate(data);
    class Env::PlayMusic(data);
    scanf("%d", &n);//����ѡ��
    switch (n)
    {
    case 1:class BackGround::GamePlay(data); break;//��Ϸ��ʼ 
    case 2:class BackGround::Explation(data); break;//����˵������ 
    case 3:class BackGround::Regulation(data); break;//��Ϸ���� 
    case 4:exit(0); break;//�ر���Ϸ 
    }
}


/****************************************
* ��Ϸ������ʼ��
****************************************/
void Welcom(class Tetris_Data &data)
{
    int i = 0, j = 0;
    data.kind_current = rand() % 7;
    data.kind_next = rand() % 7;
    data.state_current = rand() % 4;
    data.state_next = rand() % 4;
    data.left = 1;
    data.right = 1;
    data.down = 1;
    data.trans = 1;
    data.X = StartX;
    data.Y = StartY;
    data.Line = 0;
    data.Level = 1;
    data.Score = 0;
    for (i = 1; i <= height + 1; i++)
    for (j = 1; j <= width + 1; j++)data.a[i][j] = 0;
    for (i = 1; i <= width; i++)data.a[height + 1][i] = 1;
    for (i = 0; i <= height + 1; i++)
    {
        data.a[i][0] = 1;
        data.a[i][width + 1] = 1;
    }
}
/****************************************
* ��Ϸ��ʼ����
****************************************/
void GamePlay(class Tetris_Data &data)
{
    system("cls");
    Initialization(data);
    DrwaGameframe(data);
    MakeTetris(data);
    DrawNew(data);
    PrintNextTetris(data);
    data.time1 = clock();
    while (1)
    {
        KeyControl(data);
        //JustForDebugging();
        AutoDown(data);
    }
}
int main()
{
    Tetris_Data mytetris;
    Tetris_Data *pt = &mytetris;
    BackGround mybackdround;
    Welcom();
    return 0;
}