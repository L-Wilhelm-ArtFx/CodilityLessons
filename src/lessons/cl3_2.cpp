#include "utils.h"

// ===== SOLUTION START =====

#include <algorithm>

int solution(vector<int> &A)
{

	std::sort(A.begin(), A.end(), std::less<int>());

	int lastPlusOne = 1;

	for (auto x : A)
	{
		if (lastPlusOne != x)
		{
			return lastPlusOne;
		}
		lastPlusOne = x + 1;
	}

	return lastPlusOne;
}

// ===== SOLUTION END =====

int main(int argc, char const *argv[])
{
	initLesson();

	std::vector<int> testSet[]{
		{1, 2, 4, 3, 7, 6},
		{6, 5, 4, 3, 2},
		{1, 2, 3},
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
