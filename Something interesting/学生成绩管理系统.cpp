#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct student
{
	char num[20];
	char name[12];
	int grade[8];
	int baocun;
}stu[60];

int k = 0, k1 = 0;
void input();
void outputgrade();
void change();
void del();
void allgrade();
void chaxun();
void show();
void tongji();

void main()
{
	printf("       *****************************\n");
	printf("       * 欢迎来到学生成绩管理系统! *\n");
	printf("       *****************************\n");
	int a;
	do
	{
		printf("\n");
		printf("----------------------------------------------\n");
		printf("----------------------------------------------\n\n");
		printf("        **************************\n");
		printf("        *   1.新增学生信息       *\n");
		printf("        *   2.显示学生信息       *\n");
		printf("        *   3.修改学生信息       *\n");
		printf("        *   4.删除学生信息       *\n");
		printf("        *   5.显示全班排名与总分 *\n");
		printf("        *   6.查询学生成绩       *\n");
		printf("        *   7.统计全班成绩       *\n");
		printf("        *   8.退出               *\n");
		printf("        **************************\n");

		printf("          请输入你要操作的序号:");
		scanf("%d", &a);
		printf("\n----------------------------------------------\n");

		switch (a)
		{
		case 1:printf("\n"); input(); break;
		case 2:printf("\n"); show(); break;
		case 3:printf("\n"); change(); break;
		case 4:printf("\n"); del(); break;
		case 5:printf("\n"); allgrade(); break;
		case 6:printf("\n"); chaxun(); break;
		case 7:printf("\n"); tongji(); break;
		case 8:printf("\n"); exit(0); break;
		default:printf("只能选择1至7选项\n");
		}
	} while (a != 0);
}


void show()         //显示学生信息
{
	int i;
	FILE *fpt;
	if ((fpt = fopen("grade.txt", "r")) == NULL)
	{
		printf("您还没有输入学生信息!\n");
		exit(0);
	}
	else
		for (k = 0; !feof(fpt); k++)   //从文件中读取学生信息
		{
			fscanf(fpt, "%s %s %d %d %d %d %d %d %d %d\n", &stu[k].num, &stu[k].name, &stu[k].grade[0], &stu[k].grade[1], &stu[k].grade[2], &stu[k].grade[3], &stu[k].grade[4], &stu[k].grade[5], &stu[k].grade[6], &stu[k].grade[7]);
		}
	for (int s = 0; s<k; s++)
	{
		stu[s].baocun = stu[s].grade[0] + stu[s].grade[1] + stu[s].grade[2] + stu[s].grade[3] + stu[s].grade[4] + stu[s].grade[5] + stu[s].grade[6] + stu[s].grade[7];
	}
	if (k1 == 0)
	{
		for (i = 0; i<k; i++)     //显示
		{
			printf("学号:%s 姓名:%s 高数:%d 英语:%d 制图:%d 测量学:%d c语言:%d 普地:%d 体育:%d 思修:%d\n", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]);
		}
		printf("\n");
	}
	fclose(fpt);
}

void input()       //新增学生信息
{
	k1 = 1; show(); int j; char ch[100];
	printf("\n输入学生信息:\n");
	do
	{
		printf("\n学号: ");
		scanf("%s", stu[k].num);
		printf("\n姓名: ");
		scanf("%s", stu[k].name);
		for (j = 0; j<8; j++)
		{
			printf("\n成绩%d: ", j + 1);
			scanf("%d", &stu[k].grade[j]);
		}
		k++;
		printf("\n如要继续，请输入学生信息(y/n): ");
		scanf("%s", ch);
	} while (strcmp(ch, "y") == 0);
	outputgrade();
}

void outputgrade()       //将新增或修改的信息录入文件
{
	int i;
	printf(" 学生信息是:\n");
	for (i = 0; i<k; i++)
	{
		printf("\t%s \t%s \t%d \t%d \t%d \t%d \t%d \t%d \t%d \t%d", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]);
		printf("\n");
	}
	FILE*fpt;
	fpt = fopen("grade.txt", "w");
	for (i = 0; i<k; i++)
	{
		fprintf(fpt, "\t%s \t%s \t%d \t%d \t%d \t%d \t%d \t%d \t%d \t%d", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]);
		fprintf(fpt, "\n");
	}
	fclose(fpt); k1 = 0;
}

void change()    //修改学生信息
{
	int i, j;
	char a[100], ch[100];
	printf("\n输入你要修改的学生学号:");
	scanf("%s", a);
	for (i = 0; i<k; i++)
	{
		if (strcmp(stu[i].num, a) == 0)
		{
			printf("\n你确定要修改学号吗？(y/n): ");
			scanf("%s", ch);
			if (strcmp(ch, "y") == 0) { printf("\nnum:"); scanf("%s", stu[i].num); }
			printf("\n你确定要修改学生姓名吗？(y/n): ");
			scanf("%s", ch);
			if (strcmp(ch, "y") == 0) { printf("\nname"); scanf("%s", stu[i].name); }
			printf("\n你确定要修改学生成绩吗？(y/n): ");
			scanf("%s", ch);
			printf("\n");
			if (strcmp(ch, "y") == 0)
			{
				for (j = 0; j<8; j++)
				{
					printf("grade%d:", j + 1);
					scanf("%d", &stu[i].grade[j]);
					printf("\n");
				}
			}
		}
	}
	outputgrade();
}

void del()          //删除学生信息
{
	int i, j;
	char c[100];
	printf("\n输入你要删除的学生学号 ：\n");
	printf("num：");
	scanf("%s", &c);
	for (i = 0; i<100; i++) if (strcmp(c, stu[i].num) == 0) break;
	for (j = i; j <= 9; j++) stu[j] = stu[j + 1];
	printf("\t\t\t你已经删除%s的信息\n", c);
	k--;
	outputgrade();
}

void allgrade()   //排序
{
	k1 = 1; show();
	int i, i1 = 1; float sum = 0; char ch[20];
	struct student temp;
	printf("优先按总分排名请按1\n\n查看高数排名请按2\n\n查看英语排名请按3\n\n查看制图排名请按4\n\n查看测量学排名请按5\n\n查看C语言排名请按6\n\n查看普地排名请按7\n\n查看体育排名请按8\n\n查看思修排名请按9\n\n");
	printf("\n请输入:"); scanf("%s", ch); printf("\n");
	if (strcmp(ch, "1") == 0 || strcmp(ch, "2") == 0 || strcmp(ch, "3") == 0 || strcmp(ch, "4") == 0 || strcmp(ch, "5") == 0 || strcmp(ch, "6") == 0 || strcmp(ch, "7") == 0 || strcmp(ch, "8") == 0 || strcmp(ch, "9") == 0)
	{
		if (strcmp(ch, "2") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[0]<stu[j + 1].grade[0])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,高数:%d\n", v + 1, stu[v].name, stu[v].grade[0]);
		}
		if (strcmp(ch, "3") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[1]<stu[j + 1].grade[1])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,英语:%d\n", v + 1, stu[v].name, stu[v].grade[1]);
		}
		if (strcmp(ch, "4") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[2]<stu[j + 1].grade[2])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,制图:%d\n", v + 1, stu[v].name, stu[v].grade[2]);
		}
		if (strcmp(ch, "5") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[3]<stu[j + 1].grade[3])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,测量学:%d\n", v + 1, stu[v].name, stu[v].grade[3]);
		}
		if (strcmp(ch, "6") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[4]<stu[j + 1].grade[4])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,C语言:%d\n", v + 1, stu[v].name, stu[v].grade[4]);
		}
		if (strcmp(ch, "7") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[5]<stu[j + 1].grade[5])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,普地:%d\n", v + 1, stu[v].name, stu[v].grade[5]);
		}
		if (strcmp(ch, "8") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[6]<stu[j + 1].grade[6])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,体育:%d\n", v + 1, stu[v].name, stu[v].grade[6]);
		}
		if (strcmp(ch, "9") == 0)
		{
			for (int i = 0; i<k - 1; i++)
			{
				for (int j = 0; j<k - 1 - i; j++)
				{
					if (stu[j].grade[7]<stu[j + 1].grade[7])
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,思修:%d\n", v + 1, stu[v].name, stu[v].grade[7]);
		}
		if (strcmp(ch, "1") == 0)     //按总分排序
		{
			for (int i4 = 0; i4<k - 1; i4++)
			{
				for (int j = 0; j<k - 1 - i4; j++)
				{
					if (stu[j].baocun<stu[j + 1].baocun)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
					if (stu[j].baocun == stu[j + 1].baocun)
					{
						if (stu[j].grade[0]<stu[j + 1].grade[0])
						{
							temp = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = temp;
						}
						if (stu[j].grade[0] == stu[j + 1].grade[0])
						{
							if (stu[j].grade[1]<stu[j + 1].grade[1])
							{
								temp = stu[j];
								stu[j] = stu[j + 1];
								stu[j + 1] = temp;
							}
							if (stu[j].grade[1] == stu[j + 1].grade[1])
							{
								if (stu[j].grade[2]<stu[j + 1].grade[2])
								{
									temp = stu[j];
									stu[j] = stu[j + 1];
									stu[j + 1] = temp;
								}
								if (stu[j].grade[2] == stu[j + 1].grade[2])
								{
									if (stu[j].grade[3]<stu[j + 1].grade[3])
									{
										temp = stu[j];
										stu[j] = stu[j + 1];
										stu[j + 1] = temp;
									}
									if (stu[j].grade[3] == stu[j + 1].grade[3])
									{
										if (stu[j].grade[4]<stu[j + 1].grade[4])
										{
											temp = stu[j];
											stu[j] = stu[j + 1];
											stu[j + 1] = temp;
										}
										if (stu[j].grade[4] == stu[j + 1].grade[4])
										{
											if (stu[j].grade[5]<stu[j + 1].grade[5])
											{
												temp = stu[j];
												stu[j] = stu[j + 1];
												stu[j + 1] = temp;
											}
											if (stu[j].grade[5] == stu[j + 1].grade[5])
											{
												if (stu[j].grade[6]<stu[j + 1].grade[6])
												{
													temp = stu[j];
													stu[j] = stu[j + 1];
													stu[j + 1] = temp;
												}
												if (stu[j].grade[6] == stu[j + 1].grade[6])
												{
													if (stu[j].grade[7]<stu[j + 1].grade[7])
													{
														temp = stu[j];
														stu[j] = stu[j + 1];
														stu[j + 1] = temp;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			for (int v = 0; v<k; v++) printf("第%d名是%s,总分:%d\n", v + 1, stu[v].name, stu[v].baocun);
		}
	}
	else printf("\n***请输入数字1-9!***\n");
	k1 = 0;
}

void chaxun()      //查询学生信息
{
	k1 = 1; show();
	char a[100], ch[100];
	printf("\n若按学号查询请按1,若按姓名查询请按2(暂不支持模糊搜索哦)\n\n");
	printf("请输入:"); scanf("%s", ch);
	if (strcmp(ch, "1") == 0 || strcmp(ch, "2") == 0)
	{
		if (strcmp(ch, "1") == 0)
		{
			printf("\n输入你要查询的学生学号:");
			scanf("%s", &a);
			for (int i = 0; i<100; i++)
			{
				if (strcmp(a, stu[i].num) == 0) { printf("\n学号:%s 姓名:%s 高数:%d 英语:%d 制图:%d 测量学:%d c语言:%d 普地:%d 体育:%d 思修:%d\n", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]); break; }
			}
		}
		if (strcmp(ch, "2") == 0)
		{
			printf("\n输入你要查询的学生姓名:");
			scanf("%s", &a);
			for (int i = 0; i<100; i++)
			{
				if (strcmp(a, stu[i].name) == 0) { printf("\n学号:%s 姓名:%s 高数:%d 英语:%d 制图:%d 测量学:%d C语言:%d 普地:%d 体育:%d 思修:%d\n", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]); break; }
			}
		}
	}
	else printf("没有该学生!");
	k1 = 0;
}

void tongji()       //统计全班成绩
{
	k1 = 1; show();
	float sum, hege, SD;
	for (int j = 0; j<8; j++)
	{
		sum = 0; hege = 0; SD = 0;
		for (int i = 0; i<k; i++)
		{
			sum = sum + stu[i].grade[j];
			if (stu[i].grade[j] >= 60) hege++;
		}
		for (int i1 = 0; i1<k; i1++)
		{
			SD = SD + (stu[i1].grade[j] - sum / k)*(stu[i1].grade[j] - sum / k);
		}
		SD = sqrt(SD / k);
		if (j == 0) printf("高数");
		if (j == 1) printf("英语");
		if (j == 2) printf("制图");
		if (j == 3) printf("测量学");
		if (j == 4) printf("C语言");
		if (j == 5) printf("普地");
		if (j == 6) printf("体育");
		if (j == 7) printf("思修");
		int hg = hege / k * 10000;
		printf("平均成绩:%f,合格率:%d.%d%%,标准差:%f\n\n", sum / k, hg / 100, hg - hg / 100 * 100, SD);
	}
	sum = 0; hege = 0; SD = 0;
	for (int i2 = 0; i2<k; i2++)
	{
		sum = sum + stu[i2].baocun;
		if (stu[i2].baocun >= 480) hege++;
	}
	for (int i3 = 0; i3<k; i3++)
	{
		SD = SD + (stu[i3].baocun - sum / k)*(stu[i3].baocun - sum / k);
	}
	SD = sqrt(SD / k);
	int totalscore = sum / k * 100; int hg = hege / k * 10000;
	printf("总分平均成绩:%d.%d,合格率:%d.%d%%,标准差:%f:", totalscore / 100, totalscore - totalscore / 100 * 100, hg / 100, hg - hg / 100 * 100, SD);
	k1 = 0;
}