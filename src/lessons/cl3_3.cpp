#include "utils.h"

// ===== SOLUTION START =====

int solution(vector<int> &A)
{
	vector<int> diffs;
	diffs.reserve(A.size()); // TODO

	int sum = 0;

	{
		auto it = A.begin();
		while (it != A.end())
		{

			diffs.push_back(sum);

			sum += *it;

			++it;
		}
	}

	sum = 0;
	{
		auto it2 = diffs.rbegin();
		auto it = A.rbegin();
		while (it != A.rend())
		{

			sum += *it;

			*it2 = std::abs(*it2 - sum);
			// *it2 = *it2 - sum;

			++it;
			++it2;
		}
	}

	if (diffs.size() == 2)
		return diffs[1];

	auto itFind = diffs.begin() + 1;
	int min = *itFind;
	++itFind;
	while (itFind != diffs.end())
	{
		if (*itFind < min)
		{
			min = *itFind;
		}
		++itFind;
	}

	return min;
}

// ===== SOLUTION END =====

int main(int argc, char const *argv[])
{
	initLesson();

	std::vector<int> testSet[]{
		{3, 1, 2, 4, 3},
		{0, 0, 0, 3, 1, 0, 5, 0},
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
