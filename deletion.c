/*
❗ Important Notes:

   => If you insert at the end: no shifting needed
   => If you insert at the beginning or middle: you need to shift right first

*/

#include <stdio.h>

int main()
{
   int arr[5] = {10, 20, 30, 40, 50};
   int size = 5;
   int pos = 2; // Delete from index 2 (which is value 30)

   // Shift elements left
   for (int i = pos; i < size - 1; i++)
   {
      arr[i] = arr[i + 1];
   }

   size--; // Decrease size

   // Print new array
   for (int i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }

   return 0;
}
