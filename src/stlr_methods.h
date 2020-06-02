
#ifndef ___STLR_METHODS_H___
#define ___STLR_METHODS_H___

#include "Rcpp.h"

#include <exception>
#include <vector>
#include <algorithm>
#include <list>

// helper functions
template <typename object_type,typename value_type>
void stlr_push_back(object_type* p_object, const value_type& value)
{
  p_object->push_back(value);
}

template <typename object_type>
void stlr_pop_back(object_type* p_object)
{
  p_object->pop_back();
}

template <typename object_type,typename value_type>
void stlr_push_front(object_type* p_object, const value_type& value)
{
  p_object->push_front(value);
}

template <typename object_type>
void stlr_pop_front(object_type* p_object)
{
  p_object->pop_front();
}

template <typename object_type,typename value_type>
void stlr_assign(object_type* p_object,const int& number,const value_type& value)
{
  p_object->assign(number,value);
}

template <typename object_type,typename value_type>
value_type stlr_front(object_type* p_object)
{
  return p_object->front();
}

template <typename object_type,typename value_type>
value_type stlr_back(object_type* p_object)
{
  return p_object->back();
}

template <typename object_type>
int stlr_size(object_type* p_object)
{
  return p_object->size();
}

template <typename object_type>
void stlr_clear(object_type* p_object)
{
  p_object->clear();
}

template <typename object_type,typename value_type>
value_type stlr_get(object_type* p_object,const int& index)
{
  // note - designed to be consitent with R indexing (i.e. - first element of container
  // corresponds to index == 1
  return p_object->at(index-1);
}

template <typename object_type,typename value_type>
void stlr_set(object_type* p_object,const int& index,const value_type& value)
{
  // note - designed to be consitent with R indexing (i.e. - first element of container
  // corresponds to index == 1
  p_object->at(index-1) = value;
}

template <typename object_type,typename value_type>
void stlr_insert(object_type* p_object,const value_type& value)
{
  p_object->insert(value);
}

template <typename object_type,typename value_type>
void stlr_erase(object_type* p_object,const value_type& value)
{
  p_object->erase(value);
}

template <typename object_type,typename value_type>
void stlr_erase_one(object_type* p_object,const value_type& value)
{
  auto hit = p_object->find(value);
  if(hit != p_object->end())
    {
      p_object->erase(hit);
    }
}


template <typename object_type,typename value_type>
value_type stlr_min(object_type* p_object)
{
  if(p_object->begin() == p_object->end())
    {
      throw std::out_of_range("");
    }
  return *(p_object->begin());
}

template <typename object_type,typename value_type>
value_type stlr_max(object_type* p_object)
{
  if(p_object->rbegin() == p_object->rend())
    {
      throw std::out_of_range("");
    }
  return *(p_object->rbegin());
}


template <typename object_type,typename value_type>
std::vector<value_type> stlr_copy(object_type* p_object)
{
  auto n = p_object->size();
  if(n == 0)
    {
      return std::vector<value_type>();
    }
  std::vector<value_type> result(n);
  std::transform(p_object->begin(),p_object->end(),result.begin(),[](const value_type& value) {return value;});
  return result;
}

template <typename object_type,typename value_type>
int stlr_count(object_type* p_object,const value_type& value)
{
  return p_object->count(value);
}

// for boost bimaps
template <typename object_type,typename left_value_type,typename right_value_type>
void stlr_insert(object_type* p_object,const left_value_type& left_value,const right_value_type& right_value)
{
  typedef typename object_type::value_type value_type;
  p_object->insert(value_type(left_value,right_value));
}

template <typename object_type,typename key_type,typename value_type>
value_type stlr_left_at(object_type* p_object,const key_type& key)
{
  return p_object->left.at(key);
}

template <typename object_type,typename key_type,typename value_type>
value_type stlr_right_at(object_type* p_object,const key_type& key)
{
  return p_object->right.at(key);
}

template <typename object_type,typename key_type,typename value_type>
std::vector<value_type> stlr_right_equal_range(object_type* p_object,const key_type& key)
{
  auto n = p_object->right.count(key);
  if(n == 0)
    {
      return std::vector<value_type>();
    }
  auto result = std::vector<value_type>(n);
  auto range = p_object->right.equal_range(key);
  std::transform(range.first,range.second,result.begin(),[](auto& v) {return v.second;});
  return result;
}

template <typename object_type,typename key_type,typename value_type>
std::vector<value_type> stlr_left_equal_range(object_type* p_object,const key_type& key)
{
  auto n = p_object->left.count(key);
  if(n == 0)
    {
      return std::vector<value_type>();
    }
  auto result = std::vector<value_type>(n);
  auto range = p_object->left.equal_range(key);
  std::transform(range.first,range.second,result.begin(),[](auto& v) {return v.second;});
  return result;
}

template <typename object_type,typename key_type>
void stlr_left_erase(object_type* p_object,const key_type& key)
{
  p_object->left.erase(key);
}

template <typename object_type,typename key_type>
void stlr_right_erase(object_type* p_object,const key_type& key)
{
  p_object->right.erase(key);
}

template <typename object_type,typename key_type>
void stlr_left_erase_one(object_type* p_object,const key_type& key)
{
  auto hit = p_object->left.find(key);
  if(hit != p_object->left.end())
    {
      p_object->left.erase(hit);
    }
}

template <typename object_type,typename key_type>
void stlr_right_erase_one(object_type* p_object,const key_type& key)
{
  auto hit = p_object->right.find(key);
  if(hit != p_object->right.end())
    {
      p_object->right.erase(hit);
    }
}

template <typename object_type,typename key_type>
int stlr_left_count(object_type* p_object,const key_type& key)
{
  return p_object->left.count(key);
}

template <typename object_type,typename key_type>
int stlr_right_count(object_type* p_object,const key_type& key)
{
  return p_object->right.count(key);
}

template <typename object_type,typename key_type,typename value_type>
Rcpp::List stlr_left_lower_bound(object_type* p_object,const key_type& key)
{
  auto it = p_object->left.lower_bound(key);
  std::list<key_type> keys;
  std::list<value_type> values;
  if(it != p_object->left.end())
    {
      while(it != p_object->left.end())
	{
	  keys.push_back(it->first);
	  values.push_back(it->second);
	  it++;
	}
    }
  return Rcpp::List::create(Rcpp::Named("keys") = keys,Rcpp::Named("values") = values);
}

template <typename object_type,typename key_type,typename value_type>
Rcpp::List stlr_left_upper_bound(object_type* p_object,const key_type& key)
{
  auto it = p_object->left.upper_bound(key);
  std::list<key_type> keys;
  std::list<value_type> values;
  if(it != p_object->left.end())
    {
      while(it != p_object->left.end())
	{
	  keys.push_back(it->first);
	  values.push_back(it->second);
	  it++;
	}
    }
  return Rcpp::List::create(Rcpp::Named("keys") = keys,Rcpp::Named("values") = values);
}


template <typename object_type,typename key_type,typename value_type>
Rcpp::List stlr_right_lower_bound(object_type* p_object,const key_type& key)
{
  auto it = p_object->right.lower_bound(key);
  std::list<key_type> keys;
  std::list<value_type> values;
  if(it != p_object->right.end())
    {
      while(it != p_object->right.end())
	{
	  keys.push_back(it->first);
	  values.push_back(it->second);
	  it++;
	}
    }
  return Rcpp::List::create(Rcpp::Named("keys") = keys,Rcpp::Named("values") = values);
}

template <typename object_type,typename key_type,typename value_type>
Rcpp::List stlr_right_upper_bound(object_type* p_object,const key_type& key)
{
  auto it = p_object->right.upper_bound(key);
  std::list<key_type> keys;
  std::list<value_type> values;
  if(it != p_object->right.end())
    {
      while(it != p_object->right.end())
	{
	  keys.push_back(it->first);
	  values.push_back(it->second);
	  it++;
	}
    }
  return Rcpp::List::create(Rcpp::Named("keys") = keys,Rcpp::Named("values") = values);
}


template <typename object_type,typename key_type,typename value_type>
Rcpp::List stlr_left_range(object_type* p_object,const key_type& lower_key,const key_type& upper_key)
{
  if(lower_key > upper_key)
    {
      throw std::out_of_range("lower key is greater than upper key"); 
    }
  auto it_lower = p_object->left.lower_bound(lower_key);
  auto it_upper = p_object->left.upper_bound(upper_key);
  std::list<key_type> keys;
  std::list<value_type> values;
  if(it_lower != it_upper)
    {
      while(it_lower != it_upper)
	{
	  keys.push_back(it_lower->first);
	  values.push_back(it_lower->second);
	  it_lower++;
	}
    }
  return Rcpp::List::create(Rcpp::Named("keys") = keys,Rcpp::Named("values") = values);
}

template <typename object_type,typename key_type,typename value_type>
Rcpp::List stlr_right_range(object_type* p_object,const key_type& lower_key,const key_type& upper_key)
{
  if(lower_key > upper_key)
    {
      throw std::out_of_range("lower key is greater than upper key"); 
    }
  auto it_lower = p_object->right.lower_bound(lower_key);
  auto it_upper = p_object->right.upper_bound(upper_key);
  std::list<key_type> keys;
  std::list<value_type> values;
  if(it_lower != it_upper)
    {
      while(it_lower != it_upper)
	{
	  keys.push_back(it_lower->first);
	  values.push_back(it_lower->second);
	  it_lower++;
	}
    }
  return Rcpp::List::create(Rcpp::Named("keys") = keys,Rcpp::Named("values") = values);
}

template <typename object_type,typename value_type>
value_type stlr_left_min(object_type* p_object)
{
  if(p_object->left.begin() == p_object->left.end())
    {
      throw std::out_of_range("");
    }
  return p_object->left.begin()->first;
}

template <typename object_type,typename value_type>
value_type stlr_right_min(object_type* p_object)
{
  if(p_object->right.begin() == p_object->right.end())
    {
      throw std::out_of_range("");
    }
  return p_object->right.begin()->first;
}

template <typename object_type,typename value_type>
value_type stlr_left_max(object_type* p_object)
{
  if(p_object->left.rbegin() == p_object->left.rend())
    {
      throw std::out_of_range("");
    }
  return p_object->left.rbegin()->first;
}

template <typename object_type,typename value_type>
value_type stlr_right_max(object_type* p_object)
{
  if(p_object->right.rbegin() == p_object->right.rend())
    {
      throw std::out_of_range("");
    }
  return p_object->right.rbegin()->first;
}




#endif
