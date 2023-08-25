#include <curses.h>

int main() {
    WINDOW* window = initscr();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    bool running = true;

    while(running) {

        wrefresh(window);

        int input = wgetch(window);
        
        if(input == KEY_ENTER) {
            running = false;
        }

    }


    endwin();

    return 0;
}
