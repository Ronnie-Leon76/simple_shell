#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s) {
  int i = 0;

  if (!s)
    return (0);

  while (*s++)
    i++;
  return (i);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle) {
  while (*needle)
    if (*needle++ != *haystack++)
      return (NULL);
  return ((char *)haystack);
}