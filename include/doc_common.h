#ifndef DOC_COMMON_H
#define DOC_COMMON_H
#include <string>
#include <vector>
using namespace std;

class doc_common
{
public:
	static void SplitString(string &str_in, char spliter, vector<string>& datas);
};
#endif