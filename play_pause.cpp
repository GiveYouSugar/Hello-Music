#include<windows.h>
#include<mmsystem.h>//������ý���ļ��ӿ�
#pragma comment(lib,"WINMM.LIB")//���ؾ�̬��
#include"play.h"
#include <stdio.h>

extern int musiclength;//���ֳ���
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
		mciSendString(t, NULL, 0, NULL);//�������ļ�
		mciSendString("play mysong ", 0, 0, 0);//��������
		status = 1;
	}

	else if (status == 1) {
		mciSendString("pause mysong", 0, 0, 0);//��ͣ����
		status = 2;
	}
	else
	{
		mciSendString("resume mysong", 0, 0, 0);//�ָ���������
		status = 1;
	}

	char sPosition[256];
	long lLength;
	mciSendString("Status mysong length", sPosition, 255, 0); //��ȡ�������ȣ����룩
	lLength = strtol(sPosition, NULL, 10);
	musiclength = lLength;
	char time[100];
	strcpy(time, attainlength(lLength));
	drawtext(20, 566, 340, time);//��ʾ����ʱ��
	memset(currentname, 0, strlen(currentname));//ˢ��ר������
	strcpy(currentname, name);//���õ�ǰ��������

	getzhuanjiname();//��ȡר������
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
	mciSendString(t, NULL, 0, NULL);//ֹͣ����
	mciSendString("close mysong ", 0, 0, 0);//�ر�����
	status = 0;
}
void resumemusic(char name[100]) {
	char t[100] = "resume G:/mp3/";
	strcat(t, name);
	mciSendString(t, NULL, 0, NULL);//����
}
void repeatmusic(char name[100])//ѭ������
{
	closemusic(currentname);
	char t[100] = "open G:/mp3/";
	char temp[100] = " alias mysong";
	strcat(t, name);
	strcat(t, temp);
	mciSendString(t, NULL, 0, NULL);//�������ļ�
	mciSendString("play mysong repeat", 0, 0, 0);//ѭ����������
	status = 1;

	char sPosition[256];
	long lLength;
	mciSendString("Status mysong length", sPosition, 255, 0); //��ȡ�������ȣ����룩
	lLength = strtol(sPosition, NULL, 10);
	musiclength = lLength;
	char time[100];
	strcpy(time, attainlength(lLength));
	drawtext(20, 566, 340, time);//��ʾ����ʱ��
	memset(currentname, 0, strlen(currentname));//ˢ��ר������
	strcpy(currentname, name);//���õ�ǰ��������

	getzhuanjiname();//��ȡר������
	drawtext(30, 260, 40, zhuanji);
	drawpicture();


}


