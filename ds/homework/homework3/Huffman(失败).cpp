#include<bits/stdc++.h>
#include"../../BinTree/HuffTree.h"
using namespace std;

int character[100];

void deal(char c)
{
	int x;
	if(c <= 'z' && c >= 'a'){
		x = c - 'a' + 1;
		character[x]++;
	}else if(c >= 'A' && c <= 'Z'){
		x = c - 'A' + 1;
		character[x]++;
	}
}

int main()
{
	vector< HuffTree< int > > forest;
	//BinTree<int> forest[100];
	char temp;
	int sum;
	freopen("dream.txt", "r", stdin);
	while(scanf("%c", &temp) != EOF)
	{
		deal(temp);
	}
	for(int i = 1; i <= 26; i++)
	{
		sum += character[i];
//		// ��ʼ��ɭ�� 
		HuffTree<int> tmp2; 
		tmp2._root -> data = character[i];
		forest.push_back(tmp2);
	}
		
	// ����������� ������� Huffman ���� 

	for(int i = 1; i <= 26; i++)
	{
		char str = 'A' + i - 1;
		cout<<str<<" : "<<character[i]<<endl;
	}



	return 0;
} 
