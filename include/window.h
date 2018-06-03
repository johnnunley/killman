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

#ifndef WINDOW_H
#define WINDOW_H

// this file is used to interface with the gtk library

// creates the window, adds widgets, and shows it
void initializeWindow(int *argc, char ***argv);

// starts gtk_main()
void initializeLoop();

#endif
