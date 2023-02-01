/*
 * Jordan Drakos
 * CSCI 473 - Stencil Serial
 * print-2d.c - Prints the data created using make-2d.c to the screen in
 * a human-readable format.
 * 25/01/2023 (created)
 * 29/01/2023 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *argv[]) {
  int num_rows = 0, num_cols = 0;
  double **x;

  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *in_file = argv[1];
  printf("Reading in file: %s\n", argv[1]);
  x = read_file(in_file, &num_rows, &num_cols);
  print2D(x, num_rows, num_cols);
  free(x);
  exit(EXIT_SUCCESS);
}
