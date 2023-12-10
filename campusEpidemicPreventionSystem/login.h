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
	printf("                   请输入密码:");
	scanf("%s",inputpassword);

LOGIN1:
	if(strcmp(correctpassword,inputpassword)==0)
	{
		printf("          密码正确!请按下回车键以进入系统.\n");
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
			printf("                您没有权限进入此系统.\n");
			return 0;
		}
		else
		{
			system("cls");
			PrintWelcome();
			printf("            密码错误！你还有 %d 次机会.\n",3-trytimes);
			printf("                   请输入密码:");
			scanf("%s",inputpassword);
			goto LOGIN1;
		}
	}
}





