#ifndef _zad_h_
#define _zad_h_
#define LOCAL_H

#include <vector>
#include <tuple>

void init(std::vector<std::tuple<int, int, int>> edges);
int distance(int a, int b);
void change(int a, int b, int c);

#endif
