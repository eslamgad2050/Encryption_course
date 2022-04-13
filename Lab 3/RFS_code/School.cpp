// School.cpp: implementation of the CSchool class.
//
//////////////////////////////////////////////////////////////////////
#include "School.h"
#include "Student.h"
#include "RFS.h"
#include "string.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CSchool::CSchool(char filename[])
                           : rfs(sizeof(CStudent),filename)
{   }
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
// Add New Student Function
// getting new student data and add the new student to school
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
bool CSchool::AddNewStudent()
{
	CStudent NewStudent;
	//CleanScreen();
	cout<<"\t\t\tAdding New Student\n\n";
	cout<<"Student Number : ";
	cin>>NewStudent.m_Number;
	cin.ignore(); // to avoid bug in getline
	cout<<"Student Name : ";
	cin.getline(NewStudent.m_Name,100);
	for(int i=0;i<10;i++)
	{
		cout<<"% Grade of Subject # "<<i+1<<" : ";
		cin>>NewStudent.m_SubjectGrade[i];
	}
	return(rfs.put(&NewStudent));
//append new student to school
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
// Remove Student Function
// remove student from school.
// Removes the first occurrence of the student number
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
bool CSchool::RemoveStudent()
{
	CStudent Student;
		unsigned int number,i;
	//CleanScreen();
	cout<<"\t\t\tRemove Student\n\n";
	cout<<"Enter Student Nnumber to be removed : ";
	cin>>number;    //get student number
	i=0;
	if( ! rfs.get(&Student,i++) )
		return false;
	//loop if not inteded student or student is deleted
	while((number!=Student.m_Number)|| (!Student.isActive()))
	{
		if( ! rfs.get(&Student,i++) )
			return false;
	}
	// at this point the CStudent object holds the intended
	// student  otherwise if the student does not exist the
    // function fails

	//now removes the student from school
	return( rfs.del(&Student) );
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
// Modify Student Function
// modify student data. The function displays old data
// and asks for new one. Then it updates the data
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
bool CSchool::ModifyStudent()
{
	CStudent Student;
	unsigned int number,location;
	cout<<"\t\t\tModifying Student\n\n";
	cout<<"Enter Student Number to be modified : ";
	cin>>number; //get student number to be modified
	location=0;
	if( ! rfs.get(&Student,location++) )
		return false;
	//loop if not inteded student or student is deleted
	while((number!=Student.m_Number)||(!Student.isActive()))
	{
		if( ! rfs.get(&Student,location++) )
			return false;
	}
	location--;
		// the CStudent object holds the intended
// student to be modified
	cout<<"Old Number : "<<Student.m_Number<<endl;
	cout<<"New Number : ";
	cin>>Student.m_Number;
	cout<<"Old Student Name : "<<Student.m_Name
                     <<endl;
	cout<<"New Student Name : ";
	cin.getline(Student.m_Name,100);
	for(int i=0;i<10;i++)
	{
		cout<<"Old % Grade of Subject # "<<i+1<<
                                   " : "<<Student.m_SubjectGrade[i]<<endl;
		cout<<"New % Grade of Subject # "<<i+1<<
                                    " : ";
		cin>>Student.m_SubjectGrade[i];
	}
	return( rfs.put(&Student,location) );
// update student data
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
// Search for Student Function
// search for the first matched student name and displays its data
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
bool CSchool::SearchForStudent()
{
	CStudent Student;
	unsigned int location;
	char name[100];
	cout<<"\t\t\tSearch for Student\n\n";
	cin.ignore(); // for getline bug
	cout<<"Enter Student Name to Search for : ";
	cin.getline(name,100);
	location=0;
	if(! rfs.get(&Student,location++) )
		return false;
	//loop if not inteded student or student is deleted
	while((strcmp(name,Student.m_Name))||(!Student.isActive()))
	{
		if(! rfs.get(&Student,location++) )
			return false;
	}
	location--;
	// CStudent object holds inteded student
	// display student data on screen
	cout<<"Student Number : "
       <<Student.m_Number<<endl;
	cout<<"Student Name : "<<Student.m_Name<<endl;
	for(int i=0;i<10;i++)
		cout<<"% Grade of Subject # "<<i+1<<
       " : "<<Student.m_SubjectGrade[i]<<endl;
	return true;
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
//		 Sort Function
// sort students according to their results in a specified subject
// sorting is done using bubble sort (the most easy algorithm)
// Note: deleted records will be moved to the end of file
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
bool CSchool::Sort()
{
	CStudent Student1,Student2;
	unsigned int Subject,Loc1,Loc2;
	unsigned int NRecords;
	cout<<"\t\t\t\tSort\n\n";
	cout<<"Enter Subject Number to sort according to : ";
	cin>>Subject;
	Subject--;
	NRecords= rfs.GetNumberOfRecords();
	cout<<"Sorting ...\n";
	for(Loc1=0;Loc1<NRecords-1;Loc1++)
	{
        for(Loc2=Loc1+1;Loc2<NRecords;Loc2++)
		{
            if(! rfs.get(&Student1,Loc1) )
                return false;
			if(! rfs.get(&Student2,Loc2) )
                return false;
			if(!Student2.isActive())
                continue;
            if((!Student1.isActive())||(Student2.m_SubjectGrade[Subject]>Student1.m_SubjectGrade[Subject]))
			{
			    rfs.put(&Student2,Loc1);
                rfs.put(&Student1,Loc2);
			}
		}
	}
	cout<<"Sorting completed.\n";
	Loc1=0;
	while((rfs.get(&Student1,Loc1++))&&(Student1.isActive()))
	{
		cout<<"Student Number : "<<Student1.m_Number;
		cout<<"\t\tStudent Name : "<<Student1.m_Name<<endl;
		cout<<"\t\t\t% Grade of Subjects\n";
		for(Subject=0;Subject<10;Subject++)
			cout<<" # "<<Subject+1<< "\t";
		cout<<endl;
		for(Subject=0;Subject<10;Subject++)
            cout<<Student1.m_SubjectGrade[Subject]<<"\t";
		cout<<endl;
	}
	return true;
}
