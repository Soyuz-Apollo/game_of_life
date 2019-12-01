//
// Created by Evrik on 12/1/19.
//

#ifndef LIVE_3_KIND__LIFE_H_
#define LIVE_3_KIND__LIFE_H_
#define WIDTH 20
#define HEIGHT 20



class Life {

  unsigned int world[WIDTH + 2][HEIGHT + 2]{};// main world's map

  unsigned int world_buf[WIDTH + 2][HEIGHT + 2];//this one is used for generating new map using the old map(main world ma[)

  int count_of_live(int x, int y);//computing number of living cell neighbors

 public:

  void init_world();
  Life();
  void update_generation();
  void out_world();
  int sigma_of_life();//compute number of all living cells

};

#endif //LIVE_3_KIND__LIFE_H_
