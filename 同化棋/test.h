#pragma once
#include<iostream>
#include<cmath>
#include<fstream>
#include<algorithm>
#include<Windows.h>
int game(int,int);
int black_game();
int white_game();
void ai(int, int);
void f0();
void f1();
int double_game(int,int);
void f3();
void jiemian(int);
int decide_win();
int decide_num_nextstep(int, int, int);
int decide_des_nextstep(int, int, int, int, int);
void file_output(int first);
int file_input(int);

int estimate(int start, int qipan_1[7][7]);


extern int qipan[7][7];
extern int cnt_step, cnt_black, cnt_white, player;