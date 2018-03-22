#ifndef DOC_EXCEPTION_H
#define DOC_EXCEPTION_H

#include <string>
using namespace std;

class doc_exception
{
public:
	doc_exception(string err_str)
		:m_err(err_str)
	{
		
	}
	virtual ~doc_exception()
	{

	}
	string Error()
	{
		return m_err;
	}
protected:
	string m_err;
};
#endif