#include <bits/stdc++.h>

unsigned int get_diagonal_cells(unsigned int diag_number, unsigned int n) {
  uint dcount = 2 * n - 1;
  uint dmean = dcount / 2;
  if (diag_number <= dmean)
    return diag_number + 1;
  else
    return dcount - diag_number;
}

unsigned int get_possibilities(unsigned int matrix_size,
                               unsigned int invalid_cell_count) {
  unsigned int mat_cells = matrix_size * matrix_size;
  if (mat_cells <= invalid_cell_count)
    return 0;
  else
    return mat_cells - invalid_cell_count;
}

// takes matrix size and return total 2 knight arrangements.
unsigned int solve_two_knights(unsigned int n) {
  unsigned int result = 0u;
  for (unsigned int x = 0; x < n; ++x) {
    for (unsigned int y = 0; y < n; ++y) {
      unsigned int invalid_cell_count = 0u;
      invalid_cell_count +=
          2 * (n - 1); // for each cell; exclude each row and column of knight.
      unsigned int diag1 = y + x;
      unsigned int diag2 = y - x + n - 1;

      uint diag1_excluded = get_diagonal_cells(diag1, n) - 1;
      uint diag2_excluded = get_diagonal_cells(diag2, n) - 1;

      invalid_cell_count += diag1_excluded;
      invalid_cell_count += diag2_excluded;
      ++invalid_cell_count; // to include current cell to invalid cell count

      result += get_possibilities(n, invalid_cell_count);
    }
  }
  return result / 2; // 1 for the cell the current queen is placed in..
}

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  unsigned int matrix_size = 0u;
  std::cin >> matrix_size;

  for (unsigned int i = 1; i <= matrix_size; ++i) {
    std::cout << solve_two_knights(i) << std::endl;
  }

  return 0;
}
