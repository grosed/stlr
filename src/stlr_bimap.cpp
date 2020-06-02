#include <Rcpp.h>               

#include <boost/config.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>

using namespace boost::bimaps;
using namespace std;


#include "stlr_methods.h"

// convenience typedefs
typedef bimap<multiset_of<string>,multiset_of<double> > bihash_multi_string_multi_double;
typedef bimap<multiset_of<double>,multiset_of<string> > bihash_multi_double_multi_string;
typedef bimap<multiset_of<string>,multiset_of<string> > bihash_multi_string_multi_string;
typedef bimap<multiset_of<double>,multiset_of<double> > bihash_multi_double_multi_double;


// define rcpp module
RCPP_MODULE(stlr_bihash){
    using namespace Rcpp ;
    // expose the class bimap<multiset_of<string>,multiset_of<double> >
    // as "stlr_bihash_multi_string_multi_double" on the R side
    class_<bihash_multi_string_multi_double>("stlr_bihash_multi_string_multi_double")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
    .method("clear",&stlr_clear<bihash_multi_string_multi_double>)
    .method("insert",&stlr_insert<bihash_multi_string_multi_double,string,double>)
    .method("right_equal_range",&stlr_right_equal_range<bihash_multi_string_multi_double,double,string>)
    .method("left_equal_range",&stlr_left_equal_range<bihash_multi_string_multi_double,string,double>)
    .method("right_erase",&stlr_right_erase<bihash_multi_string_multi_double,double>)
    .method("left_erase",&stlr_left_erase<bihash_multi_string_multi_double,string>)
    .method("right_erase_one",&stlr_right_erase_one<bihash_multi_string_multi_double,double>)
    .method("left_erase_one",&stlr_left_erase_one<bihash_multi_string_multi_double,string>)
    .method("right_count",&stlr_right_count<bihash_multi_string_multi_double,double>)
    .method("left_count",&stlr_left_count<bihash_multi_string_multi_double,string>)
    .method("left_lower_bound",&stlr_left_lower_bound<bihash_multi_string_multi_double,string,double>)
    .method("right_lower_bound",&stlr_right_lower_bound<bihash_multi_string_multi_double,double,string>)
    .method("left_upper_bound",&stlr_left_upper_bound<bihash_multi_string_multi_double,string,double>)
    .method("right_upper_bound",&stlr_right_upper_bound<bihash_multi_string_multi_double,double,string>)
    .method("left_range",&stlr_left_range<bihash_multi_string_multi_double,string,double>)
    .method("right_range",&stlr_right_range<bihash_multi_string_multi_double,double,string>)
    .method("left_min",&stlr_left_min<bihash_multi_string_multi_double,string>)
    .method("right_min",&stlr_right_min<bihash_multi_string_multi_double,double>)
    .method("left_max",&stlr_left_max<bihash_multi_string_multi_double,string>)
    .method("right_max",&stlr_right_max<bihash_multi_string_multi_double,double>)
    ;

    // expose the class bimap<multiset_of<double>,multiset_of<string> >
    // as "stlr_bihash_multi_double_multi_string" on the R side
    class_<bihash_multi_double_multi_string>("stlr_bihash_multi_double_multi_string")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
    .method("clear",&stlr_clear<bihash_multi_double_multi_string>)
    .method("insert",&stlr_insert<bihash_multi_double_multi_string,double,string>)
    .method("right_equal_range",&stlr_right_equal_range<bihash_multi_double_multi_string,string,double>)
    .method("left_equal_range",&stlr_left_equal_range<bihash_multi_double_multi_string,double,string>)
    .method("right_erase",&stlr_right_erase<bihash_multi_double_multi_string,string>)
    .method("left_erase",&stlr_left_erase<bihash_multi_double_multi_string,double>)
    .method("right_erase_one",&stlr_right_erase_one<bihash_multi_double_multi_string,string>)
    .method("left_erase_one",&stlr_left_erase_one<bihash_multi_double_multi_string,double>)
    .method("right_count",&stlr_right_count<bihash_multi_double_multi_string,string>)
    .method("left_count",&stlr_left_count<bihash_multi_double_multi_string,double>)
    .method("left_lower_bound",&stlr_left_lower_bound<bihash_multi_double_multi_string,double,string>)
    .method("right_lower_bound",&stlr_right_lower_bound<bihash_multi_double_multi_string,string,double>)
    .method("left_upper_bound",&stlr_left_upper_bound<bihash_multi_double_multi_string,double,string>)
    .method("right_upper_bound",&stlr_right_upper_bound<bihash_multi_double_multi_string,string,double>)
    .method("left_range",&stlr_left_range<bihash_multi_double_multi_string,double,string>)
    .method("right_range",&stlr_right_range<bihash_multi_double_multi_string,string,double>)
    .method("left_min",&stlr_left_min<bihash_multi_double_multi_string,double>)
    .method("right_min",&stlr_right_min<bihash_multi_double_multi_string,string>)
    .method("left_max",&stlr_left_max<bihash_multi_double_multi_string,double>)
    .method("right_max",&stlr_right_max<bihash_multi_double_multi_string,string>)
    ;
    
    // expose the class bimap<multiset_of<double>,multiset_of<double> >
    // as "stlr_bihash_multi_string_multi_double" on the R side
    class_<bihash_multi_string_multi_string>("stlr_bihash_multi_string_multi_string")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
    .method("clear",&stlr_clear<bihash_multi_string_multi_string>)
    .method("insert",&stlr_insert<bihash_multi_string_multi_string,string,string>)
    .method("right_equal_range",&stlr_right_equal_range<bihash_multi_string_multi_string,string,string>)
    .method("left_equal_range",&stlr_left_equal_range<bihash_multi_string_multi_string,string,string>)
    .method("right_erase",&stlr_right_erase<bihash_multi_string_multi_string,string>)
    .method("left_erase",&stlr_left_erase<bihash_multi_string_multi_string,string>)
    .method("right_erase_one",&stlr_right_erase_one<bihash_multi_string_multi_string,string>)
    .method("left_erase_one",&stlr_left_erase_one<bihash_multi_string_multi_string,string>)
    .method("right_count",&stlr_right_count<bihash_multi_string_multi_string,string>)
    .method("left_count",&stlr_left_count<bihash_multi_string_multi_string,string>)
    .method("left_lower_bound",&stlr_left_lower_bound<bihash_multi_string_multi_string,string,string>)
    .method("right_lower_bound",&stlr_right_lower_bound<bihash_multi_string_multi_string,string,string>)
    .method("left_upper_bound",&stlr_left_upper_bound<bihash_multi_string_multi_string,string,string>)
    .method("right_upper_bound",&stlr_right_upper_bound<bihash_multi_string_multi_string,string,string>)
    .method("left_range",&stlr_left_range<bihash_multi_string_multi_string,string,string>)
    .method("right_range",&stlr_right_range<bihash_multi_string_multi_string,string,string>)
    .method("left_min",&stlr_left_min<bihash_multi_string_multi_string,string>)
    .method("right_min",&stlr_right_min<bihash_multi_string_multi_string,string>)
    .method("left_max",&stlr_left_max<bihash_multi_string_multi_string,string>)
    .method("right_max",&stlr_right_max<bihash_multi_string_multi_string,string>)  
    ;

    // expose the class bimap<multiset_of<double>,multiset_of<double> >
    // as "stlr_bihash_multi_double_multi_double" on the R side
    class_<bihash_multi_double_multi_double>("stlr_bihash_multi_double_multi_double")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
    .method("clear",&stlr_clear<bihash_multi_double_multi_double>)
    .method("insert",&stlr_insert<bihash_multi_double_multi_double,double,double>)
    .method("right_equal_range",&stlr_right_equal_range<bihash_multi_double_multi_double,double,double>)
    .method("left_equal_range",&stlr_left_equal_range<bihash_multi_double_multi_double,double,double>)
    .method("right_erase",&stlr_right_erase<bihash_multi_double_multi_double,double>)
    .method("left_erase",&stlr_left_erase<bihash_multi_double_multi_double,double>)
    .method("right_erase_one",&stlr_right_erase_one<bihash_multi_double_multi_double,double>)
    .method("left_erase_one",&stlr_left_erase_one<bihash_multi_double_multi_double,double>)
    .method("right_count",&stlr_right_count<bihash_multi_double_multi_double,double>)
    .method("left_count",&stlr_left_count<bihash_multi_double_multi_double,double>)
    .method("left_lower_bound",&stlr_left_lower_bound<bihash_multi_double_multi_double,double,double>)
    .method("right_lower_bound",&stlr_right_lower_bound<bihash_multi_double_multi_double,double,double>)
    .method("left_upper_bound",&stlr_left_upper_bound<bihash_multi_double_multi_double,double,double>)
    .method("right_upper_bound",&stlr_right_upper_bound<bihash_multi_double_multi_double,double,double>)
    .method("left_range",&stlr_left_range<bihash_multi_double_multi_double,double,double>)
    .method("right_range",&stlr_right_range<bihash_multi_double_multi_double,double,double>)
    .method("left_min",&stlr_left_min<bihash_multi_double_multi_double,double>)
    .method("right_min",&stlr_right_min<bihash_multi_double_multi_double,double>)
    .method("left_max",&stlr_left_max<bihash_multi_double_multi_double,double>)
    .method("right_max",&stlr_right_max<bihash_multi_double_multi_double,double>)
    ;
}













