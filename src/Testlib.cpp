#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int flag;
void print(char a, char b, int diff) {
  if ((diff+a-'0'+b-'0')%10 != 0) flag = 1;
  if (flag) putchar((diff+a-'0'+b-'0')%10+'0');
}

int main()
{
  int fd = 0;
  struct stat state;
  fstat(fd, &state);
  char* addr = (char *)mmap(NULL, state.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  int len = state.st_size;

  int pos = 0, len1 = 0, len2 = 0;
  while (len1 < len && isdigit(addr[len1])) len1 ++;
  pos = len1;
  while (pos < len && !isdigit(addr[pos])) pos ++;
  while (len2+pos < len && isdigit(addr[len2+pos])) len2 ++;
  int ptr = len1 > len2 ? len1 : len2;

  // [0, len1-1] [pos, pos+len2-1]
  #define s1(i) ((0<=i&&i<len1)?addr[len1-i-1]:'0')
  #define s2(i) ((0<=i&&i<len2)?addr[pos+len2-i-1]:'0')

  while (ptr >= 0) {
    int i = ptr - 1;
    while (i >= 0 && s1(i) - '0' + s2(i) - '0' <= 9) i --;
    int j = i + 1;
    while (j < ptr && s1(j) - '0' + s2(j) - '0' + 1 > 9) j ++;
    if (i >= 0) {
      for (int k = ptr; k > j; k --) {
        print(s1(k), s2(k), 0);
      }
      for (int k = j; k > i; k --) {
        print(s1(k), s2(k), 1);
      }
    }
    else {
      for (int k = ptr; k >= 0; k --) {
        print(s1(k), s2(k), 0);
      }
      break;
    }
    ptr = i;
  }

  if (!flag) putchar('0');

   return(0);
}