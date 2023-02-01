/*
 * Jordan Drakos
 * CSCI 473 - Stencil Serial
 * utilities.h - Header file allowing usage of utility functions in utilities.c.
 * 25/01/2023 (created)
 * 28/01/2023 (last edited)
 */
#ifndef STENCIL_SERIAL_UTILITIES
#define STENCIL_SERIAL_UTILITIES

double **malloc2D(int rows, int cols);
void fill2D(double **x, int rows, int cols);
void print2D(double **x, int rows, int cols);
void write_file(double** x, int rows, int cols, char* out_file);
double **read_file(char* in_file, int *row_pt, int *col_pt);
void write_data(double **x, int rows, int cols, char *data_file);
void append_data(double **x, int rows, int cols, char *data_file);
void nine_point(double **x, double **newx, int rows, int cols);

#endif
