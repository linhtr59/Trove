//update trove file

#include "trove.h"

void update(char *trovefile, int word_length, char *filelist){
  HASHTABLE *update_hashtable = hashtable_new(); //new hashtable to update values with
  LIST *update_list = list_new(); // new list to update values with
  scan_directory(filelist, update_hashtable, update_list); //construct the hashtable to update the values with 
  
  //open trovefile
  //convert trovefile to hashtable
  //update the values of trove hashtbale to that of update_hashtable if filename mathces
  //write trove file again and compress
 
}


