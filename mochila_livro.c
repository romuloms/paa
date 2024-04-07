#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfItems;
int capacity;
int weights[100];
int values[100];
int table[100][100];

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int knapsack(int item, int capacity)
{
  if (item == -1)
    return 0;
  printf("item: %d capacity: %d\n", item, capacity);
  if (table[item][capacity] < 0)
  {
    int value;

    if (capacity < weights[item])
      value = knapsack(item - 1, capacity);
    else
      value = max(knapsack(item - 1, capacity), values[item] + knapsack(item - 1, capacity - weights[item]));


    table[item][capacity] = value;
  }

  return table[item][capacity];
}

int main(void) {
  memset(table, -1, sizeof(table));

  scanf("%d %d", &numberOfItems, &capacity);
  for (int i = 0; i < numberOfItems; i++)
    scanf("%d %d", &weights[i], &values[i]);
  
  printf("%d\n", knapsack(numberOfItems - 1, capacity));

  return 0;
}