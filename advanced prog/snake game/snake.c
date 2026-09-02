#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH  40
#define HEIGHT 20
#define MAX_SNAKE_SIZE (WIDTH * HEIGHT)

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

Point snake[MAX_SNAKE_SIZE];
int snake_length;
Point food;
Direction direction;
int score;
int game_over;

/* Generate food at a position not occupied by the snake */
void generate_food(void)
{
    int occupied;

    do {
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;

        occupied = 0;

        for (int i = 0; i < snake_length; i++) {
            if (snake[i].x == food.x &&
                snake[i].y == food.y) {
                occupied = 1;
                break;
            }
        }
    } while (occupied);
}

/* Initialize game state */
void init_game(void)
{
    snake_length = 3;

    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;

    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;

    snake[2].x = snake[0].x - 2;
    snake[2].y = snake[0].y;

    direction = RIGHT;
    score = 0;
    game_over = 0;

    generate_food();
}

/* Draw the game */
void draw_game(void)
{
    clear();

    /* Border */
    for (int x = 0; x <= WIDTH + 1; x++) {
        mvprintw(0, x, "#");
        mvprintw(HEIGHT + 1, x, "#");
    }

    for (int y = 1; y <= HEIGHT; y++) {
        mvprintw(y, 0, "#");
        mvprintw(y, WIDTH + 1, "#");
    }

    /* Food */
    mvprintw(food.y + 1, food.x + 1, "*");

    /* Snake */
    for (int i = 0; i < snake_length; i++) {
        if (i == 0)
            mvprintw(snake[i].y + 1, snake[i].x + 1, "O");
        else
            mvprintw(snake[i].y + 1, snake[i].x + 1, "o");
    }

    mvprintw(HEIGHT + 3, 0,
             "Score: %d | W/A/S/D or Arrow Keys | Q: Quit",
             score);

    refresh();
}

/* Change direction based on keyboard input */
void handle_input(void)
{
    int ch = getch();

    switch (ch) {

    case 'w':
    case 'W':
    case KEY_UP:
        if (direction != DOWN)
            direction = UP;
        break;

    case 's':
    case 'S':
    case KEY_DOWN:
        if (direction != UP)
            direction = DOWN;
        break;

    case 'a':
    case 'A':
    case KEY_LEFT:
        if (direction != RIGHT)
            direction = LEFT;
        break;

    case 'd':
    case 'D':
    case KEY_RIGHT:
        if (direction != LEFT)
            direction = RIGHT;
        break;

    case 'q':
    case 'Q':
        game_over = 1;
        break;
    }
}

/* Check whether snake head collides with itself */
int check_self_collision(void)
{
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x &&
            snake[0].y == snake[i].y) {
            return 1;
        }
    }

    return 0;
}

/* Move snake */
void move_snake(void)
{
    Point new_head = snake[0];

    switch (direction) {

    case UP:
        new_head.y--;
        break;

    case DOWN:
        new_head.y++;
        break;

    case LEFT:
        new_head.x--;
        break;

    case RIGHT:
        new_head.x++;
        break;
    }

    /* Wall collision */
    if (new_head.x < 0 ||
        new_head.x >= WIDTH ||
        new_head.y < 0 ||
        new_head.y >= HEIGHT) {

        game_over = 1;
        return;
    }

    /* Move body */
    for (int i = snake_length; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    snake[0] = new_head;

    /* Food eaten */
    if (snake[0].x == food.x &&
        snake[0].y == food.y) {

        snake_length++;
        score += 10;

        if (snake_length >= MAX_SNAKE_SIZE) {
            game_over = 1;
            return;
        }

        generate_food();
    } else {
        /*
         * No food eaten, so remove the last
         * element by effectively keeping the
         * original length.
         */
    }

    /* Self collision */
    if (check_self_collision())
        game_over = 1;
}

int main(void)
{
    srand(time(NULL));

    /* Initialize ncurses */
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    init_game();

    while (!game_over) {

        draw_game();

        handle_input();

        if (game_over)
            break;

        move_snake();

        /* Game speed */
        usleep(100000);
    }

    /* Game over screen */
    nodelay(stdscr, FALSE);

    clear();

    mvprintw(HEIGHT / 2,
             WIDTH / 2 - 5,
             "GAME OVER");

    mvprintw(HEIGHT / 2 + 1,
             WIDTH / 2 - 8,
             "Final Score: %d",
             score);

    mvprintw(HEIGHT / 2 + 3,
             WIDTH / 2 - 12,
             "Press any key to exit");

    refresh();

    getch();

    endwin();

    return 0;
}
