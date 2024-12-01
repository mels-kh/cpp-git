#include <algorithm>
#include <ncurses.h>
#include <stdio.h>

void update_speed(int key, int &di,int &dj)
{
  if (key == KEY_RIGHT) {
      dj = 1;
      di = 0;
    }
    else if (key == KEY_LEFT) {
      dj = -1;
      di = 0;
    }
    else if (key == KEY_DOWN) {
      di = 1;
      dj = 0;
    }
    else if (key == KEY_UP) {
      di = -1;
      dj = 0;
    }

}

void update_coords(int &i, int &j, int di,int dj)
{
  i += di;
    j += dj;
    
    i = std::max(1, std::min(LINES - 2, i));
    j = std::max(1, std::min(COLS - 2, j));
}

void set_up()
{
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(100);
  
}

void update(int key,int &i, int &j, int &di,int &dj)
{
    move(i, j);
    addch('.');

   update_speed(key, di, dj);
   update_coords(i, j, di, dj);

    move(i, j);
    addch('@');
    refresh();
}
int main() {
  set_up();
  border(0, 0, 0, 0, 0, 0, 0, 0);

  int i = 1;
  int j = 1;
  move(i, j);
  addch('@');
  refresh();

  int key = 0;
  int di = 0;
  int dj = 0;
  while (key != 'q') {
    key = getch();
    update(key,i,j,di,dj);
  }

  endwin();
  return 0;
}
