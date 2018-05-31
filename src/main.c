/*
 
This file is part of killman.

killman is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

killman is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with killman.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "killman_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns a string containing the current version of killman
// NOTE: make sure to free the string after
char *getVersion() {
  // get the literals from the config file into memory
  char *ver = km_VERSION;
  char *firstPeriod = ".";
  char *rev = km_REVISION;
  char *secondPeriod = ".";
  char *mrev = km_MINOR_REVISION;
  
  // malloc the memory needed for the version string; check for errors too
  char *fullVersion = malloc(strlen(ver) + strlen(firstPeriod) + strlen(rev) + strlen(secondPeriod) + strlen(mrev) + 1); // + 1 for the null terminator
  if (fullVersion == NULL) {
    // TODO: once we have an error handling system, handle the error
    exit(-1);
  }

  // copy ver to the new string, then concatenate it with the rev, mrev, and the periods
  strcpy(fullVersion,ver);
  strcat(fullVersion,firstPeriod);
  strcat(fullVersion,rev);
  strcat(fullVersion,secondPeriod);
  strcat(fullVersion,mrev);

  // return the new string
  return fullVersion;
}

// entry point
int main(int argc, char **argv) {
  char *version = getVersion();
  printf("Initializing killman v%s...\n",version);
  // TODO: launch the window, etc
  
  // variable freeing section
  free(version);

  // return with no errors
  return 0;
}
