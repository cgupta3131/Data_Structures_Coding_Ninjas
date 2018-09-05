#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;

int main()
{
	unordered_map<string, int> ourmap; //unordered_map is a template so we have to tell what 
					      //type of keys and values are there..Operations are done in O(1) time
	//insert
	pair<string, int> p("abc",1);
	ourmap.insert(p);

	ourmap["def"] = 2;



	//find or access
		cout << ourmap["abc"] << endl;
		cout << ourmap.at("abc") << endl;

		cout << "size is " << ourmap.size() << endl;
		//cout << ourmap.at("ghi") << endl; -> not allowed will show error
		cout << ourmap["ghi"] << endl; //this won't show error and will insert default value '0'
		cout << "size is " << ourmap.size() << endl;



		//check presence
		if(ourmap.count("ghi") == 0) //counts the number of times ghi key occurs and the value could be 0 or 1
			cout << "ghi is present" << endl;


		//erase
		ourmap.erase("ghi");
		cout << "size is " << ourmap.size() << endl;
}	

