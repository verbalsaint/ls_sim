#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "mainheader.h"
#include "FileSize.h"
#include "verbalsaint.h"

VS

using namespace std;

struct Directory{
  size_t size;
  int level;
  string name;
  vector<FileSize> files;
  vector<Directory> dirs;
};

VS_END
#endif // DIRECTORY_H
