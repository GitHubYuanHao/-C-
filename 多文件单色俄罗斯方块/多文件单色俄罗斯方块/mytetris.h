#ifndef TETRIS
#define TETRIS

#define FrameX  16    //��Ϸ�������Ͻǵ�X������
#define FrameY  4  //��Ϸ�������Ͻǵ�Y������
#define height  20 //��Ϸ���ڵĸ߶�
#define width   10//��Ϸ���ڵĿ��
#define StartX  1+width/2//����˹�������ĳ���λ�ú����� 
#define StartY  2//����˹�������ĳ���λ��������

extern int Level;
extern int Score;
extern int Line;
extern int a[height + 2][width + 2];//����˹������������

void GameOver();
void Initialization();
void MakeTetris();
void PrintTetris();
void CleanOld();
void DrawNew();
void Transform();
void Judge_MoveAndTansform();
void JustForDebugging();
void PrintNextTetris();
void CleanLine();
void AutoDown();
void KeyControl();

#endif