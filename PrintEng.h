#ifndef PRINTENG_H
#define PRINTENG_H
#include "mainheader.h"
#include "Directory.h"
#include "verbalsaint.h"

VS
/**
Print out result using c++11's lambda feature.
  */
std::function<void(Directory&)> PrintTree = [&PrintTree](Directory& a_dir)->void{
    static string PADDING = string(2,'\t');
if(a_dir.level != 0){
  cout << string("|")  << string(a_dir.level*2,'-');
}

cout << a_dir.name << PADDING << a_dir.size << " Bytes" << endl;


if(!a_dir.dirs.empty()){
  for(auto itr = a_dir.dirs.begin() ; itr != a_dir.dirs.end(); ++itr ){
      //(*this)(*itr);
      PrintTree(*itr);
    }
}
if(!a_dir.files.empty()){
  for(auto itr = a_dir.files.begin() ; itr != a_dir.files.end(); ++itr ){
      cout << string("|") << string((*itr).level*2,'-') << (*itr).name << PADDING << (*itr).size << " Bytes" << endl;
    }
}
};

VS_END
#endif // PRINTENG_H
