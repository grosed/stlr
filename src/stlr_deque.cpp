

#include <Rcpp.h>               

#include <deque>
#include <string>
#include <vector>

#include "stlr_methods.h"


// convenience typedefs
typedef std::deque<double> stlr_deque_double;
typedef std::deque<std::string> stlr_deque_string;
typedef std::deque<std::vector<double> > stlr_deque_vector_double;

// define rcpp module
RCPP_MODULE(stlr_deque){
    using namespace Rcpp ;
    // expose the class std::deque<double> as "stlr_deque_double" on the R side
    class_<stlr_deque_double>("stlr_deque_double")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
    .method("push_back",&stlr_push_back<stlr_deque_double,double>)
    .method("pop_back",&stlr_pop_back<stlr_deque_double>)
    .method("push_front",&stlr_push_front<stlr_deque_double,double>)
    .method("pop_front",&stlr_pop_front<stlr_deque_double>)
    .method("assign",&stlr_assign<stlr_deque_double,double>)
    .method("front",&stlr_front<stlr_deque_double,double>)
    .method("back",&stlr_back<stlr_deque_double,double>)
    .method("size",&stlr_size<stlr_deque_double>)
    .method("clear",&stlr_clear<stlr_deque_double>)
    .method( "[[",&stlr_get<stlr_deque_double,double>)
    .method( "[[<-",&stlr_set<stlr_deque_double,double> )
    .method( "copy",&stlr_copy<stlr_deque_double,double> )
      ;
    // expose the class std::deque<std::string> as "stlr_deque_string" on the R side
    class_<stlr_deque_string>("stlr_deque_string")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
      .method("push_back",&stlr_push_back<stlr_deque_string,std::string>)
    .method("pop_back",&stlr_pop_back<stlr_deque_string>)
    .method("push_front",&stlr_push_front<stlr_deque_string,std::string>)
    .method("pop_front",&stlr_pop_front<stlr_deque_string>)
    .method("assign",&stlr_assign<stlr_deque_string,std::string>)
    .method("front",&stlr_front<stlr_deque_string,std::string>)
    .method("back",&stlr_back<stlr_deque_string,std::string>)
    .method("size",&stlr_size<stlr_deque_string>)
    .method("clear",&stlr_clear<stlr_deque_string>)
    .method( "copy",&stlr_copy<stlr_deque_string,std::string> )
    ;
    // expose the class std::deque<std::vector<double> > as "stlr_deque_vector_double" on the R side
    class_<stlr_deque_vector_double>("stlr_deque_vector_double")
    // exposing the default constructor
    .constructor()
    // exposing helper functions
    .method("push_back",&stlr_push_back<stlr_deque_vector_double,std::vector<double> >)
    .method("pop_back",&stlr_pop_back<stlr_deque_vector_double>)
    .method("push_front",&stlr_push_front<stlr_deque_vector_double,std::vector<double>>)
    .method("pop_front",&stlr_pop_front<stlr_deque_vector_double>)
    .method("assign",&stlr_assign<stlr_deque_vector_double,std::vector<double>>)
    .method("front",&stlr_front<stlr_deque_vector_double,std::vector<double>>)
    .method("back",&stlr_back<stlr_deque_vector_double,std::vector<double>>)
    .method("size",&stlr_size<stlr_deque_vector_double>)
    .method("clear",&stlr_clear<stlr_deque_vector_double>)
    .method( "copy",&stlr_copy<stlr_deque_vector_double,std::vector<double>> )
    ;
}



