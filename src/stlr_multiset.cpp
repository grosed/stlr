
#include <Rcpp.h>               

#include <set>
#include <string>

#include "stlr_methods.h"


// convenience typedefs
typedef std::multiset<double> stlr_multiset_double;
typedef std::multiset<std::string> stlr_multiset_string;


// define rcpp module
RCPP_MODULE(stlr_multiset){
    using namespace Rcpp ;
    // expose the class std::multiset<double> as "stlr_multiset_double" on the R side
    class_<stlr_multiset_double>("stlr_multiset_double")
    // exposing the default constructor
    .constructor()
    .method("size",&stlr_size<stlr_multiset_double>)
    .method("clear",&stlr_clear<stlr_multiset_double>)
    .method("insert",&stlr_insert<stlr_multiset_double,double>)
    .method("erase",&stlr_erase<stlr_multiset_double,double>)
    .method("erase_one",&stlr_erase_one<stlr_multiset_double,double>)
    .method("max",&stlr_max<stlr_multiset_double,double>)
    .method("min",&stlr_min<stlr_multiset_double,double>)
    .method("count",&stlr_count<stlr_multiset_double,double>)
    .method("copy",&stlr_copy<stlr_multiset_double,double> )
    ;
    // expose the class std::multiset<string> as "stlr_multiset_string" on the R side
    class_<stlr_multiset_string>("stlr_multiset_string")
    // exposing the default constructor
    .constructor()
    .method("size",&stlr_size<stlr_multiset_string>)
    .method("clear",&stlr_clear<stlr_multiset_string>)
      .method("insert",&stlr_insert<stlr_multiset_string,std::string>)
    .method("erase",&stlr_erase<stlr_multiset_string,std::string>)
    .method("erase_one",&stlr_erase_one<stlr_multiset_string,std::string>)
    .method("max",&stlr_max<stlr_multiset_string,std::string>)
    .method("min",&stlr_min<stlr_multiset_string,std::string>)
    .method("count",&stlr_count<stlr_multiset_string,std::string>)
    .method("copy",&stlr_copy<stlr_multiset_string,std::string> )
    ;
}  
