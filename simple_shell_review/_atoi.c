#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: integer
 */
int _atoi(char *s) {
  int i = 0;
  int sign = 1;
  int num = 0;

  while (s[i] != '\0') {
    if (s[i] == '-')
      sign *= -1;
    if ((s[i] >= '0') && (s[i] <= '9'))
      num = num * 10 + (s[i] - '0');
    i++;
  }
  return (num * sign);
}

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info) {
  return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim) {
  while (*delim)
    if (*delim++ == c)
      return (1);
  return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  else
    return (0);
}