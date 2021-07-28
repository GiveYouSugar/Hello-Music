#include <graphics.h>		// ͼ�ο�
#include<easyx.h>
#include <conio.h>
#include<stdio.h>
#include "play.h"
#include <ctime>
#include<Windows.h>
#include<stdlib.h>
#include<mmsystem.h>//������ý���ļ��ӿ�
#pragma comment(lib,"WINMM.LIB")//���ؾ�̬��
IMAGE fengmian;
extern music* head;
extern int musiclength;//���ֳ���
int progress_length = 90;//����������
char zhuanji[100];
char currentname[100]="0";//ȫ�ֱ�������ǰ�ĸ�����
int status = 0;//��������״̬


//����MOUSEHIT�ľ���
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)

//ʹpngͼƬ͸��
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// �ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	// ʹ�� Windows GDI ����ʵ�ְ�͸��λͼ
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}



void windows(int n) {


	HWND hwnd=initgraph(640, 480, EW_SHOWCONSOLE);//��������


	//���ñ���ɫ
	setbkcolor(WHITE);
	cleardevice();
	
	change();

	

	//���ñ���ͼƬ
	IMAGE image;
	loadimage(&image, "./picture/background.png");
	putimage(0, 0, &image);


	//��ͣ��ť
	IMAGE pause;
	IMAGE play2;
	loadimage(&play2, "./picture/play2.png", 36, 36);
	loadimage(&pause, "./picture/play.png",36,36);
	transparentimage(NULL, 302, 400, &pause);
	

	//�����ư�ť
	IMAGE comment;
	loadimage(&comment, "./picture/comment.png", 27, 27);
	transparentimage(NULL, 480, 405, &comment);
	
	//���ذ�ť
	IMAGE back;
	loadimage(&back, "./picture/back.png",30,30);
	transparentimage(NULL, 15, 12, &back);
	
	//��һ��ͼ��
	IMAGE next;
	loadimage(&next, "./picture/next.png", 36, 36);
	IMAGE next2;
	loadimage(&next2, "./picture/next2.png", 36, 36);
	transparentimage(NULL, 380, 400, &next);

	//��һ��ͼ��
	IMAGE last;
	loadimage(&last, "./picture/last.png", 36, 36);
	IMAGE last2;
	loadimage(&last2, "./picture/last2.png", 36, 36);
	transparentimage(NULL, 222, 400, &last);

	//ѭ��ͼ��
	IMAGE circle;
	loadimage(&circle, "./picture/circle.png", 36, 36);
	IMAGE circle2;
	loadimage(&circle2, "./picture/circle2.png", 36, 36);
	transparentimage(NULL, 130, 400, &circle);
	


	setbkmode(TRANSPARENT);//�����������ʱ����Ϊ͸��

	//������
	fillroundrect(90, 355, 550, 350, 10, 10);

	play_and_pause(playmusicbynumber(n, head));//Ĭ�ϲ���
	
	status = 1;
	int width = 620/2 - textwidth(zhuanji)/2;
	int height = 100/2 - textheight(zhuanji)/2;
	drawtext(30, width, height, zhuanji);

	
	
	
	
	printf("%d", musiclength);
	int t = 0;
	t = musiclength / 100 / 460;
	long int t1 = 0;
	//�����Ϣ
	while (1)//Ҫ�ø�ѭ�������ϼ������¼�
	{
		
			if (progress_length < 550&&t1%200000000==0&&status==1)
		{
			setfillcolor(0xAAAAAA);
			
			fillroundrect(90, 355, progress_length, 350, 10, 10);
			progress_length = progress_length + t;
			
			
		}
			t1 = t1 + 1;
		
			if (MouseHit())
		 {
			
			
				MOUSEMSG msg = GetMouseMsg();



			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 302 && msg.x <= 338 && msg.y <= 436 && msg.y >= 400)//���Ű�ť
				{

					transparentimage(NULL, 302, 400, &play2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 302, 400, &pause);
					
					play_and_pause(currentname);

				}//������ż�



				if (msg.x >= 380 && msg.x <= 416 && msg.y <= 436 && msg.y >= 400)//��һ��
				{
					transparentimage(NULL, 380, 400, &next2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 380, 400, &next);
					fundmantual();//���ý���

					nextmusic(head, currentname);

						//ˢ�½�����
					setfillcolor(WHITE);
					fillroundrect(90, 355, 550, 350, 10, 10);
					progress_length = 90;//����������
					int width = 620 / 2 - textwidth(zhuanji) / 2;
					int height = 100 / 2 - textheight(zhuanji) / 2;
					drawtext(30, width, height, zhuanji);
				}//�����һ��
				


				if (msg.x >= 222 && msg.x <= 258 && msg.y <= 436 && msg.y >= 400)//��һ��
				{
					transparentimage(NULL, 222, 400, &last2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 222, 400, &last);
					fundmantual();
					lastmusic(head, currentname);
					//������
					setfillcolor(WHITE);
					fillroundrect(90, 355, 550, 350, 10, 10);
					progress_length = 90;//����������


					int width = 620 / 2 - textwidth(zhuanji) / 2;
					int height = 100 / 2 - textheight(zhuanji) / 2;
					drawtext(30, width, height, zhuanji);

				}//�����һ��


				if (msg.x >= 130 && msg.x <= 166 && msg.y <= 436 && msg.y >= 400)//��һ��
				{
					transparentimage(NULL, 130, 400, &circle2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 130, 400, &circle);
				
					repeatmusic(currentname);
					setfillcolor(WHITE);
					fillroundrect(90, 355, 550, 350, 10, 10);
					progress_length = 90;//����������
					int width = 600 / 2 - textwidth(zhuanji) / 2;
					int height = 100 / 2 - textheight(zhuanji) / 2;
					drawtext(30, width, height, zhuanji);
				
				}//���ѭ��



				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//����
				{
					closemusic(currentname);
					closegraph();
					menu();
					
				}//�������

				if (msg.x >= 480 && msg.x <= 507 && msg.y <= 432 && msg.y >= 405)//��һ��
				{
					WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://music.163.com/#/song?id=1388961676", 1); //��������������


				}//��������




				
				printf("����(%d,%d)\n", msg.x, msg.y);
				break;
			case WM_RBUTTONDOWN:
				outtextxy(400, 400, "����Ҽ�����");
				printf("����(%d,%d)\n", msg.x, msg.y);
				break;
			}



		}
		



		
	}




	getchar();
	//�رմ���
	closegraph();

}

void change() //ʵ���ޱ߿򴰿�
{
	HWND hnd = GetHWnd();//��ȡ���ھ��
/*
long style = GetWindowLong(hnd, GWL_STYLE);
	style &= ~WS_CAPTION;
	SetWindowLong(hnd, GWL_STYLE, style);
*/	
	SetWindowText(hnd, "Hello Music");
	
}

void show_progress() {
	int t = 0;
	t = musiclength / 100 / 460;
	if (progress_length < 550)
	{
		setfillcolor(0xAAAAAA);
		Sleep(1000);//��ʱ0.1��
		fillroundrect(90, 355, progress_length, 350, 10, 10);
		progress_length = progress_length + t;
	}
}

void drawtext(int size, int x, int y,char text[100]) {
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);//�����������ʱ����Ϊ͸��
	
	settextstyle(size, 0, "΢���ź�");
	outtextxy(x, y, text);
}

 char* attainlength(int time) {
	 int fen = 0;
	 int miao = 0;
	 miao =(int) time / 1000;
	 fen =(int) miao / 60;
	 miao =(int) miao - fen * 60;
	 char f[100];//��
	 char m[100];//��
	 char tatol[100];//�ܵ�
	 itoa(miao, m,10);
	 itoa(fen, f, 10);
	 strcpy(tatol, f);
	 strcat(tatol, " : ");
	 if (miao < 10)
	 {
		 strcat(tatol, "0");
	 }
	 strcat(tatol, m);
	 return tatol;
}

 void fundmantual() {
	 //���ñ���ɫ
	 setbkcolor(WHITE);
	 cleardevice();




	 //���ñ���ͼƬ
	 IMAGE image;
	 loadimage(&image, "./picture/background.png");
	 putimage(0, 0, &image);

	 


	 //��ͣ��ť
	 IMAGE pause;
	 loadimage(&pause, "./picture/play.png", 36, 36);
	 transparentimage(NULL, 302, 400, &pause);

	 //��һ��ͼ��
	 IMAGE next;
	 loadimage(&next, "./picture/next.png", 36, 36);
	 transparentimage(NULL, 380, 400, &next);

	 //��һ��ͼ��
	 IMAGE last;
	 loadimage(&last, "./picture/last.png", 36, 36);
	 transparentimage(NULL, 222, 400, &last);


	 IMAGE fengmian;
	 loadimage(&fengmian, "./cards/BREATHE.png", 200, 200);
	 transparentimage(NULL, 222, 100, &fengmian);

	 drawpicture();

	 //���ذ�ť
	 IMAGE back;
	 loadimage(&back, "./picture/back.png", 30, 30);
	 transparentimage(NULL, 15, 12, &back);


	 //�����ư�ť
	 IMAGE comment;
	 loadimage(&comment, "./picture/comment.png", 27, 27);
	 transparentimage(NULL, 480, 405, &comment);


	 //ѭ��ͼ��
	 IMAGE circle;
	 loadimage(&circle, "./picture/circle.png", 36, 36);
	 transparentimage(NULL, 130, 400, &circle);


	 setbkmode(TRANSPARENT);//�����������ʱ����Ϊ͸��

	 //������
	 fillroundrect(90, 355, 550, 350, 10, 10);
 }



 void getzhuanjiname() {
	 
	
	 int lenth = strlen(currentname);//���鳤��

	 for (int i = 0; i <= lenth; i++) {
		 if (currentname[i] == '.') {
			 lenth = i;
			 break;
		 }
	 }
	 memset(zhuanji,0,strlen(zhuanji));//ˢ��ר������
	 strncpy(zhuanji, currentname, lenth);
	 char str1[100];
	 sprintf(str1, "./cards/%s.png", zhuanji);
	 loadimage(&fengmian, str1, 200, 200);//����ͼƬ

 }
 