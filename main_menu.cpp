
#include <graphics.h>		// ͼ�ο�
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

    //����ͼƬ
    IMAGE img1;
    loadimage(&img1, "./picture/mainmenu.png");
    putimage(0, 0, &img1);

    IMAGE choice;
    loadimage(&choice, "./picture/menuchoice.png");
     //��Ҫ���������ʱ 1���ַ���ǰ��L 2����TEXT������_T���� 3��������Ŀ����
    //�����־���
    //1�����ֲ���
  
    while (1) {
        //������
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();


            //��ʾ��ɫ���
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

    //����ͼƬ
    IMAGE im;
    loadimage(&im, "./picture/copyright.png");
    putimage(0, 0, &im);

    
    
    
    //���ذ�ť
    IMAGE back;
    loadimage(&back, "./picture/back.png", 30, 30);
    transparentimage(NULL, 15, 12, &back);


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
                if (msg.x >= 116 && msg.x <= 552 && msg.y >= 338 && msg.y <= 479) {
                    WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://github.com/phill-boop/hello-path", 1); //��������������

                }
            }
        }
    }




}