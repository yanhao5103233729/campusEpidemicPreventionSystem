int login(char correctpassword[PASSWORDDIGIT],FILE *fpl){
	short int trytimes=0;
	char inputpassword[PASSWORDDIGIT];

	if(fpl==NULL)
	{
		fpl=fopen("password.txt","a+");
		fclose(fpl);
		fpl=fopen("password.txt","r+");
		correctpassword[0]='1',correctpassword[1]='2',correctpassword[2]='3';
		rewind(fpl);
		fprintf(fpl,"%s",correctpassword);
		fclose(fpl);
	}
	else
	{
		fscanf(fpl,"%s",correctpassword);
		fclose(fpl);
	}

	PrintWelcome();
	printf("                   ����������:");
	scanf("%s",inputpassword);

LOGIN1:
	if(strcmp(correctpassword,inputpassword)==0)
	{
		printf("          ������ȷ!�밴�»س����Խ���ϵͳ.\n");
		fflush(stdin);
		getchar();
		return 1;
	}
	else
	{
		trytimes++;
		if(trytimes==3)
		{
			system("cls");
			PrintWelcome();
			printf("                ��û��Ȩ�޽����ϵͳ.\n");
			return 0;
		}
		else
		{
			system("cls");
			PrintWelcome();
			printf("            ��������㻹�� %d �λ���.\n",3-trytimes);
			printf("                   ����������:");
			scanf("%s",inputpassword);
			goto LOGIN1;
		}
	}
}





