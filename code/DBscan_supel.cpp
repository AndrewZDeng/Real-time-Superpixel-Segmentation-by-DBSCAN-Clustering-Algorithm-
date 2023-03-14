#include "DBscan.h"
#include <map>

#ifdef __cplusplus
extern "C" {
#endif

int DBSCAN_supel(int *image, int height, int width, int *output, int num_supels, int post) {

  unsigned char *R = new unsigned char[height * width];
  unsigned char *G = new unsigned char[height * width];
  unsigned char *B = new unsigned char[height * width];
  unsigned short *label = new unsigned short[height * width];

  for (int x = 0; x < height; x++) {
    for (int y = 0; y < width; y++) {
      R[x * width + y] = image[(x * width + y) * 3];
      G[x * width + y] = image[(x * width + y) * 3 + 1];
      B[x * width + y] = image[(x * width + y) * 3 + 2];
      label[x * width + y] = 0;
    }
  }

  int real_num_supels = 0;
  DBscan(R, G, B, height, width, label, num_supels, real_num_supels, post);

  // old label to new label, unorganized to organized number
  map<unsigned short, unsigned short> o2n;
  int new_label = 1;

  for (int i = 0; i < height * width; i++) {
    int old_label = label[i];
    if (o2n.find(old_label) == o2n.end()) {
      o2n[old_label] = new_label;
      new_label++;
    }
  }

  for (int x = 0; x < height; x++) {
    for (int y = 0; y < width; y++) {
      output[x * width + y] = o2n[label[x * width + y]];
    }
  }

  delete[] R;
  delete[] G;
  delete[] B;
  delete[] label;

  return real_num_supels;
}

#ifdef __cplusplus
}
#endif