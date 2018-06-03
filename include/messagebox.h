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

#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "killman_config.h"

// shows a message box
// NOTE: I'm using void * pointers here because I don't want to bloat up the include files with <gtk/gtk.h>. I'm trusting my future self to remember to put the right variables in here
int messageBox(void *parent, const char *text, const char *caption, uint type);

// define some variables that will be used in the messageBox function
#define MB_YESNO    0x00000004L
#define MB_OK       0x00000000L
#define MB_OKCANCEL 0x00000001L

// define result variables
#define ID_YES    6
#define ID_NO     7
#define ID_OK     1
#define ID_CANCEL 2

#endif
