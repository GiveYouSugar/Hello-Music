
#include<stdio.h>
#include"play.h"
#include<Windows.h>
#include <io.h>
int musiclength = 0;//���ֳ���
extern char zhuanji[100];
extern IMAGE fengmian;

//���غ�������Ϣ������ͷ
struct music* producelist()//���Ҹ���������һ���б�
{
	long Handle;//����long��������������൱��ID��
	struct _finddata_t FileInfo;//����һ���ļ����ҵĽṹ��
	char num[100];//���
	char musicname[100] = "open  G:/mp3/";//����������
	int i = 1;//��ʱ����

	music* head = (music*)malloc(sizeof(music));
	music* flag = head;

	Handle = _findfirst("G:/mp3/*.mp3", &FileInfo);//���þ���ڵ�һ���ļ�
	strcpy(flag->name, FileInfo.name);//���һ���ļ�����ȥ
	head->num = 1;


	while (_findnext(Handle, &FileInfo) == 0)//��findnext��������һ����������0ʱ��������ҵ����ļ�
	{
		flag->next = (music*)malloc(sizeof(music));
		flag = flag->next;
		strcpy(flag->name, FileInfo.name);
		i++;
		flag->num = i;
	}


	flag->next = NULL;
	flag = head;
	_findclose(Handle);//�رղ���


	//���ļ�����������б���

	while (flag != NULL)
	{
		printf("%d. %s\n",flag->num, flag->name);//��ӡ�����б�
		flag = flag->next;
	}
	return head;
}

char* playmusicbynumber(int t,struct music*head)//ͨ����������������������������������Ӧ�ĸ�����
{
	music* flag = head;
	//��ѭ����ƥ������������Ƿ����б��Ȼ�󷵻ظ���������
	while (flag!=NULL)
	{
		if (flag->num == t)
		{
			return flag->name;//���ظ���������
			break;
		}
		
		flag = flag->next;
		
	}
}

char* nextmusic(struct music* head,char name[100])//�л���һ�ף������л������������
{
	int a=0;//��ȡ��ǰ���Ÿ����ı��
	char temp[100];
	music* flag = head;
	int t = 0;
	//��ѭ�����жϵ�ǰ�ĸ���λ��
	while (flag != NULL)
	{
		if (strcmp(name, flag->name)==0)
		{
			a = flag->num;//��ǰ�������
		}
		t = flag->num;//��ȡ�ܸ�������
		flag = flag->next;
	}
	closemusic(name);
	if (a==t)
	{
	play_and_pause(playmusicbynumber(1, head));
		return playmusicbynumber(1,head); //��������һ�׸����һ�׾��е���һ��
	}
	else
	{
		play_and_pause(playmusicbynumber(a+1, head));
		return playmusicbynumber(a + 1, head);
	}
}


char* lastmusic(struct music* head, char name[100])//�л���һ�ף������л������������
{
	int a;//��ȡ��ǰ���Ÿ����ı��
	char temp[100];
	music* flag = head;
	int t = 0;
	//��ѭ�����жϵ�ǰ�ĸ���λ��
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
		return playmusicbynumber(t, head); //����ǵ�һһ�׸����һ�׾��е������
	}
	else
	{
		play_and_pause(playmusicbynumber(a-1, head));
		return playmusicbynumber(a -1, head);
	}
}

void drawpicture() {
	//ר������

	getzhuanjiname();//��ȡר������
	
		transparentimage(NULL, 222, 100, &fengmian);
}