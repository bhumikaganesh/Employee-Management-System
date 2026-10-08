
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
void create();
void page();
void delet();
void exit();
void display();
void modify();
struct employee
{
	char name[100];
	char address[100];
	int age;
	int salary;
	int employeeid;
	int contactinformation;
} c;


int main(){

	char username[100], password[100], user[] = "admin", pass[] = "password";
	system("cls");
	printf("\t\t\t\t--------------EMPLOYEE MANAGEMENT SYSTEM-------------------\n");
again:
	printf("\nENTER USER NAME\n");
	scanf("%s", &username);
	printf("\nENTER PASSWORD\n");
	scanf("%s", &password);
	if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
	{
		page();
	}
	else
	{
		printf("\nEMPLOYEE MANAGEMENT SYSTEM\n");
		printf("\ninvalid username or password\n");
	}
	return 0;
}
/*
void Register()
{
	
char password[100];
char username[100];
    FILE *fp;
    struct employee c ;
    system("cls");
    printf("Please enter your username and password \n");
    printf("Username: \t");
    scanf("%s", username);
    printf("Password: \t");
    scanf("%s",password);

    fp = fopen("employee.dat", "ab");

    fwrite(&c, sizeof(c), 1, fp);

    fclose(fp);

    printf("User registered!");
  
}
*/

void page()
{
	int choice;
	system("cls");
	printf("\n\t\t\t\t-----------EMPLOYEE MANAGEMENT SYSTEM-------------");
	printf("\n[1] Add new record");
	printf("\n[2] Delete a record");
	printf("\n[3] Modify a record");
	printf("\n[4] Display all the record");
	printf("\n[5] Exit");
	printf("\nenter your choice[1-5]");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		create();
	}
	break;
	case 2:
	{
		delet ();
	}
	break;
	case 3:
	{
		modify();
	}
	break;
	case 4:
	{
		display();
	}
	break;
	case 5:
	{
		//exit();
	}
	break;
	default:
		printf("invalid choice");
	}
}
void create()
{
	FILE *fp;
Add:
	system("cls");
	int choice, id_no;
	printf("\nENTER ALL DETAIL");
	printf("\nenter employee id:");
	scanf("%d", &id_no);
	fp = fopen("EmployeDetail.txt", "r");
	while (fread(&c, sizeof(c), 1, fp))
	{
		if (c.employeeid == id_no)
		{
			printf("\nid number already used\n");
			system("pause");
			goto Add;
		}
		else
		{
			printf("\nadd ");
		}
	}

	fp = fopen("EmployeDetail.txt", "a+");
	printf("\n\t\t\t\t-------Your New User----------");
	printf("\nenter name:");
	scanf("%s", &c.name);
	printf("\nenter employee id:");
	scanf("%d", &c.employeeid);
	printf("\nenter address:");
	scanf("%s", &c.address);
	printf("\nenter salary:");
	scanf("%d", &c.salary);
	printf("\ncontact information:");
	scanf("%d", &c.contactinformation);
	fwrite(&c, sizeof(c), 1, fp);
	if (fwrite != 0)
	{
		printf("success");
	}
	else
	{
		printf("failed");
	}
	fclose(fp);
	printf("\n1. Add more employee");
	printf("\n2. Main menu");
	printf("\n3. Exit");
	printf("\nENTER YOUR CHOICE");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		system("cls");
		goto Add;
	}
	break;
	case 2:
	{
		page();
	}
	break;
	case 3:
	{
		// exit();
	}
	break;
	}
}
void delet()
{
	system("cls");
	FILE *fp;
	FILE *fp_tmp;
	int id, choice, flag = 0;
	delet: printf("ENTER ID NO.TO DELETE:\t");
	scanf("%d", &id);
	fp = fopen("EmployeDetail.txt", "r");
	fp_tmp = fopen("EmployeDetail_tmp.txt", "a");
	while (fread(&c, sizeof(c), 1, fp))
	{
		if (id != c.employeeid)
		{
			fwrite(&c, sizeof(c), 1, fp_tmp);
		}
		else
		{
			flag = 1;
		}
	}
	fclose(fp);
	fclose(fp_tmp);

	if (flag == 1)
	{
		printf("record deleted successfully");
		remove("EmployeDetail.txt");
		rename("EmployeDetail_tmp.txt", "EmployeDetail.txt");
	}
	else
	{
		printf("record doesnot exist");
	}
	printf("\n1. Delete record\n");
	printf("\n2. Mainmenu\n");
	printf("\n3. Exit");
	printf("\nenter your choice");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		goto delet;
	}
	break;

	case 2:
	{
		page();
	}
	break;
	case 3:
	{
		// exit();
	}
	break;
	}
}
void modify()
{
	system("cls");
	FILE *fp;
	FILE *fp_tmp;
	int choice,check;
	int id,flag=0;
	modifyy:
	printf("ENTER ID NO.TO UPDATE:");
	scanf("%d",&id);
	fp=fopen("EmployeDetail.txt","r");
	fp_tmp=fopen("EmployeDetail_tmp.txt","a");
	while(fread(&c,sizeof(c),1,fp))
	{
		if(id==c.employeeid)
		{
			flag = 1;
			printf("ENTER EMPLOYEE ID:");
			scanf("%d",&c.employeeid);
			printf("ENTER EMPLOYEE NAME:");
			scanf("%s",&c.name);
			printf("ENTER ADDRESS:");
			scanf("%s",&c.address);
			printf("ENTER SALARY:");
			scanf("%d",&c.salary);
			printf("ENTER CONTACT INFORMATION:");
			scanf("%d",&c.contactinformation);
		}
		else
		{
			printf ("no");
		}
		fwrite(&c,sizeof(c),1,fp_tmp);
	}
		
	if(flag==1)
	{
		
	}
	else
	{
		printf("record doesnot exist");
	}
	fclose(fp);
	fclose(fp_tmp);
	remove("EmployeDetail.txt");
	rename("EmployeDetail_tmp.txt","EmployeDetail.txt");
	printf("\n1. Update more id");
	printf("\n2. Mainmenu");
	printf("\n3. Exit");
	printf("\nenter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:{
			goto modifyy;
		}
		break;
		case 2:{
			page();
		}
		break;
		case 3:{
			//exit();
		}
		break;
	}


}
void display()
{
	system("cls");
	FILE *fp;
	int choice;
	fp = fopen("EmployeDetail.txt", "r");
	printf("id:\tname\t\taddress\t\tcontact\t\tsalary");
	while (fread(&c, sizeof(c), 1, fp))
	{
		printf("\n%d", c.employeeid);
		printf("\t%s", c.name);
		printf("\t\t%s", c.address);
		printf("\t%d", c.contactinformation);
		printf("\t%d", c.salary);
	}
	fclose(fp);
	printf("\n\n[1].mainmenu");
	printf("\n[2].exit");
	printf("\nenter your choice:");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		page();
	}
	break;
	case 2:
	{
		// exit()
	}
	break;
	};
}

