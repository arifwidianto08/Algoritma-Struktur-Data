#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
  int day;
  int month;
  int year;
};

int is_leap_year(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return 1;
  }

  return 0;
}

int validate_input_date(int day, int month, int year) {
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
    return 0;
  }

  switch (month) {
  case 2: // February
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      // Leap year, February can have maximum 29 days.
      if (day > 29) {
        return 0;
      }
    } else {
      // Non-leap year, February can have maximum 28 days.
      if (day > 28) {
        return 0;
      }
    }
    break;
  case 4:  // April
  case 6:  // June
  case 9:  // September
  case 11: // November
    // Months with 30 days.
    if (day > 30) {
      return 0;
    }
    break;
  default:
    break; // All other months can have maximum 31 days.
  }

  return 1;
}

int main() {
  char input_date[10];
  struct Date today;
  struct Date tomorrow;

  printf("Masukkan keterangan tanggal (dd/mm/yyyy) : ");
  scanf(" %[^\n]s", input_date);

  if (sscanf(input_date, "%d/%d/%d", &today.day, &today.month, &today.year) !=
      3) {
    printf("Invalid Date Input");
    return 0;
  };

  if (validate_input_date(today.day, today.month, today.year) == 0) {
    printf("Invalid Date Input");
    return 0;
  }

  tomorrow.day = today.day + 1;
  tomorrow.month = today.month;
  tomorrow.year = today.year;

  int is_30_day_month = (tomorrow.month == 4 || tomorrow.month == 6 ||
                         tomorrow.month == 9 || tomorrow.month == 11);

  int bissextile_february =
      (tomorrow.day > 29 && tomorrow.month == 2 && is_leap_year(tomorrow.year));
  int regular_february =
      tomorrow.day > 28 && tomorrow.month == 2 && !is_leap_year(tomorrow.year);

  if (tomorrow.day > 31 || tomorrow.day > 30 && is_30_day_month ||
      bissextile_february || regular_february) {
    tomorrow.day = 1;
    tomorrow.month++;
  }

  if (tomorrow.month > 12) {
    tomorrow.month = 1;
    tomorrow.year++;
  }

  printf("Tomorrow's Date:\n");
  printf("Date : %d\n", tomorrow.day);
  printf("Month : %d\n", tomorrow.month);
  printf("Year : %d\n", tomorrow.year);
  printf("Combined : %02d/%02d/%04d\n", tomorrow.day, tomorrow.month,
         tomorrow.year);
  return 0;
}
