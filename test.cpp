#include <iostream>
#include <vector>
#include <cmath>

int frogJump(const std::vector<int> &heights, int currentStone, std::vector<int> &memo)
{
    if (currentStone == heights.size() - 1)
    {
        return 0; // Reached the last stone, no cost incurred.
    }

    if (memo[currentStone] != -1)
    {
        return memo[currentStone]; // Return memoized result if available.
    }

    int cost1 = std::abs(heights[currentStone] - heights[currentStone + 1]) + frogJump(heights, currentStone + 1, memo);
    int cost2 = std::abs(heights[currentStone] - heights[currentStone + 2]) + frogJump(heights, currentStone + 2, memo);

    // Choose the minimum cost and memoize the result.
    memo[currentStone] = std::min(cost1, cost2);
    return memo[currentStone];
}

int minTotalCost(const std::vector<int> &heights)
{
    std::vector<int> memo(heights.size(), -1); 
    return frogJump(heights, 0, memo);       
}

int main()
{
    int N;

    std::cin >> N;

    std::vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> heights[i];
    }

    int minCost = minTotalCost(heights);
    std::cout << minCost << std::endl;

    return 0;
}
