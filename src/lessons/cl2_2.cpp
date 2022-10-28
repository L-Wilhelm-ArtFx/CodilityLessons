#include "utils.h"

// ===== SOLUTION START =====

#include <unordered_map>

int solution(vector<int> &A)
{
	std::unordered_map<int, unsigned int> map;
	for (auto x : A)
	{
		auto k = map.find(x);
		if (k == map.end())
		{
			map.insert({x, 0});
		}
		else
		{
			(*k).second = (*k).second + 1;
		}
	}

	for (auto &p : map)
	{
		if (p.second % 2 == 0)
		{
			return p.first;
		}
	}
	return -1;
}

// ===== SOLUTION END =====

int main(int argc, char const *argv[])
{
	initLesson();

	std::vector<int> testSet[]{
		{1, 1, 3, 3, 6, 6, 4},
		{1, 2, 2, 2, 1},
		{99999, 3, 5, 5, 5, 5, 5, 5, 3},
	};

	size_t c = 0;
	for (auto &x : testSet)
	{
		auto result = solution(x);
		printf("#%zu\n", c++);
		printf("Input: %s\n", vectorStr(x).c_str());
		printf("Output: %d\n", result);
		printf("\n");
	}

	return 0;
}
