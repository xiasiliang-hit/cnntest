#include "Jzon.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Jzon;


void mytest()  //std::istream &stream)
{
	Jzon::Node rootNode; //= parseStream(stream);
	Jzon::Parser parser;


	rootNode = parser.parseFile("response.json");

	for (Jzon::Node::iterator it = rootNode.begin(); it != rootNode.end(); ++it)
	{
		std::string name = (*it).first;
		Jzon::Node &node = (*it).second;

		std::cout << name << " = ";
		if (node.isValue())
		{
			if (node.isString())
			{
				cout << node.toString() << endl; 
			}
			else if (node.isNumber())
			{
				cout << node.toFloat() << endl;
			}
		}
		else if (node.isArray())
		{
			std::cout << "*Array*";
		}
		else if (node.isObject())
		{
			std::cout << "*Object*";
        }
		std::cout << std::endl;
    }

	const int& rate_limit = rootNode.get("rate_limit").toInt();
	const string& version = rootNode.get("api_latest_version").toString();

	cout << rate_limit << " rate" << endl;
	cout << version << " version" << endl;

/*
        const Jzon::Array& stuff = rootNode.get("listOfStuff");
        for (Jzon::Array::const_iterator it = stuff.begin(); it != stuff.end(); ++it)
        {
                std::cout << (*it).ToString() << std::endl;
        }
*/

}




int main(void)
{
mytest();//new istream())

}



