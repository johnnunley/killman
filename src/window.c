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
#include "messagebox.h"

#include <gtk/gtk.h>

// variables
GtkWidget *window;
GtkWidget *kill_button;

// callback to kill button
static void killButtonPress(GtkWidget *widget, gpointer data) {
  messageBox(window,"Process Killed!", "Process Killed!", MB_OK);
}

// callback to destroy window
static void destroy(GtkWidget *widget, gpointer data) {
  // we don't want to give the user any trouble if they want to close the window; just exit out of the loop
  gtk_main_quit();
}

// callback to deletion event
static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
  // again, don't give the user trouble, just return FALSE to delete the window
  return FALSE;
}

// creates the window, adds widgets, and shows it
void initializeWindow(int *argc, char ***argv) {
  // call gtk_init to initialize gtk
  gtk_init(argc,argv);

  // create the window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  if (window == NULL) error("Unable to create window");

  // hook up the delete_event and destroy callbacks to the window
  g_signal_connect(window,       "delete-event",G_CALLBACK(delete_event),   NULL);
  g_signal_connect(window,       "destroy",     G_CALLBACK(destroy),        NULL);

  // create button and hook up killButtonPress to it
  kill_button = gtk_button_new_with_label("KILL");
  g_signal_connect(kill_button,"clicked",     G_CALLBACK(killButtonPress),NULL);

  // add widgets to window
  gtk_container_add(GTK_CONTAINER(window),kill_button);

  // show the window + widgets
  gtk_widget_show(window);
  gtk_widget_show(kill_button);
}

// starts gtk_main()
void initializeLoop() {
  gtk_main();
}
