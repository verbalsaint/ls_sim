#define _XOPEN_SOURCE 600 // enable nftw , >500 , S_IFSOCK, >600
#include "mainheader.h"
#include "Exception.h"
#include "ArgParser.h"
#include "BuildTree.h"
#include "PrintEng.h"
#include "verbalsaint.h"


using namespace std;
UVS // using own namespace

BuildTree BT;

/**
  call back function for nftw system call.
  It will scan all root's file first.
  Scan each Directory under root.
  Scan each Directory's Directory first (depth search)
  Scan Dorectory's file later.
  */
int callBackFun(const char* pathname,const struct stat* statbuf, int typeflag,struct FTW* ftwbuf){  
  if(ftwbuf->level == 0) return 0;
  /**
    judge regular file and directory
    */
  switch(statbuf->st_mode & S_IFMT){
    case S_IFREG:
      if(typeflag != FTW_NS){
          BT.setFile(ftwbuf->level,&pathname[ftwbuf->base],statbuf->st_size);
        }
      break;
    case S_IFDIR:
      if(typeflag != FTW_DNR && typeflag != FTW_NS){
          BT.setDir(ftwbuf->level,&pathname[ftwbuf->base]);
        }
      break;
    }
  return 0;
}


int main(int argc, char *argv[]){
  int flags =0;
  flags |= FTW_PHYS; //Do not dereference symbol links

  try{
    ArgParser ap(argc,argv); //Parse the user input argument

    BT.setRootName(ap.getDir()); // Set root directory name

    int err = nftw(ap.getDir().c_str(),callBackFun,20,flags); // Walk through i-node from root directory.

    if(err != 0) {
        throw VSException(ExceptionType::NFTW,err);
      }

    Directory result;
    result = BT.getTree(); //Fetch processed tree for directories and files
    cout << "Total size : " << result.size << " Bytes" << endl;
    PrintTree(result); //Print out the result
  }
  catch(VSException& vse){
    cout << vse.what() << endl;
    return 1;
  }
  catch(...){
    cout << "Error occured." << endl;
    return 1;
  }
  return 0;
}
