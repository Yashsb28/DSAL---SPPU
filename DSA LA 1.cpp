/* Name :- Yash S. Bhoge
   Roll no. :- 27003
   Class :- SE IT B
   Topic:- DSA Assignment 1 */
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int n;

class Student{
    private:
            string name;
            int rollNo;
            float sgpa;
    public:
            void getData();
            void Show_Data();
            void ShowData();
            void rollList();
            void findsgpa();
            void FindName();
            void NameList();
            void TopTen();
    
            //extra function
            int partition(Student ar[],int start,int end);
            void QuickSort(Student ar[],int start,int end);
  
} s[25];

  void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
  }
      
//funcion defination of getData from class Student
void Student :: getData()
{ 
  //for(int i=0;i<n;i++)
          {
            //cout<<"INFORMATION OF STUDENT :- "<<i+1<<endl;
            cout<<"Enter Name of the student : ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter Roll No. : ";
            cin>>rollNo;
            cout<<"Enter SGPA : ";
            cin>>sgpa;
            //cout<<endl;
          }
}

//function defination of ShowData
void Student::Show_Data(){
            cout<<"|--------|-------------------|--------|"<<endl;
            cout<<"|Roll No.|       Name        |  SGPA  |"<<endl;
            cout<<"|--------|-------------------|--------|"<<endl;
}
       // for(int i=0;i<n;i++)
void Student :: ShowData()          
{
            cout<<"|"<<left<<setw(8)<<rollNo
                <<"|"<<left<<setw(19)<<name
                <<"|"<<left<<setw(8);
            cout<<fixed<<setprecision(2)<<sgpa;
            cout<<"|"<<endl;
            cout<<"|--------|-------------------|--------|"<<endl;
          }


//function defination of findsgpa
void Student::findsgpa()
{
  int count =0;
  float toFind;
    count=0;
  cout<<endl<<"Enter sgpa to search : ";
    cin>>toFind;
    s[25].Show_Data();
  for(int i=0;i<n;i++){
    if(s[i].sgpa==toFind){
      s[i].ShowData();
      count++;
    }
  }
  if(count ==0)
    cout<<toFind<<"sgpa not fount";
}

//function defination of rollList
void Student::rollList()
{
  int rtemp;
  string tname;
  float gtemp;
  for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(s[j].rollNo>s[j+1].rollNo)
            {
                rtemp = s[j].rollNo;
                s[j].rollNo = s[j+1].rollNo;
                s[j+1].rollNo = rtemp;
                
                tname = s[j].name;
                s[j].name = s[j+1].name;
                s[j+1].name = tname;
                
                gtemp = s[j].sgpa;
                s[j].sgpa = s[j+1].sgpa;
                s[j+1].sgpa = gtemp;
            }
        }
    }
    
  for(int i=0;i<n;i++)
      s[i].ShowData();
    cout<<endl;
}

//Defination of Name List
void Student::NameList(){
  string stemp;
  int rtemp;
  float gtemp;
  for(int i=0;i<n-1;i++)
    for(int j=i+1;j>0;j--)
      if(s[j].name[0]<s[j-1].name[0])
      {
        stemp=s[j].name;
        s[j].name=s[j-1].name;
        s[j-1].name=stemp;
        
        gtemp = s[j].sgpa;
        s[j].sgpa = s[j-1].sgpa;
        s[j-1].sgpa = gtemp;
                
        rtemp = s[j].rollNo;
        s[j].rollNo = s[j-1].rollNo;
        s[j-1].rollNo = rtemp;
      }
  Show_Data();
  for(int i=0;i<n;i++)
      s[i].ShowData();
}

//defination of search name
void Student::FindName(){
  int temp;
  string sname,tname;
  float gtemp;
  cout<<"Enter Name to search : ";
    cin.ignore();
            getline(cin,sname);
  
  for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(s[j].name>s[j+1].name)
            {
                temp = s[j].rollNo;
                s[j].rollNo = s[j+1].rollNo;
                s[j+1].rollNo = temp;
                
                tname = s[j].name;
                s[j].name = s[j+1].name;
                s[j+1].name = tname;
                
                gtemp = s[j].sgpa;
                s[j].sgpa = s[j+1].sgpa;
                s[j+1].sgpa = gtemp;
            }
        }
    }
    s[25].Show_Data();
    int f=0,r=n,mid;
    while (f <= r) {
    mid = (f + r) / 2;

    if (s[mid].name==sname) {
        
        s[mid].ShowData();
        break;
        } 
  else if(s[mid].name <sname)
        f = mid + 1;
    else
        r = mid - 1;
    }

    if (f > r)
          cout << "\nNot Found \n";
          
        
}

int Student::partition(Student ar[],int start,int end)
{
  string stemp;
  int rtemp;
   float gtemp;
   int pivot=ar[end].sgpa;
   int i = (start - 1);
   
   for (int j = start; j<=end-1 ; j++) {
        if(ar[j].sgpa<pivot){
          i++;
          rtemp = s[i].rollNo;
          s[i].rollNo = s[j].rollNo;
          s[j].rollNo = rtemp;
                
          stemp = s[i].name;
          s[i].name = s[j].name;
          s[j].name = stemp;
                
          gtemp = s[i].sgpa;
          s[i].sgpa = s[j].sgpa;
          s[j].sgpa = gtemp;
    }      
   }
   swap(ar[i+1].sgpa,ar[end].sgpa);
   swap(ar[i+1].name,ar[end].name);
   swap(ar[i+1].rollNo,ar[end].rollNo);
    return i+1;
  }

void Student::QuickSort(Student ar[],int start,int end){
    if(start<end){
        int pos=partition(ar,start,end);
        QuickSort(ar,start,pos-1);
        QuickSort(ar,pos+1,end);
      }
  }
  
void Student::TopTen(){
  QuickSort(s,0,n);
  Show_Data();
  for(int i=10;i>0;i--)
      s[i].ShowData();
}

//main function
int main()
{
        cout<<"-------------------------------------"<<endl;
        cout<<"        STUDENTS INFORMATION         "<<endl;
        cout<<"-------------------------------------"<<endl;
  
  int m;
  int count=1;
  while(1)
  {
    
  cout<<endl<<"*************************************";
  cout<<endl<<"|\t\t\t"<<"SELECT METHOD\t\t\t|";
  cout<<endl<<"*************************************";
  cout<<endl<<"|\t"<<"1. Enter Data of Students       |";
  cout<<endl<<"|\t"<<"2. Show Data                    |";
  cout<<endl<<"|\t"<<"3. Search Student by SGPA       |";
  cout<<endl<<"|\t"<<"4. Show Data Roll No. wise      |";
  cout<<endl<<"|\t"<<"5. Search Name of Student       |";
  cout<<endl<<"|\t"<<"6. Show Data Alphabetically     | ";
  cout<<endl<<"|\t"<<"7. Topper List                  | ";
  cout<<endl<<"|\t"<<"8. Exit                         |";
  cout<<endl<<"*************************************";
      
      cout<<"\n\nEnter Choice -> ";
      cin>>m;
      cout<<endl;
      cout<<"------------------------------------"<<endl;
  switch(m)
    {
    case 1:
      cout<<"Enter Number of Students :- ";
        cin>>n; 
      cout<<"------------------------------------"<<endl;
      for(int i=0;i<n;i++)
      {
        cout<<endl<<"INFORMATION OF STUDENT :- "<<count++<<endl;
        s[i].getData();
        cout<<"------------------------------------";
      }
      break;
    case 2:
          s[25].Show_Data();
      for(int i=0;i<n;i++)
          s[i].ShowData();
      break;
    case 3:
      
      s[0].findsgpa();
      break;
    case 4:
      cout<<"\n Sorted Roll Call List\n";
      s[25].Show_Data();
      s[0].rollList();
      break;
    case 5:
      //s[25].Show_Data();
      s[0].FindName();
      break;
    case 6:
      //s[25].Show_Data();
      s[0].NameList();
      break;
    case 7:
      //s[25].Show_Data();
      s[0].TopTen();
      break;
    case 8:
        cout<<"Exiting......"<<endl;
        cout<<"----✖----✖----✖----✖----✖----✖----";
        exit(0);
    }
  }
}


