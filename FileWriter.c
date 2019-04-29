#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
  printf("This is where I leave you. Enter tilda when you're done\n");
  FILE *fptr = fopen("ThoughtsOfATeenageMutantNinjaTurtle.txt", "a");
  if(!fptr)
  {
      fptr = fopen("ThoughtsOfATeenageMutantNinjaTurtle.txt", "wb");
  }
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  fprintf(fptr, "Date: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  char *line = NULL;
  size_t n = 0;
  ssize_t result = getdelim(&line, &n, 126,stdin);
  fprintf(fptr,"%s\n\n", line);
  free(line);
}
