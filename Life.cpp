//
// Created by kisik on 12/1/19.
//

#include "Life.h"
#include <iostream>
#include <ctime>


void Life::init_world() {
  srand(std::time(nullptr));
  for (int i = 1; i < WIDTH - 1; ++i) {
	for (int j = 1; j < HEIGHT - 1; ++j) {
	  world[i][j] = rand() % 2;
	  world_buf[i][j]  = world[i][j];
	}
  }

}
Life::Life() {
  srand(std::time(nullptr));
  for (int i = 0; i < WIDTH ; ++i) {
	for (int j = 0; j < HEIGHT ; ++j) {
	  world[i][j] = 0;
	  world_buf[i][j] = 0;
	}
  }
}

int Life::count_of_live(int x, int y) {
  unsigned int count = 0;
  for (int i = x-1; i < x+2; ++i) {
	for (int j = y - 1; j < y + 2; ++j) {
	  count += world[i][j];
	}
  }
  if(world[x][y]){
	count--;
  }
  return count;
}


void Life::update_generation() {
  int num_life;
  for (int i = 1; i < WIDTH - 1; ++i) {
	for (int j = 1; j < HEIGHT - 1; ++j) {
	  num_life = count_of_live(i, j);
	  if (!world[i][j]) {
		if (num_life == 3) {
		  world_buf[i][j] = 1;
		}
	  }
	}
  }
  for (int i = 1 ; i < WIDTH - 1; ++i) {
	for (int j = 1; j < HEIGHT - 1; ++j) {
	  num_life = count_of_live(i, j);
	  if(world[i][j]){
	    if(num_life <2){
	      world_buf[i][j] = 0;
	    }else if(num_life >3){
	      world_buf[i][j] = 0;
	    }
	  }
	}
  }
  for (int i = 1; i < WIDTH -1; ++i) {
	for (int j = 1; j < HEIGHT -1; ++j) {
	  world[i][j] = world_buf[i][j];
	}

  }

}


void Life::out_world() {
  for (int i = 1; i < WIDTH -1; ++i) {
	for (int j = 1; j <HEIGHT - 1 ; ++j) {
	  if(world[i][j]){
	    std::cout << "* ";
	  }else{
	    std::cout << "  ";
	  }
	}
	std::cout << std::endl;
  }
}
int Life::sigma_of_life() {
  int count = 0;
  for (int i = 0; i <WIDTH ; ++i) {
	for (int j = 0; j < HEIGHT; ++j) {
	  count += world[i][j];
	}
  }
  return count;
}
