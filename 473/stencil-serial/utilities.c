/*
 * Jordan Drakos
 * CSCI 473 - Stencil Serial
 * utilities.c - Provides utility functions for the stencil program.
 * 25/01/2023 (created)
 * 29/01/2023 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

/*
 * Function:  malloc2D
 * Purpose:   Allocate a 2D array of user-specified size
 */
double **malloc2D(int rows, int cols) {
  double **x = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; ++i) {
    x[i] = (double *)malloc(cols * sizeof(double));
  }

  return x;
}//malloc2D

/*
 * Function:  fill2D
 * Purpose:   Fill a 2D array with initial values
 */
void fill2D(double **x, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    double *curr = x[i];
    curr[0] = curr[cols-1] = 1.0;
    for (int j = 1; j < (cols-1); ++j) {
      curr[j] = 0.0;
    }
  }
}//fill2D

/*
 * Function:  print2D
 * Purpose:   Print an array's data to the screen
 */
void print2D(double **x, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      printf("%.2f\t", x[i][j]);
    }
    printf("\n");
  }
}//print2D

/*
 * Function:  write_file
 * Purpose:   Write the data to an output file; used to create initial data file
 */
void write_file(double** x, int rows, int cols, char* out_file) {
  FILE *fp = fopen(out_file, "w");
  fwrite(&rows, 1, sizeof(int), fp);
  fwrite(&cols, 1, sizeof(int), fp);

  for (int i = 0; i < rows; ++i) {
    fwrite(x[i], 1, (cols * sizeof(double)), fp);
  }

  fclose(fp);
}//write_file

/*
 * Function:  read_file
 * Purpose:   Read data contained within an input file
 */
double **read_file(char* in_file, int *row_pt, int *col_pt) {
  FILE *fp = fopen(in_file, "r");
  if (fp == NULL) {
    printf("Error opening file: file does not exist.\n");
    exit(EXIT_FAILURE);
  }

  fread(row_pt, 1, sizeof(int), fp);
  fread(col_pt, 1, sizeof(int), fp);

  double **x = malloc2D(*row_pt, *col_pt);
  for (int i = 0; i < *row_pt; ++i) {
    fread(x[i], 1, (*col_pt * sizeof(double)), fp);
  }

  fclose(fp);
  return x;
}//read_file

/*
 * Function:  write_data
 * Purpose:   Write current state of data to a file; used to create final data file
 */
void write_data(double **x, int rows, int cols, char *data_file) {
  FILE *fp = fopen(data_file, "w");
  for (int i = 0; i < rows; ++i) {
    fwrite(x[i], 1, (cols * sizeof(double)), fp);
  }

  fclose(fp);
}//write_data

/*
 * Function:  append_data
 * Purpose:   Append current state of data to a file; for use in .raw outputs
 */
void append_data(double **x, int rows, int cols, char *data_file) {
  FILE *fp = fopen(data_file, "a");
  for (int i = 0; i < rows; ++i) {
    fwrite(x[i], 1, (cols * sizeof(double)), fp);
  }

  fclose(fp);
}//append_data

/*
 * Function:  nine_point
 * Purpose:   Performs a nine-point stencil operation defined as
 *            (NW + N + NE + E + SE + S + SW + W + C) / 9.0
 */
void nine_point(double **x, double **newx, int rows, int cols) {
  for (int i = 1; i < (rows - 1); ++i) {
    for (int j = 1; j < (cols - 1); ++j) {
      newx[i][j] = (x[i-1][j-1] + x[i-1][j]   + x[i-1][j+1] +
                    x[i][j+1]   + x[i+1][j+1] + x[i+1][j] +
                    x[i+1][j-1] + x[i][j-1]   + x[i][j]) / 9.0;
    }
  }
}//nine_point
