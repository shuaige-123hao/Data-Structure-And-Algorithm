#include <iostream>
#include <string>
using namespace std;
#define Index int

//abab才是相等前后缀
int* constructNext(string pattern) {
	//构造模式串的next数组
	int size = pattern.length();

	//空串直接匹配成功
	if (size == 0) {
		return NULL;
	}
	int* next = (int*)malloc(size * sizeof(int));
	next[0] = 0;
	for (int i = 1; i < size; i++) {
		int j = next[i - 1];
		//ababc 要算c的前后缀相等，看next[3],跳回去，看pattern【2】是否等于pattern【4】

		//如果不等,但可能还存在一个更短的相等前后缀，于是我们让：，j往回跳，i那边也一定有相同后缀
		
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		if (pattern[i] == pattern[j]) j++;
		next[i] = j;

	}
	return next;
}
Index KMP(string s, string pattern) {
	//得到next
	int* next = constructNext(pattern);
	if (next == NULL) {
		return -1;
	}
	int i,j ;
	i = j = 0;
	//开始比较   匹配次数=i前进n次+j回退（<=n) O（n）+O（m）=O（n+m)
		while(i < (int)s.size() && j < (int)pattern.size()){
			
			if (s[i] == pattern[j]) {
				i++;
				j++;

			}
			else {
				//i继续前进

				
				if (j == 0) {
					i++;
				}
				//j跳回next[j-1]索引
				else { 
					j = next[j - 1];
				}

			}
			

			

		}
		free(next);
		if (j == pattern.size()) {
			//返回主串索引，多-一个，i多+一个
			return i - j;
		}
		else {
			return -1;
		}

}
int main() {
	string a = "acabedwhqhdiuwhudhweuha";
	string b = "abab";
	int index=KMP(a, b);

}