#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "mainheader.h"
#include "Exception.h"
#include "Directory.h"
//#include "FileSize.h"
#include "verbalsaint.h"
VS

using namespace std;

class BuildTree{
private:  
  Directory _theRoot;

  size_t addup(Directory& a_tmpdir){
    if(a_tmpdir.dirs.empty()) {
        return a_tmpdir.size;
      }
    else{
        for(auto& tmpd : a_tmpdir.dirs){
            a_tmpdir.size += addup(tmpd);
          }
        return a_tmpdir.size;
      }
  }

  void updateSize(){
    // while dirs.empty=true; backoff do nothing
    // else this.size += dirs'size
    addup(_theRoot);
  }

public:
  BuildTree(){
    _theRoot.level = 0;
    _theRoot.size = 0;
  }

  void setRootName(string a_rootname){
    _theRoot.name = a_rootname;
  }

  Directory& getTree(){
    updateSize(); //update each directory's size with the directories' size underneath it.
    return _theRoot;
  }

  void setDir(int a_level,string a_name){    
    if(a_level == 1){
        //The directories under root, level 1.
        Directory tmp;
        tmp.level = a_level;
        tmp.name = a_name;
        tmp.size = 0;
        _theRoot.dirs.push_back(tmp);
      }
    else{
        Directory tmp;
        tmp.level = a_level;
        tmp.name = a_name;
        tmp.size = 0;
        int tmpLevel = a_level;        
        Directory* tmpDir = &_theRoot.dirs.back();
        //push_back this directory into previous level's Director.dirs.
        while(--tmpLevel > 1){ // use operator-- for efficiency,no tmp rvalue object
            tmpDir = &tmpDir->dirs.back();
          }
        tmpDir->dirs.push_back(tmp);
      }    
  }

  void setFile(int a_level,string a_name, off_t a_size){
    if(a_level == 1){
        // files in root dir, it's first parsed by nftw();
        FileSize tmp;
        tmp.size = a_size;
        tmp.level = a_level;
        tmp.name = a_name;
        _theRoot.files.push_back(tmp);
        _theRoot.size += tmp.size;
      }
    else{
        /**
         Files not in root dir.
         Also indicates no other directory's level == this file's level left.
         This file should added to this file's level-1's directory
         */
        FileSize tmp;
        tmp.size = a_size;
        tmp.level = a_level;
        tmp.name = a_name;
        int tmpLevel = a_level;
        Directory* tmpDir = &_theRoot.dirs.back();
        while(--tmpLevel > 1){
            tmpDir = &tmpDir->dirs.back();
          }
        tmpDir->files.push_back(tmp);
        tmpDir->size += tmp.size;
      }
  }
};



VS_END
#endif // BUILDTREE_H
