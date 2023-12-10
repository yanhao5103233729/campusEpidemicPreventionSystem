int PrintWelcome(){
	printf("┌─────────────────────────────────────────────────────┐\n");
	printf("│    欢迎使用大连理工大学校园疫情防控信息管理系统！   │\n");
	printf("│                                                     │\n");
	printf("│    ******          **       **      ***********     │\n");
	printf("│    **    ***       **       **          ***         │\n");
	printf("│    **      **      **       **          ***         │\n");
	printf("│    **       *      **       **          ***         │\n");
	printf("│    **       *      **       **          ***         │\n");
	printf("│    **      **      **       **          ***         │\n");
	printf("│    **    ***        **     **           ***         │\n");
	printf("│    ******             *****             ***         │\n");
	printf("│                                                     │\n");
    printf("└─────────────────────────────────────────────────────┘\n");
    return 0;
}

int PrintMenuHead(){
    printf("┌───────────────────────────────────────────────────────┐\n");
    printf("│             大连理工大学疫情防控管理系统              │\n");
    printf("├───────────────────────────────────────────────────────┤\n");
    printf("│                         菜单                          │\n");
    printf("├────────────────┬────────────────────┬─────────────────┤\n");

    return 0;
}

int PrintMenuEdit(){
    printf("│■■■编辑■■■│      统计数据      │       关于      │\n");
    printf("├────────────────┴────────────────────┴─────────────────┤\n");
    printf("│1  查看所有学生疫情防控填报记录                        │\n");
	printf("│2  查询学生个人信息                                    │\n");
    printf("│3  编辑学生个人信息                                    │\n");
	printf("│4  删除学生个人信息                                    │\n");
	printf("│5  排序学生个人信息                                    │\n");
	printf("│                                                       │\n");
	printf("│6  添加学生个人信息                                    │\n");
	printf("│x  添加每日健康记录                                    │\n");
	printf("│y  添加核酸检测统计                                    │\n");
	printf("│z  添加疫苗接种信息                                    │\n");
	printf("│w  添加离校申请统计                                    │\n");
	printf("│                                                       │\n");
    printf("│*  清空内存和文件中的所有数据                          │\n");
	printf("│#  安全退出系统                                        │\n");
    printf("└───────────────────────────────────────────────────────┘\n");
	return 0;
}

int PrintMenuStatics(){
    printf("│      编辑      │■■■统计数据■■■│       关于      │\n");
    printf("├────────────────┴────────────────────┴─────────────────┤\n");
    printf("│a 以核酸检测为依据查看统计信息                         │\n");
    printf("│b 以疫苗接种为依据查看统计信息                         │\n");
	printf("│c 以离校申请为依据查看统计信息                         │\n");
    printf("└───────────────────────────────────────────────────────┘\n");
    printf("");
	return 0;
}

int PrintMenuAccount(){
    printf("│      编辑      │      统计数据      │ ■■■关于■■■│\n");
    printf("├────────────────┴────────────────────┴─────────────────┤\n");
	printf("│m 修改密码                                             │\n");
	printf("│n 系统空间占用情况                                     │\n");
	printf("│r 作者信息                                             │\n");
    printf("└───────────────────────────────────────────────────────┘\n");
	return 0;
}

int PrintFileCorrupted(){
	system("cls");
	printf("\n");
	printf("    ┌────────────────────────────┐\n");
	printf("    │The file has been corrupted!│\n");
	printf("    │   The system can't work!   │\n");
	printf("    └────────────────────────────┘\n");
	return 0;
}

int ShowTab(short int *tab){
	switch(*tab)
	{
	case 1:
		{
			PrintMenuHead();
			PrintMenuEdit();
			break;
		}
	case 2:
		{
			PrintMenuHead();
			PrintMenuStatics();
			break;
		}
	case 3:
		{
			PrintMenuHead();
			PrintMenuAccount();
			break;
		}
	}
	return 0;
}

int SwitchTab(short int *tab){
	if(*tab==3){
		*tab=1;
	}
	else{
		*tab+=1;
	}
	system("cls");
	ShowTab(tab);
	return 0;
}

int PrintShutDown(){
	system("cls");
	printf("\n");
	printf("感谢您使用本系统");
	return 0;
}

int PrintAuthor(){
	printf("\n");
	printf("    ┌─────────────────────────────┐\n");
	printf("    │ 大连理工大学疫情防控管理系统│\n");
	printf("    │      版本号 Version 1.0     │\n");
	printf("    │  白岩浩 电计2004 20201072017│\n");
	printf("    └─────────────────────────────┘\n");
	printf("\n");
	return 0;
}
