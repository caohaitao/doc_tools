#ifndef DOC_MANAGER_PRODUCER
#define DOC_MANAGER_PRODUCER
#include "doc_manager.h"

class doc_manager_producer
{
public:
	static doc_manager * CreateAManager(string& file_path);
};

#endif