#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define STACK_LIMIT 1024
#define KEY_ESCAPE_return 1
#define KEY_ESCAPE 27

int current_stack_pointer = 0;
int stack[STACK_LIMIT];
char display_stack[STACK_LIMIT];
int display_stack_len = sizeof(display_stack) / sizeof(display_stack[0]);

void add_to_display_stack(int32_t number){
    switch(number){
        case 97:
            display_stack[current_stack_pointer] = 'a';
            break;
        case 98:
            display_stack[current_stack_pointer] = 'b';
            break;
        case 99:
            display_stack[current_stack_pointer] = 'c';
            break;
        case 100:
            display_stack[current_stack_pointer] = 'd';
            break;
        case 101:
            display_stack[current_stack_pointer] = 'e';
            break;
        case 102:
            display_stack[current_stack_pointer] = 'f';
            break;
        case 103:
            display_stack[current_stack_pointer] = 'g';
            break;
        case 104:
            display_stack[current_stack_pointer] = 'h';
            break;
        case 105:
            display_stack[current_stack_pointer] = 'i';
            break;
        case 106:
            display_stack[current_stack_pointer] = 'j';
            break;
        case 107:
            display_stack[current_stack_pointer] = 'k';
            break;
        case 108:
            display_stack[current_stack_pointer] = 'l';
            break;
        case 109:
            display_stack[current_stack_pointer] = 'm';
            break;
        case 110:
            display_stack[current_stack_pointer] = 'n';
            break;
        case 111:
            display_stack[current_stack_pointer] = 'o';
            break;
        case 112:
            display_stack[current_stack_pointer] = 'p';
            break;
        case 113:
            display_stack[current_stack_pointer] = 'q';
            break;
        case 114:
            display_stack[current_stack_pointer] = 'r';
            break;
        case 115:
            display_stack[current_stack_pointer] = 's';
            break;
        case 116:
            display_stack[current_stack_pointer] = 't';
            break;
        case 117:
            display_stack[current_stack_pointer] = 'u';
            break;
        case 118:
            display_stack[current_stack_pointer] = 'v';
            break;
        case 119:
            display_stack[current_stack_pointer] = 'w';
            break;
        case 120:
            display_stack[current_stack_pointer] = 'x';
            break;
        case 121:
            display_stack[current_stack_pointer] = 'y';
            break;
        case 122:
            display_stack[current_stack_pointer] = 'z';
            break;
        default:
            printf("Invalid key number");
            exit(1);
    }
}

int parse_key_pressed(int32_t key){
    printf("%s\n", SDL_GetKeyName(key));
    stack[current_stack_pointer] = key;
    if (key == KEY_ESCAPE){
        return KEY_ESCAPE_return;
    }
    add_to_display_stack(key);
    ++current_stack_pointer;
    printf("stack = %d\ndisplay_stack = %c\n", stack[current_stack_pointer-1], display_stack[current_stack_pointer-1]);
    return 0;
}

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("te", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event evs;
    bool should_quit = false;
    while(!should_quit){
        while(SDL_PollEvent(&evs)){
            switch(evs.type){
                case SDL_QUIT:
                    should_quit = true;
                    break;
                case SDL_KEYDOWN:
                    if(parse_key_pressed(evs.key.keysym.sym) == 1) should_quit = true;
                    break;
            }
        }
        SDL_RenderClear(renderer);
        int i = 0;
        while(i < display_stack_len){
            if (display_stack[i] == 0){
                i++;
                continue;
            }
            
            i++;
        }
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    return 0;
}