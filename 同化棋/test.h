#pragma once
#include<iostream>
#include<cmath>
#include<fstream>
#include<algorithm>
#include<Windows.h>
int game(int);
void black_game();
void white_game();
void ai(int);
void f0();
void f1();
void double_game(int);
void f2();
void f3_1();
void f3_2(int, int);
void jiemian(int);
int decide_win();
int decide_num_nextstep(int, int, int);
int decide_des_nextstep(int, int, int, int, int);
void file_output(int);
int file_input(int);

int estimate(int start, int qipan_1[7][7]);


extern int qipan[7][7];
extern int cnt_step, cnt_black, cnt_white, player;
extern int cunpan[200][7][7];
extern int white_cunpan[100][7][7];
extern int black_cunpan[100][7][7];