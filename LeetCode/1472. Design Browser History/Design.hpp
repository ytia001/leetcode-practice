#include <iostream>
#include <string>

class BrowserHistory {
public:
    std::string currBrowser;
    BrowserHistory* currPointer;
    BrowserHistory* nextBrowser;
    //BrowserHistory* prevBrowser;
    int currEdge = 0;

    BrowserHistory(std::string homepage) {
      currBrowser = homepage;
      nextBrowser = nullptr;
      currPointer = this;
      //prevBrowser = currPointer;
    }
    
    void visit(std::string url) {
      if(this->currPointer->nextBrowser != nullptr){
        this->currPointer->nextBrowser = nullptr;
      }
        this->currPointer->nextBrowser = new BrowserHistory(url); 
        this->currPointer->nextBrowser->currEdge = this->currPointer->currEdge + 1;
        //this->prevBrowser = this->currPointer;  
        this->currPointer = currPointer -> nextBrowser;
    }
    
    std::string back(int steps) {
        int forwardSteps = this->currPointer->currEdge - steps;
        std::cout<<forwardSteps<<std::endl;
        if(forwardSteps <= 0 ){
          this->currPointer = this;
          return this->currPointer->currBrowser;
        }else{
          this->currPointer = this;
          return forward(forwardSteps);
        }
    }
    
    std::string forward(int steps) {
        for(int i = 0 ; i < steps ; i++){
          if(this->currPointer->nextBrowser == nullptr ){
              return currPointer->currBrowser;
          }
          this->currPointer = currPointer->nextBrowser;
        }
        return this->currPointer->currBrowser;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */