#include "../stubs.h"
#include "../base.h"

#define MAXLINE BASE_SZ

int main (void)
{
  char fbuf[MAXLINE+1];
  char *fbufp;
  int c1, c2, c3;

  fbufp = fbuf;

  while ((c1 = nondet_int ()) != EOF)
  {
    c2 = nondet_int ();
    if (c2 == EOF)
      break;

    c3 = nondet_int ();
    if (c3 == EOF)
      break;

    /* OK */
    *fbufp++ = c1;
    if (fbufp >= &fbuf[MAXLINE])
      fbufp = fbuf;

    /* OK */
    *fbufp++ = c2;
    if (fbufp >= &fbuf[MAXLINE])
      fbufp = fbuf;

    /* OK */
    *fbufp++ = c3;
    if (fbufp >= &fbuf[MAXLINE])
      fbufp = fbuf;
  }

  /* force out partial last line */
  if (fbufp > fbuf)
  {
    /* OK */
    *fbufp = EOS;
  }

  return 0;
}
