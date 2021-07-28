#include<windows.h>
#include<mmsystem.h>//包含多媒体文件接口
#pragma comment(lib,"WINMM.LIB")//加载静态库
#include"play.h"
#include <stdio.h>

extern int musiclength;//音乐长度
extern int status;
extern char zhuanji[100];
extern char currentname[100];


 void play_and_pause(char name[100]) {
	char t[100] = "open G:/mp3/";
	char temp[100] = " alias mysong";
	strcat(t, name);
	strcat(t, temp);
	
	if (status==0)
	{
		mciSendString(t, NULL, 0, NULL);//打开音乐文件
		mciSendString("play mysong ", 0, 0, 0);//播放音乐
		status = 1;
	}

	else if (status == 1) {
		mciSendString("pause mysong", 0, 0, 0);//暂停音乐
		status = 2;
	}
	else
	{
		mciSendString("resume mysong", 0, 0, 0);//恢复播放音乐
		status = 1;
	}

	char sPosition[256];
	long lLength;
	mciSendString("Status mysong length", sPosition, 255, 0); //获取歌曲长度（毫秒）
	lLength = strtol(sPosition, NULL, 10);
	musiclength = lLength;
	char time[100];
	strcpy(time, attainlength(lLength));
	drawtext(20, 566, 340, time);//显示播放时间
	memset(currentname, 0, strlen(currentname));//刷新专辑名字
	strcpy(currentname, name);//设置当前歌曲名字

	getzhuanjiname();//获取专辑名字
	drawpicture();
	
	


}

void pausemusic(char name[100]) {
	char tatol[100] ="pause G:/mp3/";
	strcat(tatol, name);
	mciSendString("pause G:/mp3/changes.mp3", 0, 0, 0);//pause
}
void closemusic(char name[100]) {
	char t[100] = "stop G:/mp3/";
	char temp[100] = " alias mysong";
	strcat(t, name);
	strcat(t, temp);
	mciSendString(t, NULL, 0, NULL);//停止播放
	mciSendString("close mysong ", 0, 0, 0);//关闭音乐
	status = 0;
}
void resumemusic(char name[100]) {
	char t[100] = "resume G:/mp3/";
	strcat(t, name);
	mciSendString(t, NULL, 0, NULL);//继续
}
void repeatmusic(char name[100])//循环播放
{
	closemusic(currentname);
	char t[100] = "open G:/mp3/";
	char temp[100] = " alias mysong";
	strcat(t, name);
	strcat(t, temp);
	mciSendString(t, NULL, 0, NULL);//打开音乐文件
	mciSendString("play mysong repeat", 0, 0, 0);//循环播放音乐
	status = 1;

	char sPosition[256];
	long lLength;
	mciSendString("Status mysong length", sPosition, 255, 0); //获取歌曲长度（毫秒）
	lLength = strtol(sPosition, NULL, 10);
	musiclength = lLength;
	char time[100];
	strcpy(time, attainlength(lLength));
	drawtext(20, 566, 340, time);//显示播放时间
	memset(currentname, 0, strlen(currentname));//刷新专辑名字
	strcpy(currentname, name);//设置当前歌曲名字

	getzhuanjiname();//获取专辑名字
	drawtext(30, 260, 40, zhuanji);
	drawpicture();


}


