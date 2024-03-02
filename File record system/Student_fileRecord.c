#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void addstudent ( );
void studentrecord ( );
void searchstudent ( );
void delete ( );

struct student{
	char first_name[25];
	char last_name[25];
	char class[10], vill[20];
	int roll_no;
	float per;
};


int main ( ){
	system("color blue");
	int choice;
	while (choice!=5){
		printf("\tSIMPLE DATA BASE");
		printf("\n\t1. Add Student\n");
		printf("\t2. Student Record\n");
		printf("\t3. Search Student\n");
		printf("\t4. Delete Student\n");
		printf("\t5. Exit Student\n");
		scanf("%d", &choice);
	switch (choice){
		case 1: 
		clrscr();
		addstudent();
		clrscr();
		break;
		
		case 2: 
		clrscr();
		studentrecord();
		printf("press any key to exit");
		getch();
		clrscr();
		break;
		
		case 3: 
		clrscr();
		searchstudent();
		printf("press any key to exit");
		getch();
		clrscr();
		break;
		
		case 4: 
		clrscr();
		delete ();
		printf("press any key to exit");
		getch();
		clrscr();
		break;
	}
	}
	return 0;
}

void addstudent ( ){
	char another;
	FILE *fp;
	struct student info;
	do {
		clrscr();
		printf("\t====Add student====");
		fp=fopen("student_info","a");
		printf("\n\tEnter first name: ");
		scanf("%s",&info.first_name);
		printf("\tEnter last name: ");
		scanf("%s",&info.last_name);
		printf("\tEnter roll no: ");
		scanf("%d",&info.roll_no);
		printf("\tEnter class: ");
		scanf("%s",&info.class);
		printf("\tEnter address: ");
		scanf("%s",&info.vill);
		printf("\tEnter percentage: ");
		scanf("%f",&info.per);
		printf("________________________\n");
		if(fp==NULL){
			fprintf(stderr,"can't open file");
		}else{
			printf("Record stored successfully");
	}
	fwrite(&info, sizeof(struct student),1,fp);
	fclose(fp);
	printf("Do you want to add another record? (y/n): ");
	scanf("%s", &another);
	}
	while (another=='y' || another=='Y');
}

void studentrecord ( ){
	
	FILE *fp;
	struct student info;
	fp=fopen("student_info","r");
	printf("\t====student record====\n");
	if (fp==NULL){
		fprintf(stderr,"can't open file");
		}else{
			printf("\tRecord\n");
printf("\n___________________________\n");
	}
	while (fread (&info,sizeof(struct student),1,fp)){
		printf("\nStudent name: %s %s", info.first_name, info.last_name);
 	   printf("\nroll no	: %d", info.roll_no);
 	   printf("\nclass	  : %s", info.class);
 	   printf("\nAdress   : %s", info.vill);
 	   printf("\npercentage	: %f", info.per);
 	   printf("\n___________________________\n");
		}
		fclose (fp);
		getch( );
}


void searchstudent ( ){
	FILE *fp;
	struct student info;
	int roll_no, found=0;
	fp=fopen("student_info", "r");
	printf("======search student========");
	printf("\nEnter roll no : ");
	scanf("%d", &roll_no);
	while (fread (&info,sizeof(struct student),1,fp)){
		if (info.roll_no==roll_no){
			found=1;
		printf("\nStudent name: %s %s", info.first_name, info.last_name);
 	   printf("\nroll no	: %d", info.roll_no);
 	   printf("\nclass	  : %s", info.class);
 	   printf("\nAdress   : %s", info.vill);
 	   printf("\npercentage	: %f", info.per);
 	   printf("\n___________________________\n");
		} if (!found){
			printf("\nrecord not found\n");
	}
		fclose (fp);
		getch( );
}
}

void delete ( ){
	FILE *fp , *fp1;
	struct student info;
	int roll_no, found=0;
	printf("\t======Delete========");
	fp=fopen("student_info", "r");
	fp1=fopen("temp.txt","w");
	printf("\n Enter roll no:   ");
	scanf("%d", &roll_no);
	if (fp==NULL){
		fprintf(stderr,"can't open file");
	}
	while (fread (&info,sizeof(struct student),1,fp)){
		if (info.roll_no==roll_no){
			found=1;
		}else {
			fwrite(&info, sizeof(struct student),1,fp1);
		}
			
			}
			fclose(fp);
			fclose(fp1);
if (found){
	remove("student_info");
	rename("temp.txt", "student_info");
	printf("\nrecord deleted successfully");
}
	if (!found){
		printf("record not found");
	}
	getch();
}
