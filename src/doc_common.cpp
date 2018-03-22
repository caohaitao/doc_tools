#include "doc_common.h"

void doc_common::SplitString(string &str_in, char spliter, vector<string>& datas)
{
	char *refstr = new char[str_in.size()+1];
	memset(refstr,0,str_in.size()+1);
	int nsize = 0;
	for (int i=0;i<str_in.length();i++)
	{
		if (str_in[i]!=spliter)
		{
			refstr[nsize] = str_in[i];
			nsize++;
		}
		else
		{
			if (strcmp(refstr,"") != 0)
			{
				datas.push_back(refstr);
				memset(refstr,0,str_in.size()+1);
				nsize = 0;
			}

		}
	}
	if (strcmp(refstr,"")!=0)
	{
		datas.push_back(refstr);
	}
	delete[] refstr;
}

