#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 class questions
 {
   char q[150],a1[25],a2[25],a3[25],a4[25],r;

   public:

	 void intro();
	 void input();
	 void rules();
	 void upload();
	 void play();
	 void menu();
	 char *ret()
	 {
		return a1;
	 }
	 void display();
	 void admin();
 }ques;

   void questions::intro()
     {
	 cout<<"\n\n\n\n\n\n\t\t     Computer Science Project    \n";
	 cout<<"\n\t\t                   QUIZ    \n";
	 cout<<"\n\t\t                Designed by     ";
	 cout<<"\n\n\t\t          Pranav Khurana      ";
	 char*p="\n\n\n\t\t\t Press any key to continue ";
	 cout<<p;
	 getch();
	}

	void questions::input()
	{ 
        char name[15];  int age;  char g;
	  cout<<"\t\t\t\t\t  Welcome to the QUIZ !!!\n";
	  cout<<"\n\n\t\t Enter your details \n\n NAME: ";
	  gets(name);
	  cout<<"\n\nAge: ";
	  cin>>age;
	  cout<<"\n\nGender(m/f): ";
	  cin>>g;
	  clrscr();
	  cout<<"\n                  THE QUIZ ";
	  cout<<"\n         Today we have a NEW PLAYER here with us whose name is ";
	  puts(name);
	  if(g=='m')
	  cout<<"\n\n       His ";
	  else
	  cout<<"\n\n       Her ";
	  cout<<"age is "<<age <<" years";
	  cout<<"\n\n       Lets start the QUIZ ";
	  char*p="\n\n      Press any key to continue ";
	  cout<<p;
	  getch();
	  clrscr();
	}

	void questions::rules()
	{
	  cout<<"\n       Rules/ Instructions-     ";
	  cout<<"\n\n     * There are total 13 Multiple Choice Questions ";
	  cout<<"\n\n     * The 1st question is worth Rs 5000  ";
	  cout<<"\n\n     * With the correct answer of each question the amount gets doubled ";
	  cout<<"\n\n     * Q13 is the Jackpot Question worth Rs 5 Crore ";
	 cout<<"\n\n\n                Press any Key to continue  ";
	  getch();
	}

	void questions::menu()
	{          clrscr();
	  cout<<"\n\n\t\t\t\t MAIN MENU ";
	  cout<<"\n\n\t\t\t\t 1 - Admin";
	  cout<<"\n\n\t\t\t\t 2 - Play ";
	  cout<<"\n\n\t\t\t\t 3 - Exit ";

	  int choice;
	  cout<<"\n\n\n\t\t\t Your Choice (1/2/3): ";
	  cin>>choice;
	  switch(choice)
	  {
		 case 1: admin();  break;
		 case 2: play();   break;
		 case 3:exit(0);
	   }
}

	void questions::upload()
	{
	  clrscr();
	  char choice;
	  ofstream fout("q.dat",ios::app);
        cout<<"\n\t\t\t\t QUIZ ADMIN  \n";
	  cout<<"\n\n\t\tPress 1 to exit and Any Other Key to upload\n\n";
		int n;    cin>>n;
	  if(n==1)
		exit(0);
	   else {
	       do
	     {
		cout<<"\n\n\t\t Enter the new ques to be uploaded \n  ";
		gets(ques.q);
		cout<<"\n  Enter Options: \n";
		cout<<"\n\t\t a) ";
		gets(ques.a1);
		cout<<"\n\t\t b) ";
		gets(ques.a2);
		cout<<"\n\t\t c) ";
		gets(ques.a3);
		cout<<"\n\t\t d) ";
		gets(ques.a4);
		cout<<"\n\t Enter correct option ";
		cin>>ques.r;
		fout.write((char*)&ques,sizeof(ques));
		cout<<"\n Do you want to upload another question(y/n) ";        
           cin>>choice;
		clrscr();
	   } while(choice=='y'||choice=='Y');
	   fout.close();
	   menu();
	}
 }
    void questions::admin()
	 {
	   char ch,pass[10];
	   int choice,k=1;
      while(k)
       {           clrscr();
			 cout<<"\n\n\n\b\b             ADMIN ";
			 cout<<"\n\n\b\b            Enter Password: ";
		      strcpy(pass,NULL);
		       int p=1,x=0;
                   while(p)
		       {
			   ch=getch();
			   if(ch==13)      //ASCII value for enter key
			    {
			       pass[x]=NULL;
			       p=0;
			    }

			   else
			   {
			      cout<<"*";
			      pass[x]=ch;
			      x++;
			   }
			}

			 if(strcmp(pass,"mis")==0)
			 k=0;
			 else
			 {       cout<<"\n\n\n    WRONG PASSWORD ";
			         cout<<"\n       Press 1 to try again ";
			     cout<<"\n       Press 2 to go to Main Menu ";
			     cout<<"\n\n           Choice: ";
			     cin>>choice;
			     if(choice==2)
			     menu();
             	}
	    }            
                	  clrscr();
			  cout<<"\n\n\t\t\t\t ADMIN \n\n";
			  cout<<"\n\t\t 1 - Display Questions ";
			  cout<<"\n\t\t 2 - Upload Questions ";
			  cout<<"\n\t\t 3 - Main Menu ";
			  cout<<"\n\t\t 4 - Exit     ";
			  cout<<"\n\n\n\t\t\t Choice: ";
			  cin>>choice;
			  switch(choice)
			  {
				case 1: display();
				break;
				case 2: upload();
				break;
				case 3: menu();
				break;
				case 4: exit(0);
			  }

		   if(choice>4)
		    {
			  cout<<"\n\n   ERROR";
			  cout<<"\n    Enter a key to go to Main Menu  ";
				 getch();
				 menu();
		     }
	  }
		   void questions::display()
		   {	     	  int i=0;
			 char p[150],c1[25],c2[25],c3[25],c4[25],ans;
			 ifstream fin("q.dat",ios::binary);

			 while(fin.eof()==0&&i<20)
			 {
			   i++;
			   clrscr();
			   fin.read((char*)&ques,sizeof(ques));
			   strcpy(p,ques.q);
			   strcpy(c1,ques.a1);
			   strcpy(c2,ques.a2);
			   strcpy(c3,ques.a3);
			   strcpy(c4,ques.a4);
			   ans=ques.r;
			   cout<<"\t\t******THE QUIZ*******\t\t";
			   cout<<"\n\n  Q "<<i<<" ";
			   puts(p);
			   cout<<"\n\t\t Options are: \n  a)";
			   puts(c1);
			   cout<<"\n  b)";
			   puts(c2);
			   cout<<"\n  c)";
			   puts(c3);
			   cout<<"\n d)";
			   puts(c4);
			   cout<<"\n\n Correct Option: "<<ans;

			   if(i<20)
			   cout<<"\n\nPress any key for next question ";
			   else
			   cout<<"\n\nPress any key for ADMIN page ";
			   getch();
			}
			  admin();
	   }

		   void questions::play()
		   {
			clrscr();    randomize();
			input();
			clrscr();
			rules();
			clrscr();
			long am=0;
			int i=0;
			char p[150],c1[25],c2[25],c3[25],c4[25],ans;
			ifstream fin("q.dat",ios::binary|ios::in);
			fin.seekg(0,ios::end);
			int no_of_ques=(fin.tellg()/sizeof(ques))-1;
			int noq=no_of_ques+1;
			fin.seekg(0,ios::beg);
			int h[20],y;

			while(fin.eof()==0&&i<12)
			{
			      y=(random(noq))*sizeof(ques);
			     fin.seekg(y,ios::beg);

			  fin.read((char*)&ques,sizeof(ques));
			  strcpy(p,ques.q);
			  strcpy(c1,ques.a1);
			  strcpy(c2,ques.a2);
			  strcpy(c3,ques.a3);
			  strcpy(c4,ques.a4);
			  cout<<"\n\t\t\t\t******THE QUIZ******** ";
	   if(am==0)
     cout<<"\nQuestion amount : Rs 5000    In hand amount : Rs 0";
			  else
		  cout<<"\n Question amount : Rs"<<am*2<<"     In hand amount : Rs"<<am;  
			  cout<<"\n\n Q "<<i+1<<" ) ";
			  puts(p);
			  cout<<" Options are : \n\n a)";
			  puts(c1);
			  cout<<"\n b)";
			  puts(c2);
			  cout<<"\n c)";
			  puts(c3);
			  cout<<"\n d)";
			  puts(c4);
			  cout<<"\n\n Enter your Answer : ";
			  cin>>ans;
			  ans=tolower(ans);
			  if(ques.r==ans)
			  {
				cout<<"\n  CORRECT ANSWER";
				if(am==0)
				am=5000;
				else
				am=2*am;
				cout<<"\n You win Rs"<<am;
				char*p="\n\n Press any key to continue";
				cout<<p;
				getch();
				clrscr();
	if(i==11)
	 {
	    cout<<"\t\t\t\n\n\n You have won 7 Crore Jackpot!";
	    cout<<"\n\n\n\t\t\t CONGRATS!!!";
	    cout<<"\n\n Here is your cheque\n\n";
         cout<<"\n|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    |";
	    cout<<"\n|     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~     |";
	    cout<<"\n|        ~~~~~~~~~~~~~~~~~~~~~~~       |";
	    cout<<"\n|               7,00,000/-             |";
	    cout<<"\n|        ~~~~~~~~~~~~~~~~~~~~~~~       |";
	    cout<<"\n|     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~     |";
	    cout<<"\n|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |";
			  cout<<"\n\nPress a key to play again ";
			  getch();             menu();
		 }
	  }
		  else             
        {	        cout<<"\n  It's a WRONG ANSWER!  \n\n  Correct Option is: "<<ques.r;
	    cout<<"\n\n   You are taking home an amount of Rs "<<am;
	    char*p="\n\n  Press any key to go to the Main Menu ";
          		cout<<p;
		     getch();   		menu();
	   }
       		  i++;
    }
}
		void main()
		{
		  clrscr();
		  ques.intro();
		  clrscr();
		  ques.menu();
		  del();
		  getch();
		}

