#include "../includes/date.h"

int time_hour(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_hour;
}

int time_minutes(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_min;
}

int time_seconds(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_sec;
}

int date_day(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_mday;
}

int date_month(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_mon+1;
}

int date_year(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_year + 1900;
}


// int main(){
//   int day = date_day();
//   int month = date_month();
//   int year = date_year();
//   int hour = time_hour();
//   int minutes = time_minutes();
//   int seconds = time_seconds();
//   printf("Date: %d:%d:%d\n", day, month, year);
//   printf("Hour: %d/%d/%d\n", hour, minutes, seconds);
//   return 0;
// }
