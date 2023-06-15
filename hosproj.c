#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define rw 80
#define cl 50

FILE*fp,*fp1,*f1,*f2;
int s,z;
char fn1[]="opd12.txt";
char fn2[]="oopd12.txt";

struct hospital{
		char name[20],address[20],ch;
		int age,roomno,sn;
		char disease[30],department[20],date[15];
		char recommendation[50],category[30];
		char test[15][20];
		float testfee[15];
		float totalfee;
		float balance;
		}p,q;

char string[20];
int cid;

typedef struct hospital alka;
void newrecord(int l);
void print();
void displaytest();
void mainscreen();
void newrecord1();
void displaydepartment();
void edit1();
void editrecord();
void switch1();
void about();

void main()
{
	int a,i,n,y;
	char c,d;
	char date1[15],date2[15],string1[20];
	unsigned int tsz;

	clrscr();
	mainscreen();
	label3:
	textcolor(3);
	gotoxy(25,19);
	cprintf("Enter today's Date(yyyy/mm/dd)");
	fflush(stdin);gotoxy(28,21);
	scanf("%[^\n]",date2);
	if((date2[4]!='/')||(date2[7]!='/')||(date2[5]>'3')||(date2[8]>'3'))
	{
		clrscr();
		mainscreen();
		gotoxy(23,13);textcolor(4+128);
		cprintf("Wrong Entry");
		goto label3;
	}
	clrscr();
	mainscreen();
	label1:

	textcolor(15);
	lowvideo();gotoxy(25,8);textcolor(14);
	cprintf("Enter the corresponding no");gotoxy(25,10);textcolor(10);
	cprintf("1.Add new patient record");gotoxy(25,12);
	cprintf("2.Edit patient record");gotoxy(25,14);
	cprintf("3.Know the records of patients");gotoxy(25,16);
	cprintf("4.Delete the records");gotoxy(25,18);
	cprintf("5.About us");gotoxy(25,20);
	cprintf("6.Exit from the program");gotoxy(25,22);
	fflush(stdin);
	scanf("%c",&d);
	switch(d)
	{
		case '1':
		      {

			{
				if((fp=fopen(fn1,"rb"))==NULL)
				s=1;
				else
				{
				while(fread(&p,sizeof(alka),1,fp))
				s=1+p.sn;
				}
				fclose(fp);
			}
			clrscr();
			mainscreen();
			label:
			gotoxy(22,14);textcolor(7);
			cprintf("Enter `o' for O.P.D. & `e'for Emergency");
			gotoxy(35,21);
			fflush(stdin);
			scanf("%c",&c);
			if(c=='o')
			{
				clrscr();
				mainscreen();
				textcolor(11);gotoxy(25,6);
				cprintf("ADDING NEW O.P.D.PATIENT RECORD");textcolor(15);
				newrecord(s);
				newrecord1();

				if((fp=fopen(fn1,"ab+"))==NULL)
				{
					printf("Cannot open the file f1");
					getch();
					exit(1);
				}
				for(a=0;a<15;a++)
				p.testfee[a]=0;
				strcpy(&p.test[1][0],"0");
				p.totalfee=0;p.balance=0;
				strcpy(&p.test[0][0],"O.P.D. charge");
				p.testfee[0]=200;

				p.totalfee=200;
				strcpy(p.category,"O.P.D.Patient");
				p.balance=200;
				strcpy(p.recommendation,"Admitted to O.P.D.");
				strcat(p.recommendation," -> ");
			    strcat(p.recommendation,p.disease);
				strcpy(p.date,date2);
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);
				if((fp=fopen(fn2,"ab+"))==NULL)
				{
						printf("Cannot open the file f1");
						getch();
						exit(1);
				}
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);


			}
			else if(c=='e')
			       {
				 clrscr();
				 mainscreen();
				 textcolor(11);
				 gotoxy(25,8);
				 cprintf("ADDING NEW EMERGENCY PATIENT RECORD");
				 textcolor(15);
				 newrecord(s);
				 newrecord1();
				 if((fp=fopen(fn1,"ab+"))==NULL)
					{
						printf("Cannot open the file f1");
						getch();
						exit(1);
					}
					for(a=0;a<15;a++)
					p.testfee[a]=0;
					strcpy(&p.test[1][0],"0");
					p.totalfee=0;p.balance=0;

			       p.totalfee=250;
			       strcpy(p.date,date2);
			       strcpy(&p.test[0][0],"Emergency Charge");
			       strcpy(p.category,"Emergency Patient");
			       strcpy(p.recommendation,"Admitted to Emergency");
				   strcat(p.recommendation," -> ");
			       strcat(p.recommendation,p.disease);
			       p.testfee[0]=250;
			       p.balance=250;
			       fwrite(&p,sizeof(p),1,fp);
			       fclose(fp);
			      if((fp=fopen(fn2,"ab+"))==NULL)
				{
						printf("Cannot open the file f1");
						getch();
						exit(1);
				}
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);

			       }
			else
			{
				clrscr();
				mainscreen();
				gotoxy(22,15);textcolor(128+5);
				cprintf("Wrong choice");
				textcolor(15);
				goto label;
			}
			break;
		      }
		case '2':
		      {
		       clrscr();
		       mainscreen();
		       editrecord();
		       break;
		      }
		case '6':
		      {
			clrscr();
			mainscreen();
			textcolor(14); gotoxy(20,16);
			cprintf("THANK YOU, ");gotoxy(30,16);
			cprintf("BYE....");
			getch();
			exit(1);
			break;
			}
		case '5':
		      {
		       clrscr();
               about();
			   getch();
			   break;
		      }
		case '4':
			{
				if ((fp = fopen(fn1, "rb")) == NULL) {
					printf("Cannot open the file");
					getch();
					break;
				}

				if ((f1 = fopen("delete.txt", "wb")) == NULL) {
					printf("Cannot open the file");
					getch();
					break;
				}

				clrscr();
				mainscreen();
				gotoxy(30, 15);
				cprintf("Enter the patient no");
				gotoxy(40, 16);
				fflush(stdin);
				scanf("%d", &y);

				while (fread(&p, sizeof(alka), 1, fp)) {
					if (p.sn != y) {
						fwrite(&p, sizeof(alka), 1, f1);
					} else {
						clrscr();
						mainscreen();
						fseek(fp, (y - 1) * sizeof(alka), SEEK_SET);
						fread(&p, sizeof(alka), 1, fp);
						print();
						edit1();
						gotoxy(25, 22);
						cprintf("Press `ENTER' to delete this record");
						getch();
					}
				}

				fclose(fp);
				fclose(f1);
				remove(fn1);
				rename("delete.txt", fn1);

				if ((fp = fopen(fn2, "rb")) == NULL) {
					printf("Cannot open the file");
					getch();
					break;
				}

				if ((f1 = fopen("delete.txt", "wb")) == NULL) {
					printf("Cannot open the file");
					getch();
					break;
				}

				while (fread(&p, sizeof(alka), 1, fp)) {
					if (p.sn != y) {
						fwrite(&p, sizeof(alka), 1, f1);
					}
				}

				fclose(fp);
				fclose(f1);
				remove(fn2);
				rename("delete.txt", fn2);

				clrscr();
				mainscreen();
				gotoxy(25, 25);
				textcolor(3);
				cprintf("Record successfully deleted");
				getch();
				gotoxy(37, 30);
				break;

			}


		case '3':
			{       label6:
				clrscr();
				mainscreen();
				gotoxy(25,8);textcolor(12);
				cprintf("Enter the corresponding no");gotoxy(25,10);textcolor(3);
				cprintf("1.Records of patients in ID order");gotoxy(25,12);
				cprintf("2.Records of O.P.D. patients");gotoxy(25,14);
				cprintf("3.Records of Emergency patients");gotoxy(25,16);
				cprintf("4.Records in paricular date");gotoxy(25,18);
				cprintf("5.Records in particular ID");gotoxy(25,20);
				cprintf("6.Return to main menu");gotoxy(25,22);
				fflush(stdin);
				scanf("%c",&d);
				switch(d)
				{
				case '1':
					{
					 if((fp=fopen(fn1,"rb+"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						break;
					      }
					 fseek(fp,0,SEEK_END);
					 tsz=ftell(fp);
					 n=(int)(tsz/sizeof(alka));
					 for(i=0;i<(n-1);i++)
					 {
						for(a=i+1;a<n;a++)
						{
						fseek(fp,i*sizeof(alka),SEEK_SET);
						fread(&p,sizeof(alka),1,fp);
						fseek(fp,a*sizeof(alka),SEEK_SET);
						fread(&q,sizeof(alka),1,fp);
						if(strcmp(p.name,q.name)>0)
							{
							fseek(fp,i*sizeof(alka),SEEK_SET);
							fwrite(&q,sizeof(alka),1,fp);
							fseek(fp,a*sizeof(alka),SEEK_SET); fflush(stdin);
							fwrite(&p,sizeof(alka),1,fp);
							}
						}
					}
					rewind(fp);
					clrscr();
					mainscreen();
					gotoxy(12,10);
					textcolor(11);
					cprintf("Ready to Display the patient records according to the ID");
					gotoxy(27,12);textcolor(3);
					cprintf("Press");textcolor(15+128);
					cprintf(" `Enter' ");    textcolor(3);
					cprintf("to continue");
					getch();
					while(fread(&p,sizeof(alka),1,fp))
					{
					clrscr();
					mainscreen();
					print();
					gotoxy(17,6);  textcolor(7);
					cprintf("DISPLAYING-RECORD-ACCORDING-TO-PATIENTS-NAMES");
					edit1();

					textcolor(11);
					gotoxy(20,22);
					cprintf("Press");textcolor(15+128);
					cprintf(" `Enter'"); textcolor(11);
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;

					}
					gotoxy(60,46);
					getch();

				}
				clrscr();
				mainscreen();
				textcolor(11);
				gotoxy(30,25);
				cprintf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}
			case '6':
				{
				clrscr();
				mainscreen();
				 goto label1;
				 }
			case '3':
				{
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						break;
					      }
				clrscr();
				mainscreen();
				gotoxy(15,10);
				textcolor(2);
				cprintf("Ready to Display records of Emergency Patients");
				gotoxy(27,12);textcolor(3);
				cprintf("Press");textcolor(15+128);
				cprintf(" `Enter' ");    textcolor(3);
				cprintf("to continue");
				getch();
				while(fread(&p,sizeof(alka),1,fp))
				{
					if(strcmp(p.category,"Emergency Patient")==NULL)
					{
					clrscr();
					mainscreen();
					print();
					gotoxy(17,6);  textcolor(7);
					cprintf("::DISPLAYING-RECORDS-OF-EMERGENCY-PATIENTS::");
					edit1();

					textcolor(11);
					gotoxy(20,22);
					cprintf("Press");textcolor(15+128);
					cprintf(" `Enter'"); textcolor(11);
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					gotoxy(60,46);
					getch();
					}
				}
				clrscr();
				mainscreen();
				textcolor(11);
				gotoxy(30,25);
				cprintf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}
			case '2':
				{
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						break;
					      }
				clrscr();
				mainscreen();
				gotoxy(15,10);
				textcolor(2);
				cprintf("Ready to Display records of O.P.D Patients");
				gotoxy(27,12);textcolor(3);
				cprintf("Press");textcolor(15+128);
				cprintf(" `Enter' ");    textcolor(3);
				cprintf("to continue");
				getch();
				while(fread(&p,sizeof(alka),1,fp))
				{
					if(strcmp(p.category,"O.P.D.Patient")==NULL)
					{
					clrscr();
					mainscreen();
					print();
					gotoxy(17,6);  textcolor(7);
					cprintf("::DISPLAYING-RECORDS-OF-OPD-PATIENTS::");
					edit1();
						textcolor(11);
					gotoxy(20,22);
					cprintf("Press");textcolor(15+128);
					cprintf(" `Enter'"); textcolor(11);
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					gotoxy(60,46);
					getch();
					}
				}
				clrscr();
				mainscreen();
				textcolor(11);
				gotoxy(30,25);
				cprintf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}
		case '4':
				{

				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						break;
					      }
				clrscr();
				mainscreen();
				label8:
				gotoxy(20,15);
				textcolor(3);
				cprintf("Enter the `Date' of a paricular day(yyyy/mm/dd)");
				gotoxy(35,20);fflush(stdin);
				scanf("%s",string);
				if((string[4]!='/')||(string[7]!='/')||(string[5]>'3')||(string[8]>'3'))
				{
				clrscr();
				mainscreen();
				gotoxy(23,13);textcolor(4+128);
				cprintf("Wrong Entry");
				goto label8;
				}
			    getch();

				while(fread(&p,sizeof(alka),1,fp))
				{
					if(strcmp(string,p.date)==NULL)
					{
					clrscr();
					mainscreen();
					print();
					gotoxy(17,6);  textcolor(7);
					cprintf("::DISPLAYING-RECORDS-OF-");
					cprintf("DATE >%s",p.date);
					edit1();

					textcolor(11);
					gotoxy(20,22);
					cprintf("Press");textcolor(15+128);
					cprintf(" `Enter'"); textcolor(11);
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					gotoxy(60,46);
					getch();
					}
				}
				clrscr();
				mainscreen();
				textcolor(11);
				gotoxy(30,25);
				cprintf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}

		case '5':
				{

				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						break;
					      }
				clrscr();
				mainscreen();
				gotoxy(23,15);
				textcolor(3);
				cprintf("Enter the ID");
				gotoxy(35,20);fflush(stdin);
				scanf("%d",&cid);


				while(fread(&p,sizeof(alka),1,fp))
				{
					if(cid==p.sn)
					{
					clrscr();
					mainscreen();
					print();
					gotoxy(17,6);  textcolor(7);
					cprintf("::DISPLAYING-RECORDS-OF-");
					cprintf("ID >%d",p.sn);
					edit1();

					textcolor(11);
					gotoxy(20,22);
					cprintf("Press");textcolor(15+128);
					cprintf(" `Enter'"); textcolor(11);
					cprintf(" to quit: ");
					getch();
					}
				}
				clrscr();
				mainscreen();
				textcolor(11);
				gotoxy(30,25);
				cprintf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}

			default:
				{
				clrscr();
				mainscreen();
				textcolor(12+128);gotoxy(22,11);
				cprintf("Wrong choice");gotoxy(22,13);textcolor(15);
				 cprintf("Retype choice");
				goto label6;
				}
			}
		}break;


		default:
		       {
			clrscr();
			mainscreen();
			textcolor(12+128);gotoxy(22,6);
			cprintf("Wrong choice");gotoxy(35,6);textcolor(15);
			 cprintf("Retype choice");
			goto label1;
			}

	}
	clrscr();
	mainscreen();
	goto label1;
}

void newrecord(int l)
{
	char q;
	p.sn=l;
	displaydepartment();
	gotoxy(5,9);textcolor(10);
	cprintf("Record of patient no:");
	printf(" %d",l);
	gotoxy(5,11);
	cprintf("Name: ");

	gotoxy(5,13);
	cprintf("Address: ");

	gotoxy(5,15);
	cprintf("Age: ");

	gotoxy(5,17);
	cprintf("Sex [m/f]: ");

	gotoxy(5,19);
	cprintf("Disease Descrp: ");

	gotoxy(5,21);
	cprintf("Reff. Specialist no: ");

	fflush(stdin);gotoxy(12,11);
	scanf("%[^\n]",p.name);
	p.name[0]=toupper(p.name[0]);
	gotoxy(16,13);
	fflush(stdin);
	scanf("%[^\n]",p.address);
	gotoxy(12,15);
	fflush(stdin);
	scanf("%d",&p.age);
	gotoxy(17,17);
	fflush(stdin);
	scanf("%c",&p.ch);
	fflush(stdin);gotoxy(24,19);
	scanf("%[^\n]",p.disease);
}

void newrecord1()
{
	  char q;
	 fflush(stdin);
	 gotoxy(25,21);
	scanf("%c",&q);
	switch(q)
	{
		case '1':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Generalphysician");
			       strcpy(p.department,"General Physician");
			       gotoxy(5,23);
				cprintf("Room no:");
				fflush(stdin);
				scanf("%d",&p.roomno);
			       //	getch();

				break;

			}
		case '2':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("E.N.T.");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("302");
			       strcpy(p.department,"E.N.T");
				p.roomno=302; getch();
				break;
			}
			case '3':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Cardiologist");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("509");
			       strcpy(p.department,"cardiologist");
				p.roomno=509; getch();
				break;
			}
			case '4':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Dermatologist");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("406");
			       strcpy(p.department,"Dermatologist");
				p.roomno=406; getch();
				break;
			}

			case '5':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Gastroenteroiogist");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("308");
			       strcpy(p.department,"Gastroentrologist");
				p.roomno=308; getch();
				break;
			}
			case '6':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Pediatrician");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("207");
			       strcpy(p.department,"Padiatrician");
				p.roomno=207; getch();
				break;
			}
			case '7':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("EYE Specialist");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("102");
			       strcpy(p.department,"EYE Specialist");
				p.roomno=102; getch();
				break;
			}
			case '8':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Nephrologist");
			       gotoxy(5,23);
			       cprintf("Room no:");
			       printf("109");
			       strcpy(p.department,"Nephrologist");
				p.roomno=109; getch();
				break;
			}
			case '9':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("General Surgeon");
			       strcpy(p.department,"General Surgeon");
			       gotoxy(5,23);
				cprintf("Room no:");
				fflush(stdin);
				scanf("%d",&p.roomno);
			       //	getch();
				break;
			}
			case '10':
			{      gotoxy(5,22);
			       cprintf("Reff.Specialist:");
			       printf("Accumpunturist");
			       strcpy(p.department,"Accumpunturist");
			       gotoxy(5,23);
				cprintf("Room no:");
				fflush(stdin);
				scanf("%d",&p.roomno);

				//  getch();
				break;
			}
		default:
			{
			gotoxy(5,22);
			cprintf("Reff.Specialist:");
			fflush(stdin);
			scanf("%[^\n]",p.department);
			gotoxy(5,23);
			cprintf("Room no:");
			fflush(stdin);
			scanf("%d",&p.roomno);

			return;
			}
	}
}

void displaydepartment()
{
	int i;
	gotoxy(48,9);textcolor(6);
	cprintf(":Specialists:");
	gotoxy(47,10);textcolor(15);
	cprintf("---------------");
	gotoxy(70,9);textcolor(6);
	cprintf("Room No.");
	gotoxy(67,10);textcolor(15);
	cprintf("----------");
	gotoxy(48,11);textcolor(5);
	cprintf("1.General Physician");
	gotoxy(70,11);textcolor(7);
	cprintf("201,202");
	gotoxy(48,12);textcolor(5);
	cprintf("2.E.N.T");
	gotoxy(70,12);textcolor(7);
	cprintf("302");
	gotoxy(48,13);textcolor(5);
	cprintf("3.Cardiologist");
	gotoxy(70,13);textcolor(7);
	cprintf("509");
	gotoxy(48,14);textcolor(5);
	cprintf("4.Dermatologist");
	gotoxy(70,14);textcolor(7);
	cprintf("406");
	gotoxy(48,15);textcolor(5);
	cprintf("5.Gastroenterologist");
	gotoxy(70,15);textcolor(7);
	cprintf("308");
	gotoxy(48,16);textcolor(5);
	cprintf("6.Pediatrician");
	gotoxy(70,16);textcolor(7);
	cprintf("207");
	gotoxy(48,17);textcolor(5);
	cprintf("7.EYE Specialist");
	gotoxy(70,17);textcolor(7);
	cprintf("102");
	gotoxy(48,18);textcolor(5);
	cprintf("8.Nephrologist");
	gotoxy(70,18);textcolor(7);
	cprintf("109");
	gotoxy(48,19);textcolor(5);
	cprintf("9.General Surgeon");
	gotoxy(70,19);textcolor(7);
	cprintf("407,408");
	gotoxy(70,20);textcolor(7);
	cprintf("412,413");
	gotoxy(48,21);textcolor(5);
	cprintf("10.Accupuncturist");
	gotoxy(70,21);textcolor(7);
	cprintf("123,119");
	textcolor(15);
}

void print()
{

	gotoxy(10,8);textcolor(2);
	cprintf("Patient no:");gotoxy(21,8);textcolor(11);
	cprintf("%d",p.sn);gotoxy(10,9);textcolor(2);
	cprintf("Name:");gotoxy(15,9);textcolor(11);
	cprintf(" %s",p.name);gotoxy(10,10);textcolor(2);
	cprintf("Address:");gotoxy(18,10);textcolor(11);
	cprintf(" %s",p.address);gotoxy(10,11);textcolor(2);
	cprintf("Age:");gotoxy(15,11);textcolor(11);
	cprintf("%d",p.age);gotoxy(10,12);textcolor(2);
	cprintf("Sex:");gotoxy(14,12);textcolor(11);
	cprintf(" %c",p.ch);gotoxy(10,13);textcolor(2);
	cprintf("Date of Reg.:");gotoxy(24,13);textcolor(11);
	cprintf("%s",p.date);gotoxy(10,14);textcolor(2);
	cprintf("Room no:");gotoxy(18,14);textcolor(11);
	cprintf(" %d",p.roomno);gotoxy(10,15);textcolor(2);
	cprintf("Department:");gotoxy(21,15);textcolor(11);
	cprintf(" %s",p.department);

}

void edit1()
{
	int i,k;
	gotoxy(10,17);textcolor(2);
	cprintf("Details:");gotoxy(18,17);textcolor(11);
	cprintf(" %s",p.recommendation);gotoxy(10,19);textcolor(4);
	cprintf("Press");textcolor(15+128);
	cprintf(" `Enter'");textcolor(4);
	cprintf(" for financial records");
	getch();
	clrscr();
	mainscreen();
	textcolor(14);     gotoxy(10,8);
	cprintf("The list of expenditure of patient no: ");
	printf("%d",p.sn);
	for(z=0,i=0,k=11;p.testfee[z]!=0;i++,z++)
	{
		textcolor(15);gotoxy(20,k);
		cprintf("%d",i+1);      textcolor(11);
		cprintf(" %s",&p.test[z][0]);textcolor(15);gotoxy(40,k);
		cprintf("Rs.%0.2f",p.testfee[z]);
		k=k+2;
	}
	gotoxy(20,k+2); textcolor(11);
	cprintf("Total charge= ");textcolor(15);
	cprintf("Rs.%0.2f",p.totalfee);
	gotoxy(20,k+4);textcolor(11);
	cprintf("Total Deposited: ");textcolor(15);
	cprintf("Rs.%0.2f",p.balance);
	if(p.totalfee>p.balance)
	{
		textcolor(11); gotoxy(20,20);
		cprintf("Total money to pay= ");
		textcolor(15);
		cprintf("%0.2f",p.totalfee-p.balance);
	}
	else
	{
		textcolor(11); gotoxy(20,20);
		cprintf("Total money to return= ");
		textcolor(15);
		cprintf("%0.2f",p.balance-p.totalfee);
	}
}

void switch1()
{
	int x,i;
	float d,lk;
	char v;
	label2:
	gotoxy(30,8);textcolor(11);
	cprintf("Enter");gotoxy(30,11);
	cprintf("1.Add Details");
	gotoxy(30,13);
	cprintf("2.change specialist");
	gotoxy(30,15);
	cprintf("3.Deposit balance");
	gotoxy(30,17);
	cprintf("4.Add test");
	gotoxy(30,19);
	cprintf("5.Return to main menu");
	gotoxy(35,21);
	fflush(stdin);
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		      {
			clrscr();
			mainscreen();
			gotoxy(33,10);  textcolor(7);
			cprintf("ADDING DETAILS");
			gotoxy(15,14);
			textcolor(2);
			cprintf("Previous Details:");
			gotoxy(32,14);textcolor(11);
			cprintf(" %s ",p.recommendation);
			gotoxy(15,16);textcolor(2);
			strcat(p.recommendation,"-> ");
			printf("New Details:");
			fflush(stdin);
			scanf("%[^\n]",string);
			strcat(p.recommendation,string);
			break;
		      }
		case 2:
		      {
			clrscr();
			mainscreen();
			displaydepartment();
			gotoxy(24,8);  textcolor(7);
			cprintf("CHANGING SPECIALIST");
			gotoxy(5,14);
			textcolor(2);
			cprintf("Previous Specialist:");
			gotoxy(5,15);textcolor(11);
			cprintf(" %s ",p.department);
			textcolor(15);gotoxy(5,20);
			cprintf(":Enter the new changed Specialist;");
			gotoxy(5,21);     textcolor(2);
			cprintf("Reff. Specialist no:");
			newrecord1();
			break;
		      }
		case 3:
		      {
		       clrscr();
		       mainscreen();
		       gotoxy(32,10);  textcolor(7);
		       cprintf("DEPOSITING MONEY");
		       gotoxy(20,20);
		       textcolor(2);
		       cprintf("Deposited balance: Rs.");
		       fflush(stdin);
		       scanf("%f",&d);
		       p.balance=p.balance+d;
		       break;
		      }
		case 4:
		      {
		       clrscr();
		       mainscreen();
		       displaytest();
		       gotoxy(45,13);textcolor(3);
		       cprintf("Type `esc' tn content to stop");
		       gotoxy(45,15);textcolor(15);
		       cprintf("Contents");gotoxy(70,15);
			cprintf("Rs.");lk=0;
		       for(i=17;1;i++,z++)
		       {
				gotoxy(45,i);
				fflush(stdin);
				cprintf("%c ",16);
				scanf("%s",&p.test[z][0]);
				if(strcmp(&p.test[z][0],"esc")==0)
				{       labelh:
					gotoxy(48,i+3);textcolor(15);
					cprintf("Paid/Unpaid (p/u):");
					scanf("%c",&v);
					if(v=='p')
					{
					p.balance=p.balance+lk;
					}
					else if(v!='u')
					{       gotoxy(48,i+2);
					       //	textcolor(4+128);
					       //	cprintf("Wrong Choice");
						goto labelh;
					}
					break;
				}
				gotoxy(70,i);
				fflush(stdin);
				scanf("%f",&p.testfee[z]);
				lk=lk+p.testfee[z];
				p.totalfee=p.totalfee+p.testfee[z];
				i++;
		       }
		       break;
		      }
		case 5:
		      {
				       return;
		      }

		default:
		       {
		       clrscr();
		       mainscreen();gotoxy(30,13);textcolor(4+128);
		       cprintf("Wromg choice");
		       goto label2;
		       }

	}
	clrscr();
	mainscreen();
	goto label2;
}

void editrecord()
{
	int y,x;
	gotoxy(20,12);textcolor(11);
	cprintf("Enter the patient `record no' or `Full name': ");gotoxy(25,14);

	fflush(stdin);
	scanf("%[^\n]",string);
	string[0]=toupper(string[0]);
	y=atoi(string);
	clrscr();
	mainscreen();
	if((fp=fopen(fn1,"rb+"))==NULL)
	{
		printf("\n cannot open the record file ");
		getch();
		exit(1);
	}
      // rewind(fp);
	while(fread(&p,sizeof(p),1,fp))
	{
	if((p.sn==y)||(strcmp(p.name,string)==0))
		{
			print();
			edit1();gotoxy(20,22);textcolor(9);
			printf("Press '1'to edit and 'ANY key' to go to main menu");
			fflush(stdin);
			scanf("%d",&x);
			if(x==1)
			{
			  clrscr();
			  mainscreen();
			  switch1();
			}
			else
			return;
			rewind(fp);
			fseek(f1,(p.sn-1)*sizeof(p),SEEK_SET);
			fwrite(&p,sizeof(p),1,fp);
			fclose(fp);
			break;
		}
	}

	if(p.sn!=y)
	{
		gotoxy(22,25);textcolor(3);
		cprintf("There is no record available"); gotoxy(22,30);
		textcolor(15);
		cprintf("Press Enter to continue:"); getch();
	}


}

void displaytest()
{       int i;
	gotoxy(50,8);textcolor(14);
	cprintf("::ADDING SERVICES::");
	gotoxy(9,8);textcolor(6);
	cprintf(":PRICE LIST:");
	gotoxy(5,10);textcolor(10);
	cprintf("1. X-Ray");
	gotoxy(30,10);textcolor(11);
	cprintf("Rs. 300.00");
	gotoxy(5,11);textcolor(10);
	cprintf("2. Ultra-sound");
	gotoxy(30,11);textcolor(11);
	cprintf("Rs. 500.00");
	gotoxy(5,12);textcolor(10);
	cprintf("3. C.T.Scan");
	gotoxy(30,12);textcolor(11);
	cprintf("Rs.1800.00");
	gotoxy(5,13);textcolor(10);
	cprintf("4. TC,DC,HB");
	gotoxy(30,13);textcolor(11);
	cprintf("Rs.  90.00");
	gotoxy(5,14);textcolor(10);
	cprintf("5. Urine R/E");
	gotoxy(30,14);textcolor(11);
	cprintf("Rs.  80.00");
	gotoxy(5,15);textcolor(10);
	cprintf("6. Blood C/S");
	gotoxy(30,15);textcolor(11);
	cprintf("Rs. 250.00");
	gotoxy(5,16);textcolor(10);
	cprintf("7. Biliribin D/T");
	gotoxy(30,16);textcolor(11);
	cprintf("Rs. 200.00");
	gotoxy(5,17);textcolor(10);
	cprintf("8. Stool Test");
	gotoxy(30,17);textcolor(11);
	cprintf("Rs.  60.00");
	gotoxy(5,18);textcolor(10);
	cprintf("9. Bed Charge");
	gotoxy(30,18);textcolor(11);
	cprintf("Rs. 150.00");
	gotoxy(5,19);textcolor(10);
	cprintf("10. Sugar Test");
	gotoxy(30,19);textcolor(11);
	cprintf("Rs. 400.00");
}

void mainscreen()
{   
	gotoxy(34,2);textcolor(3);
	cprintf("JEENA CARE");
	gotoxy(32.5,4);textcolor(6);
	cprintf("Vengal, Thiruvalur");

}

void about()
{   gotoxy(36,1);textcolor(6);
	cprintf("JEENA CARE");
	gotoxy(29,3);textcolor(3);
	cprintf("Amrita Vishwa Vidyapeetham");
	gotoxy(32.5,5);textcolor(6);
	cprintf("Vengal, Thiruvalur");
	

	gotoxy(20,8);textcolor(11);
	cprintf("Created By :--");

	gotoxy(20,10);textcolor(11);
	cprintf("Nehal Khan           -      CH.EN.U4CSE22041");
	gotoxy(20,12);textcolor(11);
	cprintf("Keerthi Rohan        -      CH.EN.U4CSE22030 ");
	gotoxy(20,14);textcolor(11);
	cprintf("Harshath             -      CH.EN.U4CSE22024");
	gotoxy(20,16);textcolor(11);
	cprintf("Pravin Dharsaun      -      CH.EN.U4CSE22001");
}
