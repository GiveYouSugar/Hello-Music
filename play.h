void play_and_pause(char name[100]);
void pausemusic(char name[100]);

void change();
void lianjie();
#include <graphics.h>		// EasyX_20190219(beta)
#include <conio.h>
// 引用该库才能使用 TransparentBlt 函数
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
void repeatmusic(char name[100]);//循环播放




void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
void show_progress();//显示进度条
void windows(int n);

void resumemusic(char name[100]);
void drawtext(int size, int x, int y, char text[100]);//打印微软雅黑字体

char* attainlength(int time);//获得歌曲长度
void fundmantual();//获取基础界面

void listfunmdmantual();//列表的基础界面
void menu();


void getzhuanjiname();
void copyright();//版权封面
void drawpicture();//绘制专辑