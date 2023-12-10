//�����Ҫ�Ŀ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<wchar.h>
#include<locale.h>

//�����Ҫ�ĳ���
#define PASSWORDDIGIT 50
#define STUDENTNUMBER 50
#define IDNUMBER 20
#define NAMECHARACTER 10
#define EMAILCHARACTER 30
#define DEPARTCHARACTER 50
#define CLASCHARACTER 50
#define LOCATIONCHARACTER 100
#define CONTENTCHARACTER 200
#define JUDGE 10
#define CHECKLOCATIONCHARACTER 100
#define CHECKJUDGE 10
#define VACCINELOCATIONCHARACTER 100
#define VACCINETYPECHARACTER 20
#define OFFREASONCHARACTER 100
#define STARTINGPOINTCHARACTER 100
#define DESTINATIONCHARACTER 100
#define SUPERVISIONCHARACTER 100
#define ABOUTCHARACTER 100
#define PROTECTSTRINGLENGTH 300

//���崢��ѧ����Ϣ�Ľṹ��
struct NormalStudent
{
	char ID[IDNUMBER];//ID
	char name[NAMECHARACTER];//����
	int tel;//�绰
	char email[EMAILCHARACTER];//����
	char depart[DEPARTCHARACTER];//Ժϵ
	char clas[CLASCHARACTER];//�༶
	char location[LOCATIONCHARACTER];//ͨѶ��ַ
	char content[CONTENTCHARACTER];//���

	int healthyear;//��������
	int healthmonth;//������·�
	int healthday;//���������
	float temp1;//����(��)
	float temp2;//����(��)
	float temp3;//����(��)
	char coughjudge[JUDGE];//�Ƿ����
	char feverjudge[JUDGE];//�Ƿ���

	int checkround;//���������
	int checkyear;//���������
	int checkmonth;//�����ⱨ�·�
	int checkday;//����������
	char checklocation[CHECKLOCATIONCHARACTER];//���ص�
	char checkjudge[CHECKJUDGE];//�����

	int vaccineround;//���ִ������
	int vaccineyear;//����������
	int vaccinemonth;//��������·�
	int vaccineday;//�����������
	char vaccinelocation[VACCINELOCATIONCHARACTER];//���ص�
	char vaccinetype[VACCINETYPECHARACTER];//�����

	int offround;//��У�������
	char offreason[OFFREASONCHARACTER];//��Уԭ��
	int offyear;//��У���
	int offmonth;//��У�·�
	int offday;//��У����
	int backyear;//��У���
	int backmonth;//��У�·�
	int backday;//��У����
	char startingpoint[STARTINGPOINTCHARACTER];//�г̹켣���
	char destination[DESTINATIONCHARACTER];//�г̹켣�յ�
	char supervision[SUPERVISIONCHARACTER];//���״̬
	char about[ABOUTCHARACTER];//������
}normalstudent[STUDENTNUMBER];

char ProtectStr[PROTECTSTRINGLENGTH];//�������ַ���
int StudentCheckData[STUDENTNUMBER][2]={0};//����ͳ�ƺ���������ֲ��ı��

#include"UI.h"
#include"login.h"
#include"function.h"
#include"dataprocessing.h"

int main(){
	char password[PASSWORDDIGIT]="";
	short int tab=1;
	char operation;
	FILE *fp,*fph,*fpc,*fpv,*fpo,*fpl=fopen("password.txt","r");//fpָ�������ļ���fplָ�������ļ�
	setlocale(LC_CTYPE,"chs");

	//��½ģ��
	if(login(password,fpl)==0)
	{
		return 0;
	}

	//��ʼ���ṹ������
	Empty(normalstudent);

	//�����ļ�
	fp=fopen("data.txt","a+");
	ReadData(normalstudent,fp);

	//�˵���ʾ
	while(1)
	{
		system("cls");
		ShowTab(&tab);
		printf("��ʾ���˵���ÿһ���ǰ����ַ������Ĵ���,\"T\"��\"t\"�����л��˵��Ĳ�ͬ��Ŀ.\n");
		printf("�����������Ӧ�ı��:");
		fflush(stdin);
		scanf("%c",&operation);
		fflush(stdin);
		switch(operation)
		{
			case 'T':
			case 't':
				{SwitchTab(&tab);break;}
			case '1':
				{FunctionViewAll(normalstudent);break;}
			case '2':
				{FunctionSearch(normalstudent);break;}
			case '3':
				{FunctionEdit(normalstudent);break;}
			case '4':
				{FunctionDelete(normalstudent);break;}
			case '5':
				{FunctionIDSort(normalstudent);break;}
			case '6':
				{FunctionAdd(normalstudent);break;}
			case 'x':
				{FunctionAddh(normalstudent);break;}
			case 'y':
				{FunctionAddc(normalstudent);break;}
			case 'z':
				{FunctionAddv(normalstudent);break;}
			case 'w':
				{FunctionAddo(normalstudent);break;}
			case '*':
				{FunctionEmpty(normalstudent,fp);break;}
			case '#':
				{FunctionShutDown(fp);break;}
			case 'a':
				{FunctionShowStudentCheckStatics(normalstudent,StudentCheckData);break;}
			case 'b':
				{FunctionShowStudentVaccineStatics(normalstudent,StudentCheckData);break;}
			case 'c':
				{FunctionShowStudentOffStatics(normalstudent,StudentCheckData);break;}
			case 'm':
				{FunctionChangePassword();break;}
			case 'n':
				{FunctionGetOccupiedSpace(fp);break;}
			case 'r':
				{FunctionShowAuthor();break;}
			default:
				{
					printf("\n�������ָ��ڲ˵��ķ�Χ֮�ڣ����������룡\n");
					printf("���»س���������ѡ�����.");
					fflush(stdin);
					getchar();
					break;
				}
		
		}
		SaveData(normalstudent,fp);
	}
}