#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;



char* uniqueChar(char *str)
{
	unordered_map<char, int> ourmap;

	int length = strlen(str);
	char *final = new char [length];

	for(int i=0;i<length;i++)
		ourmap[ str[i] ]++;
	

	int j=0;
	for(int i=0;i<length;i++)
	{
		if(ourmap[ str[i] ] >= 1)
		{
			final[j] = str[i];
			j++;
			ourmap[str[i]] = 0;
		}
			
		else
			continue;
	}

	final[j] = '\0';


	return final;

}