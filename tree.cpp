#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

vector<vector<string>> tree;

void make_tree(int size) {
	int height = 4 * size + 10;
	int width = 8 * size - 1;
	tree.resize(height);
	for (int i = 0; i < height - 4; ++i)
		tree[i].assign(width, "*");
	int num = 1;
	int x = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < size + i; ++j)
		{
			for (int k = 0; k < (width - num) / 2; ++k)
				tree[x][k] = " ";
			++x;
			num += 2;
		}
		num -= 4;
	}
	num = 1;
	x = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < size + i; ++j)
		{
			for (int k = width - 1; k > (width - 1) / 2 + num / 2; --k)
				tree[x][k] = " ";
			++x;
			num += 2;
		}
		num -= 4;
	}

	for (int i = height - 4; i < height; ++i)
	{
		tree[i].assign(width, "|");
		for (int j = 0; j < (width - 1) / 2 - 2; ++j)
			tree[i][j] = " ";
		for (int j = width - 1; j > (width - 1) / 2 + 2; --j)
			tree[i][j] = " ";
	}
}

void paint_tree() {
	for (int i = 0; i < tree.size(); ++i)
	{
		for (int j = 0; j < tree[i].size(); ++j)
		{
			cout << tree[i][j];
		}
		cout << endl;
	}
}

void beauty_tree() {
	int count = 0;
	int r = rand() % 10000000;
	while(count < 22) {
		count = 0;
		for (int i = 0; i < tree.size(); ++i) {
			for (int j = 0; j < tree[i].size(); ++j) {
				if (tree[i][j] == "#")
					count++;
			}
		}
		if (tree[r % tree.size()][r % tree[r % tree.size()].size()] == "*" && r % 2 == 0)
			tree[r % tree.size()][r % tree[r % tree.size()].size()] = "#";
		else if (tree[r % tree.size()][r % tree[r % tree.size()].size()] == "*" && r % 3 == 0)
			tree[r % tree.size()][r % tree[r % tree.size()].size()] = "$";
		else if (tree[r % tree.size()][r % tree[r % tree.size()].size()] == "*")
			tree[r % tree.size()][r % tree[r % tree.size()].size()] = "&";
		r /= 10;
		if(r <= 10)
			r=rand() % 123123124;
	}
}

int main() {
	srand(time(0));
	int size = 6;
	make_tree(size);
	int x = 1;
	while(x) {
		system("clear");
		make_tree(size);
		beauty_tree();
		paint_tree();
		sleep(2);
	}
	return 0;
}
