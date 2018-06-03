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

#include "messagebox.h"

#include <gtk/gtk.h>

// this is a pain to type every time
#define DIALOG_FLAGS GTK_DIALOG_DESTROY_WITH_PARENT

// shows a message box
int messageBox(void *parent, const char *text, const char *caption, uint type) {
  // cast parent into window, init variable
  GtkWidget *window = parent;
  GtkWidget *dialog = NULL;
 
  // figure out what type of box the message box is, and initialize it
  if (type & MB_YESNO) {
    dialog = gtk_message_dialog_new(GTK_WINDOW(window), DIALOG_FLAGS, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO,    text);
  } else if (type & MB_OKCANCEL) {
    dialog = gtk_message_dialog_new(GTK_WINDOW(window), DIALOG_FLAGS, GTK_MESSAGE_INFO,     GTK_BUTTONS_OK_CANCEL, text); 
  } else {
    dialog = gtk_message_dialog_new(GTK_WINDOW(window), DIALOG_FLAGS, GTK_MESSAGE_INFO,     GTK_BUTTONS_OK,        text);
  }

  // set the title of the dialog box to the caption
  gtk_window_set_title(GTK_WINDOW(dialog), caption);

  // destroy widget once buton is clicked
  g_signal_connect_swapped(dialog,"response",G_CALLBACK(gtk_widget_destroy),dialog);

  // run the dialog, get the result
  gint result = gtk_dialog_run(GTK_DIALOG(dialog)); 

  // determine result of message box
  if (type & MB_YESNO) { switch(result) {
    default:
    case GTK_RESPONSE_DELETE_EVENT:
    case GTK_RESPONSE_NO:
      return ID_NO;
      break;
    case GTK_RESPONSE_YES:
      return ID_YES;
      break;
  } }

  if (type & MB_OKCANCEL) { switch(result) {
    default:
    case GTK_RESPONSE_DELETE_EVENT:
    case GTK_RESPONSE_OK:
      return ID_OK;
      break;
    case GTK_RESPONSE_CANCEL:
      return ID_CANCEL;
      break;
  } }

  return ID_OK;
}
