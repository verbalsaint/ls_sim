#ifndef ARGPARSER_H
#define ARGPARSER_H
#include "mainheader.h"
#include "Exception.h"
#include "verbalsaint.h"

VS //using own namespace

using namespace std;

class ArgParser{
  private:
  string _startDir;

  private:
  ArgParser(const ArgParser&) = delete;
  ArgParser operator=(const ArgParser&) = delete;

  void judge(int& argc, char**& a_argv){    
    switch(argc){
      case 1:
        break;
      case 2:
        _startDir = a_argv[1]; break;
      default:
        throw VSException(ExceptionType::ARGPARSER,"Only 1 argument allowed.");
      }
  }

  public:
  ArgParser(int&,char **&);
  string getDir(){
    return _startDir;
  }
};

ArgParser::ArgParser(int& a_argc,char**& a_argv):_startDir("."){  
  judge(a_argc,a_argv);
}

VS_END
#endif // ARGPARSER_H
