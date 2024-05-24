#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

static void normalizeDebt(std::vector<std::vector<int>>& debtMatrix, int rowIndex) {
	auto matrixSize = debtMatrix.size();

	for (int i = 0; i < matrixSize; i++) {
		auto debtFromRow = debtMatrix[rowIndex][i];
		auto debtToRow = debtMatrix[i][rowIndex];
		if (debtFromRow > debtToRow) {
			debtMatrix[rowIndex][i] = debtFromRow - debtToRow;
			debtMatrix[i][rowIndex] = 0;
		}
		else if (debtFromRow < debtToRow) {
			debtMatrix[rowIndex][i] = 0;
			debtMatrix[i][rowIndex] = debtToRow - debtFromRow;
		}
		else {
			debtMatrix[rowIndex][i] = 0;
			debtMatrix[i][rowIndex] = 0;
		}
	}
}

int main() {
	std::vector<std::vector<int>> debt = { {0, 90000, 40000, 80000, 75000},
										  {0, 0, 40000, 40000, 40000},
										  {0, 50000, 0, 40000, 75000},
										  {0, 40000, 40000, 0, 40000},
										  {0, 45000, 40000, 45000, 0} };

	for (int i = 0; i < debt.size(); i++) {
		normalizeDebt(debt, i);
	}

	size_t maxDigits = 0;
	std::for_each(debt.begin(), debt.end(), [&](std::vector<int>& row) {
		std::for_each(row.begin(), row.end(), [&](int const& num) {
			size_t currentDigits = std::to_string(num).length();
			if (currentDigits > maxDigits) {
				maxDigits = currentDigits;
			}
		});
	});

	std::for_each(debt.begin(), debt.end(), [&](std::vector<int>& row) {
		std::for_each(row.begin(), row.end(), [&](int const& num) {
			std::cout << std::setw(maxDigits) << std::left << num << " ";
		});
		std::cout << std::endl;
	});
}
