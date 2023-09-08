#include <catch2/catch_test_macros.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

// Initialize the stack
void init(Stack* stack) { stack->top = -1; }

// Check if the stack is empty
bool isEmpty(Stack* stack) { return stack->top == -1; }

// Check if the stack is full
bool isFull(Stack* stack) { return stack->top == MAX_SIZE - 1; }

// Push an element onto the stack
void push(Stack* stack, int value) {
  if (isFull(stack)) {
    printf("Stack is full. Cannot push.\n");
    return;
  }
  stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty. Cannot pop.\n");
    return -1;  // Return a sentinel value to indicate an error
  }
  return stack->data[stack->top--];
}

// Peek at the top element without removing it
int peek(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty. Cannot peek.\n");
    return -1;  // Return a sentinel value to indicate an error
  }
  return stack->data[stack->top];
}

int areEqual(char* str1, char* str2) {
  while (*str1 != '\0' && *str2 != '\0') {
    if (*str1 != *str2) {
      return 0;  // Strings are not equal
    }
    str1++;
    str2++;
  }

  if (*str1 == '\0' && *str2 == '\0') {
    return 1;  // Strings are equal
  }

  return 0;  // One string is longer than the other
}

int solution(char* S) {
  Stack stack;
  init(&stack);

  char op_buf[50];
  char* space_ptr;

  size_t str_size = strlen(S);
  char* str = (char*)malloc(str_size);

  const char* separator = " ";

  strncpy(str, S, str_size);

  char* ptr = strtok(str, separator);
  while (ptr != NULL) {
    char* end_ptr;
    long value = strtol(ptr, &end_ptr, 10);

    if (end_ptr != &ptr[0]) {
      push(&stack, value);
    } else if (areEqual(ptr, "DUP")) {
      push(&stack, peek(&stack));
    } else if (areEqual(ptr, "POP")) {
      pop(&stack);
    } else if (areEqual(ptr, "+")) {
      push(&stack, pop(&stack) + pop(&stack));
    } else if (areEqual(ptr, "-")) {
      push(&stack, pop(&stack) - pop(&stack));
    }

    ptr = strtok(NULL, separator);
  }
  free(str);
  return pop(&stack);
}

TEST_CASE("Task 1", "[tasks]") {
  char* data1 = "4 5 6 - 7 +";
  REQUIRE(solution(data1) == 8);
  char* data2 = "1 2 4 - + DUP 4 7 DUP + -";
  REQUIRE(solution(data2) == 10);
}
