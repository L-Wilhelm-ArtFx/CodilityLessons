#include "utils.h"

// ===== SOLUTION START =====

int solution(int X, int Y, int D)
{
	int diff = Y - X;
	return X == Y ? 0 : diff / D + (diff % D == 0 ? 0 : 1);
}

// ===== SOLUTION END =====

int main(int argc, char const *argv[])
{
	initLesson();

	struct Dat
	{
		int X, Y, D;
	} testSet[]{
		{1, 4, 3},
		{10, 20, 3},
		{21, 69, 5}};

	size_t c = 0;
	for (auto &x : testSet)
	{
		auto result = solution(x.X, x.Y, x.D);
		printf("#%zu\n", c++);
		printf("Input: X:%d, Y:%d, D:%d\n", x.X, x.Y, x.D);
		printf("Output: %d\n", result);
		printf("\n");
	}

	return 0;
}
