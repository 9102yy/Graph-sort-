#include<bits/stdc++.h>
#include"../../BinTree/HuffTree2.h"
const int MAX = 0x3f3f3f3f;
using namespace std;

int character[100];
HuffTree forest[100];
map <char, string> findcode; 

void Select(int n, int* s1, int* s2) {
	int i, min1 = MAX, min2 = MAX;
	*s1 = 0;
	*s2 = 0;
	for (i = 1; i <= n; i++) {
		if (forest[i].parent == 0) {
			if (forest[i].weight < min1) {
				min2 = min1;
				*s2 = *s1;
				min1 = forest[i].weight;
				*s1 = i;
			}
			else if (forest[i].weight < min2) {
				min2 = forest[i].weight;
				*s2 = i;
			}
		}
	}
}


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
		// 初始化森林 
		forest[i].weight = character[i];
		forest[i].parent = 0;
		forest[i].LC = 0;
		forest[i].RC = 0;
		forest[i].name = 'A' + i - 1;
	}
	
	for(int i = 27; i <= 51; i++)
	{
		forest[i].weight = 0;
		forest[i].parent = 0;
		forest[i].LC = 0;
		forest[i].RC = 0;
		
	}
	// 输入文章完成 下面进行 Huffman 编码 
	
	int s1, s2;
	for (int i = 27; i <= 51; i++) {
		Select(i - 1, &s1, &s2); 
		forest[i].weight = forest[s1].weight + forest[s2].weight;
		forest[s1].parent = i;
		forest[s2].parent = i;
		forest[i].LC = s1;
		forest[i].RC = s2;
	}
 	// 建立 huffman 数组完成 
	// DFS	查找各个的编码  forest[51] 一定是根节点 
	stack<int> mydfs;
	mydfs.push(51);
	while(!mydfs.empty())
	{
		int tmp = mydfs.top(); mydfs.pop();
		if(forest[tmp].LC == 0){
			// 已经查到了叶子节点 
			// 先把编码更新完成，再录入 map 中 
			if(forest[forest[tmp].parent].LC == tmp) // 就是左孩子 
			{
				forest[tmp].code = forest[forest[tmp].parent].code + "0";
			}else{
				forest[tmp].code = forest[forest[tmp].parent].code + "1";
			} 
			findcode.insert(pair<char, string>(forest[tmp].name, forest[tmp].code)); 
			 
		}else{
			// 仍是根节点  更新编码 并且左右孩子均进入栈中  
			// 判断是左孩子还是右孩子 
			if(forest[forest[tmp].parent].LC == tmp) // 就是左孩子 
			{
				forest[tmp].code = forest[forest[tmp].parent].code + "0";
			}else{
				forest[tmp].code = forest[forest[tmp].parent].code + "1";
			} 
			mydfs.push(forest[tmp].LC);
			mydfs.push(forest[tmp].RC);
			
		}
	}
	

	for(int i = 1; i <= 26; i++)
	{
		char str = 'A' + i - 1;
		cout<<str<<" : "<<character[i]<<endl;
	}
	cout<<"dream 的编码是 ："<<endl;
	cout<<findcode['D']<<" "<<findcode['R']<<" "<<findcode['A']<<" "<<findcode['M']<<" "<<findcode['E']<<endl;
	cout<<"qyy 的编码是 ："<<endl;
	cout<<findcode['Q']<<" "<<findcode['Y']<<" "<<findcode['Y']<<endl;
	return 0;
} 
