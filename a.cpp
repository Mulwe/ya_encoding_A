#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

std::string *check(std::string s1, std::string s2)
{
	std::map<char, std::string> mapping;
	std::string *out = new std::string;
	out->resize((int)s1.size());
	for (int i = 0; i < (int)s1.size(); i++)
	{
		char c = 'P';
		std::map<char, std::string>::iterator p;
		mapping.insert(pair<char, std::string>(s1[i], ""));
		mapping.insert(pair<char, std::string>(s2[i], ""));
		if (s1[i] == s2[i])
		{
			p = mapping.find(s1[i]);
			if (p->second.length() == 0 || p->second.find('P') == std::string::npos)
				c = 'P';
			else
				c = 'I';
		}
		else if (s1[i] != s2[i])
		{
			p = mapping.find(s1[i]);
			(p->second.find('S') != std::string::npos) ? c = 'I' : c = 'S';
			p = mapping.find(s2[i]);
			if (s1.find(s2[i]) == std::string::npos)
				c = 'I';
			else
				(p->second.find('S') != std::string::npos) ? c = 'I' : c = 'S';
			mapping.find(s1[i])->second += c;
		}
		else
			c = 'I';
		p->second += c;
		(*out)[i] = c;
	}
	return (out);
}

int main(void)
{
	std::fstream f;
	std::string str, s, *output;
	f.open("./input_tests/input.txt", ios_base::in);
	if (f.is_open())
		f >> str >> s;
	cout << str << "\n"
		 << s << "\n";
	f.close();
	/* check(str, s); */
	if (!str.empty() && !s.empty())
	{
		output = check(str, s);

		cout << "\033[1;32m" << *output << "\033[0m\n";
		delete output;
	}
	else
		cout << "Str or s is empty\n";
	return 0;
}