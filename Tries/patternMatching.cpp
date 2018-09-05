// #include "TrieNode.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() 
	{
		this->count = 0;
		root = new TrieNode('\0');
	}

	private:
	void insertWord(TrieNode*root,string word)
	{
		//base case
		if(word.size() == 0)
			return;
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
	bool patternMatching(TrieNode*root, vector<string> vect, string pattern) 
	{
			
		

		for(int i=0;i<vect.size();i++)
		{
			string s= vect[i];
			for(int j=0;j<s.size();j++)	
				insertWord(s.substr(j));
		}	

		/*int index2 = 'e' - 'a';
		if(root->children[3]->children[index2] != NULL)
			cout << 'a' + index2 << " is present " <<endl;*/

		TrieNode* child = root;

		for(int i=0;i<pattern.size();i++)
		{
			int index = pattern[i] - 'a';
			

			if(child->children[index] == NULL)
				return false;
			
			else
				child = child->children[index];
		}

		return true;

	}

public:
	bool patternMatching(vector<string> vect, string pattern) 
	{
		return patternMatching(root,vect,pattern);
	}
};

int main()
{
	Trie first;
	vector<string> vect;
	vect.push_back("abc");
	vect.push_back("def");
	vect.push_back("ghi");
	vect.push_back("hg");

	string pattern = "hi";

	cout << first.patternMatching(vect,pattern) << endl;


}
