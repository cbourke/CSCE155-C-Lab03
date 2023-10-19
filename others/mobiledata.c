#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <GB_per_period> <current_day> <total_GB_used>\n", argv[0]);
    exit(1);
  }

  double GB_per_period = atof(argv[1]);
  int current_day = atoi(argv[2]);
  double total_GB_used = atof(argv[3]);

  int days_remaining = 30 - current_day;
  double average_daily_usage = total_GB_used / current_day;

  printf("%d days used, %d days remaining\n", current_day, days_remaining);
  printf("Average daily use: %.3f GB/day\n", average_daily_usage);

  if (average_daily_usage > GB_per_period) {
    printf("You are EXCEEDING your average daily use (%.3f GB/day).\n", GB_per_period);
    double projected_overage = (average_daily_usage - GB_per_period) * days_remaining;
    printf("Continuing this high usage, you'll exceed your data plan by %.3f GB.\n", projected_overage);
  } else if (average_daily_usage <= GB_per_period) {
    double average_daily_remaining = GB_per_period - average_daily_usage;
    printf("You are at or below your average daily use (%.3f GB/day).\n", GB_per_period);
    printf("You can use up to %.3f GB/day and stay below your data plan limit.\n", average_daily_remaining);
  }

  if (total_GB_used >= GB_per_period) {
    printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");
  }
  
  return 0;
}