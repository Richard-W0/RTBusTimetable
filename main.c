#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

//buffer for the api calls
struct Memory{
  char *response;
  size_t size;
}

int main(void){
  CURL *curl;
  CURLcode result;
  
  //the HTTP request
  curl = curl_easy_init();
  if(curl == NULL){
    fprintf(stderr, "HTTP request failed\n");
    return -1;
  }

  //set options for the HTTP request
  curl_easy_setopt(curl, CURLOPT_URL, "https://mobility-api.mobility-database.fintraffic.fi/gtfs-realtime/v2/TripUpdates?apikey=YOUR_API_KEY");

  //actually does the request
  result = curl_easy_perform(curl);
  if(result != CURLE_OK){
    fprintf(sderr, "ERROR: %s\n", curl_easy_strerror(result));
    return -1;
  }




  //closes the easy api session
  curl_easy_cleanup(curl);
  return 0;
}
