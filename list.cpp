#include <graphics.h>		// ͼ�ο�
#include<easyx.h>
#include <conio.h>
#include<stdio.h>
#include "play.h"
#include <ctime>
#include<Windows.h>
#include<stdlib.h>
extern music* head;
void like();
void always();



void listmenu() {
	HWND hwnd = initgraph(640, 480, EW_SHOWCONSOLE);//��������
	listfunmdmantual();



	IMAGE a1;
	loadimage(&a1, "./picture/listxuanze.png");
	IMAGE a2;
	loadimage(&a2, "./picture/listxuanze.png");
	//���ذ�ť
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);



	int logostatus = 0;//�������Ƿ��Ƶ�����
	while (1)//Ҫ�ø�ѭ�������ϼ������¼�
	{



		if (MouseHit())
		{


			MOUSEMSG msg = GetMouseMsg();
			if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50 && logostatus == 0)//���Ű�ť
			{
				transparentimage(NULL, 336, 50, &a1);

				logostatus = 1;
			}//��һ��



			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130 && logostatus == 0)//���Ű�ť
			{

				transparentimage(NULL, 336, 130, &a2);

				logostatus = 1;
			}//�ڶ���


			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210 && logostatus == 0)//���Ű�ť
			{

				transparentimage(NULL, 336, 210, &a1);
				logostatus = 1;
			}//������

			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 331 && msg.y >= 290 && logostatus == 0)//���Ű�ť
			{
				transparentimage(NULL, 336, 290, &a1);
				logostatus = 1;
			}//���ĸ�


			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 411 && msg.y >= 370 && logostatus == 0)//���Ű�ť
			{
				transparentimage(NULL, 336, 370, &a1);
				logostatus = 1;
			}//�����
			else {
				listfunmdmantual();
				logostatus = 0;
			}






			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				
				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//��һ��
				{
					closegraph();
					menu();
				}//�������
				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50 )//���Ű�ť
				{
					closegraph();
					windows(1);
					
				}//��һ��



				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130 )//���Ű�ť
				{

					closegraph();
					windows(2);
				}//�ڶ���


				 if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210 )//���Ű�ť
				{

					 closegraph();
					 windows(3);
				}//������

				 if (msg.x >= 336 && msg.x <= 550 && msg.y <= 331 && msg.y >= 290 )//���Ű�ť
				{
					 closegraph();
					 windows(4);
				}//���ĸ�


				 if (msg.x >= 336 && msg.x <= 550 && msg.y <= 411 && msg.y >= 370 )//���Ű�ť
				{
					 closegraph();
					 windows(5);
				}//�����

				 if (msg.x >= 37 && msg.x <= 233 && msg.y <= 363 && msg.y >= 327)//���Ű�ť
				 {
					 closegraph();
					 like();
				 }//�ҵ��ղ�
				 if (msg.x >= 37 && msg.x <= 233 && msg.y <= 429&& msg.y >= 393)//���Ű�ť
				 {
					 closegraph();
					 always();
				 }//�����




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


void listfunmdmantual() {

	//���ñ���ͼƬ
	IMAGE image;
	loadimage(&image, "./picture/listground.png");
	putimage(0, 0, &image);
	
	//���ذ�ť
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	int t = 60;
	for (int i = 1; i < 6; i++)
	{
		drawtext(30, 356, t, playmusicbynumber(i, head));
		t = t + 80;
	}


	
}

void always() {

	initgraph(640, 480, 1);
	setbkmode(TRANSPARENT);
	//���ñ���ͼƬ
	IMAGE image;
	loadimage(&image, "./picture/always.png");
	putimage(0, 0, &image);

	//���ذ�ť
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	int t = 60;
	for (int i = 1; i < 5; i++)
	{
		drawtext(30, 356, t, playmusicbynumber(i+4, head));
		t = t + 80;
	}

	while (1)//Ҫ�ø�ѭ�������ϼ������¼�
	{


		if (MouseHit())
		{


			MOUSEMSG msg = GetMouseMsg();



			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//����
				{
					closegraph();
					menu();

				}//�������
				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50)//���Ű�ť
				{
					closegraph();
					windows(5);

				}//��һ��



				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130)//���Ű�ť
				{

					closegraph();
					windows(6);
				}//�ڶ���


				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210)//���Ű�ť
				{

					closegraph();
					windows(7);
				}//������

				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 331 && msg.y >= 290)//���Ű�ť
				{
					closegraph();
					windows(8);
				}//���ĸ�


			}
		}
	}

	getchar();
}
	


























void like() {

	initgraph(640, 480, 1);
	setbkmode(TRANSPARENT);
	//���ñ���ͼƬ
	IMAGE image;
	loadimage(&image, "./picture/love.png");
	putimage(0, 0, &image);

	//���ذ�ť
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);


	
		drawtext(30, 356, 60, playmusicbynumber(3, head));
		drawtext(30, 356, 140, playmusicbynumber(4, head));
		drawtext(30, 356, 220, playmusicbynumber(7, head));
		

		while (1)//Ҫ�ø�ѭ�������ϼ������¼�
		{


			if (MouseHit())
			{


				MOUSEMSG msg = GetMouseMsg();



				switch (msg.uMsg)
				{
				case WM_LBUTTONDOWN:
					if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//����
					{
						closegraph();
						menu();

					}//�������
					if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50)//���Ű�ť
					{
						closegraph();
						windows(3);

					}//��һ��



					if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130)//���Ű�ť
					{

						closegraph();
						windows(4);
					}//�ڶ���


					if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210)//���Ű�ť
					{

						closegraph();
						windows(7);
					}//������

			


				}
			}
		}

		getchar();

}