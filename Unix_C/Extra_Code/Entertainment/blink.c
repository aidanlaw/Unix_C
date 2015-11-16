#include <stdio.h>

int main (void)
{
  printf("Sure, I've heard of blink-182, but what about ");
  for (int i=0;i<180;)
  {
    i++;
    printf("blink-%d, ", i);
  }
  printf("and blink-181?");
}
