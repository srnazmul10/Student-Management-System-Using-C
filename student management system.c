#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>


int i = 0;
struct nazmul26
{
      char name[30];
      int   id;
      char trimester[100];
      char subject[10][100];
      char subcode[10][100];
      int subnum[100];
      float subnumber;
      float cgpa;

} stu[55];

COORD coord={0,0};

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void addstd()

{



      system("cls");
      gotoxy(30,2);
      printf("Add Student Details");
      gotoxy(30,3);
      printf("------------------- ");
      fflush(stdin);
      gotoxy(20,4);
      printf("Student Name:");
      fflush(stdin);
      gets(stu[i].name);
      gotoxy(20,5);
      printf("Enter the student id:");
      fflush(stdin);
      scanf("%d", &stu[i].id);
      fflush(stdin);
      gotoxy(20,6);
      printf("Enter the trimester name:");
      fflush(stdin);
      gets(stu[i].trimester);
      gotoxy(20,7);
      fflush(stdin);
      printf("Enter the number of the subjects of this trimester:");
      scanf("%f",&stu[i].subnumber);
      gotoxy(20,8);
      printf("Enter the subject of the trimester:");
      int x=20,p=10;
      for (int j = 0; j <stu[i].subnumber; j++)
      {

            gotoxy(20,p);

            fflush(stdin);

            gets(stu[i].subject[j]);
            p++;
      }
      gotoxy(20,10+stu[i].subnumber);
      printf("Enter the subject code of the trimester:");
      int q=20,t=10+stu[i].subnumber+1;;
      for (int n = 0; n < stu[i].subnumber; n++)
      {
            gotoxy(20,t);
            fflush(stdin);
            gets(stu[i].subcode[n]);
            t++;
      }

        gotoxy(20,t+1);

      printf("Enter the marks of the total marks obtained by the student:\t");

      int r=20,n=t+2;
      for (int k = 0; k < stu[i].subnumber; k++)

      {

            gotoxy(20,n);
            fflush(stdin);
            scanf("%d", &stu[i].subnum[k]);
            n++;
      }
      i++;
            int op=n+stu[i].subnumber;
            int add;
            fflush(stdin);
            gotoxy(20,op);
            printf("Would you like to add one more student!!!!");
            gotoxy(20,op+1);
            printf("1.YES,I WANT TO ADD ANOTHER STUDENT!   2.NO,I WANT TO GO BACK TO MAIN MENU");
            gotoxy(20,op+2);
            printf("Enter your choice:");
            scanf("%d",&add);

            switch(add)
            {
            case 1:
                system("cls");
                addstd();
                break;

            case 2:
                system("cls");
                main();
                break;
            }



}

void findbyroll()

{
        system("cls");
        system("color F0");
      int x;
        gotoxy(20,2);
      printf("Enter the roll to find the student:\t");
      fflush(stdin);
      scanf("%d", &x);

      float sum = 0;

      for (int j = 0; j < i; ++j)
      {

            if (x == stu[j].id)
            {
                gotoxy(2,3);
                 printf("NO.   Name                    ID           TRIMESTER              SUBJECTS                        SUBCODE     GRADE  CGPA");
                // gotoxy(20,4);
               //  printf("____________________________________________________________________________________________________________________1");
                 gotoxy(2,6);
                 printf("%d   %s",j+1,stu[j].name);
                 gotoxy(30,6);
                 printf("%d",stu[j].id);
                 gotoxy(44,6);
                 printf("%s",stu[j].trimester);
                 int n=58,q=6;
                 for(int n=0;n<stu[j].subnumber;n++)
                 {

                     fflush(stdin);
                     gotoxy(58,q);
                     printf("%s",stu[j].subject[n]);
                     q++;

                 }

                 int t=100,z=6;
                 for(int lo=0;lo<stu[j].subnumber;lo++)
                 {
                     fflush(stdin);
                     gotoxy(100,z);
                     printf("%s",stu[j].subcode[lo]);
                     z++;
                 }

                 int c=114,op=6;
                 for(int qw=0;qw<stu[j].subnumber;qw++)
                 {
                     fflush(stdin);
                     gotoxy(114,op);

                        if (stu[j].subnum[qw] >= 80 && stu[j].subnum[qw] <= 100)
                        {
                              sum=sum+4.00;
                              printf("A+");
                        }
                        else if (stu[j].subnum[qw] < 80 && stu[j].subnum[qw] >= 75)
                        {
                              sum=sum+3.75;
                              printf("A");
                        }
                        else if (stu[j].subnum[qw] < 75 && stu[j].subnum[qw] >= 65)
                        {
                              sum=sum+3.50;
                              printf("A-");
                        }
                        else if (stu[j].subnum[qw] < 65 && stu[j].subnum[qw] >= 55)
                        {
                              sum=sum+3.00;
                              printf("B");
                        }
                        else if (stu[j].subnum[qw] < 55 && stu[j].subnum[qw] >= 40)
                        {
                              sum=sum+2.50;
                              printf("c");
                        }
                        else if (stu[j].subnum[qw] < 40 && stu[j].subnum[qw] >= 0)
                        {
                              sum=sum*0;
                              printf("F");

                        }

                        op++;
                  }

                  gotoxy(118,6);
                  if(sum==0)
                  {
                      printf("  2.00");
                  }
                  else
                  {


                  printf("\t%.2f",(sum/stu[j].subnumber));

                  }
            }

      }


      gotoxy(30,20);
      int searchroll;
      printf("Would you like to another student by his Roll!!!");
      gotoxy(30,21);
      printf("1.YES,I WANT TO SEARCH ANOTHER STUDENT     2.NO,I WANT TO GO BACK TO MAIN MENU");
      gotoxy(30,22);
      printf("Enter your choice: ");
      scanf("%d",&searchroll);
      switch(searchroll)
      {
      case 1:
        system("cls");
        findbyroll();
        break;

      case 2:
        system("cls");
        main();
        break;
      }




}


void findbyname()

{

        system("cls");
      float sum = 0;
      char n[100];
        gotoxy(5,1);
      printf("Enter the name:");
      fflush(stdin);
      gets(n);

      for (int j = 0; j < i; ++j)
      {

            if (!strcmp(stu[j].name, n))

            {
                gotoxy(2,3);
                 printf("NO.   Name                    ID           TRIMESTER              SUBJECTS                         SUBCODE     GRADE  CGPA");
                // gotoxy(20,4);
               //  printf("____________________________________________________________________________________________________________________1");
                 gotoxy(2,6);
                 printf("%d   %s",j+1,stu[j].name);
                 gotoxy(30,6);
                 printf("%d",stu[j].id);
                 gotoxy(44,6);
                 printf("%s",stu[j].trimester);
                 int n=58,q=6;
                 for(int n=0;n<stu[j].subnumber;n++)
                 {

                     fflush(stdin);
                     gotoxy(58,q);
                     printf("%s",stu[j].subject[n]);
                     q++;

                 }

                 int t=100,z=6;
                 for(int lo=0;lo<stu[j].subnumber;lo++)
                 {
                     fflush(stdin);
                     gotoxy(100,z);
                     printf("%s",stu[j].subcode[lo]);
                     z++;
                 }

                 int c=112,op=6;
                 for(int qw=0;qw<stu[j].subnumber;qw++)
                 {
                     fflush(stdin);
                     gotoxy(114,op);

                        if (stu[j].subnum[qw] >= 80 && stu[j].subnum[qw] <= 100)
                        {
                              sum=sum+4.00;
                              printf("A+");
                        }
                        else if (stu[j].subnum[qw] < 80 && stu[j].subnum[qw] >= 75)
                        {
                              sum=sum+3.75;
                              printf("A");
                        }
                        else if (stu[j].subnum[qw] < 75 && stu[j].subnum[qw] >= 65)
                        {
                              sum=sum+3.50;
                              printf("A-");
                        }
                        else if (stu[j].subnum[qw] < 65 && stu[j].subnum[qw] >= 55)
                        {
                              sum=sum+3.00;
                              printf("B");
                        }
                        else if (stu[j].subnum[qw] < 55 && stu[j].subnum[qw] >= 40)
                        {
                              sum=sum+2.50;
                              printf("c");
                        }
                        else if (stu[j].subnum[qw] < 40 && stu[j].subnum[qw] >= 0)
                        {
                              sum=sum*0;
                              printf("F");

                        }

                        op++;
                  }

                  gotoxy(118,6);

                  if(sum==0)
                  {
                      printf("\t2.00");
                  }
                  else
                  {


                  printf("\t%.2f",(sum/stu[j].subnumber));

                  }
                 }
      }

      gotoxy(30,20);
      int searchname;
      printf("Would you like to another student by his Name!!!");
      gotoxy(30,21);
      printf("1.YES,I WANT TO SEARCH ANOTHER STUDENT     2.NO,I WANT TO GO BACK TO MAIN MENU");
      gotoxy(30,22);
      printf("Enter your choice: ");
      scanf("%d",&searchname);
      switch(searchname)
      {
      case 1:
        system("cls");
        findbyname();
        break;

      case 2:
        system("cls");
        main();
        break;
      }
}

void findtotalstd()
{
      system("cls");
      gotoxy(20,10);
      printf("Total student is %d\n", i);

      gotoxy(20,15);
      int abc;
      printf("Would you like to add one more student!!!");
      gotoxy(20,17);
      printf("1.YES I WOULD LIKE TO ADD ONE MORE STUDENT    2. NO I WANT TO GO BACK TO MAIN MENU!!!!");
      gotoxy(20,19);
      printf("ENTER YOUR CHOICE: ");
      scanf("%d",&abc);

      switch(abc)
      {
      case 1:
        system("cls");
        addstd();
        break;

      case 2:
        system("cls");
        main();
        break;
      }
}

void deletestd()
{

        system("cls");
            int x;
            fflush(stdin);
            gotoxy(30,2);
            printf("Enter the student's roll number to delete:");
            scanf("%d",&x);



      for (int j = 0; j < i; j++)
      {

            if (x == stu[j].id)
            {
                  fflush(stdin);
                  gotoxy(30,5);
                  printf("The roll you entered is successfully removed!!");
                  --i;
            }

            else
            {
                    fflush(stdin);
                    gotoxy(30,5);
                  printf("The roll you entered is not entered yet in the database!!!");
            }
      }


      gotoxy(30,8);
      int A;
      printf("Would you like to delete another student!!!");
      gotoxy(30,9);
      printf("1.YES,I WANT TO DELETE ANOTHER STUDENT     2.NO,I WANT TO GO BACK TO MAIN MENU");
      gotoxy(30,10);
      printf("Enter your choice: ");
      scanf("%d",&A);
      switch(A)
      {
      case 1:
          system("cls");
        deletestd();
        break;

      case 2:
        system("cls");
        main();
        break;
      }


}


void updatestudent()
{
      int x;
      printf("Enter the roll number of the student to update information:\t");
      scanf("%d",&x);

      for(int j=0;j<i;j++)
      {

            if (x == stu[j].id)
            {



      gotoxy(30,2);
      printf("UPDATE STUDENT DETAILS");
      gotoxy(30,3);
      printf("----------------------");
      fflush(stdin);
      gotoxy(30,4);
      printf("1.UPDATE STUDENT'S NAME");
      gotoxy(30,5);
      printf("2.UPDATE STUDENT'S ID");
       gotoxy(30,6);
      printf("3.UPDATE STUDENT'S TRIMESTER");
       gotoxy(30,7);
      printf("4.UPDATE THE SUBJECT'S OF THE TRIMESTER");
       gotoxy(30,8);
      printf("5.UPDATE THE STUDENT'S SUBJECT CODES OF THE TRIMESTER");
       gotoxy(30,9);
      printf("6.UPDATE THE STUDENT'S MARKS OF THE TRIMESTER");
      int choice;
      gotoxy(30,10);
      printf("7.UPDATE ANOTHER STUDENT");
      gotoxy(30,11);
      printf("8.MAIN MENU");
      gotoxy(30,12);
      printf("9.EXIT");

      gotoxy(30,13);
      printf("ENTER YOUR CHOICE: ");
      scanf("%d",&choice);
      switch(choice)
      {

  case 1:
      system("cls");
      gotoxy(20,10);
      printf("STUDENT'S NAME TO UPDATE:");
      fflush(stdin);
      gets(stu[j].name);
      system("cls");
      break;
  case 2:
      system("cls");
      gotoxy(20,10);
      printf("UPDATE THE STUDENT'S ID:");
      fflush(stdin);
      scanf("%d",&stu[j].id);
      system("cls");
      break;
  case 3:
      system("cls");
      fflush(stdin);
      gotoxy(20,10);

      printf("UPDATE THE TRIMESTER NAME:");
      fflush(stdin);
      gets(stu[j].trimester);
      system("cls");
      break;
  case 4:
      system("cls");
      int p=11;


      gotoxy(20,10);
      printf("UPDATE THE SUBJECTS OF THE TRIMESTER:");

      for (int k = 0; k < stu[j].subnumber; k++)
      {

          gotoxy(20,p);



            fflush(stdin);

            gets(stu[j].subject[k]);
            p++;

      }

      break;
  case 5:

      system("cls");
       p=11;

      gotoxy(20,10);
      printf("UPDATE THE STUDENT'S SUBJECT CODE OF THE TRIMESTER: ");


      for (int n = 0; n < stu[j].subnumber; n++)
      {
            gotoxy(20,p);

            fflush(stdin);
            gets(stu[j].subcode[n]);
            p++;

      }

      break;

  case 6:


      system("cls");

       p=11;
      gotoxy(20,10);


      printf("UPDATE THE STUDENT'S MARKS OBTAINED BY THE STUDENT: ");

      for (int k = 0; k < stu[j].subnumber; k++)

      {
            gotoxy(20,p);

            fflush(stdin);
            scanf("%d", &stu[j].subnum[k]);
            p++;

      }
      break;

  case 7:
      system("cls");
    updatestudent();
      break;

  case 8:
      system("cls");
    main();
    break;

  case 9:
    exit(0);
    break;
      }

      }

      }

      int ex;
      gotoxy(30,20);
      printf("Would like to update more information!!!!!");
      gotoxy(30,21);
      printf("1.YES,I WOULD LIKE TO DO   2.NO,I WANT TO GO BACK TO MAIN");
      gotoxy(30,22);
      printf("ENTER YOUR CHOICE: ");
      scanf("%d",&ex);
      switch(ex)
      {
      case 1:
          system("cls");
        updatestudent();
        break;

      case 2:
          system("cls");
        main();
        break;
      }



}

void uppercgpa()

{

    int x=6;
    system("cls");
    float cgpa = 3.50;
    int count = 0;
    for (int j = 0; j < i; ++j)

        {


            float sum = 0;
        for(int qw=0;qw<3;qw++)
        {
            fflush(stdin);
            if (stu[j].subnum[qw] >= 80 && stu[j].subnum[qw] <= 100)
            {
                  sum=sum+4.00;

            }
            else if (stu[j].subnum[qw] < 80 && stu[j].subnum[qw] >= 75)
            {
                  sum=sum+3.75;
            }
            else if (stu[j].subnum[qw] < 75 && stu[j].subnum[qw] >= 65)
            {
                  sum=sum+3.50;

            }
            else if (stu[j].subnum[qw] < 65 && stu[j].subnum[qw] >= 55)
            {
                  sum=sum+3.00;
            }
            else if (stu[j].subnum[qw] < 55 && stu[j].subnum[qw] >= 40)
            {
                  sum=sum+2.50;

            }
            else if (stu[j].subnum[qw] < 40 && stu[j].subnum[qw] >= 0)
            {
                  sum=sum+2.00;

            }

        }
        float s = sum/3;
        if(s >= cgpa){
                 gotoxy(2,3);
                 printf("NO.   Name                    ID           TRIMESTER               SUBJECTS                        SUBCODE     GRADE  CGPA");
                // gotoxy(20,4);
               //  printf("____________________________________________________________________________________________________________________1");

                 gotoxy(2,x);
                 printf("%d   %s",j+1,stu[j].name);
                 gotoxy(30,x);
                 printf("%d",stu[j].id);
                 gotoxy(44,x);
                 printf("%s",stu[j].trimester);
                 int n=44,q=6;
                // x=6;
                 for(int n=0;n<stu[j].subnumber;n++)
                 {


                     fflush(stdin);
                     gotoxy(58,x);
                     printf("%s",stu[j].subject[n]);

                     gotoxy(100,x);
                     printf("%s",stu[j].subcode[n]);


                     gotoxy(114,x);

                        if (stu[j].subnum[n] >= 80 && stu[j].subnum[n] <= 100)
                        {
                             // sum=sum+4.00;
                              printf("A+");
                        }
                        else if (stu[j].subnum[n] < 80 && stu[j].subnum[n] >= 75)
                        {
                            //  sum=sum+3.75;
                              printf("A");
                        }
                        else if (stu[j].subnum[n] < 75 && stu[j].subnum[n] >= 65)
                        {
                            //  sum=sum+3.50;
                              printf("A-");
                        }
                        else if (stu[j].subnum[n] < 65 && stu[j].subnum[n] >= 55)
                        {
                             // sum=sum+3.00;
                              printf("B");
                        }
                        else if (stu[j].subnum[n] < 55 && stu[j].subnum[n] >= 40)
                        {
                             // sum=sum+2.50;
                              printf("c");
                        }
                        else if (stu[j].subnum[n] < 40 && stu[j].subnum[n] >= 0)
                        {
                             // sum=sum * 0;
                              printf("F");

                        }

                   x++;
                  fflush(stdin);

                  }

                 if(sum == 0)
                  {
                      printf("\t2.00");
                  }
                  else
                  {

                  printf("\t%.2f",(sum/stu[j].subnumber));

                  }
                  x=x+5;



                 // break;

                }
        x=x+10;

        fflush(stdin);
            }

       fflush(stdin);

      gotoxy(30,50);
      int findall;
      printf("Would you like to see student's cgpa again those who gain 3.50!!");
      gotoxy(30,51);
      printf("1.YES,I WANT TO SEE     2.NO,I WANT TO GO BACK TO MAIN MENU");
      gotoxy(30,52);
      printf("Enter your choice: ");
      scanf("%d",&findall);
      switch(findall)
      {
      case 1:
        system("cls");
        uppercgpa();
        break;

      case 2:
        system("cls");
        main();
        break;
      }
    }





void lowercgpa()
{
    system("cls");

    int x=6;
    float cgpa = 3.50;
    int count = 0;
    for (int j = 0; j < i; ++j)

        {
        float sum = 0;

        for(int qw=0;qw<3;qw++)
        {
            fflush(stdin);
            if (stu[j].subnum[qw] >= 80 && stu[j].subnum[qw] <= 100)
            {
                  sum=sum+4.00;

            }
            else if (stu[j].subnum[qw] < 80 && stu[j].subnum[qw] >= 75)
            {
                  sum=sum+3.75;
            }
            else if (stu[j].subnum[qw] < 75 && stu[j].subnum[qw] >= 65)
            {
                  sum=sum+3.50;

            }
            else if (stu[j].subnum[qw] < 65 && stu[j].subnum[qw] >= 55)
            {
                  sum=sum+3.00;
            }
            else if (stu[j].subnum[qw] < 55 && stu[j].subnum[qw] >= 40)
            {
                  sum=sum+2.50;

            }
            else if (stu[j].subnum[qw] < 40 && stu[j].subnum[qw] >= 0)
            {
                  sum=sum+2.00;

            }

        }
        float s = sum/3;
        if(s < cgpa){

         gotoxy(2,3);
                 printf("NO.   Name                    ID           TRIMESTER               SUBJECTS                        SUBCODE     GRADE  CGPA");
                // gotoxy(20,4);
               //  printf("____________________________________________________________________________________________________________________1");
               int x=6;
                 gotoxy(2,x);
                 printf("%d   %s",j+1,stu[j].name);
                 gotoxy(30,x);
                 printf("%d",stu[j].id);
                 gotoxy(44,x);
                 printf("%s",stu[j].trimester);
                 int n=44,q=6;
                // x=6;
                 for(int n=0;n<stu[j].subnumber;n++)
                 {


                     fflush(stdin);
                     gotoxy(58,x);
                     printf("%s",stu[j].subject[n]);

                     gotoxy(100,x);
                     printf("%s",stu[j].subcode[n]);


                     gotoxy(114,x);

                        if (stu[j].subnum[n] >= 80 && stu[j].subnum[n] <= 100)
                        {
                             // sum=sum+4.00;
                              printf("A+");
                        }
                        else if (stu[j].subnum[n] < 80 && stu[j].subnum[n] >= 75)
                        {
                             // sum=sum+3.75;
                              printf("A");
                        }
                        else if (stu[j].subnum[n] < 75 && stu[j].subnum[n] >= 65)
                        {
                            //  sum=sum+3.50;
                              printf("A-");
                        }
                        else if (stu[j].subnum[n] < 65 && stu[j].subnum[n] >= 55)
                        {
                            //  sum=sum+3.00;
                              printf("B");
                        }
                        else if (stu[j].subnum[n] < 55 && stu[j].subnum[n] >= 40)
                        {
                            //  sum=sum+2.50;
                              printf("c");
                        }
                        else if (stu[j].subnum[n] < 40 && stu[j].subnum[n] >= 0)
                        {
                             // sum=sum * 0;
                              printf("F");

                        }

                  x++;
                  fflush(stdin);

                  }

                 if(sum == 0)
                  {
                      printf("\t2.00");
                  }
                  else
                  {

                  printf("\t%.2f",(sum/stu[j].subnumber));

                  }
                  x=x+5;



                 // break;

                }
         x=x+10;

        fflush(stdin);
            }


       fflush(stdin);

      gotoxy(30,50);
      int findall;
      printf("Would you like to see student's who gain lower than 3.50 again!!");
      gotoxy(30,51);
      printf("1.YES,I WANT TO SEE     2.NO,I WANT TO GO BACK TO MAIN MENU");
      gotoxy(30,52);
      printf("Enter your choice: ");
      scanf("%d",&findall);
      switch(findall)
      {
      case 1:
        system("cls");
        lowercgpa();
        break;

      case 2:
        system("cls");
        main();
        break;
      }


    }








void allstudentinformation()

{
     system("cls");
      int j;

      int x=6;


      for ( j = 0; j <i; ++j)
      {

            float sum = 0;


                 gotoxy(2,3);
                 printf("NO.   Name                    ID           TRIMESTER               SUBJECTS                        SUBCODE     GRADE  CGPA");
                // gotoxy(20,4);
               //  printf("____________________________________________________________________________________________________________________1");
                 gotoxy(2,x);
                 printf("%d   %s",j+1,stu[j].name);
                 gotoxy(30,x);
                 printf("%d",stu[j].id);
                 gotoxy(44,x);
                 printf("%s",stu[j].trimester);
                 int n=44,q=6;
                // x=6;
                 for(int n=0;n<stu[j].subnumber;n++)
                 {


                     fflush(stdin);
                     gotoxy(58,x);
                     printf("%s",stu[j].subject[n]);

                     gotoxy(100,x);
                     printf("%s",stu[j].subcode[n]);


                     gotoxy(114,x);

                        if (stu[j].subnum[n] >= 80 && stu[j].subnum[n] <= 100)
                        {
                              sum=sum+4.00;
                              printf("A+");
                        }
                        else if (stu[j].subnum[n] < 80 && stu[j].subnum[n] >= 75)
                        {
                              sum=sum+3.75;
                              printf("A");
                        }
                        else if (stu[j].subnum[n] < 75 && stu[j].subnum[n] >= 65)
                        {
                              sum=sum+3.50;
                              printf("A-");
                        }
                        else if (stu[j].subnum[n] < 65 && stu[j].subnum[n] >= 55)
                        {
                              sum=sum+3.00;
                              printf("B");
                        }
                        else if (stu[j].subnum[n] < 55 && stu[j].subnum[n] >= 40)
                        {
                              sum=sum+2.50;
                              printf("c");
                        }
                        else if (stu[j].subnum[n] < 40 && stu[j].subnum[n] >= 0)
                        {
                              sum=sum * 0;
                              printf("F");

                        }

                   x++;
                  fflush(stdin);

                  }

                 if(sum == 0)
                  {
                      printf("\t2.00");
                  }
                  else
                  {

                  printf("\t%.2f",(sum/stu[j].subnumber));

                  }
                  x=x+5;



                 // break;

                }

            x=x+10;

        fflush(stdin);

      gotoxy(30,50);
      int findall;
      printf("Would you like to see all student's information again!!");
      gotoxy(30,51);
      printf("1.YES,I WANT TO SEE     2.NO,I WANT TO GO BACK TO MAIN MENU");
      gotoxy(30,52);
      printf("Enter your choice: ");
      scanf("%d",&findall);
      switch(findall)
      {
      case 1:
        system("cls");
        allstudentinformation();
        break;

      case 2:
        system("cls");
        main();
        break;
      }







}

int main()

{

    system("cls");
    system("color F0");
      while (1)
      {

            gotoxy(45,1);
            printf("STUDENT MANAGEMENT SYSTEM");
          //  gotoxy(40,1);
           // printf("Student Details");
            gotoxy(45,2);
            printf("_________________________");
            gotoxy(30,7);
            printf("1.ADD STUDENT DETAILS");
            gotoxy(30,8);
            printf("2.FIND THE STUDENT BY HIS ROLL");
            gotoxy(30,9);
            printf("3.SEARCH THE STUDENT BY HIS NAME");
            gotoxy(30,10);
            printf("4.FIND TOTAL STUDENT");
            gotoxy(30,11);
            printf("5.DELETE STUDENT");
            gotoxy(30,12);
            printf("6.UPDATE STUDENT'S INFORMATION");
            gotoxy(30,13);
            printf("7.STUDENT'S WHO HAVE CGPA EQUAL OR UPPER THAN 3.50");
            gotoxy(30,14);
            printf("8.STUDENT'S WHO HAVE GOT CGPA LESS THAN 3.50");
            gotoxy(30,15);
            printf("9.ALL STUDENT'S INFORMATION");
            gotoxy(30,16);
            printf("10.QUIT");


            int mn;
            gotoxy(30,28);
            printf("Enter one of following:");
            fflush(stdin);
            scanf("%d", &mn);

            switch (mn)
            {
            case 1:

                  system("cls");
                  addstd();
                  break;
                  system("cls");

            case 2:
                  system("cls");
                  findbyroll();
                  break;

            case 3:
                  system("cls");
                  findbyname();
                  break;

            case 4:
                  system("cls");
                  findtotalstd();
                  break;

            case 5:
                  system("cls");
                  deletestd();
                  break;

            case 6:
                  system("cls");
                  updatestudent();
                  break;



            case 7:
                system("cls");
                uppercgpa();
                break;

            case 8:
                system("cls");
                lowercgpa();
                break;

            case 9:

                  system("cls");
                  allstudentinformation();
                  break;

            case 10:
                system("cls");
                exit(0);

            default:
                  printf("");
                  break;
            }
      }
}


