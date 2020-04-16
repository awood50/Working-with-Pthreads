/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;


// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
void *routineName(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   cout << "Thread is running..." << endl;
   return 0;
}

const char* my_messages[4] = {"English: Hello!",
                            "French: Bonjour!",
                            "Spanish: Hola!",
                            "German: Guten Tag!"};
                            
                            
// PrintMessage function
void *printMessage(void *index) {
  cout <<  my_messages[*((int*) index)] <<"\n";
  delete (int*)index;
  return 0;
}                            




int main() {
  // id is used to store a unique thread identifier,
  // returned by the call to create a new POSIX thread   
  // Create thread(s)
  pthread_t id;
  // rc = pthread_create(&id, NULL, routineName, NULL);
  for(int i = 0; i < 4; i++ ) {
      // Used new int(i)  because &i was causing weird errors
      int rc = pthread_create(&id, NULL, printMessage, new int(i));
      if (rc) {
          cout << "ERROR; return code from pthread_create() is " << rc << endl;
          return -1;
      }
  }

   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
