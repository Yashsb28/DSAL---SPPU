/* Name :- Yash S. Bhoge
   Roll no. :- 27003
   Class :- SE IT B
   Topic:- DSA Assignment 10 */
#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
const int MAX=20;
class Student
{
 int rollno;
 char name[20],city[20];
 char div;
 char dept[10];
public:
 Student()
{
  strcpy(name,"");
  strcpy(city,"");
  strcpy(dept,"");
  rollno=div=0;
}
 Student(int rollno,char name[MAX],char dept[MAX],char div,char city[MAX])
 {
  strcpy(this->name,name);
  strcpy(this->city,city);
  this->rollno=rollno;
  strcpy(this->dept,dept);
  this->div=div;
 }
 int getRollNo()
 {
  return rollno;
 }
 void displayRecord()
 {

  cout<<endl<<setw(5)<<rollno<<setw(10)<<name<<setw(10)<<dept<<setw(5)<<div<<setw(10)<<city;
 }
};
//==========File Operations ===========
class FileOperations
{
 fstream file;
public:
 FileOperations(char* filename)
{
file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
}
 void insertRecord(int rollno, char name[MAX],char dept[MAX], char div,char city[MAX])
 {
  Student s1(rollno,name,dept,div,city);
  file.seekp(0,ios::end);
  file.write((char *)&s1,sizeof(Student));
  file.clear();
 }
 void displayAll()
 {
  Student s1;
  file.seekg(0,ios::beg);
  while(file.read((char *)&s1, sizeof(Student)))
  {
   s1.displayRecord();
  }
  file.clear();
 }
 void displayRecord(int rollNo)
 {
  Student s1;
  file.seekg(0,ios::beg);
  bool flag=false;
  while(file.read((char*)&s1,sizeof(Student)))
  {
   if(s1.getRollNo()==rollNo)
   {
    s1.displayRecord();
    flag=true;
    break;
   }
  }
  if(flag==false)
  {
   cout<<"\nRecord of "<<rollNo<<"is not present.";
  }
  file.clear();
 }
 void deleteRecord(int rollno)
 {
  ofstream outFile("new.dat",ios::binary);
  file.seekg(0,ios::beg);
  bool flag=false;
  Student s1;

  while(file.read((char *)&s1, sizeof(Student)))
  {
   if(s1.getRollNo()==rollno)
   {
    flag=true;
    continue;
   }
   outFile.write((char *)&s1, sizeof(Student));
  }
  if(!flag)
  {
   cout<<"\nRecord of "<<rollno<<" is not present.";
  }
  file.close();
  outFile.close();
  remove("student.dat");
  rename("new.dat","student.dat");
  file.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);
 }
 ~FileOperations()
 {
  file.close();
  cout<<"\nFile Closed.";
 }
};
int main() {
 ofstream newFile("student.dat",ios::app|ios::binary);
  newFile.close();
  FileOperations file((char*)"student.dat");
     int rollNo,choice=0;
     char div;
     char name[MAX],address[MAX],dept[MAX];
     while(choice!=5)
     {
         //clrscr();
         cout<<endl<<"***********************"<<endl;
         cout<<"   STUDENT DATABASE";
         cout<<endl<<"***********************"<<endl;
         cout<<"1) Add New Record\n";
         cout<<"2) Display All Records\n";
         cout<<"3) Display by RollNo\n";
         cout<<"4) Deleting a Record\n";
         cout<<"5) Exit";
         cout<<endl<<"***********************"<<endl;
         cout<<"Choose your choice : ";
         cin>>choice;
         switch(choice)
         {
             case 1 : //New Record
               cout<<endl<<"Enter RollNo and name : \n";
               cin>>rollNo>>name;
               cout<<"Department : \n";
               cin>>dept;
               cout<<"Division : ";
               cin>>div;
               cout<<"Enter City : \n";
               cin>>address;
               file.insertRecord(rollNo,name,dept,div,address);
               cout<<"\nRecord Inserted !!!";
               break;
             case 2 :
              cout<<endl<<setw(5)<<"ROLL"<<setw(10)<<"NAME"<<setw(10)<<"DEPT"<<setw(5)<<"DIV"<<setw(10)<<"CITY";
               file.displayAll();
               break;
             case 3 :
               cout<<"Enter Roll Number :- ";
               cin>>rollNo;
               cout<<endl<<setw(5)<<"ROLL"<<setw(10)<<"NAME"<<setw(10)<<"DEPT"<<setw(5)<<"DIV"<<setw(10)<<"CITY";
                file.displayRecord(rollNo);

               break;
             case 4:
               cout<<"Enter rollNo :-";
               cin>>rollNo;
               file.deleteRecord(rollNo);
               cout<<"Record Deleted !!!";
               break;
            case 5 :break;
         }

     }

 return 0;
}
