#include "../stubs.h"
#include "../base.h"

#define MAXLINE BASE_SZ

int main (void)
{
  char fbuf[MAXLINE+1];
  char *fbufp;
  int c1;

  fbufp = fbuf;

  while ((c1 = nondet_int ()) != EOF)
  {
    if (isascii (c1) && isspace (c1))
      continue;
    if (c1 == '=')
      continue;

    /* BAD */
    *fbufp = c1;

    /* BAD */
    if (*fbufp++ == '\n')
    {
      if (fbufp <= fbuf)
	fbufp = fbuf;
      else if (*--fbufp != '\r') 
	fbufp++;

      /* BAD */
      *fbufp = EOS;
      fbufp = fbuf;
    }
  }

  /* force out partial last line */
  if (fbufp > fbuf)
  {
    /* BAD */
    *fbufp = EOS;
  }

  return 0;
}
