#ifndef TETRIS
#define TETRIS

#define FrameX  16    //��Ϸ�������Ͻǵ�X������
#define FrameY  4  //��Ϸ�������Ͻǵ�Y������
#define height  20 //��Ϸ���ڵĸ߶�
#define width   20//��Ϸ���ڵĿ��
#define StartX  1+width/2//����˹�������ĳ���λ�ú����� 
#define StartY  2//����˹�������ĳ���λ��������

/*
��ɫ=0     ��ɫ=1      ��ɫ=2      ǳ��ɫ=3
��ɫ=4     ��ɫ=5      ��ɫ=6      ��ɫ=7
��ɫ=8     ����ɫ=9    ����ɫ=10   ��ǳ��ɫ=11
����ɫ=12  ����ɫ=13   ����ɫ=14   ����ɫ=15
*/
#define c1    2 //��         L��                      
#define c2    8 //��         T��                      
#define c3    15//��      ������                     
#define c4    4 //��         Z��                       
#define c5    1 //��      ������ 

extern int Line;//���������� 
extern int Level;//�ȼ�
extern int Score;//����
extern int a[height + 2][width + 2];//����˹������������
extern int Music;

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