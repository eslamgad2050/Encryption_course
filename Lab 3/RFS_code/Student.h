// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////
#if !defined StudentInclude
#define StudentInclude
#include "RFS.h"
class CStudent : public Record
{
public:
	unsigned int m_Number;
	char m_Name [100];
	float m_SubjectGrade [10];
public:
	CStudent();
	virtual ~CStudent();
};
#endif
