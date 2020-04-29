#include "CommandOps.h"
#include <iostream>

using namespace std;

void ExtractHash(string buffer, string& out1)
{
	int no = 0; int start = 0;
	for (int i = 0; i < buffer.length(); i++)
	{
		if (buffer[i] == '\n' && no == 0)
		{
			start = 1;
			no = 1;
			++i;
		}
		else if (buffer[i] == '\n')
			break;
		if (start == 1)
			out1 += buffer[i];
	}
}

string ExecuteCommand(string cmd)
{
	try
	{
		char buffer[128];
		string result;
		string out;
		FILE* pipe = _popen(cmd.c_str(), "r");
		if (!pipe)
		{
			throw std::runtime_error("pipe open failed");
		}
		try
		{
			while (!feof(pipe)) 
			{
				if (fgets(buffer, 128, pipe) != nullptr)
					result += buffer;
			}
		}
		catch (...)
		{
			_pclose(pipe);
			throw;
		}
		_pclose(pipe);
		ExtractHash(result, out);
		return out;
	}
	catch (...)
	{
		return "Error Generating Hash";
	}
}

string GetHashofFile(string cmd)
{
	string CmdToExec = "certutil -hashfile " + cmd;
	return ExecuteCommand(CmdToExec);
}