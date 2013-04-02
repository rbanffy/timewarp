#include <errno.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int offset = 10; // How many seconds to advance every second
  struct timeval tv;
  struct timezone tz;
  int rc;
  while (1) {
    gettimeofday(&tv, &tz);
    tv.tv_sec += offset;
    rc = settimeofday(&tv, &tz);
    sleep(1); // TODO: make the jumps more subtle, in the millisecond range
    if (rc != 0) {
      printf("problem: errno = %d\n",errno);
      return -1;
    }
  }
  return 0;
}
