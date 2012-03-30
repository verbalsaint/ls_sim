#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "mainheader.h"
#include "verbalsaint.h"

VS

using namespace std;

enum class ExceptionType{NFTW,ARGPARSER,OTHER};

class VSException : public std::exception{
private:
    string errorstr;
public:
    template<typename T>
    VSException(ExceptionType a_et,T a_err){
      stringstream tmpss;
      switch(a_et){
        case ExceptionType::NFTW :
          tmpss << "nftw error : " << a_err << endl;
          errorstr = tmpss.str();
          break;
        case ExceptionType::ARGPARSER :
          tmpss << "argparser error : " << a_err << endl;
          errorstr = tmpss.str();
          break;
        case ExceptionType::OTHER :
          tmpss << "other error : " << a_err << endl;
          errorstr = tmpss.str();
          break;
        default:
          tmpss << "error : " << a_err << endl;
          errorstr = tmpss.str();
        }
    }


    virtual ~VSException() throw(){

    }
    virtual const char* what() const throw(){
        return errorstr.c_str();
    }
};

VS_END

#endif // EXCEPTION_H
