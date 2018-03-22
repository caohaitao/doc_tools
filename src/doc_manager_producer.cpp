#include "doc_manager_producer.h"
#include "doc_config_manager.h"

doc_manager * doc_manager_producer::CreateAManager(string& file_path)
{
	return new doc_config_manager(file_path);
}

