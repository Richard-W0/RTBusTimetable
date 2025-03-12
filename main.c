#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void){
  CURL *curl;
  CURLcode result;
  
  curl = curl_easy_init();
  if(curl == NULL){
    fprintf(stderr, "HTTP request failed\n")
    return -1;
  }

  return 0;
}
