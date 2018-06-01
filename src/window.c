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

#include "error.h"
#include "window.h"

#include <gtk/gtk.h>

// variables
GtkWidget *window;

// creates the window, adds widgets, and shows it
void initializeWindow(int *argc, char ***argv) {
  // call gtk_init to initialize gtk
  gtk_init(argc,argv);

  // create the window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  if (window == NULL) error("Unable to create window");

  // show the window
  gtk_widget_show(window);
}

// starts gtk_main()
void initializeLoop() {
  gtk_main();
}
