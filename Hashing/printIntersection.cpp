#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


void intersection(int input1[], int input2[], int size1, int size2) 
{
	unordered_map<int, int> m;
	/*unordered_map<int, bool> m2;*/


	for(int i=0;i<size1;i++)
		m[input1[i]]++;

	for(int i=0;i<size2;i++)
	{
		if(m[input2[i]] >= 1)
		{
			cout << input2[i] << endl;
			m[input2[i]]--;
		}
	}


	/*for(int i=0;i<size1;i++)
		if(m[ input1[i] ] > 1 && m2[ input1[i] ] == false)
		{
			cout << input1[i] << endl;
			m2[input2[i]] = true;
		}*/

}


int main()
{
	int input1[] = {2,6,1,2};
	int input2[] = {1,2,3,4,2};

	int size1 = 4;
	int size2 = 5;

	intersection(input1,input2,size1,size2);






}