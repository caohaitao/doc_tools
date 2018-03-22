#include "stdio.h"
#include "string.h"
#include "doc_exception.h"
#include "doc_manager_producer.h"
int main(int argc,char ** argv)
{
	char file_path[128]="";
	if(argc < 2)
	{
		printf("please input the conf file path int param 1\n");
		return -1;
	}
	strcpy(file_path,argv[1]);

	string s_file_path(file_path);
	doc_manager * manager = doc_manager_producer::CreateAManager(s_file_path);
	try
	{
		vector<doc_data> datas_out;
		manager->run(datas_out);
	}
	catch (doc_exception & err)
	{
		printf("err:%s\n",err.Error().c_str());
		delete manager;
		return -1;
	}
	delete manager;

	return 0;
}