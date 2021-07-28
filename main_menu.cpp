
#include <graphics.h>		// 图形库
#include<easyx.h>
#include <conio.h>
#include<stdio.h>
#include "play.h"
#include <ctime>
#include<Windows.h>
#include<stdlib.h>



extern music* head;



void menu() {
    int logostatus = 0;
    initgraph(640, 480, 1);
    setbkmode(TRANSPARENT);

    //背景图片
    IMAGE img1;
    loadimage(&img1, "./picture/mainmenu.png");
    putimage(0, 0, &img1);

    IMAGE choice;
    loadimage(&choice, "./picture/menuchoice.png");
     //当要输出中文字时 1、字符串前加L 2、用TEXT（）或_T（） 3、调整项目设置
    //把文字居中
    //1、音乐播放
  
    while (1) {
        //鼠标操作
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();


            //显示灰色块块
            if (msg.x >= 369 && msg.x <=583 && msg.y>=69 && msg.y <=160&&logostatus==0) {
                transparentimage(NULL, 369, 69, &choice);
                logostatus = 1;
                
            }
            else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 195&& msg.y <=264 && logostatus == 0)
            {
                transparentimage(NULL,369, 195, &choice);
                logostatus = 1;
            }
            else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 321 && msg.y <= 390 && logostatus == 0)
            {
                transparentimage(NULL, 369, 321, &choice);
                logostatus = 1;
            }
            else
            {
                putimage(0, 0, &img1);
                logostatus = 0;
            }


                       switch (msg.uMsg)
            {
            case WM_LBUTTONDOWN:

                if (msg.x >= 369 && msg.x <= 583 && msg.y >= 69 && msg.y <= 160 ) {
                    closegraph();
                    windows(1);

                }
                else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 195 && msg.y <= 264 )
                {
                    closegraph();
                    listmenu();
                }
                else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 321 && msg.y <= 390 )
                {
                    closegraph();
                    copyright();
                }
                break;
            default:
                break;
            }
        }
    }

}

void copyright() {
    initgraph(640, 480, 1);
    setbkmode(TRANSPARENT);

    //背景图片
    IMAGE im;
    loadimage(&im, "./picture/copyright.png");
    putimage(0, 0, &im);

    
    
    
    //返回按钮
    IMAGE back;
    loadimage(&back, "./picture/back.png", 30, 30);
    transparentimage(NULL, 15, 12, &back);


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
                if (msg.x >= 116 && msg.x <= 552 && msg.y >= 338 && msg.y <= 479) {
                    WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://github.com/phill-boop/hello-path", 1); //跳到网易云热评

                }
            }
        }
    }




}