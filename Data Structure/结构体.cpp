#include<string>
#include<iostream>
using namespace std;

struct student {
	int iNum;
	char cName[16];
	float fChineseScore;
	float fMathScore;
	float fEnglishScore;
};
typedef struct student STUDENT;

void DisplayTranscript() {
	STUDENT sTranscript[] = { { 1001,"ZS",69.5,61.5,91.5 },
	{ 1002,"LI",92.5,67.5,81.5 },
	{ 1003,"GJ",79.5,67.5,86.5 } };
	STUDENT *pStu = sTranscript;
	int i;
	printf("No. Name Chinese Math English\n");
	for (i = 0; i<sizeof(sTranscript) / sizeof(STUDENT); i++) {
		printf("%4d %s %6.1f %6.1f%6.1f\n",
			pStu[i].iNum, pStu[i].cName, pStu[i].fChineseScore, pStu[i].fMathScore, pStu[i].fEnglishScore);
	}

}


int main()
{
	DisplayTranscript();
    return 0;
}