void play_and_pause(char name[100]);
void pausemusic(char name[100]);

void change();
void lianjie();
#include <graphics.h>		// EasyX_20190219(beta)
#include <conio.h>
// ���øÿ����ʹ�� TransparentBlt ����
#pragma comment( lib, "MSIMG32.LIB")

struct music
{
	int num;
	char name[100];
	struct music* next;
};
char* playmusicbynumber(int t, struct music* head);

char* nextmusic(struct music* head, char name[100]);
char* lastmusic(struct music* head, char name[100]);

void listmenu();
void closemusic(char name[100]);

struct music* producelist();
void repeatmusic(char name[100]);//ѭ������




void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
void show_progress();//��ʾ������
void windows(int n);

void resumemusic(char name[100]);
void drawtext(int size, int x, int y, char text[100]);//��ӡ΢���ź�����

char* attainlength(int time);//��ø�������
void fundmantual();//��ȡ��������

void listfunmdmantual();//�б�Ļ�������
void menu();


void getzhuanjiname();
void copyright();//��Ȩ����
void drawpicture();//����ר��