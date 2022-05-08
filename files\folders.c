#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int get_file_attrib();

void main(int argc, char const *argv[])
{
	char ch,FN[128];
	int attrib;
	short int i,t=1;
	char str[]={"ENTER YOUR CHOICE + PRESS ENTER"};

	//while(t){

	printf("\033[2J"); //clear screen
	printf("\033[0;32m#FILE/FOLDER PROTECTION SOFTWARE\033[0m\n");
	printf("\033[0;32m --------S-----E-----T--------- \033[0m\n");
	printf("\033[0;32m1:WRITE AND READ A FILE/FOLDER \033[0m\n");
	printf("\033[0;32m2:PROTECT A FILE/FOLDER \033[0m\n");
	printf("\033[0;32m3:HELP \033[0m\n");
	printf("\033[0;32mESC: exit\033[0m\n");
	for (int i = 0; i < sizeof(str); ++i)
	{
		printf("\033[0;32m%c\033[0m", str[i]);
		usleep(50000); // <unistd.h>
	}
	printf("\n");
	
	
	ch = getchar(); // 

	if(ch==27){
		exit(1);
		t=0;
	}

	switch(ch){

		case '1':

		printf("\033[2J");
		printf("\033[0;32m ______________________________________ \033[0m\n");
		printf("\033[0;32mEnter the file/folder with correct path!\033[0m\n");
		printf("$ ");

		scanf("%s",FN);
		i=1;
		attrib = get_file_attrib(FN,i);

		printf("\033[2J");
		if (attrib==-1) printf("\033[0;32mWrong way or access denied\033[0m\n");
		else printf("\033[0;32mOperation executed successfully\033[0m\n");
		getchar();

		break;

		case '2':

		printf("\033[2J");
		printf("\033[0;32m ______________________________________ \033[0m\n");
		printf("\033[0;32mEnter the file/folder with correct path!\033[0m\n");
		printf("$ ");

		scanf("%s",FN);
		i=0;
		attrib = get_file_attrib(FN,i);

		printf("\033[2J");
		if (attrib==-1) printf("\033[0;32mWrong way or access denied\033[0m\n");
		else printf("\033[0;32mOperation executed successfully\033[0m\n");
		getchar();

		break;

		case '3':

		printf("\033[0;32mEnter the file/folder with correct path!\033[0m\n");
		printf("\033[0;32mExample: /home/user/example.txt\033[0m\n");
		getchar();

		break;

		default: printf("\033[2J");
		printf("\033[0;32mPLEASE INPUT CORRECT CHOICE!\033[0m\n");
		getchar();

		break;
	}



	//}

}

int get_file_attrib(char* FN,short int* i){

int tmp=-1;

if (chmod(FN,-1)!=-1){
if (i)  chmod(FN,-1); //S_IREAD|S_IWRITE
else chmod(FN,1);
tmp = 0;
}


return (tmp);
}