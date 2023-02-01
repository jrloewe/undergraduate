/*
 * Jordan Drakos
 * CSCI 473 - Stencil Serial
 * stencil-2d.c - Performs the nine-point stencil operation on input data for a
 * specified number of iterations, and writes the final state to an output data file
 * and all iterations to a raw file.
 * 25/01/2023 (created)
 * 29/01/2023 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <# iterations> <input_file> <output_file>"
           " <all iterations>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int num_iterations;
  if ((num_iterations = atoi(argv[1])) < 1) {
    printf("At least one iteration is required.\n");
    exit(EXIT_FAILURE);
  }

  char *initial_data = argv[2], *final_data = argv[3], *all_data = argv[4];
  // check that input/output files have different filenames
  if ((strcmp(initial_data, final_data) == 0) || (strcmp(initial_data, all_data) == 0) ||
      (strcmp(final_data, all_data) == 0)) {
        printf("Data files must all be different.\n");
        exit(EXIT_FAILURE);
  }

  int rows, cols;
  double **x = read_file(initial_data, &rows, &cols);
  double **newx = malloc2D(rows, cols);
  fill2D(newx, rows, cols);
  write_data(x, rows, cols, all_data);

  for (int i = 0; i < num_iterations; ++i) {
    nine_point(x, newx, rows, cols);
    append_data(newx, rows, cols, all_data);
    double **tmp = x;
    x = newx;
    newx = tmp;
  }

  write_file(x, rows, cols, final_data);
  free(x);
  free(newx);
  exit(EXIT_SUCCESS);
}
