#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<time.h>
using namespace std;
#define password "daredevil"
void searchrec(void);
//int searchreg(char s[]);
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
       //  string s1,s2;
     // friend int searchreg(char);
        void insert();
         void delet();
         void modify();
         void display();
         int search(char [],int);
         int search(char,int);
           void disp_search()
             {
                  cout<<"student id      "<<stuid<<endl;
                  cout<<"name:         "<<name<<endl;
                  cout<<"address:         "<<address<<endl;
                  cout<<"gender:     "<<gender<<endl;
                  cout<<"marital status:       "<<status<<endl;
                  cout<<"mobile/phone number:        "<<cno<<endl;
                  cout<<"date of birth:         "<<date<<endl;
              }
         
  };

void registration :: insert()
   {
        cout<<"student id : ";cin>>stuid;getchar();
         system("clear");
       while(1)
        {
           int flag=1;
           cout<<"\nname : ";
            cin.getline(name,30);
            if(strlen(name)==0)
             {
             system("clear");
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
                 system("clear");
                cout<<"invalid input name"<<endl;
                 continue;
                 }
          }
          system("clear");
         cout<<"\naddress : ";cin.getline(address,50);
         system("clear");
         cout<<"\nenter gender";
                while(1)
                {
                cout<<"\n1 for male\n2 for female\n";
                cin>>gender;
               if(gender=='1'||gender=='2')
                break;
             else
               {
                 system("clear");
               cout<<"invalid input\n";
               }
                 }
           system("clear");
         cout<<"enter marital status\n"; 
         //cout<<"[M] married\n[U] unmarried\n";
        while(1)
            {
              cout<<"[M] married\n[U] unmarried\n";
             //cout<<"\nmarital status : ";
             cin>>status;
             if(status=='M'||status=='m'||status=='U'||status=='u')
             break;
             else
             {
               system("clear");
              cout<<"invalid input\n";
              continue;
             } 
             }
         system("clear");
        int p=1;
        while(1)
          {
          cout<<"\nmobile/phone number : ";cin>>cno;
         if(strlen(cno)!=10)
         {   
         system("clear"); 
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
          system("clear"); 
         cout<<"invalid input";
           p=1;
          continue;
          }
          else
           break;
         }
       }    
        system("clear");
        
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
            system("clear");
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
            system("clear");
            cout<<"invalid input";
            continue;
              }
            }
          }
           else
          {
            system("clear");
            cout<<"invalid input";
            continue;
              }
           }
      
                      
       system("clear");
        cout<<"\ncourse : ";
       system("clear");
         while(1)
           {
              cout<<"[1] b.tech\n[2] mca\n[3] m.tech\n[4] p.hd\n";  
              cin>>course;
              if(course=='1'||course=='2'||course=='3'||course=='4')
                break;
              else
               {
                 system("clear");
                 cout<<"invalid input\n";
                  continue;  
                } 
             }
      
        
         cout<<"\n\nrecord added successfully  \n";
         cout<<"your student id is.............\n"<<stuid;
   }
//display of all records in the file
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
       if(status=='u'||status=='U'||status=='M'||status=='m')
             cout<<"unmarried";
       else
             cout<<"married";
          cout.setf(ios::left,ios::adjustfield);
         cout.width(13);
          cout<<cno;
        // cout.setf(ios::left,ios::adjustfield);
         //cout.width(11);
        // cout<<date<<endl;
    }
   class menu
      {
	 	int temp;
		public:
				 int get_menu()
				 {cout<<"\t\t*******************************"<<endl;
				 cout<<"\t\t  student registration program"<<endl;
				 cout<<"\t\t *******************************"<<endl;
                                 cout<<"\n\n\n\n\n\n\n";
                                 cout<<"\t\t[1]Add new student record"<<endl;
				 cout<<"\t\t[2]delete student record"<<endl;
				 cout<<"\t\t[3]display student records"<<endl;
				 cout<<"\t\t[4]modify student record"<<endl;
				 cout<<"\t\t[5]search student record"<<endl;
				 cout<<"\t\t[6]exit the program"<<endl;
				 cout<<"\t\tenter your choice______";
				 cin>>temp;
                                 system("clear");
                                 getchar();
				 return temp;
				 }
     };
void disp_window(void);
void authentication(void);
/*int size(void)
{
 int i=0;
  registration abc;
fstream f;
f.open("record",ios::out);
f.close();
f.open("record",ios::in);
while(f.read((char *) & abc,sizeof(abc)))
  i++;
f.close();
 return(i);
}*/
int main()
{
	fstream file,file1;
        registration s;
        int choice,x;
        menu m;
        char ch1[15];
	//  authentication();
        do
	{
                 system("clear");
		choice=m.get_menu();
                switch(choice)
                {
			case 1:
			{     
                            /*   file.open("record.dat",ios::in|ios::out);
                                 file1.open("record1.dat",ios::out);
                                 while(file.read((char *) & s,sizeof(s)))
                                       file1.write((char *) & s,sizeof(s)); 
                                 file.close();
                                 file1.close();
                                 //file.open("record.dat",ios::in);
                                 //while(file.read((char *) & s,sizeof(s)))*/
                                 file.open("record.dat",ios::ate|ios::app|ios::in|ios::out);
                                 // file.open("record.dat",ios::app|ios::out);
	                         s.insert();
                                 file.write((char *)& s,sizeof(s));
                               //system("clear");
                               file.close();
	                       break;
			}
	                   /* case 2:
	                     s.delet();
	                      break;*/
			case 3:
			{
                                file.open("record.dat",ios::in);
cout<<"studentid  name                     address                       gender  martialstatus  Phone no.   dateofbirth";
                               while(file.read((char *)& s,sizeof (s)))
	                       s.display();
                               file.close();
	                       break;
			}

	                   /* case 4:
	                        s.modify();
	                         break;*/

	                case 5:
                                 searchrec();                            
                                break;
			default:
                        {
                        	cout<<"\n Press any akey to exit :";
                                getchar();
                                exit(0);
                        }
		}
		cout<<"\npress 1 for continue     ";
              
	}while(cin>>x!=0);
	return(0);
} // End of the main fumction 
void disp_window()
{
	  cout<<"\t\t**************************************"<<endl;
	  cout<<"\t\tuniversity student information system"<<endl;
	  cout<<"\t\t*************************************"<<endl;

}
 int retry=1;
void authentication()
{    
disp_window();
	  int valid=0;
	  char pass[10];
   do 
      {
	  cout<<"\n\n\n\n\n\npassword : ";
	  cin>>pass;
        if(strcmp(pass,password)!=0)
        {
        cout<<"\n\n\n\n\n\n\npassword invalid"<<endl;
        valid=0;
	retry+=1;
	}
        else
	   valid=1;
	 }
while(valid==0&&retry<=3);
  if(retry>3)
  {cout<<"only 3 tries are allowed";
	 exit(0);}
	 else
	 cout<<"login approved!";
}
void searchrec(void)
    {
                                int bin,n,flag=0;
                                int size=0;
                                char ch1[15],c;
                                registration s;
                                fstream file1;
                                cout<<"1 for registration\n2 for name\n3 gender\n4 course\n5 martial status\n6 mobile no"<<endl; 
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
                                 cout<<"enter the gender to be search.............";
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
                                 cout<<"enter the course to be search.............";
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
                                   cout<<"enter the mobile no to be search.............";  
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
                                 }
}
 int registration :: search(char st[],int i)
      { 
          string s1,s2;
            s1=st;
          switch(i)
          {
          case 1:
          s2=stuid;break;case 2:s2=name;break;case 6:s2=cno;}
         int fla=s2.compare(s1);
          if(fla==0)
            return(0);
          else
            return(1);
         }
    int registration :: search(char ch,int n)
        {
        char c1,c2;
        c1=ch;
         switch(n)
          {
           case 3:c2=gender;break;case 4:c2=course;break;case 5:c2=status;
          }
          if(c1==c2)
          return(0);
          else
          return(1);
          }
