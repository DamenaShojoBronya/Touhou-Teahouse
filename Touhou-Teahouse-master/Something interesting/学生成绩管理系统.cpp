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
	printf("       * ��ӭ����ѧ���ɼ�����ϵͳ! *\n");
	printf("       *****************************\n");
	int a;
	do
	{
		printf("\n");
		printf("----------------------------------------------\n");
		printf("----------------------------------------------\n\n");
		printf("        **************************\n");
		printf("        *   1.����ѧ����Ϣ       *\n");
		printf("        *   2.��ʾѧ����Ϣ       *\n");
		printf("        *   3.�޸�ѧ����Ϣ       *\n");
		printf("        *   4.ɾ��ѧ����Ϣ       *\n");
		printf("        *   5.��ʾȫ���������ܷ� *\n");
		printf("        *   6.��ѯѧ���ɼ�       *\n");
		printf("        *   7.ͳ��ȫ��ɼ�       *\n");
		printf("        *   8.�˳�               *\n");
		printf("        **************************\n");

		printf("          ��������Ҫ���������:");
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
		default:printf("ֻ��ѡ��1��7ѡ��\n");
		}
	} while (a != 0);
}


void show()         //��ʾѧ����Ϣ
{
	int i;
	FILE *fpt;
	if ((fpt = fopen("grade.txt", "r")) == NULL)
	{
		printf("����û������ѧ����Ϣ!\n");
		exit(0);
	}
	else
		for (k = 0; !feof(fpt); k++)   //���ļ��ж�ȡѧ����Ϣ
		{
			fscanf(fpt, "%s %s %d %d %d %d %d %d %d %d\n", &stu[k].num, &stu[k].name, &stu[k].grade[0], &stu[k].grade[1], &stu[k].grade[2], &stu[k].grade[3], &stu[k].grade[4], &stu[k].grade[5], &stu[k].grade[6], &stu[k].grade[7]);
		}
	for (int s = 0; s<k; s++)
	{
		stu[s].baocun = stu[s].grade[0] + stu[s].grade[1] + stu[s].grade[2] + stu[s].grade[3] + stu[s].grade[4] + stu[s].grade[5] + stu[s].grade[6] + stu[s].grade[7];
	}
	if (k1 == 0)
	{
		for (i = 0; i<k; i++)     //��ʾ
		{
			printf("ѧ��:%s ����:%s ����:%d Ӣ��:%d ��ͼ:%d ����ѧ:%d c����:%d �յ�:%d ����:%d ˼��:%d\n", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]);
		}
		printf("\n");
	}
	fclose(fpt);
}

void input()       //����ѧ����Ϣ
{
	k1 = 1; show(); int j; char ch[100];
	printf("\n����ѧ����Ϣ:\n");
	do
	{
		printf("\nѧ��: ");
		scanf("%s", stu[k].num);
		printf("\n����: ");
		scanf("%s", stu[k].name);
		for (j = 0; j<8; j++)
		{
			printf("\n�ɼ�%d: ", j + 1);
			scanf("%d", &stu[k].grade[j]);
		}
		k++;
		printf("\n��Ҫ������������ѧ����Ϣ(y/n): ");
		scanf("%s", ch);
	} while (strcmp(ch, "y") == 0);
	outputgrade();
}

void outputgrade()       //���������޸ĵ���Ϣ¼���ļ�
{
	int i;
	printf(" ѧ����Ϣ��:\n");
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

void change()    //�޸�ѧ����Ϣ
{
	int i, j;
	char a[100], ch[100];
	printf("\n������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s", a);
	for (i = 0; i<k; i++)
	{
		if (strcmp(stu[i].num, a) == 0)
		{
			printf("\n��ȷ��Ҫ�޸�ѧ����(y/n): ");
			scanf("%s", ch);
			if (strcmp(ch, "y") == 0) { printf("\nnum:"); scanf("%s", stu[i].num); }
			printf("\n��ȷ��Ҫ�޸�ѧ��������(y/n): ");
			scanf("%s", ch);
			if (strcmp(ch, "y") == 0) { printf("\nname"); scanf("%s", stu[i].name); }
			printf("\n��ȷ��Ҫ�޸�ѧ���ɼ���(y/n): ");
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

void del()          //ɾ��ѧ����Ϣ
{
	int i, j;
	char c[100];
	printf("\n������Ҫɾ����ѧ��ѧ�� ��\n");
	printf("num��");
	scanf("%s", &c);
	for (i = 0; i<100; i++) if (strcmp(c, stu[i].num) == 0) break;
	for (j = i; j <= 9; j++) stu[j] = stu[j + 1];
	printf("\t\t\t���Ѿ�ɾ��%s����Ϣ\n", c);
	k--;
	outputgrade();
}

void allgrade()   //����
{
	k1 = 1; show();
	int i, i1 = 1; float sum = 0; char ch[20];
	struct student temp;
	printf("���Ȱ��ܷ������밴1\n\n�鿴���������밴2\n\n�鿴Ӣ�������밴3\n\n�鿴��ͼ�����밴4\n\n�鿴����ѧ�����밴5\n\n�鿴C���������밴6\n\n�鿴�յ������밴7\n\n�鿴���������밴8\n\n�鿴˼�������밴9\n\n");
	printf("\n������:"); scanf("%s", ch); printf("\n");
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
			for (int v = 0; v<k; v++) printf("��%d����%s,����:%d\n", v + 1, stu[v].name, stu[v].grade[0]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,Ӣ��:%d\n", v + 1, stu[v].name, stu[v].grade[1]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,��ͼ:%d\n", v + 1, stu[v].name, stu[v].grade[2]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,����ѧ:%d\n", v + 1, stu[v].name, stu[v].grade[3]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,C����:%d\n", v + 1, stu[v].name, stu[v].grade[4]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,�յ�:%d\n", v + 1, stu[v].name, stu[v].grade[5]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,����:%d\n", v + 1, stu[v].name, stu[v].grade[6]);
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
			for (int v = 0; v<k; v++) printf("��%d����%s,˼��:%d\n", v + 1, stu[v].name, stu[v].grade[7]);
		}
		if (strcmp(ch, "1") == 0)     //���ܷ�����
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
			for (int v = 0; v<k; v++) printf("��%d����%s,�ܷ�:%d\n", v + 1, stu[v].name, stu[v].baocun);
		}
	}
	else printf("\n***����������1-9!***\n");
	k1 = 0;
}

void chaxun()      //��ѯѧ����Ϣ
{
	k1 = 1; show();
	char a[100], ch[100];
	printf("\n����ѧ�Ų�ѯ�밴1,����������ѯ�밴2(�ݲ�֧��ģ������Ŷ)\n\n");
	printf("������:"); scanf("%s", ch);
	if (strcmp(ch, "1") == 0 || strcmp(ch, "2") == 0)
	{
		if (strcmp(ch, "1") == 0)
		{
			printf("\n������Ҫ��ѯ��ѧ��ѧ��:");
			scanf("%s", &a);
			for (int i = 0; i<100; i++)
			{
				if (strcmp(a, stu[i].num) == 0) { printf("\nѧ��:%s ����:%s ����:%d Ӣ��:%d ��ͼ:%d ����ѧ:%d c����:%d �յ�:%d ����:%d ˼��:%d\n", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]); break; }
			}
		}
		if (strcmp(ch, "2") == 0)
		{
			printf("\n������Ҫ��ѯ��ѧ������:");
			scanf("%s", &a);
			for (int i = 0; i<100; i++)
			{
				if (strcmp(a, stu[i].name) == 0) { printf("\nѧ��:%s ����:%s ����:%d Ӣ��:%d ��ͼ:%d ����ѧ:%d C����:%d �յ�:%d ����:%d ˼��:%d\n", stu[i].num, stu[i].name, stu[i].grade[0], stu[i].grade[1], stu[i].grade[2], stu[i].grade[3], stu[i].grade[4], stu[i].grade[5], stu[i].grade[6], stu[i].grade[7]); break; }
			}
		}
	}
	else printf("û�и�ѧ��!");
	k1 = 0;
}

void tongji()       //ͳ��ȫ��ɼ�
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
		if (j == 0) printf("����");
		if (j == 1) printf("Ӣ��");
		if (j == 2) printf("��ͼ");
		if (j == 3) printf("����ѧ");
		if (j == 4) printf("C����");
		if (j == 5) printf("�յ�");
		if (j == 6) printf("����");
		if (j == 7) printf("˼��");
		int hg = hege / k * 10000;
		printf("ƽ���ɼ�:%f,�ϸ���:%d.%d%%,��׼��:%f\n\n", sum / k, hg / 100, hg - hg / 100 * 100, SD);
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
	printf("�ܷ�ƽ���ɼ�:%d.%d,�ϸ���:%d.%d%%,��׼��:%f:", totalscore / 100, totalscore - totalscore / 100 * 100, hg / 100, hg - hg / 100 * 100, SD);
	k1 = 0;
}