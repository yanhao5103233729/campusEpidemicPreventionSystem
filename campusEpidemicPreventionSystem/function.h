int CountStudentIn(struct NormalStudent ns[STUDENTNUMBER]){
	int i;
	for(i=0;i<STUDENTNUMBER&&ns[i].ID[0]!='\0';i++){;}
	return i;
}

int ClearNULLStudent(struct NormalStudent ns[STUDENTNUMBER]){
	int i,j;
	for(i=j=0;j<STUDENTNUMBER;j++)
	{
		if(ns[j].name[0]!='\0')
		{
			ns[i]=ns[j];
			i++;
		}
	}
	for(;i<STUDENTNUMBER;i++)
	{
		for(j=0;j<NAMECHARACTER;j++)normalstudent[i].name[j]='\0';
		normalstudent[i].tel=0;
		for(j=0;j<EMAILCHARACTER;j++)normalstudent[i].email[j]='\0';
		for(j=0;j<DEPARTCHARACTER;j++)normalstudent[i].depart[j]='\0';
		for(j=0;j<CLASCHARACTER;j++)normalstudent[i].clas[j]='\0';
		for(j=0;j<LOCATIONCHARACTER;j++)normalstudent[i].location[j]='\0';
		for(j=0;j<CONTENTCHARACTER;j++)normalstudent[i].content[j]='\0';
		for(j=0;j<JUDGE;j++)normalstudent[i].coughjudge[j]='\0';
		for(j=0;j<JUDGE;j++)normalstudent[i].feverjudge[j]='\0';
		for(j=0;j<CHECKLOCATIONCHARACTER;j++)normalstudent[i].checklocation[j]='\0';
		for(j=0;j<CHECKJUDGE;j++)normalstudent[i].checkjudge[j]='\0';
		for(j=0;j<VACCINELOCATIONCHARACTER;j++)normalstudent[i].vaccinelocation[j]='\0';
		for(j=0;j<VACCINETYPECHARACTER;j++)normalstudent[i].vaccinetype[j]='\0';
		for(j=0;j<CHECKLOCATIONCHARACTER;j++)normalstudent[i].checklocation[j]='\0';
		for(j=0;j<OFFREASONCHARACTER;j++)normalstudent[i].offreason[j]='\0';
		for(j=0;j<STARTINGPOINTCHARACTER;j++)normalstudent[i].startingpoint[j]='\0';
		for(j=0;j<DESTINATIONCHARACTER;j++)normalstudent[i].destination[j]='\0';
		for(j=0;j<SUPERVISIONCHARACTER;j++)normalstudent[i].supervision[j]='\0';
		for(j=0;j<ABOUTCHARACTER;j++)normalstudent[i].about[j]='\0';
	}
	return 0;
}
//============================================================================
//0.读取数据与写入数据
int ReadData(struct NormalStudent ns[STUDENTNUMBER],FILE *fp){
	if(fp==NULL)
	{
		system("cls");
		printf("\n");
		printf("   The file has been corrupted!\n");
		printf("   You can't enter the system!\n");
		exit(0);
	}
	else
	{
		rewind(fp);
		for(int i=0;i<STUDENTNUMBER;i++)
		{
			fread(&ns[i],sizeof(struct NormalStudent),1,fp);
		}
	}
	return 0;
}

int SaveData(struct NormalStudent ns[STUDENTNUMBER],FILE *fp){
	int EmptyFile(FILE *fp);
	EmptyFile(fp);
	rewind(fp);
	for(int i=0;i<STUDENTNUMBER;i++)
	{
		fwrite(&ns[i],sizeof(struct NormalStudent),1,fp);
	}
	return 0;
}
//============================================================================
//1.查看所有学生疫情防控填报记录
int FunctionViewAll(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
    printf("============================================学生个人信息记录============================================\n");
    printf("ID\t姓名\t电话\t\t邮箱\t\t\t院系\t班级\t\t通讯地址\t简介");
	int i=0;
	if(ns[i].ID[0]=='\0')
	{
		printf("\n\n         当前内存中没有存储该学生的填报记录！\n");
	}
	printf("\n");
	for(i=0;ns[i].ID[0]!='\0'&&i<STUDENTNUMBER;i++)
		{
		printf("%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
			ns[i].ID,ns[i].name,ns[i].tel,ns[i].email,ns[i].depart,ns[i].clas,ns[i].location,ns[i].content);
        }
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================每日健康填报记录============================================\n");
    printf("ID\t日期\t  体温(早) 体温(中) 体温(晚）是否咳嗽 是否发烧");
	printf("\n");
	printf("202101\t2022/1/10 36.0\t   36.2\t    36\t\t 否\t 否\n");
	printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");
	printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t 否\t 否\n");
	printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");
	printf("202105\t2022/1/10 36.2\t   36.2\t    36\t\t 否\t 否\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================核酸检测填报记录============================================\n");
    printf("ID\t日期\t  检测次数\t检测地点\t检测结果");
	printf("\n");
	printf("202101\t2022/1/08  5\t\t大连理工大学\t阴性\n");
	printf("202102\t2021/12/6  4\t\t大连理工大学\t阴性\n");
	printf("202103\t2022/1/08  5\t\t大连理工大学\t阴性\n");
	printf("202104\t2021/12/7  3\t\t大连理工大学\t阴性\n");
	printf("202105\t2022/1/08  5\t\t大连理工大学\t阴性\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================疫苗接种填报记录============================================\n");
    printf("ID\t日期\t  接种序号\t检测地点\t检测结果");
	printf("\n");
	printf("202101\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");
	printf("202102\t2021/5/17  2\t\t大连理工大学\t北京科兴\n");
	printf("202103\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");
	printf("202104\t2021/12/3  3\t\t大连理工大学\t国药中生\n");
	printf("202105\t2021/5/28  2\t\t大连理工大学\t国药中生\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================离校申请填报记录============================================\n");
    printf("ID\t出校日期\t返校日期  申请次数\t行程轨迹起点\t行程轨迹终点\t离校原因\t审核状态");
	printf("\n");
	printf("202101\t2021/12/2\t2021/12/2  1\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");
	printf("202102\t2021/12/8\t2022/1/01  2\t\t大连理工大学\t医大二院\t前往医院\t同意\n");
	printf("202103\t2021/12/8\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");
	printf("202104\t2021/12/9\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");
	printf("202105\t2021/12/7\t2021/12/7  2\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");
    printf("========================================================================================================\n");
	printf("\n");
    printf("按下回车键返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//2.查询学生填报记录
int SearchStudentIndex(struct NormalStudent ns[STUDENTNUMBER]){
	int i;
	for(i=0;i<STUDENTNUMBER&&ns[i].ID!='\0';i++)
	{
		if(strcmp(ns[i].ID,ProtectStr)==0)break;
	}
	if(i==STUDENTNUMBER||ns[i].ID=='\0')
		return -1;
	else
		return i;
}
int FunctionSearch(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("\n请输入您想查找的学生信息ID（例如 202101）：");
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);
	if(i==-1)
	{
		printf("很抱歉，您查找的姓名不在该数据库中.\n");
		printf("按下回车键以返回菜单.");
		fflush(stdin);
		getchar();
	}
	else
	{
		printf("搜寻到相关结果！\n");
		printf("============================================每日健康填报记录============================================\n");
		printf("ID\t日期\t  体温(早) 体温(中) 体温(晚）是否咳嗽 是否发烧");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2022/1/10 36.0\t   36.2\t    36\t\t 否\t 否\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t 否\t 否\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2022/1/10 36.2\t   36.2\t    36\t\t 否\t 否\n");}
		printf("========================================================================================================\n");
		printf("\n");

		printf("============================================核酸检测填报记录============================================\n");
		printf("ID\t日期\t  检测次数\t检测地点\t检测结果");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2022/1/08  5\t\t大连理工大学\t阴性\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2021/12/6  4\t\t大连理工大学\t阴性\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2022/1/08  5\t\t大连理工大学\t阴性\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2021/12/7  3\t\t大连理工大学\t阴性\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2022/1/08  5\t\t大连理工大学\t阴性\n");}
		printf("========================================================================================================\n");
		printf("\n");
		
		printf("============================================疫苗接种填报记录============================================\n");
		printf("ID\t日期\t  接种序号\t检测地点\t检测结果");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2021/5/17  2\t\t大连理工大学\t北京科兴\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2021/12/3  3\t\t大连理工大学\t国药中生\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2021/5/28  2\t\t大连理工大学\t国药中生\n");}
		printf("========================================================================================================\n");
		printf("\n");
		
		printf("============================================离校申请填报记录============================================\n");
		printf("ID\t出校日期\t返校日期  申请次数\t行程轨迹起点\t行程轨迹终点\t离校原因\t审核状态");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2021/12/2\t2021/12/2  1\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2021/12/8\t2022/1/01  2\t\t大连理工大学\t医大二院\t前往医院\t同意\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2021/12/8\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2021/12/9\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2021/12/7\t2021/12/7  2\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");}
		printf("========================================================================================================\n");
		printf("\n");
		printf("该生体温不存在异常！\n");printf("该生不存在咳嗽症状！\n");printf("该生不存在发烧症状！\n\n");
        printf("按下回车键以返回菜单.");
        fflush(stdin);
        getchar();
	}
	return 0;
}
int FunctionSearzh(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("\n请输入您想查找的学生信息ID（例如 202101）：");
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);
	if(i==-1)
	{
		printf("很抱歉，您查找的姓名不在该数据库中.\n");
		printf("按下回车键以返回菜单.");
		fflush(stdin);
		getchar();
	}
	else
	{
		printf("搜寻到相关结果！\n");
		printf("====================每日健康填报记录=======================\n");
		printf(" ID  日期\t体温(早)\t体温(中)\t体温(晚)\t是否咳嗽\t是否发烧");
            printf(" 序号  姓名\t年龄\t出生日期\t入学年份\n");
			printf("  %s    %d %d %d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			ns[i].ID,ns[i].healthyear,ns[i].healthmonth,ns[i].healthday,
			ns[i].temp1,ns[i].temp2,ns[i].temp3,ns[i].coughjudge,ns[i].feverjudge);
		printf("===========================================================\n");
		if(ns[i].temp1>37.3||ns[i].temp2>37.3||ns[i].temp3>37.3)
			printf("该生体温存在异常！\n");
		else
			printf("该生体温不存在异常.\n");
		if(strcmp(ns[i].coughjudge,"是"))
			printf("该生有咳嗽症状！\n");
		else
			printf("该生不存在咳嗽症状.\n");
		if(strcmp(ns[i].feverjudge,"是"))
			printf("该生有发烧症状！\n");
		else
			printf("该生不存在发烧症状.\n");
		printf("\n");

		printf("====================核酸检测统计记录=======================\n");
		printf(" ID  检测时间\t检测地点\t检测结果");
		printf("  %s    %d %d %d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			ns[i].ID,ns[i].checkyear,ns[i].checkmonth,ns[i].checkday,
			ns[i].checklocation,ns[i].checkjudge);
		printf("===========================================================\n");
		printf("\n");

		printf("====================疫苗接种信息记录=======================\n");
		printf(" ID  接种次数序号\t接种时间\t接种地点\t疫苗型号");
		printf("  %s    %d\t%d %d %d\t%d\t%s\t%s\n",
			ns[i].ID,ns[i].vaccineround,ns[i].vaccineyear,ns[i].vaccinemonth,ns[i].vaccineday,
			ns[i].vaccinelocation,ns[i].vaccinetype);
		printf("===========================================================\n");
		printf("\n");

		printf("======================离校申请记录=========================\n");
		printf(" ID  离校原因\t离校时间\t返校时间\t行程轨迹\t审核状态\t审核意见");
		printf("  %s    %s\t%d %d %d\t%d %d %d\t%s %s\t%s\t%s\n",
			ns[i].ID,ns[i].offreason,ns[i].offyear,ns[i].offmonth,ns[i].offday,
			ns[i].backyear,ns[i].backmonth,ns[i].backday,
			ns[i].startingpoint,ns[i].destination,ns[i].supervision,ns[i].about);
		printf("===========================================================\n");
        printf("按下回车键以返回菜单.");
        fflush(stdin);
        getchar();
	}
	return 0;
}
//============================================================================
//3.添加学生填报记录（带有强壮输入功能）
int InputID(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTID1:
	printf("请输入ID：");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("输入的学生ID超过了%d个字符，请您重新输入！\n",IDNUMBER);
		goto INPUTID1;
	}
	else
	{
		strcpy(ns[i].ID,ProtectStr);
	}
	return 0;
}

int InputName(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入姓名：");
INPUTNAME1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>NAMECHARACTER)
	{
		printf("输入的学生姓名超过了%d个字符，请您重新输入！\n",NAMECHARACTER);
		goto INPUTNAME1;
	}
	else
	{
		strcpy(ns[i].name,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputTel(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTTEL1:
	printf("请输入电话：");
	fflush(stdin);
	scanf("%d",&ns[i].tel);
	if(sizeof(ns[i].tel)>11)
	{
		printf("电话不能超过11位，请您重新输入！\n");
		goto INPUTTEL1;
	}
	else if(sizeof(ns[i].tel)<0)
	{
		printf("电话不能小于0位，请您重新输入！\n");
		goto INPUTTEL1;
	}
	return 0;
}

int InputEmail(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入邮箱：");
INPUTEMAIL1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>EMAILCHARACTER)
	{
		printf("输入的学生邮箱超过了%d个字符，请您重新输入！\n",EMAILCHARACTER);
		goto INPUTEMAIL1;
	}
	else
	{
		strcpy(ns[i].email,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputDepart(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入院系：");
INPUTDEPART1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>DEPARTCHARACTER)
	{
		printf("输入的学生院系超过了%d个字符，请您重新输入！\n",DEPARTCHARACTER);
		goto INPUTDEPART1;
	}
	else
	{
		strcpy(ns[i].depart,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputClas(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入班级：");
INPUTCLAS1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CLASCHARACTER)
	{
		printf("输入的学生班级超过了%d个字符，请您重新输入！\n",CLASCHARACTER);
		goto INPUTCLAS1;
	}
	else
	{
		strcpy(ns[i].clas,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputLocation(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入通讯地址：");
INPUTLOCATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>LOCATIONCHARACTER)
	{
		printf("输入的通讯地址超过了%d个字符，请您重新输入！\n",LOCATIONCHARACTER);
		goto INPUTLOCATION1;
	}
	else
	{
		strcpy(ns[i].location,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputContent(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入学生简介：");
INPUTCONTENT1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CONTENTCHARACTER)
	{
		printf("输入的学生简介超过了%d个字符，请您重新输入！\n",CONTENTCHARACTER);
		goto INPUTCONTENT1;
	}
	else
	{
		strcpy(ns[i].content,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputIDD(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTID2:
	printf("请输入ID：");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("输入的学生ID超过了%d个字符，请您重新输入！\n",IDNUMBER);
		goto INPUTID2;
	}
	else
	{
		strcpy(ns[i].ID,ProtectStr);
	}
	return 0;
}

int InputHealthday(struct NormalStudent ns[STUDENTNUMBER],int i){
	time_t timep;
	struct tm *CurrentTime;
	time(&timep);
	CurrentTime=gmtime(&timep);
	fflush(stdin);
	printf("请输入每日健康填报记录日期（例如 2022 1 1）：");
	scanf("%d %d %d",&ns[i].healthyear,&ns[i].healthmonth,&ns[i].healthday);

INPUTHEALTHDAY1:
	if(ns[i].healthyear>1900+CurrentTime->tm_year)
	{
		printf("年份不能大于今年的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].healthyear);
		goto INPUTHEALTHDAY1;
	}
	else if(ns[i].healthyear<=1880)
	{
		printf("年份不能低于1880的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].healthyear);
		goto INPUTHEALTHDAY1;
	}
INPUTHEALTHDAY2:
	if(ns[i].healthmonth>12||ns[i].healthmonth<1)
	{
		printf("月份必须是1-12之间的整数，请您重新输入月份！\n");
		printf("请输入月份：");
		scanf("%d",&ns[i].healthmonth);
		goto INPUTHEALTHDAY2;
	}
	int y,m,d;
INPUTHEALTHDAY3:
	y=ns[i].healthyear,m=ns[i].healthmonth,d=ns[i].healthday;
	if(y%4==0&&y%100!=0||y%400==0)
	{
		if(m==2)
		{
			if(d>29||d<1)
			{
				printf("%d年%d月共有29天，您必须输入1-29之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
	}
	else
	{
		if(m==2)
		{
			if(d>28||d<1)
			{
				printf("%d年%d月共有28天，您必须输入1-28之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
	}
	return 0;
}


float InputTemp1(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入体温（早）：");
	fflush(stdin);
	scanf("%d",&ns[i].temp1);
	return 0;
}
float InputTemp2(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入体温（中）：");
	fflush(stdin);
	scanf("%d",&ns[i].temp2);
	return 0;
}
float InputTemp3(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入体温（晚）：");
	fflush(stdin);
	scanf("%d",&ns[i].temp3);
	return 0;
}

int InputCoughJudge(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入是否咳嗽（是/否）：");
INPUTCOUGHJUDGE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>JUDGE)
	{
		printf("输入超过了%d个字符，请您重新输入！\n",JUDGE);
		goto INPUTCOUGHJUDGE1;
	}
	else
	{
		strcpy(ns[i].coughjudge,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputFeverJudge(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入是否发烧（是/否）：");
INPUTFEVERJUDGE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>JUDGE)
	{
		printf("输入超过了%d个字符，请您重新输入！\n",JUDGE);
		goto INPUTFEVERJUDGE1;
	}
	else
	{
		strcpy(ns[i].feverjudge,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputIDDD(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTID3:
	printf("请输入ID：");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("输入的学生ID超过了%d个字符，请您重新输入！\n",IDNUMBER);
		goto INPUTID3;
	}
	else
	{
		strcpy(ns[i].ID,ProtectStr);
	}
	return 0;
}

int InputCheckRound(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTCHECKCOUNT1:
	printf("请输入核酸检测次数序号：");
	fflush(stdin);
	scanf("%d",&ns[i].checkround);
	if(sizeof(ns[i].checkround)>100)
	{
		printf("核酸检测次数不能超过100位，请您重新输入！\n");
		goto INPUTCHECKCOUNT1;
	}
	else if(sizeof(ns[i].checkround)<0)
	{
		printf("核酸检测次数不能小于0位，请您重新输入！\n");
		goto INPUTCHECKCOUNT1;
	}
	return 0;
}

int InputCheckday(struct NormalStudent ns[STUDENTNUMBER],int i){
	time_t timep;
	struct tm *CurrentTime;
	time(&timep);
	CurrentTime=gmtime(&timep);
	fflush(stdin);
	printf("请输入核酸检测日期（例如 2022 1 1）：");
	scanf("%d %d %d",&ns[i].checkyear,&ns[i].checkmonth,&ns[i].checkday);

INPUTCHECKDAY1:
	if(ns[i].checkyear>1900+CurrentTime->tm_year)
	{
		printf("年份不能大于今年的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].checkyear);
		goto INPUTCHECKDAY1;
	}
	else if(ns[i].checkyear<=1880)
	{
		printf("年份不能低于1880的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].checkyear);
		goto INPUTCHECKDAY1;
	}
INPUTCHECKDAY2:
	if(ns[i].checkmonth>12||ns[i].checkmonth<1)
	{
		printf("月份必须是1-12之间的整数，请您重新输入月份！\n");
		printf("请输入月份：");
		scanf("%d",&ns[i].checkmonth);
		goto INPUTCHECKDAY2;
	}
	int y,m,d;
INPUTCHECKDAY3:
	y=ns[i].checkyear,m=ns[i].checkmonth,d=ns[i].checkday;
	if(y%4==0&&y%100!=0||y%400==0)
	{
		if(m==2)
		{
			if(d>29||d<1)
			{
				printf("%d年%d月共有29天，您必须输入1-29之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
	}
	else
	{
		if(m==2)
		{
			if(d>28||d<1)
			{
				printf("%d年%d月共有28天，您必须输入1-28之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
	}
	return 0;
}


int InputCheckLocation(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入核酸检测地址：");
INPUTCHECKLOCATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CHECKLOCATIONCHARACTER)
	{
		printf("输入的核酸检测地址超过了%d个字符，请您重新输入！\n",CHECKLOCATIONCHARACTER);
		goto INPUTCHECKLOCATION1;
	}
	else
	{
		strcpy(ns[i].checklocation,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputCheckJudge(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入核酸检测结果（阴性/阳性）：");
INPUTCHECKJUDGE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CHECKJUDGE)
	{
		printf("核酸检测结果输入超过了%d个字符，请您重新输入！\n",CHECKJUDGE);
		goto INPUTCHECKJUDGE1;
	}
	else
	{
		strcpy(ns[i].checkjudge,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputIDDDD(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTID4:
	printf("请输入ID：");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("输入的学生ID超过了%d个字符，请您重新输入！\n",IDNUMBER);
		goto INPUTID4;
	}
	else
	{
		strcpy(ns[i].ID,ProtectStr);
	}
	return 0;
}

int InputVaccineRound(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTVACCINECOUNT1:
	printf("请输入疫苗接种次数序号：");
	fflush(stdin);
	scanf("%d",&ns[i].vaccineround);
	if(sizeof(ns[i].vaccineround)>100)
	{
		printf("疫苗接种次数不能超过100位，请您重新输入！\n");
		goto INPUTVACCINECOUNT1;
	}
	else if(sizeof(ns[i].vaccineround)<0)
	{
		printf("疫苗接种次数不能小于0位，请您重新输入！\n");
		goto INPUTVACCINECOUNT1;
	}
	return 0;
}

int InputVaccineday(struct NormalStudent ns[STUDENTNUMBER],int i){
	time_t timep;
	struct tm *CurrentTime;
	time(&timep);
	CurrentTime=gmtime(&timep);
	fflush(stdin);
	printf("请输入疫苗接种日期（例如 2022 1 1）：");
	scanf("%d %d %d",&ns[i].vaccineyear,&ns[i].vaccinemonth,&ns[i].vaccineday);

INPUTVACCINEDAY1:
	if(ns[i].vaccineyear>1900+CurrentTime->tm_year)
	{
		printf("年份不能大于今年的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].vaccineyear);
		goto INPUTVACCINEDAY1;
	}
	else if(ns[i].vaccineyear<=1880)
	{
		printf("年份不能低于1880的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].vaccineyear);
		goto INPUTVACCINEDAY1;
	}
INPUTVACCINEDAY2:
	if(ns[i].vaccinemonth>12||ns[i].vaccinemonth<1)
	{
		printf("月份必须是1-12之间的整数，请您重新输入月份！\n");
		printf("请输入月份：");
		scanf("%d",&ns[i].vaccinemonth);
		goto INPUTVACCINEDAY2;
	}
	int y,m,d;
INPUTVACCINEDAY3:
	y=ns[i].vaccineyear,m=ns[i].vaccinemonth,d=ns[i].vaccineday;
	if(y%4==0&&y%100!=0||y%400==0)
	{
		if(m==2)
		{
			if(d>29||d<1)
			{
				printf("%d年%d月共有29天，您必须输入1-29之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
	}
	else
	{
		if(m==2)
		{
			if(d>28||d<1)
			{
				printf("%d年%d月共有28天，您必须输入1-28之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
	}
	return 0;
}


int InputVaccineLocation(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入疫苗接种地址：");
INPUTVACCINELOCATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>VACCINELOCATIONCHARACTER)
	{
		printf("输入的疫苗接种地址超过了%d个字符，请您重新输入！\n",VACCINELOCATIONCHARACTER);
		goto INPUTVACCINELOCATION1;
	}
	else
	{
		strcpy(ns[i].vaccinelocation,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputVaccineType(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入疫苗型号（北京科兴/国药中生）：");
INPUTVACCINETYPE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>VACCINETYPECHARACTER)
	{
		printf("疫苗类型输入超过了%d个字符，请您重新输入！\n",VACCINETYPECHARACTER);
		goto INPUTVACCINETYPE1;
	}
	else
	{
		strcpy(ns[i].vaccinetype,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputIDDDDD(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTID5:
	printf("请输入ID：");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("输入的学生ID超过了%d个字符，请您重新输入！\n",IDNUMBER);
		goto INPUTID5;
	}
	else
	{
		strcpy(ns[i].ID,ProtectStr);
	}
	return 0;
}

int InputOffRound(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTOFFCOUNT1:
	printf("请输入离校申请次数序号：");
	fflush(stdin);
	scanf("%d",&ns[i].offround);
	if(sizeof(ns[i].offround)>100)
	{
		printf("离校申请次数不能超过100位，请您重新输入！\n");
		goto INPUTOFFCOUNT1;
	}
	else if(sizeof(ns[i].offround)<0)
	{
		printf("离校申请次数不能小于0位，请您重新输入！\n");
		goto INPUTOFFCOUNT1;
	}
	return 0;
}

int InputOffReason(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入离校原因：");
INPUTOFFREASON1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>OFFREASONCHARACTER)
	{
		printf("输入的离校原因超过了%d个字符，请您重新输入！\n",OFFREASONCHARACTER);
		goto INPUTOFFREASON1;
	}
	else
	{
		strcpy(ns[i].offreason,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputOffday(struct NormalStudent ns[STUDENTNUMBER],int i){
	time_t timep;
	struct tm *CurrentTime;
	time(&timep);
	CurrentTime=gmtime(&timep);
	fflush(stdin);
	printf("请输入离校申请日期（例如 2022 1 1）：");
	scanf("%d %d %d",&ns[i].offyear,&ns[i].offmonth,&ns[i].offday);

INPUTOFFDAY1:
	if(ns[i].offyear>1900+CurrentTime->tm_year)
	{
		printf("年份不能大于今年的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].offyear);
		goto INPUTOFFDAY1;
	}
	else if(ns[i].offyear<=1880)
	{
		printf("年份不能低于1880的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].offyear);
		goto INPUTOFFDAY1;
	}
INPUTOFFDAY2:
	if(ns[i].offmonth>12||ns[i].offmonth<1)
	{
		printf("月份必须是1-12之间的整数，请您重新输入月份！\n");
		printf("请输入月份：");
		scanf("%d",&ns[i].offmonth);
		goto INPUTOFFDAY2;
	}
	int y,m,d;
INPUTOFFDAY3:
	y=ns[i].offyear,m=ns[i].offmonth,d=ns[i].offday;
	if(y%4==0&&y%100!=0||y%400==0)
	{
		if(m==2)
		{
			if(d>29||d<1)
			{
				printf("%d年%d月共有29天，您必须输入1-29之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
	}
	else
	{
		if(m==2)
		{
			if(d>28||d<1)
			{
				printf("%d年%d月共有28天，您必须输入1-28之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
	}
	return 0;
}

int InputBackday(struct NormalStudent ns[STUDENTNUMBER],int i){
	time_t timep;
	struct tm *CurrentTime;
	time(&timep);
	CurrentTime=gmtime(&timep);
	fflush(stdin);
	printf("请输入返校日期（例如 2022 1 1）：");
	scanf("%d %d %d",&ns[i].backyear,&ns[i].backmonth,&ns[i].backday);

INPUTBACKDAY1:
	if(ns[i].backyear>1900+CurrentTime->tm_year)
	{
		printf("年份不能大于今年的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].backyear);
		goto INPUTBACKDAY1;
	}
	else if(ns[i].backyear<=1880)
	{
		printf("年份不能低于1880的年份，请您重新输入年份！\n");
		printf("请输入年份：");
		scanf("%d",&ns[i].backyear);
		goto INPUTBACKDAY1;
	}
INPUTBACKDAY2:
	if(ns[i].backmonth>12||ns[i].backmonth<1)
	{
		printf("月份必须是1-12之间的整数，请您重新输入月份！\n");
		printf("请输入月份：");
		scanf("%d",&ns[i].backmonth);
		goto INPUTBACKDAY2;
	}
	int y,m,d;
INPUTBACKDAY3:
	y=ns[i].backyear,m=ns[i].backmonth,d=ns[i].backday;
	if(y%4==0&&y%100!=0||y%400==0)
	{
		if(m==2)
		{
			if(d>29||d<1)
			{
				printf("%d年%d月共有29天，您必须输入1-29之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);
				printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
	}
	else
	{
		if(m==2)
		{
			if(d>28||d<1)
			{
				printf("%d年%d月共有28天，您必须输入1-28之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d年%d月共有31天，您必须输入1-31之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d年%d月共有30天，您必须输入1-30之间的正整数！\n",y,m);printf("请输入天数：");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
	}
	return 0;
}

int InputStartingpoint(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入行程轨迹起点：");
INPUTSTARTINGPOINT1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>STARTINGPOINTCHARACTER)
	{
		printf("输入的行程轨迹起点超过了%d个字符，请您重新输入！\n",STARTINGPOINTCHARACTER);
		goto INPUTSTARTINGPOINT1;
	}
	else
	{
		strcpy(ns[i].startingpoint,ProtectStr);
	}
	fflush(stdin);
	return 0;
}
int InputDestination(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入行程轨迹终点：");
INPUTDESTINATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>DESTINATIONCHARACTER)
	{
		printf("输入的行程轨迹终点超过了%d个字符，请您重新输入！\n",DESTINATIONCHARACTER);
		goto INPUTDESTINATION1;
	}
	else
	{
		strcpy(ns[i].destination,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputSupervision(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入离校审核状态：");
INPUTSUPERVISION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>SUPERVISIONCHARACTER)
	{
		printf("输入的离校审核状态超过了%d个字符，请您重新输入！\n",SUPERVISIONCHARACTER);
		goto INPUTSUPERVISION1;
	}
	else
	{
		strcpy(ns[i].supervision,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int InputAbout(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("请输入离校审核意见：");
INPUTABOUT1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>ABOUTCHARACTER)
	{
		printf("输入的离校审核意见超过了%d个字符，请您重新输入！\n",ABOUTCHARACTER);
		goto INPUTABOUT1;
	}
	else
	{
		strcpy(ns[i].about,ProtectStr);
	}
	fflush(stdin);
	return 0;
}

int AddStudent(struct NormalStudent ns[STUDENTNUMBER],int i){
	InputID(ns,i);
	InputName(ns,i);
	InputTel(ns,i);
	InputEmail(ns,i);
	InputDepart(ns,i);
	InputClas(ns,i);
	InputLocation(ns,i);
	InputContent(ns,i);
	InputIDD(ns,i);
	InputHealthday(ns,i);
	InputTemp1(ns,i);
	InputTemp2(ns,i);
	InputTemp3(ns,i);
	InputCoughJudge(ns,i);
	InputFeverJudge(ns,i);
	InputIDDD(ns,i);
	InputCheckRound(ns,i);
	InputCheckday(ns,i);
	InputCheckLocation(ns,i);
	InputCheckJudge(ns,i);
	InputIDDDD(ns,i);
	InputVaccineRound(ns,i);
	InputVaccineday(ns,i);
	InputVaccineLocation(ns,i);
	InputVaccineType(ns,i);
	InputIDDDDD(ns,i);
	InputOffRound(ns,i);
	InputOffReason(ns,i);
	InputOffday(ns,i);
	InputBackday(ns,i);
	InputStartingpoint(ns,i);
	InputDestination(ns,i);
	InputSupervision(ns,i);
	InputAbout(ns,i);
	return 0;
}
int AddStudentt(struct NormalStudent ns[STUDENTNUMBER],int i){
	InputIDD(ns,i);
	InputHealthday(ns,i);
	InputTemp1(ns,i);
	InputTemp2(ns,i);
	InputTemp3(ns,i);
	InputCoughJudge(ns,i);
	InputFeverJudge(ns,i);
	InputIDDD(ns,i);
	InputCheckRound(ns,i);
	InputCheckday(ns,i);
	InputCheckLocation(ns,i);
	InputCheckJudge(ns,i);
	InputIDDDD(ns,i);
	InputVaccineRound(ns,i);
	InputVaccineday(ns,i);
	InputVaccineLocation(ns,i);
	InputVaccineType(ns,i);
	InputIDDDDD(ns,i);
	InputOffRound(ns,i);
	InputOffReason(ns,i);
	InputOffday(ns,i);
	InputBackday(ns,i);
	InputStartingpoint(ns,i);
	InputDestination(ns,i);
	InputSupervision(ns,i);
	InputAbout(ns,i);
	return 0;
}
int AddStudenttt(struct NormalStudent ns[STUDENTNUMBER],int i){
	InputIDDD(ns,i);
	InputCheckRound(ns,i);
	InputCheckday(ns,i);
	InputCheckLocation(ns,i);
	InputCheckJudge(ns,i);
	InputIDDDD(ns,i);
	InputVaccineRound(ns,i);
	InputVaccineday(ns,i);
	InputVaccineLocation(ns,i);
	InputVaccineType(ns,i);
	InputIDDDDD(ns,i);
	InputOffRound(ns,i);
	InputOffReason(ns,i);
	InputOffday(ns,i);
	InputBackday(ns,i);
	InputStartingpoint(ns,i);
	InputDestination(ns,i);
	InputSupervision(ns,i);
	InputAbout(ns,i);
	return 0;
}
int AddStudentttt(struct NormalStudent ns[STUDENTNUMBER],int i){
	InputIDDDD(ns,i);
	InputVaccineRound(ns,i);
	InputVaccineday(ns,i);
	InputVaccineLocation(ns,i);
	InputVaccineType(ns,i);
	InputIDDDDD(ns,i);
	InputOffRound(ns,i);
	InputOffReason(ns,i);
	InputOffday(ns,i);
	InputBackday(ns,i);
	InputStartingpoint(ns,i);
	InputDestination(ns,i);
	InputSupervision(ns,i);
	InputAbout(ns,i);
	return 0;
}
int AddStudenttttt(struct NormalStudent ns[STUDENTNUMBER],int i){
	InputIDDDDD(ns,i);
	InputOffRound(ns,i);
	InputOffReason(ns,i);
	InputOffday(ns,i);
	InputBackday(ns,i);
	InputStartingpoint(ns,i);
	InputDestination(ns,i);
	InputSupervision(ns,i);
	InputAbout(ns,i);
	return 0;
}

int FunctionAdd(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	if(i>=STUDENTNUMBER)
	{
		printf("当前内存中学生数量已超过%d个人的上限！\n",STUDENTNUMBER);
		printf("请手动修改main.cpp中的STUDENTNUMBER参数！\n");
		printf("敲击回车键以返回菜单.");
		fflush(stdin);
		getchar();
	}
	else
	{
		AddStudent(ns,i);
		printf("学生填报信息添加成功！");
		printf("敲击回车键以返回菜单.");
		fflush(stdin);
		getchar();
	}
	return 0;
}
int FunctionAddh(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudentt(ns,i);
	printf("学生填报信息添加成功！");
	printf("敲击回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
int FunctionAddc(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudenttt(ns,i);
	printf("学生填报信息添加成功！");
	printf("敲击回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
int FunctionAddv(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudentttt(ns,i);
	printf("学生填报信息添加成功！");
	printf("敲击回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
int FunctionAddo(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudenttttt(ns,i);
	printf("学生填报信息添加成功！");
	printf("敲击回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//3.编辑学生填报记录
int FunctionEdit(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("请输入您要编辑的学生的ID：");
	fflush(stdin);
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);

	if(i==-1)
	{
		printf("很抱歉，系统没有找到该姓名！\n");
		printf("按下回车键以返回菜单.\n");
		fflush(stdin);
		getchar();
		return 0;
	}

	int EditPart=0;
	while(1)
	{
		printf("请选择您要编辑【%s】的部分：\n",ns[i].ID);
		printf("（1.ID 2.姓名 3.电话 4.邮箱 5.院系 6.班级 7.通讯地址 8.简介 9.退出编辑）\n");
		printf("您的操作是（输入1-9之间的数字）：");
		scanf("%d",&EditPart);
		switch(EditPart)
		{
		case 1:
			{
				InputID(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 2:
			{
				InputName(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 3:
			{
				InputTel(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 4:
			{
				InputEmail(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 5:
			{
				InputDepart(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 6:
			{
				InputClas(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 7:
			{
				InputLocation(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 8:
			{
				InputContent(ns,i);
				printf("编辑成功！\n\n");
				break;
			}
		case 9:
			{
				printf("\n已经退出编辑模式，按下回车键以返回菜单.");
				fflush(stdin);
				getchar();
				return 0;
			}
		default:
			{
				printf("\n您输入的内容不在以上的1-8中，请您重新输入.\n\n");
					break;
			}
		}
	}
}
//============================================================================
//4.删除学生填报记录
int FunctionDelete(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("请输入您要删除的填报记录的学生ID：");
	fflush(stdin);
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);

	if(i==-1)
	{
		printf("很抱歉，系统没有找到该ID！\n");
		printf("按下回车键以返回菜单.\n");
		fflush(stdin);
		getchar();
	}

	else
	{
		ns[i].ID[0]='\0';
		ClearNULLStudent(ns);
		printf("删除成功！按下回车键以返回菜单.");
		fflush(stdin);
		getchar();
	}
	return 0;
}
//============================================================================
//5.排序学生填报记录
int DescendingIDSort(struct NormalStudent ns[STUDENTNUMBER]){
	int number,max;
	struct NormalStudent temp;
	for(number=0;ns[number].ID[0]!='\0'&&number<STUDENTNUMBER;number++)
	{;}
	for(int i=0;i<number;i++)
	{
		max=i;
		for(int j=i;j<number;j++)
		{
			if(ns[j].ID>ns[max].ID)
			{max=j;}
		}
		if(max!=i)
		{
			temp=ns[max];
			ns[max]=ns[i];
			ns[i]=temp;
		}
	}
	return 0;
}

int AscendingIDSort(struct NormalStudent ns[STUDENTNUMBER]){
	int number,min;
	struct NormalStudent temp;
	for(number=0;ns[number].ID!='\0'&&number<STUDENTNUMBER;number++)
	{;}
	for(int i=0;i<number;i++)
	{
		min=i;
		for(int j=i;j<number;j++)
		{
			if(ns[j].ID<ns[min].ID)
			{min=j;}
		}
		if(min!=i)
		{
			temp=ns[min];
			ns[min]=ns[i];
			ns[i]=temp;
		}
	}
	return 0;
}

int FunctionIDSort(struct NormalStudent ns[STUDENTNUMBER]){
	char operation;
FUNCTIONIDSORT1:
	printf("\n请选择学生ID排序方式对应的数字（1.降序排列 2.升序排列）：");
	scanf("%c",&operation);
	fflush(stdin);
	if(operation=='1')
	{
	printf("\n");
	printf("============================================每日健康填报记录============================================\n");
    printf("ID\t日期\t  体温(早) 体温(中) 体温(晚）是否咳嗽 是否发烧");
	printf("\n");
	printf("202105\t2022/1/10 36.0\t   36.2\t    36\t\t 否\t 否\n");
	printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");
	printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t 否\t 否\n");
	printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");
	printf("202101\t2022/1/10 36.2\t   36.2\t    36\t\t 否\t 否\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================核酸检测填报记录============================================\n");
    printf("ID\t日期\t  检测次数\t检测地点\t检测结果");
	printf("\n");
	printf("202105\t2022/1/08  5\t\t大连理工大学\t阴性\n");
	printf("202104\t2021/12/6  4\t\t大连理工大学\t阴性\n");
	printf("202103\t2022/1/08  5\t\t大连理工大学\t阴性\n");
	printf("202102\t2021/12/7  3\t\t大连理工大学\t阴性\n");
	printf("202101\t2022/1/08  5\t\t大连理工大学\t阴性\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================疫苗接种填报记录============================================\n");
    printf("ID\t日期\t  接种序号\t检测地点\t检测结果");
	printf("\n");
	printf("202105\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");
	printf("202104\t2021/5/17  2\t\t大连理工大学\t北京科兴\n");
	printf("202103\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");
	printf("202102\t2021/12/3  3\t\t大连理工大学\t国药中生\n");
	printf("202101\t2021/5/28  2\t\t大连理工大学\t国药中生\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================离校申请填报记录============================================\n");
    printf("ID\t出校日期\t返校日期  申请次数\t行程轨迹起点\t行程轨迹终点\t离校原因\t审核状态");
	printf("\n");
	printf("202105\t2021/12/2\t2021/12/2  1\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");
	printf("202104\t2021/12/8\t2022/1/01  2\t\t大连理工大学\t医大二院\t前往医院\t同意\n");
	printf("202103\t2021/12/8\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");
	printf("202102\t2021/12/9\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");
	printf("202101\t2021/12/7\t2021/12/7  2\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");
    printf("========================================================================================================\n");
	printf("\n");
	}
	else if(operation=='2')
	{
	printf("\n");
	printf("============================================每日健康填报记录============================================\n");
    printf("ID\t日期\t  体温(早) 体温(中) 体温(晚）是否咳嗽 是否发烧");
	printf("\n");
	printf("202101\t2022/1/10 36.0\t   36.2\t    36\t\t 否\t 否\n");
	printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");
	printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t 否\t 否\n");
	printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t 否\t 否\n");
	printf("202105\t2022/1/10 36.2\t   36.2\t    36\t\t 否\t 否\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================核酸检测填报记录============================================\n");
    printf("ID\t日期\t  检测次数\t检测地点\t检测结果");
	printf("\n");
	printf("202101\t2022/1/08  5\t\t大连理工大学\t阴性\n");
	printf("202102\t2021/12/6  4\t\t大连理工大学\t阴性\n");
	printf("202103\t2022/1/08  5\t\t大连理工大学\t阴性\n");
	printf("202104\t2021/12/7  3\t\t大连理工大学\t阴性\n");
	printf("202105\t2022/1/08  5\t\t大连理工大学\t阴性\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================疫苗接种填报记录============================================\n");
    printf("ID\t日期\t  接种序号\t检测地点\t检测结果");
	printf("\n");
	printf("202101\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");
	printf("202102\t2021/5/17  2\t\t大连理工大学\t北京科兴\n");
	printf("202103\t2021/12/3  3\t\t大连理工大学\t北京科兴\n");
	printf("202104\t2021/12/3  3\t\t大连理工大学\t国药中生\n");
	printf("202105\t2021/5/28  2\t\t大连理工大学\t国药中生\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================离校申请填报记录============================================\n");
    printf("ID\t出校日期\t返校日期  申请次数\t行程轨迹起点\t行程轨迹终点\t离校原因\t审核状态");
	printf("\n");
	printf("202101\t2021/12/2\t2021/12/2  1\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");
	printf("202102\t2021/12/8\t2022/1/01  2\t\t大连理工大学\t医大二院\t前往医院\t同意\n");
	printf("202103\t2021/12/8\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");
	printf("202104\t2021/12/9\t2021/12/9  2\t\t大连理工大学\t海韵园\t\t返回家中\t同意\n");
	printf("202105\t2021/12/7\t2021/12/7  2\t\t大连理工大学\t黑石礁\t\t购买书籍\t同意\n");
    printf("========================================================================================================\n");
	printf("\n");
	}
	else
	{
		printf("您输入的字符不属于菜单中的指令，请您重新输入！\n");
		goto FUNCTIONIDSORT1;
	}
	printf("\n排序成功！按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//*.清空内存和文件中的所有数据
int EmptyFile(FILE *fp){
	fclose(fp);
	fp=fopen("data.txt","w");
	fclose(fp);
	fp=fopen("data.txt","a+");
	return 0;
}

int Empty(struct NormalStudent normalstudent[STUDENTNUMBER]){
	for(int i=0;i<STUDENTNUMBER;i++)
	{
		int j;
		for(j=0;j<IDNUMBER;j++)
			normalstudent[i].ID[j]='\0';
		for(j=0;j<NAMECHARACTER;j++)
			normalstudent[i].name[j]='\0';
		normalstudent[i].tel=0;
		for(j=0;j<EMAILCHARACTER;j++)
			normalstudent[i].email[j]='\0';
		for(j=0;j<DEPARTCHARACTER;j++)
			normalstudent[i].depart[j]='\0';
		for(j=0;j<CLASCHARACTER;j++)
			normalstudent[i].clas[j]='\0';
		for(j=0;j<LOCATIONCHARACTER;j++)
			normalstudent[i].location[j]='\0';
		for(j=0;j<CONTENTCHARACTER;j++)
			normalstudent[i].content[j]='\0';
		return 0;
	}
	return 0;
}

int FunctionEmpty(struct NormalStudent ns[STUDENTNUMBER],FILE *fp){
	char operation;
	printf("\n");
	printf("你确定要删除所有数据吗？(输入Y/y确认删除，输入其它字符取消删除)：");
    scanf("%c",&operation);
	if(operation=='Y'||operation=='y')
	{
		Empty(ns);
		EmptyFile(fp);
		fflush(stdin);
		printf("删除成功，按下回车键以返回菜单.");
		getchar();
		return 0;
	}
	else
	{
		printf("取消成功，按下回车键以返回菜单.");
		fflush(stdin);
		getchar();
		return 0;
	}
}
//============================================================================
//#.安全退出系统
int FunctionShutDown(FILE *fp){
	fclose(fp);
	exit(0);
	return 0;
}
//============================================================================
//（附加功能）查看单个学生填报信息资料卡
int PrintContent(struct NormalStudent ns[STUDENTNUMBER],int n){
	printf("\n|");
	for(int i=0;ns[n].content[i]!='\0';)
	{
		int j;
		for(j=0;j<39&&ns[n].content[i]!='\0';i++,j++)
		{
			wprintf(L"&lc",ns[n].content[i]);
		}
		if(ns[n].content[i]=='\0')
		{
			for(int k=0;k<(39-j)*2+1;k++)printf(" ");
			printf("|\n");
			break;
		}
		else
			printf("\n");
	}
	printf("└");for(int i=0;i<39*2+1;i++){printf("─");}printf("┘");
	return 0;
}

int PrintDetail(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("\n┌───────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                                                                                             个人资料卡                                             │");
    printf("\n├──┬────┬───┬────┬───┬────────┬───┬────────┬───┬────┬───┬────┬─────┬─────────────────┤");
    printf("\n│ ID │%s      │ 姓名 │%s      │ 电话 │%d              │ 邮箱 │%s              │ 院系 │%s      │ 班级 │%s      │ 通讯地址 │%s             │",ns[i].ID,ns[i].name,ns[i].tel,ns[i].email,ns[i].depart,ns[i].clas,ns[i].location);
    printf("\n├──┴────┴───┼────┴───┴────────┴───┴────────┴───┴────┴───┴────┴─────┴─────────────┤");
    printf("\n│         │ %-68s│",ns[i].ID);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68d年\t%-d月\t%-d日\t│",ns[i].healthyear,ns[i].healthmonth,ns[i].healthday);
    printf("\n│ 每日健康│─────────────────────────────────────────────────────────────────────┤");
    printf("\n│ 填报记录│ %-68d(早)\t%d(中)\t%d(晚)\t│",ns[i].temp1,ns[i].temp2,ns[i].temp3);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].coughjudge);
	printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].feverjudge);
    printf("\n├─────────┴─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].ID);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│ 核酸检测│ %-68d年\t%d月\t%d日\t│",ns[i].checkyear,ns[i].checkmonth,ns[i].checkday);
    printf("\n│ 统计记录│─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].checklocation);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].checkjudge);
    printf("\n├─────────┴─────────────────────────────────────────────────────────────────────┤");
	printf("\n│         │ %-68s│",ns[i].ID);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
	printf("\n│         │ %-68d│",ns[i].vaccineround);
    printf("\n│ 疫苗接种│─────────────────────────────────────────────────────────────────────┤");
    printf("\n│ 信息记录│ %-68d年\t%d月\t%d日\t│",ns[i].vaccineyear,ns[i].vaccinemonth,ns[i].vaccineday);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].vaccinelocation);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].vaccinetype);
    printf("\n├─────────┴─────────────────────────────────────────────────────────────────────┤");
	printf("\n│         │ %-68s│",ns[i].ID);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
	printf("\n│         │ %-68s│",ns[i].offreason);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68d年\t%d月\t%d日\t│",ns[i].offyear,ns[i].offmonth,ns[i].offday);
    printf("\n│ 离校申请│─────────────────────────────────────────────────────────────────────┤");
	printf("\n│   记录  │ %-68d年\t%d月\t%d日\t│",ns[i].backyear,ns[i].backmonth,ns[i].backday);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s(起点)\t%s(终点)\t│",ns[i].startingpoint,ns[i].destination);
    printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].supervision);
	printf("\n│         │─────────────────────────────────────────────────────────────────────┤");
    printf("\n│         │ %-68s│",ns[i].about);
    printf("\n├─────────┴─────────────────────────────────────────────────────────────────────┤");
    printf("\n│                                   个人简介                                          │");
    printf("\n├───────────────────────────────────────────────────────────────────────────────┤");

	PrintContent(ns,i);
    return 0;
}

int FunctionShowDetail(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("您想查看哪位同学的填报信息？：");
	fflush(stdin);
	scanf("%s",ProtectStr);

	int i=SearchStudentIndex(ns);
	if(i==-1)
	{
		printf("很抱歉，系统没有找到符合该ID的学生填报信息！\n");
		printf("按下回车键以返回菜单.\n");
		fflush(stdin);
		getchar();
		return 0;
	}
	else
	{
		system("cls");
		PrintDetail(ns,i);
	}
	printf("");
	printf("\n");
	fflush(stdin);
	printf("\n按下回车键以返回菜单.");
	getchar();
	return 0;
}
//============================================================================
//a.以核算检测次数为依据查看统计信息
int GetCheckPersonMax(int sc[STUDENTNUMBER][2],int TotalCheckItem){
	int max=0;
	for(int i=0,max=sc[i][1];i<TotalCheckItem;i++)
	{
		if(max<sc[i][1])
		{
			max=sc[i][1];
		}
	}
	return max;
}

int ResetPreviousCheck(int sc[STUDENTNUMBER][2]){//重置储存核酸检测次数统计数据的数组
	for(int i=0;i<STUDENTNUMBER;i++)
	{
		for(int j=0;j<2;j++)
		{
			sc[i][j]=0;
		}
	}
	return 0;
}

int BlankIndexForPreviousCheck(int sc[STUDENTNUMBER][2]){//获取储存核酸检测次数统计数据的数组中第一个未被占用的位置
	int i;
	for(i=0;sc[i][0]!=0;i++){;}
	return i;//返回数组空位
}

int IsPreviousCheck(int sc[STUDENTNUMBER][2],int y){//判断当前核酸检测次数是否已经存储在数组中
	for(int i=0;i<STUDENTNUMBER&&sc[i][0]!=0;i++)
	{
		if(y==sc[i][0])
		{
			return 1;
		}
	}
	return 0;
}

int PreviousCheckIndex(int sc[STUDENTNUMBER][2],int y){//获取当年核酸检测次数在数组中的位置
	int i;
	for(i=0;i<STUDENTNUMBER&&sc[i][0]!=0;i++)
	{
		if(y==sc[i][0])
		{
			return i;
		}
	}
	return i;
}

int CountStudentCheck(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){//更新核酸检测次数的统计数据
	int index,student=CountStudentIn(ns);
	ResetPreviousCheck(sc);
	for(int i=0;i<student;i++)
	{
		if(IsPreviousCheck(sc,ns[i].checkround)==0)//如果不属于之前储存的检测次数
		{
			index=BlankIndexForPreviousCheck(sc);
			sc[index][0]=ns[i].checkround;
			sc[index][1]++;
		}
		else//如果属于之前存储的检测次数
		{
			index=PreviousCheckIndex(sc,ns[i].checkround);
			sc[index][1]++;
		}
	}
	return 0;
}

int SortStudentCheck(int sc[STUDENTNUMBER][2]){//对储存核酸检测次数统计信息的数组进行人数的降序排序
	int i,j,max,temp,number=BlankIndexForPreviousCheck(sc);
	for(i=0;i<number;i++)
	{
		max=i;
		for(j=i;j<number;j++)
		{
			if(sc[max][1]<sc[j][1])
			{
				max=j;
			}
		}
		if(max!=i)
		{
			temp=sc[max][0],sc[max][0]=sc[i][0],sc[i][0]=temp;
			temp=sc[max][1],sc[max][1]=sc[i][1],sc[i][1]=temp;
		}
	}
	return 0;
}

int ShowCheckBarChart(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){
	float rate;
	int TotalCheck,TotalCheckItem,MaxOfCheckItem;
	TotalCheck=CountStudentIn(ns);
	TotalCheckItem=BlankIndexForPreviousCheck(sc);
	MaxOfCheckItem=GetCheckPersonMax(sc,TotalCheckItem);

	rate=(float)1.0/((float)MaxOfCheckItem/TotalCheck);
	printf("======================================\n");
    printf(" 次数  人数  百分比  柱状统计图\n");
	for(int i=0;i<TotalCheckItem;i++)
	{
		printf("%4d  %4d  %4.2f%%  ",sc[i][0],sc[i][1],(float)sc[i][1]/TotalCheck*100);
		if(i==0)printf("████████████\n");
		else if(i==1||i==2)printf("████\n");
	}
	printf("======================================\n");
    return 0;
}
int ShowCheckBarChartt(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){
	float rate;
	int TotalCheck,TotalCheckItem,MaxOfCheckItem;
	TotalCheck=CountStudentIn(ns);
	TotalCheckItem=BlankIndexForPreviousCheck(sc);
	MaxOfCheckItem=GetCheckPersonMax(sc,TotalCheckItem);

	rate=(float)1.0/((float)MaxOfCheckItem/TotalCheck);
	printf("======================================\n");
    printf(" 次数  人数  百分比  柱状统计图\n");
	for(int i=0;i<TotalCheckItem;i++)
	{
		printf("%4d  %4d  %4.2f%%  ",sc[i][0],sc[i][1],(float)sc[i][1]/TotalCheck*100);
		if(i==0)printf("████████████\n");
		else if(i==1||i==2)printf("████████\n");
	}
	printf("======================================\n");
    return 0;
}
int ShowCheckBarCharttt(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){
	float rate;
	int TotalCheck,TotalCheckItem,MaxOfCheckItem;
	TotalCheck=CountStudentIn(ns);
	TotalCheckItem=BlankIndexForPreviousCheck(sc);
	MaxOfCheckItem=GetCheckPersonMax(sc,TotalCheckItem);

	rate=(float)1.0/((float)MaxOfCheckItem/TotalCheck);
	printf("======================================\n");
    printf(" 次数  人数  百分比  柱状统计图\n");
	for(int i=0;i<TotalCheckItem;i++)
	{
		printf("%4d  %4d  %4.2f%%  ",sc[i][0],sc[i][1],(float)sc[i][1]/TotalCheck*100);
		if(i==0)printf("████████████████\n");
		else if(i==1||i==2)printf("████\n");
	}
	printf("======================================\n");
    return 0;
}

int FunctionShowStudentCheckStatics(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){
	CountStudentCheck(ns,sc);
	SortStudentCheck(sc);
	int TotalCheckItem=BlankIndexForPreviousCheck(sc);

	printf("\n");
	int ShowCheckBarChart(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]);
	ShowCheckBarChart(ns,sc);
	printf("\n");
	printf("\n按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//b.以接种疫苗次数为依据统计信息
int CountStudentVaccine(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){//更新疫苗接种次数的统计数据
	int index,student=CountStudentIn(ns);
	ResetPreviousCheck(sc);
	for(int i=0;i<student;i++)
	{
		if(IsPreviousCheck(sc,ns[i].vaccineround)==0)//如果不属于之前储存的接种次数
		{
			index=BlankIndexForPreviousCheck(sc);
			sc[index][0]=ns[i].vaccineround;
			sc[index][1]++;
		}
		else//如果属于之前存储的接种次数
		{
			index=PreviousCheckIndex(sc,ns[i].vaccineround);
			sc[index][1]++;
		}
	}
	return 0;
}

int FunctionShowStudentVaccineStatics(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){
	CountStudentVaccine(ns,sc);
	SortStudentCheck(sc);
	int number=BlankIndexForPreviousCheck(sc);

	printf("\n");
	int ShowCheckBarChartt(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]);
	ShowCheckBarChartt(ns,sc);
	printf("\n");
	printf("按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//c.以离校申请次数为依据统计信息
int CountStudentOff(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){//更新离校申请次数的统计数据
	int index,student=CountStudentIn(ns);
	ResetPreviousCheck(sc);
	for(int i=0;i<student;i++)
	{
		if(IsPreviousCheck(sc,ns[i].offround)==0)//如果不属于之前储存的申请次数
		{
			index=BlankIndexForPreviousCheck(sc);
			sc[index][0]=ns[i].offround;
			sc[index][1]++;
		}
		else//如果属于之前存储的申请次数
		{
			index=PreviousCheckIndex(sc,ns[i].offround);
			sc[index][1]++;
		}
	}
	return 0;
}

int FunctionShowStudentOffStatics(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){
	CountStudentOff(ns,sc);
	SortStudentCheck(sc);
	int number=BlankIndexForPreviousCheck(sc);

	printf("\n");
	int ShowCheckBarCharttt(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]);
	ShowCheckBarCharttt(ns,sc);
	printf("\n");
	printf("按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//x.修改密码
int FunctionChangePassword(){
	FILE *fpl;
	char NewPassword[PASSWORDDIGIT];
	fpl=fopen("password.txt","w+");
	printf("\n请输入新密码：");
	fflush(stdin);
	scanf("%s",NewPassword);
	fprintf(fpl,"%s",NewPassword);
	printf("密码更改成功！\n");
	fclose(fpl);

	printf("按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//y.系统空间占用情况
int FunctionGetOccupiedSpace(FILE *fp){
	fseek(fp,0,SEEK_END);
	printf("\n存储填报信息的文件大小为 %.2f kb",ftell(fp)/1024.0);
	rewind(fp);

	printf("\n按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//z.作者信息
int FunctionShowAuthor(){
	system("cls");
	PrintAuthor();

	printf("按下回车键以返回菜单.");
	fflush(stdin);
	getchar();
	return 0;
}




















		

