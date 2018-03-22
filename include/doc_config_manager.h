/**
 * doc_config_manager.h 
 *
 * Copyright (c) Unary Corporation. All Rights Reserved.
 *
 * Author:CaoHaitao
 * 
 */
#ifndef DOC_CONFIG_MANAGER_H
#define DOC_CONFIG_MANAGER_H
#include "doc_manager.h"

class doc_config_manager:public doc_manager
{
public:
	doc_config_manager(string & file_path);
	virtual ~doc_config_manager();

	virtual void run(vector<doc_data> & datas_out);

protected:
};

#endif