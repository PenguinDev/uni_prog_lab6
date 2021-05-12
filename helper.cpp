#include "pch.h"
#include "helper.h"

bool is_numeric(std::string const& str)
{
	auto result = double();
	auto i = istringstream(str);

	i >> result;

	return !i.fail() && i.eof();
}

string to_std_string(CString const& src)
{
	return { src.GetString(), src.GetString() + src.GetLength() };
}
