#include "utils.h"

#define START(x) printf("Lesson")
// ===== SOLUTION START =====

#include <bitset>

int solution(int N)
{
	std::bitset<sizeof(int) * 8> bits(N);
	int largestGap = 0;
	int gapCounter = 0;

	size_t i = 0;
	// Loop until first active bit
	while (i < bits.size() && bits[i] == 0)
	{
		++i;
	}

	while (i < bits.size())
	{
		int v = bits[i];
		if (v)
		{
			if (gapCounter > largestGap)
			{
				largestGap = gapCounter;
			}
			gapCounter = 0;
		}
		else
		{
			++gapCounter;
		}
		++i;
	}

	return largestGap;
}

// ===== SOLUTION END =====

int main(int argc, char const *argv[])
{
	initLesson();

	int testSet[]{
		0,
		10,
		17,
		INT_MAX,
		INT_MAX - 1,
		INT_MIN,
		INT_MIN + 1,
	};

	size_t c = 0;
	for (auto x : testSet)
	{
		auto result = solution(x);
		printf("#%zu\n", c++);
		printf("Input: %d\n", x);
		printf("Output: %d\n", result);
		printf("\n");
	}

	return 0;
}
