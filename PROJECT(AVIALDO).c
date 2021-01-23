#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
struct student{
	char sname[30];
	char sid[30];
	char saddress[50];
	char snum[20];
	char sdep[10];
	char semail[30];
	char spass[30];
};
struct teacher{
	char tid[30];
	char tpass[30];
};
struct attendance{
char attendance[1];
int currentdate[13];
int currentdate1[13];	
};
struct subject{
char sub[10];
float marks;
};
struct announcement{
	char ann[90];
};
FILE *fpa;
FILE *fpa1;
FILE *fpt;
struct student st;
struct teacher t;
struct attendance a;
struct subject s;
void gotoxy(int x, int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}
void colorit(int);
void menu();
void admin();
void teacher();
void student();
void adminauthen();
void teacherauthen();
void studentauthen();
void incorrectadmin();
void incorrectteacher();
void incorrectstudent();
void addstudent();
void addteacher();
void viewstudent();
void viewstudent1();
void searchstudent();
void editstudent();
void editname(); 
void editaddress();
void editnum(); 
void editdep(); 
void editemail();
void editpass();
void deletestudent();
void markattendance();
void viewattendance();
void announcement();
void viewannouncement();
void addmarks();
void viewmarks();

void colorit(int col)
{                  
	HANDLE hstdout;
	hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
		                                //12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
    SetConsoleTextAttribute( hstdout, col );
}
 
void menu()             //MENU FUNCTION
{ system("cls");
 int pos=1,keypressed=0;
    int i,j;
	for(i=1;i<=20;++i)
	{
		gotoxy(30,i);
		colorit(15);
		for(j=1;j<=50;++j)
		{
		
		 if(j==1 || j==50 || i==1 || i==20)printf ("|");
		 else printf(" ");
	    }
	 //printf ("\n");
	}
	
	while(keypressed!=13)
	{            //LOOP WILL RUN UNTIL ENTER KEY (HAVING VALUE 13) IS PRESSED
	gotoxy(40,2);colorit(15);printf ("Welcome To A V I A L D O");
	gotoxy(40,3); printf ("========================");
	gotoxy(35,6);colorit(15);if(pos==1){colorit(10);}printf ("Login as an Admin");
	gotoxy(35,8);colorit(15);if(pos==2){colorit(10);}printf ("Login as a Teacher");
	gotoxy(35,10);colorit(15);if(pos==3){colorit(10);}printf ("Login as a Student");
	gotoxy(35,12);colorit(15);if(pos==4){colorit(10);}printf ("E x i t");
	keypressed = getch();
	if(keypressed==80)  //80 is the value for down key
	   {pos++;}
	if(keypressed==72)   //72 is the value of up key
	   {pos--;}            
	if(pos==5)pos=1; 
	if(pos==0)pos=4;
    }
   if(pos==1){system("cls");adminauthen();}
   if(pos==2){system ("cls");teacherauthen();}
   if(pos==3){system("cls");studentauthen();}
   if(pos==4){gotoxy(0,25);colorit(15);exit(0);system("cls");}
}
void admin() //admin block..
{
	int pos=1,keyp=0;
	
	while (keyp!=13)
	{
	if(keyp==8)
	{
	system("cls");	
    menu();
    }
	gotoxy(45,2);colorit(15);printf("Admin Portal");
	gotoxy(45,3);printf("------------");
	gotoxy(42,8);colorit(15);if(pos==1){colorit(10);}printf("Add Student Details");
	gotoxy(42,10);colorit(15);if(pos==2){colorit(10);}printf("View All Student Details");
	gotoxy(42,12);colorit(15);if(pos==3){colorit(10);}printf("Search Student Details");
	gotoxy(42,14);colorit(15);if(pos==4){colorit(10);}printf("Edit Student Details");
	gotoxy(42,16);colorit(15);if(pos==5){colorit(10);}printf("Delete Student Details");
	gotoxy(42,18);colorit(15);if(pos==6){colorit(10);}printf("Add Teacher Details");
    keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==7)pos=1;
	if(pos==0)pos=6;
	}
	if(pos==1){addstudent();}
	if(pos==2){viewstudent();}
	if(pos==3){searchstudent();}
	if(pos==4){editstudent();}
	if(pos==5){deletestudent();}
	if(pos==6){addteacher();}
}
void addstudent(){
	int pos=1,keyp=0;
	system("cls");
	fpa=fopen("student details.txt","a");
	gotoxy(45,8);colorit(15);printf("Enter Student Name :");colorit(8);scanf("%s",st.sname);fflush(stdin);
	gotoxy(45,10);colorit(15);printf("Enter Student I D:");colorit(8);scanf("%s",st.sid);
	gotoxy(45,12);colorit(15);printf("Enter Student Address:");colorit(8);scanf("%s",st.saddress);
	gotoxy(45,14);colorit(15);printf("Enter Student Number:");colorit(8);scanf("%s",st.snum);
	gotoxy(45,16);colorit(15);printf("Enter Student Department:");colorit(8);scanf("%s",st.sdep);
	gotoxy(45,18);colorit(15);printf("Enter Student Email:");colorit(8);scanf("%s",st.semail);
    gotoxy(45,20);colorit(15);printf("Enter Student Password:");colorit(8);scanf("%s",st.spass);
	fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);

	fclose(fpa);
	while(keyp!=13)
	{
		gotoxy(45,26);colorit(15);if(pos==1){colorit(12);}printf("Add One More Detail Of Student / Enroll a New Student");
	    gotoxy(45,27);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,28);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}

		if(pos==1){system("cls");addstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void addteacher()
{
		int pos=1,keyp=0;
	system("cls");
	fpt=fopen("teacher details.txt","a");
	gotoxy(45,10);colorit(15);printf("Enter Teacher I D:");colorit(8);scanf("%s",t.tid);
	gotoxy(45,12);colorit(15);printf("Enter Teacher Password:");colorit(8);scanf("%s",t.tpass);
	fprintf(fpt,"%s %s\n",t.tid,t.tpass);
    fclose(fpt);
	while(keyp!=13){
		gotoxy(45,26);colorit(15);if(pos==1){colorit(12);}printf("Add One More Teacher");
	    gotoxy(45,27);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,28);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==4)pos=1;
	if(pos==0)pos=3;
		}
		if(pos==1){system("cls");addteacher();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void viewstudent()
{
	int pos=1,keyp=0;
	system("cls");
	fpa=fopen("student details.txt","r");
    colorit(15);while(fscanf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
	colorit(15);printf("\nName : %s\nID : %s\nAddress : %s\nNumber : %s\nDepartment : %s\nEmail : %s\nPassword : %s\n\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
	fclose(fpa);
	while(keyp!=13){
	    gotoxy(45,27);colorit(15);if(pos==1){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,28);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==3)pos=1;
	if(pos==0)pos=2;
		}
		if(pos==1){system("cls");admin();}
		if(pos==2){system("cls");menu();}

}
void viewstudent1()
{
	int pos=1,keyp=0;
	system("cls");
	fpa=fopen("student details.txt","r");
    colorit(15);while(fscanf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
	colorit(15);printf("\nName : %s\nID : %s\nAddress : %s\nNumber : %s\nDepartment : %s\nEmail : %s\nPassword : %s\n\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
	fclose(fpa);
	while(keyp!=13){
	    gotoxy(45,27);colorit(15);if(pos==1){colorit(12);}printf("GO BACK TO TEACHER BLOCK");
		gotoxy(45,28);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==3)pos=1;
	if(pos==0)pos=2;
		}
		if(pos==1){system("cls");teacher();}
		if(pos==2){system("cls");menu();}
}
void searchstudent()
{
	int pos=1,keyp=0;
	char searchid[30];int flag=0;
	system("cls");
	gotoxy(45,3);colorit(15);printf("****Search Student By ID****");
	gotoxy(10,6);colorit(15);printf("Enter Student ID TO Search Students Record : ");colorit(8);scanf("%s",searchid);
	fpa=fopen("student details.txt","r");
	gotoxy(45,12);colorit(5);while(fscanf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,searchid)==0)
		{
			gotoxy(45,10);colorit(14);printf("R E C O R D   F O U N D");
			gotoxy(45,12);colorit(5);printf("\n\t\t\t\t\t\tName : %s\n\n\t\t\t\t\t\tID : %s\n\n\t\t\t\t\t\tAddress : %s\n\n\t\t\t\t\t\tNumber : %s\n\n\t\t\t\t\t\tDepartment : %s\n\n\t\t\t\t\t\tEmail : %s\n\n\t\t\t\t\t\tPassword : %s\n\n\t\t\t\t\t\t",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
			flag=1;
		}
	}
	if(flag==0)
	{gotoxy(45,18);colorit(1);printf("R E C O R D.N O T.F O U N D\a\a\a");}
    fclose(fpa);
    while(keyp!=13)
	{
		gotoxy(45,30);colorit(15);if(pos==1){colorit(12);}printf("SEARCH ANOTHER RECORD");
	    gotoxy(45,31);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,32);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");searchstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void editstudent()
{
	system("cls");
	int pos=1,keyp=0;
	while (keyp!=13)
	{
	gotoxy(45,2);colorit(15);printf("****Edit Student Details****");
	gotoxy(45,3);colorit(15);printf("____________________________");	
    gotoxy(15,9);colorit(15);if(pos==1){colorit(10);}printf("Edit Student Name");
	gotoxy(15,10);colorit(15);if(pos==2){colorit(10);}printf("Edit Student Address");
	gotoxy(15,11);colorit(15);if(pos==3){colorit(10);}printf("Edit Student Num");
	gotoxy(15,12);colorit(15);if(pos==4){colorit(10);}printf("Edit Student Department");
	gotoxy(15,13);colorit(15);if(pos==5){colorit(10);}printf("Edit Student Email");
	gotoxy(15,14);colorit(15);if(pos==6){colorit(10);}printf("Edit Student Password");

	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==7)pos=1;
	if(pos==0)pos=6;
	}
	if(pos==1){gotoxy(15,16);editname();}
	if(pos==2){gotoxy(15,16);editaddress();}
	if(pos==3){gotoxy(15,16);editnum();}
	if(pos==4){gotoxy(15,16);editdep();}
	if(pos==5){gotoxy(15,16);editemail();}
	if(pos==6){gotoxy(15,16);editpass();}
	
	
}
void editname()
{
	int pos=1,keyp=0;
	int flag=0;
	char sname1[30],sid1[30],saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Your ID :");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Name To EDIT :");colorit(8);scanf("%s",sname1);
	    fprintf(fpa1,"%s %s %s %s %s %s %s\n",sname1,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void editaddress()
{
	int pos=1,keyp=0;
	int flag=0;
	char sname1[30],sid1[30],saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Your ID :");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
	        gotoxy(15,18);colorit(15);printf("Enter Address To EDIT :");colorit(8);scanf("%s",saddress1);
	        fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,saddress1,st.snum,st.sdep,st.semail,st.spass);
	}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void editnum()
{
	int pos=1,keyp=0;
	int flag=0;
	char sname1[30],sid1[30],saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Your ID :");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Number To EDIT :");colorit(8);scanf("%s",snum1);
	    fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,snum1,st.sdep,st.semail,st.spass);
	}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void editdep()
{
	int flag=0;
	int pos=1,keyp=0;
	char sname1[30],sid1[30],saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Your ID :");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Department To EDIT :");colorit(8);scanf("%s",sdep1);
	    fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,sdep1,st.semail,st.spass);
	}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}	
}
void editemail()
{
	int flag=0;
	int pos=1,keyp=0;
	char sname1[30],sid1[30],saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Your ID :");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Email To EDIT :");colorit(8);scanf("%s",semail1);
	    fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,semail1,st.spass);
	}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void editpass()
{
	int flag=0;
	int pos=1,keyp=0;
	char sname1[30],sid1[30],saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Your ID :");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Password To EDIT :");colorit(8);scanf("%s",spass1);
	    fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,spass1);
	}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editstudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
}
void deletestudent()
{
	system("cls");
	int pos=1,keyp=0;
	int flag=0;
	char sid1[30];//,saddress1[50],snum1[20],sdep1[10],semail1[30],spass1[30];
	fpa=fopen("student details.txt","r");
	fpa1=fopen("temp.txt","a");
	gotoxy(45,2);colorit(15);printf("****DELETE STUDENT REDCORD****");
	gotoxy(45,3);colorit(15);printf("______________________________");
	gotoxy(15,6);colorit(15);printf("Enter Student ID Whose Record You Want To Delete:");colorit(8);scanf("%s",sid1);
	while(fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
	{
		if(strcmp(st.sid,sid1)==0)
		{
			flag=1;
			gotoxy(30,8);colorit(13);printf("R E C O R D..S U C C E S S F U L L Y.. D E L E T E D");
		}
	else
	{
	fprintf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
	}
}
if(flag==0){gotoxy(45,12);colorit(15);printf("Record Of student with ID : %s is not found",sid1);}
fclose(fpa);
fclose(fpa1);
fpa=fopen("student details.txt","w");
fclose(fpa);
fpa=fopen("student details.txt","a");
fpa1=fopen("temp.txt","r");
	while(fscanf(fpa1,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
		fprintf(fpa,"%s %s %s %s %s %s %s\n",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass);
}
fclose(fpa);
fclose(fpa1);
fpa=fopen("temp.txt","w");
fclose(fpa);
while(keyp!=13)
	{
		gotoxy(45,15);colorit(15);if(pos==1){colorit(12);}printf("DELETE ANOTHER RECORD");
	    gotoxy(45,16);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO ADMIN BLOCK");
		gotoxy(45,17);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");deletestudent();}
		if(pos==2){system("cls");admin();}
		if(pos==3){system("cls");menu();}
	
}
void teacher() // T E A C H E R_____B L O C K 
{
	
	int pos=1,keyp=0;
	while (keyp!=13)
	{
	if(keyp==8)
	{
		system("cls");
		menu();
	}
	gotoxy(45,2);colorit(15);printf("Teacher Portal");
	gotoxy(45,3);printf("--------------");
	gotoxy(43,8);colorit(15);if(pos==1){colorit(10);}printf("View Student Details");
	gotoxy(43,10);colorit(15);if(pos==2){colorit(10);}printf("Mark Student Attendance");
	gotoxy(43,12);colorit(15);if(pos==3){colorit(10);}printf("Enter Student Marks");
	gotoxy(43,14);colorit(15);if(pos==4){colorit(10);}printf("Make An Announcement");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==5)pos=1;
	if(pos==0)pos=4;
	}
	if(pos==1){system("cls");viewstudent1();}
	if(pos==2){system("cls");markattendance();}
	if(pos==3){system("cls");addmarks();}
	if(pos==4){system("cls");announcement();}
}
void markattendance()
{ 
system("cls");
FILE *fpa2;
FILE *fpa;
gotoxy(45,2);printf("MARK STUDENT ATTENDACNE");
gotoxy(45,3);printf("_______________________");

printf ("\n\n\nEnter Current date[dd/mm/yy]\t");scanf("%s",a.currentdate);
fpa2 = fopen("attendance.txt","a");	
fpa = fopen("student details.txt","r");
while (fscanf(fpa,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)		
{
printf ("\nName : %s\nID : %s\n\n",st.sname,st.sid);
printf ("Enter [p] for present OR [a] for absent........\t");scanf ("%s", a.attendance);
fprintf (fpa2,"Date : %s\nName : %s\nID : %s\nAttendance Status : %s\n\n",a.currentdate,st.sname,st.sid,a.attendance);
}
fclose(fpa);
fclose(fpa2);
int keyp=0,pos=1;
while(keyp!=13)
	{
		gotoxy(45,20);colorit(15);if(pos==1){colorit(12);}printf("MARK ANOTHER ATTENDANCE");
	    gotoxy(45,21);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO TEACHER BLOCK");
		gotoxy(45,22);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");markattendance();}
		if(pos==2){system("cls");teacher();}
		if(pos==3){system("cls");menu();}

}
void addmarks()
{system("cls"); 
FILE *fp2;
FILE *fp3;
fp2 = fopen("student details.txt", "r");
fp3 = fopen("marks.txt","a");
gotoxy(45,2);printf("ADDING MARKS");
gotoxy(45,3);printf("_____________\n\n");
while(fscanf(fp2,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
{
	printf ("\nName : %s\nID : %s\n\n",st.sname,st.sid);
	printf ("Enter Subject Name\t");
	scanf ("%s", s.sub);
	printf ("\nEnter Subject Marks\t");
	scanf ("%f", &s.marks);
	fprintf (fp3,"Name : %s\nID : %s\nSubject : %s\nSubject Marks : %.2f\n\n", st.sname,st.sid,s.sub,s.marks);
}
fclose(fp3);	
int keyp=0, pos=1;
while(keyp!=13)
	{
		gotoxy(45,15);colorit(15);if(pos==1){colorit(12);}printf("ADD MORE");
	    gotoxy(45,16);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO TEACHER BLOCK");
		gotoxy(45,17);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");addmarks();}
		if(pos==2){system("cls");teacher();}
		if(pos==3){system("cls");menu();}
}

void announcement()
{
	system("cls");
	FILE *fp;
	struct announcement r;
    gotoxy(45,2);colorit(15);printf("MAKING ANNOUNCEMENT");
    gotoxy(45,3);colorit(15);printf("___________________");
	fp=fopen("announcement.txt","a");
	colorit(15);printf("\n\n\nEnter Date [dd/mm/yy]\t");scanf("%s",a.currentdate1);fflush(stdin);
	colorit(15);printf("MAKE AN ANNOUNCEMENT FOR THE CLASS : ");scanf("%s",r.ann);
	fprintf(fp,"Date : %s\nAnnouncement : %s",a.currentdate1,r.ann);
	int keyp=0,pos=1;
while(keyp!=13)
	{
		gotoxy(45,20);colorit(15);if(pos==1){colorit(12);}printf("MAKE ANOTHER ANNOUNCEMENT");
	    gotoxy(45,21);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO TEACHER BLOCK");
		gotoxy(45,22);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");announcement();}
		if(pos==2){system("cls");teacher();}
		if(pos==3){system("cls");menu();}
}
void student()
{
	int pos=1,keyp=0;
	while (keyp!=13)   
	{
		if(keyp==8)
		{
			system("cls");
			menu();
		}
	gotoxy(45,2);colorit(15);printf("Student Portal");
	gotoxy(45,3);printf("--------------");
	gotoxy(43,8);colorit(15);if(pos==1){colorit(10);}printf("View Your Attendance");
	gotoxy(43,10);colorit(15);if(pos==2){colorit(10);}printf("View Your Marks");
	gotoxy(43,12);colorit(15);if(pos==3){colorit(10);}printf("View Announcements From Teacher");
	//gotoxy(20,16);arrowhere(5,pos);printf("Make An Announcment");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
    if(pos==4)pos=1;
    if(pos==0)pos=3;
	}
	if(pos==1){system("cls");viewattendance();}
	if(pos==2){system("cls");viewmarks();}
	if(pos==3){system("cls");viewannouncement();}
}

void viewannouncement()
{
	system("cls");
	FILE *fp;
	struct announcement r;
    gotoxy(45,2);colorit(15);printf("VIEWING ANNOUNCEMENT");
    gotoxy(45,3);colorit(15);printf("__________________\n\n\n");
	fp=fopen("announcement.txt","r");
	while(fscanf(fp,"Date : %s\nAnnouncement : %s",a.currentdate1,r.ann)!=EOF)
	{
		printf("DATE ON WHICH THE ANNOUNCEMENT WAS MADE : %s\n\n\n",a.currentdate1);
		printf("ANNOUNMENTS : %s",r.ann);
	}
	int keyp=0,pos=1;
    while(keyp!=13)
	{
	    gotoxy(45,21);colorit(15);if(pos==1){colorit(12);}printf("GO BACK TO STUDENT BLOCK");
		gotoxy(45,22);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==3)pos=1;
	    if(pos==0)pos=2;
	}
		if(pos==1){system("cls");student();}
		if(pos==2){system("cls");menu();}
}
void viewmarks()
{ system("cls"); 
FILE *fpa2;
char id[15];
fpa2 = fopen("marks.txt","r");
gotoxy(45,2);printf("VIEWING MARKS");
gotoxy(45,3);printf("_____________\n\n");
printf ("Enter Your ID to View the Marks : \t");
scanf ("%s", id);
while (fscanf(fpa2,"Name : %s\nID : %s\nSubject : %s\nSubject Marks : %f\n\n", st.sname,st.sid,s.sub,&s.marks)!=EOF)
{
if (strcmp(id,st.sid)==0)
printf ("\nName : %s\nID : %s\nSubject : %s\nSubject Marks : %.2f\n\n", st.sname,st.sid,s.sub,s.marks);
	
}	
fclose(fpa2);
int keyp=0, pos=1;
while(keyp!=13)
	{
		gotoxy(45,15);colorit(15);if(pos==1){colorit(12);}printf("VIEW MORE");
	    gotoxy(45,16);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO STUDENT BLOCK");
		gotoxy(45,17);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");viewmarks();}
		if(pos==2){system("cls");student();}
		if(pos==3){system("cls");menu();}
	
}	
void viewattendance()
{
	system("cls");
	FILE *fpa2;
	char id[20];
	int keyp=0,pos=1;
	gotoxy(45,2);printf("VIEW ATTENDANCE");
	gotoxy(45,3);printf("_______________");
    fpa2= fopen("attendance.txt","r");
    gotoxy(15,5);printf ("Enter ID to search\t");scanf ("%s",id);
    while(fscanf(fpa2,"Date : %s\nName : %s\nID : %s\nAttendance Status : %s\n\n",a.currentdate,st.sname,st.sid,a.attendance)!=EOF)
  {   if(strcmp(id,st.sid)==0)
	 printf("\n\n\nDate : %s\nName : %s\nID : %s\nAttendance Status : %s\n\n",a.currentdate,st.sname,st.sid,a.attendance);
  }
  fclose(fpa2);
  while(keyp!=13)
	{
		gotoxy(45,10);colorit(15);if(pos==1){colorit(12);}printf("VIEW MORE ATTENDANCE");
	    gotoxy(45,11);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO STUDENT BLOCK");
		gotoxy(45,12);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN MENU BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");viewattendance();}
		if(pos==2){system("cls");student();}
		if(pos==3){system("cls");menu();}
}
void adminauthen()
{
  FILE *fpa;
  fpa= fopen ("admin.txt", "r");
  char aID[20],aPass[20],ch,characpos=0,admin1[20],pass[20];  //aID and aPass are in the file and admin1 and pass are storing strings from file	
  gotoxy(40,2); printf ("***Authentication Required***");	
  gotoxy(35,6);printf ("Enter Admin ID : ");fflush(stdin);colorit(8);gets(aID);
  gotoxy(35,8);colorit(15);printf ("Enter Password : ");colorit(8);
    while (1)
{                                       //INFINITE LOOP (WILL TERMINATE ACCORDING TO THE CONDITIONS)
	ch=getch();
	if (ch==13)                                  //BY PRESSING THE ENTER KEY LOOP WILL TERMINATE
	break;
	else if (ch==8)
	{                              //BACKSPACE TO REMOVE A CHARACTER
	if(characpos>0)	
	{                             //BACKSPACE THE CHARACTERS UNTIL THE INDEX NUMBER IS GREATER THAN 0 
	characpos--;
	aPass[characpos]='\0';                        //PRINTING NULL CHARACTER AT THAT CHARACTER POSITION WHICH WE WANT TO REMOVE
	printf ("\b \b");
	}                            //TO BRING THE CURSOR BACKWARD
}   
    else {
	aPass[characpos]= ch;
	characpos++;
	printf ("*");}                               //MASKING THE PASSWORD
}
   aPass[characpos] = '\0';   //TERMINATING THE STRING
   fscanf (fpa,"%s", &admin1);
   fscanf (fpa,"%s", &pass);

   if (strcmp(aID,admin1)==0 && strcmp(aPass,pass)==0)
   {
   system("cls");
    admin();
    }
else incorrectadmin();
fclose(fpa);
}
void teacherauthen()
{ 
    int flag=0;
	char tid1[30],tpass1[30],ch,characpos=0;
	gotoxy(40,2); printf ("***Authentication Required***");
    gotoxy(35,8);printf ("Enter Teacher ID : ");fflush(stdin);colorit(8);scanf("%s",tid1);
    gotoxy(35,10);colorit(15);printf ("Enter Password : ");colorit(8);
	while (1)
{                                   //INFINITE LOOP (WILL TERMINATE ACCORDING TO THE CONDITIONS)
	ch=getch();
	if (ch==13)                                  //BY PRESSING THE ENTER KEY LOOP WILL TERMINATE
	break;
	else if (ch==8)
	{                              //BACKSPACE TO REMOVE A CHARACTER
	if(characpos>0)	
	{                             //BACKSPACE THE CHARACTERS UNTIL THE INDEX NUMBER IS GREATER THAN 0 
	characpos--;
	tpass1[characpos]='\0';                        //PRINTING NULL CHARACTER AT THAT CHARACTER POSITION WHICH WE WANT TO REMOVE
	printf ("\b \b");
	}                            //TO BRING THE CURSOR BACKWARD
}   
    else {
	tpass1[characpos]= ch;
	characpos++;
	printf ("*");}                               //MASKING THE PASSWORD
}
    tpass1[characpos] = '\0';   //TERMINATING THE STRING
    fpt=fopen("teacher details.txt","r");
    while(fscanf(fpt,"%s %s",t.tid,t.tpass)!=EOF)
    {
    	if(strcmp(t.tid,tid1)==0 && strcmp(t.tpass,tpass1)==0)
    	{
            flag=1;
		}
	}
	if (flag==1) {system("cls"); teacher();}
	else incorrectteacher();
    fclose(fpt);
}
void studentauthen()
{
	FILE *fptr;
	int flag=0;
	char sid1[30],spass1[30],ch,characpos=0;
	gotoxy(40,2); printf ("***Authentication Required***");
    gotoxy(35,8);printf ("Enter Student ID : ");fflush(stdin);colorit(8);scanf("%s",sid1);
    gotoxy(35,10);colorit(15);printf ("Enter Password : ");colorit(8);
	while(1)
{                                       //INFINITE LOOP (WILL TERMINATE ACCORDING TO THE CONDITIONS)
	ch=getch();
	if (ch==13)                                  //BY PRESSING THE ENTER KEY LOOP WILL TERMINATE
	break;
	else if (ch==8)
	{                              //BACKSPACE TO REMOVE A CHARACTER
	if(characpos>0)	
	{                             //BACKSPACE THE CHARACTERS UNTIL THE INDEX NUMBER IS GREATER THAN 0 
	characpos--;
	spass1[characpos]='\0';                        //PRINTING NULL CHARACTER AT THAT CHARACTER POSITION WHICH WE WANT TO REMOVE
	printf ("\b \b");
	}                            //TO BRING THE CURSOR BACKWARD
}   
    else {
	spass1[characpos]= ch;
	characpos++;
	printf ("*");}                               //MASKING THE PASSWORD
}
    spass1[characpos] = '\0';   //TERMINATING THE STRING
    fptr=fopen("student details.txt","r");
    while(fscanf(fptr,"%s %s %s %s %s %s %s",st.sname,st.sid,st.saddress,st.snum,st.sdep,st.semail,st.spass)!=EOF)
    {
    	if(strcmp(st.sid,sid1)==0 && strcmp(st.spass,spass1)==0)
    	{
            flag=1;
		}
	}
	if (flag==1) {system("cls"); student();}
	else incorrectstudent();
    fclose(fptr);
}
void incorrectadmin()
{
	int pos=1,keyp=0;
	gotoxy(37,12);colorit(15);{colorit(12);}printf ("Username or Password is Incorrect");
	while(keyp!=13){
	gotoxy(47,15);colorit(15);if(pos==1){colorit(13);}printf ("Try Again");
	gotoxy(44,16);colorit(15);if(pos==2){colorit(13);}printf ("GO BACK TO MENU");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--; 
	if(pos==3)pos=1;
	if(pos==0)pos=2;
	}
	if(pos==1){
	system("cls");
	colorit(15);adminauthen();}
	if(pos==2){
		system("cls");
		colorit(15);menu();
	}
}
void incorrectteacher()
{
	int pos=1,keyp=0;
	gotoxy(37,12);colorit(15);{colorit(12);}printf ("Username or Password is Incorrect");
	while(keyp!=13){
	gotoxy(47,15);colorit(15);if(pos==1){colorit(13);}printf ("Try Again");
	gotoxy(44,16);colorit(15);if(pos==2){colorit(13);}printf ("GO BACK TO MENU");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--; 
	if(pos==3)pos=1;
	if(pos==0)pos=2;}
	if(pos==1){system("cls");colorit(15);teacherauthen();}
	if(pos==2){system("cls");colorit(15);menu();}
}
void incorrectstudent()
{
	int pos=1,keyp=0;
	gotoxy(37,12);colorit(15);{colorit(12);}printf ("Username or Password is Incorrect");
	while(keyp!=13){
	gotoxy(47,15);colorit(15);if(pos==1){colorit(13);}printf ("Try Again");
	gotoxy(44,16);colorit(15);if(pos==2){colorit(13);}printf ("GO BACK TO MENU");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--; 
	if(pos==3)pos=1;
	if(pos==0)pos=2;}
	if(pos==1){system("cls");colorit(15);studentauthen();}
	if(pos==2){system("cls");colorit(15);menu();}
}
main()
{
    menu();
    system ("cls");
}


