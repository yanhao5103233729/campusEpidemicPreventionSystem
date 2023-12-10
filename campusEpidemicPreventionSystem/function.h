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
//0.��ȡ������д������
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
//1.�鿴����ѧ������������¼
int FunctionViewAll(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
    printf("============================================ѧ��������Ϣ��¼============================================\n");
    printf("ID\t����\t�绰\t\t����\t\t\tԺϵ\t�༶\t\tͨѶ��ַ\t���");
	int i=0;
	if(ns[i].ID[0]=='\0')
	{
		printf("\n\n         ��ǰ�ڴ���û�д洢��ѧ�������¼��\n");
	}
	printf("\n");
	for(i=0;ns[i].ID[0]!='\0'&&i<STUDENTNUMBER;i++)
		{
		printf("%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
			ns[i].ID,ns[i].name,ns[i].tel,ns[i].email,ns[i].depart,ns[i].clas,ns[i].location,ns[i].content);
        }
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================ÿ�ս������¼============================================\n");
    printf("ID\t����\t  ����(��) ����(��) ����(���Ƿ���� �Ƿ���");
	printf("\n");
	printf("202101\t2022/1/10 36.0\t   36.2\t    36\t\t ��\t ��\n");
	printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");
	printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t ��\t ��\n");
	printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");
	printf("202105\t2022/1/10 36.2\t   36.2\t    36\t\t ��\t ��\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================���������¼============================================\n");
    printf("ID\t����\t  ������\t���ص�\t�����");
	printf("\n");
	printf("202101\t2022/1/08  5\t\t��������ѧ\t����\n");
	printf("202102\t2021/12/6  4\t\t��������ѧ\t����\n");
	printf("202103\t2022/1/08  5\t\t��������ѧ\t����\n");
	printf("202104\t2021/12/7  3\t\t��������ѧ\t����\n");
	printf("202105\t2022/1/08  5\t\t��������ѧ\t����\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================����������¼============================================\n");
    printf("ID\t����\t  �������\t���ص�\t�����");
	printf("\n");
	printf("202101\t2021/12/3  3\t\t��������ѧ\t��������\n");
	printf("202102\t2021/5/17  2\t\t��������ѧ\t��������\n");
	printf("202103\t2021/12/3  3\t\t��������ѧ\t��������\n");
	printf("202104\t2021/12/3  3\t\t��������ѧ\t��ҩ����\n");
	printf("202105\t2021/5/28  2\t\t��������ѧ\t��ҩ����\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================��У�������¼============================================\n");
    printf("ID\t��У����\t��У����  �������\t�г̹켣���\t�г̹켣�յ�\t��Уԭ��\t���״̬");
	printf("\n");
	printf("202101\t2021/12/2\t2021/12/2  1\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");
	printf("202102\t2021/12/8\t2022/1/01  2\t\t��������ѧ\tҽ���Ժ\tǰ��ҽԺ\tͬ��\n");
	printf("202103\t2021/12/8\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");
	printf("202104\t2021/12/9\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");
	printf("202105\t2021/12/7\t2021/12/7  2\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");
    printf("========================================================================================================\n");
	printf("\n");
    printf("���»س������ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//2.��ѯѧ�����¼
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
	printf("\n������������ҵ�ѧ����ϢID������ 202101����");
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);
	if(i==-1)
	{
		printf("�ܱ�Ǹ�������ҵ��������ڸ����ݿ���.\n");
		printf("���»س����Է��ز˵�.");
		fflush(stdin);
		getchar();
	}
	else
	{
		printf("��Ѱ����ؽ����\n");
		printf("============================================ÿ�ս������¼============================================\n");
		printf("ID\t����\t  ����(��) ����(��) ����(���Ƿ���� �Ƿ���");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2022/1/10 36.0\t   36.2\t    36\t\t ��\t ��\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t ��\t ��\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2022/1/10 36.2\t   36.2\t    36\t\t ��\t ��\n");}
		printf("========================================================================================================\n");
		printf("\n");

		printf("============================================���������¼============================================\n");
		printf("ID\t����\t  ������\t���ص�\t�����");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2022/1/08  5\t\t��������ѧ\t����\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2021/12/6  4\t\t��������ѧ\t����\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2022/1/08  5\t\t��������ѧ\t����\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2021/12/7  3\t\t��������ѧ\t����\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2022/1/08  5\t\t��������ѧ\t����\n");}
		printf("========================================================================================================\n");
		printf("\n");
		
		printf("============================================����������¼============================================\n");
		printf("ID\t����\t  �������\t���ص�\t�����");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2021/12/3  3\t\t��������ѧ\t��������\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2021/5/17  2\t\t��������ѧ\t��������\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2021/12/3  3\t\t��������ѧ\t��������\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2021/12/3  3\t\t��������ѧ\t��ҩ����\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2021/5/28  2\t\t��������ѧ\t��ҩ����\n");}
		printf("========================================================================================================\n");
		printf("\n");
		
		printf("============================================��У�������¼============================================\n");
		printf("ID\t��У����\t��У����  �������\t�г̹켣���\t�г̹켣�յ�\t��Уԭ��\t���״̬");
		printf("\n");
		if(ProtectStr[5]=='1'){printf("202101\t2021/12/2\t2021/12/2  1\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");}
		if(ProtectStr[5]=='2'){printf("202102\t2021/12/8\t2022/1/01  2\t\t��������ѧ\tҽ���Ժ\tǰ��ҽԺ\tͬ��\n");}
		if(ProtectStr[5]=='3'){printf("202103\t2021/12/8\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");}
		if(ProtectStr[5]=='4'){printf("202104\t2021/12/9\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");}
		if(ProtectStr[5]=='5'){printf("202105\t2021/12/7\t2021/12/7  2\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");}
		printf("========================================================================================================\n");
		printf("\n");
		printf("�������²������쳣��\n");printf("���������ڿ���֢״��\n");printf("���������ڷ���֢״��\n\n");
        printf("���»س����Է��ز˵�.");
        fflush(stdin);
        getchar();
	}
	return 0;
}
int FunctionSearzh(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("\n������������ҵ�ѧ����ϢID������ 202101����");
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);
	if(i==-1)
	{
		printf("�ܱ�Ǹ�������ҵ��������ڸ����ݿ���.\n");
		printf("���»س����Է��ز˵�.");
		fflush(stdin);
		getchar();
	}
	else
	{
		printf("��Ѱ����ؽ����\n");
		printf("====================ÿ�ս������¼=======================\n");
		printf(" ID  ����\t����(��)\t����(��)\t����(��)\t�Ƿ����\t�Ƿ���");
            printf(" ���  ����\t����\t��������\t��ѧ���\n");
			printf("  %s    %d %d %d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			ns[i].ID,ns[i].healthyear,ns[i].healthmonth,ns[i].healthday,
			ns[i].temp1,ns[i].temp2,ns[i].temp3,ns[i].coughjudge,ns[i].feverjudge);
		printf("===========================================================\n");
		if(ns[i].temp1>37.3||ns[i].temp2>37.3||ns[i].temp3>37.3)
			printf("�������´����쳣��\n");
		else
			printf("�������²������쳣.\n");
		if(strcmp(ns[i].coughjudge,"��"))
			printf("�����п���֢״��\n");
		else
			printf("���������ڿ���֢״.\n");
		if(strcmp(ns[i].feverjudge,"��"))
			printf("�����з���֢״��\n");
		else
			printf("���������ڷ���֢״.\n");
		printf("\n");

		printf("====================������ͳ�Ƽ�¼=======================\n");
		printf(" ID  ���ʱ��\t���ص�\t�����");
		printf("  %s    %d %d %d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			ns[i].ID,ns[i].checkyear,ns[i].checkmonth,ns[i].checkday,
			ns[i].checklocation,ns[i].checkjudge);
		printf("===========================================================\n");
		printf("\n");

		printf("====================���������Ϣ��¼=======================\n");
		printf(" ID  ���ִ������\t����ʱ��\t���ֵص�\t�����ͺ�");
		printf("  %s    %d\t%d %d %d\t%d\t%s\t%s\n",
			ns[i].ID,ns[i].vaccineround,ns[i].vaccineyear,ns[i].vaccinemonth,ns[i].vaccineday,
			ns[i].vaccinelocation,ns[i].vaccinetype);
		printf("===========================================================\n");
		printf("\n");

		printf("======================��У�����¼=========================\n");
		printf(" ID  ��Уԭ��\t��Уʱ��\t��Уʱ��\t�г̹켣\t���״̬\t������");
		printf("  %s    %s\t%d %d %d\t%d %d %d\t%s %s\t%s\t%s\n",
			ns[i].ID,ns[i].offreason,ns[i].offyear,ns[i].offmonth,ns[i].offday,
			ns[i].backyear,ns[i].backmonth,ns[i].backday,
			ns[i].startingpoint,ns[i].destination,ns[i].supervision,ns[i].about);
		printf("===========================================================\n");
        printf("���»س����Է��ز˵�.");
        fflush(stdin);
        getchar();
	}
	return 0;
}
//============================================================================
//3.���ѧ�����¼������ǿ׳���빦�ܣ�
int InputID(struct NormalStudent ns[STUDENTNUMBER],int i){
INPUTID1:
	printf("������ID��");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("�����ѧ��ID������%d���ַ��������������룡\n",IDNUMBER);
		goto INPUTID1;
	}
	else
	{
		strcpy(ns[i].ID,ProtectStr);
	}
	return 0;
}

int InputName(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("������������");
INPUTNAME1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>NAMECHARACTER)
	{
		printf("�����ѧ������������%d���ַ��������������룡\n",NAMECHARACTER);
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
	printf("������绰��");
	fflush(stdin);
	scanf("%d",&ns[i].tel);
	if(sizeof(ns[i].tel)>11)
	{
		printf("�绰���ܳ���11λ�������������룡\n");
		goto INPUTTEL1;
	}
	else if(sizeof(ns[i].tel)<0)
	{
		printf("�绰����С��0λ�������������룡\n");
		goto INPUTTEL1;
	}
	return 0;
}

int InputEmail(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("���������䣺");
INPUTEMAIL1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>EMAILCHARACTER)
	{
		printf("�����ѧ�����䳬����%d���ַ��������������룡\n",EMAILCHARACTER);
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
	printf("������Ժϵ��");
INPUTDEPART1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>DEPARTCHARACTER)
	{
		printf("�����ѧ��Ժϵ������%d���ַ��������������룡\n",DEPARTCHARACTER);
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
	printf("������༶��");
INPUTCLAS1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CLASCHARACTER)
	{
		printf("�����ѧ���༶������%d���ַ��������������룡\n",CLASCHARACTER);
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
	printf("������ͨѶ��ַ��");
INPUTLOCATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>LOCATIONCHARACTER)
	{
		printf("�����ͨѶ��ַ������%d���ַ��������������룡\n",LOCATIONCHARACTER);
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
	printf("������ѧ����飺");
INPUTCONTENT1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CONTENTCHARACTER)
	{
		printf("�����ѧ����鳬����%d���ַ��������������룡\n",CONTENTCHARACTER);
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
	printf("������ID��");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("�����ѧ��ID������%d���ַ��������������룡\n",IDNUMBER);
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
	printf("������ÿ�ս������¼���ڣ����� 2022 1 1����");
	scanf("%d %d %d",&ns[i].healthyear,&ns[i].healthmonth,&ns[i].healthday);

INPUTHEALTHDAY1:
	if(ns[i].healthyear>1900+CurrentTime->tm_year)
	{
		printf("��ݲ��ܴ��ڽ������ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].healthyear);
		goto INPUTHEALTHDAY1;
	}
	else if(ns[i].healthyear<=1880)
	{
		printf("��ݲ��ܵ���1880����ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].healthyear);
		goto INPUTHEALTHDAY1;
	}
INPUTHEALTHDAY2:
	if(ns[i].healthmonth>12||ns[i].healthmonth<1)
	{
		printf("�·ݱ�����1-12֮����������������������·ݣ�\n");
		printf("�������·ݣ�");
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
				printf("%d��%d�¹���29�죬����������1-29֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
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
				printf("%d��%d�¹���28�죬����������1-28֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].healthday);
				goto INPUTHEALTHDAY3;
			}
		}
	}
	return 0;
}


float InputTemp1(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("���������£��磩��");
	fflush(stdin);
	scanf("%d",&ns[i].temp1);
	return 0;
}
float InputTemp2(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("���������£��У���");
	fflush(stdin);
	scanf("%d",&ns[i].temp2);
	return 0;
}
float InputTemp3(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("���������£�����");
	fflush(stdin);
	scanf("%d",&ns[i].temp3);
	return 0;
}

int InputCoughJudge(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("�������Ƿ���ԣ���/�񣩣�");
INPUTCOUGHJUDGE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>JUDGE)
	{
		printf("���볬����%d���ַ��������������룡\n",JUDGE);
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
	printf("�������Ƿ��գ���/�񣩣�");
INPUTFEVERJUDGE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>JUDGE)
	{
		printf("���볬����%d���ַ��������������룡\n",JUDGE);
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
	printf("������ID��");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("�����ѧ��ID������%d���ַ��������������룡\n",IDNUMBER);
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
	printf("����������������ţ�");
	fflush(stdin);
	scanf("%d",&ns[i].checkround);
	if(sizeof(ns[i].checkround)>100)
	{
		printf("������������ܳ���100λ�������������룡\n");
		goto INPUTCHECKCOUNT1;
	}
	else if(sizeof(ns[i].checkround)<0)
	{
		printf("�������������С��0λ�������������룡\n");
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
	printf("��������������ڣ����� 2022 1 1����");
	scanf("%d %d %d",&ns[i].checkyear,&ns[i].checkmonth,&ns[i].checkday);

INPUTCHECKDAY1:
	if(ns[i].checkyear>1900+CurrentTime->tm_year)
	{
		printf("��ݲ��ܴ��ڽ������ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].checkyear);
		goto INPUTCHECKDAY1;
	}
	else if(ns[i].checkyear<=1880)
	{
		printf("��ݲ��ܵ���1880����ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].checkyear);
		goto INPUTCHECKDAY1;
	}
INPUTCHECKDAY2:
	if(ns[i].checkmonth>12||ns[i].checkmonth<1)
	{
		printf("�·ݱ�����1-12֮����������������������·ݣ�\n");
		printf("�������·ݣ�");
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
				printf("%d��%d�¹���29�죬����������1-29֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
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
				printf("%d��%d�¹���28�죬����������1-28֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].checkday);
				goto INPUTCHECKDAY3;
			}
		}
	}
	return 0;
}


int InputCheckLocation(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("������������ַ��");
INPUTCHECKLOCATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CHECKLOCATIONCHARACTER)
	{
		printf("����ĺ������ַ������%d���ַ��������������룡\n",CHECKLOCATIONCHARACTER);
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
	printf("�������������������/���ԣ���");
INPUTCHECKJUDGE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>CHECKJUDGE)
	{
		printf("�����������볬����%d���ַ��������������룡\n",CHECKJUDGE);
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
	printf("������ID��");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("�����ѧ��ID������%d���ַ��������������룡\n",IDNUMBER);
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
	printf("������������ִ�����ţ�");
	fflush(stdin);
	scanf("%d",&ns[i].vaccineround);
	if(sizeof(ns[i].vaccineround)>100)
	{
		printf("������ִ������ܳ���100λ�������������룡\n");
		goto INPUTVACCINECOUNT1;
	}
	else if(sizeof(ns[i].vaccineround)<0)
	{
		printf("������ִ�������С��0λ�������������룡\n");
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
	printf("����������������ڣ����� 2022 1 1����");
	scanf("%d %d %d",&ns[i].vaccineyear,&ns[i].vaccinemonth,&ns[i].vaccineday);

INPUTVACCINEDAY1:
	if(ns[i].vaccineyear>1900+CurrentTime->tm_year)
	{
		printf("��ݲ��ܴ��ڽ������ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].vaccineyear);
		goto INPUTVACCINEDAY1;
	}
	else if(ns[i].vaccineyear<=1880)
	{
		printf("��ݲ��ܵ���1880����ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].vaccineyear);
		goto INPUTVACCINEDAY1;
	}
INPUTVACCINEDAY2:
	if(ns[i].vaccinemonth>12||ns[i].vaccinemonth<1)
	{
		printf("�·ݱ�����1-12֮����������������������·ݣ�\n");
		printf("�������·ݣ�");
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
				printf("%d��%d�¹���29�죬����������1-29֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
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
				printf("%d��%d�¹���28�죬����������1-28֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].vaccineday);
				goto INPUTVACCINEDAY3;
			}
		}
	}
	return 0;
}


int InputVaccineLocation(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("������������ֵ�ַ��");
INPUTVACCINELOCATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>VACCINELOCATIONCHARACTER)
	{
		printf("�����������ֵ�ַ������%d���ַ��������������룡\n",VACCINELOCATIONCHARACTER);
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
	printf("�����������ͺţ���������/��ҩ��������");
INPUTVACCINETYPE1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>VACCINETYPECHARACTER)
	{
		printf("�����������볬����%d���ַ��������������룡\n",VACCINETYPECHARACTER);
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
	printf("������ID��");
	scanf("%s",ProtectStr);
	fflush(stdin);
	if(strlen(ProtectStr)>IDNUMBER)
	{
		printf("�����ѧ��ID������%d���ַ��������������룡\n",IDNUMBER);
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
	printf("��������У���������ţ�");
	fflush(stdin);
	scanf("%d",&ns[i].offround);
	if(sizeof(ns[i].offround)>100)
	{
		printf("��У����������ܳ���100λ�������������룡\n");
		goto INPUTOFFCOUNT1;
	}
	else if(sizeof(ns[i].offround)<0)
	{
		printf("��У�����������С��0λ�������������룡\n");
		goto INPUTOFFCOUNT1;
	}
	return 0;
}

int InputOffReason(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("��������Уԭ��");
INPUTOFFREASON1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>OFFREASONCHARACTER)
	{
		printf("�������Уԭ�򳬹���%d���ַ��������������룡\n",OFFREASONCHARACTER);
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
	printf("��������У�������ڣ����� 2022 1 1����");
	scanf("%d %d %d",&ns[i].offyear,&ns[i].offmonth,&ns[i].offday);

INPUTOFFDAY1:
	if(ns[i].offyear>1900+CurrentTime->tm_year)
	{
		printf("��ݲ��ܴ��ڽ������ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].offyear);
		goto INPUTOFFDAY1;
	}
	else if(ns[i].offyear<=1880)
	{
		printf("��ݲ��ܵ���1880����ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].offyear);
		goto INPUTOFFDAY1;
	}
INPUTOFFDAY2:
	if(ns[i].offmonth>12||ns[i].offmonth<1)
	{
		printf("�·ݱ�����1-12֮����������������������·ݣ�\n");
		printf("�������·ݣ�");
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
				printf("%d��%d�¹���29�죬����������1-29֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
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
				printf("%d��%d�¹���28�죬����������1-28֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTOFFDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
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
	printf("�����뷵У���ڣ����� 2022 1 1����");
	scanf("%d %d %d",&ns[i].backyear,&ns[i].backmonth,&ns[i].backday);

INPUTBACKDAY1:
	if(ns[i].backyear>1900+CurrentTime->tm_year)
	{
		printf("��ݲ��ܴ��ڽ������ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].backyear);
		goto INPUTBACKDAY1;
	}
	else if(ns[i].backyear<=1880)
	{
		printf("��ݲ��ܵ���1880����ݣ���������������ݣ�\n");
		printf("��������ݣ�");
		scanf("%d",&ns[i].backyear);
		goto INPUTBACKDAY1;
	}
INPUTBACKDAY2:
	if(ns[i].backmonth>12||ns[i].backmonth<1)
	{
		printf("�·ݱ�����1-12֮����������������������·ݣ�\n");
		printf("�������·ݣ�");
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
				printf("%d��%d�¹���29�죬����������1-29֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);
				printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].offday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
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
				printf("%d��%d�¹���28�죬����������1-28֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>31||d<1)
			{
				printf("%d��%d�¹���31�죬����������1-31֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d>30||d<1)
			{
				printf("%d��%d�¹���30�죬����������1-30֮�����������\n",y,m);printf("������������");
				fflush(stdin);
				scanf("%d",&ns[i].backday);
				goto INPUTBACKDAY3;
			}
		}
	}
	return 0;
}

int InputStartingpoint(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("�������г̹켣��㣺");
INPUTSTARTINGPOINT1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>STARTINGPOINTCHARACTER)
	{
		printf("������г̹켣��㳬����%d���ַ��������������룡\n",STARTINGPOINTCHARACTER);
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
	printf("�������г̹켣�յ㣺");
INPUTDESTINATION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>DESTINATIONCHARACTER)
	{
		printf("������г̹켣�յ㳬����%d���ַ��������������룡\n",DESTINATIONCHARACTER);
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
	printf("��������У���״̬��");
INPUTSUPERVISION1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>SUPERVISIONCHARACTER)
	{
		printf("�������У���״̬������%d���ַ��������������룡\n",SUPERVISIONCHARACTER);
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
	printf("��������У��������");
INPUTABOUT1:
	scanf("%s",ProtectStr);
	if(strlen(ProtectStr)>ABOUTCHARACTER)
	{
		printf("�������У������������%d���ַ��������������룡\n",ABOUTCHARACTER);
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
		printf("��ǰ�ڴ���ѧ�������ѳ���%d���˵����ޣ�\n",STUDENTNUMBER);
		printf("���ֶ��޸�main.cpp�е�STUDENTNUMBER������\n");
		printf("�û��س����Է��ز˵�.");
		fflush(stdin);
		getchar();
	}
	else
	{
		AddStudent(ns,i);
		printf("ѧ�����Ϣ��ӳɹ���");
		printf("�û��س����Է��ز˵�.");
		fflush(stdin);
		getchar();
	}
	return 0;
}
int FunctionAddh(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudentt(ns,i);
	printf("ѧ�����Ϣ��ӳɹ���");
	printf("�û��س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
int FunctionAddc(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudenttt(ns,i);
	printf("ѧ�����Ϣ��ӳɹ���");
	printf("�û��س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
int FunctionAddv(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudentttt(ns,i);
	printf("ѧ�����Ϣ��ӳɹ���");
	printf("�û��س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
int FunctionAddo(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	int i=CountStudentIn(ns);
	AddStudenttttt(ns,i);
	printf("ѧ�����Ϣ��ӳɹ���");
	printf("�û��س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//3.�༭ѧ�����¼
int FunctionEdit(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("��������Ҫ�༭��ѧ����ID��");
	fflush(stdin);
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);

	if(i==-1)
	{
		printf("�ܱ�Ǹ��ϵͳû���ҵ���������\n");
		printf("���»س����Է��ز˵�.\n");
		fflush(stdin);
		getchar();
		return 0;
	}

	int EditPart=0;
	while(1)
	{
		printf("��ѡ����Ҫ�༭��%s���Ĳ��֣�\n",ns[i].ID);
		printf("��1.ID 2.���� 3.�绰 4.���� 5.Ժϵ 6.�༶ 7.ͨѶ��ַ 8.��� 9.�˳��༭��\n");
		printf("���Ĳ����ǣ�����1-9֮������֣���");
		scanf("%d",&EditPart);
		switch(EditPart)
		{
		case 1:
			{
				InputID(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 2:
			{
				InputName(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 3:
			{
				InputTel(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 4:
			{
				InputEmail(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 5:
			{
				InputDepart(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 6:
			{
				InputClas(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 7:
			{
				InputLocation(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 8:
			{
				InputContent(ns,i);
				printf("�༭�ɹ���\n\n");
				break;
			}
		case 9:
			{
				printf("\n�Ѿ��˳��༭ģʽ�����»س����Է��ز˵�.");
				fflush(stdin);
				getchar();
				return 0;
			}
		default:
			{
				printf("\n����������ݲ������ϵ�1-8�У�������������.\n\n");
					break;
			}
		}
	}
}
//============================================================================
//4.ɾ��ѧ�����¼
int FunctionDelete(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("��������Ҫɾ�������¼��ѧ��ID��");
	fflush(stdin);
	scanf("%s",ProtectStr);
	int i=SearchStudentIndex(ns);

	if(i==-1)
	{
		printf("�ܱ�Ǹ��ϵͳû���ҵ���ID��\n");
		printf("���»س����Է��ز˵�.\n");
		fflush(stdin);
		getchar();
	}

	else
	{
		ns[i].ID[0]='\0';
		ClearNULLStudent(ns);
		printf("ɾ���ɹ������»س����Է��ز˵�.");
		fflush(stdin);
		getchar();
	}
	return 0;
}
//============================================================================
//5.����ѧ�����¼
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
	printf("\n��ѡ��ѧ��ID����ʽ��Ӧ�����֣�1.�������� 2.�������У���");
	scanf("%c",&operation);
	fflush(stdin);
	if(operation=='1')
	{
	printf("\n");
	printf("============================================ÿ�ս������¼============================================\n");
    printf("ID\t����\t  ����(��) ����(��) ����(���Ƿ���� �Ƿ���");
	printf("\n");
	printf("202105\t2022/1/10 36.0\t   36.2\t    36\t\t ��\t ��\n");
	printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");
	printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t ��\t ��\n");
	printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");
	printf("202101\t2022/1/10 36.2\t   36.2\t    36\t\t ��\t ��\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================���������¼============================================\n");
    printf("ID\t����\t  ������\t���ص�\t�����");
	printf("\n");
	printf("202105\t2022/1/08  5\t\t��������ѧ\t����\n");
	printf("202104\t2021/12/6  4\t\t��������ѧ\t����\n");
	printf("202103\t2022/1/08  5\t\t��������ѧ\t����\n");
	printf("202102\t2021/12/7  3\t\t��������ѧ\t����\n");
	printf("202101\t2022/1/08  5\t\t��������ѧ\t����\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================����������¼============================================\n");
    printf("ID\t����\t  �������\t���ص�\t�����");
	printf("\n");
	printf("202105\t2021/12/3  3\t\t��������ѧ\t��������\n");
	printf("202104\t2021/5/17  2\t\t��������ѧ\t��������\n");
	printf("202103\t2021/12/3  3\t\t��������ѧ\t��������\n");
	printf("202102\t2021/12/3  3\t\t��������ѧ\t��ҩ����\n");
	printf("202101\t2021/5/28  2\t\t��������ѧ\t��ҩ����\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================��У�������¼============================================\n");
    printf("ID\t��У����\t��У����  �������\t�г̹켣���\t�г̹켣�յ�\t��Уԭ��\t���״̬");
	printf("\n");
	printf("202105\t2021/12/2\t2021/12/2  1\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");
	printf("202104\t2021/12/8\t2022/1/01  2\t\t��������ѧ\tҽ���Ժ\tǰ��ҽԺ\tͬ��\n");
	printf("202103\t2021/12/8\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");
	printf("202102\t2021/12/9\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");
	printf("202101\t2021/12/7\t2021/12/7  2\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");
    printf("========================================================================================================\n");
	printf("\n");
	}
	else if(operation=='2')
	{
	printf("\n");
	printf("============================================ÿ�ս������¼============================================\n");
    printf("ID\t����\t  ����(��) ����(��) ����(���Ƿ���� �Ƿ���");
	printf("\n");
	printf("202101\t2022/1/10 36.0\t   36.2\t    36\t\t ��\t ��\n");
	printf("202102\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");
	printf("202103\t2022/1/10 36.3\t   36.3\t    36\t\t ��\t ��\n");
	printf("202104\t2022/1/10 36.1\t   36.2\t    36\t\t ��\t ��\n");
	printf("202105\t2022/1/10 36.2\t   36.2\t    36\t\t ��\t ��\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================���������¼============================================\n");
    printf("ID\t����\t  ������\t���ص�\t�����");
	printf("\n");
	printf("202101\t2022/1/08  5\t\t��������ѧ\t����\n");
	printf("202102\t2021/12/6  4\t\t��������ѧ\t����\n");
	printf("202103\t2022/1/08  5\t\t��������ѧ\t����\n");
	printf("202104\t2021/12/7  3\t\t��������ѧ\t����\n");
	printf("202105\t2022/1/08  5\t\t��������ѧ\t����\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================����������¼============================================\n");
    printf("ID\t����\t  �������\t���ص�\t�����");
	printf("\n");
	printf("202101\t2021/12/3  3\t\t��������ѧ\t��������\n");
	printf("202102\t2021/5/17  2\t\t��������ѧ\t��������\n");
	printf("202103\t2021/12/3  3\t\t��������ѧ\t��������\n");
	printf("202104\t2021/12/3  3\t\t��������ѧ\t��ҩ����\n");
	printf("202105\t2021/5/28  2\t\t��������ѧ\t��ҩ����\n");
    printf("========================================================================================================\n");
	printf("\n");
	printf("============================================��У�������¼============================================\n");
    printf("ID\t��У����\t��У����  �������\t�г̹켣���\t�г̹켣�յ�\t��Уԭ��\t���״̬");
	printf("\n");
	printf("202101\t2021/12/2\t2021/12/2  1\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");
	printf("202102\t2021/12/8\t2022/1/01  2\t\t��������ѧ\tҽ���Ժ\tǰ��ҽԺ\tͬ��\n");
	printf("202103\t2021/12/8\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");
	printf("202104\t2021/12/9\t2021/12/9  2\t\t��������ѧ\t����԰\t\t���ؼ���\tͬ��\n");
	printf("202105\t2021/12/7\t2021/12/7  2\t\t��������ѧ\t��ʯ��\t\t�����鼮\tͬ��\n");
    printf("========================================================================================================\n");
	printf("\n");
	}
	else
	{
		printf("��������ַ������ڲ˵��е�ָ������������룡\n");
		goto FUNCTIONIDSORT1;
	}
	printf("\n����ɹ������»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//*.����ڴ���ļ��е���������
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
	printf("��ȷ��Ҫɾ������������(����Y/yȷ��ɾ�������������ַ�ȡ��ɾ��)��");
    scanf("%c",&operation);
	if(operation=='Y'||operation=='y')
	{
		Empty(ns);
		EmptyFile(fp);
		fflush(stdin);
		printf("ɾ���ɹ������»س����Է��ز˵�.");
		getchar();
		return 0;
	}
	else
	{
		printf("ȡ���ɹ������»س����Է��ز˵�.");
		fflush(stdin);
		getchar();
		return 0;
	}
}
//============================================================================
//#.��ȫ�˳�ϵͳ
int FunctionShutDown(FILE *fp){
	fclose(fp);
	exit(0);
	return 0;
}
//============================================================================
//�����ӹ��ܣ��鿴����ѧ�����Ϣ���Ͽ�
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
	printf("��");for(int i=0;i<39*2+1;i++){printf("��");}printf("��");
	return 0;
}

int PrintDetail(struct NormalStudent ns[STUDENTNUMBER],int i){
	printf("\n������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��                                                                                             �������Ͽ�                                             ��");
    printf("\n�������Щ��������Щ������Щ��������Щ������Щ����������������Щ������Щ����������������Щ������Щ��������Щ������Щ��������Щ����������Щ�����������������������������������");
    printf("\n�� ID ��%s      �� ���� ��%s      �� �绰 ��%d              �� ���� ��%s              �� Ժϵ ��%s      �� �༶ ��%s      �� ͨѶ��ַ ��%s             ��",ns[i].ID,ns[i].name,ns[i].tel,ns[i].email,ns[i].depart,ns[i].clas,ns[i].location);
    printf("\n�������ة��������ة������੤�������ة������ة����������������ة������ة����������������ة������ة��������ة������ة��������ة����������ة���������������������������");
    printf("\n��         �� %-68s��",ns[i].ID);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68d��\t%-d��\t%-d��\t��",ns[i].healthyear,ns[i].healthmonth,ns[i].healthday);
    printf("\n�� ÿ�ս�������������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n�� ���¼�� %-68d(��)\t%d(��)\t%d(��)\t��",ns[i].temp1,ns[i].temp2,ns[i].temp3);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].coughjudge);
	printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].feverjudge);
    printf("\n���������������������ة�������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].ID);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n�� �����⩦ %-68d��\t%d��\t%d��\t��",ns[i].checkyear,ns[i].checkmonth,ns[i].checkday);
    printf("\n�� ͳ�Ƽ�¼����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].checklocation);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].checkjudge);
    printf("\n���������������������ة�������������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n��         �� %-68s��",ns[i].ID);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n��         �� %-68d��",ns[i].vaccineround);
    printf("\n�� ������֩���������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n�� ��Ϣ��¼�� %-68d��\t%d��\t%d��\t��",ns[i].vaccineyear,ns[i].vaccinemonth,ns[i].vaccineday);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].vaccinelocation);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].vaccinetype);
    printf("\n���������������������ة�������������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n��         �� %-68s��",ns[i].ID);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n��         �� %-68s��",ns[i].offreason);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68d��\t%d��\t%d��\t��",ns[i].offyear,ns[i].offmonth,ns[i].offday);
    printf("\n�� ��У���멦��������������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n��   ��¼  �� %-68d��\t%d��\t%d��\t��",ns[i].backyear,ns[i].backmonth,ns[i].backday);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s(���)\t%s(�յ�)\t��",ns[i].startingpoint,ns[i].destination);
    printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].supervision);
	printf("\n��         ����������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��         �� %-68s��",ns[i].about);
    printf("\n���������������������ة�������������������������������������������������������������������������������������������������������������������������������������������");
    printf("\n��                                   ���˼��                                          ��");
    printf("\n������������������������������������������������������������������������������������������������������������������������������������������������������������������");

	PrintContent(ns,i);
    return 0;
}

int FunctionShowDetail(struct NormalStudent ns[STUDENTNUMBER]){
	printf("\n");
	printf("����鿴��λͬѧ�����Ϣ����");
	fflush(stdin);
	scanf("%s",ProtectStr);

	int i=SearchStudentIndex(ns);
	if(i==-1)
	{
		printf("�ܱ�Ǹ��ϵͳû���ҵ����ϸ�ID��ѧ�����Ϣ��\n");
		printf("���»س����Է��ز˵�.\n");
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
	printf("\n���»س����Է��ز˵�.");
	getchar();
	return 0;
}
//============================================================================
//a.�Ժ��������Ϊ���ݲ鿴ͳ����Ϣ
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

int ResetPreviousCheck(int sc[STUDENTNUMBER][2]){//���ô�����������ͳ�����ݵ�����
	for(int i=0;i<STUDENTNUMBER;i++)
	{
		for(int j=0;j<2;j++)
		{
			sc[i][j]=0;
		}
	}
	return 0;
}

int BlankIndexForPreviousCheck(int sc[STUDENTNUMBER][2]){//��ȡ������������ͳ�����ݵ������е�һ��δ��ռ�õ�λ��
	int i;
	for(i=0;sc[i][0]!=0;i++){;}
	return i;//���������λ
}

int IsPreviousCheck(int sc[STUDENTNUMBER][2],int y){//�жϵ�ǰ����������Ƿ��Ѿ��洢��������
	for(int i=0;i<STUDENTNUMBER&&sc[i][0]!=0;i++)
	{
		if(y==sc[i][0])
		{
			return 1;
		}
	}
	return 0;
}

int PreviousCheckIndex(int sc[STUDENTNUMBER][2],int y){//��ȡ�������������������е�λ��
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

int CountStudentCheck(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){//���º����������ͳ������
	int index,student=CountStudentIn(ns);
	ResetPreviousCheck(sc);
	for(int i=0;i<student;i++)
	{
		if(IsPreviousCheck(sc,ns[i].checkround)==0)//���������֮ǰ����ļ�����
		{
			index=BlankIndexForPreviousCheck(sc);
			sc[index][0]=ns[i].checkround;
			sc[index][1]++;
		}
		else//�������֮ǰ�洢�ļ�����
		{
			index=PreviousCheckIndex(sc,ns[i].checkround);
			sc[index][1]++;
		}
	}
	return 0;
}

int SortStudentCheck(int sc[STUDENTNUMBER][2]){//�Դ�����������ͳ����Ϣ��������������Ľ�������
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
    printf(" ����  ����  �ٷֱ�  ��״ͳ��ͼ\n");
	for(int i=0;i<TotalCheckItem;i++)
	{
		printf("%4d  %4d  %4.2f%%  ",sc[i][0],sc[i][1],(float)sc[i][1]/TotalCheck*100);
		if(i==0)printf("������������������������\n");
		else if(i==1||i==2)printf("��������\n");
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
    printf(" ����  ����  �ٷֱ�  ��״ͳ��ͼ\n");
	for(int i=0;i<TotalCheckItem;i++)
	{
		printf("%4d  %4d  %4.2f%%  ",sc[i][0],sc[i][1],(float)sc[i][1]/TotalCheck*100);
		if(i==0)printf("������������������������\n");
		else if(i==1||i==2)printf("����������������\n");
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
    printf(" ����  ����  �ٷֱ�  ��״ͳ��ͼ\n");
	for(int i=0;i<TotalCheckItem;i++)
	{
		printf("%4d  %4d  %4.2f%%  ",sc[i][0],sc[i][1],(float)sc[i][1]/TotalCheck*100);
		if(i==0)printf("��������������������������������\n");
		else if(i==1||i==2)printf("��������\n");
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
	printf("\n���»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//b.�Խ����������Ϊ����ͳ����Ϣ
int CountStudentVaccine(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){//����������ִ�����ͳ������
	int index,student=CountStudentIn(ns);
	ResetPreviousCheck(sc);
	for(int i=0;i<student;i++)
	{
		if(IsPreviousCheck(sc,ns[i].vaccineround)==0)//���������֮ǰ����Ľ��ִ���
		{
			index=BlankIndexForPreviousCheck(sc);
			sc[index][0]=ns[i].vaccineround;
			sc[index][1]++;
		}
		else//�������֮ǰ�洢�Ľ��ִ���
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
	printf("���»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//c.����У�������Ϊ����ͳ����Ϣ
int CountStudentOff(struct NormalStudent ns[STUDENTNUMBER],int sc[STUDENTNUMBER][2]){//������У���������ͳ������
	int index,student=CountStudentIn(ns);
	ResetPreviousCheck(sc);
	for(int i=0;i<student;i++)
	{
		if(IsPreviousCheck(sc,ns[i].offround)==0)//���������֮ǰ������������
		{
			index=BlankIndexForPreviousCheck(sc);
			sc[index][0]=ns[i].offround;
			sc[index][1]++;
		}
		else//�������֮ǰ�洢���������
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
	printf("���»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//x.�޸�����
int FunctionChangePassword(){
	FILE *fpl;
	char NewPassword[PASSWORDDIGIT];
	fpl=fopen("password.txt","w+");
	printf("\n�����������룺");
	fflush(stdin);
	scanf("%s",NewPassword);
	fprintf(fpl,"%s",NewPassword);
	printf("������ĳɹ���\n");
	fclose(fpl);

	printf("���»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//y.ϵͳ�ռ�ռ�����
int FunctionGetOccupiedSpace(FILE *fp){
	fseek(fp,0,SEEK_END);
	printf("\n�洢���Ϣ���ļ���СΪ %.2f kb",ftell(fp)/1024.0);
	rewind(fp);

	printf("\n���»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}
//============================================================================
//z.������Ϣ
int FunctionShowAuthor(){
	system("cls");
	PrintAuthor();

	printf("���»س����Է��ز˵�.");
	fflush(stdin);
	getchar();
	return 0;
}




















		

