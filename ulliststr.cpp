#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string const & ULListStr::front() const{
	if(empty()){
		throw std::out_of_range("List is empty");
	}
	else {
		return head_->val[head_->first];
	}
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
	if(loc >= size_){
		return nullptr;
	}
	Item* temp = head_;
	size_t count = 0;

	while(temp != nullptr){
		size_t Items = temp->last - temp->first;
		if(loc < count + Items){
			return &(temp->val[temp->first+(loc-count)]);
		}
		count += Items; 
		temp = temp->next;
	}
	return nullptr;
}
std::string const & ULListStr::back() const{
if(empty()){
		throw std::out_of_range("List is empty");
	}
	else {
		return tail_->val[tail_->last-1];
	}
}
void ULListStr::pop_front(){
	if(empty()){
		return;
	}
	head_->first++;
	size_--;
	if(head_->first == head_->last){
		Item* temp = head_;
		head_ = head_->next;
		if(head_){
			head_->prev = nullptr;
		}
		else{
			tail_ = nullptr;
		}
		delete temp; 
	}
}
void ULListStr::push_front(const std::string& val){
if(head_ == NULL || head_->first == 0){
	Item* newNode = new Item();
	newNode->last = ARRSIZE;
	newNode->first = ARRSIZE - 1;
	newNode->val[newNode->first] = val; 
	newNode->next = head_;
	newNode->prev = NULL;

	if (head_) {
			head_->prev = newNode;
		} else {
			tail_ = newNode;
		}
		head_ = newNode;
	} else { 
		head_->first--;
		head_->val[head_->first] = val;
	}
	size_++;
}
void ULListStr::pop_back(){
	if(empty()){
		return;
	}
	tail_->last--;
	size_--;

	if(tail_->first == tail_->last){
		Item* temp = tail_;
		tail_ = tail_->prev;
		if(tail_){
			tail_->next = nullptr;
		}
		else{
			head_ = nullptr;
		}
		delete temp; 
	}

}
void ULListStr::push_back(const std::string& val){
if(tail_ == NULL || tail_->last == ARRSIZE){
	Item* newNode = new Item();
	newNode->first = 0;
	newNode->last = 1;
	newNode->val[0] = val; 
	newNode->prev = tail_;
	newNode->next = NULL;

	if (tail_) {
			tail_->next = newNode;
		} else {
			head_ = newNode;
		}
		tail_ = newNode;
	} else {  
		tail_->val[tail_->last] = val;
		tail_->last++;
	}
	size_++;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
