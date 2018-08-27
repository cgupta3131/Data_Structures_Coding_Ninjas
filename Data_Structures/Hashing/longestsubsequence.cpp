
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int minimum(int *input, int n,int value1, int value2)
{
	int index1,index2;

	for(int i=0;i<n;i++)
	{
		if(input[i] == value1)
		{
			index1 = i;
			break;
		}

	}

	for(int i=0;i<n;i++)
	{
		if(input[i] == value2)
		{
			index2 = i;
			break;
		}

	}


	if(index1 > index2)
		return value2;
	else
		return value1;

}

vector<int> longestSubsequence(int *input, int n)
{

	unordered_map<int, bool> ourmap;
	unordered_map<int, bool> temp;

	int max = 0;
	int mid = 0;
	int no_left = 0;
	int no_right = 0;

	for(int i=0;i<n;i++)
		ourmap[ input[i] ] = true;	

	for(int i=0;i<n;i++)
		temp[ input[i] ] = false;	



	for(int i=0;i<n;i++)
	{

		if(temp[ input[i] ] == true) //means that input[i] has been already visited
			continue;


		temp[ input[i] ] = true; 

		int front = 0;
		while(1)
		{
			if( ourmap[ input[i]+front+1 ] ==  true   )
			{
				temp[ input[i]+front+1 ] =  true;	
				front++;			
			}

			else
				break;
		}


		int back = 0;
		while(1)
		{
			if( ourmap[ input[i] + back - 1 ] ==  true   )
			{
				temp[ input[i] + back-1 ] =  true;	
				back--;			
			}

			else
				break;
		}



		if(max < front-back+1)
		{
		
			max = front-back+1;
			mid = input[i];
			no_left = -1*back;
			no_right = front;
		}

		if(max == front-back+1)
		{
			int value1 = mid-no_left;
			int value2 = input[i] + back;

			int min = minimum(input,n,value1,value2);

			if(min == value2)
			{
				max = front-back+1;
				mid = input[i];
				no_left = -1*back;
				no_right = front;
			}

		}
		
	}

	vector<int> output;

	for(int i=0;i<max;i++)
		output.push_back( mid - no_left + i );

	return output;
	

}

int main()
{

	int input[] = {23, 13, 15, 21, 19, 11, 16,24};
	int n = sizeof(input)/sizeof(input[0]);

	vector<int> output = longestSubsequence(input,n);

	for(int i=0;i<output.size();i++)
		cout << output.at(i) << " ";
	cout << endl;

}