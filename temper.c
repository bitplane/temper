/*
 * Standalone temperature logger
 *
 */

#include <stdio.h>
#include <errno.h>
#include <time.h>
#include "pcsensor.h"

/* Calibration adjustments */
/* See http://www.pitt-pladdy.com/blog/_20110824-191017_0100_TEMPer_under_Linux_perl_with_Cacti/ */
static float scale = 1.0287;
static float offset = -0.85;

float read_temp() {
  int i;
  float tempc = 0.0000;

  for (i = 0; i < 4; i++) {
    usb_dev_handle* lvr_winusb = pcsensor_open();
    if (!lvr_winusb) {
      sleep(3);
      continue;
    }
    tempc = pcsensor_get_temperature(lvr_winusb);
    pcsensor_close(lvr_winusb);

  /* Read can fail silently with a 0.0 return; repeat until we get a not zero
   * value or until we have read a zero value 3 times (just in case the
   * temperature really is zero */
    if (tempc < -0.0001 || tempc > 0.0001) { return tempc; }
  }
  errno = ENOENT;
  return tempc;
}

float correct(float tempc) {
  return (tempc * scale) + offset;
}

void print_temp(float tempc) {
  struct tm *utc;
  time_t t;
  t = time(NULL);
  utc = localtime(&t);

  char dt[80];
  strftime(dt, 80, "%F %T", utc);

  printf("%s,%2.2f\n", dt, tempc);
  fflush(stdout);
}

int main(){
  float tempc = read_temp();

  if (errno == ENOENT) {
    return 1;
  } else {
    print_temp(correct(tempc));
    return 0;
  }
}
