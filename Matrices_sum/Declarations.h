#pragma once
#include <cstdio>
#include <cctype>
#include <iostream>
#include "Declarations.h"
#define dim 20

int InsertInt(int& n);

void InsertValue(int n, int a[dim][dim]);

void PrintMatrix(int n, int a[dim][dim]);

void SumOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]);

void DifferenceOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]);

void ProductOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]);

void QuotientOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]);
