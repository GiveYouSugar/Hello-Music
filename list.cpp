#include <graphics.h>		// 图形库
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
	HWND hwnd = initgraph(640, 480, EW_SHOWCONSOLE);//创建窗口
	listfunmdmantual();



	IMAGE a1;
	loadimage(&a1, "./picture/listxuanze.png");
	IMAGE a2;
	loadimage(&a2, "./picture/listxuanze.png");
	//返回按钮
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);



	int logostatus = 0;//监测鼠标是否移到上面
	while (1)//要用个循环来不断监测鼠标事件
	{



		if (MouseHit())
		{


			MOUSEMSG msg = GetMouseMsg();
			if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50 && logostatus == 0)//播放按钮
			{
				transparentimage(NULL, 336, 50, &a1);

				logostatus = 1;
			}//第一个



			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130 && logostatus == 0)//播放按钮
			{

				transparentimage(NULL, 336, 130, &a2);

				logostatus = 1;
			}//第二个


			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210 && logostatus == 0)//播放按钮
			{

				transparentimage(NULL, 336, 210, &a1);
				logostatus = 1;
			}//第三个

			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 331 && msg.y >= 290 && logostatus == 0)//播放按钮
			{
				transparentimage(NULL, 336, 290, &a1);
				logostatus = 1;
			}//第四个


			else if (msg.x >= 336 && msg.x <= 550 && msg.y <= 411 && msg.y >= 370 && logostatus == 0)//播放按钮
			{
				transparentimage(NULL, 336, 370, &a1);
				logostatus = 1;
			}//第五个
			else {
				listfunmdmantual();
				logostatus = 0;
			}






			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				
				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//下一首
				{
					closegraph();
					menu();
				}//点击返回
				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50 )//播放按钮
				{
					closegraph();
					windows(1);
					
				}//第一个



				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130 )//播放按钮
				{

					closegraph();
					windows(2);
				}//第二个


				 if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210 )//播放按钮
				{

					 closegraph();
					 windows(3);
				}//第三个

				 if (msg.x >= 336 && msg.x <= 550 && msg.y <= 331 && msg.y >= 290 )//播放按钮
				{
					 closegraph();
					 windows(4);
				}//第四个


				 if (msg.x >= 336 && msg.x <= 550 && msg.y <= 411 && msg.y >= 370 )//播放按钮
				{
					 closegraph();
					 windows(5);
				}//第五个

				 if (msg.x >= 37 && msg.x <= 233 && msg.y <= 363 && msg.y >= 327)//播放按钮
				 {
					 closegraph();
					 like();
				 }//我的收藏
				 if (msg.x >= 37 && msg.x <= 233 && msg.y <= 429&& msg.y >= 393)//播放按钮
				 {
					 closegraph();
					 always();
				 }//我最常听




				printf("坐标(%d,%d)\n", msg.x, msg.y);
				break;
			case WM_RBUTTONDOWN:
				outtextxy(400, 400, "鼠标右键按下");
				printf("坐标(%d,%d)\n", msg.x, msg.y);
				break;
			}



		}





	}




	getchar();
	//关闭窗口
	closegraph();
}


void listfunmdmantual() {

	//设置背景图片
	IMAGE image;
	loadimage(&image, "./picture/listground.png");
	putimage(0, 0, &image);
	
	//返回按钮
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
	//设置背景图片
	IMAGE image;
	loadimage(&image, "./picture/always.png");
	putimage(0, 0, &image);

	//返回按钮
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	int t = 60;
	for (int i = 1; i < 5; i++)
	{
		drawtext(30, 356, t, playmusicbynumber(i+4, head));
		t = t + 80;
	}

	while (1)//要用个循环来不断监测鼠标事件
	{


		if (MouseHit())
		{


			MOUSEMSG msg = GetMouseMsg();



			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//返回
				{
					closegraph();
					menu();

				}//点击返回
				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50)//播放按钮
				{
					closegraph();
					windows(5);

				}//第一个



				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130)//播放按钮
				{

					closegraph();
					windows(6);
				}//第二个


				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210)//播放按钮
				{

					closegraph();
					windows(7);
				}//第三个

				if (msg.x >= 336 && msg.x <= 550 && msg.y <= 331 && msg.y >= 290)//播放按钮
				{
					closegraph();
					windows(8);
				}//第四个


			}
		}
	}

	getchar();
}
	


























void like() {

	initgraph(640, 480, 1);
	setbkmode(TRANSPARENT);
	//设置背景图片
	IMAGE image;
	loadimage(&image, "./picture/love.png");
	putimage(0, 0, &image);

	//返回按钮
	IMAGE back;
	loadimage(&back, "./picture/back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);


	
		drawtext(30, 356, 60, playmusicbynumber(3, head));
		drawtext(30, 356, 140, playmusicbynumber(4, head));
		drawtext(30, 356, 220, playmusicbynumber(7, head));
		

		while (1)//要用个循环来不断监测鼠标事件
		{


			if (MouseHit())
			{


				MOUSEMSG msg = GetMouseMsg();



				switch (msg.uMsg)
				{
				case WM_LBUTTONDOWN:
					if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//返回
					{
						closegraph();
						menu();

					}//点击返回
					if (msg.x >= 336 && msg.x <= 550 && msg.y <= 91 && msg.y >= 50)//播放按钮
					{
						closegraph();
						windows(3);

					}//第一个



					if (msg.x >= 336 && msg.x <= 550 && msg.y <= 171 && msg.y >= 130)//播放按钮
					{

						closegraph();
						windows(4);
					}//第二个


					if (msg.x >= 336 && msg.x <= 550 && msg.y <= 251 && msg.y >= 210)//播放按钮
					{

						closegraph();
						windows(7);
					}//第三个

			


				}
			}
		}

		getchar();

}