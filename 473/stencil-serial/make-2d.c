/*
 * Jordan Drakos
 * CSCI 473 - Stencil Serial
 * make-2d.c - Creates a data file with the initial conditions and boundary values.
 * 25/01/2023 (created)
 * 29/01/2023 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *argv[]) {
  int num_rows, num_cols;
  char *out_file;

  if (argc != 4) {
    printf("Usage: %s <# rows> <# cols> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Not specified in the assignment, but a minimum of four rows/columns seems to
  // be the best starting point based on our initial state and how the data is
  // manipulated in the stencil function.
  if ((num_rows = atoi(argv[1])) < 4 || (num_cols = atoi(argv[2])) < 4) {
    printf("At least four rows and four columns are required.\n");
    exit(EXIT_FAILURE);
  }

  double **x = malloc2D(num_rows, num_cols);
  out_file = argv[3];
  fill2D(x, num_rows, num_cols);
  write_file(x, num_rows, num_cols, out_file);
  free(x);
  exit(EXIT_SUCCESS);
}
