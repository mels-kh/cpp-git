#include <iostream>
#include <ncurses.h>

int main() {
  initscr(); // инициализировать "экран" поверх терминала
	noecho(); // не выводить считанные с клавиатуры символы
	cbreak();	// сразу считывать все нажатия. не ждать enter.
  curs_set(0);
  keypad(stdscr, TRUE); // разрешить считывание дополнительных клавиш, типа стрелок, f1-f12 и т.д.
  border(0, 0, 0, 0, 0, 0, 0, 0); // нарисовать границу "экрана" 
  int i = 1, j = 1;

  move(i, j); // Переместить курсор в указанную позицию
  addch('@'); // Нарисовать символ в указанной позиции
	refresh(); // Обновить экран

  int key = 0; // инициализируем переменную для считывания с клавиатуры
  //addch('.');
  // refresh();
  while(key != 'q') {
    key = getch(); // Программа останавливается, пока пользователь не нажмет на клавишу. Возвращает код нажатой клавиши.
   
    
    if (key == KEY_RIGHT) {
      j++;
      if(j + 1 == COLS)
      {
        j--;
        continue;
      }
    }
    if (key == KEY_LEFT) {
      j--;
      if(j == 0)
      {
        j++;
        continue;
      }
    }
    if (key == KEY_DOWN) {
      i++;
      if(i + 1 == LINES)
      {
        i--;
        continue;
      }
    }
    if (key == KEY_UP) {
      i--;
      if(i == 0)
      {
        i++;
        continue;
      }
  }
    
    move(i, j);
    addch('@');
    
    
    
    refresh();
    if (key == KEY_RIGHT) {
      move(i, j - 1);
    addch('.');
    }
    if (key == KEY_LEFT) {
      move(i, j + 1);
    addch('.');
    }
    if (key == KEY_DOWN) {
      move(i - 1, j);
    addch('.');
    }
    if (key == KEY_UP) {
      move(i + 1, j);
    addch('.');
    }
  }
  endwin();
}