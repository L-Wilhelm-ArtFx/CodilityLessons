#include "utils.h"

// ===== SOLUTION START =====

#include <algorithm>

vector<int> solution(vector<int> &A, int K)
{

	vector<int> B;
	B.reserve(A.size());

	for (int i = 0; i < A.size(); i++)
	{
		int shifted = i - K;
		if (shifted < 0)
		{
			shifted += (int)(-(i - K) / (int)A.size() + 1) * (int)A.size();
		}

		// same as
		while (shifted < 0)
		{
			shifted += (int)A.size();
		}

		int cycled = shifted % A.size();
		B.push_back(A[cycled]);
	}

	return B;
}

// ===== SOLUTION END =====

int main(int argc, char const *argv[])
{
	initLesson();

	std::pair<std::vector<int>, int> testSet[]{
		{{1, 2, 3, 4}, /**/ 5},
		{{1, 2, 3, 4}, /**/ 500},
		{{1}, /**/ 5},
	};

	size_t c = 0;
	for (auto &x : testSet)
	{
		auto result = solution(x.first, x.second);
		printf("#%zu\n", c++);
		printf("Input: %s, %d\n", vectorStr(x.first).c_str(), x.second);
		printf("Output: %s\n", vectorStr(result).c_str());
		printf("\n");
	}

	return 0;
}