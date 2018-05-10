#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<time.h>
using namespace std;
#define password "daredevil"
void searchrec(void);
//int searchreg(char s[]);
//****************************************************************************
//              class containing student record and functions related to task
//****************************************************************************
class registration
  {
    private:
       char stuid[15];
       char name[30];
       char address[50];
       char gender;
       char course;
       char status;
       char cno[10];
       char date[10];
      public:
        void insert();
         void delet();
        friend void modify();
         void display();
//***************************************************************
//return 1 or 0 according to string matches or not
//************************************************************
           int  search1(char st[])  
            {
                 int fla=1;
                 string s2,s1;
                //cout<<"\n enter string   "<<st;
                 s2=st;
                 //cout<<"\n copy of st "<<s2;
                 s1=stuid;
                 //cout<<"\n copy of student id  "<<s1;
                  fla=s1.find(s2);
                 // cout<<"\n fla=  "<<fla;
                 if(fla>=0)
                  return(1);
                 else
                   return(0);
            }
         int search(char [],int);
         int search(char,int);
          
         
  }; 
  void  modify()  //TO Modify the record of perticular student
   {
                 cout<<"\nEnter the registration number  for updation ...:";
                 char ser[10];
                 cin.getline(ser,10);
                 int siz=0,siz1=0;
                 int bin=0;
                  registration d;
                 fstream file1;
                 file1.open("record.dat",ios::in|ios::out);
                while( file1.read((char *) & d, sizeof(d)))
                  {
                       bin=d.search1(ser);
                     //cout<<"\nbin= "<<bin;
                     //if(bin!=1)
                       siz++;
                     if(bin==1)
                       {   break;}
                  }
                   
                     int loc;
                         loc=(siz-1)*sizeof(d);
                         file1.seekp(loc,ios::beg);
                         if(bin==1)
                        {   cout<<"\nstudentid  name                     address                       gender  martialstatus  Phone no.   dateofbirth \n";                                                         cout<<"___________________________________________________________________________________________________\
____________________________";
                            d.display();
                            cout<<"\n Enter the field to be updation ....";
                           cout<<"\n [1] Name \n [2] Address \n [3] Gender \n [4] Marital Status \n [5] Phone number ";
                           cout<<"\n Enter Your choice....";
                            int ch;
                            cin>>ch;
                             getchar();
                            switch(ch)
                             {
                                case 1: 
           
                          cout<<"\n Enter Name...";
                                     cin.getline(d.name,30);
                                     break;
                                case 2:
                                      cout<<"\n Enter the Address....";
                                      cin.getline(d.address,50);
                                       break;
                                case 3 :
                                      cout<<"\nenter gender";
                                       while(1)
                                        {
                                          cout<<"\n1 for male\n2 for female\n";
                                           cin>>d.gender;
                                          if(d.gender=='1'||d.gender=='2')
                                           break;
                                         else
                                          {
                                            //system("clear");
                                             cout<<"invalid input\n";
                                          }
                                      }break;
                                   
                                    case 4:
                                          while(1)
                                            {
                                                cout<<"[M] married\n[U] unmarried\n";
                                                cin>>d.status;
                                                if(d.status=='M'||d.status=='m'||d.status=='U'||d.status=='u')
              					  break;
	             			       else
        				        {
               						//system("clear");
             						 cout<<"invalid input\n";
              					     continue;
             					} 
             				   }
                                         break;
                                     case 5:
                                       while(1)
                                        {
                                          int p;
                                         cout<<"\nmobile/phone number... : ";
                                          cin>>d.cno;
                                          if(strlen(d.cno)!=10)
                                           {   
                                            // system("clear"); 
                                              cout<<"invalid input";
                                              continue;
                                           }
                                        else 
                                         {
                                           for(int i=0;i<10;i++)
                                            {
                                             if(d.cno[i]<'0'||d.cno[i]>'9')
                                              {
                                                   p=0;
                                                 break;
                                              }
                                           }
                                         if(p==0)
                                          {
                                          //  system("clear"); 
                                            cout<<"invalid input";
                                            p=1;
                                          continue;
                                         }
                                       else
                                         break;
                                    }  
                               }break;
                        
                     
                       }
                     //d.insert();
                 file1.write((char *) & d, sizeof(d));
                  cout<<"\n Record is Updated successfully...";
                  file1.close();
              }
           else
           cout<<"\n Record is not found ....";
        
                
  }  
void registration :: insert()  //To insert the record of student into file
   {
         cout<<"\n Enter the student id...... : ";
         cin>>stuid;
         getchar();
         //system("clear");
       while(1)
        {
           int flag=1;
           cout<<"\nEnter name of student....: ";
            cin.getline(name,30);
            if(strlen(name)==0)
             {
              cout<<"invalid input name\n";
             continue;
               } 
             for(int i=strlen(name)-1;i>=0;i--)
               { 
                 if(((name[i]>='a'&&name[i]<='z')||(name[i]>='A'&&name[i]<='Z')||(name[i]=='.'||name[i]==' ')))
                  flag=1;
                 else
                  { 
                     flag=0;
                      break; 
                   }
                  
                }
               if(flag==1)
                 break;
               else
                {
                 cout<<"invalid input name"<<endl;
                 continue;
                 }
          }
           cout<<"\nEnter address of student: ";
           cin.getline(address,50);
              cout<<"\nenter gender";
                while(1)
                {
                  cout<<"\n1 for male\n2 for female\n";
                  cout<<"\n Enter your choice....";
                  cin>>gender;
                  if(gender=='1'||gender=='2')
                      break;
                 else
                  {
                    cout<<"invalid input\n";
                   }
                 }
             cout<<"\nEnter marital status\n"; 
        
        while(1)
            {
              cout<<"[M] married\n[U] unmarried\n";
             //cout<<"\nmarital status : ";
              cout<<"\n enter your choice...";
             cin>>status;
             if(status=='M'||status=='m'||status=='U'||status=='u')
             break;
             else
             {
                cout<<"invalid input\n";
                continue;
             } 
             }
         int p=1;
        while(1)
          {
             cout<<"\nmobile/phone number : ";
             cin>>cno;
             if(strlen(cno)!=10)
               {   
                
                 cout<<"invalid input";
                 continue;
               }
             else 
               {
                  for(int i=0;i<10;i++)
                   {
                    if(cno[i]<'0'||cno[i]>'9')
                     {
                        p=0;
                       break;
                    }
                  }
               if(p==0)
                {
                  cout<<"invalid input";
                  p=1;
                  continue;
                 }
               else
                break;
             }
       }    
       
        
        while(1)
         {
        cout<<"\ndate of birth(dd/mm/yyyy) : ";
        cin>>date;
        int year=(1000*(date[6]-48)+100*(date[7]-48)+10*(date[8]-48)+(date[9]-48));
        int month=(10*(date[3]-48)+(date[4]-48));
        int days=(10*(date[0]-48)+(date[1]-48));
        if(year>=1950)
        {
        if((year%4==0&&year%100!=0)||(year%400==0))
          {
           if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(days>=1&&days<=31))
             break;
           else if((month==4||month==6||month==9||month==11)&&(days>=1&&days<=30))
              break;
           else if(month==2&&(days>=1&&days<=29))
              break;
            else
             {
              cout<<"invalid input";
            continue;
               }
             }
          else
           {
            if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(days>=1&&days<=31))
             break;
           else if((month==4||month==6||month==9||month==11)&&(days>=1&&days<=30))
              break;
             else if(month==2&&(days>=1&&days<=28))
              break;
            else
             {
             cout<<"invalid input";
            continue;
              }
            }
          }
           else
          {
            cout<<"invalid input";
            continue;
              }
           }
      
                      

        cout<<"\nEnter the course : ";
        
         while(1)
           {
              cout<<"\n[1] b.tech\n[2] mca\n[3] m.tech\n[4] p.hd\n";  
              cout<<"\n Enter the corresponding number...";
              cin>>course;
              if(course=='1'||course=='2'||course=='3'||course=='4')
                break;
              else
               {
                 cout<<"invalid input\n";
                  continue;  
                } 
             }
           cout<<"\n\nrecord added successfully  \n";
           //cout<<"\n Press any key to continue....";
            //getchar();
             //system("clear");
      //   cout<<"your student id is.............\n"<<stuid;
   }
//***************************************
//display of all records in the file
//**************************************
   void registration :: display()
    {
       int i,j,k=0;
      cout<<"\n";
       cout.setf(ios::left,ios::adjustfield);
       cout.width(11);
       cout<<stuid;
       cout.setf(ios::left,ios::adjustfield);
       cout.width(25);
       cout<<name;
        
         i=strlen(address);
         if(i<=30)
            {
             cout.setf(ios::left,ios::adjustfield);
             cout.width(30);
             cout<<address;
            }
         else
           {
            for(j=0;j<30;j++)
             cout<<address[j];
             cout<<endl;
             cout<<"                                    ";
              //cout.setf(ios::left,ios::adjustfield);
              //cout.width(30);
              while(j<i)
               {
                 cout<<address[j++];
                 k++;
             } 
              for(i=0;i<30-k;i++)
              cout<<" ";
            }
          cout.setf(ios::left,ios::adjustfield);
         cout.width(8);
          if(gender=='1')
             cout<<"male";
          else
             cout<<"female";
        cout.setf(ios::left,ios::adjustfield);
         cout.width(15); 
       if(status=='u'||status=='U')
             cout<<"unmarried";
       else
          cout<<"married";
         cout.setf(ios::left,ios::adjustfield);
         cout.width(13);
          cout<<cno;
      //    cout.setf(ios::left,ios::adjustfield);
        //  cout.width(11);
          // cout<<date<<endl;
    }
//*******************************************************************
//class to show the initial view and main menu
//******************************************************************
   class menu
      {
	 	int temp;
		public:
				 int get_menu()
				 {

                                    system("clear");
                                     system("tput cup 10 35");
				        cout<<"******************************************************";
				       cout<<"\n";
				        system("tput cup 11 45");
				        cout<<"STUDENT REGISTRATION PROGRAMME"<<"\n";
				        system("tput cup 12 35");
			        cout<<"*******************************************************\n";//system("sh star.sh");
			        cout<<"\n";
			        system("tput cup 15 53");
			        cout<<"MAIN MENU"<<"\n";
				        system("tput cup 17 45");
			                cout<<"[1] ADD NEW STUDENT RECORD"<<"\n";
				        system("sleep 0.20s");
				        system("tput cup 19 45");
				        cout<<"[2] DISPLAY STUDENT RECORD"<<"\n";
				        system("sleep 0.20s");
				        system("tput cup 21 45");
				        cout<<"[3] MODIFY STUDENT RECORD"<<"\n";
				         system("sleep 0.20s");
				        system("tput cup 23 45");
				        cout<<"[4] SEARCH STUDENT RECORD"<<"\n";
				         system("sleep 0.20s");
				        system("tput cup 25 45");
				        cout<<"[5] EXIT THE PROGRAMME"<<"\n";
				        system("tput cup 30 80");
				         system("sleep 0.30s");
				        cout<<"Waiting for your response...";
					 cin>>temp;
                                 system("clear");
                                 getchar();
				 return temp;
				 }
     };
void welcome();
//*************************************
//beginning of main function
//*************************************
int main()
{ 
        welcome();  
	fstream file,file1;
        registration s;
        int choice,x;
        menu m;
        char ch1[15];
       do
	{
                 system("clear");
		choice=m.get_menu();
                switch(choice)
                {
			case 1:
			  {     
                                 
                                 file.open("record.dat",ios::ate|ios::app|ios::in|ios::out);
                                  s.insert();
                                file.write((char *)& s,sizeof(s));
                                 file.close();
	                       break;
		      	 }                
			case 2:
			  {
                                file.open("record.dat",ios::in);
cout<<"studentid  name                     address                       gender  martialstatus  Phone no.   dateofbirth";
cout<<"\n_____________________________________________________________________________________________________________";

 
                              while(file.read((char *)& s,sizeof (s)))
	                       s.display();
                               file.close();
	                       break;
			}
	               case 3:
	                      modify();
	                      break;

	                case 4:
                                searchrec();                            
                                break;
                        case 5:
                             cout<<"\n Press any key to exit .....";
                              getchar();
                               exit(0);
			default:
                        {
                        	cout<<"\n Wrong input... :";
                                getchar();
                               // exit(0);
                        }
		}
		cout<<"\n\n\npress 1 for continue     ";
              
	}while(cin>>x!=0);
	return(0);
} // End of the main fumction 

//*******************************************************************
//function to search a student record by every field
//*******************************************************************
void searchrec(void)
    {
                                int bin,n,flag=0;
                                int size=0;
                                char ch1[15],c;
                                registration s;
                                fstream file1;
                                cout<<"[1] for registration\n[2] for name\n[3] gender\n[4] course\n[5] martial status\n[6] mobile no"<<endl; 
                                cin>>n;
                                switch(n)
                                {
                                 case 1:
                                 cout<<"enter the registration no to be search.............";
                                cin>>ch1;
                                file1.open("record.dat",ios::in);
                                while(file1.read((char *) & s,sizeof(s)))
				{    
                                        bin=s.search(ch1,n);
                                        if(bin==0&&size==0)
                                        {
                                          cout<<"studentid  name                     address                       gender  martialstatus  Phone no. dateofbirth";
                                                s.display();
                                          size=1;
                                           flag=1;
                                           }
                                         else if(bin==0&&size==1)
                                                   s.display();                                              
                                        }
                                  if(flag==0)
                                  cout<<"no record is found\n";                                
                                file1.close();   
                                break;
                                case 2:
                                cout<<"enter the name to be search.............";getchar();
                                 cin.getline(ch1,30);
                                file1.open("record.dat",ios::in);
                                while(file1.read((char *) & s,sizeof(s)))
				{    
                                        bin=s.search(ch1,n);
                                        if(bin==0&&size==0)
                                        {
                                          cout<<"studentid  name                     address                       gender  martialstatus  Phone no. dateofbirth";
                                                s.display();
                                          size=1;
                                          flag=1;
                                           }
                                         else if(bin==0&&size==1)
                                                   s.display();                                              
                                        }        
                                  if(flag==0)
                                  cout<<"no record is found\n";                        
                                file1.close();
                                 break; 
                                  case 3:
                                 cout<<"enter the gender to be searched.............";
                                 cout<<"\n [1] Male\n[2]Female";
                                 cout<<"\n Enter corresponding numbner...";
                                  cin>>c;
                                file1.open("record.dat",ios::in);
                                while(file1.read((char *) & s,sizeof(s)))
				{    
                                        bin=s.search(c,n);
                                        if(bin==0&&size==0)
                                        {
                                          cout<<"studentid  name                     address                       gender  martialstatus  Phone no. dateofbirth";
                                                s.display();
                                          size=1;
                                          flag=1;
                                           }
                                         else if(bin==0&&size==1)
                                                   s.display();                                              
                                        }  
                                  if(flag==0)
                                  cout<<"no record is found\n";                              
                                file1.close();
                                 break; 
                                 case 4:
                                 cout<<"\nEnter the course to be searched .............";
                                  cout<<"\n[1] b.tech\n[2] mca\n[3] m.tech\n[4] p.hd\n";  
                                 cout<<"\n Enter the corresponding number...";
                                    cin>>c;
                                file1.open("record.dat",ios::in);
                                while(file1.read((char *) & s,sizeof(s)))
				       {    
                                        bin=s.search(c,n);
                                        if(bin==0&&size==0)
                                        {
                                          cout<<"studentid  name                     address                       gender  martialstatus  Phone no. dateofbirth";
                                                s.display();
                                          size=1;
                                          flag=1;
                                           }
                                         else if(bin==0&&size==1)
                                                   s.display();                                              
                                        } 
                                  if(flag==0)
                                  cout<<"no record is found\n";                               
                                file1.close();
                                 break; 
                                 case 5:
                                    cout<<"enter the martial status to be search.............";
                                    cout<<"\n [U] Unmarried \n[M] Married";
                                     cout<<"\n Enter the corresponding alphabet";
                                     cin>>c;
                                file1.open("record.dat",ios::in);
                                while(file1.read((char *) & s,sizeof(s)))
				{    
                                        bin=s.search(c,n);
                                        if(bin==0&&size==0)
                                        {
                                          cout<<"studentid  name                     address                       gender  martialstatus  Phone no. dateofbirth";
                                
              s.display();
                                          size=1;flag=1;
                                           }
                                         else if(bin==0&&size==1)
                                                   s.display();                                              
                                        }   
                                   if(flag==0)
                                  cout<<"no record is found\n";                             
                                file1.close();
                                 break;
                                  case 6:
                                   cout<<"\nEnter the mobile no to be search.............";  
                                   cin>>ch1;
                                file1.open("record.dat",ios::in);
                                while(file1.read((char *) & s,sizeof(s)))
				{    
                                        bin=s.search(ch1,n);
                                        if(bin==0&&size==0)
                                        {
                                          cout<<"studentid  name                     address                       gender  martialstatus  Phone no. dateofbirth";
                                                s.display();
                                          size=1;
                                          flag=1;
                                           }
                                         else 
                                              if(bin==0&&size==1)
                                                   s.display();                                              
                                        } 
                                  if(flag==0)
                                  cout<<"no record is found\n";                               
                                file1.close();
                                 }
}
//*************************************************************************************
//function which match the input string with the string in the file and returns 0 or 1
//*************************************************************************************
 int registration :: search(char st[],int i)
      { 
          string s1,s2;
            s1=st;
          switch(i)
          {
          case 1:
            s2=stuid;
            break;
          case 2:s2=name;
           break; 
          case 6:s2=cno;
       }
         int fla=s2.compare(s1);
          if(fla==0)
            return(0);
          else
            return(1);
         }
//*******************************************************************************************
//function which match the input character with the character in the file and returns 0 or 1
//*******************************************************************************************
    int registration :: search(char ch,int n)
        {
        char c1,c2;
        c1=ch;
         switch(n)
          {
            case 3:
             c2=gender;
              break;
            case 4:
             c2=course; 
             break; 
            case 5: 
             c2=status;
          }
          if(c1==c2)
          return(0);
          else
          return(1);
          }

//*****************************************************
//     function to create a welcome screen
//*****************************************************
 void welcome()
  {
    system("clear");system("tput cup 4 20");
	cout<<"#########################################################################################"<<"\n";
	system("tput cup 5 20");system("sleep 0.20s");
	cout<<"###											###"<<"\n";
	system("tput cup 6 20");system("sleep 0.20s");
	cout<<"###	################	   ################		##################      ###"<<"\n";
	system("tput cup 7 20");system("sleep 0.20s");
	cout<<"###	################	   ################		##################	###"<<"\n";
	system("tput cup 8 20");system("sleep 0.20s");
	cout<<"###	######	     ###	       #######			########       ###	###"<<"\n";
	system("tput cup 9 20");system("sleep 0.20s");
	cout<<"###	######			       #######			########		###"<<"\n";
	system("tput cup 10 20");system("sleep 0.20s");
	cout<<"###	######			       #######			########		###"<<"\n";
	system("tput cup 11 20");system("sleep 0.20s");
	cout<<"###	################	       #######			##################	###"<<"\n";
	system("tput cup 12 20");system("sleep 0.20s");
	cout<<"###	        ########	       #######				  ########	###"<<"\n";
	system("tput cup 13 20");system("sleep 0.20s");
	cout<<"###		########	       #######				  ########	###"<<"\n";
	system("tput cup 14 20");system("sleep 0.20s");
	cout<<"###	###	########	       #######			###	  ########	###"<<"\n";
	system("tput cup 15 20");system("sleep 0.20s");
	cout<<"###	################	    ###############		##################	###"<<"\n";
	system("tput cup 16 20");system("sleep 0.20s");
	cout<<"###	################	    ###############		##################	###"<<"\n";
	system("tput cup 17 20");system("sleep 0.20s");
	cout<<"###											###"<<"\n";
	system("tput cup 18 20");system("sleep 0.20s");
	cout<<"#########################################################################################"<<"\n";
	system("tput cup 21 60");
	cout<<"DESIGNED BY"<<"\n";
	system("tput cup 24 55");
	cout<<" AVN9 <<"\n";

         system("tput cup 32 80");
         cout<<"\n Press any key to continue....";
          getchar(); 
   }
	
