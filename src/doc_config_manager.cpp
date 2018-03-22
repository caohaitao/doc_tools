#include "doc_config_manager.h"
#include "doc_exception.h"
#include "doc_common.h"
#include <fstream>
#include <vector>
using namespace std;

doc_config_manager::doc_config_manager(string & file_path)
:doc_manager(file_path)
{

}

doc_config_manager::~doc_config_manager()
{
	
}

static void find_data_explain(doc_data & data,vector<string> & whole_lines,const int data_index)
{
	int index = data_index - 1;
	while (index>-1)
	{
		string & s = whole_lines[index];
		if (strncmp(s.c_str()," * Text",7) == 0)
		{
			for (int i=index+1;i<data_index-1;i++)
			{
				if (whole_lines[i].length()<3)
				{
					continue;
				}
				string sub_s = whole_lines[i].substr(3);
				data.s_exception.push_back(sub_s);
			}
			break;
		}
		else if (strncmp(s.c_str(),"#define",7)==0)
		{
			break;
		}
		index--;
	}
}

void doc_config_manager::run(vector<doc_data> & datas_out)
{
	ifstream ifs(m_file_path.c_str());
	if (!ifs)
	{
		throw doc_exception("file input not exist");
	}
	vector<string> whole_lines;
	while (!ifs.eof())
	{
		char line[256];
		ifs.getline(line,256);
		whole_lines.push_back(line);
	}
	ifs.close();

	for (int i=0;i<whole_lines.size();i++)
	{
		if (strncmp(whole_lines[i].c_str(),"#define",7)==0)
		{
			vector<string> splits;
			doc_common::SplitString(whole_lines[i],' ',splits);
			if (splits.size() != 3)
			{
				continue;
			}
			doc_data d;
			d.s_name = splits[2];
			find_data_explain(d,whole_lines,i);
			datas_out.push_back(d);
		}
	}
}
