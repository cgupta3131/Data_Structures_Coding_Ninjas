#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void PairSum(int *input, int n)
{
	unordered_map<int, int> m;

	for(int i=0;i<n;i++)
		m[input[i]]++;

	

	for(int i=0;i<n;i++)
	{	
		
		if(input[i] == 0)
			continue;

		int total = m[input[i]] * m[ -1*input[i] ];

		for(int j=0;j<total;j++)
		{
			if(input[i] > 0)
				cout << -1*input[i] << " " << input[i] << endl;
			else
				cout << input[i] << " " << -1*input[i] << endl;
		} 

		m[input[i]] = 0;
		m[-1*input[i]] = 0;


	}


	int count_zeros = m[0];
	int temp = count_zeros*(count_zeros-1) / 2;

	for(int i=0;i<temp;i++)
		cout << "0 0" << endl;

}

int main()
{

	int input[] = {2,1,-2,2,3,-2};

	int n = sizeof(input)/sizeof(input[0]);

	PairSum(input,n);


}