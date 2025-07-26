/*
❗ Important Notes:

   => Always check if size < max size before inserting
   => If you insert at the end: no shifting needed
   => If you insert at the beginning or middle: you need to shift right first

*/

#include <stdio.h>

int main()
{
   int arr[10] = {10, 20, 30, 40, 50};
   int size = 5;
   int pos = 2;
   int value = 99;

   if (size < 10)
   { // Check capacity
      for (int i = size; i > pos - 1; i--)
      {
         arr[i] = arr[i - 1];
      }

      arr[pos] = value;
      size++;

      for (int i = 0; i < size; i++)
      {
         printf("%d ", arr[i]);
      }
   }
   else
   {
      printf("Array is full.\n");
   }

   return 0;
}
