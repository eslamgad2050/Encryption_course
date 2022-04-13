// School.h: interface for the CSchool class.
//
//////////////////////////////////////////////////////////////////////
#if !defined SchoolInclude
#define SchoolInclude
#include "RFS.h"
class CSchool
{
    private:
        RFS rfs;
	public:
		CSchool(char filename[]);
		bool AddNewStudent();
		bool RemoveStudent();
		bool ModifyStudent();
		bool SearchForStudent();
		bool Sort();
};
#endif
