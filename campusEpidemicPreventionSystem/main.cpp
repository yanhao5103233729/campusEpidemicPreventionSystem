//引入必要的库
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<wchar.h>
#include<locale.h>

//定义必要的常量
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

//定义储存学生信息的结构体
struct NormalStudent
{
	char ID[IDNUMBER];//ID
	char name[NAMECHARACTER];//姓名
	int tel;//电话
	char email[EMAILCHARACTER];//邮箱
	char depart[DEPARTCHARACTER];//院系
	char clas[CLASCHARACTER];//班级
	char location[LOCATIONCHARACTER];//通讯地址
	char content[CONTENTCHARACTER];//简介

	int healthyear;//健康填报年份
	int healthmonth;//健康填报月份
	int healthday;//健康填报日期
	float temp1;//体温(早)
	float temp2;//体温(中)
	float temp3;//体温(晚)
	char coughjudge[JUDGE];//是否咳嗽
	char feverjudge[JUDGE];//是否发烧

	int checkround;//检测次数序号
	int checkyear;//核酸检测年份
	int checkmonth;//核酸检测报月份
	int checkday;//核酸检测日期
	char checklocation[CHECKLOCATIONCHARACTER];//检测地点
	char checkjudge[CHECKJUDGE];//检测结果

	int vaccineround;//接种次数序号
	int vaccineyear;//疫苗接种年份
	int vaccinemonth;//疫苗接种月份
	int vaccineday;//疫苗接种日期
	char vaccinelocation[VACCINELOCATIONCHARACTER];//检测地点
	char vaccinetype[VACCINETYPECHARACTER];//检测结果

	int offround;//离校次数序号
	char offreason[OFFREASONCHARACTER];//离校原因
	int offyear;//出校年份
	int offmonth;//出校月份
	int offday;//出校日期
	int backyear;//返校年份
	int backmonth;//返校月份
	int backday;//返校日期
	char startingpoint[STARTINGPOINTCHARACTER];//行程轨迹起点
	char destination[DESTINATIONCHARACTER];//行程轨迹终点
	char supervision[SUPERVISIONCHARACTER];//审核状态
	char about[ABOUTCHARACTER];//审核意见
}normalstudent[STUDENTNUMBER];

char ProtectStr[PROTECTSTRINGLENGTH];//缓冲区字符串
int StudentCheckData[STUDENTNUMBER][2]={0};//用于统计核酸检测次数分布的表格

#include"UI.h"
#include"login.h"
#include"function.h"
#include"dataprocessing.h"

int main(){
	char password[PASSWORDDIGIT]="";
	short int tab=1;
	char operation;
	FILE *fp,*fph,*fpc,*fpv,*fpo,*fpl=fopen("password.txt","r");//fp指向数据文件，fpl指向密码文件
	setlocale(LC_CTYPE,"chs");

	//登陆模块
	if(login(password,fpl)==0)
	{
		return 0;
	}

	//初始化结构体数组
	Empty(normalstudent);

	//加载文件
	fp=fopen("data.txt","a+");
	ReadData(normalstudent,fp);

	//菜单显示
	while(1)
	{
		system("cls");
		ShowTab(&tab);
		printf("提示：菜单中每一项功能前面的字符是它的代号,\"T\"或\"t\"用于切换菜单的不同栏目.\n");
		printf("请输入操作对应的编号:");
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
					printf("\n你输入的指令不在菜单的范围之内，请重新输入！\n");
					printf("按下回车键以重新选择操作.");
					fflush(stdin);
					getchar();
					break;
				}
		
		}
		SaveData(normalstudent,fp);
	}
}