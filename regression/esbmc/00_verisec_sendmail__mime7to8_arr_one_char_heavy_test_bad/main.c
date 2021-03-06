#include "../stubs.h"
#include "../base.h"

#define MAXLINE BASE_SZ

int main (void)
{
  char fbuf[MAXLINE+1];
  int fb;
  int c1;

  fb = 0;
  while ((c1 = nondet_int ()) != EOF)
  {
    if (isascii (c1) && isspace (c1))
      continue;
    if (c1 == '=')
      continue;

    /* BAD */
    fbuf[fb] = c1;

    /* BAD */
    if (fbuf[fb] == '\n')
    {
      fb--;
      if (fb < 0)
	fb = 0;
      else if (fbuf[fb] != '\r') 
	fb++;

      /* BAD */
      fbuf[fb] = 0;
      fb = 0;
    }
    else
      fb++;
  }

  /* force out partial last line */
  if (fb > 0)
  {
    /* BAD */
    fbuf[fb] = 0;
  }

  return 0;
}
