#include<iostream>
#include<string>
#include<vector>


using namespace std;

//Space Optimization!!
//Fast Searching!!


class TrieNode
{
public:
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data)
	{
		this->data =  data;
		children  = new TrieNode*[26];

		for(int i=0;i<26;i++)
			children[i] = NULL;

		isTerminal = false;
	}
};


class Trie
{
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode('\0');

	}

private:
	void insertWord(TrieNode*root,string word)
	{
		//base case
		if(word.size() == 0)
		{
			root->isTerminal = true;
			return;
		}
		//Calculation
		int index = word[0] -'a';
		TrieNode *child;

		if(root->children[index] != NULL)
			child = root->children[index];
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		//Recursive Call
		insertWord(child,word.substr(1));
	}

public:

	void insertWord(string word)
	{
		insertWord(root,word);

	}

private:
	void autoComplete(TrieNode*root, vector<string> input, string pattern) 
	{

        vector<string> output;
        for(int i=0;i<input.size();i++)
		{
			string s = input[i];
			for(int j=0;j<s.size();j++)	
				insertWord(s);
		}

        TrieNode *temp = root;

        int flag = 0;
        for(int i=0;i<pattern.size();i++)
        {
        	int index = pattern[i] - 'a';
        	if(temp->children[index] != NULL)
        		temp = temp->children[index];
        	else
        	{
        		flag = 1;
        		break;
        	}

        }

        if(flag == 1) //No matching
        {
        	cout << "(Empty) There is no word which starts with " << pattern << endl;
        	return;
        }


        if(temp->isTerminal == true)
        	cout << pattern << endl;

        string extra = pattern; 
        
        for(int i=0;i<26;i++)
        {
        	if(temp->children[i] != NULL && temp->children[i]->isTerminal == true ) 
        	{	
        		extra = extra  + char('a' + i);
        		cout << extra << endl;
        		temp = temp->children[i];
        		i=0;  //starting the loop from start over again
        	}

        	if(temp->children[i] != NULL && temp->children[i]->isTerminal == false ) 
        	{	
        		extra = extra  + char('a' + i);
        		temp = temp->children[i];
        		i=0; //starting the loop from start over again
        	}

        }

    }



public:
	void autoComplete(vector<string> input, string pattern)
	{
		autoComplete(root,input,pattern);
	} 


};


int main()
{
	Trie first;
	vector<string> vect;
	vect.push_back("do");
	vect.push_back("dont");
	vect.push_back("no");
	vect.push_back("not");
	vect.push_back("note");
	vect.push_back("notes");
	vect.push_back("noze");
	vect.push_back("den");

	string pattern = "no";

	first.autoComplete(vect,pattern);


}


