
#include<stdio.h>
#include"play.h"
#include<Windows.h>
#include <io.h>
#include <conio.h>

extern char zhuanji[100];
music* head = producelist();//获取包含歌曲信息的链表头
int main()
{
	
	menu();
	//listmenu();
	//windows();
	
	
	//WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://music.163.com/#/song?id=1388961676", 1); //跳到网易云热评
	
	/*
	mciSendString("play G:/mp3/喜欢你.mp3 ", 0, 0, 0);//播放音乐
	Sleep(5000);
	mciSendString("pause G:/mp3/喜欢你.mp3", 0, 0, 0);//播放音乐
	Sleep(5000);
	mciSendString("resume G:/mp3/喜欢你.mp3", 0, 0, 0);//播放音乐

	*/
	


	





/*
char choice[100];
	int a;
	music* head = producelist();//获取包含歌曲信息的链表头
	while (1)
	{
		printf("请输入你想听的歌曲序号\n");
		scanf("%d", &a);
		char name[100];//当前歌曲名字
		strcpy(name, playmusicbynumber(a, head));//通过序号获得名字
		play_and_pause(name);
		printf("%s\n",zhuanji);
	}


*/
	
	
	system("pause");
	
}