/**
 * doc_manager.h 
 *
 * Copyright (c) Unary Corporation. All Rights Reserved.
 *
 * Author:CaoHaitao
 * 
 */
#ifndef DOC_MANAGER_H
#define DOC_MANAGER_H
#include <string>
#include <vector>
using namespace std;

struct doc_data
{
	string s_name;
	vector<string> s_exception;
	string s_default;
};

class doc_manager
{
public:
	doc_manager(string& file_path);
	virtual ~doc_manager();

	virtual void run(vector<doc_data> & datas_out);
protected:
	string m_file_path;
};
#endif