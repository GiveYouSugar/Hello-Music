
#include<stdio.h>
#include"play.h"
#include<Windows.h>
#include <io.h>
int musiclength = 0;//音乐长度
extern char zhuanji[100];
extern IMAGE fengmian;

//返回含歌曲信息的链表头
struct music* producelist()//查找歌曲并生成一个列表
{
	long Handle;//声明long类型来做句柄（相当于ID）
	struct _finddata_t FileInfo;//创建一个文件查找的结构体
	char num[100];//编号
	char musicname[100] = "open  G:/mp3/";//歌曲总名字
	int i = 1;//临时变量

	music* head = (music*)malloc(sizeof(music));
	music* flag = head;

	Handle = _findfirst("G:/mp3/*.mp3", &FileInfo);//设置句柄在第一个文件
	strcpy(flag->name, FileInfo.name);//存第一个文件名进去
	head->num = 1;


	while (_findnext(Handle, &FileInfo) == 0)//用findnext来查找下一个，当等于0时即代表查找到了文件
	{
		flag->next = (music*)malloc(sizeof(music));
		flag = flag->next;
		strcpy(flag->name, FileInfo.name);
		i++;
		flag->num = i;
	}


	flag->next = NULL;
	flag = head;
	_findclose(Handle);//关闭查找


	//把文件名都存进了列表里

	while (flag != NULL)
	{
		printf("%d. %s\n",flag->num, flag->name);//打印歌曲列表
		flag = flag->next;
	}
	return head;
}

char* playmusicbynumber(int t,struct music*head)//通过输入数字来决定歌曲，返回数字所对应的歌曲名
{
	music* flag = head;
	//用循环来匹配输入的数字是否在列表里，然后返回歌曲的名字
	while (flag!=NULL)
	{
		if (flag->num == t)
		{
			return flag->name;//返回歌曲的名字
			break;
		}
		
		flag = flag->next;
		
	}
}

char* nextmusic(struct music* head,char name[100])//切换下一首，返回切换歌曲后的名字
{
	int a=0;//获取当前播放歌曲的编号
	char temp[100];
	music* flag = head;
	int t = 0;
	//用循环来判断当前的歌曲位置
	while (flag != NULL)
	{
		if (strcmp(name, flag->name)==0)
		{
			a = flag->num;//当前歌曲编号
		}
		t = flag->num;//获取总歌曲长度
		flag = flag->next;
	}
	closemusic(name);
	if (a==t)
	{
	play_and_pause(playmusicbynumber(1, head));
		return playmusicbynumber(1,head); //如果是最后一首歌点下一首就切到第一首
	}
	else
	{
		play_and_pause(playmusicbynumber(a+1, head));
		return playmusicbynumber(a + 1, head);
	}
}


char* lastmusic(struct music* head, char name[100])//切换上一首，返回切换歌曲后的名字
{
	int a;//获取当前播放歌曲的编号
	char temp[100];
	music* flag = head;
	int t = 0;
	//用循环来判断当前的歌曲位置
	while (flag != NULL)
	{
		if (strcmp(name, flag->name) == 0)
		{
			a = flag->num;
		}
		t = flag->num;
		flag = flag->next;
	}
	closemusic(name);
	if (a == 1)
	{
		play_and_pause(playmusicbynumber(t, head));
		return playmusicbynumber(t, head); //如果是第一一首歌点下一首就切到最后首
	}
	else
	{
		play_and_pause(playmusicbynumber(a-1, head));
		return playmusicbynumber(a -1, head);
	}
}

void drawpicture() {
	//专辑封面

	getzhuanjiname();//获取专辑名字
	
		transparentimage(NULL, 222, 100, &fengmian);
}