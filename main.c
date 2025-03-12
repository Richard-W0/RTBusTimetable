#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

//buffer for the api calls
struct Memory{
  char *response;
  size_t size;
};

int main(void){
  CURL *curl;
  CURLcode result;

  const char *API_KEY = getenv("API_KEY_RTB");
  if(API_KEY == NULL){
    fprintf(stderr, "API key not set\n");
    return -1;
  }
  
  //the HTTP request
  curl = curl_easy_init();
  if(curl == NULL){
    fprintf(stderr, "HTTP request failed\n");
    return -1;
  }

  //append the api key
  char url[512];
  snprintf(url, sizeof(url), "https://mobility-api.mobility-database.fintraffic.fi/gtfs-realtime/v2/TripUpdates?apikey=%s", API_KEY);

  //set options for the HTTP request
  curl_easy_setopt(curl, CURLOPT_URL, url);

  //actually does the request
  result = curl_easy_perform(curl);
  if(result != CURLE_OK){
    fprintf(stderr, "ERROR: %s\n", curl_easy_strerror(result));
    return -1;
  }




  //closes the easy api session
  curl_easy_cleanup(curl);
  return 0;
}
