#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


int main()
{

	unordered_map<string, int> ourmap;
	ourmap["abc"]  = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;


	unordered_map<string, int> :: iterator it;

	it = ourmap.begin();

	for( ; it!=ourmap.end() ; it++)
		cout << "Key : " << it->first << " Value : " << it->second << endl;

	

	cout << endl << endl;

	unordered_map<string, int> :: iterator it2 = ourmap.find("abc"); //find() returns an iterator
	ourmap.erase(it2); //erase function can ALSO take input as iterator pointing to that particular mapping
	//ourmap.erase(it2, it2 + 2) // will delete it2, it2+1, it2 +2 , it2+3

	it = ourmap.begin();

	for( ; it!=ourmap.end() ; it++)
		cout << "Key : " << it->first << " Value : " << it->second << endl;


	cout << endl << endl;




	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int> :: iterator it_vector = v.begin();

	while(it_vector != v.end() )
	{
		cout << *it_vector << endl;

		it_vector++;
	}






}