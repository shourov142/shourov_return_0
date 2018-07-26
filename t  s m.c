
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;




/*******************************************FUNCTION PROTOTYPE**********************************************************/
//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();


/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/

int main()

{
		system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t                                               \n");
	printf("\t\t        -----------------------------          \n");
	printf("\t\t           TRAIN TICKET RERS. SYSTEM           \n");
	printf("\t\t        -----------------------------          \n");
	printf("\t\t                                               \n");
	printf("\t\t                                               \n");
	printf("\t\t                                               \n");
	printf("\t\t              Developed BY                     \n");
	printf("\t\t              |  Shourov |                     \n");
	printf("\t\t                                               \n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Welcome To Train Seat Reservation System!!");
	printf(" \n");
	printf(" \n ");
	printf(" \n N.B. This System is only available for Dhaka's Passengers ");
	printf(" \n");
	printf(" \n ");
	printf(" \n Press Enter to Enter the System.....");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n\t\t\t=================================\n");
	printf(" \t\t\t   TRAIN SEAT RESERVATION SYSTEM");
	printf("\n\t\t\t=================================\n");
	printf("\n                                 \n");
	printf("\n1 Reserve A Ticket\n");
	printf("\n2 View All Available Trains\n");
	printf("\n3 Cancel Reservation\n");
	printf("\n4 Exit");
	printf("\n\n Enter your Choice:");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

//The function is yet not completed, need more details to be added!
//timings of the trains are still missing

void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tTurna Express       Dhaka to Chittagong     \tTk.500\t\t9am");
	printf("\n1002\tPadma Express       Dhaka To Rajshahi       \tTk.450\t\t12pm");
	printf("\n1003\tChittra Express     Dhaka To Khulna         \tTk.450\t\t8am");
	printf("\n1004\tSirajgonj Express   Dhaka To Sirajganj      \tTk.280\t\t5pm");
	printf("\n1005\tLal moni Express    Dhaka To Lalmonirhat    \tTk.300\t\t7am");
	printf("\n1006\tJoyantika Express   Dhaka To Sylhet         \tTk.580\t\t9.30am");
    printf("\n1007\tUpukol Express      Dhaka To Noakhali       \tTk.350\t\t1pm");
    printf("\n1008\tDrutojan Express    Dhaka To Dinajpur       \tTk.310\t\t4pm");
    printf("\n1009\tDhumketue Express   Dhaka To Rajshahi       \tTk.470\t\t3.35pm");
    printf("\n1010\tMoitree Express     Dhaka To Kholkhata      \tTk.2460\t\t4.15pm");

}



void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name: ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats: ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\nPress Enter To View Available Trains ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number: ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again-- ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress backspace to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress backspace to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again----- ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(500.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(450.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(450.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(280.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(300.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(580.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(350.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(310.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(470.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(2460.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("\t\t-------------------\n");
	printf("\t\tTICKET\n");
	printf("\t\t-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}



void specifictrain(int train_num)
{

	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tTurna Express");
		printf("\nDestination:\t\tDhaka to Chittagong");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tPadma Express");
		printf("\nDestination:\t\tDhaka to Rajshahi");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tChittra Express");
		printf("\nDestination:\t\tDhaka to Khulna");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tSirajgonj Express");
		printf("\nDestination:\t\tDhaka to Sirajganj");
		printf("\nDeparture:\t\t5pm ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tLal moni Express");
		printf("\nDestination:\t\tDhaka to Lalmonirhat");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tJoyantika Express ");
		printf("\nDestination:\t\tDhaka to Sylhet");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\nDestination:\t\tBoston to Washington");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tDrutojan Express");
		printf("\n Destination:\t\tDhaka to Dinajpur");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tDhumketue Express");
		printf("\nDestination:\t\tDhaka to Rajshahi");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMoitree Express");
		printf("\nDestination:\t\tDhaka to Kholkhata");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       Thank you for log in  !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\t Press Enter to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for maximum times!!!");

		getch();

		}
		system("cls");
}

void cancel(void)   /* Sorry this function does not work. Coding is not completed. Codes have been removed due to some errors  */
{
	/*FILE *f,*t;
	int i=0;
	int trainnum;
	t=fopen("seats_reserved.txt","w");
	if ((f=fopen("seats_reserved.txt","r"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main();
		* * * * *
		*
		*
		*
		*
		*
		*
		*  /  missing codes  /
	}
	else*/
	system("cls");
	int trainnum;

		printf("Enter the train number: ");

		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\n Canceled");
		getch();
}





